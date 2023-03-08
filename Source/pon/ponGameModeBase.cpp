// Copyright Epic Games, Inc. All Rights Reserved.


#include "ponGameModeBase.h"
#include "TitlePlayerController.h"
AponGameModeBase::AponGameModeBase()
{
	PlayerControllerClass = ATitlePlayerController::StaticClass();
}
