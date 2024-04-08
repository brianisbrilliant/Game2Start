//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <Animation/AnimNodeBase.h>
#include <BoneControllers/AnimNode_SkeletalControlBase.h>

#include <array>
#include <map>

#include "OptitrackSkeletonTypes.h"

#include "AnimNode_OptitrackSkeleton.generated.h"


#define OPTITRACK_SKELNODE_DEBUGDRAW (1 && !(UE_BUILD_SHIPPING || UE_BUILD_TEST))

struct FOptitrackBoneReference
{
    // used for bones that may have a socket associated with it
    // TargetBone is the current bone (or parent bone if associated with a socket), always valid
    FBoneReference TargetBone;
    // SocketTransform is only non-identity transform if associated with a socket reference
	FTransform SocketTransform;
};

USTRUCT( BlueprintType )
struct OPTITRACKNATNET_API FAnimNode_OptitrackSkeleton : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	FAnimNode_OptitrackSkeleton();

	virtual void /*FAnimNode_Base::*/Initialize_AnyThread( const FAnimationInitializeContext& Context ) override;
	virtual void /*FAnimNode_Base::*/CacheBones_AnyThread( const FAnimationCacheBonesContext& Context ) override;
	virtual void /*FAnimNode_Base::*/Update_AnyThread( const FAnimationUpdateContext& Context ) override;
	virtual void /*FAnimNode_Base::*/EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output) final;


public:
#if WITH_EDITORONLY_DATA
	bool HasRetargetBasePose() const { return RetargetBasePose.Num() > 0; }
	bool UpdateRetargetBasePose();
#endif

	UPROPERTY()//( EditAnywhere, BlueprintReadWrite, Category="Retargeting" )
	USkeletalMesh* RetargetBaseMesh;

	UPROPERTY(EditAnywhere, EditFixedSize, Category = "Retargeting")
	TArray<FBoneSocketTarget> BoneSockets;

	TArray<FOptitrackBoneReference> OptitrackBoneMappings;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinShownByDefault) )
	FName SourceSkeletonAssetName;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinShownByDefault) )
	class AOptitrackClientOrigin* StreamingClientOrigin;

    /** Scale UE bones to match tracked skeleton*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinShownByDefault))
    bool ScaleBones = true;

    /** Infer rotation of reference bone poses to match Motive T-Pose*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinShownByDefault))
    bool PoseCorrection = true;

    /** Infer appropriate roll bone orientation. Only available for arms.*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinShownByDefault))
    bool RollBoneInterpolation = false;

    /** Blending parameter for rollbone interpolation*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinShownByDefault, EditCondition = "RollBoneInterpolation"))
    float RollBoneBlending = 0.5f;
	
    /** Enable to ignore finger positions and only use orientation information from Motive when mapping hands.*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinShownByDefault))
    bool FingerRotationOnly = true;

    /** Base Skeleton Rotation. Automatically inferred for full skeletons.*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinHiddenByDefault))
    FRotator SkeletonBaseRotation = FRotator(0, 0, 0);

	/** Base Skeleton Rotation. Automatically inferred for full skeletons.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinHiddenByDefault))
	bool UseTranslationCorrection = true;
	/** Base Skeleton Rotation. Automatically inferred for full skeletons.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinHiddenByDefault))
	bool UseSpineInterpolation = true;

    /** Base Thumb Rotation.*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (PinHiddenByDefault))
    float ThumbBaseRotation = 3.14 / 6.0;

	TArray<EOptitrackBone> SpineBones = { EOptitrackBone::Hip, EOptitrackBone::Ab, EOptitrackBone::Chest, EOptitrackBone::Neck, EOptitrackBone::Head };
    TArray<EOptitrackBone> SupportedRollBones = { EOptitrackBone::LUArm, EOptitrackBone::LFArm, EOptitrackBone::RUArm, EOptitrackBone::RFArm };
    TArray<EOptitrackBone> FingerBones = { EOptitrackBone::LThumb1,  EOptitrackBone::LThumb2,  EOptitrackBone::LThumb3,
        EOptitrackBone::LIndex1,  EOptitrackBone::LIndex2,  EOptitrackBone::LIndex3,
        EOptitrackBone::LMiddle1, EOptitrackBone::LMiddle2, EOptitrackBone::LMiddle3,
        EOptitrackBone::LRing1,   EOptitrackBone::LRing2,   EOptitrackBone::LRing3,
        EOptitrackBone::LPinky1,  EOptitrackBone::LPinky2,  EOptitrackBone::LPinky3,

        EOptitrackBone::RThumb1,  EOptitrackBone::RThumb2,  EOptitrackBone::RThumb3,
        EOptitrackBone::RIndex1,  EOptitrackBone::RIndex2,  EOptitrackBone::RIndex3,
        EOptitrackBone::RMiddle1, EOptitrackBone::RMiddle2, EOptitrackBone::RMiddle3,
        EOptitrackBone::RRing1,   EOptitrackBone::RRing2,   EOptitrackBone::RRing3,
        EOptitrackBone::RPinky1,  EOptitrackBone::RPinky2,  EOptitrackBone::RPinky3 };

private:
	static const int32 kInvalidBoneStreamingId = -1;
	static const uint8 kMaxSourceBones = static_cast<uint8>(EOptitrackBone::NumBones);

    // Motive is +Z forward, which after the UE4 change of basis/handedness is +Y forward.
    // We want +X forward, so this applies that 90 degree rotation about Z.
    FQuat mOptitrackSkeletonQuatBasisChange;
    FQuat mOptitrackSkeletonQuatBasisChangeInv;

	// Applies Motive data for a given bone to the skeleton
	void PerformStreamingRetargeting(FComponentSpacePoseContext& PoseContext, uint8 BoneId);
	
	// Methods for computing necessary rotations to make reference skeleton into a perfect T-pose
	void ComputePoseCorrection(const FComponentSpacePoseContext& Pose);
	void ComputePoseCorrection(const FComponentSpacePoseContext& Pose, const FBoneReference& BoneRef, const EOptitrackBone& Bone);

	// Getter for world transform for the skeleton reference pose (no pose correction)
	FTransform GetWorldRefTransform(const FComponentSpacePoseContext& Pose, const FCompactPoseBoneIndex& Idx) const;
	// Getter pose correction rotation for a given bone (world space)
	FQuat GetRefPoseCorrectionRotation(const FCompactPoseBoneIndex& fcpIdx);
	FVector GetRefBoneScaleAxisFromDefinition(EOptitrackBone Bone);

    // Returns world transform of bone
	void CacheStreamingBoneIds( EOptitrackBoneNamingConvention BoneNamingConvention );
	int32 FindBoneId( const FName& BoneName );

	void MarkSkeletonDefinitionInvalid();
	bool TryUpdateSkeletonDefinition();

	FVector GetLocalBoneScaleAxis( EOptitrackBone Bone ) const;
	FVector GetLocalBoneAxisFromDefinition(EOptitrackBone Bone) const;
    FVector GetLocalBoneAxis(EOptitrackBone Bone) const;
	EOptitrackBone GetBoneSegmentChild( EOptitrackBone Bone ) const;
	void ExtractSourceScalingFromDefinition();
	void ExtractSourceScalingFromLatestState();
	void UpdateTargetScaleRatios();
	void ResetTargetScaleRatios();

	// Helpers
	int32 GetStreamingId( EOptitrackBone Bone ) const;
	FVector GetCsBoneLocation( /*const*/ FCSPose<FCompactPose>& CsPose, const FAnimInstanceProxy* AnimInstance, EOptitrackBone Bone ) const;
	float GetCsBoneDistanceToParent( /*const*/ FCSPose<FCompactPose>& CsPose, EOptitrackBone Bone ) const;
    FCompactPoseBoneIndex GetMappedParentPoseIndex(const FCompactPose& Pose, const FCompactPoseBoneIndex BoneIdx) const;
	FVector GetStreamDefBoneLocation( int32 StreamingId ) const;
	float GetStreamDefBoneDistanceToParent( EOptitrackBone Bone ) const;
	float GetLatestStateBoneDistanceToParent( EOptitrackBone Bone ) const;

