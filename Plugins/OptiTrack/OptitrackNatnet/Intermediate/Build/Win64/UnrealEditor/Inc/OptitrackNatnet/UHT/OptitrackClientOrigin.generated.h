// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OptitrackClientOrigin.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AOptitrackClientOrigin;
class UWorld;
enum class EOptitrackTimestampType : uint8;
struct FOptitrackMarkerState;
struct FOptitrackRigidBodyState;
struct FOptitrackSkeletonDefinition;
struct FOptitrackSkeletonState;
struct FTimecode;
#ifdef OPTITRACKNATNET_OptitrackClientOrigin_generated_h
#error "OptitrackClientOrigin.generated.h already included, missing '#pragma once' in OptitrackClientOrigin.h"
#endif
#define OPTITRACKNATNET_OptitrackClientOrigin_generated_h

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_45_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackRigidBodyState>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_71_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackMarkerState>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_97_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOptitrackCamera_Statics; \
	OPTITRACKNATNET_API static class UScriptStruct* StaticStruct();


template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<struct FOptitrackCamera>();

#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_SPARSE_DATA
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execShutdownClient); \
	DECLARE_FUNCTION(execGetDataDescription); \
	DECLARE_FUNCTION(execInitializeClient); \
	DECLARE_FUNCTION(execIsClientConnected); \
	DECLARE_FUNCTION(execIsClientInitialized); \
	DECLARE_FUNCTION(execFindHmdClientOrigin); \
	DECLARE_FUNCTION(execFindDefaultClientOrigin); \
	DECLARE_FUNCTION(execGetLatestTimecode); \
	DECLARE_FUNCTION(execGetTimestampType); \
	DECLARE_FUNCTION(execGetLatestMarkerStateUntransformed); \
	DECLARE_FUNCTION(execGetLatestRigidBodyStateUntransformed); \
	DECLARE_FUNCTION(execFindSkeletonDefinition); \
	DECLARE_FUNCTION(execGetLatestSkeletonStateByName); \
	DECLARE_FUNCTION(execGetLatestSkeletonState); \
	DECLARE_FUNCTION(execGetLatestMarkerState); \
	DECLARE_FUNCTION(execGetLatestRigidBodyState);


#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_ACCESSORS
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_INCLASS \
private: \
	static void StaticRegisterNativesAOptitrackClientOrigin(); \
	friend struct Z_Construct_UClass_AOptitrackClientOrigin_Statics; \
public: \
	DECLARE_CLASS(AOptitrackClientOrigin, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OptitrackNatnet"), NO_API) \
	DECLARE_SERIALIZER(AOptitrackClientOrigin)


#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOptitrackClientOrigin(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOptitrackClientOrigin) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOptitrackClientOrigin); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOptitrackClientOrigin); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOptitrackClientOrigin(AOptitrackClientOrigin&&); \
	NO_API AOptitrackClientOrigin(const AOptitrackClientOrigin&); \
public: \
	NO_API virtual ~AOptitrackClientOrigin();


#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_129_PROLOG
#define FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_SPARSE_DATA \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_RPC_WRAPPERS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_ACCESSORS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_INCLASS \
	FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_132_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OPTITRACKNATNET_API UClass* StaticClass<class AOptitrackClientOrigin>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h


#define FOREACH_ENUM_EOPTITRACKTIMESTAMPTYPE(op) \
	op(EOptitrackTimestampType::Unknown) \
	op(EOptitrackTimestampType::LocalArrivalTime) \
	op(EOptitrackTimestampType::ServerAggregationTime) \
	op(EOptitrackTimestampType::ServerExposureTime) 

enum class EOptitrackTimestampType : uint8;
template<> struct TIsUEnumClass<EOptitrackTimestampType> { enum { Value = true }; };
template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackTimestampType>();

#define FOREACH_ENUM_EOPTITRACKCLIENTCONNECTIONTYPE(op) \
	op(EOptitrackClientConnectionType::Multicast) \
	op(EOptitrackClientConnectionType::Unicast) 

enum class EOptitrackClientConnectionType : uint8;
template<> struct TIsUEnumClass<EOptitrackClientConnectionType> { enum { Value = true }; };
template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackClientConnectionType>();

#define FOREACH_ENUM_EOPTITRACKFORWARDAXISTYPE(op) \
	op(EOptitrackForwardAxisType::Z_Positive) \
	op(EOptitrackForwardAxisType::X_Positive) 

enum class EOptitrackForwardAxisType : uint8;
template<> struct TIsUEnumClass<EOptitrackForwardAxisType> { enum { Value = true }; };
template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackForwardAxisType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
