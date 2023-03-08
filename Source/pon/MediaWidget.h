// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"

#include "MediaWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UMediaWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		class UImage* IMAGE;

	bool Check();
};
