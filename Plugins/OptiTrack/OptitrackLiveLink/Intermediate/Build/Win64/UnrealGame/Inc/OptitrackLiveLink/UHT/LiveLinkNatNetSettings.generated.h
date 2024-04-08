// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LiveLinkNatNetSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OPTITRACKLIVELINK_LiveLinkNatNetSettings_generated_h
#error "LiveLinkNatNetSettings.generated.h already included, missing '#pragma once' in LiveLinkNatNetSettings.h"
#endif
#define OPTITRACKLIVELINK_LiveLinkNatNetSettings_generated_h

#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_SPARSE_DATA
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_ACCESSORS
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOptitrackLiveLinkSourceSettings(); \
	friend struct Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics; \
public: \
	DECLARE_CLASS(UOptitrackLiveLinkSourceSettings, ULiveLinkSourceSettings, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OptitrackLiveLink"), NO_API) \
	DECLARE_SERIALIZER(UOptitrackLiveLinkSourceSettings)


#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOptitrackLiveLinkSourceSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOptitrackLiveLinkSourceSettings(UOptitrackLiveLinkSourceSettings&&); \
	NO_API UOptitrackLiveLinkSourceSettings(const UOptitrackLiveLinkSourceSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOptitrackLiveLinkSourceSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOptitrackLiveLinkSourceSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOptitrackLiveLinkSourceSettings) \
	NO_API virtual ~UOptitrackLiveLinkSourceSettings();


#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_38_PROLOG
#define FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_SPARSE_DATA \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_ACCESSORS \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_INCLASS_NO_PURE_DECLS \
	FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_42_ENHANCED_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OPTITRACKLIVELINK_API UClass* StaticClass<class UOptitrackLiveLinkSourceSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h


#define FOREACH_ENUM_EOPTITRACKLIVELINKCONNECTIONTYPE(op) \
	op(EOptitrackLiveLinkConnectionType::Multicast) \
	op(EOptitrackLiveLinkConnectionType::Unicast) 

enum class EOptitrackLiveLinkConnectionType : uint8;
template<> struct TIsUEnumClass<EOptitrackLiveLinkConnectionType> { enum { Value = true }; };
template<> OPTITRACKLIVELINK_API UEnum* StaticEnum<EOptitrackLiveLinkConnectionType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
