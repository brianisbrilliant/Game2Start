//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#include "OptitrackSkeletonComponent.h"

#include "OptitrackNatNet.h"
#include "OptitrackAnimInstance.h"
#include "OptitrackClientOrigin.h"

#include "Net/UnrealNetwork.h"
#include "Logging/LogMacros.h"

UOptitrackSkeletonComponent::UOptitrackSkeletonComponent( const FObjectInitializer& ObjectInitializer )
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_LastDemotable;
    SetIsReplicatedByDefault(true);
}

void UOptitrackSkeletonComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UOptitrackSkeletonComponent, SourceSkeletonAssetName);
}

void UOptitrackSkeletonComponent::BeginPlay()
{
	Super::BeginPlay();

	if ( StreamingClientOrigin == nullptr )
	{
		StreamingClientOrigin = AOptitrackClientOrigin::FindDefaultClientOrigin( GetWorld() );
        if (StreamingClientOrigin == nullptr)
        {
            UE_LOG(LogOptitrack, Warning, TEXT("UOptitrackSkeletonComponent::BeginPlay(): Unable to locate any client origin. Ensure there is one in the scene."));
            return;
        }
	}

	// TODO: Set anim node variables
	TInlineComponentArray< USkeletalMeshComponent* > SkelMeshComponents;
	GetOwner()->GetComponents( SkelMeshComponents );
	for ( USkeletalMeshComponent* SkelMeshComp : SkelMeshComponents )
	{
		if ( UOptitrackAnimInstance* AnimInstance = Cast<UOptitrackAnimInstance>( SkelMeshComp->GetAnimInstance() ) )
		{
			OptitrackAnimInstance = AnimInstance;

#if 0
			OptitrackAnimInstance->SetRootMotionMode( ERootMotionMode::RootMotionFromEverything );
#endif

			break;
		}
	}

	if ( OptitrackAnimInstance )
	{
		if ( OptitrackAnimInstance->SourceSkeletonAssetName == NAME_None )
		{
			OptitrackAnimInstance->SourceSkeletonAssetName = SourceSkeletonAssetName;
		}

		if ( OptitrackAnimInstance->StreamingClientOrigin == nullptr )
		{
			OptitrackAnimInstance->StreamingClientOrigin = StreamingClientOrigin;
		}   

	}

}


void UOptitrackSkeletonComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

#if 0
	if ( OptitrackAnimInstance == nullptr || OptitrackAnimInstance->GetSkelMeshComponent() == nullptr )
	{
		return;
	}

	USkeletalMeshComponent* SkelMeshComp = OptitrackAnimInstance->GetSkelMeshComponent();

	FRootMotionMovementParams RootMotion = SkelMeshComp->ConsumeRootMotion();
	RootMotion.Set( SkelMeshComp->ConvertLocalRootMotionToWorld( RootMotion.GetRootMotionTransform() ) );
#endif

	if ( StreamingClientOrigin == nullptr )
	{
		return;
	}

    if (HideOnInvalidDefinition)
    {
        FOptitrackSkeletonState SkelState;
        if (StreamingClientOrigin->GetLatestSkeletonStateByName(SourceSkeletonAssetName, SkelState))
        {
            GetOwner()->SetActorHiddenInGame(false);
        }
        else if (!StreamingClientOrigin->FindSkeletonDefinition(SourceSkeletonAssetName, SkeletonDefinition))
        {
            GetOwner()->SetActorHiddenInGame(true);
        }
    }
}
