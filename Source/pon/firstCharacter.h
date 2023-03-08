// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Door.h"
#include "GameFramework/Character.h"
#include "firstCharacter.generated.h"

DECLARE_DELEGATE(FCustom);

UCLASS()
class PON_API AfirstCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AfirstCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere,Category=camera)
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = body)
		USkeletalMeshComponent* hand;
	UPROPERTY(EditAnywhere)
		class ADoor* door;
	UPROPERTY(EditAnywhere)
		class AItem* Item;
	UFUNCTION()
		void CallDelegate();

	FCustom MyDelegate;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void RunOn();
	void RunOut();
	void openDoor();
	void ChangeSpead(bool Cheacking);
	void testWidget();
	void PushButten();
public:
	bool Check;
	bool Check2;
};
