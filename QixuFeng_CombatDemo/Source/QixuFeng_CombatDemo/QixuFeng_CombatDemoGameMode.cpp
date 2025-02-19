// Copyright Epic Games, Inc. All Rights Reserved.

#include "QixuFeng_CombatDemoGameMode.h"
#include "QixuFeng_CombatDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQixuFeng_CombatDemoGameMode::AQixuFeng_CombatDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
