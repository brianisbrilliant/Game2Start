//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 

#include "LiveLinkNatNetRetarget.h"

#include <BoneIndices.h>
#include <BonePose.h>
#include <Roles/LiveLinkAnimationTypes.h>
#include "DrawDebugHelpers.h"

UOptiTrackLiveLinkRetarget::UOptiTrackLiveLinkRetarget( const FObjectInitializer& ObjectInitializer )
    : Super( ObjectInitializer )
{
	RootBoneName = L"root";
	HipBoneName = L"pelvis";
	AbBoneName = L"spine_01";
	ChestBoneName = L"spine_02";
	NeckBoneName = L"neck_01";
	HeadBoneName = L"head";

	LShoulderBoneName = L"clavicle_l";
	LUArmBoneName = L"upperarm_l";
	LFArmBoneName = L"lowerarm_l";
	LHandBoneName = L"hand_l";

	RShoulderBoneName = L"clavicle_r";
	RUArmBoneName = L"upperarm_r";
	RFArmBoneName = L"lowerarm_r";
	RHandBoneName = L"hand_r";

	LThighBoneName = L"thigh_l";
	LShinBoneName = L"calf_l";
	LFootBoneName = L"foot_l";
	LToeBoneName = L"ball_l";

	RThighBoneName = L"thigh_r";
	RShinBoneName = L"calf_r";
	RFootBoneName = L"foot_r";
	RToeBoneName = L"ball_r";

	LThumb1BoneName = L"thumb_01_l";
	LThumb2BoneName = L"thumb_02_l";
	LThumb3BoneName = L"thumb_03_l";
	LIndex1BoneName = L"index_01_l";
	LIndex2BoneName = L"index_02_l";
	LIndex3BoneName = L"index_03_l";
	LMiddle1BoneName = L"middle_01_l";
	LMiddle2BoneName = L"middle_02_l";
	LMiddle3BoneName = L"middle_03_l";
	LRing1BoneName = L"ring_01_l";
	LRing2BoneName = L"ring_02_l";
	LRing3BoneName = L"ring_03_l";
	LPinky1BoneName = L"pinky_01_l";
	LPinky2BoneName = L"pinky_02_l";
	LPinky3BoneName = L"pinky_03_l";

	RThumb1BoneName = L"thumb_01_r";
	RThumb2BoneName = L"thumb_02_r";
	RThumb3BoneName = L"thumb_03_r";
	RIndex1BoneName = L"index_01_r";
	RIndex2BoneName = L"index_02_r";
	RIndex3BoneName = L"index_03_r";
	RMiddle1BoneName = L"middle_01_r";
	RMiddle2BoneName = L"middle_02_r";
	RMiddle3BoneName = L"middle_03_r";
	RRing1BoneName = L"ring_01_r";
	RRing2BoneName = L"ring_02_r";
	RRing3BoneName = L"ring_03_r";
	RPinky1BoneName = L"pinky_01_r";
	RPinky2BoneName = L"pinky_02_r";
	RPinky3BoneName = L"pinky_03_r";

	mScaleBones = false;

	mLThumb1Rotation = FRotator::MakeFromEuler( FVector( -45, 0, -30 ) );
	mLThumb2Rotation = FRotator::MakeFromEuler( FVector( 20, 0, 30 ) );
	mLThumb3Rotation = FRotator::ZeroRotator;
	mRThumb1Rotation = FRotator::MakeFromEuler( FVector( -45, 0, -30 ) );
	mRThumb2Rotation = FRotator::MakeFromEuler( FVector( 20, 0, 30 ) );
	mRThumb3Rotation = FRotator::ZeroRotator;

	mDrawSourceSkeleton = false;
	mDrawTargetSkeleton = false;
	mDrawOutputPose = false;
}

