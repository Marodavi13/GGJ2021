// Copyright Epic Games, Inc. All Rights Reserved.

#include "LFGameMode.h"
#include "../Actors/Character/LFCharacter.h"

ALFGameMode::ALFGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ALFCharacter::StaticClass();	
}
