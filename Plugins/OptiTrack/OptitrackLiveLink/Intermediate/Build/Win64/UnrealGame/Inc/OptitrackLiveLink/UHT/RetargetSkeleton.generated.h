// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RetargetSkeleton.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OPTITRACKLIVELINK_RetargetSkeleton_generated_h
#error "RetargetSkeleton.generated.h already included, missing '#pragma once' in RetargetSkeleton.h"
#endif
#define OPTITRACKLIVELINK_RetargetSkeleton_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h


#define FOREACH_ENUM_OPTITRACKBONEID(op) \
	op(OptiTrackBoneID::Root) \
	op(OptiTrackBoneID::Hips) \
	op(OptiTrackBoneID::Spine) \
	op(OptiTrackBoneID::Spine1) \
	op(OptiTrackBoneID::Neck) \
	op(OptiTrackBoneID::Head) \
	op(OptiTrackBoneID::LeftShoulder) \
	op(OptiTrackBoneID::LeftArm) \
	op(OptiTrackBoneID::LeftForeArm) \
	op(OptiTrackBoneID::LeftHand) \
	op(OptiTrackBoneID::RightShoulder) \
	op(OptiTrackBoneID::RightArm) \
	op(OptiTrackBoneID::RightForeArm) \
	op(OptiTrackBoneID::RightHand) \
	op(OptiTrackBoneID::LeftUpLeg) \
	op(OptiTrackBoneID::LeftLeg) \
	op(OptiTrackBoneID::LeftFoot) \
	op(OptiTrackBoneID::LeftToeBase) \
	op(OptiTrackBoneID::RightUpLeg) \
	op(OptiTrackBoneID::RightLeg) \
	op(OptiTrackBoneID::RightFoot) \
	op(OptiTrackBoneID::RightToeBase) \
	op(OptiTrackBoneID::LeftHandThumb1) \
	op(OptiTrackBoneID::LeftHandThumb2) \
	op(OptiTrackBoneID::LeftHandThumb3) \
	op(OptiTrackBoneID::LeftHandIndex1) \
	op(OptiTrackBoneID::LeftHandIndex2) \
	op(OptiTrackBoneID::LeftHandIndex3) \
	op(OptiTrackBoneID::LeftHandMiddle1) \
	op(OptiTrackBoneID::LeftHandMiddle2) \
	op(OptiTrackBoneID::LeftHandMiddle3) \
	op(OptiTrackBoneID::LeftHandRing1) \
	op(OptiTrackBoneID::LeftHandRing2) \
	op(OptiTrackBoneID::LeftHandRing3) \
	op(OptiTrackBoneID::LeftHandPinky1) \
	op(OptiTrackBoneID::LeftHandPinky2) \
	op(OptiTrackBoneID::LeftHandPinky3) \
	op(OptiTrackBoneID::RightHandThumb1) \
	op(OptiTrackBoneID::RightHandThumb2) \
	op(OptiTrackBoneID::RightHandThumb3) \
	op(OptiTrackBoneID::RightHandIndex1) \
	op(OptiTrackBoneID::RightHandIndex2) \
	op(OptiTrackBoneID::RightHandIndex3) \
	op(OptiTrackBoneID::RightHandMiddle1) \
	op(OptiTrackBoneID::RightHandMiddle2) \
	op(OptiTrackBoneID::RightHandMiddle3) \
	op(OptiTrackBoneID::RightHandRing1) \
	op(OptiTrackBoneID::RightHandRing2) \
	op(OptiTrackBoneID::RightHandRing3) \
	op(OptiTrackBoneID::RightHandPinky1) \
	op(OptiTrackBoneID::RightHandPinky2) \
	op(OptiTrackBoneID::RightHandPinky3) \
	op(OptiTrackBoneID::NumBones) \
	op(OptiTrackBoneID::UndefinedBone) 

enum class OptiTrackBoneID : uint8;
template<> struct TIsUEnumClass<OptiTrackBoneID> { enum { Value = true }; };
template<> OPTITRACKLIVELINK_API UEnum* StaticEnum<OptiTrackBoneID>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
