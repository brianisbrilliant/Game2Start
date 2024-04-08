//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 

#include "AnimNode_OptitrackSkeleton.h"
#include "OptitrackClientOrigin.h"
#include <Internationalization/Regex.h>
#include <Animation/AnimInstanceProxy.h>
#include <BoneControllers/AnimNode_ModifyBone.h>
#include <Engine/SkeletalMeshSocket.h>

#if OPTITRACK_SKELNODE_DEBUGDRAW
#	include <DrawDebugHelpers.h>
#endif

FAnimNode_OptitrackSkeleton::FAnimNode_OptitrackSkeleton():
#if 0
    mOptitrackSkeletonQuatBasisChange(FRotator(0, 90, 0)),
    mOptitrackSkeletonQuatBasisChangeInv(FRotator(0, -90, 0))
#else
    mOptitrackSkeletonQuatBasisChange( FRotator( 0, 0, 0 ) ),
    mOptitrackSkeletonQuatBasisChangeInv( FRotator( 0, 0, 0 ) )
#endif
{
    const uint8 kNumBones = static_cast<uint8>(EOptitrackBone::NumBones);
	BoneSockets.SetNum( kNumBones );
	MarkSkeletonDefinitionInvalid();
}


void FAnimNode_OptitrackSkeleton::Initialize_AnyThread( const FAnimationInitializeContext& Context )
{
	Super::Initialize_AnyThread( Context );

	MarkSkeletonDefinitionInvalid();
}

void FAnimNode_OptitrackSkeleton::CacheBones_AnyThread( const FAnimationCacheBonesContext& Context )
{
	const FBoneContainer& RequiredBones = Context.AnimInstanceProxy->GetRequiredBones();	

	OptitrackBoneMappings.Empty();
	for (FBoneSocketTarget& Socket : BoneSockets)
	{
        //BoneRef.Initialize( RequiredBones );
		Socket.InitializeBoneReferences(RequiredBones);
		if (Socket.bUseSocket)
		{
			// Socket needs additional initialization
			Socket.Initialize(Context.AnimInstanceProxy);
		}

		// initialize 
		FBoneReference BoneRef;
		FTransform SocketTransform;
		if (Socket.bUseSocket)
		{
			const USkeletalMeshComponent* OwnerMeshComponent = Context.AnimInstanceProxy->GetSkelMeshComponent();
			USkeletalMeshSocket const* const MeshSocket = OwnerMeshComponent->GetSocketByName(Socket.SocketReference.SocketName);
			if (!MeshSocket)
			{
				continue;
			}
			BoneRef.BoneName = MeshSocket->BoneName;
			BoneRef.Initialize(Context.AnimInstanceProxy->GetRequiredBones());
			SocketTransform = MeshSocket->GetSocketLocalTransform();
		}
		else
		{
			BoneRef = Socket.BoneReference;
		}
		FOptitrackBoneReference OptiBoneRef;
		OptiBoneRef.TargetBone = BoneRef;
		OptiBoneRef.SocketTransform = SocketTransform;
		OptitrackBoneMappings.Add(OptiBoneRef);
	}

    // Need this for FCompactPose.
    FMemMark Mark( FMemStack::Get() );

    FCompactPose RefPose;
    
	RefPose.SetBoneContainer( &RequiredBones );
	RefPose.ResetToRefPose();

	FCSPose<FCompactPose> CsRefPose;
	CsRefPose.InitPose( RefPose );
    
	// Composite measurements
	const FVector HipPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::Hip );
	const FVector HeadPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::Head );
	const FVector LFootPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::LFoot );
	const FVector RFootPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::RFoot );
	TargetScaling.TorsoLength = (HeadPos - HipPos).Size();
	TargetScaling.AvgLegLength = ((LFootPos - HipPos).Size() + (RFootPos - HipPos).Size()) / 2.0f;
	TargetScaling.Height = (HeadPos - RFootPos / 2.0f - LFootPos / 2.0f).Size();

	const FVector LHandPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::LHand );
	const FVector RHandPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::RHand );
	const FVector LShoulderPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::LShoulder );
	const FVector RShoulderPos = GetCsBoneLocation( CsRefPose, Context.AnimInstanceProxy, EOptitrackBone::RShoulder );
	const float IntraShoulderDist = (LShoulderPos - RShoulderPos).Size();
	const float IntraHandDist = (LHandPos - RHandPos).Size();
	TargetScaling.AvgArmLength = (IntraHandDist - IntraShoulderDist) / 2.0f;

    // initialize ignore bone array
    const TArray<int32> PoseIndexArray = RequiredBones.GetSkeletonToPoseBoneIndexArray();
    IgnoreBoneIndices.Reset(kMaxSourceBones);
    // Loop through bones and find all ignore bones (which include roll bones)
    for (int32 BoneIndex : PoseIndexArray)
    {
        if (BoneIndex == -1)
        {
            continue;
        }
        bool BoneIndexInBoneMappings = false;
		for (FOptitrackBoneReference& OptiBoneRef : OptitrackBoneMappings)
        {
            //if (BoneRef.BoneIndex == BoneIndex)
			if(OptiBoneRef.TargetBone.CachedCompactPoseIndex == RequiredBones.GetCompactPoseIndexFromSkeletonIndex(BoneIndex))
            {
                BoneIndexInBoneMappings = true;
                break;
            }
        }
        if (!BoneIndexInBoneMappings)
        {
            // add to ignore bone list
            IgnoreBoneIndices.Push(BoneIndex);
            // check if also a roll bone
            FName BoneName = RequiredBones.GetReferenceSkeleton().GetBoneName(BoneIndex);
            TArray<FRegexPattern> RollBoneCandidates;
            RollBoneCandidates.Push(FRegexPattern(TEXT(".*roll.*")));
            RollBoneCandidates.Push(FRegexPattern(TEXT(".*twist.*")));
            for (FRegexPattern& Pattern : RollBoneCandidates)
            {
                FRegexMatcher Matcher(Pattern, BoneName.ToString());
                if (Matcher.FindNext())
                {
                    // Bone is a roll bone
                    RollBoneIndices.Push(BoneIndex);
                    RollBoneParentIndices.Push(RequiredBones.GetParentBoneIndex(BoneIndex));
					RollBoneRefs[BoneIndex] = FBoneReference(BoneName);
                    break;
                }
            }
        }
    }

	// initialize rollbone refs
	for (std::pair<const int32,FBoneReference>& pair : RollBoneRefs)
	{
		pair.second.Initialize(RequiredBones);
	}

    // Exact segment lengths - skip the root bone.
    TargetScaling.BoneDistanceToParent[0] = 0.0f;
    for (uint8 BoneId = 2; BoneId < static_cast<uint8>(EOptitrackBone::NumBones); ++BoneId)
    {
        EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);
        float BoneLength = GetCsBoneDistanceToParent(CsRefPose, Bone);
        if (BoneLength == 0.0f)
        {
            TargetScaling.BoneDistanceToParent[BoneId] = 1.0f;
        }
        else
        {
            TargetScaling.BoneDistanceToParent[BoneId] = BoneLength;
        }
    }
}


