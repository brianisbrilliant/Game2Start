//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 

#pragma once

#include "LiveLinkNatNetSettings.h"

#include <ILiveLinkSource.h>
#include <HAL/ThreadSafeBool.h>
#include <mutex>

#pragma pack(push, 8)
#	include <NatNetCAPI.h>
#	include <NatNetClient.h>
#	include <NatNetTypes.h>
#pragma pack(pop)


UENUM( BlueprintType )
enum class EOptitrackLiveLinkBoneNamingConvention : uint8
{
	Motive     UMETA(DisplayName = "Motive"),
	FBX        UMETA(DisplayName = "FBX"),
	BVH		   UMETA(DisplayName = "BVH"),
};


class OPTITRACKLIVELINK_API FLiveLinkNatNetSource : public ILiveLinkSource
{
public:
	FLiveLinkNatNetSource( const FOptitrackLiveLinkSettings& Settings );
	virtual ~FLiveLinkNatNetSource();

	//~ Begin ILiveLinkSource interface
	virtual void ReceiveClient( ILiveLinkClient* InClient, FGuid InSourceGuid ) override;
	virtual void InitializeSettings( ULiveLinkSourceSettings* Settings ) override;
	//virtual bool CanBeDisplayedInUI() const override { return true; }
	virtual bool IsSourceStillValid() const override { return NNClient && !bLLShuttingDown; }
	virtual bool RequestSourceShutdown() override;

	virtual FText GetSourceType() const override { return SourceType; };
	virtual FText GetSourceMachineName() const override { return SourceMachineName; }
	virtual FText GetSourceStatus() const override { return SourceStatus; }

	virtual TSubclassOf<ULiveLinkSourceSettings> GetSettingsClass() const override;

	virtual void OnSettingsChanged( ULiveLinkSourceSettings* Settings, const FPropertyChangedEvent& PropertyChangedEvent ) override;
	//~ End ILiveLinkSource interface

	void SetSourceSettings( UOptitrackLiveLinkSourceSettings& Settings );

private:
	bool ConnectToNatNet( const sNatNetClientConnectParams& connectParams );

	void SetTimecodeProvider();
	void ResetTimecodeProvider() const;
	bool SetTimecodeProviderSubject( const FName& subjectName );

	void GenerateDataDescriptions();
	void ClearDataDescriptions();

	static void NATNET_CALLCONV NatNetFrameReceivedCallback_Thunk( sFrameOfMocapData* NewFrame, void* pContext );
	static void NATNET_CALLCONV ServerDiscoveredCallback_Thunk( const sNatNetDiscoveredServer* pDiscoveredServer, void* pUserContext );
	void NatNetFrameReceivedCallback( sFrameOfMocapData* NewFrame );
	void ServerDiscoveredCallback( const sNatNetDiscoveredServer* pDiscoveredServer );
	void HelperThreadProc();

	void NatNetToLiveLinkTimeCode( int rate, int hours, int minutes, int seconds, int frames, FQualifiedFrameTime& LLTimeCode );

	bool SetBoneNamingConvention( EOptitrackLiveLinkBoneNamingConvention BoneNamingConvention );
	bool SetSkeletonUseLocalCoordinates( bool LocalCoordinates );
	int GetLiveEditMode();
	float GetFrameRate();

	FFrameRate GetComplexTimecodeRate();

	// Settings that control how to connect to NatNet
	FOptitrackLiveLinkSettings NatNetSettings;

	// Connection labels that appear in the LiveLink window.
	FText SourceType;
	FText SourceMachineName;
	FText SourceStatus;

	ILiveLinkClient* LLClient = nullptr;
	FGuid LLSourceGuid;
	FThreadSafeBool bLLShuttingDown = false;

	// OptiTrack connection information
	NatNetClient* NNClient = nullptr;
	sDataDescriptions* NNDataDescs = nullptr;

	// List of assets created
	TArray<FLiveLinkSubjectKey> LLAssets;
	std::mutex AssetMutex;
	bool bAssetListChanged = false;

	// Correlates asset definitions and frame data
	TMap< int32, FName > NNSkelIdToSubjectName;
	TMap< int32, FName > NNRigidBodyIdToSubjectName;
	TMap< int32, FName > NNTMarkersetIdToSubjectName;

	int TimecodeWaitBuffer = 0;
	int TimecodeMaxSubFrame = -1;
	float NNFrameRate = -1.0;
	float NNTimecodeRate = -1.0;

	// Stream data origin
	FTransform StreamDataOrigin = FTransform::Identity;
	float StreamDataScale = 1;

	/** Auto discovery and disconnection detection parameters*/
	bool bAsynchronousDiscoveryActiveFlag = false;
	bool bClientConnected = false;
	bool bTriggerReconnectFlag = false;
	NatNetDiscoveryHandle NatNetDiscoveryHandle = nullptr;
	uint64_t NatNetTimestampEpoch = 0;
	uint64_t NatNetLastRecievedTimestamp = UINT64_MAX;

	bool bExitHelperThread = false;
	std::thread HelperThread;

	bool bDetectDisconnect = false;
	bool bRefreshDataDescriptions = false;
	bool bUpdateFrameRate = false;
	bool bDetectLiveEditModeChange = false;
	bool bMotiveLiveMode = false;
	bool bLabeledMarkersEnabled = false;
	bool bUnlabeledMarkersEnabled = false;

	// NatNet keeps MAX_UNLABELED_MARKERS = 1000
	static const int kMaximumUnlabeledMarkers = MAX_UNLABELED_MARKERS;

public:
	static const FString LiveLinkNatNetSourceName;
};
