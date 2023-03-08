// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

UCLASS()
class PON_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UFUNCTION()
		void OnCharacterBegieOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool BodyCheck;
private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void turn(float NewAxisValue);
	void LookUp(float NewAxisValue);

};
