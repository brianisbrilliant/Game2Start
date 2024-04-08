//======================================================================================================
// Copyright 2016, NaturalPoint Inc.
//====================================================================================================== 

#include "OptitrackClientOrigin.h"
#include "OptitrackNatnet.h"
#include "IOptitrackDisplaySync.h"

#include "Features/IModularFeatures.h"
#include <EngineUtils.h>
#include <DrawDebugHelpers.h>
#include <HAL/RunnableThread.h>

#include <string>


AOptitrackClientOrigin::AOptitrackClientOrigin( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	ServerAddress = "0.0.0.0";
	ClientAddress = "0.0.0.0";
	ConnectionType = EOptitrackClientConnectionType::Multicast;
    PrimaryActorTick.bCanEverTick = true;
	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>( this, TEXT( "RootSceneComponent" ) );

#if WITH_EDITORONLY_DATA
	RootComponent->bVisualizeComponent = true;
#endif
}

static bool RigidBodyDataToState(const sRigidBodyData& rbData, double t, double coordScalingFactor, FOptitrackRigidBodyState& outRbState)
{
    // convert Motive position/orientation -> UE position/orientation
    const FVector position(rbData.z * coordScalingFactor, -rbData.x * coordScalingFactor, rbData.y * coordScalingFactor);
    const FQuat orientation(rbData.qz, -rbData.qx, rbData.qy, -rbData.qw);

    outRbState.TimestampPlatformSeconds = t;
    outRbState.Position = position;
    outRbState.Orientation = orientation;

    // first bit of sRigidBodyData::params indicates if it was tracked this frame
    const bool bTrackedThisFrame = (rbData.params & 0x01) != 0;
    return bTrackedThisFrame;
}

bool AOptitrackClientOrigin::GetLatestRigidBodyState( int32 RbId, FOptitrackRigidBodyState& OutRbState, bool NetworkCompensation )
{
	if ( GetLatestRigidBodyStateUntransformed( RbId, OutRbState, NetworkCompensation) )
	{
		const FTransform optitrackRbTransform( OutRbState.Orientation, OutRbState.Position );

		const FTransform adjustedRbTransform = optitrackRbTransform * GetTransform();
		OutRbState.Position = adjustedRbTransform.GetLocation();
		OutRbState.Orientation = adjustedRbTransform.GetRotation();

		return true;
	}
	else
	{
		return false;
	}
}

bool AOptitrackClientOrigin::GetLatestMarkerState(int32 markerId, FOptitrackMarkerState& OutMarkerState)
{
    if (GetLatestMarkerStateUntransformed(markerId, OutMarkerState))
    {
        const FTransform optitrackMarkerTransform(FQuat::Identity, OutMarkerState.Position);

        const FTransform adjustedMarkerTransform = optitrackMarkerTransform * GetTransform();
        OutMarkerState.Position = adjustedMarkerTransform.GetLocation();

        return true;
    }
    else
    {
        return false;
    }
}

bool AOptitrackClientOrigin::GetLatestSkeletonStateByName(const FName& SkelName, FOptitrackSkeletonState& OutSkelState)
{
    if (SkeletonNameToIdMap.Contains(SkelName))
    {
        if (IsClientConnected() && Client && bCanUseDataSubscription && bUseDataSubscription)
        {
            if (!SubscribedSkeletonNames.Contains(SkelName))
            {
                // subscribe to skeleton
                FrameUpdateLock.Lock();
                const std::wstring wstr(*SkelName.ToString());
                const std::string str(wstr.begin(), wstr.end());
                bool subscribedFlag = NatNetSubscribeByName(str, "Skeleton");
                if (subscribedFlag)
                {
                    SubscribedSkeletonNames.Add(SkelName);
                }
                FrameUpdateLock.Unlock();
                return false;
            }
        }

        return GetLatestSkeletonState(SkeletonNameToIdMap[SkelName], OutSkelState);
    }
    else
    {
        return false;
    }
}

bool AOptitrackClientOrigin::GetLatestSkeletonState(int32 SkelId, FOptitrackSkeletonState& OutSkelState)
{
    bool bResult = false;

    // NOTE: This lock blocks NatNet frame delivery for the duration.
// See comment in NatNetDataCallback.
    FrameUpdateLock.Lock();

    if (const FOptitrackSkeletonState* pState = LatestSkeletonStates.Find(SkelId))
    {
        OutSkelState = *pState;
        bResult = true;
    }

    FrameUpdateLock.Unlock();

    return bResult;
}

bool AOptitrackClientOrigin::FindSkeletonDefinition(const FName& SkeletonName, FOptitrackSkeletonDefinition& OutSkelDef) const
{
    for (const TPair< int32, FOptitrackSkeletonDefinition >& SkelDef : SkeletonDefinitions)
    {
        if (SkelDef.Value.Name == SkeletonName)
        {
            OutSkelDef = SkelDef.Value;
            return true;
        }
    }

    return false;
}


