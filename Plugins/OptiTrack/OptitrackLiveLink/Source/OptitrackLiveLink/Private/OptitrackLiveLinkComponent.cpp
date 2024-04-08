//======================================================================================================
// Copyright 2023, NaturalPoint Inc.
//====================================================================================================== 

#include "OptitrackLiveLinkComponent.h"

// Constructor is here for later development if necessary
UOptitrackLiveLinkComponent::UOptitrackLiveLinkComponent()
{
	// These values get overriden by the parent on construction
	// Unfortunately it's a bit of a pain to put constructor arguments so this is how it must be done
	mLineThicknessScale = 1.0f;
    mAssetColor = FColor( 0, 255, 0 ); 

	mMarkerSize = 1.0f;
	mMarkerColor = FColor( 255, 255, 255 );
}

// Whenever a property is changed, trigger parent's CheckProperties() function to manage parent properties
void UOptitrackLiveLinkComponent::PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent )
{
	if( mParentActor )
	{
		mParentActor->CheckProperties();
	}
}