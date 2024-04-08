//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#include "LiveLinkNatNetSettings.h"

#define LOCTEXT_NAMESPACE "LiveLinkNatNetSettings"


// static
FString FOptitrackLiveLinkSettings::ConnectionTypeToString( EOptitrackLiveLinkConnectionType ConnType )
{
	return (ConnType == EOptitrackLiveLinkConnectionType::Unicast)
		? "Unicast"
		: "Multicast";
}


//static
FOptitrackLiveLinkSettings FOptitrackLiveLinkSettings::FromString( const FString& SettingsStr )
{
	FOptitrackLiveLinkSettings ParsedSettings;

	FParse::Bool( *SettingsStr, TEXT("ConnectAutomatically="), ParsedSettings.ConnectAutomatically );
	FParse::Bool( *SettingsStr, TEXT( "IncludeMarkers=" ), ParsedSettings.IncludeMarkers );
	FParse::Value( *SettingsStr, TEXT("ServerIpAddress="), ParsedSettings.ServerIpAddress );
	FParse::Value( *SettingsStr, TEXT("ClientIpAddress="), ParsedSettings.ClientIpAddress );

	FString TempConnType;
	if ( FParse::Value( *SettingsStr, TEXT("ConnectionType="), TempConnType ) )
	{
		if ( TempConnType.Equals( "Unicast", ESearchCase::IgnoreCase ) )
		{
			ParsedSettings.ConnectionType = EOptitrackLiveLinkConnectionType::Unicast;
		}
		else 
		{
			ParsedSettings.ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
		}
	}

	return ParsedSettings;
}


FString FOptitrackLiveLinkSettings::ToString() const
{
	return FString::Printf(
		TEXT( "ConnectAutomatically=\"%s\" "
			  "IncludeMarkers=\"%s\" "
		      "ServerIpAddress=\"%s\" "
		      "ClientIpAddress=\"%s\" "
		      "ConnectionType=\"%s\"" ),
		ConnectAutomatically ? TEXT("true") : TEXT("false"),
		IncludeMarkers ? TEXT( "true" ) : TEXT( "false" ),
		*ServerIpAddress,
		*ClientIpAddress,
		*ConnectionTypeToString( ConnectionType )
	);
}


#undef LOCTEXT_NAMESPACE
