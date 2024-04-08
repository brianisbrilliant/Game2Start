// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OptitrackSkeletonTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OPTITRACKNATNET_OptitrackSkeletonTypes_generated_h
#error "OptitrackSkeletonTypes.generated.h already included, missing '#pragma once' in OptitrackSkeletonTypes.h"
#endif
#define OPTITRACKNATNET_OptitrackSkeletonTypes_generated_h

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_11_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackPose_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackPose>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_84_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackBoneDefinition>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_103_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackSkeletonDefinition>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_120_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackSkeletonState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h


#define FOREACH_ENUM_EOPTITRACKBONENAMINGCONVENTION(op) \
	op(EOptitrackBoneNamingConvention::Motive) \
	op(EOptitrackBoneNamingConvention::FBX) \
	op(EOptitrackBoneNamingConvention::BVH) 

enum class EOptitrackBoneNamingConvention : uint8;
template<> struct TIsUEnumClass<EOptitrackBoneNamingConvention> { enum { Value = true }; };
template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackBoneNamingConvention>();

#define FOREACH_ENUM_EOPTITRACKBONE(op) \
	op(EOptitrackBone::Root) \
	op(EOptitrackBone::Hip) \
	op(EOptitrackBone::Ab) \
	op(EOptitrackBone::Chest) \
	op(EOptitrackBone::Neck) \
	op(EOptitrackBone::Head) \
	op(EOptitrackBone::LShoulder) \
	op(EOptitrackBone::LUArm) \
	op(EOptitrackBone::LFArm) \
	op(EOptitrackBone::LHand) \
	op(EOptitrackBone::RShoulder) \
	op(EOptitrackBone::RUArm) \
	op(EOptitrackBone::RFArm) \
	op(EOptitrackBone::RHand) \
	op(EOptitrackBone::LThigh) \
	op(EOptitrackBone::LShin) \
	op(EOptitrackBone::LFoot) \
	op(EOptitrackBone::LToe) \
	op(EOptitrackBone::RThigh) \
	op(EOptitrackBone::RShin) \
	op(EOptitrackBone::RFoot) \
	op(EOptitrackBone::RToe) \
	op(EOptitrackBone::LThumb1) \
	op(EOptitrackBone::LThumb2) \
	op(EOptitrackBone::LThumb3) \
	op(EOptitrackBone::LIndex1) \
	op(EOptitrackBone::LIndex2) \
	op(EOptitrackBone::LIndex3) \
	op(EOptitrackBone::LMiddle1) \
	op(EOptitrackBone::LMiddle2) \
	op(EOptitrackBone::LMiddle3) \
	op(EOptitrackBone::LRing1) \
	op(EOptitrackBone::LRing2) \
	op(EOptitrackBone::LRing3) \
	op(EOptitrackBone::LPinky1) \
	op(EOptitrackBone::LPinky2) \
	op(EOptitrackBone::LPinky3) \
	op(EOptitrackBone::RThumb1) \
	op(EOptitrackBone::RThumb2) \
	op(EOptitrackBone::RThumb3) \
	op(EOptitrackBone::RIndex1) \
	op(EOptitrackBone::RIndex2) \
	op(EOptitrackBone::RIndex3) \
	op(EOptitrackBone::RMiddle1) \
	op(EOptitrackBone::RMiddle2) \
	op(EOptitrackBone::RMiddle3) \
	op(EOptitrackBone::RRing1) \
	op(EOptitrackBone::RRing2) \
	op(EOptitrackBone::RRing3) \
	op(EOptitrackBone::RPinky1) \
	op(EOptitrackBone::RPinky2) \
	op(EOptitrackBone::RPinky3) \
	op(EOptitrackBone::NumBones) 

enum class EOptitrackBone : uint8;
template<> struct TIsUEnumClass<EOptitrackBone> { enum { Value = true }; };
template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackBone>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
