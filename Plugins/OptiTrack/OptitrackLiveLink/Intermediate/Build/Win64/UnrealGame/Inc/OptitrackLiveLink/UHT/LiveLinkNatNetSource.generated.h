// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LiveLinkNatNetSource.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OPTITRACKLIVELINK_LiveLinkNatNetSource_generated_h
#error "LiveLinkNatNetSource.generated.h already included, missing '#pragma once' in LiveLinkNatNetSource.h"
#endif
#define OPTITRACKLIVELINK_LiveLinkNatNetSource_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSource_h


#define FOREACH_ENUM_EOPTITRACKLIVELINKBONENAMINGCONVENTION(op) \
	op(EOptitrackLiveLinkBoneNamingConvention::Motive) \
	op(EOptitrackLiveLinkBoneNamingConvention::FBX) \
	op(EOptitrackLiveLinkBoneNamingConvention::BVH) 

enum class EOptitrackLiveLinkBoneNamingConvention : uint8;
template<> struct TIsUEnumClass<EOptitrackLiveLinkBoneNamingConvention> { enum { Value = true }; };
template<> OPTITRACKLIVELINK_API UEnum* StaticEnum<EOptitrackLiveLinkBoneNamingConvention>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
