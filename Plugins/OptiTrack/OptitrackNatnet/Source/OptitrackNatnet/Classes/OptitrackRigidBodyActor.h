//======================================================================================================
// Copyright 2017, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <GameFramework/Actor.h>

#include "OptitrackRigidBodyActor.generated.h"


class UOptitrackRigidBodyComponent;


UCLASS( ComponentWrapperClass )
class OPTITRACKNATNET_API AOptitrackRigidBodyActor : public AActor
{
	GENERATED_UCLASS_BODY()

	UOptitrackRigidBodyComponent* GetRigidBodyComponent() { return RigidBodyComponent; }

	/**
	* If true, rigid body actor will hide if no associated asset is being streamed from Motive.
	*/
	UPROPERTY( EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Optitrack" )
	bool bHideOnInvalidDefinition = true;

protected:
	virtual void TickActor( float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction ) override;

private:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category="Rigid Body Actor", meta=(AllowPrivateAccess="true") )
	UOptitrackRigidBodyComponent* RigidBodyComponent;
};