void FAnimNode_OptitrackSkeleton::Update_AnyThread( const FAnimationUpdateContext& Context )
{
	GetEvaluateGraphExposedInputs().Execute(Context);

	if ( StreamingClientOrigin == nullptr )
	{
		return;
	}

	if ( SourceSkeletonDefinitionValid == false )
	{
		if ( ! TryUpdateSkeletonDefinition() )
		{
			return;
		}
	}

    const bool DataAvailable = StreamingClientOrigin->GetLatestSkeletonStateByName(SourceSkeletonAssetName, LatestSkeletonState);
    
	if ( DataAvailable == false )
	{
		MarkSkeletonDefinitionInvalid();
		return;
	}
	ExtractSourceScalingFromLatestState();
	UpdateTargetScaleRatios();
}

void FAnimNode_OptitrackSkeleton::EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output)
{
	Output.ResetToRefPose();

	if (SourceSkeletonDefinitionValid && !PoseCorrectionCalculated)
	{
		const FBoneContainer& RequiredBones = Output.AnimInstanceProxy->GetRequiredBones();
		// compute 
		ComputePoseCorrection(Output);
		
		PoseCorrectionCalculated = true;
	}

	// setup up spine interpolant
	if (SpineCurve.Initialized)
	{
		SpineCurve.SpinePosCurve.Reset();
		SpineCurve.SpineRotCurve.Reset();
		int idx = 0;
		for (EOptitrackBone Bone : SpineBones)
		{
			const uint8 BoneId = static_cast<uint8>(Bone);
			const int32 BoneStreamingId = BoneStreamingIds[BoneId];
			if (BoneStreamingId < 0)
			{
				continue;
			}
			const FTransform& SpineTransform = LatestSkeletonState.WorldSpaceBoneTransforms[BoneStreamingId];
			SpineCurve.SpinePosCurve.AddPoint(SpineCurve.SourceSpineValues[Bone] / SpineCurve.SourceSpineLength, SpineTransform.GetLocation());
			SpineCurve.SpineRotCurve.AddPoint(SpineCurve.SourceSpineValues[Bone] / SpineCurve.SourceSpineLength, SpineTransform.GetRotation());
			idx++;
		}
	}

	for (int BoneId = 0; BoneId < static_cast<int>(EOptitrackBone::NumBones); ++BoneId)
	{
		if (BoneSockets[BoneId].bUseSocket)
		{
			const USkeletalMeshComponent* OwnerMeshComponent = Output.AnimInstanceProxy->GetSkelMeshComponent();
			USkeletalMeshSocket const* const MeshSocket = OwnerMeshComponent->GetSocketByName(BoneSockets[BoneId].SocketReference.SocketName);
			if (MeshSocket)
			{
				OptitrackBoneMappings[BoneId].SocketTransform = MeshSocket->GetSocketLocalTransform();
			}
		}
		PerformStreamingRetargeting(Output, BoneId);
	}
	
	for (const FCompactPoseBoneIndex fcpIdx : Output.Pose.GetPose().ForEachBoneIndex())
	{
		Output.Pose.GetPose()[fcpIdx].DiagnosticCheck_IsValid();
	}
	
}
void FAnimNode_OptitrackSkeleton::PerformStreamingRetargeting(FComponentSpacePoseContext& PoseContext, uint8 BoneId)
{
	if (BoneId >= OptitrackBoneMappings.Num() || BoneId >= kMaxSourceBones)
	{
		return;
	}

	FBoneReference& BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
	if (!BoneRef.IsValidToEvaluate())
	{
		return;
	}
	
	const int32 BoneStreamingId = BoneStreamingIds[BoneId];

	if (BoneStreamingId < 0)
	{
		return;
	}

	const FCompactPoseBoneIndex fcpIdx = BoneRef.CachedCompactPoseIndex;
	const EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);

	// Some bones should be mapped w/out translation ( common with fingers)
	bool IgnoreTranslation = FingerRotationOnly && FingerBones.Contains(Bone);
	IgnoreTranslation |= !UseTranslationCorrection;

	// Initialize bone modifier
	FAnimNode_ModifyBone boneModifier;
	boneModifier.BoneToModify = BoneRef;
	// all calculations should be done in world space
	boneModifier.RotationSpace = EBoneControlSpace::BCS_WorldSpace;
	boneModifier.TranslationSpace = EBoneControlSpace::BCS_WorldSpace;
	boneModifier.ScaleSpace = EBoneControlSpace::BCS_WorldSpace;
	// replace (as opposed to additive/ignore) current pose data with Optitrack data
	boneModifier.TranslationMode = IgnoreTranslation ? EBoneModificationMode::BMM_Ignore : EBoneModificationMode::BMM_Replace;
	boneModifier.RotationMode = EBoneModificationMode::BMM_Replace;
	boneModifier.ScaleMode = ScaleBones ? EBoneModificationMode::BMM_Replace : EBoneModificationMode::BMM_Ignore;

	// Three rotations are needed to apply OptiTrack data to skeleton
	//		1. Optitrack data, data comes from OptitrackClientOrigin (LHS vs RHS already handled)
	//			'StreamingTransform' - World Space
	//		2. Skeleton reference rotation (not necessarily a T-pose)
	//			'WorldRefRotation' - World Space
	//		3. Pose Correction Rotation, Rotation needed to modify skeleton reference rotation into a perfect T-pose
	//			'PoseCorrectionRotation' - World Space

	// 1. Optitrack bone data
	FTransform& StreamingTransform = LatestSkeletonState.WorldSpaceBoneTransforms[BoneStreamingId];
	// 2. Skeleton Reference rotation (not necessarily a T-pose)
	const FQuat WorldRefRotation = GetWorldRefTransform(PoseContext, fcpIdx).GetRotation();
	// 3. Pose Correction
	FQuat PoseCorrectionRotation(0, 0, 0, 1);
	if (PoseCorrection)
	{
		PoseCorrectionRotation = GetRefPoseCorrectionRotation(fcpIdx);
	}

	// Spine interpolation
	if (UseSpineInterpolation && SpineBones.Contains(Bone) && SpineCurve.Initialized)
	{
		float spineVal = SpineCurve.TargetSpineValues[fcpIdx] / SpineCurve.TargetSpineLength;
		FVector SpinePos = SpineCurve.SpinePosCurve.Eval(spineVal);
		FQuat SpineRot = SpineCurve.SpineRotCurve.Eval(spineVal);
		StreamingTransform.SetLocation(SpinePos);
		StreamingTransform.SetRotation(SpineRot);
	}
	// end spine interpolation
	
	// build pose rotation
	//		Motive * Component Space Rotation (Y forward w.r.t skeleton in UE) * T-Pose from Ref Skeleton * Ref Skeleton
	FQuat PoseRotation = StreamingTransform.GetRotation() * FQuat(SkeletonBaseRotation) * PoseCorrectionRotation * WorldRefRotation;

	// Roll bone calculation
	// Check if current bone is the parent of a rollbone
	FQuat RollBoneRotation(0, 0, 0, 1);
	bool ShouldApplyRollBoneRotation = false;
	if (RollBoneInterpolation && RollBoneParentIndices.Contains(fcpIdx.GetInt()) && SupportedRollBones.Contains(Bone))
	{
		// detect if roll bone is in heirarchy or not
		int32 ArrayIndex = 0;
		RollBoneParentIndices.Find(fcpIdx.GetInt(), ArrayIndex);
		const int32 RollBoneIndex = RollBoneIndices[ArrayIndex];
		const EOptitrackBone ChildBone = GetBoneSegmentChild(Bone);
		const FCompactPoseBoneIndex ChildIdx = OptitrackBoneMappings[static_cast<uint8>(ChildBone)].TargetBone.CachedCompactPoseIndex;
		const bool RollBoneInHierarchy = PoseContext.Pose.GetPose().GetParentBoneIndex(ChildIdx).GetInt() == RollBoneIndex;

		// Decompose Optitrack local pose rotation into swing/twist.
		const FVector BoneAxis = GetLocalBoneAxisFromDefinition(Bone).GetSafeNormal();
		int32 ChildBoneStreamingId = BoneStreamingIds[static_cast<uint8>(GetBoneSegmentChild(Bone))];
		const FQuat OptitrackLocalRotation = LatestSkeletonState.LocalBoneSpaceTransforms[BoneStreamingId].GetRotation();
		FQuat Swing; FQuat Twist;
		OptitrackLocalRotation.ToSwingTwist(BoneAxis, Swing, Twist);

		// Apply roll bone blend and create roll bone rotation
		const FQuat RollBoneTwist = FQuat::Slerp(FQuat(0, 0, 0, 1), Twist, RollBoneBlending);
		const FQuat RollBoneSwing = OptitrackLocalRotation * RollBoneTwist.Inverse();
		// NOTE: OptitrackLocalRotation.Inverse() * RollBoneSwing * RollBoneTwist = FQuat(0,0,0,1)
		//		RollBoneTwist.Inverse() = OptitrackLocalRotation.Inverse() * RollBoneSwing
		
		if (RollBoneInHierarchy)
		{
			// Roll bone is in heirarchy
			// Remove twist from current bone rotation
			// Twist bone should have the normal rotation
			PoseRotation = StreamingTransform.GetRotation() * RollBoneTwist.Inverse() * FQuat(SkeletonBaseRotation) * PoseCorrectionRotation * WorldRefRotation;
			RollBoneRotation = StreamingTransform.GetRotation() * FQuat(SkeletonBaseRotation) * PoseCorrectionRotation * WorldRefRotation;
		}
		else
		{
			// Roll bone not in heirarchy
			// No need to modify rotation of current bone, only need to 'untwist' on twist bone 
			// Will make it look like current bone has no twist (although it does)
			RollBoneRotation = StreamingTransform.GetRotation() * OptitrackLocalRotation.Inverse() * RollBoneSwing * RollBoneTwist.Inverse() * FQuat(SkeletonBaseRotation) * PoseCorrectionRotation * WorldRefRotation;
		}

		ShouldApplyRollBoneRotation = true;
	}

	// Update bone modifier transform
	boneModifier.Rotation = FRotator(PoseRotation);
	boneModifier.Translation = StreamingTransform.GetLocation() - PoseRotation.RotateVector(OptitrackBoneMappings[BoneId].SocketTransform.GetLocation());
	boneModifier.Scale = TargetBoneLocalScaleRatios[BoneId];

	// apply transformation to pose context
	TArray<FBoneTransform> BoneTransforms;
	boneModifier.EvaluateSkeletalControl_AnyThread(PoseContext, BoneTransforms);
	if (BoneTransforms.Num() > 0)
	{
		PoseContext.Pose.SafeSetCSBoneTransforms(BoneTransforms);
	}

	if (ShouldApplyRollBoneRotation)
	{
		// Get bone index of roll bone
		int32 ArrayIndex = 0;
		RollBoneParentIndices.Find(fcpIdx.GetInt(), ArrayIndex);
		const int32 RollBoneIndex = RollBoneIndices[ArrayIndex];

		// create bone modifier to apply twist to rollbone
		FAnimNode_ModifyBone RollBoneModifier;
		RollBoneModifier.BoneToModify = RollBoneRefs[RollBoneIndex];
		// all calculations should be done in world space
		RollBoneModifier.RotationSpace = EBoneControlSpace::BCS_WorldSpace;
		// replace (as opposed to additive/ignore) current pose data with Optitrack data
		RollBoneModifier.TranslationMode =EBoneModificationMode::BMM_Ignore;
		RollBoneModifier.RotationMode = EBoneModificationMode::BMM_Replace;
		RollBoneModifier.ScaleMode = EBoneModificationMode::BMM_Ignore;
		RollBoneModifier.Rotation = FRotator(RollBoneRotation);

		// apply transformation to pose context
		TArray<FBoneTransform> RollBoneTransforms;
		RollBoneModifier.EvaluateSkeletalControl_AnyThread(PoseContext, RollBoneTransforms);
		if (RollBoneTransforms.Num() > 0)
		{
			PoseContext.Pose.SafeSetCSBoneTransforms(RollBoneTransforms);
		}
	}
}

