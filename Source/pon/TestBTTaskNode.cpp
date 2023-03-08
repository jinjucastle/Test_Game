// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBTTaskNode.h"
#include "MonsterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
UTestBTTaskNode::UTestBTTaskNode()
{
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UTestBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if(nullptr==NavSystem)
		return EBTNodeResult::Failed;
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AMonsterAIController::HomePosKey);
	FNavLocation NextPatrol;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextPatrol))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMonsterAIController::PatrolPosKey, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
