// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "monster.generated.h"

UCLASS()
class PON_API Amonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* body;
	UPROPERTY(EditAnywhere)
		UBoxComponent* Box;
	UPROPERTY(EditAnywhere)
		UBoxComponent* TEST;
	UPROPERTY(EditAnywhere)
		UMaterialInterface* Metarial;

	
	float moveing;
	FVector OneVector;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	void Running();

};
