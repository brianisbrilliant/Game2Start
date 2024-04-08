//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//======================================================================================================
#pragma once

#include <AnimGraphNode_Base.h>
#include "AnimNode_OptitrackSkeleton.h"

#include "AnimGraphNode_OptitrackSkeleton.generated.h"


UCLASS( BlueprintType )
class OPTITRACKNATNETEDITOR_API UAnimGraphNode_OptitrackSkeleton : public UAnimGraphNode_Base
{
    GENERATED_UCLASS_BODY()

    UPROPERTY( EditAnywhere, Category="Settings" )
    FAnimNode_OptitrackSkeleton Node;

	virtual void CreateOutputPins() override;

public:
    virtual FText /*UEdGraphNode::*/GetNodeTitle( ENodeTitleType::Type TitleType ) const override;
    virtual FText /*UEdGraphNode::*/GetTooltipText() const override;
    virtual FText /*UEdGraphNode::*/GetMenuCategory() const override;
};
