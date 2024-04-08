//======================================================================================================
// Copyright 2016, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <GameFramework/Actor.h>
#include <Misc/Timecode.h>

#include "OptitrackSkeletonTypes.h"

#pragma pack(push, 8)
#	include <NatNetCAPI.h>
#	include <NatNetClient.h>
#	include <NatNetTypes.h>
#pragma pack(pop)

#include <thread>
#include <string>

#include "OptitrackClientOrigin.generated.h"

UENUM( BlueprintType )
enum class EOptitrackTimestampType : uint8
{
	/** We don't know what the server supports until after we've received at least one frame. */
	Unknown = 0,

	/** When the NatNet frame callback occurred. Fallback when precise metrics are unavailable. */
	LocalArrivalTime,

	/** Clock synchronized estimate of when the camera data became available on the server. */
	ServerAggregationTime,

	/** Clock synchronized estimate of when the camera exposure occurred. */
	ServerExposureTime,
};


/**
* Represents a pose for a tracked rigid body.
*/
USTRUCT( BlueprintType )
struct FOptitrackRigidBodyState
{
	GENERATED_USTRUCT_BODY()

	/**
	 * Timestamp corresponding to this rigid body pose. Exact semantics can vary depending on
	 * server support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.
	 *
	 * Can be directly compared with values returned by FPlatformTime::Seconds().
	 */
	UPROPERTY()
	double TimestampPlatformSeconds;

	/** Position in tracking space. */
	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	FVector Position;

	/** Orientation in tracking space. */
	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	FQuat Orientation;
};

/** 
* Represents a tracked marker.
*/
USTRUCT(BlueprintType)
struct FOptitrackMarkerState
{
    GENERATED_USTRUCT_BODY()

    /**
    * Timestamp corresponding to this marker. Exact semantics can vary depending on
    * server support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.
    *
    * Can be directly compared with values returned by FPlatformTime::Seconds().
    */
    UPROPERTY()
    double TimestampPlatformSeconds;

    /** Position in tracking space. */
    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    FVector Position;

    /** Marker Id in Motive. */
    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    int32 Id;
};

/**
* Represents a camera object.
*/
USTRUCT( BlueprintType )
struct FOptitrackCamera
{
	GENERATED_USTRUCT_BODY()

    /** Position in tracking space. */
    UPROPERTY( BlueprintReadOnly, Category = "Optitrack" )
	FName Name;

	/** Position in tracking space. */
	UPROPERTY( BlueprintReadOnly, Category = "Optitrack" )
	FVector Position;

	/** Marker Id in Motive. */
	UPROPERTY( BlueprintReadOnly, Category = "Optitrack" )
	FQuat Orientation;
};

UENUM( BlueprintType )
enum class EOptitrackClientConnectionType : uint8
{
	Multicast = 0     UMETA(DisplayName = "Multicast"),
	Unicast			  UMETA(DisplayName = "Unicast"),
};

UENUM( BlueprintType )
enum class EOptitrackForwardAxisType : uint8
{
    Z_Positive = 0 UMETA(DisplayName = "+Z Forward"),
    X_Positive     UMETA(DisplayName = "+X Forward"),
};

/**
*
*/
UCLASS()
class OPTITRACKNATNET_API AOptitrackClientOrigin : public AActor
{
	GENERATED_UCLASS_BODY()

    /** If true, the NatNet client will search for and connect to Motive automatically . */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optitrack")
    bool bAutoConnect = true;

	/** The network address of the NatNet server to connect to. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!bAutoConnect"), Category="Optitrack" )
	FString ServerAddress;

	/** The address of the local network interface to use. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!bAutoConnect"), Category="Optitrack" )
	FString ClientAddress;

	/** The NatNet client type to instantiate. Must match the setting of the NatNet server. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!bAutoConnect"), Category="Optitrack" )
	EOptitrackClientConnectionType ConnectionType;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Optitrack" )
	EOptitrackBoneNamingConvention BoneNamingConvention = EOptitrackBoneNamingConvention::FBX;

    /** If true, call InitializeClient and connect automatically during PreInitializeComponents. */
    UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Optitrack" )
    bool bAutoInitialize = true;

    /** If true and connection is Unicast, the NatNet client will have an opt-in policy for receiving data from Motive. Data related to Rigid bodies/Skeletons not referenced in the scene will not be streamed to this client. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Optitrack")
    bool bUseDataSubscription = true;

	/** If true, draw Motive and UE bone locations (white and green respectively)*/
	UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Optitrack" )
	uint8 bDrawDebugSkeletons : 1;

	/** If true, draw Motive's labeled marker locations*/
	UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Optitrack" )
	bool bDrawMarkers = false;

    /** Color used for labeled marker locations*/
    UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Optitrack" )
	FColor DrawMarkersColor = FColor::Blue;

