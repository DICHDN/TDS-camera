// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThirdP_TDS : ModuleRules
{
	public ThirdP_TDS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
