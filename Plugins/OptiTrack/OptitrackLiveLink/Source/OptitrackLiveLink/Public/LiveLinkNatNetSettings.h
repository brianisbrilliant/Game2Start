//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <LiveLinkSourceSettings.h>

#include "LiveLinkNatNetSettings.generated.h"


UENUM( BlueprintType )
enum class EOptitrackLiveLinkConnectionType : uint8
{
	Multicast = 0     UMETA(DisplayName = "Multicast"),
	Unicast			  UMETA(DisplayName = "Unicast"),
};


struct OPTITRACKLIVELINK_API FOptitrackLiveLinkSettings
{
public:
	static FString ConnectionTypeToString( EOptitrackLiveLinkConnectionType ConnType );

	static FOptitrackLiveLinkSettings FromString( const FString& SettingsStr );

public:
	FString ToString() const;

	bool ConnectAutomatically = true;
	bool IncludeMarkers = false;
	FString ServerIpAddress = "127.0.0.1";
	FString ClientIpAddress = "127.0.0.1";
	EOptitrackLiveLinkConnectionType ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
};


/** Live link streaming settings */
UCLASS()
class OPTITRACKLIVELINK_API UOptitrackLiveLinkSourceSettings : public ULiveLinkSourceSettings
{
public:
	GENERATED_BODY()

	/** Origin of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset")
	FVector Location = FVector::ZeroVector;

	/** Orientation of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset")
	FRotator Orientation = FRotator::ZeroRotator;

	/** Scale of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset")
	float Scale = 1;

	/** Whether to create LiveLink subjects for labeled markers */
	UPROPERTY(EditAnywhere, Category = "Markers")
	bool CreateLabeledMarkerSubjects = false;

	/** Whether to create LiveLink subjects for unlabeled markers */
	UPROPERTY(EditAnywhere, Category = "Markers")
	bool CreateUnlabeledMarkerSubjects = false;

	/** Set LiveLink as timecode provider */
	UPROPERTY(EditAnywhere, Category = "TimecodeProvider")
	bool TimecodeProvider = false;

	/** Timecode provider subject name */
	UPROPERTY(EditAnywhere, Category = "TimecodeProvider")
	FName SubjectName;
};
