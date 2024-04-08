#include "OptitrackNatnetEditor.h"
#include "AnimGraphNode_OptitrackSkeleton.h"
#include "AnimGraphNode_OptitrackSkeleton_DetailCustomization.h"
#include <PropertyEditorModule.h>


class FOptitrackNatnetEditorModule : public IOptitrackNatnetEditorPlugin
{
public:
    // IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


IMPLEMENT_MODULE( FOptitrackNatnetEditorModule, OptitrackNatnetEditor )


void FOptitrackNatnetEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>( "PropertyEditor" );
	PropertyModule.RegisterCustomClassLayout(
		UAnimGraphNode_OptitrackSkeleton::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic( &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::MakeInstance )
	);
}


void FOptitrackNatnetEditorModule::ShutdownModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>( "PropertyEditor" );
	PropertyModule.UnregisterCustomClassLayout( "AnimGraphNode_OptitrackSkeleton" );
}