void UOptiTrackLiveLinkRetarget::BuildPoseFromAnimationData( float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose )
{
	OutPose.ResetToRefPose();

	if( mSourceSkeleton.Bones().Num() == 0 )
	{
		mSourceSkeleton.Create( *InSkeletonData, *InFrameData );
	}

    // FBX Bone naming convention.
    if( mTargetSkeleton.Bones().Num() == 0 )
    {
		TMap<FName, FName> boneNameMap;
		
		// FBX Bone naming convention
        {
            boneNameMap.FindOrAdd( L"Root" ) = RootBoneName;
            boneNameMap.FindOrAdd( L"Hips" ) = HipBoneName;
            boneNameMap.FindOrAdd( L"Spine" ) = AbBoneName;
            boneNameMap.FindOrAdd( L"Spine1" ) = ChestBoneName;
            boneNameMap.FindOrAdd( L"Neck" ) = NeckBoneName;
            boneNameMap.FindOrAdd( L"Head" ) = HeadBoneName;

            boneNameMap.FindOrAdd( L"LeftShoulder" ) = LShoulderBoneName;
            boneNameMap.FindOrAdd( L"LeftArm" ) = LUArmBoneName;
            boneNameMap.FindOrAdd( L"LeftForeArm" ) = LFArmBoneName;
            boneNameMap.FindOrAdd( L"LeftHand" ) = LHandBoneName;

            boneNameMap.FindOrAdd( L"RightShoulder" ) = RShoulderBoneName;
            boneNameMap.FindOrAdd( L"RightArm" ) = RUArmBoneName;
            boneNameMap.FindOrAdd( L"RightForeArm" ) = RFArmBoneName;
            boneNameMap.FindOrAdd( L"RightHand" ) = RHandBoneName;

            boneNameMap.FindOrAdd( L"LeftUpLeg" ) = LThighBoneName;
            boneNameMap.FindOrAdd( L"LeftLeg" ) = LShinBoneName;
            boneNameMap.FindOrAdd( L"LeftFoot" ) = LFootBoneName;
            boneNameMap.FindOrAdd( L"LeftToeBase" ) = LToeBoneName;

            boneNameMap.FindOrAdd( L"RightUpLeg" ) = RThighBoneName;
            boneNameMap.FindOrAdd( L"RightLeg" ) = RShinBoneName;
            boneNameMap.FindOrAdd( L"RightFoot" ) = RFootBoneName;
            boneNameMap.FindOrAdd( L"RightToeBase" ) = RToeBoneName;

            boneNameMap.FindOrAdd( L"LeftHandThumb1" ) = LThumb1BoneName;
            boneNameMap.FindOrAdd( L"LeftHandThumb2" ) = LThumb2BoneName;
            boneNameMap.FindOrAdd( L"LeftHandThumb3" ) = LThumb3BoneName;
            boneNameMap.FindOrAdd( L"LeftHandIndex1" ) = LIndex1BoneName;
            boneNameMap.FindOrAdd( L"LeftHandIndex2" ) = LIndex2BoneName;
            boneNameMap.FindOrAdd( L"LeftHandIndex3" ) = LIndex3BoneName;
            boneNameMap.FindOrAdd( L"LeftHandMiddle1" ) = LMiddle1BoneName;
            boneNameMap.FindOrAdd( L"LeftHandMiddle2" ) = LMiddle2BoneName;
            boneNameMap.FindOrAdd( L"LeftHandMiddle3" ) = LMiddle3BoneName;
            boneNameMap.FindOrAdd( L"LeftHandRing1" ) = LRing1BoneName;
            boneNameMap.FindOrAdd( L"LeftHandRing2" ) = LRing2BoneName;
            boneNameMap.FindOrAdd( L"LeftHandRing3" ) = LRing3BoneName;
            boneNameMap.FindOrAdd( L"LeftHandPinky1" ) = LPinky1BoneName;
            boneNameMap.FindOrAdd( L"LeftHandPinky2" ) = LPinky2BoneName;
            boneNameMap.FindOrAdd( L"LeftHandPinky3" ) = LPinky3BoneName;

            boneNameMap.FindOrAdd( L"RightHandThumb1" ) = RThumb1BoneName;
            boneNameMap.FindOrAdd( L"RightHandThumb2" ) = RThumb2BoneName;
            boneNameMap.FindOrAdd( L"RightHandThumb3" ) = RThumb3BoneName;
            boneNameMap.FindOrAdd( L"RightHandIndex1" ) = RIndex1BoneName;
            boneNameMap.FindOrAdd( L"RightHandIndex2" ) = RIndex2BoneName;
            boneNameMap.FindOrAdd( L"RightHandIndex3" ) = RIndex3BoneName;
            boneNameMap.FindOrAdd( L"RightHandMiddle1" ) = RMiddle1BoneName;
            boneNameMap.FindOrAdd( L"RightHandMiddle2" ) = RMiddle2BoneName;
            boneNameMap.FindOrAdd( L"RightHandMiddle3" ) = RMiddle3BoneName;
            boneNameMap.FindOrAdd( L"RightHandRing1" ) = RRing1BoneName;
            boneNameMap.FindOrAdd( L"RightHandRing2" ) = RRing2BoneName;
            boneNameMap.FindOrAdd( L"RightHandRing3" ) = RRing3BoneName;
            boneNameMap.FindOrAdd( L"RightHandPinky1" ) = RPinky1BoneName;
            boneNameMap.FindOrAdd( L"RightHandPinky2" ) = RPinky2BoneName;
            boneNameMap.FindOrAdd( L"RightHandPinky3" ) = RPinky3BoneName;
        }


		mTargetSkeleton.Create( OutPose.GetBoneContainer().GetReferenceSkeleton(), boneNameMap );
		mTargetSkeleton.SetTPose( mSourceSkeleton );
	}

	if( mTargetSkeleton.HasFingers() )
	{
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb1, mLThumb1Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb2, mLThumb2Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb3, mLThumb3Rotation.Quaternion() );

		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb1, mRThumb1Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb2, mRThumb2Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb3, mRThumb3Rotation.Quaternion() );
	}

	mSourceSkeleton.Update( *InFrameData );
	mTargetSkeleton.Retarget( mSourceSkeleton, mScaleBones );
	mTargetSkeleton.GetPose( OutPose );

	if( mDrawSourceSkeleton )
	{
		//DrawSkeleton( GetWorld(), InSkeletonData, InFrameData, true, true, true, FColor::Green );
		DrawSkeleton( GetWorld(), mSourceSkeleton, true, FColor::Red );
	}

	if( mDrawTargetSkeleton )
	{
		DrawSkeleton( GetWorld(), mTargetSkeleton, true, FColor::Cyan );

		// Draw T pose
		for( cRetargetBone& bone : mTargetSkeleton.Bones() )
			bone.mFinalTransform.SetRotation( bone.mCoordinate );
		DrawSkeleton( GetWorld(), mTargetSkeleton, true, FColor::Yellow );
	}

	if( mDrawOutputPose )
		DrawPose( GetWorld(), OutPose, true, true, true, FColor::Orange );
}