#if WITH_EDITORONLY_DATA
bool FAnimNode_OptitrackSkeleton::UpdateRetargetBasePose()
{
	if ( RetargetBaseMesh )
	{
		RetargetBasePose = RetargetBaseMesh->GetRetargetBasePose();

		for ( FTransform& RetargetBaseTransform : RetargetBasePose )
		{
			RetargetBaseTransform.NormalizeRotation();
		}

		return true;
	}

	return false;
}

#endif // #if WITH_EDITORONLY_DATA


void FAnimNode_OptitrackSkeleton::CacheStreamingBoneIds( EOptitrackBoneNamingConvention BoneNamingConvention )
{
	for ( int BoneIdx = 0; BoneIdx < kMaxSourceBones; ++BoneIdx )
	{
		BoneStreamingIds[BoneIdx] = FindBoneId( GetStreamingBoneName( static_cast<EOptitrackBone>(BoneIdx), BoneNamingConvention ) );
	}
}

void FAnimNode_OptitrackSkeleton::ComputePoseCorrection(const FComponentSpacePoseContext& Pose)
{
	// calculate skeleton base rotation by looking at mapped hands/feet
	 // get base rotation (Y forward vs X forward)
	if (OptitrackBoneMappings[static_cast<uint8>(EOptitrackBone::LFoot)].TargetBone.IsValidToEvaluate() && OptitrackBoneMappings[static_cast<uint8>(EOptitrackBone::RFoot)].TargetBone.IsValidToEvaluate())
	{
		// use world translation between feet to infer what is left/right versus forward/backward. Assumes Z is up
		const FBoneReference& LFootBone = OptitrackBoneMappings[static_cast<uint8>(EOptitrackBone::LFoot)].TargetBone;
		const FBoneReference& RFootBone = OptitrackBoneMappings[static_cast<uint8>(EOptitrackBone::RFoot)].TargetBone;
		const FVector LFootLocation = GetWorldRefTransform(Pose, LFootBone.CachedCompactPoseIndex).GetLocation();
		const FVector RFootLocation = GetWorldRefTransform(Pose, RFootBone.CachedCompactPoseIndex).GetLocation();
		const FVector FootDiff = (LFootLocation - RFootLocation).GetSafeNormal();

		const double tol = 0.1;
		if (FVector::DotProduct(FVector(1, 0, 0), FootDiff) > 1 - tol)
		{
			// X+ takes you from right to left => Y forward
			SkeletonBaseRotation = FRotator(0, -90, 0);
		}
	}

	// loop through bones and compute necessary rotation to make UE ref pose into a perfect T-pose	
	for (int BoneId = 1; BoneId < static_cast<int>(EOptitrackBone::NumBones); ++BoneId)
	{
		const FBoneReference& BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
		const EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);
		if (!BoneRef.IsValidToEvaluate())
		{
			continue;
		}

		ComputePoseCorrection(Pose, BoneRef, Bone);
	}

	// calculate relative length along spine
	if (SourceSkeletonDefinitionValid)
	{
		bool flag = true;
		float SourceSpineLength = 0.0f;
		float TargetSpineLength = 0.0f;
		FVector TargetPrevBonePos;
		for (EOptitrackBone SpineBone : SpineBones)
		{
			
			const uint8 BoneId = static_cast<uint8>(SpineBone);
			if (!SourceSkeletonDefinition.Bones.Contains(BoneId) || BoneId >= OptitrackBoneMappings.Num())
			{
				break;
			}
			const FBoneReference& BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
			const FCompactPoseBoneIndex& fcpIdx = BoneRef.CachedCompactPoseIndex;
			if (!BoneRef.IsValidToEvaluate())
			{
				// spine bone not mapped, don't use interpolant
				flag = false;
				break;
			}
			if (SpineBone == EOptitrackBone::Hip)
			{
				TargetPrevBonePos = GetWorldRefTransform(Pose, BoneRef.CachedCompactPoseIndex).GetLocation();
			}
			else 
			{
				SourceSpineLength += SourceSkeletonDefinition.Bones[BoneId].LocalOffset.Size();
				FVector TargetSpineBonePos = GetWorldRefTransform(Pose, fcpIdx).GetLocation();
				TargetSpineLength += (TargetSpineBonePos - TargetPrevBonePos).Size();
				TargetPrevBonePos = TargetSpineBonePos;
			}

			SpineCurve.SourceSpineValues[SpineBone] = SourceSpineLength;
			SpineCurve.TargetSpineValues[fcpIdx] = TargetSpineLength;
		}

		if (flag)
		{
			SpineCurve.SourceSpineLength = SourceSpineLength;
			SpineCurve.TargetSpineLength = TargetSpineLength;
			SpineCurve.Initialized = true;
		}
	}
}
void FAnimNode_OptitrackSkeleton::ComputePoseCorrection(const FComponentSpacePoseContext& Pose, const FBoneReference& BoneRef, const EOptitrackBone& Bone)
{
	// Find the needed rotation to rotate a bone of the UE Skeleton to a perfect T-Pose
	// This is done by:
	// 1. Look at the current bone and it's child (for UE skeleton AND Motive character)
	// 2. Compute the vector that points from the current bone to child (world space)
	// 3. Compute the rotation needed to rotate the UE diff vector to the Motive diff vector

	FQuat WorldPoseCorrectionRotation(0, 0, 0, 1);
	FVector WorldPoseCorrectionTranslation(0, 0, 0);
	const uint8 BoneId = static_cast<uint8>(Bone);
	const FCompactPoseBoneIndex& fcpIdx = BoneRef.CachedCompactPoseIndex;
	const EOptitrackBone ChildBone = GetBoneSegmentChild(Bone);

	FVector BoneScaleAxis = GetLocalBoneAxis(Bone);

	if (ChildBone != EOptitrackBone::Root)
	{
		// Bone has a child w.r.t Motive heirarchy
		FBoneReference& ChildBoneRef = OptitrackBoneMappings[static_cast<uint8>(ChildBone)].TargetBone;
		if (ChildBoneRef.IsValidToEvaluate() && BoneRef.IsValidToEvaluate())
		{
			// Mapped child UE Bone is valid, compute rotation

			// UE - get world vector pointing from current bone to child
			const FVector ChildBoneLoc = GetWorldRefTransform(Pose, ChildBoneRef.CachedCompactPoseIndex).GetLocation();
			const FVector BoneLoc = GetWorldRefTransform(Pose, fcpIdx).GetLocation();
			const FVector RefSkeletonBoneAxis = BoneLoc - ChildBoneLoc;
			// OptiTrack - get world vector pointing from 
			const FVector OptiBoneAxis =SkeletonBaseRotation.UnrotateVector(-GetLocalBoneAxisFromDefinition(Bone));
			if (OptiBoneAxis.IsNearlyZero())
			{
				return;
			}

			// Get rotation needed to take reference skeleton bone axis -> optitrack bone axis
			//WorldPoseCorrectionRotation = FQuat::FindBetween(RefSkeletonBoneAxis, OptiBoneAxis);
			FVector RotAxis = FVector::CrossProduct(RefSkeletonBoneAxis, OptiBoneAxis);
			if (RotAxis.Size() > KINDA_SMALL_NUMBER)
			{
				RotAxis.Normalize();
				float theta = FMath::Acos(FVector::DotProduct(RefSkeletonBoneAxis.GetSafeNormal(), OptiBoneAxis.GetSafeNormal()));
				WorldPoseCorrectionRotation = FQuat(RotAxis, theta).GetNormalized();
			}
			// convert world ref bone axis to local space
			BoneScaleAxis = GetWorldRefTransform(Pose, fcpIdx).GetRotation().UnrotateVector(RefSkeletonBoneAxis);
			BoneScaleAxis = BoneScaleAxis.GetAbs();
		}
	}
	else
	{
		// no valid child
		// POLICY: use pose correction from parent
		WorldPoseCorrectionRotation = GetRefPoseCorrectionRotation(Pose.Pose.GetPose().GetParentBoneIndex(fcpIdx));
	}
	// cache result
	RefPoseCorrectionRotations[fcpIdx] = WorldPoseCorrectionRotation;
	RefPoseBoneScaleAxis[fcpIdx] = BoneScaleAxis.GetSafeNormal();
}

