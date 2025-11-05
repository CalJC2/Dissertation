// Copyright Epic Games, Inc. All Rights Reserved.

#include "Goap_DissGameMode.h"
#include "Goap_DissPlayerController.h"
#include "Goap_DissCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoap_DissGameMode::AGoap_DissGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGoap_DissPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}