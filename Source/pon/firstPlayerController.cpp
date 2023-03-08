// Fill out your copyright notice in the Description page of Project Settings.


#include "firstPlayerController.h"
#include "firstCharacter.h"
#include "MediaWidget.h"
#include "MainWidget.h"
#include "FileMediaSource.h"
#include "LoadingWidget.h"
#include "Blueprint/UserWidget.h"
#include "TestCharacter.h"




AfirstPlayerController::AfirstPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	//Loading=LoadClass<ULoadingWidget>(NULL, TEXT("/Game/Asset/Widget/Loading.Loading_C"), NULL, LOAD_None, NULL);
	
	static ConstructorHelpers::FClassFinder<ULoadingWidget>LODING(TEXT("/Game/Asset/Widget/Loading.Loading_C"));
	if (LODING.Succeeded())
	{
		Loading = LODING.Class;
	}

	static ConstructorHelpers::FClassFinder<UMediaWidget>UI(TEXT("/Game/Asset/Widget/TestUI.TestUI_C"));
	if (UI.Succeeded())
	{
		TESTWIDGET = UI.Class;
	}
	static ConstructorHelpers::FObjectFinder<UMediaPlayer>MEDIA(TEXT("/Game/Asset/Movies/TestMedia"));
	if (MEDIA.Succeeded())
	{
		TestMedia = MEDIA.Object;
	}
	static ConstructorHelpers::FObjectFinder<UFileMediaSource>SOURCE(TEXT("/Game/Asset/Movies/player"));
	if (SOURCE.Succeeded())
	{
		TestSource = SOURCE.Object;
	}
	powerq = false;
	
}

void AfirstPlayerController::BeginPlay()
{
	Super::BeginPlay();
		
	

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	
	
	
}

void AfirstPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAction(TEXT("OPEN"), EInputEvent::IE_Pressed, this, &AfirstPlayerController::TestVir);

}

void AfirstPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*UMediaWidget* power = TESTWIDGET.GetDefaultObject();
	if(power->Check())
		ABLOG_S(Warning);
	*/
	/*auto testA = Cast<ATestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestCharacter::StaticClass()));
	if (testA->BodyCheck)
		TestVir();*/

	if (powerq && TestMedia->IsPlaying() && TestMedia->GetRate() == 0.0) {
		ABLOG(Warning, TEXT("power"));
		ReturnGame();
		powerq = false;
	
	}
}

void AfirstPlayerController::TestVir()
{//여기에 두면 안됨 검색은 
	//TestMedia->OnEndReached.AddDynamic(this, &AfirstPlayerController::OnMediaEnd);
	TestMedia->OpenSource(TestSource);
	TestMedia->Play();
	Test = CreateWidget<UMediaWidget>(this, TESTWIDGET);
	Test->SetVisibility(ESlateVisibility::Visible);
	Test->SetIsEnabled(true);
	Test->SetDesiredSizeInViewport(FVector2D(0.0f, 0.0f));
	Test->SetPositionInViewport(FVector2D(0.0f, 0.0f));
	Test->SetAnchorsInViewport(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	
	Test->AddToViewport(1);
	UGameplayStatics::SetGamePaused(GetWorld(),true);
	//SetPause(true);
	SetInputMode(FInputModeUIOnly());
	SetShowMouseCursor(true);
	
	powerq = true;
}

void AfirstPlayerController::ReturnGame()
{
	Test->RemoveFromViewport();
	LoadingWidget = CreateWidget<ULoadingWidget>(this, Loading);
	
	LoadingWidget->AddToViewport(2);

	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{

			UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("protectLevel")));	
			
		}), 3.0f, false);
		UGameplayStatics::SetGamePaused(GetWorld(),false);
			//SetPause(false);
		SetInputMode(FInputModeGameOnly());
}

void AfirstPlayerController::OnMediaEnd()
{
	ABLOG_S(Warning);
}






