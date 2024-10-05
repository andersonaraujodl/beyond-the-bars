// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeyondTheBarsGameMode.h"
#include "BeyondTheBarsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABeyondTheBarsGameMode::ABeyondTheBarsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
