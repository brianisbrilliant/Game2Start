//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//======================================================================================================  

using Path = System.IO.Path;
using UnrealBuildTool;


public class OptitrackLiveLink : ModuleRules
{
    public OptitrackLiveLink( ReadOnlyTargetRules Target ) : base( Target )
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDefinitions.Add( "NATNETLIB_IMPORTS" );

        PublicIncludePaths.AddRange(
            new string[] {
                //"OptitrackLiveLink/Public",
                // ... add public include paths required here ...
            }
        );


        PrivateIncludePaths.AddRange(
            new string[] {
                "OptitrackLiveLink/Private",
                // ... add other private include paths required here ...
            }
        );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Projects",
                "CoreUObject",
                "Engine",

                "LiveLink",
                "LiveLinkInterface",
                "LiveLinkAnimationCore",

                "InputCore",
                "SlateCore",
                "Slate",

                // ... add other public dependencies that you statically link with here ...
            }
        );

        if (Target.Type == TargetRules.TargetType.Editor)
        {

        }

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "TimeManagement",

                "LiveLink",
                "LiveLinkInterface",
                // ... add private dependencies that you statically link with here ...
            }
        );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
        );

        /****************************************/

        // If you update this path, ensure the DLL runtime delay load path in FOptitrackNatnetModule::StartupModule stays in sync.
        string NatNetPath = Path.GetFullPath( Path.Combine( ModuleDirectory, "..", "..", "ThirdParty", "NatNetSDK" ) );
        PublicSystemIncludePaths.Add( Path.Combine( NatNetPath, "include" ) );

        // 64 bit only in Unreal Engine 5
        string NatNetLibBinPath = Path.Combine(NatNetPath, "lib", "Win64");
        PublicAdditionalLibraries.Add(Path.Combine(NatNetLibBinPath, "NatNetLib.lib"));
        PublicDelayLoadDLLs.Add("NatNetLib.dll");
        RuntimeDependencies.Add(Path.Combine(NatNetLibBinPath, "NatNetLib.dll"));
    }
}