FTransform FAnimNode_OptitrackSkeleton::GetWorldRefTransform(const FComponentSpacePoseContext& Pose, const FCompactPoseBoneIndex& Idx) const
{
	if (Idx.GetInt() == INDEX_NONE)
	{
		return FTransform();
	}
	FCompactPoseBoneIndex ParentIdx = Pose.Pose.GetPose().GetParentBoneIndex(Idx);
	if (ParentIdx == INDEX_NONE)
	{
		// Parent is invalid => bone index (fcpIdx) is the root
		return Pose.Pose.GetPose().GetRefPose(Idx);
	}

	FTransform SocketTransform;
	for (const FOptitrackBoneReference& BoneRef : OptitrackBoneMappings)
	{
		if (Idx == BoneRef.TargetBone.CachedCompactPoseIndex)
		{
			SocketTransform = BoneRef.SocketTransform;
			break;
		}
	}

	return SocketTransform * Pose.Pose.GetPose().GetRefPose(Idx) * GetWorldRefTransform(Pose, ParentIdx);
}

FQuat FAnimNode_OptitrackSkeleton::GetRefPoseCorrectionRotation(const FCompactPoseBoneIndex& fcpIdx)
{
	if (RefPoseCorrectionRotations.find(fcpIdx) != RefPoseCorrectionRotations.end())
	{
		return FQuat(RefPoseCorrectionRotations[fcpIdx]);
	}
	else
	{
		return FQuat(0,0,0,1);
	}
}

