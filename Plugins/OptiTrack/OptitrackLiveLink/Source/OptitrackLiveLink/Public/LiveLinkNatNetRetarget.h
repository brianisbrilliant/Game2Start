//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <LiveLinkRetargetAsset.h>
#include <LiveLinkRemapAsset.h>

#include "CoreMinimal.h"
#include "BoneIndices.h"
#include "RetargetSkeleton.h"
#include "LiveLinkNatNetRetarget.generated.h"

UCLASS( Blueprintable )
class OPTITRACKLIVELINK_API UOptiTrackLiveLinkRetarget : public ULiveLinkRetargetAsset
{
	GENERATED_UCLASS_BODY()

	//~ Begin ULiveLinkRetargetAsset interface
	virtual void BuildPoseFromAnimationData( float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose );
	//~ End ULiveLinkRetargetAsset interface

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Root Bone Name")
	FName RootBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Hip Bone Name")
	FName HipBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Ab Bone Name")
	FName AbBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Chest Bone Name")
	FName ChestBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Neck Bone Name")
	FName NeckBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Head Bone Name")
	FName HeadBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Shoulder Bone Name")
	FName LShoulderBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Upper Arm Bone Name")
	FName LUArmBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Forearm Bone Name")
	FName LFArmBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Hand Bone Name")
	FName LHandBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Shoulder Bone Name")
	FName RShoulderBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Upper Arm Bone Name")
	FName RUArmBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Forearm Bone Name")
	FName RFArmBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Hand Bone Name")
	FName RHandBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thigh Bone Name")
	FName LThighBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Shin Bone Name")
	FName LShinBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Foot Bone Name")
	FName LFootBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Toe Bone Name")
	FName LToeBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thigh Bone Name")
	FName RThighBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Shin Bone Name")
	FName RShinBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Foot Bone Name")
	FName RFootBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Toe Bone Name")
	FName RToeBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb1 Bone Name")
	FName LThumb1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb2 Bone Name")
	FName LThumb2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb3 Bone Name")
	FName LThumb3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index1 Bone Name")
	FName LIndex1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index2 Bone Name")
	FName LIndex2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index3 Bone Name")
	FName LIndex3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle1 Bone Name")
	FName LMiddle1BoneName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle2 Bone Name")
	FName LMiddle2BoneName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle3 Bone Name")
	FName LMiddle3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring1 Bone Name")
	FName LRing1BoneName;   

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring2 Bone Name")
	FName LRing2BoneName;   

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring3 Bone Name")
	FName LRing3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky1 Bone Name")
	FName LPinky1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky2 Bone Name")
	FName LPinky2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky3 Bone Name")
	FName LPinky3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb1 Bone Name")
	FName RThumb1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb2 Bone Name")
	FName RThumb2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb3 Bone Name")
	FName RThumb3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index1 Bone Name")
	FName RIndex1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index2 Bone Name")
	FName RIndex2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index3 Bone Name")
	FName RIndex3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle1 Bone Name")
	FName RMiddle1BoneName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle2 Bone Name")
	FName RMiddle2BoneName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle3 Bone Name")
	FName RMiddle3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring1 Bone Name")
	FName RRing1BoneName;   

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring2 Bone Name")
	FName RRing2BoneName;   

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring3 Bone Name")
	FName RRing3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky1 Bone Name")
	FName RPinky1BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky2 Bone Name")
	FName RPinky2BoneName;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky3 Bone Name")
	FName RPinky3BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Scale Bones")
	bool mScaleBones;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb1 Rotation Offset")
	FRotator mLThumb1Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb2 Rotation Offset")
	FRotator mLThumb2Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb3 Rotation Offset")
	FRotator mLThumb3Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb1 Rotation Offset")
	FRotator mRThumb1Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb2 Rotation Offset")
	FRotator mRThumb2Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb3 Rotation Offset")
	FRotator mRThumb3Rotation;

private:
	cRetargetSkeleton mSourceSkeleton;
	cRetargetSkeleton mTargetSkeleton;

	bool mDrawSourceSkeleton;
	bool mDrawTargetSkeleton;
	bool mDrawOutputPose;

	void DrawAxis( UWorld* world, const FTransform& tr, float size ) const;
	void DrawSkeleton( UWorld* world, const cRetargetSkeleton& skeleton, bool drawAxis, const FColor& color ) const;
	void DrawSkeleton( UWorld* world, const FLiveLinkSkeletonStaticData* skeletonData, const FLiveLinkAnimationFrameData* frameData, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const;
	void DrawPose( UWorld* world, const FCompactPose& pose, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const;
};
