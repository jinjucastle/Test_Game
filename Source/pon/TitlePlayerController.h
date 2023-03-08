// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitlePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PON_API ATitlePlayerController : public APlayerController
{
	GENERATED_BODY()
public:

		ATitlePlayerController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UMainWidget>UIWidGet;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ULoadingWidget>Loading;
	UPROPERTY(EditDefaultsOnly)
		class UMainWidget* mainWidget;
	UPROPERTY(EditDefaultsOnly)
		class ULoadingWidget* LoadingWidget;

	void start();

	void Load();

};
