//======================================================================================================
// Copyright 2023, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include "Components/SceneComponent.h"
#include "OptitrackLiveLinkComponent.generated.h"

class AOptitrackLiveLinkDisplay;

UCLASS(hidecategories = (Rendering, Tags, Activation, Cooking, Physics, LOD, AssetUserData, Collision, Navigation))
class OPTITRACKLIVELINK_API UOptitrackLiveLinkComponent : public USceneComponent
{
    GENERATED_BODY()

public:

	UOptitrackLiveLinkComponent();

	void PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent );

	/** Line thickness */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Asset", DisplayName = "Line Thickness" )
	float mLineThicknessScale;

	/** Diplay Asset */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Asset", DisplayName = "Display Asset" )
	bool mDisplayAsset = true;

	/** Asset color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Asset", DisplayName = "Asset Color" )
	FColor mAssetColor;

	// Ensure that the marker category is greyed out if there's no marker subject attached?

	/** Marker Size */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Markers", DisplayName = "Marker Size" )
	float mMarkerSize;

	/** Display Markers */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Markers", DisplayName = "Display Markers" )
	bool mDisplayMarkers = true;

	/** Marker color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Markers", DisplayName = "Marker Color" )
	FColor mMarkerColor;

	TObjectPtr<AOptitrackLiveLinkDisplay> mParentActor;
	FLiveLinkSubjectKey mMarkerSubjectKey;
};