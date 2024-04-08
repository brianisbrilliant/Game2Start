// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackRigidBodyActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackRigidBodyActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackRigidBodyActor();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackRigidBodyActor_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackRigidBodyComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	void AOptitrackRigidBodyActor::StaticRegisterNativesAOptitrackRigidBodyActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOptitrackRigidBodyActor);
	UClass* Z_Construct_UClass_AOptitrackRigidBodyActor_NoRegister()
	{
		return AOptitrackRigidBodyActor::StaticClass();
	}
	struct Z_Construct_UClass_AOptitrackRigidBodyActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bHideOnInvalidDefinition_MetaData[];
#endif
		static void NewProp_bHideOnInvalidDefinition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideOnInvalidDefinition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RigidBodyComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RigidBodyComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::Class_MetaDataParams[] = {
		{ "IgnoreCategoryKeywordsInSubclasses", "true" },
		{ "IncludePath", "OptitrackRigidBodyActor.h" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09* If true, rigid body actor will hide if no associated asset is being streamed from Motive.\n\x09*/" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyActor.h" },
		{ "ToolTip", "If true, rigid body actor will hide if no associated asset is being streamed from Motive." },
	};
#endif
	void Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition_SetBit(void* Obj)
	{
		((AOptitrackRigidBodyActor*)Obj)->bHideOnInvalidDefinition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition = { "bHideOnInvalidDefinition", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOptitrackRigidBodyActor), &Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition_MetaData), Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_RigidBodyComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rigid Body Actor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_RigidBodyComponent = { "RigidBodyComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOptitrackRigidBodyActor, RigidBodyComponent), Z_Construct_UClass_UOptitrackRigidBodyComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_RigidBodyComponent_MetaData), Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_RigidBodyComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_bHideOnInvalidDefinition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::NewProp_RigidBodyComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOptitrackRigidBodyActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::ClassParams = {
		&AOptitrackRigidBodyActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AOptitrackRigidBodyActor()
	{
		if (!Z_Registration_Info_UClass_AOptitrackRigidBodyActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOptitrackRigidBodyActor.OuterSingleton, Z_Construct_UClass_AOptitrackRigidBodyActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOptitrackRigidBodyActor.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<AOptitrackRigidBodyActor>()
	{
		return AOptitrackRigidBodyActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOptitrackRigidBodyActor);
	AOptitrackRigidBodyActor::~AOptitrackRigidBodyActor() {}
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOptitrackRigidBodyActor, AOptitrackRigidBodyActor::StaticClass, TEXT("AOptitrackRigidBodyActor"), &Z_Registration_Info_UClass_AOptitrackRigidBodyActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOptitrackRigidBodyActor), 4181563182U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyActor_h_2519093736(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
