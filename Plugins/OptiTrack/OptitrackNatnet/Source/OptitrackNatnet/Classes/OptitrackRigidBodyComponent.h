//======================================================================================================
// Copyright 2017, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <SceneViewExtension.h>
#include <LateUpdateManager.h>
#include <Components/SceneComponent.h>
#include "OptitrackRigidBodyComponent.generated.h"


/**
  * A component whose position and orientation is driven by the pose of the
  * specified tracked rigid body. Supports render thread "late updates" for
  * reduced tracking latency.
  */
UCLASS( Blueprintable, ClassGroup="OptiTrack", meta=(BlueprintSpawnableComponent) )
class OPTITRACKNATNET_API UOptitrackRigidBodyComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

	virtual ~UOptitrackRigidBodyComponent();

	/** ID of the rigid body used to drive this component's transform. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Optitrack" )
	int32 StreamingId;

	/** If false, render transforms within the rigid body hierarchy will be updated a second time immediately before rendering. */
	UPROPERTY( EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category="Optitrack" )
	uint32 bDisableLowLatencyUpdate : 1;

    /** If true, compensate rigid body to account for network/software latency.*/
    UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Optitrack")
    bool bNetworkCompensation = true;

	/**
	* If your scene contains multiple client origin objects, you can specify
	* which one to use. If unset, this defaults to the first client origin
	* that's found in the world.
	*/
	UPROPERTY( EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category="Optitrack" )
	class AOptitrackClientOrigin* TrackingOrigin;

    /**
    * If true, rigid body transform from Motive will be applied with respect to parent transform instead of the client origin.
    */
    UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Optitrack")
    bool RespectParentTransform = false;

protected:
	//~ Begin UActorComponent Interface
	virtual void BeginPlay() override;
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	virtual void SendRenderTransform_Concurrent() override;
	//~ End UActorComponent Interface

private:
	/** View extension object that can persist on the render thread without the rigid body component. */
	class FViewExtension : public FSceneViewExtensionBase
	{
	public:
		FViewExtension( const FAutoRegister& AutoRegister, UOptitrackRigidBodyComponent* InRigidBodyComponent )
			: FSceneViewExtensionBase( AutoRegister )
			, RigidBodyComponent( InRigidBodyComponent )
		{}
		virtual ~FViewExtension() {}

		//~ Begin ISceneViewExtension Interface
		virtual void SetupViewFamily( FSceneViewFamily& InViewFamily ) override {}
		virtual void SetupView( FSceneViewFamily& InViewFamily, FSceneView& InView ) override {}
		virtual void BeginRenderViewFamily( FSceneViewFamily& InViewFamily ) override;
		virtual void PreRenderView_RenderThread( FRHICommandListImmediate& RHICmdList, FSceneView& InView ) override {}
		virtual void PreRenderViewFamily_RenderThread( FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily ) override;
		virtual int32 GetPriority() const override { return -10; }
		virtual bool IsActiveThisFrame( class FViewport* InViewport ) const;
		//~ End ISceneViewExtension Interface

	private:
		friend class UOptitrackRigidBodyComponent;

		/** Rigid body component associated with this view extension */
		UOptitrackRigidBodyComponent* RigidBodyComponent;
		FLateUpdateManager LateUpdate;
	};

	TSharedPtr< FViewExtension, ESPMode::ThreadSafe > ViewExtension;
	FTransform RenderThreadRelativeTransform;
	FVector RenderThreadComponentScale;
	double RenderThreadPoseTimestamp;
};
