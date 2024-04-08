//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//======================================================================================================
#include "AnimGraphNode_OptitrackSkeleton.h"
#include "AnimationGraphSchema.h"

#define LOCTEXT_NAMESPACE "OptitrackNatnet"


UAnimGraphNode_OptitrackSkeleton::UAnimGraphNode_OptitrackSkeleton( const FObjectInitializer& ObjectInitializer )
    : Super( ObjectInitializer )
{
}


FText UAnimGraphNode_OptitrackSkeleton::GetNodeTitle( ENodeTitleType::Type TitleType ) const
{
    return LOCTEXT( "OptitrackSkeleton_NodeTitle", "OptiTrack Skeleton" );
}


FText UAnimGraphNode_OptitrackSkeleton::GetTooltipText() const
{
    return LOCTEXT( "OptitrackSkeleton_Tooltip", "Drive skeleton based on streamed motion capture data from an OptiTrack NatNet server." );
}


FText UAnimGraphNode_OptitrackSkeleton::GetMenuCategory() const
{
    return LOCTEXT( "OptitrackSkeleton_MenuCategory", "Optitrack" );
}

void UAnimGraphNode_OptitrackSkeleton::CreateOutputPins()
{
	CreatePin(EGPD_Output, UAnimationGraphSchema::PC_Struct, FComponentSpacePoseLink::StaticStruct(), TEXT("Pose"));
}

#undef LOCTEXT_NAMESPACE