bool AOptitrackClientOrigin::GetLatestRigidBodyStateUntransformed( int32 RbId, FOptitrackRigidBodyState& OutRbState, bool NetworkCompensation)
{
	bool bResult = false;

    if (Client != nullptr && bCanUseDataSubscription && bUseDataSubscription)
    {
        if (!SubscribedRigidBodyIds.Contains(RbId))
        {
            FrameUpdateLock.Lock();
            bool subscribedFlag = NatNetSubscribeById(RbId);
            if (subscribedFlag)
            {
                SubscribedRigidBodyIds.Add(RbId);
            }
            FrameUpdateLock.Unlock();
            return false;
        }
    }

	// NOTE: This lock blocks NatNet frame delivery for the duration.
	// See comment in NatNetDataCallback.
	FrameUpdateLock.Lock();


    if( const FOptitrackRigidBodyState* pState = LatestRigidBodyStates.Find( RbId ) )
    {
        OutRbState = *pState;
        bResult = true;
    }

    if ( !NetworkCompensation && Client != nullptr)
    {
        // if possible, get the predicted time of the next frame
        double SecondsToNextFrame = 0.0;
        if (IModularFeatures::Get().IsModularFeatureAvailable(OptitrackDisplaySyncFeatureName))
        {
            IOptitrackDisplaySync& displaySync = IModularFeatures::Get().GetModularFeature<IOptitrackDisplaySync>(OptitrackDisplaySyncFeatureName);
            SecondsToNextFrame = displaySync.GetTimeToNextFrame();
        }

        sRigidBodyData rbData;
        ErrorCode ec = Client->GetPredictedRigidBodyPose(RbId, rbData, SecondsToNextFrame);
        bResult = ec == ErrorCode_OK;

        //convert natnet rb pose to ue rb state
        double timestamp = FPlatformTime::Seconds() + SecondsToNextFrame;
        bResult &= RigidBodyDataToState(rbData, timestamp, CachedWorldToMeters, OutRbState);

    }

	FrameUpdateLock.Unlock();

	return bResult;
}

bool AOptitrackClientOrigin::GetLatestMarkerStateUntransformed(int32 markerId, FOptitrackMarkerState& OutMarkerState)
{
    bool bResult = false; 

    if (Client != nullptr && bCanUseDataSubscription && bUseDataSubscription)
    {
        if (!bSubscribedToLabeledMarkersFlag)
        {
            NatNetSubscribeByName("", "LabeledMarkers");
            bSubscribedToLabeledMarkersFlag = true;
            return false;
        }
    }

    // NOTE: This lock blocks NatNet frame delivery for the duration.
    // See comment in NatNetDataCallback.
    FrameUpdateLock.Lock();

    if (const FOptitrackMarkerState* pState = LatestMarkerStates.Find(markerId))
    {
        OutMarkerState = *pState;
        bResult = true;
    }

    FrameUpdateLock.Unlock();

    return bResult;
}

bool AOptitrackClientOrigin::GetLatestTimecode(FTimecode& OutLatestTimecode) const
{
	FrameUpdateLock.Lock();
	OutLatestTimecode = LatestTimecode;
	FrameUpdateLock.Unlock();
	return true;
}



//static
AOptitrackClientOrigin* AOptitrackClientOrigin::FindDefaultClientOrigin( UWorld* World )
{
	AOptitrackClientOrigin* returnClientOrigin = nullptr;

	int numClientOrigins = 0;
	for ( TActorIterator<AOptitrackClientOrigin> ClientOriginIter( World ); ClientOriginIter; ++ClientOriginIter )
	{
		++numClientOrigins;

		if ( numClientOrigins == 1 )
		{
			returnClientOrigin = *ClientOriginIter;
		}
	}

	if ( numClientOrigins == 0 )
	{
		UE_LOG( LogOptitrack, Warning, TEXT( "AOptitrackClientOrigin::FindDefaultClientOrigin: Unable to locate any client origin actors!" ) );
	}
	else if ( numClientOrigins > 1 )
	{
		UE_LOG( LogOptitrack, Warning, TEXT( "AOptitrackClientOrigin::FindDefaultClientOrigin: Multiple client origin actors; using first (%s)" ), *returnClientOrigin->GetName() );
	}

	return returnClientOrigin;
}


//static
AOptitrackClientOrigin* AOptitrackClientOrigin::FindHmdClientOrigin( UWorld* World )
{
	AOptitrackClientOrigin* returnClientOrigin = nullptr;

	int numEligibleClientOrigins = 0;
	for ( TActorIterator<AOptitrackClientOrigin> ClientOriginIter( World ); ClientOriginIter; ++ClientOriginIter )
	{
        ++numEligibleClientOrigins;
        if (numEligibleClientOrigins == 1)
        {
            returnClientOrigin = *ClientOriginIter;
        }
	}

	if ( numEligibleClientOrigins == 0 )
	{
		UE_LOG( LogOptitrack, Warning, TEXT( "AOptitrackClientOrigin::FindHmdClientOrigin: Unable to locate any client origin actors that specify the HMD rigid body ID!" ) );
	}
	else if ( numEligibleClientOrigins > 1 )
	{
		UE_LOG( LogOptitrack, Warning, TEXT( "AOptitrackClientOrigin::FindHmdClientOrigin: Multiple client origin actors specify an HMD rigid body ID; using first (%s)" ), *returnClientOrigin->GetName() );
	}

	return returnClientOrigin;
}


