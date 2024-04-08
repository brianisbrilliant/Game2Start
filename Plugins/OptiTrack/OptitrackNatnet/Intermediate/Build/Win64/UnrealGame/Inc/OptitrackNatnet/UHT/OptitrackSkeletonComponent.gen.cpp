// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackSkeletonComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackSkeletonComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackAnimInstance_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackSkeletonComponent();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackSkeletonComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	void UOptitrackSkeletonComponent::StaticRegisterNativesUOptitrackSkeletonComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOptitrackSkeletonComponent);
	UClass* Z_Construct_UClass_UOptitrackSkeletonComponent_NoRegister()
	{
		return UOptitrackSkeletonComponent::StaticClass();
	}
	struct Z_Construct_UClass_UOptitrackSkeletonComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceSkeletonAssetName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SourceSkeletonAssetName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StreamingClientOrigin_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StreamingClientOrigin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HideOnInvalidDefinition_MetaData[];
#endif
		static void NewProp_HideOnInvalidDefinition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_HideOnInvalidDefinition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OptitrackAnimInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OptitrackAnimInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "OptiTrack" },
		{ "Comment", "/**\n* A component that drives the position and rotation of its actor's root\n* component based on the extracted XY planar movement of a tracked skeleton's\n* root motion / hip movement. Designed to work with FAnimNode_OptitrackSkeleton.\n*/" },
		{ "IncludePath", "OptitrackSkeletonComponent.h" },
		{ "ModuleRelativePath", "Classes/OptitrackSkeletonComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "A component that drives the position and rotation of its actor's root\ncomponent based on the extracted XY planar movement of a tracked skeleton's\nroot motion / hip movement. Designed to work with FAnimNode_OptitrackSkeleton." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_SourceSkeletonAssetName_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Classes/OptitrackSkeletonComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_SourceSkeletonAssetName = { "SourceSkeletonAssetName", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackSkeletonComponent, SourceSkeletonAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_SourceSkeletonAssetName_MetaData), Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_SourceSkeletonAssetName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_StreamingClientOrigin_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09* If your scene contains multiple client origin objects, you can specify\n\x09* which one to use. If unset, this defaults to the first client origin\n\x09* that's found in the world.\n\x09*/" },
		{ "ModuleRelativePath", "Classes/OptitrackSkeletonComponent.h" },
		{ "ToolTip", "If your scene contains multiple client origin objects, you can specify\nwhich one to use. If unset, this defaults to the first client origin\nthat's found in the world." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_StreamingClientOrigin = { "StreamingClientOrigin", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackSkeletonComponent, StreamingClientOrigin), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_StreamingClientOrigin_MetaData), Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_StreamingClientOrigin_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n    * If asset isn't being streamed from Motive, hide skeleton.\n    * Defaults to true.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackSkeletonComponent.h" },
		{ "ToolTip", "If asset isn't being streamed from Motive, hide skeleton.\nDefaults to true." },
	};
#endif
	void Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition_SetBit(void* Obj)
	{
		((UOptitrackSkeletonComponent*)Obj)->HideOnInvalidDefinition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition = { "HideOnInvalidDefinition", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackSkeletonComponent), &Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition_MetaData), Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_OptitrackAnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "Classes/OptitrackSkeletonComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_OptitrackAnimInstance = { "OptitrackAnimInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackSkeletonComponent, OptitrackAnimInstance), Z_Construct_UClass_UOptitrackAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_OptitrackAnimInstance_MetaData), Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_OptitrackAnimInstance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_SourceSkeletonAssetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_StreamingClientOrigin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_HideOnInvalidDefinition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::NewProp_OptitrackAnimInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOptitrackSkeletonComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::ClassParams = {
		&UOptitrackSkeletonComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOptitrackSkeletonComponent()
	{
		if (!Z_Registration_Info_UClass_UOptitrackSkeletonComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOptitrackSkeletonComponent.OuterSingleton, Z_Construct_UClass_UOptitrackSkeletonComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOptitrackSkeletonComponent.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<UOptitrackSkeletonComponent>()
	{
		return UOptitrackSkeletonComponent::StaticClass();
	}

	void UOptitrackSkeletonComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_SourceSkeletonAssetName(TEXT("SourceSkeletonAssetName"));

		const bool bIsValid = true
			&& Name_SourceSkeletonAssetName == ClassReps[(int32)ENetFields_Private::SourceSkeletonAssetName].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UOptitrackSkeletonComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOptitrackSkeletonComponent);
	UOptitrackSkeletonComponent::~UOptitrackSkeletonComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOptitrackSkeletonComponent, UOptitrackSkeletonComponent::StaticClass, TEXT("UOptitrackSkeletonComponent"), &Z_Registration_Info_UClass_UOptitrackSkeletonComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOptitrackSkeletonComponent), 4198108739U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_258170597(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackSkeletonComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
