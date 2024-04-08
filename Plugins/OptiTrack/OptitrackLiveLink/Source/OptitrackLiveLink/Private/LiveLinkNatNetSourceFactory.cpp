//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 

#include "LiveLinkNatNetSourceFactory.h"

#include "LiveLinkNatNetSource.h"
#include "LiveLinkNatNetSourceEditorWidget.h"


#define LOCTEXT_NAMESPACE "LiveLinkNatNetSourceFactory"


FText ULiveLinkNatNetSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT( "SourceDisplayName", "OptiTrack Source" );
}


FText ULiveLinkNatNetSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT( "SourceTooltip", "Connects to OptiTrack Motive via NatNet." );
}


// Creates the widget responsible for configuring and creating the source
TSharedPtr<SWidget> ULiveLinkNatNetSourceFactory::BuildCreationPanel( FOnLiveLinkSourceCreated OnLiveLinkSourceCreated ) const
{
	return SNew( SLiveLinkNatNetSourceEditorWidget )
		.OnCreateSource( FLiveLinkNatNetSourceEditorOnCreateSource::CreateUObject(
			this, &ULiveLinkNatNetSourceFactory::OnCreateSource, OnLiveLinkSourceCreated
		) );
}


TSharedPtr<ILiveLinkSource> ULiveLinkNatNetSourceFactory::CreateSource( const FString& ConnectionString ) const
{
	return MakeShared<FLiveLinkNatNetSource>( FOptitrackLiveLinkSettings::FromString( ConnectionString ) );
}


void ULiveLinkNatNetSourceFactory::OnCreateSource( FOptitrackLiveLinkSettings InSettings, FOnLiveLinkSourceCreated OnLiveLinkSourceCreated ) const
{
	OnLiveLinkSourceCreated.ExecuteIfBound(
		MakeShared<FLiveLinkNatNetSource>( InSettings ),
		InSettings.ToString()
	);
}


#undef LOCTEXT_NAMESPACE
