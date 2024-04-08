//======================================================================================================
// Copyright 2021, NaturalPoint Inc.
//====================================================================================================== 

#include "RetargetSkeleton.h"

cRetargetBone::cRetargetBone() :
	mID( OptiTrackBoneID::UndefinedBone ),
	mOffsetTransform( FTransform::Identity ),
	mTPoseRotation( FQuat::Identity ),
	mCoordinate( FQuat::Identity ),
	mFinalTransform( FTransform::Identity ),
	mFrameTransform( FTransform::Identity ),
	mParent( nullptr ),
	mIndex( -1 )
{
}

void cRetargetBone::AddChild( cRetargetBone* child )
{
	mChildren.Add( child );
	child->mParent = this;
}

void cRetargetBone::UpdateTransform( bool updateChildren )
{
	mFinalTransform = mFrameTransform * FTransform( mTPoseRotation ) * mOffsetTransform;

	if( mParent )
		mFinalTransform *= mParent->mFinalTransform;

	if( !updateChildren )
		return;

	for( cRetargetBone* child : mChildren )
		child->UpdateTransform();
}

cRetargetBone* cRetargetBone::FindChildByID( OptiTrackBoneID ID ) const
{
	if( auto bone = mChildren.FindByPredicate( [&]( const cRetargetBone* b ) { return b->mID == ID; } ) )
		return *bone;

	for( const cRetargetBone* child : mChildren )
	{
		if( cRetargetBone* bone = child->FindChildByID( ID ) )
			return bone;
	}

	return nullptr;
}

FVector cRetargetBone::Direction() const
{
	switch( mID )
	{
	case OptiTrackBoneID::Root:
	case OptiTrackBoneID::Hips:
	case OptiTrackBoneID::LeftShoulder:
	case OptiTrackBoneID::RightShoulder:
	case OptiTrackBoneID::LeftHandThumb1:
	case OptiTrackBoneID::RightHandThumb1:
		return FVector::ZeroVector;
	case OptiTrackBoneID::LeftHand:
		{
			const cRetargetBone* middle = FindChildByID( OptiTrackBoneID::LeftHandMiddle1 );
			const cRetargetBone* ring = FindChildByID( OptiTrackBoneID::LeftHandRing1 );
			if( middle && ring )
				return ( middle->mFinalTransform.GetTranslation() + ring->mFinalTransform.GetTranslation() ) * 0.5f - mFinalTransform.GetTranslation();
		}
		break;
	case OptiTrackBoneID::RightHand:
		{
			const cRetargetBone* middle = FindChildByID( OptiTrackBoneID::RightHandMiddle1 );
			const cRetargetBone* ring = FindChildByID( OptiTrackBoneID::RightHandRing1 );
			if( middle && ring )
				return ( middle->mFinalTransform.GetTranslation() + ring->mFinalTransform.GetTranslation() ) * 0.5f - mFinalTransform.GetTranslation();
		}
		break;
	}

	if( mChildren.Num() > 0 )
		return mChildren[0]->mFinalTransform.GetTranslation() - mFinalTransform.GetTranslation();
	if( mParent )
		return mFinalTransform.GetTranslation() - mParent->mFinalTransform.GetTranslation();

	return FVector::ZeroVector;
}

void cRetargetBone::SetDirection( OptiTrackBoneID childID, const FVector& direction )
{
	if( direction == FVector::ZeroVector )
		return;

	if( cRetargetBone* child = FindChildByID( childID ) )
	{
		FVector v1 = mFinalTransform.InverseTransformPosition( child->mFinalTransform.GetTranslation() );
		FVector v2 = mFinalTransform.InverseTransformVector( direction );
		mTPoseRotation = FQuat::FindBetween( v1, v2 );
		UpdateTransform();
	}
}

