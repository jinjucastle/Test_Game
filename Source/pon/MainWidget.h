// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (AllowPrivateAccess = "true"))
		class UButton* NewGame;
	UPROPERTY(meta = (AllowPrivateAccess = "true"))
		class UButton* Exit;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ULoadingWidget>Loading;
	
	UPROPERTY(EditDefaultsOnly)
		class ULoadingWidget* LoadingWidget;
	UFUNCTION(BlueprintCallable)
	void NewWorld();

	
};
