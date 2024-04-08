// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackLiveLink/Public/LiveLinkNatNetSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiveLinkNatNetSettings() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	LIVELINKINTERFACE_API UClass* Z_Construct_UClass_ULiveLinkSourceSettings();
	OPTITRACKLIVELINK_API UClass* Z_Construct_UClass_UOptitrackLiveLinkSourceSettings();
	OPTITRACKLIVELINK_API UClass* Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_NoRegister();
	OPTITRACKLIVELINK_API UEnum* Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType();
	UPackage* Z_Construct_UPackage__Script_OptitrackLiveLink();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType;
	static UEnum* EOptitrackLiveLinkConnectionType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType, (UObject*)Z_Construct_UPackage__Script_OptitrackLiveLink(), TEXT("EOptitrackLiveLinkConnectionType"));
		}
		return Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.OuterSingleton;
	}
	template<> OPTITRACKLIVELINK_API UEnum* StaticEnum<EOptitrackLiveLinkConnectionType>()
	{
		return EOptitrackLiveLinkConnectionType_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enumerators[] = {
		{ "EOptitrackLiveLinkConnectionType::Multicast", (int64)EOptitrackLiveLinkConnectionType::Multicast },
		{ "EOptitrackLiveLinkConnectionType::Unicast", (int64)EOptitrackLiveLinkConnectionType::Unicast },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "Multicast.DisplayName", "Multicast" },
		{ "Multicast.Name", "EOptitrackLiveLinkConnectionType::Multicast" },
		{ "Unicast.DisplayName", "Unicast" },
		{ "Unicast.Name", "EOptitrackLiveLinkConnectionType::Unicast" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackLiveLink,
		nullptr,
		"EOptitrackLiveLinkConnectionType",
		"EOptitrackLiveLinkConnectionType",
		Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType()
	{
		if (!Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.InnerSingleton, Z_Construct_UEnum_OptitrackLiveLink_EOptitrackLiveLinkConnectionType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType.InnerSingleton;
	}
	void UOptitrackLiveLinkSourceSettings::StaticRegisterNativesUOptitrackLiveLinkSourceSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOptitrackLiveLinkSourceSettings);
	UClass* Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_NoRegister()
	{
		return UOptitrackLiveLinkSourceSettings::StaticClass();
	}
	struct Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CreateLabeledMarkerSubjects_MetaData[];
#endif
		static void NewProp_CreateLabeledMarkerSubjects_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CreateLabeledMarkerSubjects;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CreateUnlabeledMarkerSubjects_MetaData[];
#endif
		static void NewProp_CreateUnlabeledMarkerSubjects_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CreateUnlabeledMarkerSubjects;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimecodeProvider_MetaData[];
#endif
		static void NewProp_TimecodeProvider_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_TimecodeProvider;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubjectName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SubjectName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkSourceSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_OptitrackLiveLink,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Live link streaming settings */" },
		{ "IncludePath", "LiveLinkNatNetSettings.h" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Live link streaming settings" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "StreamedDataOffset" },
		{ "Comment", "/** Origin of streamed data. */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Origin of streamed data." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackLiveLinkSourceSettings, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Location_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Location_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Orientation_MetaData[] = {
		{ "Category", "StreamedDataOffset" },
		{ "Comment", "/** Orientation of streamed data. */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Orientation of streamed data." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackLiveLinkSourceSettings, Orientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Orientation_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Orientation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Scale_MetaData[] = {
		{ "Category", "StreamedDataOffset" },
		{ "Comment", "/** Scale of streamed data. */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Scale of streamed data." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackLiveLinkSourceSettings, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Scale_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects_MetaData[] = {
		{ "Category", "Markers" },
		{ "Comment", "/** Whether to create LiveLink subjects for labeled markers */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Whether to create LiveLink subjects for labeled markers" },
	};
#endif
	void Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects_SetBit(void* Obj)
	{
		((UOptitrackLiveLinkSourceSettings*)Obj)->CreateLabeledMarkerSubjects = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects = { "CreateLabeledMarkerSubjects", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackLiveLinkSourceSettings), &Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects_MetaData[] = {
		{ "Category", "Markers" },
		{ "Comment", "/** Whether to create LiveLink subjects for unlabeled markers */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Whether to create LiveLink subjects for unlabeled markers" },
	};
#endif
	void Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects_SetBit(void* Obj)
	{
		((UOptitrackLiveLinkSourceSettings*)Obj)->CreateUnlabeledMarkerSubjects = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects = { "CreateUnlabeledMarkerSubjects", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackLiveLinkSourceSettings), &Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider_MetaData[] = {
		{ "Category", "TimecodeProvider" },
		{ "Comment", "/** Set LiveLink as timecode provider */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Set LiveLink as timecode provider" },
	};
#endif
	void Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider_SetBit(void* Obj)
	{
		((UOptitrackLiveLinkSourceSettings*)Obj)->TimecodeProvider = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider = { "TimecodeProvider", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOptitrackLiveLinkSourceSettings), &Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_SubjectName_MetaData[] = {
		{ "Category", "TimecodeProvider" },
		{ "Comment", "/** Timecode provider subject name */" },
		{ "ModuleRelativePath", "Public/LiveLinkNatNetSettings.h" },
		{ "ToolTip", "Timecode provider subject name" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_SubjectName = { "SubjectName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOptitrackLiveLinkSourceSettings, SubjectName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_SubjectName_MetaData), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_SubjectName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_Scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateLabeledMarkerSubjects,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_CreateUnlabeledMarkerSubjects,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_TimecodeProvider,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::NewProp_SubjectName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOptitrackLiveLinkSourceSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::ClassParams = {
		&UOptitrackLiveLinkSourceSettings::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOptitrackLiveLinkSourceSettings()
	{
		if (!Z_Registration_Info_UClass_UOptitrackLiveLinkSourceSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOptitrackLiveLinkSourceSettings.OuterSingleton, Z_Construct_UClass_UOptitrackLiveLinkSourceSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOptitrackLiveLinkSourceSettings.OuterSingleton;
	}
	template<> OPTITRACKLIVELINK_API UClass* StaticClass<UOptitrackLiveLinkSourceSettings>()
	{
		return UOptitrackLiveLinkSourceSettings::StaticClass();
	}
	UOptitrackLiveLinkSourceSettings::UOptitrackLiveLinkSourceSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOptitrackLiveLinkSourceSettings);
	UOptitrackLiveLinkSourceSettings::~UOptitrackLiveLinkSourceSettings() {}
	struct Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::EnumInfo[] = {
		{ EOptitrackLiveLinkConnectionType_StaticEnum, TEXT("EOptitrackLiveLinkConnectionType"), &Z_Registration_Info_UEnum_EOptitrackLiveLinkConnectionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 558092275U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOptitrackLiveLinkSourceSettings, UOptitrackLiveLinkSourceSettings::StaticClass, TEXT("UOptitrackLiveLinkSourceSettings"), &Z_Registration_Info_UClass_UOptitrackLiveLinkSourceSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOptitrackLiveLinkSourceSettings), 163399319U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_2139418728(TEXT("/Script/OptitrackLiveLink"),
		Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_LiveLinkNatNetSettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