EAxis::Type cRetargetBone::LengthAxis() const
{
	switch( mID )
	{
	case OptiTrackBoneID::Root:
	case OptiTrackBoneID::Hips:
	case OptiTrackBoneID::Spine:
	case OptiTrackBoneID::Spine1:
	case OptiTrackBoneID::Neck:
	case OptiTrackBoneID::Head:
		return EAxis::Z;
	case OptiTrackBoneID::LeftShoulder:
	case OptiTrackBoneID::LeftArm:
	case OptiTrackBoneID::LeftForeArm:
	case OptiTrackBoneID::LeftHand:
	case OptiTrackBoneID::RightShoulder:
	case OptiTrackBoneID::RightArm:
	case OptiTrackBoneID::RightForeArm:
	case OptiTrackBoneID::RightHand:
		return EAxis::Y;
	case OptiTrackBoneID::LeftUpLeg:
	case OptiTrackBoneID::LeftLeg:
	case OptiTrackBoneID::RightUpLeg:
	case OptiTrackBoneID::RightLeg:
		return EAxis::Z;
	case OptiTrackBoneID::LeftFoot:
	case OptiTrackBoneID::LeftToeBase:
	case OptiTrackBoneID::RightFoot:
	case OptiTrackBoneID::RightToeBase:
		return EAxis::X;
	}

	if( mID >= OptiTrackBoneID::LeftHandThumb1 && mID <= OptiTrackBoneID::RightHandPinky3 )
		return EAxis::Y;

	return EAxis::None;
}

float cRetargetBone::Length( float skeletonHeight ) const
{
	if( mChildren.Num() == 1 )
		return mChildren[0]->mOffsetTransform.GetTranslation().Size();
	
	if( mChildren.Num() > 1 )
	{
		OptiTrackBoneID childBoneID = OptiTrackBoneID::UndefinedBone;

		switch( mID )
		{
		case OptiTrackBoneID::Hips:	 childBoneID = OptiTrackBoneID::Spine; break;
		case OptiTrackBoneID::Spine1: childBoneID = OptiTrackBoneID::Neck; break;
		case OptiTrackBoneID::LeftHand: childBoneID = OptiTrackBoneID::LeftHandMiddle1; break;
		case OptiTrackBoneID::RightHand: childBoneID = OptiTrackBoneID::RightHandMiddle1; break;
		}

		if( cRetargetBone* childBone = FindChildByID( childBoneID ) )
			return childBone->mOffsetTransform.GetTranslation().Size();
	}
	
	switch( mID )
	{
	case OptiTrackBoneID::Head: return skeletonHeight * 0.14f;
	case OptiTrackBoneID::LeftHand: return skeletonHeight * 0.05f;
	case OptiTrackBoneID::RightHand: return skeletonHeight * 0.05f;
	case OptiTrackBoneID::LeftFoot: return skeletonHeight * 0.14f;
	case OptiTrackBoneID::RightFoot: return skeletonHeight * 0.14f;
	case OptiTrackBoneID::LeftToeBase: return skeletonHeight * 0.02f;
	case OptiTrackBoneID::RightToeBase: return skeletonHeight * 0.02f;
	case OptiTrackBoneID::LeftHandThumb3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::LeftHandIndex3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::LeftHandMiddle3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::LeftHandRing3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::LeftHandPinky3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::RightHandThumb3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::RightHandIndex3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::RightHandMiddle3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::RightHandRing3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	case OptiTrackBoneID::RightHandPinky3: return mParent ? mParent->Length( skeletonHeight ) : 0;
	}

	return 0;
}

OptiTrackBoneID cRetargetBone::BoneNameToID( const FName& name )
{
	FString fullName( L"OptiTrackBoneID::" );
	fullName.Append( name.ToString() );

	for( int e = 0; e < (int)OptiTrackBoneID::NumBones; e++ )
	{
		FString enumName = UEnum::GetValueAsString<OptiTrackBoneID>( (OptiTrackBoneID)e );
		if( fullName == enumName )
		{
			return (OptiTrackBoneID)e;
		}
	}

	return OptiTrackBoneID::UndefinedBone;
}


cRetargetSkeleton::cRetargetSkeleton() :
	mHeight( 180.0f )
{
}

