// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdP_TDSGameMode.h"
#include "ThirdP_TDSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdP_TDSGameMode::AThirdP_TDSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
