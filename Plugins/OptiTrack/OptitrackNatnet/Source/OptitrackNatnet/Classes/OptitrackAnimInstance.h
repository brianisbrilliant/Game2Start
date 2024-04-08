//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <Animation/AnimInstance.h>
#include "OptitrackAnimInstance.generated.h"

class UOptitrackSkeletonComponent;

UCLASS( Transient )
class OPTITRACKNATNET_API UOptitrackAnimInstance : public UAnimInstance
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Optitrack" )
	FName SourceSkeletonAssetName;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Optitrack" )
	class AOptitrackClientOrigin* StreamingClientOrigin;
};
