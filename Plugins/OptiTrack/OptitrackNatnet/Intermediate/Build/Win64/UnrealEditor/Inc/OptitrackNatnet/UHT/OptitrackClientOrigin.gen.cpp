// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackClientOrigin.h"
#include "OptitrackNatnet/Public/OptitrackSkeletonTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackClientOrigin() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTimecode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackCamera();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackMarkerState();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackRigidBodyState();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonState();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackTimestampType;
	static UEnum* EOptitrackTimestampType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackTimestampType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackTimestampType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("EOptitrackTimestampType"));
		}
		return Z_Registration_Info_UEnum_EOptitrackTimestampType.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackTimestampType>()
	{
		return EOptitrackTimestampType_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enumerators[] = {
		{ "EOptitrackTimestampType::Unknown", (int64)EOptitrackTimestampType::Unknown },
		{ "EOptitrackTimestampType::LocalArrivalTime", (int64)EOptitrackTimestampType::LocalArrivalTime },
		{ "EOptitrackTimestampType::ServerAggregationTime", (int64)EOptitrackTimestampType::ServerAggregationTime },
		{ "EOptitrackTimestampType::ServerExposureTime", (int64)EOptitrackTimestampType::ServerExposureTime },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "LocalArrivalTime.Comment", "/** When the NatNet frame callback occurred. Fallback when precise metrics are unavailable. */" },
		{ "LocalArrivalTime.Name", "EOptitrackTimestampType::LocalArrivalTime" },
		{ "LocalArrivalTime.ToolTip", "When the NatNet frame callback occurred. Fallback when precise metrics are unavailable." },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ServerAggregationTime.Comment", "/** Clock synchronized estimate of when the camera data became available on the server. */" },
		{ "ServerAggregationTime.Name", "EOptitrackTimestampType::ServerAggregationTime" },
		{ "ServerAggregationTime.ToolTip", "Clock synchronized estimate of when the camera data became available on the server." },
		{ "ServerExposureTime.Comment", "/** Clock synchronized estimate of when the camera exposure occurred. */" },
		{ "ServerExposureTime.Name", "EOptitrackTimestampType::ServerExposureTime" },
		{ "ServerExposureTime.ToolTip", "Clock synchronized estimate of when the camera exposure occurred." },
		{ "Unknown.Comment", "/** We don't know what the server supports until after we've received at least one frame. */" },
		{ "Unknown.Name", "EOptitrackTimestampType::Unknown" },
		{ "Unknown.ToolTip", "We don't know what the server supports until after we've received at least one frame." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		"EOptitrackTimestampType",
		"EOptitrackTimestampType",
		Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackTimestampType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackTimestampType.InnerSingleton, Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackTimestampType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState;
class UScriptStruct* FOptitrackRigidBodyState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackRigidBodyState, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackRigidBodyState"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackRigidBodyState>()
{
	return FOptitrackRigidBodyState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimestampPlatformSeconds_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_TimestampPlatformSeconds;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n* Represents a pose for a tracked rigid body.\n*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Represents a pose for a tracked rigid body." },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackRigidBodyState>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_TimestampPlatformSeconds_MetaData[] = {
		{ "Comment", "/**\n\x09 * Timestamp corresponding to this rigid body pose. Exact semantics can vary depending on\n\x09 * server support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.\n\x09 *\n\x09 * Can be directly compared with values returned by FPlatformTime::Seconds().\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Timestamp corresponding to this rigid body pose. Exact semantics can vary depending on\nserver support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.\n\nCan be directly compared with values returned by FPlatformTime::Seconds()." },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_TimestampPlatformSeconds = { "TimestampPlatformSeconds", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackRigidBodyState, TimestampPlatformSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_TimestampPlatformSeconds_MetaData), Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_TimestampPlatformSeconds_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Position in tracking space. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Position in tracking space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackRigidBodyState, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Orientation_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Orientation in tracking space. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Orientation in tracking space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackRigidBodyState, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Orientation_MetaData), Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Orientation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_TimestampPlatformSeconds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewProp_Orientation,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackRigidBodyState",
		Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::PropPointers),
		sizeof(FOptitrackRigidBodyState),
		alignof(FOptitrackRigidBodyState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackRigidBodyState()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackMarkerState;
class UScriptStruct* FOptitrackMarkerState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackMarkerState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackMarkerState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackMarkerState, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackMarkerState"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackMarkerState.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackMarkerState>()
{
	return FOptitrackMarkerState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimestampPlatformSeconds_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_TimestampPlatformSeconds;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** \n* Represents a tracked marker.\n*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Represents a tracked marker." },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackMarkerState>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_TimestampPlatformSeconds_MetaData[] = {
		{ "Comment", "/**\n    * Timestamp corresponding to this marker. Exact semantics can vary depending on\n    * server support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.\n    *\n    * Can be directly compared with values returned by FPlatformTime::Seconds().\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Timestamp corresponding to this marker. Exact semantics can vary depending on\nserver support; see EOptitrackTimestampType and AOptitrackClientOrigin::GetTimestampType.\n\nCan be directly compared with values returned by FPlatformTime::Seconds()." },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_TimestampPlatformSeconds = { "TimestampPlatformSeconds", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackMarkerState, TimestampPlatformSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_TimestampPlatformSeconds_MetaData), Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_TimestampPlatformSeconds_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Position in tracking space. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Position in tracking space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackMarkerState, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Id_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Marker Id in Motive. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Marker Id in Motive." },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackMarkerState, Id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Id_MetaData), Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_TimestampPlatformSeconds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewProp_Id,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackMarkerState",
		Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::PropPointers),
		sizeof(FOptitrackMarkerState),
		alignof(FOptitrackMarkerState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackMarkerState()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackMarkerState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackMarkerState.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackMarkerState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackCamera;
class UScriptStruct* FOptitrackCamera::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackCamera.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackCamera.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackCamera, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackCamera"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackCamera.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackCamera>()
{
	return FOptitrackCamera::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackCamera_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackCamera_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n* Represents a camera object.\n*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Represents a camera object." },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackCamera>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Position in tracking space. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Position in tracking space." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackCamera, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Position in tracking space. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Position in tracking space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackCamera, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Orientation_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Marker Id in Motive. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Marker Id in Motive." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackCamera, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Orientation_MetaData), Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Orientation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewProp_Orientation,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackCamera_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackCamera",
		Z_Construct_UScriptStruct_FOptitrackCamera_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::PropPointers),
		sizeof(FOptitrackCamera),
		alignof(FOptitrackCamera),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackCamera_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackCamera_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackCamera()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackCamera.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackCamera.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackCamera_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackCamera.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackClientConnectionType;
	static UEnum* EOptitrackClientConnectionType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackClientConnectionType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackClientConnectionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("EOptitrackClientConnectionType"));
		}
		return Z_Registration_Info_UEnum_EOptitrackClientConnectionType.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackClientConnectionType>()
	{
		return EOptitrackClientConnectionType_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enumerators[] = {
		{ "EOptitrackClientConnectionType::Multicast", (int64)EOptitrackClientConnectionType::Multicast },
		{ "EOptitrackClientConnectionType::Unicast", (int64)EOptitrackClientConnectionType::Unicast },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "Multicast.DisplayName", "Multicast" },
		{ "Multicast.Name", "EOptitrackClientConnectionType::Multicast" },
		{ "Unicast.DisplayName", "Unicast" },
		{ "Unicast.Name", "EOptitrackClientConnectionType::Unicast" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		"EOptitrackClientConnectionType",
		"EOptitrackClientConnectionType",
		Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackClientConnectionType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackClientConnectionType.InnerSingleton, Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackClientConnectionType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackForwardAxisType;
	static UEnum* EOptitrackForwardAxisType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackForwardAxisType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackForwardAxisType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("EOptitrackForwardAxisType"));
		}
		return Z_Registration_Info_UEnum_EOptitrackForwardAxisType.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackForwardAxisType>()
	{
		return EOptitrackForwardAxisType_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enumerators[] = {
		{ "EOptitrackForwardAxisType::Z_Positive", (int64)EOptitrackForwardAxisType::Z_Positive },
		{ "EOptitrackForwardAxisType::X_Positive", (int64)EOptitrackForwardAxisType::X_Positive },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "X_Positive.DisplayName", "+X Forward" },
		{ "X_Positive.Name", "EOptitrackForwardAxisType::X_Positive" },
		{ "Z_Positive.DisplayName", "+Z Forward" },
		{ "Z_Positive.Name", "EOptitrackForwardAxisType::Z_Positive" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		"EOptitrackForwardAxisType",
		"EOptitrackForwardAxisType",
		Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackForwardAxisType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackForwardAxisType.InnerSingleton, Z_Construct_UEnum_OptitrackNatnet_EOptitrackForwardAxisType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackForwardAxisType.InnerSingleton;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execShutdownClient)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ShutdownClient();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetDataDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetDataDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execInitializeClient)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->InitializeClient();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execIsClientConnected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsClientConnected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execIsClientInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsClientInitialized();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execFindHmdClientOrigin)
	{
		P_GET_OBJECT(UWorld,Z_Param_World);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOptitrackClientOrigin**)Z_Param__Result=AOptitrackClientOrigin::FindHmdClientOrigin(Z_Param_World);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execFindDefaultClientOrigin)
	{
		P_GET_OBJECT(UWorld,Z_Param_World);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOptitrackClientOrigin**)Z_Param__Result=AOptitrackClientOrigin::FindDefaultClientOrigin(Z_Param_World);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestTimecode)
	{
		P_GET_STRUCT_REF(FTimecode,Z_Param_Out_OutTimecode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestTimecode(Z_Param_Out_OutTimecode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetTimestampType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EOptitrackTimestampType*)Z_Param__Result=P_THIS->GetTimestampType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestMarkerStateUntransformed)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_markerId);
		P_GET_STRUCT_REF(FOptitrackMarkerState,Z_Param_Out_OutMarkerState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestMarkerStateUntransformed(Z_Param_markerId,Z_Param_Out_OutMarkerState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestRigidBodyStateUntransformed)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_RbId);
		P_GET_STRUCT_REF(FOptitrackRigidBodyState,Z_Param_Out_OutRbStat);
		P_GET_UBOOL(Z_Param_networkCompensation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestRigidBodyStateUntransformed(Z_Param_RbId,Z_Param_Out_OutRbStat,Z_Param_networkCompensation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execFindSkeletonDefinition)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_SkeletonName);
		P_GET_STRUCT_REF(FOptitrackSkeletonDefinition,Z_Param_Out_OutSkelDef);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->FindSkeletonDefinition(Z_Param_Out_SkeletonName,Z_Param_Out_OutSkelDef);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestSkeletonStateByName)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_SkelName);
		P_GET_STRUCT_REF(FOptitrackSkeletonState,Z_Param_Out_OutSkelState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestSkeletonStateByName(Z_Param_Out_SkelName,Z_Param_Out_OutSkelState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestSkeletonState)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SkelId);
		P_GET_STRUCT_REF(FOptitrackSkeletonState,Z_Param_Out_OutSkelState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestSkeletonState(Z_Param_SkelId,Z_Param_Out_OutSkelState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestMarkerState)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_markerId);
		P_GET_STRUCT_REF(FOptitrackMarkerState,Z_Param_Out_OutMarkerState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestMarkerState(Z_Param_markerId,Z_Param_Out_OutMarkerState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOptitrackClientOrigin::execGetLatestRigidBodyState)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_RbId);
		P_GET_STRUCT_REF(FOptitrackRigidBodyState,Z_Param_Out_OutRbState);
		P_GET_UBOOL(Z_Param_networkCompensation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLatestRigidBodyState(Z_Param_RbId,Z_Param_Out_OutRbState,Z_Param_networkCompensation);
		P_NATIVE_END;
	}
	void AOptitrackClientOrigin::StaticRegisterNativesAOptitrackClientOrigin()
	{
		UClass* Class = AOptitrackClientOrigin::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindDefaultClientOrigin", &AOptitrackClientOrigin::execFindDefaultClientOrigin },
			{ "FindHmdClientOrigin", &AOptitrackClientOrigin::execFindHmdClientOrigin },
			{ "FindSkeletonDefinition", &AOptitrackClientOrigin::execFindSkeletonDefinition },
			{ "GetDataDescription", &AOptitrackClientOrigin::execGetDataDescription },
			{ "GetLatestMarkerState", &AOptitrackClientOrigin::execGetLatestMarkerState },
			{ "GetLatestMarkerStateUntransformed", &AOptitrackClientOrigin::execGetLatestMarkerStateUntransformed },
			{ "GetLatestRigidBodyState", &AOptitrackClientOrigin::execGetLatestRigidBodyState },
			{ "GetLatestRigidBodyStateUntransformed", &AOptitrackClientOrigin::execGetLatestRigidBodyStateUntransformed },
			{ "GetLatestSkeletonState", &AOptitrackClientOrigin::execGetLatestSkeletonState },
			{ "GetLatestSkeletonStateByName", &AOptitrackClientOrigin::execGetLatestSkeletonStateByName },
			{ "GetLatestTimecode", &AOptitrackClientOrigin::execGetLatestTimecode },
			{ "GetTimestampType", &AOptitrackClientOrigin::execGetTimestampType },
			{ "InitializeClient", &AOptitrackClientOrigin::execInitializeClient },
			{ "IsClientConnected", &AOptitrackClientOrigin::execIsClientConnected },
			{ "IsClientInitialized", &AOptitrackClientOrigin::execIsClientInitialized },
			{ "ShutdownClient", &AOptitrackClientOrigin::execShutdownClient },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics
	{
		struct OptitrackClientOrigin_eventFindDefaultClientOrigin_Parms
		{
			UWorld* World;
			AOptitrackClientOrigin* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindDefaultClientOrigin_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindDefaultClientOrigin_Parms, ReturnValue), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::NewProp_World,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Helper for the common case where only a single client origin is present.\n\x09 * Used to provide a default for any UOptitrackRigidBody components which\n\x09 * don't otherwise specify a particular origin to use.\n\x09 * Note: This is potentially expensive and the result should be cached.\n\x09 * @return The first AOptitrackClientOrigin actor found in @World.\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Helper for the common case where only a single client origin is present.\nUsed to provide a default for any UOptitrackRigidBody components which\ndon't otherwise specify a particular origin to use.\nNote: This is potentially expensive and the result should be cached.\n@return The first AOptitrackClientOrigin actor found in @World." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "FindDefaultClientOrigin", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::OptitrackClientOrigin_eventFindDefaultClientOrigin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::OptitrackClientOrigin_eventFindDefaultClientOrigin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics
	{
		struct OptitrackClientOrigin_eventFindHmdClientOrigin_Parms
		{
			UWorld* World;
			AOptitrackClientOrigin* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindHmdClientOrigin_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindHmdClientOrigin_Parms, ReturnValue), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::NewProp_World,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Finds the first AOptitrackClientOrigin specifying an HMD rigid body ID.\n\x09 * Note: This is potentially expensive and the result should be cached.\n\x09 * @return The first suitable AOptitrackClientOrigin actor found in @World.\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Finds the first AOptitrackClientOrigin specifying an HMD rigid body ID.\nNote: This is potentially expensive and the result should be cached.\n@return The first suitable AOptitrackClientOrigin actor found in @World." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "FindHmdClientOrigin", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::OptitrackClientOrigin_eventFindHmdClientOrigin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::OptitrackClientOrigin_eventFindHmdClientOrigin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics
	{
		struct OptitrackClientOrigin_eventFindSkeletonDefinition_Parms
		{
			FName SkeletonName;
			FOptitrackSkeletonDefinition OutSkelDef;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletonName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SkeletonName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutSkelDef;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_SkeletonName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_SkeletonName = { "SkeletonName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindSkeletonDefinition_Parms, SkeletonName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_SkeletonName_MetaData), Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_SkeletonName_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_OutSkelDef = { "OutSkelDef", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventFindSkeletonDefinition_Parms, OutSkelDef), Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition, METADATA_PARAMS(0, nullptr) }; // 1304275298
	void Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventFindSkeletonDefinition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventFindSkeletonDefinition_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_SkeletonName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_OutSkelDef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack|Advanced" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "FindSkeletonDefinition", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::OptitrackClientOrigin_eventFindSkeletonDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::OptitrackClientOrigin_eventFindSkeletonDefinition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics
	{
		struct OptitrackClientOrigin_eventGetDataDescription_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetDataDescription_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetDataDescription_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n    * Request NatNet data description from server.\n    * Invalid to call if @IsClientInitialized() returns false.\n    * @return True on success, false on failure.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Request NatNet data description from server.\nInvalid to call if @IsClientInitialized() returns false.\n@return True on success, false on failure." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetDataDescription", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::OptitrackClientOrigin_eventGetDataDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::OptitrackClientOrigin_eventGetDataDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestMarkerState_Parms
		{
			int32 markerId;
			FOptitrackMarkerState OutMarkerState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_markerId;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutMarkerState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_markerId = { "markerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestMarkerState_Parms, markerId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_OutMarkerState = { "OutMarkerState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestMarkerState_Parms, OutMarkerState), Z_Construct_UScriptStruct_FOptitrackMarkerState, METADATA_PARAMS(0, nullptr) }; // 4159873427
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestMarkerState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestMarkerState_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_markerId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_OutMarkerState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n    * Retrieves latest available FOptitrackMarkerState for the marker identified by the\n    * @markerId parameter. Note that this data can be stale/non-existent if the marker\n    * hasn't streamed any new data recently.\n    *\n    * The tracking space pose is transformed by the offset/rotation/scale of this actor,\n    * such that the placement of this actor corresponds to the tracking space origin.\n    *\n    * @param OutMarkerState Receives latest available marker state (if any).\n    * @return True if any marker state was available for the specified ID,\n    *         otherwise false.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Retrieves latest available FOptitrackMarkerState for the marker identified by the\n@markerId parameter. Note that this data can be stale/non-existent if the marker\nhasn't streamed any new data recently.\n\nThe tracking space pose is transformed by the offset/rotation/scale of this actor,\nsuch that the placement of this actor corresponds to the tracking space origin.\n\n@param OutMarkerState Receives latest available marker state (if any).\n@return True if any marker state was available for the specified ID,\n        otherwise false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestMarkerState", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::OptitrackClientOrigin_eventGetLatestMarkerState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::OptitrackClientOrigin_eventGetLatestMarkerState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms
		{
			int32 markerId;
			FOptitrackMarkerState OutMarkerState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_markerId;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutMarkerState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_markerId = { "markerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms, markerId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_OutMarkerState = { "OutMarkerState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms, OutMarkerState), Z_Construct_UScriptStruct_FOptitrackMarkerState, METADATA_PARAMS(0, nullptr) }; // 4159873427
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_markerId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_OutMarkerState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack|Advanced" },
		{ "Comment", "/**\n    * Retrieves latest available FOptitrackMarkerState for the marker identified by the\n    * @markerId parameter. Note that this data can be stale/non-existent if the marker\n    * hasn't streamed any new data recently.\n    *\n    * This \"Untransformed\" version returns the tracking space pose, applying only the global\n    * WorldToMeters scale. It does not take into account the transform of this actor.\n    *\n    * @param OutMarkerState Receives latest available marker state (if any).\n    * @return True if any marker state was available for the specified ID,\n    *         otherwise false.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Retrieves latest available FOptitrackMarkerState for the marker identified by the\n@markerId parameter. Note that this data can be stale/non-existent if the marker\nhasn't streamed any new data recently.\n\nThis \"Untransformed\" version returns the tracking space pose, applying only the global\nWorldToMeters scale. It does not take into account the transform of this actor.\n\n@param OutMarkerState Receives latest available marker state (if any).\n@return True if any marker state was available for the specified ID,\n        otherwise false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestMarkerStateUntransformed", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::OptitrackClientOrigin_eventGetLatestMarkerStateUntransformed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms
		{
			int32 RbId;
			FOptitrackRigidBodyState OutRbState;
			bool networkCompensation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_RbId;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutRbState;
		static void NewProp_networkCompensation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_networkCompensation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_RbId = { "RbId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms, RbId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_OutRbState = { "OutRbState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms, OutRbState), Z_Construct_UScriptStruct_FOptitrackRigidBodyState, METADATA_PARAMS(0, nullptr) }; // 188295417
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_networkCompensation_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms*)Obj)->networkCompensation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_networkCompensation = { "networkCompensation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_networkCompensation_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_RbId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_OutRbState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_networkCompensation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the\n\x09 * @RbId parameter. Note that this data can be stale if the rigid body in question hasn't\n\x09 * streamed any new data recently.\n\x09 *\n\x09 * The tracking space pose is transformed by the offset/rotation/scale of this actor,\n\x09 * such that the placement of this actor corresponds to the tracking space origin.\n\x09 *\n\x09 * @param OutRbState Receives latest available rigid body state (if any).\n\x09 * @return True if any rigid body state was available for the specified ID,\n\x09 *         otherwise false.\n\x09 */" },
		{ "CPP_Default_networkCompensation", "false" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the\n@RbId parameter. Note that this data can be stale if the rigid body in question hasn't\nstreamed any new data recently.\n\nThe tracking space pose is transformed by the offset/rotation/scale of this actor,\nsuch that the placement of this actor corresponds to the tracking space origin.\n\n@param OutRbState Receives latest available rigid body state (if any).\n@return True if any rigid body state was available for the specified ID,\n        otherwise false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestRigidBodyState", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::OptitrackClientOrigin_eventGetLatestRigidBodyState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms
		{
			int32 RbId;
			FOptitrackRigidBodyState OutRbStat;
			bool networkCompensation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_RbId;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutRbStat;
		static void NewProp_networkCompensation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_networkCompensation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_RbId = { "RbId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms, RbId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_OutRbStat = { "OutRbStat", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms, OutRbStat), Z_Construct_UScriptStruct_FOptitrackRigidBodyState, METADATA_PARAMS(0, nullptr) }; // 188295417
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_networkCompensation_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms*)Obj)->networkCompensation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_networkCompensation = { "networkCompensation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_networkCompensation_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_RbId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_OutRbStat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_networkCompensation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack|Advanced" },
		{ "Comment", "/**\n\x09 * Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the\n\x09 * @RbId parameter. Note that this data can be stale if the rigid body in question hasn't\n\x09 * streamed any new data recently.\n\x09 *\n\x09 * This \"Untransformed\" version returns the tracking space pose, applying only the global\n\x09 * WorldToMeters scale. It does not take into account the transform of this actor.\n\x09 *\n\x09 * @param OutRbState Receives latest available rigid body state (if any).\n\x09 * @return True if any rigid body state was available for the specified ID,\n\x09 *         otherwise false.\n\x09 */" },
		{ "CPP_Default_networkCompensation", "false" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Retrieves latest available FOptitrackRigidBodyState for the rigid body identified by the\n@RbId parameter. Note that this data can be stale if the rigid body in question hasn't\nstreamed any new data recently.\n\nThis \"Untransformed\" version returns the tracking space pose, applying only the global\nWorldToMeters scale. It does not take into account the transform of this actor.\n\n@param OutRbState Receives latest available rigid body state (if any).\n@return True if any rigid body state was available for the specified ID,\n        otherwise false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestRigidBodyStateUntransformed", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::OptitrackClientOrigin_eventGetLatestRigidBodyStateUntransformed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestSkeletonState_Parms
		{
			int32 SkelId;
			FOptitrackSkeletonState OutSkelState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SkelId;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutSkelState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_SkelId = { "SkelId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestSkeletonState_Parms, SkelId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_OutSkelState = { "OutSkelState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestSkeletonState_Parms, OutSkelState), Z_Construct_UScriptStruct_FOptitrackSkeletonState, METADATA_PARAMS(0, nullptr) }; // 3316904843
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestSkeletonState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestSkeletonState_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_SkelId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_OutSkelState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack|Advanced" },
		{ "Comment", "/**\n    * TODO\n    *\n    * @param OutSkelState\n    * @return True if any skeleton state was available for the specified ID,\n    *         otherwise false.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "TODO\n\n@param OutSkelState\n@return True if any skeleton state was available for the specified ID,\n        otherwise false." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestSkeletonState", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::OptitrackClientOrigin_eventGetLatestSkeletonState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::OptitrackClientOrigin_eventGetLatestSkeletonState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics
	{
		struct OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms
		{
			FName SkelName;
			FOptitrackSkeletonState OutSkelState;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkelName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SkelName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutSkelState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_SkelName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_SkelName = { "SkelName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms, SkelName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_SkelName_MetaData), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_SkelName_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_OutSkelState = { "OutSkelState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms, OutSkelState), Z_Construct_UScriptStruct_FOptitrackSkeletonState, METADATA_PARAMS(0, nullptr) }; // 3316904843
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_SkelName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_OutSkelState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack|Advanced" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestSkeletonStateByName", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::OptitrackClientOrigin_eventGetLatestSkeletonStateByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics
	{
		struct FTimecode
		{
			int32 Hours;
			int32 Minutes;
			int32 Seconds;
			int32 Frames;
			bool bDropFrameFormat;
		};

		struct OptitrackClientOrigin_eventGetLatestTimecode_Parms
		{
			FTimecode OutTimecode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutTimecode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_OutTimecode = { "OutTimecode", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetLatestTimecode_Parms, OutTimecode), Z_Construct_UScriptStruct_FTimecode, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventGetLatestTimecode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventGetLatestTimecode_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_OutTimecode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetLatestTimecode", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::OptitrackClientOrigin_eventGetLatestTimecode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::OptitrackClientOrigin_eventGetLatestTimecode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics
	{
		struct OptitrackClientOrigin_eventGetTimestampType_Parms
		{
			EOptitrackTimestampType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OptitrackClientOrigin_eventGetTimestampType_Parms, ReturnValue), Z_Construct_UEnum_OptitrackNatnet_EOptitrackTimestampType, METADATA_PARAMS(0, nullptr) }; // 3117092262
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Describes the semantics of @FOptitrackRigidBodyState::TimestampPlatformSeconds values. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Describes the semantics of @FOptitrackRigidBodyState::TimestampPlatformSeconds values." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "GetTimestampType", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::OptitrackClientOrigin_eventGetTimestampType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::OptitrackClientOrigin_eventGetTimestampType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics
	{
		struct OptitrackClientOrigin_eventInitializeClient_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventInitializeClient_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventInitializeClient_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Attempt to initialize NatNet and connect to the server.\n\x09 * Invalid to call if @IsClientInitialized() returns true.\n\x09 * @return True on success, false on failure.\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Attempt to initialize NatNet and connect to the server.\nInvalid to call if @IsClientInitialized() returns true.\n@return True on success, false on failure." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "InitializeClient", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::OptitrackClientOrigin_eventInitializeClient_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::OptitrackClientOrigin_eventInitializeClient_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics
	{
		struct OptitrackClientOrigin_eventIsClientConnected_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventIsClientConnected_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventIsClientConnected_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n    * Returns true if the Client has successfully connected to Motive\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Returns true if the Client has successfully connected to Motive" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "IsClientConnected", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::OptitrackClientOrigin_eventIsClientConnected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::OptitrackClientOrigin_eventIsClientConnected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics
	{
		struct OptitrackClientOrigin_eventIsClientInitialized_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventIsClientInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventIsClientInitialized_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Returns true if the last call to InitializeClient succeeded,\n\x09 * and ShutdownClient has not been called subsequently.\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Returns true if the last call to InitializeClient succeeded,\nand ShutdownClient has not been called subsequently." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "IsClientInitialized", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::OptitrackClientOrigin_eventIsClientInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::OptitrackClientOrigin_eventIsClientInitialized_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics
	{
		struct OptitrackClientOrigin_eventShutdownClient_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OptitrackClientOrigin_eventShutdownClient_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OptitrackClientOrigin_eventShutdownClient_Parms), &Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::Function_MetaDataParams[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09 * Attempt to shut down any existing NatNet client.\n\x09 * Invalid to call if @IsClientInitialized() returns false.\n\x09 * @return True on success, false on failure.\n\x09 */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Attempt to shut down any existing NatNet client.\nInvalid to call if @IsClientInitialized() returns false.\n@return True on success, false on failure." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOptitrackClientOrigin, nullptr, "ShutdownClient", nullptr, nullptr, Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::OptitrackClientOrigin_eventShutdownClient_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::OptitrackClientOrigin_eventShutdownClient_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOptitrackClientOrigin);
	UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister()
	{
		return AOptitrackClientOrigin::StaticClass();
	}
	struct Z_Construct_UClass_AOptitrackClientOrigin_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoConnect_MetaData[];
#endif
		static void NewProp_bAutoConnect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoConnect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ServerAddress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClientAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ClientAddress;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ConnectionType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConnectionType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ConnectionType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BoneNamingConvention_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneNamingConvention_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneNamingConvention;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoInitialize_MetaData[];
#endif
		static void NewProp_bAutoInitialize_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoInitialize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseDataSubscription_MetaData[];
#endif
		static void NewProp_bUseDataSubscription_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDataSubscription;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebugSkeletons_MetaData[];
#endif
		static void NewProp_bDrawDebugSkeletons_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebugSkeletons;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawMarkers_MetaData[];
#endif
		static void NewProp_bDrawMarkers_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawMarkers;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DrawMarkersColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DrawMarkersColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebugCameras_MetaData[];
#endif
		static void NewProp_bDrawDebugCameras_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebugCameras;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOptitrackClientOrigin_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AOptitrackClientOrigin_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_FindDefaultClientOrigin, "FindDefaultClientOrigin" }, // 1552427908
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_FindHmdClientOrigin, "FindHmdClientOrigin" }, // 3398628231
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_FindSkeletonDefinition, "FindSkeletonDefinition" }, // 1872685415
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetDataDescription, "GetDataDescription" }, // 270361002
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerState, "GetLatestMarkerState" }, // 3042527865
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestMarkerStateUntransformed, "GetLatestMarkerStateUntransformed" }, // 236375465
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyState, "GetLatestRigidBodyState" }, // 1376988869
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestRigidBodyStateUntransformed, "GetLatestRigidBodyStateUntransformed" }, // 897887817
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonState, "GetLatestSkeletonState" }, // 1900808076
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestSkeletonStateByName, "GetLatestSkeletonStateByName" }, // 1614228025
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetLatestTimecode, "GetLatestTimecode" }, // 211840552
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_GetTimestampType, "GetTimestampType" }, // 1943791776
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_InitializeClient, "InitializeClient" }, // 2576790949
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_IsClientConnected, "IsClientConnected" }, // 981365852
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_IsClientInitialized, "IsClientInitialized" }, // 1932019585
		{ &Z_Construct_UFunction_AOptitrackClientOrigin_ShutdownClient, "ShutdownClient" }, // 1859249674
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n*\n*/" },
		{ "IncludePath", "OptitrackClientOrigin.h" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, the NatNet client will search for and connect to Motive automatically . */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true, the NatNet client will search for and connect to Motive automatically ." },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bAutoConnect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect = { "bAutoConnect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ServerAddress_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** The network address of the NatNet server to connect to. */" },
		{ "EditCondition", "!bAutoConnect" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "The network address of the NatNet server to connect to." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ServerAddress = { "ServerAddress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackClientOrigin, ServerAddress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ServerAddress_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ServerAddress_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ClientAddress_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** The address of the local network interface to use. */" },
		{ "EditCondition", "!bAutoConnect" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "The address of the local network interface to use." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ClientAddress = { "ClientAddress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackClientOrigin, ClientAddress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ClientAddress_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ClientAddress_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** The NatNet client type to instantiate. Must match the setting of the NatNet server. */" },
		{ "EditCondition", "!bAutoConnect" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "The NatNet client type to instantiate. Must match the setting of the NatNet server." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType = { "ConnectionType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackClientOrigin, ConnectionType), Z_Construct_UEnum_OptitrackNatnet_EOptitrackClientConnectionType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType_MetaData) }; // 1869603557
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention = { "BoneNamingConvention", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackClientOrigin, BoneNamingConvention), Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention_MetaData) }; // 740152900
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, call InitializeClient and connect automatically during PreInitializeComponents. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true, call InitializeClient and connect automatically during PreInitializeComponents." },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bAutoInitialize = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize = { "bAutoInitialize", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true and connection is Unicast, the NatNet client will have an opt-in policy for receiving data from Motive. Data related to Rigid bodies/Skeletons not referenced in the scene will not be streamed to this client. */" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true and connection is Unicast, the NatNet client will have an opt-in policy for receiving data from Motive. Data related to Rigid bodies/Skeletons not referenced in the scene will not be streamed to this client." },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bUseDataSubscription = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription = { "bUseDataSubscription", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, draw Motive and UE bone locations (white and green respectively)*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true, draw Motive and UE bone locations (white and green respectively)" },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bDrawDebugSkeletons = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons = { "bDrawDebugSkeletons", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, draw Motive's labeled marker locations*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true, draw Motive's labeled marker locations" },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bDrawMarkers = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers = { "bDrawMarkers", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_DrawMarkersColor_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** Color used for labeled marker locations*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "Color used for labeled marker locations" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_DrawMarkersColor = { "DrawMarkersColor", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackClientOrigin, DrawMarkersColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_DrawMarkersColor_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_DrawMarkersColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, draw Motive's camera locations (Motive 3.0+ only)*/" },
		{ "ModuleRelativePath", "Classes/OptitrackClientOrigin.h" },
		{ "ToolTip", "If true, draw Motive's camera locations (Motive 3.0+ only)" },
	};
#endif
	void Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras_SetBit(void* Obj)
	{
		((AOptitrackClientOrigin*)Obj)->bDrawDebugCameras = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras = { "bDrawDebugCameras", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackClientOrigin), &Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras_MetaData), Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOptitrackClientOrigin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoConnect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ServerAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ClientAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_ConnectionType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_BoneNamingConvention,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bAutoInitialize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bUseDataSubscription,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugSkeletons,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawMarkers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_DrawMarkersColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackClientOrigin_Statics::NewProp_bDrawDebugCameras,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOptitrackClientOrigin_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOptitrackClientOrigin>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOptitrackClientOrigin_Statics::ClassParams = {
		&AOptitrackClientOrigin::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AOptitrackClientOrigin_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::Class_MetaDataParams), Z_Construct_UClass_AOptitrackClientOrigin_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackClientOrigin_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AOptitrackClientOrigin()
	{
		if (!Z_Registration_Info_UClass_AOptitrackClientOrigin.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOptitrackClientOrigin.OuterSingleton, Z_Construct_UClass_AOptitrackClientOrigin_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOptitrackClientOrigin.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<AOptitrackClientOrigin>()
	{
		return AOptitrackClientOrigin::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOptitrackClientOrigin);
	AOptitrackClientOrigin::~AOptitrackClientOrigin() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::EnumInfo[] = {
		{ EOptitrackTimestampType_StaticEnum, TEXT("EOptitrackTimestampType"), &Z_Registration_Info_UEnum_EOptitrackTimestampType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3117092262U) },
		{ EOptitrackClientConnectionType_StaticEnum, TEXT("EOptitrackClientConnectionType"), &Z_Registration_Info_UEnum_EOptitrackClientConnectionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1869603557U) },
		{ EOptitrackForwardAxisType_StaticEnum, TEXT("EOptitrackForwardAxisType"), &Z_Registration_Info_UEnum_EOptitrackForwardAxisType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2375543935U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ScriptStructInfo[] = {
		{ FOptitrackRigidBodyState::StaticStruct, Z_Construct_UScriptStruct_FOptitrackRigidBodyState_Statics::NewStructOps, TEXT("OptitrackRigidBodyState"), &Z_Registration_Info_UScriptStruct_OptitrackRigidBodyState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackRigidBodyState), 188295417U) },
		{ FOptitrackMarkerState::StaticStruct, Z_Construct_UScriptStruct_FOptitrackMarkerState_Statics::NewStructOps, TEXT("OptitrackMarkerState"), &Z_Registration_Info_UScriptStruct_OptitrackMarkerState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackMarkerState), 4159873427U) },
		{ FOptitrackCamera::StaticStruct, Z_Construct_UScriptStruct_FOptitrackCamera_Statics::NewStructOps, TEXT("OptitrackCamera"), &Z_Registration_Info_UScriptStruct_OptitrackCamera, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackCamera), 637151860U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOptitrackClientOrigin, AOptitrackClientOrigin::StaticClass, TEXT("AOptitrackClientOrigin"), &Z_Registration_Info_UClass_AOptitrackClientOrigin, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOptitrackClientOrigin), 2895850974U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_2472534502(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackClientOrigin_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
