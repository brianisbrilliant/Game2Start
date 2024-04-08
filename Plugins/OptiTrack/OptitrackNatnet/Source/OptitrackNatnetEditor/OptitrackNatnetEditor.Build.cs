//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//======================================================================================================

namespace UnrealBuildTool.Rules
{
	public class OptitrackNatnetEditor : ModuleRules
	{
        public OptitrackNatnetEditor( ReadOnlyTargetRules Target ) : base( Target )
		{
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            PrivateIncludePaths.Add( "OptitrackNatnetEditor/Private" );

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"AnimGraphRuntime",

					"UnrealEd",
					"BlueprintGraph",
					"AnimGraph",
					"SlateCore",
					"Slate",
					"EditorStyle",
					"PropertyEditor",

					"OptitrackNatnet",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
				}
			);
		}
	}
}
