//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#include "OptitrackSkeletonTypes.h"

#define LOCTEXT_NAMESPACE "OptitrackNatnet"

FText GetDisplayBoneName( EOptitrackBone BoneId )
{
	switch ( BoneId )
	{
	case EOptitrackBone::Root:      return LOCTEXT( "BoneDisplayName_Root",      "Root" );
	case EOptitrackBone::Hip:       return LOCTEXT( "BoneDisplayName_Hip",       "Hip" );
	case EOptitrackBone::Ab:        return LOCTEXT( "BoneDisplayName_Ab",        "Ab" );
	case EOptitrackBone::Chest:     return LOCTEXT( "BoneDisplayName_Chest",     "Chest" );
	case EOptitrackBone::Neck:      return LOCTEXT( "BoneDisplayName_Neck",      "Neck" );
	case EOptitrackBone::Head:      return LOCTEXT( "BoneDisplayName_Head",      "Head" );
	case EOptitrackBone::LShoulder: return LOCTEXT( "BoneDisplayName_LShoulder", "Left Shoulder" );
	case EOptitrackBone::LUArm:     return LOCTEXT( "BoneDisplayName_LUArm",     "Left Upper Arm" );
	case EOptitrackBone::LFArm:     return LOCTEXT( "BoneDisplayName_LFArm",     "Left Forearm" );
	case EOptitrackBone::LHand:     return LOCTEXT( "BoneDisplayName_LHand",     "Left Hand" );
	case EOptitrackBone::RShoulder: return LOCTEXT( "BoneDisplayName_RShoulder", "Right Shoulder" );
	case EOptitrackBone::RUArm:     return LOCTEXT( "BoneDisplayName_RUArm",     "Right Upper Arm" );
	case EOptitrackBone::RFArm:     return LOCTEXT( "BoneDisplayName_RFArm",     "Right Forearm" );
	case EOptitrackBone::RHand:     return LOCTEXT( "BoneDisplayName_RHand",     "Right Hand" );
	case EOptitrackBone::LThigh:    return LOCTEXT( "BoneDisplayName_LThigh",    "Left Thigh" );
	case EOptitrackBone::LShin:     return LOCTEXT( "BoneDisplayName_LShin",     "Left Shin" );
	case EOptitrackBone::LFoot:     return LOCTEXT( "BoneDisplayName_LFoot",     "Left Foot" );
	case EOptitrackBone::LToe:      return LOCTEXT( "BoneDisplayName_LToe",      "Left Toe" );
	case EOptitrackBone::RThigh:    return LOCTEXT( "BoneDisplayName_RThigh",    "Right Thigh" );
	case EOptitrackBone::RShin:     return LOCTEXT( "BoneDisplayName_RShin",     "Right Shin" );
	case EOptitrackBone::RFoot:     return LOCTEXT( "BoneDisplayName_RFoot",     "Right Foot" );
	case EOptitrackBone::RToe:      return LOCTEXT( "BoneDisplayName_RToe",      "Right Toe" );
	case EOptitrackBone::LThumb1:   return LOCTEXT( "BoneDisplayName_LThumb1",   "Left Thumb 1" );
	case EOptitrackBone::LThumb2:   return LOCTEXT( "BoneDisplayName_LThumb2",   "Left Thumb 2" );
	case EOptitrackBone::LThumb3:   return LOCTEXT( "BoneDisplayName_LThumb3",   "Left Thumb 3" );
	case EOptitrackBone::LIndex1:   return LOCTEXT( "BoneDisplayName_LIndex1",   "Left Index 1" );
	case EOptitrackBone::LIndex2:   return LOCTEXT( "BoneDisplayName_LIndex2",   "Left Index 2" );
	case EOptitrackBone::LIndex3:   return LOCTEXT( "BoneDisplayName_LIndex3",   "Left Index 3" );
	case EOptitrackBone::LMiddle1:  return LOCTEXT( "BoneDisplayName_LMiddle1",  "Left Middle 1" );
	case EOptitrackBone::LMiddle2:  return LOCTEXT( "BoneDisplayName_LMiddle2",  "Left Middle 2" );
	case EOptitrackBone::LMiddle3:  return LOCTEXT( "BoneDisplayName_LMiddle3",  "Left Middle 3" );
	case EOptitrackBone::LRing1:    return LOCTEXT( "BoneDisplayName_LRing1",    "Left Ring 1" );
	case EOptitrackBone::LRing2:    return LOCTEXT( "BoneDisplayName_LRing2",    "Left Ring 2" );
	case EOptitrackBone::LRing3:    return LOCTEXT( "BoneDisplayName_LRing3",    "Left Ring 3" );
	case EOptitrackBone::LPinky1:   return LOCTEXT( "BoneDisplayName_LPinky1",   "Left Pinky 1" );
	case EOptitrackBone::LPinky2:   return LOCTEXT( "BoneDisplayName_LPinky2",   "Left Pinky 2" );
	case EOptitrackBone::LPinky3:   return LOCTEXT( "BoneDisplayName_LPinky3",   "Left Pinky 3" );
	case EOptitrackBone::RThumb1:   return LOCTEXT( "BoneDisplayName_RThumb1",   "Right Thumb 1" );
	case EOptitrackBone::RThumb2:   return LOCTEXT( "BoneDisplayName_RThumb2",   "Right Thumb 2" );
	case EOptitrackBone::RThumb3:   return LOCTEXT( "BoneDisplayName_RThumb3",   "Right Thumb 3" );
	case EOptitrackBone::RIndex1:   return LOCTEXT( "BoneDisplayName_RIndex1",   "Right Index 1" );
	case EOptitrackBone::RIndex2:   return LOCTEXT( "BoneDisplayName_RIndex2",   "Right Index 2" );
	case EOptitrackBone::RIndex3:   return LOCTEXT( "BoneDisplayName_RIndex3",   "Right Index 3" );
	case EOptitrackBone::RMiddle1:  return LOCTEXT( "BoneDisplayName_RMiddle1",  "Right Middle 1" );
	case EOptitrackBone::RMiddle2:  return LOCTEXT( "BoneDisplayName_RMiddle2",  "Right Middle 2" );
	case EOptitrackBone::RMiddle3:  return LOCTEXT( "BoneDisplayName_RMiddle3",  "Right Middle 3" );
	case EOptitrackBone::RRing1:    return LOCTEXT( "BoneDisplayName_RRing1",    "Right Ring 1" );
	case EOptitrackBone::RRing2:    return LOCTEXT( "BoneDisplayName_RRing2",    "Right Ring 2" );
	case EOptitrackBone::RRing3:    return LOCTEXT( "BoneDisplayName_RRing3",    "Right Ring 3" );
	case EOptitrackBone::RPinky1:   return LOCTEXT( "BoneDisplayName_RPinky1",   "Right Pinky 1" );
	case EOptitrackBone::RPinky2:   return LOCTEXT( "BoneDisplayName_RPinky2",   "Right Pinky 2" );
	case EOptitrackBone::RPinky3:   return LOCTEXT( "BoneDisplayName_RPinky3",   "Right Pinky 3" );
	}

	return LOCTEXT( "BoneDisplayName_Invalid", "(Invalid Bone)" );
}


