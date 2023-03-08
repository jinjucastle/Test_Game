// Fill out your copyright notice in the Description page of Project Settings.


#include "firstGameModeBase.h"
#include "TestPawn.h"
#include"firstCharacter.h"
#include "firstPlayerController.h"

AfirstGameModeBase::AfirstGameModeBase()
{
	DefaultPawnClass = AfirstCharacter::StaticClass();
	PlayerControllerClass = AfirstPlayerController::StaticClass();
}

