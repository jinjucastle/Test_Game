// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class PON_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* wall;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* butten;
	UPROPERTY(EditAnywhere)
		UBoxComponent* Box;
	
public:
	void DownButten();

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