void UOptiTrackLiveLinkRetarget::DrawAxis( UWorld* world, const FTransform& tr, float size ) const
{
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( size, 0, 0 ) ), FColor::Red, false, -1, SDPG_MAX, 0.5f );
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( 0, size, 0 ) ), FColor::Green, false, -1, SDPG_MAX, 0.5f );
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( 0, 0, size ) ), FColor::Blue, false, -1, SDPG_MAX, 0.5f );
}

void UOptiTrackLiveLinkRetarget::DrawSkeleton( UWorld* world, const cRetargetSkeleton& skeleton, bool drawAxis, const FColor& color ) const
{
	for( const cRetargetBone& bone : skeleton.Bones() )
	{
		if( bone.mParent )
			DrawDebugLine( world, bone.mFinalTransform.GetTranslation(), bone.mParent->mFinalTransform.GetTranslation(), color, false, -1, SDPG_MAX, 1 );

		DrawDebugSphere( world, bone.mFinalTransform.GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, bone.mFinalTransform, 10 );
	}
}

void UOptiTrackLiveLinkRetarget::DrawSkeleton( UWorld* world, const FLiveLinkSkeletonStaticData* skeletonData, const FLiveLinkAnimationFrameData* frameData, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const
{
	TMap<OptiTrackBoneID, FTransform> boneTransforms;
	for( int i = 0; i < skeletonData->GetBoneNames().Num(); i++ )
	{
		OptiTrackBoneID boneID = cRetargetBone::BoneNameToID( skeletonData->GetBoneNames()[i] );
		if( boneID == OptiTrackBoneID::UndefinedBone )
			continue;

		boneTransforms.FindOrAdd( boneID ) = frameData->Transforms[i];

		int parentIndex = skeletonData->GetBoneParents()[i];
		if( parentIndex >= 0 )
		{
			OptiTrackBoneID parentID = cRetargetBone::BoneNameToID( skeletonData->GetBoneNames()[parentIndex] );
			if( parentID != OptiTrackBoneID::UndefinedBone )
				boneTransforms[boneID] *= boneTransforms[parentID];

			if( drawLines )
				DrawDebugLine( world, boneTransforms[parentID].GetTranslation(), boneTransforms[boneID].GetTranslation(), color, false, -1, SDPG_MAX, 1 );
		}

		if( drawJoints )
			DrawDebugSphere( world, boneTransforms[boneID].GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, boneTransforms[boneID], 10 );
	}
}

void UOptiTrackLiveLinkRetarget::DrawPose( UWorld* world, const FCompactPose& pose, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const
{
	TMap<int, FTransform> boneTransforms;

	for( const FCompactPoseBoneIndex& poseIndex : pose.ForEachBoneIndex() )
	{
		boneTransforms.FindOrAdd( poseIndex.GetInt() ) = pose[poseIndex];

		int parentIndex = pose.GetBoneContainer().GetReferenceSkeleton().GetRawParentIndex(poseIndex.GetInt());
		if( parentIndex >= 0 )
			boneTransforms[poseIndex.GetInt()] *= boneTransforms[parentIndex];

		if( drawLines && parentIndex >= 0 )
			DrawDebugLine( world, boneTransforms[parentIndex].GetTranslation(), boneTransforms[poseIndex.GetInt()].GetTranslation(), color, false, -1, SDPG_MAX, 1 );

		if( drawJoints )
			DrawDebugSphere( world, boneTransforms[poseIndex.GetInt()].GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, boneTransforms[poseIndex.GetInt()], 10 );
	}
}