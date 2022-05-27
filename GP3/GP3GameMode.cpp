// Copyright Epic Games, Inc. All Rights Reserved.

#include "GP3GameMode.h"
#include "GP3Character.h"
#include "UObject/ConstructorHelpers.h"

AGP3GameMode::AGP3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_Game/Player/Blueprints/Ue4ASP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