void cRetargetSkeleton::Create( const FLiveLinkSkeletonStaticData& skeletonData, const FLiveLinkAnimationFrameData& frameData )
{
	mBones.SetNum( skeletonData.GetBoneNames().Num() );

	for( int i = 0; i < skeletonData.GetBoneNames().Num(); i++ )
	{
		cRetargetBone& bone = mBones[i];

		bone.mID = cRetargetBone::BoneNameToID( skeletonData.GetBoneNames()[i] );
		if( bone.mID == OptiTrackBoneID::Root )
			bone.mOffsetTransform = FTransform::Identity;
		else
			bone.mOffsetTransform.SetTranslation( frameData.Transforms[i].GetTranslation() );
		bone.mFinalTransform = bone.mOffsetTransform;

		int parentIndex = skeletonData.GetBoneParents()[i];
		if( parentIndex >= 0 )
			mBones[parentIndex].AddChild( &bone );

		bone.mIndex = i;

		if( bone.mID != OptiTrackBoneID::UndefinedBone )
			mBoneIDtoIndexMap.FindOrAdd( bone.mID ) = i;
	}

	if( mBones.Num() > 0 )
		mBones[0].UpdateTransform();

	UpdateHeight();
}

void cRetargetSkeleton::Create( const FReferenceSkeleton& refSkeleton, const TMap<FName, FName>& boneNameMap )
{
	const TArray<FMeshBoneInfo>& boneInfos = refSkeleton.GetRefBoneInfo();
	TArray<FTransform> refPose = refSkeleton.GetRefBonePose();

	mBones.SetNum( boneInfos.Num() );
	for( int i = 0; i < boneInfos.Num(); i++ )
	{
		const FMeshBoneInfo& boneInfo = boneInfos[i];
		cRetargetBone& bone = mBones[i];

		if( const FName* boneName = boneNameMap.FindKey( boneInfo.Name ) )
			bone.mID = cRetargetBone::BoneNameToID( *boneName );

		bone.mOffsetTransform = refPose[i];
		bone.mFinalTransform = bone.mOffsetTransform;

		int parentIndex = refSkeleton.GetParentIndex( i );
		if( parentIndex >= 0 )
			mBones[parentIndex].AddChild( &bone );

		bone.mIndex = i;

		if( bone.mID != OptiTrackBoneID::UndefinedBone )
			mBoneIDtoIndexMap.FindOrAdd( bone.mID ) = i;
	}

	SetHipOffsetByLegLength();

	if( mBones.Num() > 0 )
		mBones[0].UpdateTransform();

	SetForwardDirection( FVector( 1, 0, 0 ) );
	UpdateHeight();
}

void cRetargetSkeleton::SetTPose( const cRetargetSkeleton& sourceSkeleton )
{
	for( cRetargetBone& bone : mBones )
	{
		const cRetargetBone* srcBone = sourceSkeleton.FindBoneByID( bone.mID );
		if( srcBone )
		{
			switch( srcBone->mID )
			{
			case OptiTrackBoneID::Root:
			case OptiTrackBoneID::Hips:
				break;
			case OptiTrackBoneID::LeftArm:
			case OptiTrackBoneID::LeftForeArm:
			case OptiTrackBoneID::RightArm:
			case OptiTrackBoneID::RightForeArm:
			case OptiTrackBoneID::LeftUpLeg:
			case OptiTrackBoneID::LeftLeg:
			case OptiTrackBoneID::RightUpLeg:
			case OptiTrackBoneID::RightLeg:

			case OptiTrackBoneID::LeftHandThumb2:
			case OptiTrackBoneID::LeftHandThumb3:
			case OptiTrackBoneID::LeftHandIndex1:
			case OptiTrackBoneID::LeftHandIndex2:
			case OptiTrackBoneID::LeftHandIndex3:
			case OptiTrackBoneID::LeftHandMiddle1:
			case OptiTrackBoneID::LeftHandMiddle2:
			case OptiTrackBoneID::LeftHandMiddle3:
			case OptiTrackBoneID::LeftHandRing1:
			case OptiTrackBoneID::LeftHandRing2:
			case OptiTrackBoneID::LeftHandRing3:
			case OptiTrackBoneID::LeftHandPinky1:
			case OptiTrackBoneID::LeftHandPinky2:
			case OptiTrackBoneID::LeftHandPinky3:

			case OptiTrackBoneID::RightHandThumb2:
			case OptiTrackBoneID::RightHandThumb3:
			case OptiTrackBoneID::RightHandIndex1:
			case OptiTrackBoneID::RightHandIndex2:
			case OptiTrackBoneID::RightHandIndex3:
			case OptiTrackBoneID::RightHandMiddle1:
			case OptiTrackBoneID::RightHandMiddle2:
			case OptiTrackBoneID::RightHandMiddle3:
			case OptiTrackBoneID::RightHandRing1:
			case OptiTrackBoneID::RightHandRing2:
			case OptiTrackBoneID::RightHandRing3:
			case OptiTrackBoneID::RightHandPinky1:
			case OptiTrackBoneID::RightHandPinky2:
			case OptiTrackBoneID::RightHandPinky3:
				if( srcBone->mChildren.Num() > 0 )
					bone.SetDirection( srcBone->mChildren[0]->mID, srcBone->Direction() );
				break;
			}
		}

		bone.mCoordinate = bone.mFinalTransform.GetRotation();
	}
}

