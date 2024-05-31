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
                
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoActiveRecord.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoData.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoDataODBC.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoEncodings.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoFoundation.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoJSON.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoNet.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoPrometheus.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoUtil.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoXML.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "PocoZip.lib"));

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoActiveRecord.dll"));
                PublicDelayLoadDLLs.Add("PocoActiveRecord.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoData.dll"));
                PublicDelayLoadDLLs.Add("PocoData.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoDataODBC.dll"));
                PublicDelayLoadDLLs.Add("PocoDataODBC.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoEncodings.dll"));
                PublicDelayLoadDLLs.Add("PocoEncodings.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoFoundation.dll"));
                PublicDelayLoadDLLs.Add("PocoFoundation.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoJSON.dll"));
                PublicDelayLoadDLLs.Add("PocoJSON.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoNet.dll"));
                PublicDelayLoadDLLs.Add("PocoNet.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoPrometheus.dll"));
                PublicDelayLoadDLLs.Add("PocoPrometheus.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoUtil.dll"));
                PublicDelayLoadDLLs.Add("PocoUtil.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoXML.dll"));
                PublicDelayLoadDLLs.Add("PocoXML.dll");

                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "bin", "PocoZip.dll"));
                PublicDelayLoadDLLs.Add("PocoZip.dll");
            }
        }
    }
}
