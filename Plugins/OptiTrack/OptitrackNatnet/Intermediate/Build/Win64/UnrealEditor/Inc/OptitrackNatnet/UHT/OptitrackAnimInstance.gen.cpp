// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackAnimInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackAnimInstance();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackAnimInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	void UOptitrackAnimInstance::StaticRegisterNativesUOptitrackAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOptitrackAnimInstance);
	UClass* Z_Construct_UClass_UOptitrackAnimInstance_NoRegister()
	{
		return UOptitrackAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UOptitrackAnimInstance_Statics
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOptitrackAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "OptitrackAnimInstance.h" },
		{ "ModuleRelativePath", "Classes/OptitrackAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_SourceSkeletonAssetName_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Classes/OptitrackAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_SourceSkeletonAssetName = { "SourceSkeletonAssetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackAnimInstance, SourceSkeletonAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_SourceSkeletonAssetName_MetaData), Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_SourceSkeletonAssetName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_StreamingClientOrigin_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "ModuleRelativePath", "Classes/OptitrackAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_StreamingClientOrigin = { "StreamingClientOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackAnimInstance, StreamingClientOrigin), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_StreamingClientOrigin_MetaData), Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_StreamingClientOrigin_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOptitrackAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_SourceSkeletonAssetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackAnimInstance_Statics::NewProp_StreamingClientOrigin,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOptitrackAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOptitrackAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOptitrackAnimInstance_Statics::ClassParams = {
		&UOptitrackAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOptitrackAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UOptitrackAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOptitrackAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UOptitrackAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOptitrackAnimInstance.OuterSingleton, Z_Construct_UClass_UOptitrackAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOptitrackAnimInstance.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<UOptitrackAnimInstance>()
	{
		return UOptitrackAnimInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOptitrackAnimInstance);
	UOptitrackAnimInstance::~UOptitrackAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOptitrackAnimInstance, UOptitrackAnimInstance::StaticClass, TEXT("UOptitrackAnimInstance"), &Z_Registration_Info_UClass_UOptitrackAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOptitrackAnimInstance), 56693244U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackAnimInstance_h_2137757666(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