void cRetargetSkeleton::SetBoneRotationOffset( OptiTrackBoneID boneID, const FQuat& offset )
{
	mBoneRotationOffsets.FindOrAdd( boneID ) = offset;
}

void cRetargetSkeleton::Update( const FLiveLinkAnimationFrameData& frameData )
{
	for( cRetargetBone& bone : mBones )
	{
		if( bone.mIndex >= 0 )
		{
			const FTransform& trFrame = frameData.Transforms[bone.mIndex];
			bone.mFrameTransform.SetTranslation( bone.mOffsetTransform.InverseTransformPosition( trFrame.GetTranslation() ) );
			bone.mFrameTransform.SetRotation( trFrame.GetRotation() );
		}

		bone.UpdateTransform( false );
	}
}

void cRetargetSkeleton::Retarget( const cRetargetSkeleton& sourceSkeleton, bool scaleBones )
{
	for( cRetargetBone& bone : mBones )
	{
		bone.mFrameTransform = FTransform::Identity;
		bone.UpdateTransform( false );
	}

	if( scaleBones )
	{
		TMap<OptiTrackBoneID, FTransform> tPose;
		sourceSkeleton.TPoseTransforms( tPose );

		float heightScale = sourceSkeleton.Height() / Height();

		for( int i = 0; i < mBones.Num(); i++ )
		{ 
			cRetargetBone& bone = mBones[i];

			if( FTransform* trSrc = tPose.Find( bone.mID ) )
			{
				FTransform frameTransform = *trSrc;

				if( bone.mParent )
					frameTransform *= bone.mParent->mFinalTransform.Inverse();

				frameTransform *= bone.mOffsetTransform.Inverse();
				frameTransform *= FTransform( bone.mTPoseRotation ).Inverse();
				bone.mFrameTransform.SetTranslation( frameTransform.GetTranslation() );

				if( i == 0 )
				{
					bone.mFrameTransform.SetScale3D( FVector( heightScale, heightScale, heightScale ) );
				}
				else
				{
					// Calculate scaling amount along bone's length axis
					FVector boneScale( 1, 1, 1 );

					if( const cRetargetBone* srcBone = sourceSkeleton.FindBoneByID( bone.mID ) )
					{
						float scale = srcBone->Length( sourceSkeleton.Height() ) / bone.Length( Height() );
						scale /= heightScale;
						
						switch( bone.LengthAxis() )
						{
						case EAxis::X: boneScale.X = scale; break;
						case EAxis::Y: boneScale.Y = scale; break;
						case EAxis::Z: boneScale.Z = scale; break;
						}

						FVector sc( bone.mFrameTransform.GetScale3D() );
						sc.X *= boneScale.X;
						sc.Y *= boneScale.Y;
						sc.Z *= boneScale.Z;

						bone.mFrameTransform.SetScale3D( sc );
					}

					// Counteract the scaling for child bones
					for( cRetargetBone* child : bone.mChildren )
						child->mFrameTransform.SetScale3D( FVector( 1.0f / boneScale.X, 1.0f / boneScale.Y, 1.0f / boneScale.Z ) );
				}

				bone.UpdateTransform( false );
			}
		}
	}

	for( cRetargetBone& bone : mBones )
	{
		const cRetargetBone* srcBone = sourceSkeleton.FindBoneByID( bone.mID );
		if( srcBone )
		{
			FQuat boneRot = srcBone->mFrameTransform.GetRotation();
			boneRot = bone.mCoordinate.Inverse() * boneRot * bone.mCoordinate;
			bone.mFrameTransform.SetRotation( boneRot );

			switch( bone.mID )
			{
			case OptiTrackBoneID::Root:
			case OptiTrackBoneID::Hips:
			{
				FVector bonePos = srcBone->mFrameTransform.GetTranslation();
				if( scaleBones )
					bonePos += bone.mFrameTransform.GetTranslation();
				bone.mFrameTransform.SetTranslation( bonePos );
				break;
			}
			}
		}

		bone.UpdateTransform( false );
	}
}