void AOptitrackClientOrigin::PreInitializeComponents()
{
	// TODO: Do we need to support this changing at runtime?
	CachedWorldToMeters = GetWorld()->GetWorldSettings()->WorldToMeters;

	Super::PreInitializeComponents();
}

void AOptitrackClientOrigin::BeginPlay()
{
    Super::BeginPlay();

    if (bAutoInitialize)
    {
        InitializeClient();
    }

    // cache frame rate if possible
    if (IModularFeatures::Get().IsModularFeatureAvailable(OptitrackDisplaySyncFeatureName))
    {
        IOptitrackDisplaySync& displaySync = IModularFeatures::Get().GetModularFeature<IOptitrackDisplaySync>(OptitrackDisplaySyncFeatureName);
        displaySync.Initialize();
    }
}


void AOptitrackClientOrigin::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    if (Client)
    {
        mAsynchronousDiscoveryActiveFlag = false;
        if (mDetectDisconnectionThread.joinable())
        {
            mDetectDisconnectionExitFlag = true;
            mDetectDisconnectionThread.join();
        }
        if (mNatNetDiscoveryHandle != nullptr)
        {
            NatNet_FreeAsyncServerDiscovery(mNatNetDiscoveryHandle);
            mNatNetDiscoveryHandle = nullptr;
        }
        ShutdownClient();
    }
}

static void NATNET_CALLCONV NatNetFrameReceivedThunk(sFrameOfMocapData* NewFrame, void* UserData)
{
    AOptitrackClientOrigin* This = reinterpret_cast<AOptitrackClientOrigin*>(UserData);

    if (ensure(This))
    {
        This->NatNetFrameReceivedCallback_Internal(NewFrame);
    }
}

static void NATNET_CALLCONV ServerDiscoveredCallbackThunk(const sNatNetDiscoveredServer* pDiscoveredServer, void* pUserContext)
{
    AOptitrackClientOrigin* This = reinterpret_cast<AOptitrackClientOrigin*>(pUserContext);

    if (ensure(This))
    {
        This->ServerDiscoveredCallback(pDiscoveredServer);
    }
}

void AOptitrackClientOrigin::Tick(float DeltaSeconds)
{
	Super::Tick( DeltaSeconds );

	FrameUpdateLock.Lock();

	if ( bDrawDebugSkeletons )
	{
		for ( const TPair< int32, FOptitrackSkeletonDefinition >& skelDefEntry : SkeletonDefinitions )
		{
			const int32 skelId = skelDefEntry.Key;
			const FOptitrackSkeletonDefinition& skelDef = skelDefEntry.Value;

			if ( ! LatestSkeletonStates.Contains( skelId ) )
			{
				continue;
			}

			const FOptitrackSkeletonState& skelState = LatestSkeletonStates[skelId];

			for ( const TPair<int, FOptitrackBoneDefinition>&pair : skelDef.Bones )
			{
                int boneId = pair.Key; 
                if (!skelDef.Bones.Contains(boneId))
                {
                    // BoneId not in the skeleton definition, could happen for non-full skeletons, e.g. hand only models
                    continue;
                }
				const FOptitrackBoneDefinition& boneDef = skelDef.Bones[boneId];
				const int32 parentBoneId = boneDef.ParentId;
				const FTransform& boneTransform = skelState.WorldSpaceBoneTransforms[boneId];

				FVector Start, End;
				FColor LineColor;

				End = boneTransform.GetLocation();

				if ( parentBoneId >= 0 )
				{
					const FTransform& parentBoneTransform = skelState.WorldSpaceBoneTransforms[parentBoneId];
					Start = parentBoneTransform.GetLocation();
					LineColor = FColor::White;
				}
				else
				{
					Start = GetTransform().GetLocation();
					LineColor = FColor::Red;
				}

				static const float SphereRadius = 2.0f;

				FVector EndToStart = (Start - End);
				float ConeLength = EndToStart.Size();
				float Angle = FMath::RadiansToDegrees( FMath::Atan( SphereRadius / ConeLength ) ) * 0.02f;

				DrawDebugSphere( GetWorld(), End, SphereRadius, 10, LineColor );
				DrawDebugCone( GetWorld(), End, EndToStart, ConeLength, Angle, Angle, 4, LineColor );
				//DrawDebugCoordinateSystem( GetWorld(), End, boneTransform.Rotator(), SphereRadius * 4.0f, false, -1.f, 0.1f );
				//DrawDebugString( GetWorld(), End, boneDef.Name.ToString(), nullptr, FColor::White, 0.f, true );
			}
		}
	}

	if( bDrawMarkers )
	{
        if (bCanUseDataSubscription && bUseDataSubscription && !bSubscribedToLabeledMarkersFlag)
        {
            // subscribe to labeled marker data
            NatNetSubscribeByName("", "LabeledMarkers");
            bSubscribedToLabeledMarkersFlag = true;
        }
		for( const TPair<int32, FOptitrackMarkerState>&pair : LatestMarkerStates )
		{
			FOptitrackMarkerState markerState;
			GetLatestMarkerState( pair.Key, markerState );
			FVector MarkerPos = markerState.Position;
			static const float SphereRadius = 1.0f;
			FColor LineColor = DrawMarkersColor;
			DrawDebugSphere( GetWorld(), MarkerPos, SphereRadius, 10, LineColor );
		}
	}

    // Draws Debug Mesh Spheres where Camera locations are relative to the OptiTrack Client Origin
    if( bDrawDebugCameras ) 
    {
        for( int i = 0; i < CameraDefinitions.Num(); ++i )
        {
            FOptitrackCamera cameraState = CameraDefinitions[i];
            FTransform cameraGlobalTransform( cameraState.Orientation, cameraState.Position );
            FTransform cameraRelativeTransform = cameraGlobalTransform * GetTransform();
            static const float SphereRadius = 10.0f;
            FColor LineColor = FColor::Black;
            DrawDebugSphere( GetWorld(), cameraRelativeTransform.GetTranslation(), SphereRadius, 10, LineColor );
        }
    }

    if (NeedUpdateDataDescription)
    {
        // Update Data Description
        GetDataDescription();
    }

    if (mTriggerReconnectFlag)
    {
        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: Attempting server discovery."));
        ShutdownClient();
        Client = IOptitrackNatnetPlugin::Get().CreateClient();

        if (Client == nullptr)
        {
            UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: IOptitrackNatnetPlugin::CreateClient failed"));
            return;
        }

        mClientConnected = false;
        // activate asynchronous discovery
        mAsynchronousDiscoveryActiveFlag = true;
        if (mNatNetDiscoveryHandle != nullptr)
        {
            NatNet_FreeAsyncServerDiscovery(mNatNetDiscoveryHandle);
            mNatNetDiscoveryHandle = nullptr;
        }
        NatNet_CreateAsyncServerDiscovery(&mNatNetDiscoveryHandle, ServerDiscoveredCallbackThunk, this);
        mTriggerReconnectFlag = false;
    }

	FrameUpdateLock.Unlock();
}

