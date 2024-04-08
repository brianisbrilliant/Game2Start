//======================================================================================================
// Copyright 2021, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include "Roles/LiveLinkAnimationTypes.h"


struct FLiveLinkSkeletonStaticData;
struct FLiveLinkAnimationFrameData;
struct FReferenceSkeleton;
struct FCompactPose;

UENUM()
enum class OptiTrackBoneID : uint8
{
	Root = 0,
	Hips,
	Spine,
	Spine1,
	Neck,
	Head,

	LeftShoulder = 6,
	LeftArm,
	LeftForeArm,
	LeftHand,

	RightShoulder = 10,
	RightArm,
	RightForeArm,
	RightHand,

	LeftUpLeg = 14,
	LeftLeg,
	LeftFoot,
	LeftToeBase,

	RightUpLeg = 18,
	RightLeg,
	RightFoot,
	RightToeBase,

	LeftHandThumb1, LeftHandThumb2, LeftHandThumb3,
	LeftHandIndex1, LeftHandIndex2, LeftHandIndex3,
	LeftHandMiddle1, LeftHandMiddle2, LeftHandMiddle3,
	LeftHandRing1, LeftHandRing2, LeftHandRing3,
	LeftHandPinky1, LeftHandPinky2, LeftHandPinky3,

    RightHandThumb1, RightHandThumb2, RightHandThumb3,
    RightHandIndex1, RightHandIndex2, RightHandIndex3,
    RightHandMiddle1, RightHandMiddle2, RightHandMiddle3,
    RightHandRing1, RightHandRing2, RightHandRing3,
    RightHandPinky1, RightHandPinky2, RightHandPinky3,

	NumBones,

	UndefinedBone
};

class cRetargetBone
{
public:
	cRetargetBone();

	void AddChild( cRetargetBone* child );
	cRetargetBone* FindChildByID( OptiTrackBoneID ID ) const;

	void UpdateTransform( bool updateChildren = true );

	FVector Direction() const;
	void SetDirection( OptiTrackBoneID childID, const FVector& direction );

	EAxis::Type LengthAxis() const;
	float Length( float skeletonHeight ) const;

	static OptiTrackBoneID BoneNameToID( const FName& name );

	OptiTrackBoneID mID;

	FTransform mOffsetTransform; // Offset transform relative to its parent
	FQuat mTPoseRotation;		 // Rotation needed to pose the skeleton into T pose
	FQuat mCoordinate;			 // Bone orientation at T pose
	FTransform mFrameTransform;  // Local animation transform
	FTransform mFinalTransform;  // Global bone transform 

	cRetargetBone* mParent;
	TArray<cRetargetBone*> mChildren;
	int mIndex;
};

class cRetargetSkeleton
{
public:
	cRetargetSkeleton();

	void Create( const FLiveLinkSkeletonStaticData& skeletonData, const FLiveLinkAnimationFrameData& frameData );
	void Create( const FReferenceSkeleton& refSkeleton, const TMap<FName, FName>& boneNameMap );

	TArray<cRetargetBone>& Bones() { return mBones; }
	const TArray<cRetargetBone>& Bones() const { return mBones; }

	void SetTPose( const cRetargetSkeleton& sourceSkeleton );
	void SetBoneRotationOffset( OptiTrackBoneID boneID, const FQuat& offset );

	void Update( const FLiveLinkAnimationFrameData& frameData );
	void Retarget( const cRetargetSkeleton& sourceSkeleton, bool scaleBones );
	void GetPose( FCompactPose& pose );

	cRetargetBone* FindBoneByID( OptiTrackBoneID ID );
	const cRetargetBone* FindBoneByID( OptiTrackBoneID ID ) const;

	bool HasFingers() const;

protected:
	void SetForwardDirection( const FVector& forward );

	float Height() const { return mHeight;}
	void UpdateHeight();

	void SetHipOffsetByLegLength();
	void TPoseTransforms( TMap<OptiTrackBoneID, FTransform>& transforms ) const;

protected:
	TArray<cRetargetBone> mBones;
	TMap<OptiTrackBoneID, int> mBoneIDtoIndexMap;
	TMap<OptiTrackBoneID, FQuat> mBoneRotationOffsets;
	float mHeight;
};
