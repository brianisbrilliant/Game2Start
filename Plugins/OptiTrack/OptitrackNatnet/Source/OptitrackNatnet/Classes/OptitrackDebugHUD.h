//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <CoreMinimal.h>
#include <GameFramework/HUD.h>
#include "OptitrackDebugHUD.generated.h"


class AOptitrackClientOrigin;


UCLASS()
class AOptitrackDebugHUD : public AHUD
{
	GENERATED_BODY()

public:
	void DebugDraw( UCanvas* DebugCanvas, APlayerController* DebugPC );
	void AddClient( AOptitrackClientOrigin* DebugClient );

private:
	void DebugDraw_ClientLatency( UCanvas* DebugCanvas, AOptitrackClientOrigin* DebugClient );

	TArray< AOptitrackClientOrigin* > DebugClients;
};
