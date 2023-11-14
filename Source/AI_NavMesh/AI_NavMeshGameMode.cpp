// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_NavMeshGameMode.h"
#include "AI_NavMeshPlayerController.h"
#include "AI_NavMeshCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAI_NavMeshGameMode::AAI_NavMeshGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAI_NavMeshPlayerController::StaticClass();

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