int32 FAnimNode_OptitrackSkeleton::FindBoneId( const FName& BoneName )
{
	for ( const TPair<int, FOptitrackBoneDefinition>& pair : SourceSkeletonDefinition.Bones )
	{
		if ( pair.Value.Name.ToString().EndsWith( BoneName.ToString() ) )
		{
			return pair.Value.Id;
		}
	}

	return -1;
}

void FAnimNode_OptitrackSkeleton::MarkSkeletonDefinitionInvalid()
{
	SourceSkeletonDefinitionValid = false;

	for ( int32& BoneStreamingId : BoneStreamingIds )
	{
		BoneStreamingId = kInvalidBoneStreamingId;
	}

	ResetTargetScaleRatios();
}

bool FAnimNode_OptitrackSkeleton::TryUpdateSkeletonDefinition()
{
	if ( StreamingClientOrigin->FindSkeletonDefinition( SourceSkeletonAssetName, SourceSkeletonDefinition ) )
	{
		SourceSkeletonDefinitionValid = true;

		CacheStreamingBoneIds( StreamingClientOrigin->BoneNamingConvention );

		// Compute segment length adjustments as anisotropic bone scale factors.
		ExtractSourceScalingFromDefinition();
		UpdateTargetScaleRatios();

		return true;
	}
	else
	{
		return false;
	}
}

FVector FAnimNode_OptitrackSkeleton::GetRefBoneScaleAxisFromDefinition(EOptitrackBone Bone)
{
	int BoneId = static_cast<int>(Bone);
	if (OptitrackBoneMappings[BoneId].TargetBone.IsValidToEvaluate())
	{
		const FBoneReference& BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
		if (RefPoseBoneScaleAxis.find(BoneRef.CachedCompactPoseIndex) != RefPoseBoneScaleAxis.end())
		{
			return RefPoseBoneScaleAxis[BoneRef.CachedCompactPoseIndex];
		}
	}

	return GetLocalBoneScaleAxis(Bone);
}

// The returned vector should be either unit length or zero length (if the segment should not be scaled).
FVector FAnimNode_OptitrackSkeleton::GetLocalBoneScaleAxis( EOptitrackBone Bone ) const
{
	switch ( Bone )
	{
	case EOptitrackBone::Ab:
	case EOptitrackBone::Chest:
	case EOptitrackBone::Neck:
//    case EOptitrackBone::Head:
	case EOptitrackBone::LShoulder:
	case EOptitrackBone::RShoulder:
		//return FVector(1, 0, 0);
    case EOptitrackBone::LUArm:
    case EOptitrackBone::RUArm:
	case EOptitrackBone::LFArm:
	case EOptitrackBone::RFArm:
	case EOptitrackBone::LHand:
	case EOptitrackBone::RHand:
       // return FVector(1,0,0);
	case EOptitrackBone::LThigh:
    case EOptitrackBone::RThigh:
	case EOptitrackBone::LShin:
	case EOptitrackBone::RShin:
        //return FVector(1, 0, 0);
		return FVector(0,1,0);// LJS REMOVE THIS
	}

	return FVector::ZeroVector;
}

// The returned vector should be either unit length or zero length (if the segment should not be scaled).
FVector FAnimNode_OptitrackSkeleton::GetLocalBoneAxisFromDefinition(EOptitrackBone Bone) const
{
	if (SourceSkeletonDefinitionValid)
	{
		int ChildBoneId = static_cast<int>(GetBoneSegmentChild(Bone));
		if (SourceSkeletonDefinition.Bones.Contains(ChildBoneId))
		{
			// Get skeleton definition local offset for parent - child ( LocalOffset is child - parent, negate)
			FVector BoneAxis = SourceSkeletonDefinition.Bones[ChildBoneId].LocalOffset;
			return BoneAxis;
		}
		else
		{
			return GetLocalBoneAxis(Bone);
		}
	}
	else
	{
		return GetLocalBoneAxis(Bone);
	}
}

