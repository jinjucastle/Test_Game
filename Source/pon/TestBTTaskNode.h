// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TestBTTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTestBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UTestBTTaskNode();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
};