    /** If true, draw Motive's camera locations (Motive 3.0+ only)*/
    UPROPERTY( EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Optitrack" )
    bool bDrawDebugCameras = false;


    DECLARE_EVENT_TwoParams( AOptitrackClientOrigin, FOnNatNetFrameReceivedEvent, struct sFrameOfMocapData*, double );
    FOnNatNetFrameReceivedEvent& OnNatNetFrameReceived() { return NatNetFrameReceivedEvent; }

	/**
	 * Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the
	 * @RbId parameter. Note that this data can be stale if the rigid body in question hasn't
	 * streamed any new data recently.
	 *
	 * The tracking space pose is transformed by the offset/rotation/scale of this actor,
	 * such that the placement of this actor corresponds to the tracking space origin.
	 *
	 * @param OutRbState Receives latest available rigid body state (if any).
	 * @return True if any rigid body state was available for the specified ID,
	 *         otherwise false.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	bool GetLatestRigidBodyState( int32 RbId, FOptitrackRigidBodyState& OutRbState, bool networkCompensation = false );

    /**
    * Retrieves latest available FOptitrackMarkerState for the marker identified by the
    * @markerId parameter. Note that this data can be stale/non-existent if the marker
    * hasn't streamed any new data recently.
    *
    * The tracking space pose is transformed by the offset/rotation/scale of this actor,
    * such that the placement of this actor corresponds to the tracking space origin.
    *
    * @param OutMarkerState Receives latest available marker state (if any).
    * @return True if any marker state was available for the specified ID,
    *         otherwise false.
    */
    UFUNCTION(BlueprintCallable, Category = "Optitrack")
    bool GetLatestMarkerState(int32 markerId, FOptitrackMarkerState& OutMarkerState);

    /**
    * TODO
    *
    * @param OutSkelState
    * @return True if any skeleton state was available for the specified ID,
    *         otherwise false.
    */
    UFUNCTION( BlueprintCallable, Category="Optitrack|Advanced" )
    bool GetLatestSkeletonState( int32 SkelId, FOptitrackSkeletonState& OutSkelState );

    UFUNCTION(BlueprintCallable, Category = "Optitrack|Advanced")
    bool GetLatestSkeletonStateByName(const FName& SkelName, FOptitrackSkeletonState& OutSkelState);

    UFUNCTION( BlueprintCallable, Category="Optitrack|Advanced" )
    bool FindSkeletonDefinition( const FName& SkeletonName, FOptitrackSkeletonDefinition& OutSkelDef ) const;

	/**
	 * Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the
	 * @RbId parameter. Note that this data can be stale if the rigid body in question hasn't
	 * streamed any new data recently.
	 *
	 * This "Untransformed" version returns the tracking space pose, applying only the global
	 * WorldToMeters scale. It does not take into account the transform of this actor.
	 *
	 * @param OutRbState Receives latest available rigid body state (if any).
	 * @return True if any rigid body state was available for the specified ID,
	 *         otherwise false.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack|Advanced" )
	bool GetLatestRigidBodyStateUntransformed( int32 RbId, FOptitrackRigidBodyState& OutRbStat, bool networkCompensation = false );

    /**
    * Retrieves latest available FOptitrackMarkerState for the marker identified by the
    * @markerId parameter. Note that this data can be stale/non-existent if the marker
    * hasn't streamed any new data recently.
    *
    * This "Untransformed" version returns the tracking space pose, applying only the global
    * WorldToMeters scale. It does not take into account the transform of this actor.
    *
    * @param OutMarkerState Receives latest available marker state (if any).
    * @return True if any marker state was available for the specified ID,
    *         otherwise false.
    */
    UFUNCTION(BlueprintCallable, Category = "Optitrack|Advanced")
    bool GetLatestMarkerStateUntransformed(int32 markerId, FOptitrackMarkerState& OutMarkerState);

	/** Describes the semantics of @FOptitrackRigidBodyState::TimestampPlatformSeconds values. */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	EOptitrackTimestampType GetTimestampType() const { return TimestampType; }

	UFUNCTION(BlueprintCallable, Category = "Optitrack")
	bool GetLatestTimecode(FTimecode &OutTimecode) const;

	/**
	 * Helper for the common case where only a single client origin is present.
	 * Used to provide a default for any UOptitrackRigidBody components which
	 * don't otherwise specify a particular origin to use.
	 * Note: This is potentially expensive and the result should be cached.
	 * @return The first AOptitrackClientOrigin actor found in @World.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	static AOptitrackClientOrigin* FindDefaultClientOrigin( UWorld* World );

	/**
	 * Finds the first AOptitrackClientOrigin specifying an HMD rigid body ID.
	 * Note: This is potentially expensive and the result should be cached.
	 * @return The first suitable AOptitrackClientOrigin actor found in @World.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	static AOptitrackClientOrigin* FindHmdClientOrigin( UWorld* World );

	/**
	 * Returns true if the last call to InitializeClient succeeded,
	 * and ShutdownClient has not been called subsequently.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	bool IsClientInitialized() const { return Client != nullptr; }

    /**
    * Returns true if the Client has successfully connected to Motive
    */
    UFUNCTION(BlueprintCallable, Category = "Optitrack")
    bool IsClientConnected() const { return mClientConnected; }

	/**
	 * Attempt to initialize NatNet and connect to the server.
	 * Invalid to call if @IsClientInitialized() returns true.
	 * @return True on success, false on failure.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	bool InitializeClient();

    /**
    * Request NatNet data description from server.
    * Invalid to call if @IsClientInitialized() returns false.
    * @return True on success, false on failure.
    */
    UFUNCTION(BlueprintCallable, Category = "Optitrack")
    bool GetDataDescription();

	/**
	 * Attempt to shut down any existing NatNet client.
	 * Invalid to call if @IsClientInitialized() returns false.
	 * @return True on success, false on failure.
	 */
	UFUNCTION( BlueprintCallable, Category="Optitrack" )
	bool ShutdownClient();

public:
	void NatNetFrameReceivedCallback_Internal( struct sFrameOfMocapData* NewFrame );
    void ServerDiscoveredCallback(const sNatNetDiscoveredServer* pDiscoveredServer);
    void ValidateAuthenticationToken(const char* challengeToken, char* authToken);

protected:
	//~ Begin AActor Interface
	virtual void PreInitializeComponents() override;
    virtual void BeginPlay();
	virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;
    virtual void Tick(float DeltaSeconds) override;

private:
    bool SetDefaultSkeletonSettings();
    bool NeedUpdateDataDescription = false;

	class NatNetClient* Client = nullptr;
    void ThreadProc_DetectDisconnection();
    bool ConnectNatNet(const sNatNetClientConnectParams& params);
	TArray< int32 > mMotiveVersion = { 0, 0, 0, 0 };

    bool NatNetSubscribeById(int32_t rbId, const std::string& type = "RigidBody");
    bool NatNetSubscribeByName(const std::string& name, const std::string& type);
    bool NatNetUnsubscribeAll();
    TSet<int32> SubscribedRigidBodyIds;
    TSet<FName> SubscribedSkeletonNames;
    bool bSubscribedToLabeledMarkersFlag = false;
    bool bCanUseDataSubscription = false; // flag for internal multicast/unicast

    /** Auto discovery and disconnection detection parameters*/
    bool mDetectDisconnectionExitFlag = false;
    bool mAsynchronousDiscoveryActiveFlag = false;
    bool mClientConnected = false;
    bool mTriggerReconnectFlag = false;
    NatNetDiscoveryHandle mNatNetDiscoveryHandle = nullptr;
    uint64_t mNatNetTimestampEpoch = 0;
    uint64_t mNatNetLastRecievedTimestamp = UINT64_MAX;
    std::thread mDetectDisconnectionThread;

	/** Controls access to @LatestRigidBodyStates map. */
	mutable FCriticalSection FrameUpdateLock;

	/** Copied from AWorldSettings::WorldToMeters for use in the NatNet callback (which happens on another thread). */
	float CachedWorldToMeters;

    TMap< int32, FOptitrackSkeletonDefinition > SkeletonDefinitions;
    TMap< FName, int32> SkeletonNameToIdMap;

	TArray< FOptitrackCamera > CameraDefinitions;

    /** Key is rigid body ID, value is latest pose available for that rigid body. */
    TMap< int32, FOptitrackRigidBodyState > LatestRigidBodyStates;

    /** Key is skeleton ID, value is latest set of bone poses available for that skeleton. */
    TMap< int32, FOptitrackSkeletonState > LatestSkeletonStates;

    /** Key is marker ID, value is latest position of marker available. */
    TMap< int32, FOptitrackMarkerState> LatestMarkerStates;

	EOptitrackTimestampType TimestampType = EOptitrackTimestampType::Unknown;

	FTimecode LatestTimecode;

	FOnNatNetFrameReceivedEvent NatNetFrameReceivedEvent;

#if ! UE_BUILD_SHIPPING
private:
	friend class AOptitrackDebugHUD;

	struct FTimingStats
	{
		static const uint32 kSampleCount = 400;

		int32 CurrentIndex;
		TArray< float > TotalLatencySamples;
		TArray< float > NetworkLatencySamples;
		TArray< float > ArrivalPeriodSamples;

		FTimingStats()
			: CurrentIndex( 0 )
		{
			TotalLatencySamples.AddZeroed( kSampleCount );
			NetworkLatencySamples.AddZeroed( kSampleCount );
			ArrivalPeriodSamples.AddZeroed( kSampleCount );
		}

		void RecordSamples( float totalLatency, float networkLatency, float arrivalPeriod )
		{
			TotalLatencySamples[CurrentIndex] = totalLatency;
			NetworkLatencySamples[CurrentIndex] = networkLatency;
			ArrivalPeriodSamples[CurrentIndex] = arrivalPeriod;

			if ( ++CurrentIndex == kSampleCount )
			{
				CurrentIndex = 0;
			}
		}
	};

	double LastArrivalTimestamp = 0.0;
	FTimingStats TimingStats;
#endif // #if ! UE_BUILD_SHIPPING
};
