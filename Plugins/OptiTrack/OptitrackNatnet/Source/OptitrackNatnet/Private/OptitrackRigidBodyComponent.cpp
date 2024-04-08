//======================================================================================================
// Copyright 2017, NaturalPoint Inc.
//====================================================================================================== 
#include "OptitrackRigidBodyComponent.h"
#include "OptitrackClientOrigin.h"

#include <Engine/Engine.h>
#include <SceneView.h>
#include <Logging/MessageLog.h>
#include <Misc/UObjectToken.h>


#define LOCTEXT_NAMESPACE "OptitrackNatnet"


namespace
{
	// This is to prevent destruction of rigid body components while they are being accessed by the render thread.
	FCriticalSection CritSect;

	// Console variable for disabling rigid body late updates globally.
	TAutoConsoleVariable<int32> CVarEnableRigidBodyLateUpdate(
		TEXT( "OptiTrack.EnableRigidBodyLateUpdate" ),
		1,
		TEXT( "This command allows you to specify whether the rigid body late update is applied.\n" )
		TEXT( " 0: don't use late update\n" )
		TEXT( " 1: use late update (default)" ),
		ECVF_Cheat
	);
} // anonymous namespace



UOptitrackRigidBodyComponent::UOptitrackRigidBodyComponent( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;
	PrimaryComponentTick.bTickEvenWhenPaused = true;

	bAutoActivate = true;

	StreamingId = 0;
	bDisableLowLatencyUpdate = false;
}


UOptitrackRigidBodyComponent::~UOptitrackRigidBodyComponent()
{
	if ( ViewExtension.IsValid() )
	{
		{
			// This component could be getting accessed from the render thread, so it needs to wait
			// before clearing RigidBodyComponent and allowing the destructor to continue.
			FScopeLock ScopeLock( &CritSect );
			ViewExtension->RigidBodyComponent = nullptr;
		}

		ViewExtension.Reset();
	}
}


void UOptitrackRigidBodyComponent::BeginPlay()
{
	Super::BeginPlay();

	if ( TrackingOrigin == nullptr )
	{
		TrackingOrigin = AOptitrackClientOrigin::FindDefaultClientOrigin( GetWorld() );
	}

	TArray<USceneComponent*> Children;
	GetChildrenComponents( false, Children );
	if ( Children.Num() == 0 )
	{
		FMessageLog( "PIE" ).Error()
			->AddToken( FUObjectToken::Create( this ) )
			->AddToken( FTextToken::Create( LOCTEXT( "RigidBodyNoChildren",
				"OptiTrack rigid body component only affects child components, but has no children. "
				"Did you intend to make it the root component instead?"
			) ) );
	}
}


void UOptitrackRigidBodyComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if ( IsActive() == false || TrackingOrigin == nullptr || GetOwner() == nullptr || GetOwner()->GetRootComponent() == nullptr )
	{
		return;
	}

	FOptitrackRigidBodyState rbState;
    if (!RespectParentTransform)
    {
        if (TrackingOrigin->GetLatestRigidBodyState(StreamingId, rbState, bNetworkCompensation))
        {
            SetWorldLocationAndRotation(rbState.Position, rbState.Orientation);
        }
    }
    else
    {
		if( TrackingOrigin->GetLatestRigidBodyStateUntransformed( StreamingId, rbState, bNetworkCompensation ) )
		{
			SetRelativeLocationAndRotation( rbState.Position, rbState.Orientation );
		}
    }

	if ( ! ViewExtension.IsValid() && GEngine )
	{
		ViewExtension = FSceneViewExtensions::NewExtension<FViewExtension>( this );
	}
}


void UOptitrackRigidBodyComponent::SendRenderTransform_Concurrent()
{
	RenderThreadRelativeTransform = GetRelativeTransform();
	RenderThreadComponentScale = GetComponentScale();
	Super::SendRenderTransform_Concurrent();
}


//////////////////////////////////////////////////////////////////////////
// UOptitrackRigidBodyComponent::FViewExtension
//////////////////////////////////////////////////////////////////////////


void UOptitrackRigidBodyComponent::FViewExtension::BeginRenderViewFamily( FSceneViewFamily& InViewFamily )
{
	if ( ! RigidBodyComponent )
	{
		return;
	}

	// Set up the late update state for the rigid body component.
	LateUpdate.Setup( RigidBodyComponent->CalcNewComponentToWorld( FTransform() ), RigidBodyComponent, false );
}


void UOptitrackRigidBodyComponent::FViewExtension::PreRenderViewFamily_RenderThread( FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily )
{
	if ( ! RigidBodyComponent )
	{
		return;
	}

	FTransform OldTransform;
	FTransform NewTransform;

	{
		FScopeLock ScopeLock( &CritSect );

		if ( ! RigidBodyComponent || ! RigidBodyComponent->TrackingOrigin )
		{
			return;
		}

		FOptitrackRigidBodyState rbState;
        if (!RigidBodyComponent->RespectParentTransform)
        {
            if (!RigidBodyComponent->TrackingOrigin->GetLatestRigidBodyState(RigidBodyComponent->StreamingId, rbState, RigidBodyComponent->bNetworkCompensation))
            {
                return;
            }
        }
        else
        {
            if (!RigidBodyComponent->TrackingOrigin->GetLatestRigidBodyStateUntransformed(RigidBodyComponent->StreamingId, rbState, RigidBodyComponent->bNetworkCompensation))
            {
                return;
            }
        }

		OldTransform = RigidBodyComponent->RenderThreadRelativeTransform;
		NewTransform = FTransform( rbState.Orientation, rbState.Position, RigidBodyComponent->RenderThreadComponentScale );

        if (!RigidBodyComponent->RespectParentTransform && RigidBodyComponent->GetAttachParent())
        {
            // Check to see if the asset name is valid
            FName RBName = RigidBodyComponent->GetAttachSocketName();
            if( !RBName.IsValid() )
            {
                UE_LOG( LogTemp, Warning, TEXT( "UOptitrackRigidBodyComponent::FViewExtension::PreRenderViewFamily_RenderThread:: ASName NOT VALID!!" ) );
                return;
            }

            // Make Sure we aren't marked for destruction
            if( IsValidChecked( RigidBodyComponent ) || IsValidChecked( RigidBodyComponent->GetAttachParent() ) )
            {
                UE_LOG( LogTemp, Warning, TEXT( "UOptitrackRigidBodyComponent::FViewExtension::PreRenderViewFamily_RenderThread:: Rigid Body Marked for Distruction!!" ) );
                return;
            }

            FTransform ParentToWorld = RigidBodyComponent->GetAttachParent()->GetSocketTransform( RBName );
            NewTransform = NewTransform * ParentToWorld.Inverse();
        }
	}

	// Tell the late update manager to apply the offset to the scene components.
	LateUpdate.Apply_RenderThread( InViewFamily.Scene, OldTransform, NewTransform );
}

bool UOptitrackRigidBodyComponent::FViewExtension::IsActiveThisFrame( class FViewport* InViewport ) const
{
	check( IsInGameThread() );
	return RigidBodyComponent && ! RigidBodyComponent->bDisableLowLatencyUpdate && CVarEnableRigidBodyLateUpdate.GetValueOnGameThread();
}
