//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <LiveLinkSourceFactory.h>

#include "LiveLinkNatNetSource.h"

#include "LiveLinkNatNetSourceFactory.generated.h"


UCLASS()
class ULiveLinkNatNetSourceFactory : public ULiveLinkSourceFactory
{
public:
	GENERATED_BODY()

	//~ Begin ULiveLinkSourceFactory interface
	virtual FText GetSourceDisplayName() const override;
	virtual FText GetSourceTooltip() const override;
	virtual EMenuType GetMenuType() const override { return EMenuType::SubPanel; }
	virtual TSharedPtr<SWidget> BuildCreationPanel( FOnLiveLinkSourceCreated OnLiveLinkSourceCreated ) const override;
	virtual TSharedPtr<ILiveLinkSource> CreateSource( const FString& ConnectionString ) const override;
	//~ End ULiveLinkSourceFactory interface

protected:
	void OnCreateSource( FOptitrackLiveLinkSettings InSettings, FOnLiveLinkSourceCreated OnLiveLinkSourceCreated ) const;
};