bool AOptitrackClientOrigin::InitializeClient()
{
	check( IOptitrackNatnetPlugin::IsAvailable() );

	if ( Client != nullptr )
	{
		UE_LOG( LogOptitrack, Error, TEXT( "AOptitrackClientOrigin: Not valid to call InitializeClient when already initialized" ) );
		return false;
	}

	Client = IOptitrackNatnetPlugin::Get().CreateClient();

	if ( Client == nullptr )
	{
		UE_LOG( LogOptitrack, Error, TEXT( "AOptitrackClientOrigin: IOptitrackNatnetPlugin::CreateClient failed" ) );
		return false;
	}
    
    mClientConnected = false;

    if (bAutoConnect)
    {
        // Initialize NatNet asynchronous discovery.
        mAsynchronousDiscoveryActiveFlag = true;
        NatNet_CreateAsyncServerDiscovery(&mNatNetDiscoveryHandle, ServerDiscoveredCallbackThunk, this);

        // Start disconnection detection thread.
        mDetectDisconnectionThread = std::thread(&AOptitrackClientOrigin::ThreadProc_DetectDisconnection, this);
    }
    else
    {
        // connect normally
        const std::string strClientAddr(TCHAR_TO_ANSI(*ClientAddress));
        const std::string strServerAddr(TCHAR_TO_ANSI(*ServerAddress));
        sNatNetClientConnectParams connectParams;
        connectParams.connectionType = (ConnectionType == EOptitrackClientConnectionType::Unicast) ? ConnectionType_Unicast : ConnectionType_Multicast;
        connectParams.localAddress = strClientAddr.c_str();
        connectParams.serverAddress = strServerAddr.c_str();
        ConnectNatNet(connectParams);
    }

    return true;
}

