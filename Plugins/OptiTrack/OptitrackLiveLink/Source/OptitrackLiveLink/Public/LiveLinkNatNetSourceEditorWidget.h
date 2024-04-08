//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <Widgets/SCompoundWidget.h>

#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "LiveLinkNatNetSettings.h"


DECLARE_DELEGATE_OneParam( FLiveLinkNatNetSourceEditorOnCreateSource, FOptitrackLiveLinkSettings );

class SLiveLinkNatNetSourceEditorWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS( SLiveLinkNatNetSourceEditorWidget ) {}
		SLATE_EVENT( FLiveLinkNatNetSourceEditorOnCreateSource, OnCreateSource )
	SLATE_END_ARGS()

	void Construct( const FArguments& Args );

private:
	bool GetConnectionParamsEnabled() const { return ! ConnectAutomatically->IsChecked(); }
	TSharedPtr<FString> GetConnectionTypeString() const;
	void OnConnectionTypeChanged( TSharedPtr<FString> Value, ESelectInfo::Type SelectInfo );

	FReply OnCreateClicked() const;

	// FIXME: Probably shouldn't use this widget as its own model
	TSharedPtr<SCheckBox> ConnectAutomatically;
	TSharedPtr<SCheckBox> IncludeMarkers;
	TSharedPtr<SEditableTextBox> ServerIpAddress;
	TSharedPtr<SEditableTextBox> ClientIpAddress;
	EOptitrackLiveLinkConnectionType ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
	TArray<TSharedPtr <FString>> ConnectionTypeStrings; 

	FLiveLinkNatNetSourceEditorOnCreateSource OnCreateSource;
};
