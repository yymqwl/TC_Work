// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TC_Work : ModuleRules
{
	public TC_Work(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "TC_RPC" ,"UE5Coro"});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"HTTPServer", "TC_Core" , "UE5Coro"
        });
		//CppStandard = CppStandardVersion.Cpp20;
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
