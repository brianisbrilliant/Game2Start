// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnetEditor/Public/AnimGraphNode_OptitrackSkeleton.h"
#include "OptitrackNatnet/Public/AnimNode_OptitrackSkeleton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_OptitrackSkeleton() {}
// Cross Module References
	ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_Base();
	OPTITRACKNATNET_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton();
	OPTITRACKNATNETEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton();
	OPTITRACKNATNETEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnetEditor();
// End Cross Module References
	void UAnimGraphNode_OptitrackSkeleton::StaticRegisterNativesUAnimGraphNode_OptitrackSkeleton()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_OptitrackSkeleton);
	UClass* Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_NoRegister()
	{
		return UAnimGraphNode_OptitrackSkeleton::StaticClass();
	}
	struct Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Node;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnetEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "AnimGraphNode_OptitrackSkeleton.h" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_OptitrackSkeleton.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::NewProp_Node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_OptitrackSkeleton.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimGraphNode_OptitrackSkeleton, Node), Z_Construct_UScriptStruct_FAnimNode_OptitrackSkeleton, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::NewProp_Node_MetaData), Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::NewProp_Node_MetaData) }; // 2782919493
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::NewProp_Node,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_OptitrackSkeleton>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::ClassParams = {
		&UAnimGraphNode_OptitrackSkeleton::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton()
	{
		if (!Z_Registration_Info_UClass_UAnimGraphNode_OptitrackSkeleton.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_OptitrackSkeleton.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimGraphNode_OptitrackSkeleton.OuterSingleton;
	}
	template<> OPTITRACKNATNETEDITOR_API UClass* StaticClass<UAnimGraphNode_OptitrackSkeleton>()
	{
		return UAnimGraphNode_OptitrackSkeleton::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_OptitrackSkeleton);
	UAnimGraphNode_OptitrackSkeleton::~UAnimGraphNode_OptitrackSkeleton() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnetEditor_Public_AnimGraphNode_OptitrackSkeleton_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnetEditor_Public_AnimGraphNode_OptitrackSkeleton_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_OptitrackSkeleton, UAnimGraphNode_OptitrackSkeleton::StaticClass, TEXT("UAnimGraphNode_OptitrackSkeleton"), &Z_Registration_Info_UClass_UAnimGraphNode_OptitrackSkeleton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_OptitrackSkeleton), 3473064171U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnetEditor_Public_AnimGraphNode_OptitrackSkeleton_h_3988059558(TEXT("/Script/OptitrackNatnetEditor"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnetEditor_Public_AnimGraphNode_OptitrackSkeleton_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnetEditor_Public_AnimGraphNode_OptitrackSkeleton_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
