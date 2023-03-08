// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Pawn.h"
#include "TestPawn.generated.h"

UCLASS()
class PON_API ATestPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* body;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
		
};