FVector FAnimNode_OptitrackSkeleton::GetLocalBoneAxis(EOptitrackBone Bone) const
{

	switch (Bone)
	{
	case EOptitrackBone::Root:
	case EOptitrackBone::Hip:
	case EOptitrackBone::Ab:
	case EOptitrackBone::Chest:
	case EOptitrackBone::Head:
	case EOptitrackBone::Neck:
		return FVector(0.0f, 0.0f, -1.0f);
	case EOptitrackBone::LShoulder:
	case EOptitrackBone::LUArm:
	case EOptitrackBone::LFArm:
	case EOptitrackBone::LHand:
	case EOptitrackBone::LIndex1:
	case EOptitrackBone::LIndex2:
	case EOptitrackBone::LIndex3:
	case EOptitrackBone::LMiddle1:
	case EOptitrackBone::LMiddle2:
	case EOptitrackBone::LMiddle3:
	case EOptitrackBone::LRing1:
	case EOptitrackBone::LRing2:
	case EOptitrackBone::LRing3:
	case EOptitrackBone::LPinky1:
	case EOptitrackBone::LPinky2:
	case EOptitrackBone::LPinky3:
		return FVector(0.0f, -1.0f, 0.0f);
	case EOptitrackBone::LThumb1:
	case EOptitrackBone::LThumb2:
	case EOptitrackBone::LThumb3:
	{
		return FVector(-sin(ThumbBaseRotation), cos(ThumbBaseRotation), 0.0f);
	}
	case EOptitrackBone::RShoulder:
	case EOptitrackBone::RUArm:
	case EOptitrackBone::RFArm:
	case EOptitrackBone::RHand:
	case EOptitrackBone::RIndex1:
	case EOptitrackBone::RIndex2:
	case EOptitrackBone::RIndex3:
	case EOptitrackBone::RMiddle1:
	case EOptitrackBone::RMiddle2:
	case EOptitrackBone::RMiddle3:
	case EOptitrackBone::RRing1:
	case EOptitrackBone::RRing2:
	case EOptitrackBone::RRing3:
	case EOptitrackBone::RPinky1:
	case EOptitrackBone::RPinky2:
	case EOptitrackBone::RPinky3:
		return FVector(0.0f, 1.0f, 0.0f);
	case EOptitrackBone::RThumb1:
	case EOptitrackBone::RThumb2:
	case EOptitrackBone::RThumb3:
	{
		return FVector(-sin(ThumbBaseRotation), -cos(ThumbBaseRotation), 0.0f);
	}
	case EOptitrackBone::LThigh:
	case EOptitrackBone::LShin:
	case EOptitrackBone::RThigh:
	case EOptitrackBone::RShin:
		return FVector(0.0f, 0.0f, 1.0f);
	}

	return FVector::ZeroVector;
}

EOptitrackBone FAnimNode_OptitrackSkeleton::GetBoneSegmentChild( EOptitrackBone Bone ) const
{
	switch ( Bone )
	{
    case EOptitrackBone::Root: return EOptitrackBone::Hip;
    case EOptitrackBone::Hip: return EOptitrackBone::Ab;
	case EOptitrackBone::Ab: return EOptitrackBone::Chest;
	case EOptitrackBone::Chest: return EOptitrackBone::Neck;
	case EOptitrackBone::Neck: return EOptitrackBone::Head;
	case EOptitrackBone::LShoulder: return EOptitrackBone::LUArm;
	case EOptitrackBone::LUArm: return EOptitrackBone::LFArm;
	case EOptitrackBone::LFArm: return EOptitrackBone::LHand;
	case EOptitrackBone::RShoulder: return EOptitrackBone::RUArm;
	case EOptitrackBone::RUArm: return EOptitrackBone::RFArm;
	case EOptitrackBone::RFArm: return EOptitrackBone::RHand;
	case EOptitrackBone::LThigh: return EOptitrackBone::LShin;
	case EOptitrackBone::LShin: return EOptitrackBone::LFoot;
    case EOptitrackBone::LFoot: return EOptitrackBone::LToe;
	case EOptitrackBone::RThigh: return EOptitrackBone::RShin;
	case EOptitrackBone::RShin: return EOptitrackBone::RFoot;
    case EOptitrackBone::RFoot: return EOptitrackBone::RToe;
    case EOptitrackBone::LHand: return EOptitrackBone::LMiddle1;
    case EOptitrackBone::RHand: return EOptitrackBone::RMiddle1;
    case EOptitrackBone::LThumb1: return EOptitrackBone::LThumb2;
    case EOptitrackBone::LThumb2:   return EOptitrackBone::LThumb3;
    case EOptitrackBone::LIndex1:return EOptitrackBone::LIndex2;
    case EOptitrackBone::LIndex2:return EOptitrackBone::LIndex3;
    case EOptitrackBone::LMiddle1:return EOptitrackBone::LMiddle2;
    case EOptitrackBone::LMiddle2:return EOptitrackBone::LMiddle3;
    case EOptitrackBone::LRing1:return EOptitrackBone::LRing2;
    case EOptitrackBone::LRing2:return EOptitrackBone::LRing3;
    case EOptitrackBone::LPinky1:return EOptitrackBone::LPinky2;
    case EOptitrackBone::LPinky2: return EOptitrackBone::LPinky3;
    case EOptitrackBone::RThumb1: return EOptitrackBone::RThumb2;
    case EOptitrackBone::RThumb2:   return EOptitrackBone::RThumb3;
    case EOptitrackBone::RIndex1:return EOptitrackBone::RIndex2;
    case EOptitrackBone::RIndex2:return EOptitrackBone::RIndex3;
    case EOptitrackBone::RMiddle1:return EOptitrackBone::RMiddle2;
    case EOptitrackBone::RMiddle2:return EOptitrackBone::RMiddle3;
    case EOptitrackBone::RRing1:return EOptitrackBone::RRing2;
    case EOptitrackBone::RRing2:return EOptitrackBone::RRing3;
    case EOptitrackBone::RPinky1:return EOptitrackBone::RPinky2;
    case EOptitrackBone::RPinky2: return EOptitrackBone::RPinky3;
	}

	return EOptitrackBone::Root;
}


void FAnimNode_OptitrackSkeleton::ExtractSourceScalingFromDefinition()
{
	const FVector HipPos = GetStreamDefBoneLocation( GetStreamingId( EOptitrackBone::Hip ) );
	const FVector HeadPos = GetStreamDefBoneLocation( GetStreamingId( EOptitrackBone::Head ) );
	const FVector LFootPos = GetStreamDefBoneLocation( GetStreamingId( EOptitrackBone::LFoot ) );
	const FVector RFootPos = GetStreamDefBoneLocation( GetStreamingId( EOptitrackBone::RFoot ) );
	SourceScaling.TorsoLength = (HeadPos - HipPos).Size();
	SourceScaling.AvgLegLength = ((LFootPos - HipPos).Size() + (RFootPos - HipPos).Size()) / 2.0f;

	SourceScaling.Height = (HeadPos - RFootPos / 2.0f - LFootPos / 2.0f).Size();

	// Exact segment lengths - skip the root bone.
	SourceScaling.BoneDistanceToParent[0] = 0.0f;
	for ( uint8 BoneId = 1; BoneId < static_cast<uint8>(EOptitrackBone::NumBones); ++BoneId )
	{
		EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);
		SourceScaling.BoneDistanceToParent[BoneId] = GetStreamDefBoneDistanceToParent( Bone );
	}
}


