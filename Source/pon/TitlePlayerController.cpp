// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePlayerController.h"
#include "MainWidget.h"
#include "LoadingWidget.h"
ATitlePlayerController::ATitlePlayerController()
{
	static ConstructorHelpers::FClassFinder<UMainWidget>MAIN(TEXT("/Game/Asset/Widget/UI_Title.UI_Title_C"));
	if (MAIN.Succeeded())
	{
		UIWidGet = MAIN.Class;
	}
	static ConstructorHelpers::FClassFinder<ULoadingWidget>LOAD(TEXT("/Game/Asset/Widget/Test.Test_C"));
	if (LOAD.Succeeded())
	{
		Loading = LOAD.Class;
	}
}

void ATitlePlayerController::BeginPlay()
{
	start();
	
}

void ATitlePlayerController::start()
{
	/*mainWidget = CreateWidget<UMainWidget>(this, UIWidGet);
	mainWidget->AddToViewport();
*/
	LoadingWidget = CreateWidget<ULoadingWidget>(this, Loading);
	LoadingWidget->AddToViewport();

}

void ATitlePlayerController::Load()
{
	mainWidget->RemoveFromViewport();
	

	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			UGameplayStatics::OpenLevel(this, FName(TEXT("protectLevel")));
		}), 5.0f, false);
		
}
