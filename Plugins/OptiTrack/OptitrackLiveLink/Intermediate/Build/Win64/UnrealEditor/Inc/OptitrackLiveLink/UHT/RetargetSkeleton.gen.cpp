// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OptitrackLiveLink/Public/RetargetSkeleton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRetargetSkeleton() {}
// Cross Module References
	OPTITRACKLIVELINK_API UEnum* Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID();
	UPackage* Z_Construct_UPackage__Script_OptitrackLiveLink();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_OptiTrackBoneID;
	static UEnum* OptiTrackBoneID_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_OptiTrackBoneID.OuterSingleton)
		{
			Z_Registration_Info_UEnum_OptiTrackBoneID.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID, (UObject*)Z_Construct_UPackage__Script_OptitrackLiveLink(), TEXT("OptiTrackBoneID"));
		}
		return Z_Registration_Info_UEnum_OptiTrackBoneID.OuterSingleton;
	}
	template<> OPTITRACKLIVELINK_API UEnum* StaticEnum<OptiTrackBoneID>()
	{
		return OptiTrackBoneID_StaticEnum();
	}
	struct Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enumerators[] = {
		{ "OptiTrackBoneID::Root", (int64)OptiTrackBoneID::Root },
		{ "OptiTrackBoneID::Hips", (int64)OptiTrackBoneID::Hips },
		{ "OptiTrackBoneID::Spine", (int64)OptiTrackBoneID::Spine },
		{ "OptiTrackBoneID::Spine1", (int64)OptiTrackBoneID::Spine1 },
		{ "OptiTrackBoneID::Neck", (int64)OptiTrackBoneID::Neck },
		{ "OptiTrackBoneID::Head", (int64)OptiTrackBoneID::Head },
		{ "OptiTrackBoneID::LeftShoulder", (int64)OptiTrackBoneID::LeftShoulder },
		{ "OptiTrackBoneID::LeftArm", (int64)OptiTrackBoneID::LeftArm },
		{ "OptiTrackBoneID::LeftForeArm", (int64)OptiTrackBoneID::LeftForeArm },
		{ "OptiTrackBoneID::LeftHand", (int64)OptiTrackBoneID::LeftHand },
		{ "OptiTrackBoneID::RightShoulder", (int64)OptiTrackBoneID::RightShoulder },
		{ "OptiTrackBoneID::RightArm", (int64)OptiTrackBoneID::RightArm },
		{ "OptiTrackBoneID::RightForeArm", (int64)OptiTrackBoneID::RightForeArm },
		{ "OptiTrackBoneID::RightHand", (int64)OptiTrackBoneID::RightHand },
		{ "OptiTrackBoneID::LeftUpLeg", (int64)OptiTrackBoneID::LeftUpLeg },
		{ "OptiTrackBoneID::LeftLeg", (int64)OptiTrackBoneID::LeftLeg },
		{ "OptiTrackBoneID::LeftFoot", (int64)OptiTrackBoneID::LeftFoot },
		{ "OptiTrackBoneID::LeftToeBase", (int64)OptiTrackBoneID::LeftToeBase },
		{ "OptiTrackBoneID::RightUpLeg", (int64)OptiTrackBoneID::RightUpLeg },
		{ "OptiTrackBoneID::RightLeg", (int64)OptiTrackBoneID::RightLeg },
		{ "OptiTrackBoneID::RightFoot", (int64)OptiTrackBoneID::RightFoot },
		{ "OptiTrackBoneID::RightToeBase", (int64)OptiTrackBoneID::RightToeBase },
		{ "OptiTrackBoneID::LeftHandThumb1", (int64)OptiTrackBoneID::LeftHandThumb1 },
		{ "OptiTrackBoneID::LeftHandThumb2", (int64)OptiTrackBoneID::LeftHandThumb2 },
		{ "OptiTrackBoneID::LeftHandThumb3", (int64)OptiTrackBoneID::LeftHandThumb3 },
		{ "OptiTrackBoneID::LeftHandIndex1", (int64)OptiTrackBoneID::LeftHandIndex1 },
		{ "OptiTrackBoneID::LeftHandIndex2", (int64)OptiTrackBoneID::LeftHandIndex2 },
		{ "OptiTrackBoneID::LeftHandIndex3", (int64)OptiTrackBoneID::LeftHandIndex3 },
		{ "OptiTrackBoneID::LeftHandMiddle1", (int64)OptiTrackBoneID::LeftHandMiddle1 },
		{ "OptiTrackBoneID::LeftHandMiddle2", (int64)OptiTrackBoneID::LeftHandMiddle2 },
		{ "OptiTrackBoneID::LeftHandMiddle3", (int64)OptiTrackBoneID::LeftHandMiddle3 },
		{ "OptiTrackBoneID::LeftHandRing1", (int64)OptiTrackBoneID::LeftHandRing1 },
		{ "OptiTrackBoneID::LeftHandRing2", (int64)OptiTrackBoneID::LeftHandRing2 },
		{ "OptiTrackBoneID::LeftHandRing3", (int64)OptiTrackBoneID::LeftHandRing3 },
		{ "OptiTrackBoneID::LeftHandPinky1", (int64)OptiTrackBoneID::LeftHandPinky1 },
		{ "OptiTrackBoneID::LeftHandPinky2", (int64)OptiTrackBoneID::LeftHandPinky2 },
		{ "OptiTrackBoneID::LeftHandPinky3", (int64)OptiTrackBoneID::LeftHandPinky3 },
		{ "OptiTrackBoneID::RightHandThumb1", (int64)OptiTrackBoneID::RightHandThumb1 },
		{ "OptiTrackBoneID::RightHandThumb2", (int64)OptiTrackBoneID::RightHandThumb2 },
		{ "OptiTrackBoneID::RightHandThumb3", (int64)OptiTrackBoneID::RightHandThumb3 },
		{ "OptiTrackBoneID::RightHandIndex1", (int64)OptiTrackBoneID::RightHandIndex1 },
		{ "OptiTrackBoneID::RightHandIndex2", (int64)OptiTrackBoneID::RightHandIndex2 },
		{ "OptiTrackBoneID::RightHandIndex3", (int64)OptiTrackBoneID::RightHandIndex3 },
		{ "OptiTrackBoneID::RightHandMiddle1", (int64)OptiTrackBoneID::RightHandMiddle1 },
		{ "OptiTrackBoneID::RightHandMiddle2", (int64)OptiTrackBoneID::RightHandMiddle2 },
		{ "OptiTrackBoneID::RightHandMiddle3", (int64)OptiTrackBoneID::RightHandMiddle3 },
		{ "OptiTrackBoneID::RightHandRing1", (int64)OptiTrackBoneID::RightHandRing1 },
		{ "OptiTrackBoneID::RightHandRing2", (int64)OptiTrackBoneID::RightHandRing2 },
		{ "OptiTrackBoneID::RightHandRing3", (int64)OptiTrackBoneID::RightHandRing3 },
		{ "OptiTrackBoneID::RightHandPinky1", (int64)OptiTrackBoneID::RightHandPinky1 },
		{ "OptiTrackBoneID::RightHandPinky2", (int64)OptiTrackBoneID::RightHandPinky2 },
		{ "OptiTrackBoneID::RightHandPinky3", (int64)OptiTrackBoneID::RightHandPinky3 },
		{ "OptiTrackBoneID::NumBones", (int64)OptiTrackBoneID::NumBones },
		{ "OptiTrackBoneID::UndefinedBone", (int64)OptiTrackBoneID::UndefinedBone },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enum_MetaDataParams[] = {
		{ "Head.Name", "OptiTrackBoneID::Head" },
		{ "Hips.Name", "OptiTrackBoneID::Hips" },
		{ "LeftArm.Name", "OptiTrackBoneID::LeftArm" },
		{ "LeftFoot.Name", "OptiTrackBoneID::LeftFoot" },
		{ "LeftForeArm.Name", "OptiTrackBoneID::LeftForeArm" },
		{ "LeftHand.Name", "OptiTrackBoneID::LeftHand" },
		{ "LeftHandIndex1.Name", "OptiTrackBoneID::LeftHandIndex1" },
		{ "LeftHandIndex2.Name", "OptiTrackBoneID::LeftHandIndex2" },
		{ "LeftHandIndex3.Name", "OptiTrackBoneID::LeftHandIndex3" },
		{ "LeftHandMiddle1.Name", "OptiTrackBoneID::LeftHandMiddle1" },
		{ "LeftHandMiddle2.Name", "OptiTrackBoneID::LeftHandMiddle2" },
		{ "LeftHandMiddle3.Name", "OptiTrackBoneID::LeftHandMiddle3" },
		{ "LeftHandPinky1.Name", "OptiTrackBoneID::LeftHandPinky1" },
		{ "LeftHandPinky2.Name", "OptiTrackBoneID::LeftHandPinky2" },
		{ "LeftHandPinky3.Name", "OptiTrackBoneID::LeftHandPinky3" },
		{ "LeftHandRing1.Name", "OptiTrackBoneID::LeftHandRing1" },
		{ "LeftHandRing2.Name", "OptiTrackBoneID::LeftHandRing2" },
		{ "LeftHandRing3.Name", "OptiTrackBoneID::LeftHandRing3" },
		{ "LeftHandThumb1.Name", "OptiTrackBoneID::LeftHandThumb1" },
		{ "LeftHandThumb2.Name", "OptiTrackBoneID::LeftHandThumb2" },
		{ "LeftHandThumb3.Name", "OptiTrackBoneID::LeftHandThumb3" },
		{ "LeftLeg.Name", "OptiTrackBoneID::LeftLeg" },
		{ "LeftShoulder.Name", "OptiTrackBoneID::LeftShoulder" },
		{ "LeftToeBase.Name", "OptiTrackBoneID::LeftToeBase" },
		{ "LeftUpLeg.Name", "OptiTrackBoneID::LeftUpLeg" },
		{ "ModuleRelativePath", "Public/RetargetSkeleton.h" },
		{ "Neck.Name", "OptiTrackBoneID::Neck" },
		{ "NumBones.Name", "OptiTrackBoneID::NumBones" },
		{ "RightArm.Name", "OptiTrackBoneID::RightArm" },
		{ "RightFoot.Name", "OptiTrackBoneID::RightFoot" },
		{ "RightForeArm.Name", "OptiTrackBoneID::RightForeArm" },
		{ "RightHand.Name", "OptiTrackBoneID::RightHand" },
		{ "RightHandIndex1.Name", "OptiTrackBoneID::RightHandIndex1" },
		{ "RightHandIndex2.Name", "OptiTrackBoneID::RightHandIndex2" },
		{ "RightHandIndex3.Name", "OptiTrackBoneID::RightHandIndex3" },
		{ "RightHandMiddle1.Name", "OptiTrackBoneID::RightHandMiddle1" },
		{ "RightHandMiddle2.Name", "OptiTrackBoneID::RightHandMiddle2" },
		{ "RightHandMiddle3.Name", "OptiTrackBoneID::RightHandMiddle3" },
		{ "RightHandPinky1.Name", "OptiTrackBoneID::RightHandPinky1" },
		{ "RightHandPinky2.Name", "OptiTrackBoneID::RightHandPinky2" },
		{ "RightHandPinky3.Name", "OptiTrackBoneID::RightHandPinky3" },
		{ "RightHandRing1.Name", "OptiTrackBoneID::RightHandRing1" },
		{ "RightHandRing2.Name", "OptiTrackBoneID::RightHandRing2" },
		{ "RightHandRing3.Name", "OptiTrackBoneID::RightHandRing3" },
		{ "RightHandThumb1.Name", "OptiTrackBoneID::RightHandThumb1" },
		{ "RightHandThumb2.Name", "OptiTrackBoneID::RightHandThumb2" },
		{ "RightHandThumb3.Name", "OptiTrackBoneID::RightHandThumb3" },
		{ "RightLeg.Name", "OptiTrackBoneID::RightLeg" },
		{ "RightShoulder.Name", "OptiTrackBoneID::RightShoulder" },
		{ "RightToeBase.Name", "OptiTrackBoneID::RightToeBase" },
		{ "RightUpLeg.Name", "OptiTrackBoneID::RightUpLeg" },
		{ "Root.Name", "OptiTrackBoneID::Root" },
		{ "Spine.Name", "OptiTrackBoneID::Spine" },
		{ "Spine1.Name", "OptiTrackBoneID::Spine1" },
		{ "UndefinedBone.Name", "OptiTrackBoneID::UndefinedBone" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OptitrackLiveLink,
		nullptr,
		"OptiTrackBoneID",
		"OptiTrackBoneID",
		Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID()
	{
		if (!Z_Registration_Info_UEnum_OptiTrackBoneID.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_OptiTrackBoneID.InnerSingleton, Z_Construct_UEnum_OptitrackLiveLink_OptiTrackBoneID_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_OptiTrackBoneID.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h_Statics::EnumInfo[] = {
		{ OptiTrackBoneID_StaticEnum, TEXT("OptiTrackBoneID"), &Z_Registration_Info_UEnum_OptiTrackBoneID, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1682939569U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h_1039980477(TEXT("/Script/OptitrackLiveLink"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jacob_marroquin_Desktop_OptitrackLiveLink_HostProject_Plugins_OptitrackLiveLink_Source_OptitrackLiveLink_Public_RetargetSkeleton_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
