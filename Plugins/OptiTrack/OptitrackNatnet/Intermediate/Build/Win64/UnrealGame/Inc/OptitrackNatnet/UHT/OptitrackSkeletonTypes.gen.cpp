// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Public/OptitrackSkeletonTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackSkeletonTypes() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone();
	OPTITRACKNATNET_API UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackBoneDefinition();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackPose();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonState();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackPose;
class UScriptStruct* FOptitrackPose::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackPose.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackPose.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackPose, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackPose"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackPose.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackPose>()
{
	return FOptitrackPose::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackPose_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackPose_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackPose>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackPose, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Orientation_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackPose, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Orientation_MetaData), Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Orientation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackPose_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewProp_Orientation,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackPose_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackPose",
		Z_Construct_UScriptStruct_FOptitrackPose_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackPose_Statics::PropPointers),
		sizeof(FOptitrackPose),
		alignof(FOptitrackPose),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackPose_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackPose_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackPose_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackPose()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackPose.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackPose.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackPose_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackPose.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention;
	static UEnum* EOptitrackBoneNamingConvention_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("EOptitrackBoneNamingConvention"));
		}
		return Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackBoneNamingConvention>()
	{
		return EOptitrackBoneNamingConvention_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enumerators[] = {
		{ "EOptitrackBoneNamingConvention::Motive", (int64)EOptitrackBoneNamingConvention::Motive },
		{ "EOptitrackBoneNamingConvention::FBX", (int64)EOptitrackBoneNamingConvention::FBX },
		{ "EOptitrackBoneNamingConvention::BVH", (int64)EOptitrackBoneNamingConvention::BVH },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BVH.DisplayName", "BVH" },
		{ "BVH.Name", "EOptitrackBoneNamingConvention::BVH" },
		{ "FBX.DisplayName", "FBX" },
		{ "FBX.Name", "EOptitrackBoneNamingConvention::FBX" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
		{ "Motive.DisplayName", "Motive" },
		{ "Motive.Name", "EOptitrackBoneNamingConvention::Motive" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		"EOptitrackBoneNamingConvention",
		"EOptitrackBoneNamingConvention",
		Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.InnerSingleton, Z_Construct_UEnum_OptitrackNatnet_EOptitrackBoneNamingConvention_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackBone;
	static UEnum* EOptitrackBone_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackBone.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackBone.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("EOptitrackBone"));
		}
		return Z_Registration_Info_UEnum_EOptitrackBone.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UEnum* StaticEnum<EOptitrackBone>()
	{
		return EOptitrackBone_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enumerators[] = {
		{ "EOptitrackBone::Root", (int64)EOptitrackBone::Root },
		{ "EOptitrackBone::Hip", (int64)EOptitrackBone::Hip },
		{ "EOptitrackBone::Ab", (int64)EOptitrackBone::Ab },
		{ "EOptitrackBone::Chest", (int64)EOptitrackBone::Chest },
		{ "EOptitrackBone::Neck", (int64)EOptitrackBone::Neck },
		{ "EOptitrackBone::Head", (int64)EOptitrackBone::Head },
		{ "EOptitrackBone::LShoulder", (int64)EOptitrackBone::LShoulder },
		{ "EOptitrackBone::LUArm", (int64)EOptitrackBone::LUArm },
		{ "EOptitrackBone::LFArm", (int64)EOptitrackBone::LFArm },
		{ "EOptitrackBone::LHand", (int64)EOptitrackBone::LHand },
		{ "EOptitrackBone::RShoulder", (int64)EOptitrackBone::RShoulder },
		{ "EOptitrackBone::RUArm", (int64)EOptitrackBone::RUArm },
		{ "EOptitrackBone::RFArm", (int64)EOptitrackBone::RFArm },
		{ "EOptitrackBone::RHand", (int64)EOptitrackBone::RHand },
		{ "EOptitrackBone::LThigh", (int64)EOptitrackBone::LThigh },
		{ "EOptitrackBone::LShin", (int64)EOptitrackBone::LShin },
		{ "EOptitrackBone::LFoot", (int64)EOptitrackBone::LFoot },
		{ "EOptitrackBone::LToe", (int64)EOptitrackBone::LToe },
		{ "EOptitrackBone::RThigh", (int64)EOptitrackBone::RThigh },
		{ "EOptitrackBone::RShin", (int64)EOptitrackBone::RShin },
		{ "EOptitrackBone::RFoot", (int64)EOptitrackBone::RFoot },
		{ "EOptitrackBone::RToe", (int64)EOptitrackBone::RToe },
		{ "EOptitrackBone::LThumb1", (int64)EOptitrackBone::LThumb1 },
		{ "EOptitrackBone::LThumb2", (int64)EOptitrackBone::LThumb2 },
		{ "EOptitrackBone::LThumb3", (int64)EOptitrackBone::LThumb3 },
		{ "EOptitrackBone::LIndex1", (int64)EOptitrackBone::LIndex1 },
		{ "EOptitrackBone::LIndex2", (int64)EOptitrackBone::LIndex2 },
		{ "EOptitrackBone::LIndex3", (int64)EOptitrackBone::LIndex3 },
		{ "EOptitrackBone::LMiddle1", (int64)EOptitrackBone::LMiddle1 },
		{ "EOptitrackBone::LMiddle2", (int64)EOptitrackBone::LMiddle2 },
		{ "EOptitrackBone::LMiddle3", (int64)EOptitrackBone::LMiddle3 },
		{ "EOptitrackBone::LRing1", (int64)EOptitrackBone::LRing1 },
		{ "EOptitrackBone::LRing2", (int64)EOptitrackBone::LRing2 },
		{ "EOptitrackBone::LRing3", (int64)EOptitrackBone::LRing3 },
		{ "EOptitrackBone::LPinky1", (int64)EOptitrackBone::LPinky1 },
		{ "EOptitrackBone::LPinky2", (int64)EOptitrackBone::LPinky2 },
		{ "EOptitrackBone::LPinky3", (int64)EOptitrackBone::LPinky3 },
		{ "EOptitrackBone::RThumb1", (int64)EOptitrackBone::RThumb1 },
		{ "EOptitrackBone::RThumb2", (int64)EOptitrackBone::RThumb2 },
		{ "EOptitrackBone::RThumb3", (int64)EOptitrackBone::RThumb3 },
		{ "EOptitrackBone::RIndex1", (int64)EOptitrackBone::RIndex1 },
		{ "EOptitrackBone::RIndex2", (int64)EOptitrackBone::RIndex2 },
		{ "EOptitrackBone::RIndex3", (int64)EOptitrackBone::RIndex3 },
		{ "EOptitrackBone::RMiddle1", (int64)EOptitrackBone::RMiddle1 },
		{ "EOptitrackBone::RMiddle2", (int64)EOptitrackBone::RMiddle2 },
		{ "EOptitrackBone::RMiddle3", (int64)EOptitrackBone::RMiddle3 },
		{ "EOptitrackBone::RRing1", (int64)EOptitrackBone::RRing1 },
		{ "EOptitrackBone::RRing2", (int64)EOptitrackBone::RRing2 },
		{ "EOptitrackBone::RRing3", (int64)EOptitrackBone::RRing3 },
		{ "EOptitrackBone::RPinky1", (int64)EOptitrackBone::RPinky1 },
		{ "EOptitrackBone::RPinky2", (int64)EOptitrackBone::RPinky2 },
		{ "EOptitrackBone::RPinky3", (int64)EOptitrackBone::RPinky3 },
		{ "EOptitrackBone::NumBones", (int64)EOptitrackBone::NumBones },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enum_MetaDataParams[] = {
		{ "Ab.Name", "EOptitrackBone::Ab" },
		{ "BlueprintType", "true" },
		{ "Chest.Name", "EOptitrackBone::Chest" },
		{ "Head.Name", "EOptitrackBone::Head" },
		{ "Hip.Name", "EOptitrackBone::Hip" },
		{ "LFArm.Name", "EOptitrackBone::LFArm" },
		{ "LFoot.Name", "EOptitrackBone::LFoot" },
		{ "LHand.Name", "EOptitrackBone::LHand" },
		{ "LIndex1.Name", "EOptitrackBone::LIndex1" },
		{ "LIndex2.Name", "EOptitrackBone::LIndex2" },
		{ "LIndex3.Name", "EOptitrackBone::LIndex3" },
		{ "LMiddle1.Name", "EOptitrackBone::LMiddle1" },
		{ "LMiddle2.Name", "EOptitrackBone::LMiddle2" },
		{ "LMiddle3.Name", "EOptitrackBone::LMiddle3" },
		{ "LPinky1.Name", "EOptitrackBone::LPinky1" },
		{ "LPinky2.Name", "EOptitrackBone::LPinky2" },
		{ "LPinky3.Name", "EOptitrackBone::LPinky3" },
		{ "LRing1.Name", "EOptitrackBone::LRing1" },
		{ "LRing2.Name", "EOptitrackBone::LRing2" },
		{ "LRing3.Name", "EOptitrackBone::LRing3" },
		{ "LShin.Name", "EOptitrackBone::LShin" },
		{ "LShoulder.Name", "EOptitrackBone::LShoulder" },
		{ "LThigh.Name", "EOptitrackBone::LThigh" },
		{ "LThumb1.Name", "EOptitrackBone::LThumb1" },
		{ "LThumb2.Name", "EOptitrackBone::LThumb2" },
		{ "LThumb3.Name", "EOptitrackBone::LThumb3" },
		{ "LToe.Name", "EOptitrackBone::LToe" },
		{ "LUArm.Name", "EOptitrackBone::LUArm" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
		{ "Neck.Name", "EOptitrackBone::Neck" },
		{ "NumBones.Name", "EOptitrackBone::NumBones" },
		{ "RFArm.Name", "EOptitrackBone::RFArm" },
		{ "RFoot.Name", "EOptitrackBone::RFoot" },
		{ "RHand.Name", "EOptitrackBone::RHand" },
		{ "RIndex1.Name", "EOptitrackBone::RIndex1" },
		{ "RIndex2.Name", "EOptitrackBone::RIndex2" },
		{ "RIndex3.Name", "EOptitrackBone::RIndex3" },
		{ "RMiddle1.Name", "EOptitrackBone::RMiddle1" },
		{ "RMiddle2.Name", "EOptitrackBone::RMiddle2" },
		{ "RMiddle3.Name", "EOptitrackBone::RMiddle3" },
		{ "Root.Name", "EOptitrackBone::Root" },
		{ "RPinky1.Name", "EOptitrackBone::RPinky1" },
		{ "RPinky2.Name", "EOptitrackBone::RPinky2" },
		{ "RPinky3.Name", "EOptitrackBone::RPinky3" },
		{ "RRing1.Name", "EOptitrackBone::RRing1" },
		{ "RRing2.Name", "EOptitrackBone::RRing2" },
		{ "RRing3.Name", "EOptitrackBone::RRing3" },
		{ "RShin.Name", "EOptitrackBone::RShin" },
		{ "RShoulder.Name", "EOptitrackBone::RShoulder" },
		{ "RThigh.Name", "EOptitrackBone::RThigh" },
		{ "RThumb1.Name", "EOptitrackBone::RThumb1" },
		{ "RThumb2.Name", "EOptitrackBone::RThumb2" },
		{ "RThumb3.Name", "EOptitrackBone::RThumb3" },
		{ "RToe.Name", "EOptitrackBone::RToe" },
		{ "RUArm.Name", "EOptitrackBone::RUArm" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		"EOptitrackBone",
		"EOptitrackBone",
		Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackBone.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackBone.InnerSingleton, Z_Construct_UEnum_OptitrackNatnet_EOptitrackBone_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackBone.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition;
class UScriptStruct* FOptitrackBoneDefinition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackBoneDefinition, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackBoneDefinition"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackBoneDefinition>()
{
	return FOptitrackBoneDefinition::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentId_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ParentId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LocalOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// The streaming skeleton begins at the hip bone; the root bone is implicit, and not streamed.\n" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
		{ "ToolTip", "The streaming skeleton begins at the hip bone; the root bone is implicit, and not streamed." },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackBoneDefinition>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Id_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackBoneDefinition, Id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Id_MetaData), Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Id_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_ParentId_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_ParentId = { "ParentId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackBoneDefinition, ParentId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_ParentId_MetaData), Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_ParentId_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackBoneDefinition, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_LocalOffset_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_LocalOffset = { "LocalOffset", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackBoneDefinition, LocalOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_LocalOffset_MetaData), Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_LocalOffset_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_ParentId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewProp_LocalOffset,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackBoneDefinition",
		Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::PropPointers),
		sizeof(FOptitrackBoneDefinition),
		alignof(FOptitrackBoneDefinition),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackBoneDefinition()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition;
class UScriptStruct* FOptitrackSkeletonDefinition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackSkeletonDefinition"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackSkeletonDefinition>()
{
	return FOptitrackSkeletonDefinition::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bones_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Bones_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bones_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Bones;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackSkeletonDefinition>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Id_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonDefinition, Id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Id_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Id_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonDefinition, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Name_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_ValueProp = { "Bones", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOptitrackBoneDefinition, METADATA_PARAMS(0, nullptr) }; // 3337760777
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_Key_KeyProp = { "Bones_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones = { "Bones", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonDefinition, Bones), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_MetaData) }; // 3337760777
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewProp_Bones,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackSkeletonDefinition",
		Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::PropPointers),
		sizeof(FOptitrackSkeletonDefinition),
		alignof(FOptitrackSkeletonDefinition),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OptitrackSkeletonState;
class UScriptStruct* FOptitrackSkeletonState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOptitrackSkeletonState, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("OptitrackSkeletonState"));
	}
	return Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FOptitrackSkeletonState>()
{
	return FOptitrackSkeletonState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_BonePoses_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_BonePoses_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BonePoses_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_BonePoses;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldSpaceBoneTransforms_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_WorldSpaceBoneTransforms_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldSpaceBoneTransforms_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_WorldSpaceBoneTransforms;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LocalBoneSpaceTransforms_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LocalBoneSpaceTransforms_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalBoneSpaceTransforms_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_LocalBoneSpaceTransforms;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOptitrackSkeletonState>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_ValueProp = { "BonePoses", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOptitrackPose, METADATA_PARAMS(0, nullptr) }; // 2898488484
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_Key_KeyProp = { "BonePoses_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses = { "BonePoses", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonState, BonePoses), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_MetaData) }; // 2898488484
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_ValueProp = { "WorldSpaceBoneTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_Key_KeyProp = { "WorldSpaceBoneTransforms_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms = { "WorldSpaceBoneTransforms", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonState, WorldSpaceBoneTransforms), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_ValueProp = { "LocalBoneSpaceTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_Key_KeyProp = { "LocalBoneSpaceTransforms_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Public/OptitrackSkeletonTypes.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms = { "LocalBoneSpaceTransforms", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOptitrackSkeletonState, LocalBoneSpaceTransforms), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_MetaData), Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_BonePoses,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_WorldSpaceBoneTransforms,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewProp_LocalBoneSpaceTransforms,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		nullptr,
		&NewStructOps,
		"OptitrackSkeletonState",
		Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::PropPointers),
		sizeof(FOptitrackSkeletonState),
		alignof(FOptitrackSkeletonState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FOptitrackSkeletonState()
	{
		if (!Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.InnerSingleton, Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OptitrackSkeletonState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::EnumInfo[] = {
		{ EOptitrackBoneNamingConvention_StaticEnum, TEXT("EOptitrackBoneNamingConvention"), &Z_Registration_Info_UEnum_EOptitrackBoneNamingConvention, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 740152900U) },
		{ EOptitrackBone_StaticEnum, TEXT("EOptitrackBone"), &Z_Registration_Info_UEnum_EOptitrackBone, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3903250755U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::ScriptStructInfo[] = {
		{ FOptitrackPose::StaticStruct, Z_Construct_UScriptStruct_FOptitrackPose_Statics::NewStructOps, TEXT("OptitrackPose"), &Z_Registration_Info_UScriptStruct_OptitrackPose, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackPose), 2898488484U) },
		{ FOptitrackBoneDefinition::StaticStruct, Z_Construct_UScriptStruct_FOptitrackBoneDefinition_Statics::NewStructOps, TEXT("OptitrackBoneDefinition"), &Z_Registration_Info_UScriptStruct_OptitrackBoneDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackBoneDefinition), 3337760777U) },
		{ FOptitrackSkeletonDefinition::StaticStruct, Z_Construct_UScriptStruct_FOptitrackSkeletonDefinition_Statics::NewStructOps, TEXT("OptitrackSkeletonDefinition"), &Z_Registration_Info_UScriptStruct_OptitrackSkeletonDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackSkeletonDefinition), 1304275298U) },
		{ FOptitrackSkeletonState::StaticStruct, Z_Construct_UScriptStruct_FOptitrackSkeletonState_Statics::NewStructOps, TEXT("OptitrackSkeletonState"), &Z_Registration_Info_UScriptStruct_OptitrackSkeletonState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOptitrackSkeletonState), 3316904843U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_394162699(TEXT("/Script/OptitrackNatnet"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_OptitrackSkeletonTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