void cRetargetSkeleton::GetPose( FCompactPose& pose )
{
	const TArray<uint16>& boneIndices = pose.GetBoneContainer().GetBoneIndicesArray();
	for( int poseIndex = 0; poseIndex < boneIndices.Num(); poseIndex++ )
	{
		int boneIndex = boneIndices[poseIndex];
		if( boneIndex >= mBones.Num() )
			continue;

		const cRetargetBone& bone = mBones[boneIndex];
		FTransform& tr = pose[FCompactPoseBoneIndex( poseIndex )];

		FVector pos = bone.mFrameTransform.GetTranslation();
		tr.SetTranslation( tr.GetTranslation() + pos );

		FQuat rot = bone.mTPoseRotation * bone.mFrameTransform.GetRotation();
		if( FQuat* rotationOffset = mBoneRotationOffsets.Find( bone.mID ) )
			rot *= *rotationOffset;
		tr.SetRotation( tr.GetRotation() * rot );

		tr.SetScale3D( bone.mFrameTransform.GetScale3D() );
	}
}

cRetargetBone* cRetargetSkeleton::FindBoneByID( OptiTrackBoneID ID )
{
	if( auto* index = mBoneIDtoIndexMap.Find( ID ) )
		return &mBones[*index];
	return nullptr;
}

const cRetargetBone* cRetargetSkeleton::FindBoneByID( OptiTrackBoneID ID ) const
{
	if( auto* index = mBoneIDtoIndexMap.Find( ID ) )
		return &mBones[*index];
	return nullptr;
}

bool cRetargetSkeleton::HasFingers() const
{
	return	mBoneIDtoIndexMap.Find( OptiTrackBoneID::LeftHandThumb1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::LeftHandIndex1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::LeftHandMiddle1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::LeftHandRing1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::LeftHandPinky1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::RightHandThumb1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::RightHandIndex1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::RightHandMiddle1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::RightHandRing1 ) != nullptr ||
			mBoneIDtoIndexMap.Find( OptiTrackBoneID::RightHandPinky1 ) != nullptr;
}

void cRetargetSkeleton::SetForwardDirection( const FVector& forward )
{
	if( mBones.Num() == 0 )
		return;

	cRetargetBone *left, *right;
	left = FindBoneByID( OptiTrackBoneID::LeftUpLeg );
	right = FindBoneByID( OptiTrackBoneID::RightUpLeg );
	if( !left || !right )
	{
		left = FindBoneByID( OptiTrackBoneID::LeftLeg );
		right = FindBoneByID( OptiTrackBoneID::RightLeg );
	}
	if( !left || !right )
	{
		left = FindBoneByID( OptiTrackBoneID::LeftFoot );
		right = FindBoneByID( OptiTrackBoneID::RightFoot );
	}
	if( !left || !right )
	{
		left = FindBoneByID( OptiTrackBoneID::LeftArm );
		right = FindBoneByID( OptiTrackBoneID::RightArm );
	}
	if( !left || !right )
	{
		left = FindBoneByID( OptiTrackBoneID::LeftForeArm );
		right = FindBoneByID( OptiTrackBoneID::RightForeArm );
	}
	if( !left || !right )
		return;

	FVector dir = FVector::CrossProduct( ( right->mFinalTransform.GetTranslation() - left->mFinalTransform.GetTranslation() ).GetSafeNormal(), FVector( 0, 0, 1 ) );

	cRetargetBone& root = mBones[0];
	root.mTPoseRotation = FQuat::FindBetween( dir, forward );
	root.UpdateTransform();
}

