//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//======================================================================================================

#include "LiveLinkNatNetSourceEditorWidget.h"

#include <Widgets/Text/STextBlock.h>
#include <Widgets/Input/SButton.h>
#include <Widgets/SBoxPanel.h>
#include <Widgets/Input/STextComboBox.h>

#define LOCTEXT_NAMESPACE "LiveLinkNatNetSourceEditor"

void SLiveLinkNatNetSourceEditorWidget::Construct( const FArguments& Args )
{
	OnCreateSource = Args._OnCreateSource;

	const float kRowPadding = 3;
	const float kLabelColMinWidth = 125;
	const float kEditColMinWidth = 125;

	ConnectionTypeStrings.Add( MakeShareable<FString>( new FString( "Multicast" ) ) );
	ConnectionTypeStrings.Add( MakeShareable<FString>( new FString( "Unicast" ) ) );

	ChildSlot
	[
		SNew( SVerticalBox )
		+ SVerticalBox::Slot()
		.Padding( kRowPadding )
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SNew( STextBlock )
				.Text( LOCTEXT("ConnectAutomaticallyLabel", "Connect Automatically") )
				.MinDesiredWidth( kLabelColMinWidth )
			]
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SAssignNew( ConnectAutomatically, SCheckBox )
				.IsChecked( ECheckBoxState::Checked )
			]
		]
		+ SVerticalBox::Slot()
			.Padding( kRowPadding )
			[
				SNew( SHorizontalBox )
				+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SNew( STextBlock )
				.Text( LOCTEXT( "IncludeMarkersLabel", "Include Asset Markers" ) )
			.MinDesiredWidth( kLabelColMinWidth )
			]
		+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SAssignNew( IncludeMarkers, SCheckBox )
				.IsChecked( ECheckBoxState::Unchecked )
			]
		]
		+ SVerticalBox::Slot()
		.Padding( kRowPadding )
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SNew( STextBlock )
				.Text( LOCTEXT("ServerAddressLabel", "Server Address") )
				.MinDesiredWidth( kLabelColMinWidth )
			]
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SAssignNew( ServerIpAddress, SEditableTextBox )
				.Text( FText::FromString( "127.0.0.1" ) )
				.MinDesiredWidth( kEditColMinWidth )
				.IsEnabled( this, &SLiveLinkNatNetSourceEditorWidget::GetConnectionParamsEnabled )
			]
		]
		+ SVerticalBox::Slot()
		.Padding( kRowPadding )
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SNew( STextBlock )
				.Text( LOCTEXT("ClientAddressLabel", "Client Address") )
				.MinDesiredWidth( kLabelColMinWidth )
			]
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SAssignNew( ClientIpAddress, SEditableTextBox )
				.Text( FText::FromString( "127.0.0.1" ) )
				.MinDesiredWidth( kEditColMinWidth )
				.IsEnabled( this, &SLiveLinkNatNetSourceEditorWidget::GetConnectionParamsEnabled )
			]
		]
		+ SVerticalBox::Slot()
		.Padding( kRowPadding )
		.AutoHeight()
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			.VAlign( VAlign_Center )
			[
				SNew( STextBlock )
				.Text( LOCTEXT("ConnectionTypeLabel", "Connection Type") )
				.MinDesiredWidth( kLabelColMinWidth )
			]
			+ SHorizontalBox::Slot()
			.HAlign( HAlign_Left )
			[
				SNew( STextComboBox )
				.OptionsSource( &ConnectionTypeStrings )
				.InitiallySelectedItem( GetConnectionTypeString() )
				.OnSelectionChanged( this, &SLiveLinkNatNetSourceEditorWidget::OnConnectionTypeChanged )
				.IsEnabled( this, &SLiveLinkNatNetSourceEditorWidget::GetConnectionParamsEnabled )
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding( 0, 10, 0, 0 )
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth( 1 )
			+ SHorizontalBox::Slot()
			.FillWidth( 1 )
			[
				SNew( SButton )
				.Text( LOCTEXT("CreateButtonLabel", "Create") )
				.HAlign( HAlign_Center )
				.OnClicked( this, &SLiveLinkNatNetSourceEditorWidget::OnCreateClicked )
			]
			+ SHorizontalBox::Slot()
			.FillWidth( 1 )
		]
	];
}

TSharedPtr<FString> SLiveLinkNatNetSourceEditorWidget::GetConnectionTypeString() const
{
	switch( ConnectionType )
	{
	case EOptitrackLiveLinkConnectionType::Unicast:
		return ConnectionTypeStrings[1];
	case EOptitrackLiveLinkConnectionType::Multicast:
	default:
		return ConnectionTypeStrings[0];
	}
}

void SLiveLinkNatNetSourceEditorWidget::OnConnectionTypeChanged( TSharedPtr<FString> Value, ESelectInfo::Type SelectInfo )
{
	if( Value->Equals( "Multicast" ) )
		ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
	else if( Value->Equals( "Unicast" ) )
		ConnectionType = EOptitrackLiveLinkConnectionType::Unicast;
}


FReply SLiveLinkNatNetSourceEditorWidget::OnCreateClicked() const
{
	FOptitrackLiveLinkSettings Settings;
	Settings.ConnectAutomatically = ConnectAutomatically->IsChecked();
	Settings.IncludeMarkers = IncludeMarkers->IsChecked();
	Settings.ServerIpAddress = ServerIpAddress.Get()->GetText().ToString();
	Settings.ClientIpAddress = ClientIpAddress.Get()->GetText().ToString();
	Settings.ConnectionType = ConnectionType;

	OnCreateSource.ExecuteIfBound( Settings );

	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE
