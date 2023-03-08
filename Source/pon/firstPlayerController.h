// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/PlayerController.h"
#include "MediaPlayer.h"
#include "FileMediaSource.h"
#include "firstPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PON_API AfirstPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;
	
	virtual void SetupInputComponent()override;

	virtual void Tick(float DeltaTime)override;
	
	
public:
	void TestVir();
	void ReturnGame();

	void OnMediaEnd();


public:
	AfirstPlayerController();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMediaWidget> TESTWIDGET;

	UPROPERTY()
		class UMediaWidget* Test;
	UPROPERTY(EditAnywhere)
		class UMediaPlayer* TestMedia;
	UPROPERTY(EditAnywhere)
		class UFileMediaSource* TestSource;
	bool powerq;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ULoadingWidget>Loading;

	UPROPERTY(EditDefaultsOnly)
		class ULoadingWidget* LoadingWidget;
};
