// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBTService.h"
#include "MonsterAIController.h"
#include "TestCharacter.h"
#include "firstCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UTestBTService::UTestBTService()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;

}

void UTestBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector center = ControllingPawn->GetActorLocation();
	float DetectRadius = 600.0f;

	if (nullptr == World)return;
	TArray<FOverlapResult>OverlapResult;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResult,
		center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResults : OverlapResult)
		{
			AfirstCharacter* character = Cast<AfirstCharacter>(OverlapResults.GetActor());
			if (character) {
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMonsterAIController::TargetKey, character);
				DrawDebugSphere(World, center, DetectRadius, 16, FColor::Green, false, 0.2f);

				DrawDebugPoint(World, character->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), character->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
			else
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMonsterAIController::TargetKey, nullptr);
		}
	}
	DrawDebugSphere(World, center, DetectRadius, 16, FColor::Red, false, 0.2f);

}