// Based on CBone::IDtoName.
//
// Search:
//   case EOptitrackBone::([A-Za-z0-9]+):(\s*)wcscpy_s\( szName, iMax, L"([A-Za-z0-9]+)" \); break;
//
// Replace:
//  case EOptitrackBone::$1:$2{ static FName $1Name( "$3" ); return $1Name; break; }

FName GetStreamingBoneName( EOptitrackBone BoneId, EOptitrackBoneNamingConvention NamingConvention )
{
	if ( BoneId == EOptitrackBone::Root )
	{
		static FName RootName( "Root" );
		return RootName;
	}

	if ( NamingConvention == EOptitrackBoneNamingConvention::Motive )
	{
		switch ( BoneId )
		{
		case EOptitrackBone::Hip:       { static FName HipName( "Hip" ); return HipName; break; }
		case EOptitrackBone::Ab:        { static FName AbName( "Ab" ); return AbName; break; }
		case EOptitrackBone::Chest:     { static FName ChestName( "Chest" ); return ChestName; break; }
		case EOptitrackBone::Neck:      { static FName NeckName( "Neck" ); return NeckName; break; }
		case EOptitrackBone::Head:      { static FName HeadName( "Head" ); return HeadName; break; }
		case EOptitrackBone::LShoulder: { static FName LShoulderName( "LShoulder" ); return LShoulderName; break; }
		case EOptitrackBone::LUArm:     { static FName LUArmName( "LUArm" ); return LUArmName; break; }
		case EOptitrackBone::LFArm:     { static FName LFArmName( "LFArm" ); return LFArmName; break; }
		case EOptitrackBone::LHand:     { static FName LHandName( "LHand" ); return LHandName; break; }
		case EOptitrackBone::RShoulder: { static FName RShoulderName( "RShoulder" ); return RShoulderName; break; }
		case EOptitrackBone::RUArm:     { static FName RUArmName( "RUArm" ); return RUArmName; break; }
		case EOptitrackBone::RFArm:     { static FName RFArmName( "RFArm" ); return RFArmName; break; }
		case EOptitrackBone::RHand:     { static FName RHandName( "RHand" ); return RHandName; break; }
		case EOptitrackBone::LThigh:    { static FName LThighName( "LThigh" ); return LThighName; break; }
		case EOptitrackBone::LShin:     { static FName LShinName( "LShin" ); return LShinName; break; }
		case EOptitrackBone::LFoot:     { static FName LFootName( "LFoot" ); return LFootName; break; }
		case EOptitrackBone::LToe:      { static FName LToeName( "LToe" ); return LToeName; break; }
		case EOptitrackBone::RThigh:    { static FName RThighName( "RThigh" ); return RThighName; break; }
		case EOptitrackBone::RShin:     { static FName RShinName( "RShin" ); return RShinName; break; }
		case EOptitrackBone::RFoot:     { static FName RFootName( "RFoot" ); return RFootName; break; }
		case EOptitrackBone::RToe:      { static FName RToeName( "RToe" ); return RToeName; break; }
		case EOptitrackBone::LThumb1:   { static FName LThumb1Name( "LThumb1" ); return LThumb1Name; break; }
		case EOptitrackBone::LThumb2:   { static FName LThumb2Name( "LThumb2" ); return LThumb2Name; break; }
		case EOptitrackBone::LThumb3:   { static FName LThumb3Name( "LThumb3" ); return LThumb3Name; break; }
		case EOptitrackBone::LIndex1:   { static FName LIndex1Name( "LIndex1" ); return LIndex1Name; break; }
		case EOptitrackBone::LIndex2:   { static FName LIndex2Name( "LIndex2" ); return LIndex2Name; break; }
		case EOptitrackBone::LIndex3:   { static FName LIndex3Name( "LIndex3" ); return LIndex3Name; break; }
		case EOptitrackBone::LMiddle1:  { static FName LMiddle1Name( "LMiddle1" ); return LMiddle1Name; break; }
		case EOptitrackBone::LMiddle2:  { static FName LMiddle2Name( "LMiddle2" ); return LMiddle2Name; break; }
		case EOptitrackBone::LMiddle3:  { static FName LMiddle3Name( "LMiddle3" ); return LMiddle3Name; break; }
		case EOptitrackBone::LRing1:    { static FName LRing1Name( "LRing1" ); return LRing1Name; break; }
		case EOptitrackBone::LRing2:    { static FName LRing2Name( "LRing2" ); return LRing2Name; break; }
		case EOptitrackBone::LRing3:    { static FName LRing3Name( "LRing3" ); return LRing3Name; break; }
		case EOptitrackBone::LPinky1:   { static FName LPinky1Name( "LPinky1" ); return LPinky1Name; break; }
		case EOptitrackBone::LPinky2:   { static FName LPinky2Name( "LPinky2" ); return LPinky2Name; break; }
		case EOptitrackBone::LPinky3:   { static FName LPinky3Name( "LPinky3" ); return LPinky3Name; break; }
		case EOptitrackBone::RThumb1:   { static FName RThumb1Name( "RThumb1" ); return RThumb1Name; break; }
		case EOptitrackBone::RThumb2:   { static FName RThumb2Name( "RThumb2" ); return RThumb2Name; break; }
		case EOptitrackBone::RThumb3:   { static FName RThumb3Name( "RThumb3" ); return RThumb3Name; break; }
		case EOptitrackBone::RIndex1:   { static FName RIndex1Name( "RIndex1" ); return RIndex1Name; break; }
		case EOptitrackBone::RIndex2:   { static FName RIndex2Name( "RIndex2" ); return RIndex2Name; break; }
		case EOptitrackBone::RIndex3:   { static FName RIndex3Name( "RIndex3" ); return RIndex3Name; break; }
		case EOptitrackBone::RMiddle1:  { static FName RMiddle1Name( "RMiddle1" ); return RMiddle1Name; break; }
		case EOptitrackBone::RMiddle2:  { static FName RMiddle2Name( "RMiddle2" ); return RMiddle2Name; break; }
		case EOptitrackBone::RMiddle3:  { static FName RMiddle3Name( "RMiddle3" ); return RMiddle3Name; break; }
		case EOptitrackBone::RRing1:    { static FName RRing1Name( "RRing1" ); return RRing1Name; break; }
		case EOptitrackBone::RRing2:    { static FName RRing2Name( "RRing2" ); return RRing2Name; break; }
		case EOptitrackBone::RRing3:    { static FName RRing3Name( "RRing3" ); return RRing3Name; break; }
		case EOptitrackBone::RPinky1:   { static FName RPinky1Name( "RPinky1" ); return RPinky1Name; break; }
		case EOptitrackBone::RPinky2:   { static FName RPinky2Name( "RPinky2" ); return RPinky2Name; break; }
		case EOptitrackBone::RPinky3:   { static FName RPinky3Name( "RPinky3" ); return RPinky3Name; break; }
		}
	}
	else if ( NamingConvention == EOptitrackBoneNamingConvention::FBX )
	{
		switch ( BoneId )
		{
		case EOptitrackBone::Hip:       { static FName HipName( "Hips" ); return HipName; break; }
		case EOptitrackBone::Ab:        { static FName AbName( "Spine" ); return AbName; break; }
		case EOptitrackBone::Chest:     { static FName ChestName( "Spine1" ); return ChestName; break; }
		case EOptitrackBone::Neck:      { static FName NeckName( "Neck" ); return NeckName; break; }
		case EOptitrackBone::Head:      { static FName HeadName( "Head" ); return HeadName; break; }
		case EOptitrackBone::LShoulder: { static FName LShoulderName( "LeftShoulder" ); return LShoulderName; break; }
		case EOptitrackBone::LUArm:     { static FName LUArmName( "LeftArm" ); return LUArmName; break; }
		case EOptitrackBone::LFArm:     { static FName LFArmName( "LeftForeArm" ); return LFArmName; break; }
		case EOptitrackBone::LHand:     { static FName LHandName( "LeftHand" ); return LHandName; break; }
		case EOptitrackBone::RShoulder: { static FName RShoulderName( "RightShoulder" ); return RShoulderName; break; }
		case EOptitrackBone::RUArm:     { static FName RUArmName( "RightArm" ); return RUArmName; break; }
		case EOptitrackBone::RFArm:     { static FName RFArmName( "RightForeArm" ); return RFArmName; break; }
		case EOptitrackBone::RHand:     { static FName RHandName( "RightHand" ); return RHandName; break; }
		case EOptitrackBone::LThigh:    { static FName LThighName( "LeftUpLeg" ); return LThighName; break; }
		case EOptitrackBone::LShin:     { static FName LShinName( "LeftLeg" ); return LShinName; break; }
		case EOptitrackBone::LFoot:     { static FName LFootName( "LeftFoot" ); return LFootName; break; }
		case EOptitrackBone::LToe:      { static FName LToeName( "LeftToeBase" ); return LToeName; break; }
		case EOptitrackBone::RThigh:    { static FName RThighName( "RightUpLeg" ); return RThighName; break; }
		case EOptitrackBone::RShin:     { static FName RShinName( "RightLeg" ); return RShinName; break; }
		case EOptitrackBone::RFoot:     { static FName RFootName( "RightFoot" ); return RFootName; break; }
		case EOptitrackBone::RToe:      { static FName RToeName( "RightToeBase" ); return RToeName; break; }
		case EOptitrackBone::LThumb1:   { static FName LThumb1Name( "LeftHandThumb1" ); return LThumb1Name; break; }
		case EOptitrackBone::LThumb2:   { static FName LThumb2Name( "LeftHandThumb2" ); return LThumb2Name; break; }
		case EOptitrackBone::LThumb3:   { static FName LThumb3Name( "LeftHandThumb3" ); return LThumb3Name; break; }
		case EOptitrackBone::LIndex1:   { static FName LIndex1Name( "LeftHandIndex1" ); return LIndex1Name; break; }
		case EOptitrackBone::LIndex2:   { static FName LIndex2Name( "LeftHandIndex2" ); return LIndex2Name; break; }
		case EOptitrackBone::LIndex3:   { static FName LIndex3Name( "LeftHandIndex3" ); return LIndex3Name; break; }
		case EOptitrackBone::LMiddle1:  { static FName LMiddle1Name( "LeftHandMiddle1" ); return LMiddle1Name; break; }
		case EOptitrackBone::LMiddle2:  { static FName LMiddle2Name( "LeftHandMiddle2" ); return LMiddle2Name; break; }
		case EOptitrackBone::LMiddle3:  { static FName LMiddle3Name( "LeftHandMiddle3" ); return LMiddle3Name; break; }
		case EOptitrackBone::LRing1:    { static FName LRing1Name( "LeftHandRing1" ); return LRing1Name; break; }
		case EOptitrackBone::LRing2:    { static FName LRing2Name( "LeftHandRing2" ); return LRing2Name; break; }
		case EOptitrackBone::LRing3:    { static FName LRing3Name( "LeftHandRing3" ); return LRing3Name; break; }
		case EOptitrackBone::LPinky1:   { static FName LPinky1Name( "LeftHandPinky1" ); return LPinky1Name; break; }
		case EOptitrackBone::LPinky2:   { static FName LPinky2Name( "LeftHandPinky2" ); return LPinky2Name; break; }
		case EOptitrackBone::LPinky3:   { static FName LPinky3Name( "LeftHandPinky3" ); return LPinky3Name; break; }
		case EOptitrackBone::RThumb1:   { static FName RThumb1Name( "RightHandThumb1" ); return RThumb1Name; break; }
		case EOptitrackBone::RThumb2:   { static FName RThumb2Name( "RightHandThumb2" ); return RThumb2Name; break; }
		case EOptitrackBone::RThumb3:   { static FName RThumb3Name( "RightHandThumb3" ); return RThumb3Name; break; }
		case EOptitrackBone::RIndex1:   { static FName RIndex1Name( "RightHandIndex1" ); return RIndex1Name; break; }
		case EOptitrackBone::RIndex2:   { static FName RIndex2Name( "RightHandIndex2" ); return RIndex2Name; break; }
		case EOptitrackBone::RIndex3:   { static FName RIndex3Name( "RightHandIndex3" ); return RIndex3Name; break; }
		case EOptitrackBone::RMiddle1:  { static FName RMiddle1Name( "RightHandMiddle1" ); return RMiddle1Name; break; }
		case EOptitrackBone::RMiddle2:  { static FName RMiddle2Name( "RightHandMiddle2" ); return RMiddle2Name; break; }
		case EOptitrackBone::RMiddle3:  { static FName RMiddle3Name( "RightHandMiddle3" ); return RMiddle3Name; break; }
		case EOptitrackBone::RRing1:    { static FName RRing1Name( "RightHandRing1" ); return RRing1Name; break; }
		case EOptitrackBone::RRing2:    { static FName RRing2Name( "RightHandRing2" ); return RRing2Name; break; }
		case EOptitrackBone::RRing3:    { static FName RRing3Name( "RightHandRing3" ); return RRing3Name; break; }
		case EOptitrackBone::RPinky1:   { static FName RPinky1Name( "RightHandPinky1" ); return RPinky1Name; break; }
		case EOptitrackBone::RPinky2:   { static FName RPinky2Name( "RightHandPinky2" ); return RPinky2Name; break; }
		case EOptitrackBone::RPinky3:   { static FName RPinky3Name( "RightHandPinky3" ); return RPinky3Name; break; }
		}
	}
	else if ( NamingConvention == EOptitrackBoneNamingConvention::BVH )
	{
		switch ( BoneId )
		{
		case EOptitrackBone::Hip:       { static FName HipName( "Hips" ); return HipName; break; }
		case EOptitrackBone::Ab:        { static FName AbName( "Chest" ); return AbName; break; }
		case EOptitrackBone::Chest:     { static FName ChestName( "Chest2" ); return ChestName; break; }
		case EOptitrackBone::Neck:      { static FName NeckName( "Neck" ); return NeckName; break; }
		case EOptitrackBone::Head:      { static FName HeadName( "Head" ); return HeadName; break; }
		case EOptitrackBone::LShoulder: { static FName LShoulderName( "LeftCollar" ); return LShoulderName; break; }
		case EOptitrackBone::LUArm:     { static FName LUArmName( "LeftShoulder" ); return LUArmName; break; }
		case EOptitrackBone::LFArm:     { static FName LFArmName( "LeftElbow" ); return LFArmName; break; }
		case EOptitrackBone::LHand:     { static FName LHandName( "LeftWrist" ); return LHandName; break; }
		case EOptitrackBone::RShoulder: { static FName RShoulderName( "RightCollar" ); return RShoulderName; break; }
		case EOptitrackBone::RUArm:     { static FName RUArmName( "RightShoulder" ); return RUArmName; break; }
		case EOptitrackBone::RFArm:     { static FName RFArmName( "RightElbow" ); return RFArmName; break; }
		case EOptitrackBone::RHand:     { static FName RHandName( "RightWrist" ); return RHandName; break; }
		case EOptitrackBone::LThigh:    { static FName LThighName( "LeftHip" ); return LThighName; break; }
		case EOptitrackBone::LShin:     { static FName LShinName( "LeftKnee" ); return LShinName; break; }
		case EOptitrackBone::LFoot:     { static FName LFootName( "LeftAnkle" ); return LFootName; break; }
		case EOptitrackBone::LToe:      { static FName LToeName( "LeftToe" ); return LToeName; break; }
		case EOptitrackBone::RThigh:    { static FName RThighName( "RightHip" ); return RThighName; break; }
		case EOptitrackBone::RShin:     { static FName RShinName( "RightKnee" ); return RShinName; break; }
		case EOptitrackBone::RFoot:     { static FName RFootName( "RightAnkle" ); return RFootName; break; }
		case EOptitrackBone::RToe:      { static FName RToeName( "RightToe" ); return RToeName; break; }
		case EOptitrackBone::LThumb1:   { static FName LThumb1Name( "LeftFinger0" ); return LThumb1Name; break; }
		case EOptitrackBone::LThumb2:   { static FName LThumb2Name( "LeftFinger01" ); return LThumb2Name; break; }
		case EOptitrackBone::LThumb3:   { static FName LThumb3Name( "LeftFinger02" ); return LThumb3Name; break; }
		case EOptitrackBone::LIndex1:   { static FName LIndex1Name( "LeftFinger1" ); return LIndex1Name; break; }
		case EOptitrackBone::LIndex2:   { static FName LIndex2Name( "LeftFinger11" ); return LIndex2Name; break; }
		case EOptitrackBone::LIndex3:   { static FName LIndex3Name( "LeftFinger12" ); return LIndex3Name; break; }
		case EOptitrackBone::LMiddle1:  { static FName LMiddle1Name( "LeftFinger2" ); return LMiddle1Name; break; }
		case EOptitrackBone::LMiddle2:  { static FName LMiddle2Name( "LeftFinger21" ); return LMiddle2Name; break; }
		case EOptitrackBone::LMiddle3:  { static FName LMiddle3Name( "LeftFinger22" ); return LMiddle3Name; break; }
		case EOptitrackBone::LRing1:    { static FName LRing1Name( "LeftFinger3" ); return LRing1Name; break; }
		case EOptitrackBone::LRing2:    { static FName LRing2Name( "LeftFinger31" ); return LRing2Name; break; }
		case EOptitrackBone::LRing3:    { static FName LRing3Name( "LeftFinger32" ); return LRing3Name; break; }
		case EOptitrackBone::LPinky1:   { static FName LPinky1Name( "LeftFinger4" ); return LPinky1Name; break; }
		case EOptitrackBone::LPinky2:   { static FName LPinky2Name( "LeftFinger41" ); return LPinky2Name; break; }
		case EOptitrackBone::LPinky3:   { static FName LPinky3Name( "LeftFinger42" ); return LPinky3Name; break; }
		case EOptitrackBone::RThumb1:   { static FName RThumb1Name( "RightFinger0" ); return RThumb1Name; break; }
		case EOptitrackBone::RThumb2:   { static FName RThumb2Name( "RightFinger01" ); return RThumb2Name; break; }
		case EOptitrackBone::RThumb3:   { static FName RThumb3Name( "RightFinger02" ); return RThumb3Name; break; }
		case EOptitrackBone::RIndex1:   { static FName RIndex1Name( "RightFinger1" ); return RIndex1Name; break; }
		case EOptitrackBone::RIndex2:   { static FName RIndex2Name( "RightFinger11" ); return RIndex2Name; break; }
		case EOptitrackBone::RIndex3:   { static FName RIndex3Name( "RightFinger12" ); return RIndex3Name; break; }
		case EOptitrackBone::RMiddle1:  { static FName RMiddle1Name( "RightFinger2" ); return RMiddle1Name; break; }
		case EOptitrackBone::RMiddle2:  { static FName RMiddle2Name( "RightFinger21" ); return RMiddle2Name; break; }
		case EOptitrackBone::RMiddle3:  { static FName RMiddle3Name( "RightFinger22" ); return RMiddle3Name; break; }
		case EOptitrackBone::RRing1:    { static FName RRing1Name( "RightFinger3" ); return RRing1Name; break; }
		case EOptitrackBone::RRing2:    { static FName RRing2Name( "RightFinger31" ); return RRing2Name; break; }
		case EOptitrackBone::RRing3:    { static FName RRing3Name( "RightFinger32" ); return RRing3Name; break; }
		case EOptitrackBone::RPinky1:   { static FName RPinky1Name( "RightFinger4" ); return RPinky1Name; break; }
		case EOptitrackBone::RPinky2:   { static FName RPinky2Name( "RightFinger41" ); return RPinky2Name; break; }
		case EOptitrackBone::RPinky3:   { static FName RPinky3Name( "RightFinger42" ); return RPinky3Name; break; }
		}
	}

	return NAME_None;
}


