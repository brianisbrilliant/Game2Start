// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Public/AnimNode_OptitrackSkeleton.h"
#include "../../Source/Runtime/Engine/Public/Animation/BoneSocketReference.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_OptitrackSkeleton() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_Base();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneSocketTarget();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_OptitrackSkeleton>() == std::is_polymorphic<FAnimNode_Base>(), "USTRUCT FAnimNode_OptitrackSkeleton cannot be polymorphic unless super FAnimNode_Base is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton;
class UScriptStruct* FAnimNode_OptitrackSkeleton::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton, (UObject*)Z_Construct_UPackage__Script_OptitrackNatnet(), TEXT("AnimNode_OptitrackSkeleton"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.OuterSingleton;
}
template<> OPTITRACKNATNET_API UScriptStruct* StaticStruct<FAnimNode_OptitrackSkeleton>()
{
	return FAnimNode_OptitrackSkeleton::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RetargetBaseMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RetargetBaseMesh;
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoneSockets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneSockets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BoneSockets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceSkeletonAssetName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SourceSkeletonAssetName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StreamingClientOrigin_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StreamingClientOrigin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScaleBones_MetaData[];
#endif
		static void NewProp_ScaleBones_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ScaleBones;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PoseCorrection_MetaData[];
#endif
		static void NewProp_PoseCorrection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_PoseCorrection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollBoneInterpolation_MetaData[];
#endif
		static void NewProp_RollBoneInterpolation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_RollBoneInterpolation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollBoneBlending_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollBoneBlending;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FingerRotationOnly_MetaData[];
#endif
		static void NewProp_FingerRotationOnly_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FingerRotationOnly;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletonBaseRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SkeletonBaseRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UseTranslationCorrection_MetaData[];
#endif
		static void NewProp_UseTranslationCorrection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseTranslationCorrection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UseSpineInterpolation_MetaData[];
#endif
		static void NewProp_UseSpineInterpolation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseSpineInterpolation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThumbBaseRotation_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThumbBaseRotation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RetargetBasePose_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RetargetBasePose_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RetargetBasePose;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_OptitrackSkeleton>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBaseMesh_MetaData[] = {
		{ "Comment", "//( EditAnywhere, BlueprintReadWrite, Category=\"Retargeting\" )\n" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "ToolTip", "( EditAnywhere, BlueprintReadWrite, Category=\"Retargeting\" )" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBaseMesh = { "RetargetBaseMesh", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, RetargetBaseMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBaseMesh_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBaseMesh_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets_Inner = { "BoneSockets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBoneSocketTarget, METADATA_PARAMS(0, nullptr) }; // 2515700810
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets_MetaData[] = {
		{ "Category", "Retargeting" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets = { "BoneSockets", nullptr, (EPropertyFlags)0x0010000000000041, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, BoneSockets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets_MetaData) }; // 2515700810
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SourceSkeletonAssetName_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SourceSkeletonAssetName = { "SourceSkeletonAssetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, SourceSkeletonAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SourceSkeletonAssetName_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SourceSkeletonAssetName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_StreamingClientOrigin_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_StreamingClientOrigin = { "StreamingClientOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, StreamingClientOrigin), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_StreamingClientOrigin_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_StreamingClientOrigin_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Scale UE bones to match tracked skeleton*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Scale UE bones to match tracked skeleton" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->ScaleBones = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones = { "ScaleBones", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Infer rotation of reference bone poses to match Motive T-Pose*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Infer rotation of reference bone poses to match Motive T-Pose" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->PoseCorrection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection = { "PoseCorrection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Infer appropriate roll bone orientation. Only available for arms.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Infer appropriate roll bone orientation. Only available for arms." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->RollBoneInterpolation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation = { "RollBoneInterpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneBlending_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Blending parameter for rollbone interpolation*/" },
		{ "EditCondition", "RollBoneInterpolation" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Blending parameter for rollbone interpolation" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneBlending = { "RollBoneBlending", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, RollBoneBlending), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneBlending_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneBlending_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Enable to ignore finger positions and only use orientation information from Motive when mapping hands.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Enable to ignore finger positions and only use orientation information from Motive when mapping hands." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->FingerRotationOnly = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly = { "FingerRotationOnly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SkeletonBaseRotation_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Base Skeleton Rotation. Automatically inferred for full skeletons.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "Base Skeleton Rotation. Automatically inferred for full skeletons." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SkeletonBaseRotation = { "SkeletonBaseRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, SkeletonBaseRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SkeletonBaseRotation_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SkeletonBaseRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Base Skeleton Rotation. Automatically inferred for full skeletons.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "Base Skeleton Rotation. Automatically inferred for full skeletons." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->UseTranslationCorrection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection = { "UseTranslationCorrection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Base Skeleton Rotation. Automatically inferred for full skeletons.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "Base Skeleton Rotation. Automatically inferred for full skeletons." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation_SetBit(void* Obj)
	{
		((FAnimNode_OptitrackSkeleton*)Obj)->UseSpineInterpolation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation = { "UseSpineInterpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_OptitrackSkeleton), &Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ThumbBaseRotation_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Base Thumb Rotation.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "Base Thumb Rotation." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ThumbBaseRotation = { "ThumbBaseRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, ThumbBaseRotation), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ThumbBaseRotation_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ThumbBaseRotation_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose_Inner = { "RetargetBasePose", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimNode_OptitrackSkeleton.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose = { "RetargetBasePose", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_OptitrackSkeleton, RetargetBasePose), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose_MetaData), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBaseMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_BoneSockets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SourceSkeletonAssetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_StreamingClientOrigin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ScaleBones,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_PoseCorrection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneInterpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RollBoneBlending,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_FingerRotationOnly,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_SkeletonBaseRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseTranslationCorrection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_UseSpineInterpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_ThumbBaseRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewProp_RetargetBasePose,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
		Z_Construct_UScriptStruct_FAnimNode_Base,
		&NewStructOps,
		"AnimNode_OptitrackSkeleton",
		Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::PropPointers),
		sizeof(FAnimNode_OptitrackSkeleton),
		alignof(FAnimNode_OptitrackSkeleton),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_AnimNode_OptitrackSkeleton_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_AnimNode_OptitrackSkeleton_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_OptitrackSkeleton::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton_Statics::NewStructOps, TEXT("AnimNode_OptitrackSkeleton"), &Z_Registration_Info_UScriptStruct_AnimNode_OptitrackSkeleton, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_OptitrackSkeleton), 2782919493U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_AnimNode_OptitrackSkeleton_h_3700626883(TEXT("/Script/OptitrackNatnet"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_AnimNode_OptitrackSkeleton_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Public_AnimNode_OptitrackSkeleton_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