void FAnimNode_OptitrackSkeleton::ExtractSourceScalingFromLatestState()
{
	// Exact segment lengths - skip the root bone.
	SourceScaling.BoneDistanceToParent[0] = 0.0f;
	for ( uint8 BoneId = 1; BoneId < static_cast<uint8>(EOptitrackBone::NumBones); ++BoneId )
	{
		EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);
		SourceScaling.BoneDistanceToParent[BoneId] = GetStreamDefBoneDistanceToParent( Bone );
	}
}


void FAnimNode_OptitrackSkeleton::UpdateTargetScaleRatios()
{
	const float SourceHeadToAnkle = SourceScaling.Height;
	const float TargetHeadToAnkle = TargetScaling.Height;
	float TargetRootScaleRatio = 1.0f;

	// handle case for non-full skeletons where head/feet/arms aren't necessarily mapped
	if (SourceHeadToAnkle != 0.0f && TargetHeadToAnkle != 0.0f)
	{
		TargetRootScaleRatio = SourceHeadToAnkle / TargetHeadToAnkle;
	}

	TargetBoneLocalScaleRatios[static_cast<uint8>(EOptitrackBone::Root)] = FVector(TargetRootScaleRatio);
	TargetBoneLocalScaleRatios[static_cast<uint8>(EOptitrackBone::Hip)] = FVector(TargetRootScaleRatio);

	// Segment length ratios - skip the root and hips.
	static_assert(0 == static_cast<uint8>(EOptitrackBone::Root), "Expecting to skip root by starting at 2");
	static_assert(1 == static_cast<uint8>(EOptitrackBone::Hip), "Expecting to skip hips by starting at 2");
	for ( uint8 BoneId = 2; BoneId < static_cast<uint8>(EOptitrackBone::NumBones); ++BoneId )
	{
		const EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);
		const uint8 SegmentChildId = static_cast<uint8>(GetBoneSegmentChild( Bone ));
		if (SegmentChildId != 0)
		{
            if (TargetScaling.BoneDistanceToParent[SegmentChildId] != 0.0f && SourceScaling.BoneDistanceToParent[SegmentChildId] != 0.0f && OptitrackBoneMappings[BoneId].TargetBone.IsValidToEvaluate() && OptitrackBoneMappings[SegmentChildId].TargetBone.IsValidToEvaluate())
            {				
				FVector boneAxis = GetRefBoneScaleAxisFromDefinition(Bone);
				FVector boneScale = FVector(1.f) + (SourceScaling.BoneDistanceToParent[SegmentChildId] / TargetScaling.BoneDistanceToParent[SegmentChildId] / TargetRootScaleRatio - 1) * boneAxis;

				// scale torso as a whole, default behaviour interpolates spine
				switch (Bone)
				{
				case EOptitrackBone::Ab:
				case EOptitrackBone::Chest:
				case EOptitrackBone::Neck:
				case EOptitrackBone::Head:
					boneScale = FVector(1.f) + (SourceScaling.TorsoLength / TargetScaling.TorsoLength / TargetRootScaleRatio - 1) * GetLocalBoneScaleAxis(Bone);
				}

                if (boneAxis != FVector::ZeroVector)
                {
                    TargetBoneLocalScaleRatios[BoneId] = TargetRootScaleRatio * boneScale;
                }
                else
                {
					TargetBoneLocalScaleRatios[BoneId] = TargetRootScaleRatio * FVector(1.0f);// FVector(1.0f);
                }
            }
            else
            {
                TargetBoneLocalScaleRatios[BoneId] = TargetRootScaleRatio * FVector(1.f);
            }
		}
		else if(Bone == EOptitrackBone::Head)
		{
			TargetBoneLocalScaleRatios[BoneId] = TargetRootScaleRatio * FVector(1.f);
		}
		else
		{
			TargetBoneLocalScaleRatios[BoneId] = FVector( 1.f );
		}
	}
}

void FAnimNode_OptitrackSkeleton::ResetTargetScaleRatios()
{
	for ( FVector& BoneScaleRatio : TargetBoneLocalScaleRatios )
	{
		BoneScaleRatio = FVector( 1.0f );
	}
}


int32 FAnimNode_OptitrackSkeleton::GetStreamingId( EOptitrackBone Bone ) const
{
	const uint8 BoneId = static_cast<uint8>(Bone);
	return BoneStreamingIds[BoneId];
}

FVector FAnimNode_OptitrackSkeleton::GetCsBoneLocation( /*const*/ FCSPose<FCompactPose>& CsPose, const FAnimInstanceProxy* AnimInstance, EOptitrackBone Bone) const
{
	const FBoneContainer& RequiredBones = CsPose.GetPose().GetBoneContainer();
	const uint8 BoneId = static_cast<uint8>(Bone);
	FBoneReference BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
	
	if (BoneRef.IsValidToEvaluate(RequiredBones))
	{
		const FCompactPoseBoneIndex BoneIdx = BoneRef.GetCompactPoseIndex(RequiredBones);
		return CsPose.GetComponentSpaceTransform(BoneIdx).GetLocation() + CsPose.GetComponentSpaceTransform(BoneIdx).GetRotation().RotateVector(OptitrackBoneMappings[BoneId].SocketTransform.GetLocation());
	}
	

	return FVector::ZeroVector;
}


