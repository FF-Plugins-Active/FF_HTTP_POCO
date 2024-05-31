namespace UnrealBuildTool.Rules
{
    using System.IO;

    public class POCO : ModuleRules
    {
        public POCO(ReadOnlyTargetRules Target) : base(Target)
        {
    		Type = ModuleType.External;
            bEnableUndefinedIdentifierWarnings = false;
            bEnableExceptions = true;
            bUseRTTI = true;

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "include"));

                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoFoundation.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoNet.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoUtil.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoData.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoDataODBC.lib"));

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoFoundation.dll"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoNet.dll"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoUtil.dll"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoData.dll"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoDataODBC.dll"));

                PublicDelayLoadDLLs.Add("PocoFoundation.dll");
                PublicDelayLoadDLLs.Add("PocoNet.dll");
                PublicDelayLoadDLLs.Add("PocoUtil.dll");
                PublicDelayLoadDLLs.Add("PocoData.dll");
                PublicDelayLoadDLLs.Add("PocoDataODBC.dll");
            }
        }
    }
}
