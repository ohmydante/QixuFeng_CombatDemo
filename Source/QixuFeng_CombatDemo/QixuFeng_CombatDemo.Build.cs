// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QixuFeng_CombatDemo : ModuleRules
{
	public QixuFeng_CombatDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
		});
	}
}