void cRetargetSkeleton::UpdateHeight()
{
	const cRetargetBone* head = FindBoneByID( OptiTrackBoneID::Head );
	if( !head )
		return;

	const float topOfHeadScale = 0.1f;
	const float toeHeightScale = 0.011f;
	const float ankleHeightScale = 0.05f;
	float height = 0;
	if( cRetargetBone* lToe = FindBoneByID( OptiTrackBoneID::LeftToeBase ) )
		height = ( head->mFinalTransform.GetTranslation().Z - lToe->mFinalTransform.GetTranslation().Z ) * ( 1 + topOfHeadScale + toeHeightScale );
	else if( cRetargetBone* rToe = FindBoneByID( OptiTrackBoneID::RightToeBase ) )
		height = ( head->mFinalTransform.GetTranslation().Z - rToe->mFinalTransform.GetTranslation().Z ) * ( 1 + topOfHeadScale + toeHeightScale );
	else if( cRetargetBone* lFoot = FindBoneByID( OptiTrackBoneID::LeftFoot ) )
		height = ( head->mFinalTransform.GetTranslation().Z - lFoot->mFinalTransform.GetTranslation().Z ) * ( 1 + topOfHeadScale + ankleHeightScale );
	else if( cRetargetBone* rFoot = FindBoneByID( OptiTrackBoneID::RightFoot ) )
		height = ( head->mFinalTransform.GetTranslation().Z - rFoot->mFinalTransform.GetTranslation().Z ) * ( 1 + topOfHeadScale + ankleHeightScale );

	if( height > 0 )
		mHeight = height;
}

void cRetargetSkeleton::SetHipOffsetByLegLength()
{
	cRetargetBone* hip = FindBoneByID( OptiTrackBoneID::Hips );
	if( !hip )
		return;

	const cRetargetBone* footBone = FindBoneByID( OptiTrackBoneID::LeftToeBase );
	if( !footBone )
		footBone = FindBoneByID( OptiTrackBoneID::RightToeBase );
	if( !footBone )
		footBone = FindBoneByID( OptiTrackBoneID::LeftFoot );
	if( !footBone )
		footBone = FindBoneByID( OptiTrackBoneID::RightFoot );
	if( !footBone )
		return;
	
	float hipHeight = 0;
	const cRetargetBone* bone = footBone;
	while( bone && bone->mID != OptiTrackBoneID::Hips )
	{
		hipHeight -= bone->mOffsetTransform.GetLocation().Z;
		bone = bone->mParent;
	}

	const float toeHeightScale = 0.011f;
	const float ankleHeightScale = 0.05f;
	switch( footBone->mID )
	{
	case OptiTrackBoneID::LeftToeBase:
	case OptiTrackBoneID::RightToeBase:
		hipHeight *= ( 1 + toeHeightScale * 2 );
		break;
	case OptiTrackBoneID::LeftFoot:
	case OptiTrackBoneID::RightFoot:
		hipHeight *= ( 1 + ankleHeightScale * 2 );
		break;
	}

	hip->mOffsetTransform.SetTranslation( FVector( 0, 0, hipHeight ) );
}

void cRetargetSkeleton::TPoseTransforms( TMap<OptiTrackBoneID, FTransform>& transforms ) const
{
	for( const cRetargetBone& bone : mBones )
		transforms.FindOrAdd( bone.mID ) = FTransform( bone.mTPoseRotation ) * bone.mOffsetTransform;

	for( const cRetargetBone& bone : mBones )
	{
		if( bone.mParent )
			transforms[bone.mID] *= transforms[bone.mParent->mID];
	}

	FTransform invRoot = transforms[mBones[0].mID].Inverse();
	for( const cRetargetBone& bone : mBones )
		transforms[bone.mID] *= invRoot;
}