EOptitrackBone GetParentBone( EOptitrackBone BoneId )
{
	switch ( BoneId )
	{
	case EOptitrackBone::Root: return EOptitrackBone::Root;
	case EOptitrackBone::Hip: return EOptitrackBone::Root;
	case EOptitrackBone::Ab: return EOptitrackBone::Hip;
	case EOptitrackBone::Chest: return EOptitrackBone::Ab;
	case EOptitrackBone::Neck: return EOptitrackBone::Chest;
	case EOptitrackBone::Head: return EOptitrackBone::Neck;
	case EOptitrackBone::LShoulder: return EOptitrackBone::Chest;
	case EOptitrackBone::LUArm: return EOptitrackBone::LShoulder;
	case EOptitrackBone::LFArm: return EOptitrackBone::LUArm;
	case EOptitrackBone::LHand: return EOptitrackBone::LFArm;
	case EOptitrackBone::RShoulder: return EOptitrackBone::Chest;
	case EOptitrackBone::RUArm: return EOptitrackBone::RShoulder;
	case EOptitrackBone::RFArm: return EOptitrackBone::RUArm;
	case EOptitrackBone::RHand: return EOptitrackBone::RFArm;
	case EOptitrackBone::LThigh: return EOptitrackBone::Hip;
	case EOptitrackBone::LShin: return EOptitrackBone::LThigh;
	case EOptitrackBone::LFoot: return EOptitrackBone::LShin;
    case EOptitrackBone::LToe: return EOptitrackBone::LFoot;
	case EOptitrackBone::RThigh: return EOptitrackBone::Hip;
	case EOptitrackBone::RShin: return EOptitrackBone::RThigh;
	case EOptitrackBone::RFoot: return EOptitrackBone::RShin;
    case EOptitrackBone::RToe: return EOptitrackBone::RFoot;
    case EOptitrackBone::LThumb1: return EOptitrackBone::LHand;
    case EOptitrackBone::LThumb2:   return EOptitrackBone::LThumb1;
    case EOptitrackBone::LThumb3:   return EOptitrackBone::LThumb2;
    case EOptitrackBone::LIndex1:return EOptitrackBone::LHand;
    case EOptitrackBone::LIndex2:return EOptitrackBone::LIndex1;
    case EOptitrackBone::LIndex3:return EOptitrackBone::LIndex2;
    case EOptitrackBone::LMiddle1:return EOptitrackBone::LHand;
    case EOptitrackBone::LMiddle2:return EOptitrackBone::LMiddle1;
    case EOptitrackBone::LMiddle3:return EOptitrackBone::LMiddle2;
    case EOptitrackBone::LRing1:return EOptitrackBone::LHand;
    case EOptitrackBone::LRing2:return EOptitrackBone::LRing1;
    case EOptitrackBone::LRing3:return EOptitrackBone::LRing2;
    case EOptitrackBone::LPinky1:return EOptitrackBone::LHand;
    case EOptitrackBone::LPinky2: return EOptitrackBone::LPinky1;
    case EOptitrackBone::LPinky3: return EOptitrackBone::LPinky2;
    case EOptitrackBone::RThumb1: return EOptitrackBone::RHand;
    case EOptitrackBone::RThumb2:   return EOptitrackBone::RThumb1;
    case EOptitrackBone::RThumb3:   return EOptitrackBone::RThumb2;
    case EOptitrackBone::RIndex1:return EOptitrackBone::RHand;
    case EOptitrackBone::RIndex2:return EOptitrackBone::RIndex1;
    case EOptitrackBone::RIndex3:return EOptitrackBone::RIndex2;
    case EOptitrackBone::RMiddle1:return EOptitrackBone::RHand;
    case EOptitrackBone::RMiddle2:return EOptitrackBone::RMiddle1;
    case EOptitrackBone::RMiddle3:return EOptitrackBone::RMiddle2;
    case EOptitrackBone::RRing1:return EOptitrackBone::RHand;
    case EOptitrackBone::RRing2:return EOptitrackBone::RRing1;
    case EOptitrackBone::RRing3:return EOptitrackBone::RRing2;
    case EOptitrackBone::RPinky1:return EOptitrackBone::RHand;
    case EOptitrackBone::RPinky2: return EOptitrackBone::RPinky1;
    case EOptitrackBone::RPinky3: return EOptitrackBone::RPinky2;
	}

	return EOptitrackBone::Root;
}


#undef LOCTEXT_NAMESPACE
