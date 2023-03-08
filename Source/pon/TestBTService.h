// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "BehaviorTree/BTService.h"
#include "TestBTService.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTestBTService : public UBTService
{
	GENERATED_BODY()
	
public:
	UTestBTService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
