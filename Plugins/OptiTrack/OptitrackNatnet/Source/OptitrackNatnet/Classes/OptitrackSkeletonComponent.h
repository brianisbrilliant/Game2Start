//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <Components/ActorComponent.h>
#include "OptitrackClientOrigin.h"
#include "OptitrackSkeletonComponent.generated.h"

/**
* A component that drives the position and rotation of its actor's root
* component based on the extracted XY planar movement of a tracked skeleton's
* root motion / hip movement. Designed to work with FAnimNode_OptitrackSkeleton.
*/
UCLASS( ClassGroup="OptiTrack", meta=(BlueprintSpawnableComponent) )
class OPTITRACKNATNET_API UOptitrackSkeletonComponent : public UActorComponent
{
	GENERATED_BODY()

	UOptitrackSkeletonComponent( const FObjectInitializer& ObjectInitializer );

public:
	UPROPERTY( Replicated, EditAnywhere, BlueprintReadWrite, Category="Optitrack" )
	FName SourceSkeletonAssetName;

	/**
	* If your scene contains multiple client origin objects, you can specify
	* which one to use. If unset, this defaults to the first client origin
	* that's found in the world.
	*/
	UPROPERTY( EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category="Optitrack" )
	class AOptitrackClientOrigin* StreamingClientOrigin;

    /**
    * If asset isn't being streamed from Motive, hide skeleton.
    * Defaults to true.
    */
    UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Optitrack")
    bool HideOnInvalidDefinition = true;

protected:
	virtual void /*UActorComponent::*/BeginPlay() override;
	virtual void /*UActorComponent::*/TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

    void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	UPROPERTY()
	class UOptitrackAnimInstance* OptitrackAnimInstance;

	FOptitrackSkeletonDefinition SkeletonDefinition;
};