bool AOptitrackClientOrigin::GetDataDescription()
{
    if (Client == nullptr)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: Data Description requested without valid connected client."));
        return false;
    }

    SkeletonDefinitions.Empty();
    SkeletonNameToIdMap.Empty();
    LatestSkeletonStates.Empty();
	LatestRigidBodyStates.Empty();
    sDataDescriptions* DataDescriptions = nullptr;
    const ErrorCode GetDataDescsResult = Client->GetDataDescriptionList(&DataDescriptions, (1 << Descriptor_RigidBody) | (1 << Descriptor_Skeleton) | (1 << Descriptor_Camera ) );
    if (!ensureMsgf(GetDataDescsResult == ErrorCode_OK && DataDescriptions != nullptr, TEXT("NatNetClient::GetDataDescriptionList failed with return code %d"), GetDataDescsResult))
    {
        ShutdownClient();
        return false;
    }
    // Parse data descriptions for skeleton definitions.
    const float coordScalingFactor = CachedWorldToMeters;
    for (int32 descIdx = 0; descIdx < DataDescriptions->nDataDescriptions; ++descIdx)
    {
        if (DataDescriptions->arrDataDescriptions[descIdx].type == Descriptor_Skeleton)
        {
            const sSkeletonDescription& skelDesc =
                *DataDescriptions->arrDataDescriptions[descIdx].Data.SkeletonDescription;

            FOptitrackSkeletonDefinition skelDef;
            skelDef.Id = skelDesc.skeletonID;
            skelDef.Name = skelDesc.szName;

            skelDef.Bones.Empty(skelDesc.nRigidBodies + 1);
            FOptitrackBoneDefinition rootBoneDef;
            rootBoneDef.Id = 0;
            rootBoneDef.LocalOffset = FVector::ZeroVector;
            rootBoneDef.Name = "Root";
            rootBoneDef.ParentId = -1;
            skelDef.Bones.Emplace(0, rootBoneDef);

            for (int32 boneIdx = 0; boneIdx < skelDesc.nRigidBodies; ++boneIdx)
            {
                const sRigidBodyDescription& boneDesc = skelDesc.RigidBodies[boneIdx];
                checkSlow(boneDesc.ID > 0);

                //FOptitrackBoneDefinition& boneDef = skelDef.Bones[boneDesc.ID];
                FOptitrackBoneDefinition boneDef;
                boneDef.Name = boneDesc.szName;
                boneDef.Id = boneDesc.ID;
                boneDef.ParentId = boneDesc.parentID;
#if 0
                boneDef.LocalOffset = FVector( boneDesc.offsetx * coordScalingFactor, boneDesc.offsetz * coordScalingFactor, boneDesc.offsety * coordScalingFactor );
#else
				boneDef.LocalOffset = FVector(boneDesc.offsetz * coordScalingFactor, -boneDesc.offsetx * coordScalingFactor, boneDesc.offsety * coordScalingFactor);
#endif
                skelDef.Bones.Emplace(boneDesc.ID, boneDef);
            }

            SkeletonDefinitions.Emplace(skelDef.Id, MoveTemp(skelDef));
            SkeletonNameToIdMap.Emplace(skelDef.Name, skelDef.Id);
        }
        else if( DataDescriptions->arrDataDescriptions[descIdx].type == Descriptor_Camera && mMotiveVersion[0] >= 3 ) // Cameras only works in Motive 3.0+
        {
            const sCameraDescription& camDesc =
                *DataDescriptions->arrDataDescriptions[descIdx].Data.CameraDescription;

            FOptitrackCamera camDef;
            camDef.Name = camDesc.strName;
            camDef.Position = FVector( camDesc.z * coordScalingFactor, -camDesc.x * coordScalingFactor, camDesc.y * coordScalingFactor );
            camDef.Orientation = FQuat(camDesc.qx, camDesc.qy, camDesc.qz, camDesc.qw);

            CameraDefinitions.Add( camDef );
        }
    }
    Client->SetFrameReceivedCallback(&NatNetFrameReceivedThunk, this);

    NeedUpdateDataDescription = false;

    return true;
}


bool AOptitrackClientOrigin::ShutdownClient()
{
	if ( Client != nullptr )
	{
		FrameUpdateLock.Lock();
		Client->Disconnect();
		check( IOptitrackNatnetPlugin::IsAvailable() );
		IOptitrackNatnetPlugin::Get().DestroyClient( Client );
		Client = nullptr;
		TimestampType = EOptitrackTimestampType::Unknown;

		FrameUpdateLock.Unlock();

		return true;
	}
	else
	{
		UE_LOG( LogOptitrack, Error, TEXT( "AOptitrackClientOrigin: Not valid to call ShutdownClient when not initialized" ) );
		return false;
	}
	SkeletonDefinitions.Reset();
}

bool AOptitrackClientOrigin::SetDefaultSkeletonSettings()
{
    if (IsClientInitialized())
    {
        // Get bone naming convention and match 
        void* pResult;
        int ret = 0;
        int nBytes = 0;
        ret = Client->SendMessageAndWait("GetProperty,,Bone Naming Convention", &pResult, &nBytes);
        if (ret == ErrorCode_OK)
        {
            char* BoneConvention((char*) pResult);
            if (BoneConvention[0] == '0')
            {
                BoneNamingConvention = EOptitrackBoneNamingConvention::Motive;
            }
            else if (BoneConvention[0] == '1')
            {
                BoneNamingConvention = EOptitrackBoneNamingConvention::FBX;
            }
            else if (BoneConvention[0] == '2')
            {
                BoneNamingConvention = EOptitrackBoneNamingConvention::BVH;
            }
        }
        else
        {
            UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: Unable to match Motive bone naming convention. Check Motive streaming settings."));
        }

        // Ensure skeletons are streamed with local coordinates (and not global)
        ret = Client->SendMessageAndWait("SetProperty,,Skeleton Coordinates,true", &pResult, &nBytes);
        if (ret != ErrorCode_OK)
        {
            UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: Unable to set skeleton coordinates to local. Check Motive streaming settings."));
        }

    }
    return true;
}


