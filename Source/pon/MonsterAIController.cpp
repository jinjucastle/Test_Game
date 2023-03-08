// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree//BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"


const FName AMonsterAIController::HomePosKey(TEXT("Homepos"));
const FName AMonsterAIController::PatrolPosKey(TEXT("Patrolpos"));
const FName AMonsterAIController::TargetKey(TEXT("Target"));

AMonsterAIController::AMonsterAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData>BBO(TEXT("/Game/Asset/anim/BB_TESTPAWN.BB_TESTPAWN"));
	if (BBO.Succeeded())
		BBAsset = BBO.Object;

	static ConstructorHelpers::FObjectFinder<UBehaviorTree>BT(TEXT("/Game/Asset/anim/BT_TESTPAWN.BT_TESTPAWN"));
	if (BT.Succeeded())
		BTAsset = BT.Object;
}

void AMonsterAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UBlackboardComponent* blackq = GetBlackboardComponent();
	if (UseBlackboard(BBAsset, blackq))
	{
		blackq->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			ABLOG(Error, TEXT("AIController could't run behavior tree! "));
		}
	}
}



