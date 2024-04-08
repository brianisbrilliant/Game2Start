// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackNatnet/Classes/OptitrackRigidBodyComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOptitrackRigidBodyComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_AOptitrackClientOrigin_NoRegister();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackRigidBodyComponent();
	OPTITRACKNATNET_API UClass* Z_Construct_UClass_UOptitrackRigidBodyComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OptitrackNatnet();
// End Cross Module References
	void UOptitrackRigidBodyComponent::StaticRegisterNativesUOptitrackRigidBodyComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOptitrackRigidBodyComponent);
	UClass* Z_Construct_UClass_UOptitrackRigidBodyComponent_NoRegister()
	{
		return UOptitrackRigidBodyComponent::StaticClass();
	}
	struct Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StreamingId_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_StreamingId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDisableLowLatencyUpdate_MetaData[];
#endif
		static void NewProp_bDisableLowLatencyUpdate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableLowLatencyUpdate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bNetworkCompensation_MetaData[];
#endif
		static void NewProp_bNetworkCompensation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNetworkCompensation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackingOrigin_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TrackingOrigin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RespectParentTransform_MetaData[];
#endif
		static void NewProp_RespectParentTransform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_RespectParentTransform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackNatnet,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OptiTrack" },
		{ "Comment", "/**\n  * A component whose position and orientation is driven by the pose of the\n  * specified tracked rigid body. Supports render thread \"late updates\" for\n  * reduced tracking latency.\n  */" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "OptitrackRigidBodyComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "A component whose position and orientation is driven by the pose of the\nspecified tracked rigid body. Supports render thread \"late updates\" for\nreduced tracking latency." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_StreamingId_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** ID of the rigid body used to drive this component's transform. */" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "ID of the rigid body used to drive this component's transform." },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_StreamingId = { "StreamingId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackRigidBodyComponent, StreamingId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_StreamingId_MetaData), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_StreamingId_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If false, render transforms within the rigid body hierarchy will be updated a second time immediately before rendering. */" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "If false, render transforms within the rigid body hierarchy will be updated a second time immediately before rendering." },
	};
#endif
	void Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate_SetBit(void* Obj)
	{
		((UOptitrackRigidBodyComponent*)Obj)->bDisableLowLatencyUpdate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate = { "bDisableLowLatencyUpdate", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UOptitrackRigidBodyComponent), &Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate_MetaData), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/** If true, compensate rigid body to account for network/software latency.*/" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "If true, compensate rigid body to account for network/software latency." },
	};
#endif
	void Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation_SetBit(void* Obj)
	{
		((UOptitrackRigidBodyComponent*)Obj)->bNetworkCompensation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation = { "bNetworkCompensation", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackRigidBodyComponent), &Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation_MetaData), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_TrackingOrigin_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n\x09* If your scene contains multiple client origin objects, you can specify\n\x09* which one to use. If unset, this defaults to the first client origin\n\x09* that's found in the world.\n\x09*/" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "If your scene contains multiple client origin objects, you can specify\nwhich one to use. If unset, this defaults to the first client origin\nthat's found in the world." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_TrackingOrigin = { "TrackingOrigin", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackRigidBodyComponent, TrackingOrigin), Z_Construct_UClass_AOptitrackClientOrigin_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_TrackingOrigin_MetaData), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_TrackingOrigin_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform_MetaData[] = {
		{ "Category", "Optitrack" },
		{ "Comment", "/**\n    * If true, rigid body transform from Motive will be applied with respect to parent transform instead of the client origin.\n    */" },
		{ "ModuleRelativePath", "Classes/OptitrackRigidBodyComponent.h" },
		{ "ToolTip", "If true, rigid body transform from Motive will be applied with respect to parent transform instead of the client origin." },
	};
#endif
	void Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform_SetBit(void* Obj)
	{
		((UOptitrackRigidBodyComponent*)Obj)->RespectParentTransform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform = { "RespectParentTransform", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackRigidBodyComponent), &Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform_MetaData), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_StreamingId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bDisableLowLatencyUpdate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_bNetworkCompensation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_TrackingOrigin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::NewProp_RespectParentTransform,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOptitrackRigidBodyComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::ClassParams = {
		&UOptitrackRigidBodyComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOptitrackRigidBodyComponent()
	{
		if (!Z_Registration_Info_UClass_UOptitrackRigidBodyComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOptitrackRigidBodyComponent.OuterSingleton, Z_Construct_UClass_UOptitrackRigidBodyComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOptitrackRigidBodyComponent.OuterSingleton;
	}
	template<> OPTITRACKNATNET_API UClass* StaticClass<UOptitrackRigidBodyComponent>()
	{
		return UOptitrackRigidBodyComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOptitrackRigidBodyComponent);
	struct Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOptitrackRigidBodyComponent, UOptitrackRigidBodyComponent::StaticClass, TEXT("UOptitrackRigidBodyComponent"), &Z_Registration_Info_UClass_UOptitrackRigidBodyComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOptitrackRigidBodyComponent), 3861491606U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyComponent_h_1586109202(TEXT("/Script/OptitrackNatnet"),
		Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_r1ver_OneDrive_Desktop_OptiTrack_OptitrackNatnet_HostProject_Plugins_OptitrackNatnet_Source_OptitrackNatnet_Classes_OptitrackRigidBodyComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