void AOptitrackClientOrigin::NatNetFrameReceivedCallback_Internal( struct sFrameOfMocapData* NewFrame )
{
	// Compute a timestamp for the rigid body states. See also ServerSupportsExposureTimestamp().
	const double arrivalTimestamp = FPlatformTime::Seconds();

    // Use best available timestamp (USB cameras don't support mid-exposure).
    const uint64_t natNetTimestamp =
        NewFrame->CameraMidExposureTimestamp == 0
        ? NewFrame->CameraDataReceivedTimestamp
        : NewFrame->CameraMidExposureTimestamp;
    mNatNetLastRecievedTimestamp = natNetTimestamp;
    if (mNatNetTimestampEpoch == 0)
    {
        mNatNetTimestampEpoch = natNetTimestamp;
    }

	double totalLatency;
	if ( NewFrame->CameraMidExposureTimestamp != 0 )
	{
		TimestampType = EOptitrackTimestampType::ServerExposureTime;
		totalLatency = Client->SecondsSinceHostTimestamp( NewFrame->CameraMidExposureTimestamp );
	}
	else if ( NewFrame->CameraDataReceivedTimestamp != 0 )
	{
		// In this case, the pipeline is only partially instrumented, and latency is underestimated slightly.
		// Could be the case with a USB camera system, for example.
		TimestampType = EOptitrackTimestampType::ServerAggregationTime;
		totalLatency = Client->SecondsSinceHostTimestamp( NewFrame->CameraDataReceivedTimestamp );
	}
	else
	{
		// Latency metric is unavailable/unknown.
		TimestampType = EOptitrackTimestampType::LocalArrivalTime;
		totalLatency = 0.0;
	}

	const double dataTimestamp = arrivalTimestamp - totalLatency;

    NatNetFrameReceivedEvent.Broadcast( NewFrame, dataTimestamp );

#if ! UE_BUILD_SHIPPING
	const double networkLatency = Client->SecondsSinceHostTimestamp( NewFrame->TransmitTimestamp );
	const double arrivalPeriod = arrivalTimestamp - LastArrivalTimestamp;

	TimingStats.RecordSamples( totalLatency, networkLatency, arrivalPeriod );
	LastArrivalTimestamp = arrivalTimestamp;
#endif // #if ! UE_BUILD_SHIPPING

	// TODO: In the event of FrameUpdateLock contention, rather than blocking,
	// the frame NatNet is attempting to deliver is dropped. In practice,
	// contention should be infrequent, and the NatNet stream's frame rate is
	// generally much higher than Unreal.
	// A more sophisticated locking (or lock-free) scheme would be preferable.
    if (FrameUpdateLock.TryLock())
    {
		// get timecode
		int hour, minute, second, frame, subframe;
		NatNet_DecodeTimecode(NewFrame->Timecode, NewFrame->TimecodeSubframe, &hour, &minute, &second, &frame, &subframe);
		LatestTimecode = FTimecode(hour, minute, second, frame, false);

        const float coordScalingFactor = CachedWorldToMeters;

        for (int i = 0; i < NewFrame->nRigidBodies; ++i)
        {
            const sRigidBodyData& rbData = NewFrame->RigidBodies[i];

            FOptitrackRigidBodyState rbState;
            
            bool tracked = RigidBodyDataToState(rbData, dataTimestamp, coordScalingFactor, rbState);
            if (tracked)
            {
                LatestRigidBodyStates.Emplace(rbData.ID, rbState);
            }
        }

        // unpack labeled markers
        LatestMarkerStates.Empty(NewFrame->nLabeledMarkers);
        for (int i = 0; i < NewFrame->nLabeledMarkers; ++i)
        {
            const sMarker& markerData = NewFrame->LabeledMarkers[i];
            const FVector position(markerData.z * coordScalingFactor, -markerData.x * coordScalingFactor, markerData.y * coordScalingFactor);
            FOptitrackMarkerState markerState;
            markerState.TimestampPlatformSeconds = dataTimestamp;
            markerState.Position = position;
            markerState.Id = markerData.ID;

            LatestMarkerStates.Emplace(markerData.ID, markerState);
        }


        // Check if data descriptions have changed
        if ((NewFrame->params & 0x02) != 0)
        {
            NeedUpdateDataDescription = true;
        }

        LatestSkeletonStates.Reserve(NewFrame->nSkeletons);

        for (int skelIdx = 0; skelIdx < NewFrame->nSkeletons; ++skelIdx)
        {
            const sSkeletonData& skelData = NewFrame->Skeletons[skelIdx];

            // TODO: Reject any incoming skeleton state that's invalid or doesn't match our definition,
            // that way downstream client code doesn't need to do redundant checking.
            if (!SkeletonDefinitions.Contains(skelData.skeletonID))
            {
                // TODO: Can't continue without knowledge of the hierarchy.
                // Maybe this condition should flag for a re-request of updated NatNet data descriptions?
                continue;
            }

            const FOptitrackSkeletonDefinition& skelDef = SkeletonDefinitions[skelData.skeletonID];

            FOptitrackSkeletonState& skelState = LatestSkeletonStates.FindOrAdd(skelData.skeletonID);
            skelState.BonePoses.Empty(skelData.nRigidBodies + 1);

			FOptitrackPose rootPose;
			rootPose.Position = FVector::ZeroVector;
			rootPose.Orientation = FQuat::Identity;
			skelState.BonePoses.Emplace(0, rootPose);

            // Streaming bone index is one lower since there's no root bone in the streaming data.
            for (int boneIdx = 0; boneIdx < skelData.nRigidBodies; ++boneIdx)
            {
                const sRigidBodyData& boneData = skelData.RigidBodyData[boneIdx];

                int32 boneSkelId, boneId;
                NatNet_DecodeID(boneData.ID, &boneSkelId, &boneId);
                checkSlow(boneSkelId == skelData.skeletonID);
                checkSlow( boneId > 0 );

                //FOptitrackPose& bonePose = skelState.BonePoses[boneId];
                FOptitrackPose bonePose;
#if 0
                bonePose.Position = FVector(boneData.x * coordScalingFactor, boneData.z * coordScalingFactor, boneData.y * coordScalingFactor);
                bonePose.Orientation = FQuat(boneData.qx, boneData.qz, boneData.qy, -boneData.qw).GetNormalized();
#else
                bonePose.Position = FVector( boneData.z * coordScalingFactor, -boneData.x * coordScalingFactor, boneData.y * coordScalingFactor );
                bonePose.Orientation = FQuat( boneData.qz, -boneData.qx, boneData.qy, -boneData.qw ).GetNormalized();
#endif
                skelState.BonePoses.Emplace(boneId, bonePose);
            }

            // Compute world space bones
            skelState.WorldSpaceBoneTransforms.Empty(skelData.nRigidBodies + 1);
			skelState.LocalBoneSpaceTransforms.Empty(skelData.nRigidBodies + 1);

            for (const TPair<int, FOptitrackBoneDefinition>& pair : skelDef.Bones )
            {
                int boneId = pair.Key;
                const FOptitrackBoneDefinition& boneDef = skelDef.Bones[boneId];
                const int32 parentBoneId = boneDef.ParentId;
                checkSlow(parentBoneId < boneId); // Topological ordering
                checkSlow(skelState.BonePoses.Contains(boneId));

                const FOptitrackPose& srcBonePose = skelState.BonePoses[boneId];
                const FTransform& parentBoneTrackingSpace = boneId > 0
                    ? skelState.WorldSpaceBoneTransforms[parentBoneId]
                    : GetTransform();

                const FTransform boneSpaceTransform = FTransform(srcBonePose.Orientation, srcBonePose.Position);

                skelState.WorldSpaceBoneTransforms.Emplace(boneId, boneSpaceTransform * parentBoneTrackingSpace);
				skelState.LocalBoneSpaceTransforms.Emplace(boneId, boneSpaceTransform);
            }
        }

		FrameUpdateLock.Unlock();
	}
}

