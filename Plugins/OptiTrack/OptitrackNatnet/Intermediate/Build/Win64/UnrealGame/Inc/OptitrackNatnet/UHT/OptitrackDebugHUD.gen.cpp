// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackDebugHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackDebugHUD() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackDebugHUD();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackDebugHUD_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	void AOptitrackDebugHUD::StaticRegisterNativesAOptitrackDebugHUD()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOptitrackDebugHUD);
	UClass* Z_Construct_UClass_AOptitrackDebugHUD_NoRegister()
	{
		return AOptitrackDebugHUD::StaticClass();
	}
	struct Z_Construct_UClass_AOptitrackDebugHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOptitrackDebugHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackDebugHUD_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackDebugHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "OptitrackDebugHUD.h" },
		{ "ModuleRelativePath", "Classes/OptitrackDebugHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOptitrackDebugHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOptitrackDebugHUD>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOptitrackDebugHUD_Statics::ClassParams = {
		&AOptitrackDebugHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackDebugHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AOptitrackDebugHUD_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AOptitrackDebugHUD()
	{
		if (!Z_Registration_Info_UClass_AOptitrackDebugHUD.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOptitrackDebugHUD.OuterSingleton, Z_Construct_UClass_AOptitrackDebugHUD_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOptitrackDebugHUD.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<AOptitrackDebugHUD>()
	{
		return AOptitrackDebugHUD::StaticClass();
	}
	AOptitrackDebugHUD::AOptitrackDebugHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOptitrackDebugHUD);
	AOptitrackDebugHUD::~AOptitrackDebugHUD() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackDebugHUD_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackDebugHUD_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOptitrackDebugHUD, AOptitrackDebugHUD::StaticClass, TEXT("AOptitrackDebugHUD"), &Z_Registration_Info_UClass_AOptitrackDebugHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOptitrackDebugHUD), 3224742092U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackDebugHUD_h_684538773(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackDebugHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackDebugHUD_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
