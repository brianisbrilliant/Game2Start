//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include "OptitrackSkeletonTypes.generated.h"

USTRUCT(BlueprintType)
struct FOptitrackPose
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    FVector Position;

    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    FQuat Orientation;
};

UENUM( BlueprintType )
enum class EOptitrackBoneNamingConvention : uint8
{
	Motive     UMETA(DisplayName = "Motive"),
	FBX        UMETA(DisplayName = "FBX"),
	BVH		   UMETA(DisplayName = "BVH"),
};


UENUM( BlueprintType )
enum class EOptitrackBone : uint8
{
	Root = 0,
	Hip,
	Ab,
	Chest,
	Neck,
	Head,

	LShoulder = 6,
	LUArm,
	LFArm,
	LHand,

	RShoulder = 10,
	RUArm,
	RFArm,
	RHand,

	LThigh = 14,
	LShin,
	LFoot,
	LToe,

	RThigh = 18,
	RShin,
	RFoot,
	RToe,

	LThumb1,  LThumb2,  LThumb3,
	LIndex1,  LIndex2,  LIndex3,
	LMiddle1, LMiddle2, LMiddle3,
	LRing1,   LRing2,   LRing3,
	LPinky1,  LPinky2,  LPinky3,

	RThumb1,  RThumb2,  RThumb3,
	RIndex1,  RIndex2,  RIndex3,
	RMiddle1, RMiddle2, RMiddle3,
	RRing1,   RRing2,   RRing3,
	RPinky1,  RPinky2,  RPinky3,

	NumBones,
};


FText OPTITRACKNATNET_API GetDisplayBoneName( EOptitrackBone BoneId );
FName OPTITRACKNATNET_API GetStreamingBoneName( EOptitrackBone BoneId, EOptitrackBoneNamingConvention NamingConvention );
EOptitrackBone OPTITRACKNATNET_API GetParentBone( EOptitrackBone BoneId );


// The streaming skeleton begins at the hip bone; the root bone is implicit, and not streamed.
USTRUCT( BlueprintType )
struct FOptitrackBoneDefinition
{
	GENERATED_BODY()

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	int Id;

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	int ParentId;

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	FName Name;

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	FVector LocalOffset;
};


USTRUCT( BlueprintType )
struct FOptitrackSkeletonDefinition
{
	GENERATED_BODY()

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	int Id;

	UPROPERTY( BlueprintReadOnly, Category="Optitrack" )
	FName Name;

    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")

    TMap<int, FOptitrackBoneDefinition > Bones;
};


USTRUCT( BlueprintType )
struct FOptitrackSkeletonState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    TMap<int, FOptitrackPose> BonePoses;


    UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
    TMap<int, FTransform> WorldSpaceBoneTransforms;

	UPROPERTY(BlueprintReadOnly, Category = "Optitrack")
	TMap<int, FTransform> LocalBoneSpaceTransforms;
};