float FAnimNode_OptitrackSkeleton::GetCsBoneDistanceToParent( /*const*/ FCSPose<FCompactPose>& CsPose, EOptitrackBone Bone ) const
{
	const FBoneContainer& RequiredBones = CsPose.GetPose().GetBoneContainer();
	const uint8 BoneId = static_cast<uint8>(Bone);
	if (BoneId > OptitrackBoneMappings.Num() - 1)
	{
		return 0.f;
	}
	const FBoneReference& BoneRef = OptitrackBoneMappings[BoneId].TargetBone;
	if ( BoneRef.IsValidToEvaluate( RequiredBones ) )
	{
		const FCompactPoseBoneIndex BoneIdx = BoneRef.GetCompactPoseIndex( RequiredBones );
        const FCompactPoseBoneIndex ParentBoneIdx = GetMappedParentPoseIndex(CsPose.GetPose(), BoneIdx);
        check(ParentBoneIdx != BoneIdx);

		if ( CsPose.GetPose().IsValidIndex( ParentBoneIdx ) )
		{
			const FTransform SocketTransform = OptitrackBoneMappings[BoneId].SocketTransform;
			const FVector BoneCsLocation = CsPose.GetComponentSpaceTransform(BoneIdx).GetLocation() + CsPose.GetComponentSpaceTransform(BoneIdx).GetRotation().RotateVector(SocketTransform.GetLocation());
			FTransform ParentSocketTransform;
			for (const FOptitrackBoneReference& ParentBoneRef : OptitrackBoneMappings)
			{
				if (ParentBoneRef.TargetBone.CachedCompactPoseIndex == ParentBoneIdx)
				{
					ParentSocketTransform = ParentBoneRef.SocketTransform;
					break;
				}
			}
			const FVector ParentCsLocation = CsPose.GetComponentSpaceTransform(ParentBoneIdx).GetLocation();// -CsPose.GetComponentSpaceTransform(ParentBoneIdx).GetRotation().RotateVector(ParentSocketTransform.GetLocation());
			return (BoneCsLocation - ParentCsLocation).Size();
		}
	}

	return 0.f;
}

FCompactPoseBoneIndex FAnimNode_OptitrackSkeleton::GetMappedParentPoseIndex(const FCompactPose& Pose, const FCompactPoseBoneIndex BoneIdx) const
{
    check(Pose.IsValidIndex(BoneIdx))
    if (!Pose.IsValidIndex(BoneIdx))
    {
        return BoneIdx;
    }
    // find parent compact pose bone index that is mapped (not an ignore bone)
    const FCompactPoseBoneIndex ParentBoneIdx = Pose.GetBoneContainer().GetParentBoneIndex(BoneIdx);
	if (!Pose.IsValidIndex(ParentBoneIdx))
	{
		return BoneIdx;
	}
    check(Pose.IsValidIndex(ParentBoneIdx));
    if (!IgnoreBoneIndices.Contains(ParentBoneIdx.GetInt()))
    {
        // Parent is not an ignore bone (i.e. mapped). Return parent index;
        return ParentBoneIdx;
    }
    else
    {
        return GetMappedParentPoseIndex(Pose, ParentBoneIdx);
    }
}

FVector FAnimNode_OptitrackSkeleton::GetStreamDefBoneLocation( int32 StreamingId ) const
{
    if (StreamingId == -1)
    {
        return FVector(0, 0, 0);
    }
	const FOptitrackBoneDefinition& BoneDef = SourceSkeletonDefinition.Bones[StreamingId];
	const FVector BoneLocalPos = BoneDef.LocalOffset;
	if ( BoneDef.ParentId != kInvalidBoneStreamingId )
	{
		return BoneLocalPos + GetStreamDefBoneLocation( BoneDef.ParentId );
	}
	else
	{
		return BoneLocalPos;
	}
}


float FAnimNode_OptitrackSkeleton::GetStreamDefBoneDistanceToParent( EOptitrackBone Bone ) const
{
	const int32 StreamingId = GetStreamingId( Bone );
	if ( StreamingId != kInvalidBoneStreamingId )
	{
		return SourceSkeletonDefinition.Bones[StreamingId].LocalOffset.Size();
	}
	else
	{
		return 0.f;
	}
}


float FAnimNode_OptitrackSkeleton::GetLatestStateBoneDistanceToParent( EOptitrackBone Bone ) const
{
	const int32 StreamingId = GetStreamingId( Bone );
	if ( StreamingId != kInvalidBoneStreamingId )
	{
		return LatestSkeletonState.BonePoses[StreamingId].Position.Size();
	}
	else
	{
		return 0.f;
	}
}


//#if OPTITRACK_SKELNODE_DEBUGDRAW
template< typename PoseT >
void FAnimNode_OptitrackSkeleton::DrawPose( FAnimInstanceProxy* DrawProxy, FCSPose< PoseT >& CsPose, const FColor& DrawColor )
{
	if ( DrawProxy == nullptr )
	{
		return;
	}

	const FTransform ComponentToWorld = DrawProxy->GetSkelMeshComponent()
		? DrawProxy->GetSkelMeshComponent()->GetComponentToWorld()
		: FTransform::Identity;

	for ( const FCompactPoseBoneIndex fcpIdx : CsPose.GetPose().ForEachBoneIndex() )
	{
		FTransform BoneTM = CsPose.GetComponentSpaceTransform( fcpIdx );
		BoneTM.NormalizeRotation();

		FVector Start, End;
		FColor LineColor = DrawColor;

		End = BoneTM.GetLocation();

		const FCompactPoseBoneIndex fcpParentIdx = CsPose.GetPose().GetParentBoneIndex( fcpIdx );
		if ( fcpParentIdx >= 0 )
		{
			FTransform ParentTM = CsPose.GetComponentSpaceTransform( fcpParentIdx );
			ParentTM.NormalizeRotation();
			Start = ParentTM.GetLocation();
		}
		else
		{
			Start = FVector::ZeroVector;//ComponentToWorld.GetLocation();
			LineColor = FColor::Red;
		}

		static const float SphereRadius = 1.0f;

		// Calc cone size
#if 0
		FVector EndToStart = (Start - End);
		float ConeLength = EndToStart.Size();
		float Angle = FMath::RadiansToDegrees( FMath::Atan( SphereRadius / ConeLength ) ) * 0.02f;
		DrawDebugCone( World, End, EndToStart, ConeLength, Angle, Angle, 4, LineColor );
		DrawDebugSphere( World, End, SphereRadius, 10, LineColor );
		DrawDebugCoordinateSystem( World, End, BoneTM.Rotator(), SphereRadius );

		const FMeshPoseBoneIndex MeshIdx =
			CsPose.GetPose().GetBoneContainer().MakeMeshPoseIndex( fcpIdx );
		const FName& BoneName =
			SkelMeshComp->SkeletalMesh->RefSkeleton.GetRefBoneInfo()[ MeshIdx.GetInt() ].Name;

		DrawDebugString( World, End, BoneName.ToString(), nullptr, FColor::White, 0.0f );
#else
		const FVector WorldStart = ComponentToWorld.TransformPosition( Start );
		const FVector WorldEnd = ComponentToWorld.TransformPosition( End );
		DrawProxy->AnimDrawDebugLine( WorldStart, WorldEnd, LineColor );
		DrawProxy->AnimDrawDebugSphere( WorldEnd, SphereRadius, 10, LineColor );
        //DrawProxy->AnimDrawDebugCoordinateSystem(WorldEnd, BoneTM.Rotator(), SphereRadius * 4.0f, false, -1.f, 0.15f);
#endif
	}
}
//#endif // #if OPTITRACK_SKELNODE_DEBUGDRAW
