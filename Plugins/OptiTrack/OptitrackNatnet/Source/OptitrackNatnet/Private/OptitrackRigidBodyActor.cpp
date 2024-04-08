//======================================================================================================
// Copyright 2017, NaturalPoint Inc.
//====================================================================================================== 

#include "OptitrackRigidBodyActor.h"
#include "OptitrackRigidBodyComponent.h"
#include "OptitrackClientOrigin.h"


AOptitrackRigidBodyActor::AOptitrackRigidBodyActor( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	RigidBodyComponent = CreateDefaultSubobject<UOptitrackRigidBodyComponent>( TEXT( "RigidBodyComponent" ) );

	RootComponent = RigidBodyComponent;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	PrimaryActorTick.bTickEvenWhenPaused = true;
}


void AOptitrackRigidBodyActor::TickActor( float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction )
{
	Super::TickActor( DeltaTime, TickType, ThisTickFunction );

	FOptitrackRigidBodyState rbState;
	if( RigidBodyComponent->TrackingOrigin && bHideOnInvalidDefinition )
	{
		if( RigidBodyComponent->TrackingOrigin->GetLatestRigidBodyState( RigidBodyComponent->StreamingId, rbState ) )
		{
			SetActorHiddenInGame( false );
		}
		else
		{
			SetActorHiddenInGame( true );
		}
		
	}
}

