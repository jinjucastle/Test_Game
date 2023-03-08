// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UCLASS()
class PON_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = body)
		UStaticMeshComponent* body;
	
	UPROPERTY(EditAnywhere)
		UCurveFloat* DoorCurve;

	UFUNCTION()
		void ControlDoor();
	UFUNCTION()
		void ToggleDoor();
	

	bool open;
	bool ReadyState;
	float RotateValue;
	float CurveFloatValue;
	float TimelineValue;

	FRotator DoorRotation;
	FTimeline MyTimeline;

};