void AOptitrackClientOrigin::ValidateAuthenticationToken(const char* challengeToken, char* authToken)
{
    if (Client)
    {
        Client->ValidateAuthenticationToken(challengeToken, authToken);
    }
}


void AOptitrackClientOrigin::ThreadProc_DetectDisconnection()
{
    // Start the disconnection detection loop
    mDetectDisconnectionExitFlag = false;
    while (mDetectDisconnectionExitFlag == false)
    {
        if (Client == nullptr && mAsynchronousDiscoveryActiveFlag == false)
        {
            // shouldn't happen, but just in case
            UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet attempting server discovery."));
            mTriggerReconnectFlag = true;
        }

        if (bAutoConnect && mNatNetTimestampEpoch != 0 && mAsynchronousDiscoveryActiveFlag == false)
        {
            const double secondsSinceLastTimestamp =
                Client ->SecondsSinceHostTimestamp(mNatNetLastRecievedTimestamp);

            if (Client != nullptr && secondsSinceLastTimestamp > 1.0)
            {
                // valid timestamp and not actively seeking motive server, receive frame hasn't been called in a second
                // ping Motive to see if it's still there
                void* pResult;
                int ret = 0;
                int nBytes = 0;
                ret = Client->SendMessageAndWait("FrameRate", &pResult, &nBytes);
                if (ret != 0)
                {
                    // unable to query Motive, assume it's gone and trigger re-discovery
                    mTriggerReconnectFlag = true;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void AOptitrackClientOrigin::ServerDiscoveredCallback(const sNatNetDiscoveredServer* pDiscoveredServer)
{
    if (mClientConnected)
    {
        // already connected...
        return;
    }

    // server discovered, unpack connection info
    if (ServerAddress != "0.0.0.0" && ServerAddress != pDiscoveredServer->serverAddress)
    {
        // newly found server does not match specified server address config, don't connect
        return;
    }

    if (ClientAddress != "0.0.0.0" && ClientAddress != pDiscoveredServer->localAddress)
    {
        // newly found server does not match specified local address config, don't connect
        return;
    }

    UE_LOG(LogOptitrack, Log, TEXT("Motive server discovered, connecting...\n"));

    // Initialize NatNet for discovered server
    sNatNetClientConnectParams connectParams;
    connectParams.connectionType = pDiscoveredServer->serverDescription.ConnectionMulticast ? ConnectionType_Multicast : ConnectionType_Unicast;
    connectParams.serverAddress = pDiscoveredServer->serverAddress;
    connectParams.localAddress = pDiscoveredServer->localAddress;
    ConnectNatNet(connectParams);
    mAsynchronousDiscoveryActiveFlag = false;
}


bool AOptitrackClientOrigin::ConnectNatNet(const sNatNetClientConnectParams& connectParams)
{
    const ErrorCode ConnectResult = Client->Connect(connectParams);
    if (ConnectResult != ErrorCode_OK)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: NatNetClient::Connect failed with return code %d"), static_cast<int32>(ConnectResult));
        ShutdownClient();
        return false;
    }

    bCanUseDataSubscription = false;
    sServerDescription serverDesc;
    ErrorCode getDescEc =  Client->GetServerDescription(&serverDesc);
    if (getDescEc == ErrorCode_OK && strcmp(serverDesc.szHostApp, "Motive")==0)
    {
        // determine if subscription is supported
        // need unicast connection as well as Motive version >= 2.2
        bCanUseDataSubscription = connectParams.connectionType == ConnectionType_Unicast;
        const int major = serverDesc.HostAppVersion[0];
        const int minor = serverDesc.HostAppVersion[1];
        const bool motiveVersionCompatible = major >= 3 || (major >= 2 && minor >= 2);
        bCanUseDataSubscription &= motiveVersionCompatible;
        
        mMotiveVersion[0] = major; 
        mMotiveVersion[1] = minor; 
        mMotiveVersion[2] = serverDesc.HostAppVersion[2]; //patch
    }

    if (!GetDataDescription())
    {
        return false;
    }

    if (bCanUseDataSubscription && bUseDataSubscription)
    {
        NatNetUnsubscribeAll();
    }

    mClientConnected = true;

    // Set local/global streaming setting as well as match bone naming convention
    SetDefaultSkeletonSettings();

    return true;
}


bool AOptitrackClientOrigin::NatNetSubscribeById(int32_t rbId, const std::string& type)
{
    if (Client == nullptr)
    {
        return false;
    }

    int32_t* pResponse = nullptr;
    int      responseSize = 0;

    std::string cmd = "SubscribeByID," + type + ",";
    cmd += std::to_string(rbId);

    const ErrorCode ec =
        Client ->SendMessageAndWait(cmd.c_str(), reinterpret_cast<void**>(&pResponse), &responseSize);

    if (ec != ErrorCode_OK)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: NatNetClient SubscribeById failed with return code %d"), static_cast<int32>(ec));
        return false;
    }

    if (pResponse == nullptr)
    {
        UE_LOG(LogOptitrack, Error, TEXT("NatNet SubscribeByID failed (pResponse == nullptr)\n"));
        return false;
    }
    else if (responseSize != sizeof(int32_t) || *pResponse != 0)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: NatNet SubscribeByID failed (response size %d, response[0] == %d)"), static_cast<int32>(responseSize), *pResponse);
        return false;
    }

    UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNetClient SubscribeById Succeeded, ID: %d"), static_cast<int32>(rbId));

    return true;
}

bool AOptitrackClientOrigin::NatNetSubscribeByName(const std::string& name, const std::string& type)
{
    if (Client == nullptr)
    {
        return false;
    }

    int32_t* pResponse = nullptr;
    int      responseSize = 0;

    std::string cmd = "SubscribeToData," + type + "," + name;

    const ErrorCode ec =
        Client->SendMessageAndWait(cmd.c_str(), reinterpret_cast<void**>(&pResponse), &responseSize);

    if (ec != ErrorCode_OK)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: NatNetClient SubscribeByName failed with return code %d"), static_cast<int32>(ec));
        return false;
    }

    if (pResponse == nullptr)
    {
        UE_LOG(LogOptitrack, Error, TEXT("NatNet SubscribeByName failed (pResponse == nullptr)\n"));
        return false;
    }
    else if (responseSize != sizeof(int32_t) || *pResponse != 0)
    {
        UE_LOG(LogOptitrack, Error, TEXT("AOptitrackClientOrigin: NatNet SubscribeByName failed (response size %d, response[0] == %d)"), static_cast<int32>(responseSize), *pResponse);
        return false;
    }

    // ljs revisit
    //UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNetClient SubscribeByName Succeeded, Name: %s"), name.c_str());

    return true;
}


bool AOptitrackClientOrigin::NatNetUnsubscribeAll()
{
    if (Client == nullptr)
    {
        return false;
    }

    // clear internal cached state of subscribed data
    SubscribedRigidBodyIds.Empty();
    SubscribedSkeletonNames.Empty();
    bSubscribedToLabeledMarkersFlag = false;

    int32_t* pResponse = nullptr;
    int      responseSize = 0;

    // Clear filter list.
    const int clearEc =
        Client->SendMessageAndWait("SubscribeToData", reinterpret_cast<void**>(&pResponse), &responseSize);

    if (clearEc != ErrorCode_OK)
    {
        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet filter clear failed (error code %d)"), static_cast<int32>(clearEc));
        return false;
    }

    if (pResponse == nullptr)
    {
        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet filter clear failed (pResponse == nullptr)"));
        return false;
    }
    else if (responseSize != sizeof(int32_t) || *pResponse != 0)
    {
        //DriverLog( "NatNet filter clear failed (response size %d, response[0] == %d)\n", responseSize, *pResponse );
        //return false;
    }

    // Clear filter list.
    const int noneEc = Client->SendMessageAndWait(
        "SubscribeToData,alltypes,none", reinterpret_cast<void**>(&pResponse), &responseSize);

    if (noneEc != ErrorCode_OK)
    {

        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet unsubscribe failed(error code %d)"), static_cast<int32>(noneEc));
        return false;
    }

    if (pResponse == nullptr)
    {
        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet unsubscribe failed (pResponse == nullptr)"));
        return false;
    }
    else if (responseSize != sizeof(int32_t) || *pResponse != 0)
    {
        UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet unsubscribe failed (response size %d, response[0] == %d)"), static_cast<int32>(responseSize), *pResponse);
        return false;
    }

    // Success.
    UE_LOG(LogOptitrack, Log, TEXT("AOptitrackClientOrigin: NatNet subscriptions successfully reset"));

    return true;
}