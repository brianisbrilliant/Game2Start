// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OptitrackSkeletonComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OPTITRACKNATNET_OptitrackSkeletonComponent_generated_h
#error "OptitrackSkeletonComponent.generated.h already included, missing '#pragma once' in OptitrackSkeletonComponent.h"
#endif
#define OPTITRACKNATNET_OptitrackSkeletonComponent_generated_h

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_SPARSE_DATA
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOptitrackSkeletonComponent(); \
	friend struct Z_Construct_UClass_UOptitrackSkeletonComponent_Statics; \
public: \
	DECLARE_CLASS(UOptitrackSkeletonComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OptitrackNatnet"), NO_API) \
	DECLARE_SERIALIZER(UOptitrackSkeletonComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SourceSkeletonAssetName=NETFIELD_REP_START, \
		NETFIELD_REP_END=SourceSkeletonAssetName	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOptitrackSkeletonComponent(UOptitrackSkeletonComponent&&); \
	NO_API UOptitrackSkeletonComponent(const UOptitrackSkeletonComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOptitrackSkeletonComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOptitrackSkeletonComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOptitrackSkeletonComponent) \
	NO_API virtual ~UOptitrackSkeletonComponent();


#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_15_PROLOG
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_SPARSE_DATA \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OPTITRACKNATNET_API UClass* StaticClass<class UOptitrackSkeletonComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
