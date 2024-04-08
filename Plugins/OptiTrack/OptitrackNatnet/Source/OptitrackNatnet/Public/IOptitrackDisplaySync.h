//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include "Features/IModularFeature.h"
#include "UObject/NameTypes.h"

static const FName OptitrackDisplaySyncFeatureName = FName(TEXT("OptitrackDisplaySync"));

class IOptitrackDisplaySync : public IModularFeature
{
public:
    virtual ~IOptitrackDisplaySync() {}

    virtual double GetTimeToNextFrame() = 0;
    virtual void Initialize() = 0;
};