//#if OPTITRACK_SKELNODE_DEBUGDRAW
	template< typename PoseT >
	void DrawPose( FAnimInstanceProxy* DrawProxy, FCSPose< PoseT >& CsPose, const FColor& DrawColor );
//#endif

    bool FullSkeletonModel = true;
	bool SourceSkeletonDefinitionValid;
	bool PoseCorrectionCalculated = false;
	FOptitrackSkeletonDefinition SourceSkeletonDefinition;
	std::array<int32, kMaxSourceBones> BoneStreamingIds;
	FOptitrackSkeletonState LatestSkeletonState;

	struct SkeletonScaling {
		// Helpful composite measurements calculated once from the reference/T-pose.
		// Used to compute the character height for the primary/root isotropic scale factor.
		float TorsoLength; // Head to hip
		float AvgLegLength; // Average hip to ankles
		float AvgArmLength; // Average hands to shoulders
		float Height;

		// Exact segment lengths (for source data, updated every streaming frame).
		std::array<float, kMaxSourceBones> BoneDistanceToParent;
	};

	struct SpineInterpolant
	{
		FInterpCurveQuat SpineRotCurve;
		FInterpCurveVector SpinePosCurve;
		std::map<EOptitrackBone, float> SourceSpineValues;
		std::map<FCompactPoseBoneIndex, float> TargetSpineValues;
		float SourceSpineLength = 0.0f;
		float TargetSpineLength = 0.0f;
		bool Initialized = false;
	};
	SpineInterpolant SpineCurve;

	SkeletonScaling SourceScaling;
	SkeletonScaling TargetScaling;
	std::array<FVector, kMaxSourceBones> TargetBoneLocalScaleRatios;
	std::map<FCompactPoseBoneIndex, FQuat> RefPoseCorrectionRotations;
	std::map<FCompactPoseBoneIndex, FVector> RefPoseBoneScaleAxis;
    TArray<int32> IgnoreBoneIndices;
    TArray<int32> RollBoneIndices;
    TArray<int32> RollBoneParentIndices;
	std::map<int32, FBoneReference> RollBoneRefs;

	UPROPERTY()
	TArray<FTransform> RetargetBasePose;
};
