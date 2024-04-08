//======================================================================================================
// Copyright 2016, NaturalPoint Inc.
//====================================================================================================== 

#pragma once

#include <Logging/LogMacros.h>
#include <Modules/ModuleManager.h>


DECLARE_LOG_CATEGORY_EXTERN( LogOptitrackLiveLink, Log, All );


/**
* The public interface to this module
*/
class OPTITRACKLIVELINK_API IOptitrackLiveLinkPlugin : public IModuleInterface
{
public:
	virtual class NatNetClient* CreateClient() = 0;
	virtual void DestroyClient( class NatNetClient* pClient ) = 0;

public:
	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline IOptitrackLiveLinkPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IOptitrackLiveLinkPlugin >( "OptitrackLiveLink" );
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "OptitrackLiveLink" );
	}
};
