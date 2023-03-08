// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawn.h"
#include "MonsterAIController.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BODY"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MESH(TEXT("/Game/CharacterBodyFX/Mannequin/Character/Mesh/SK_Mannequin"));
	if (MESH.Succeeded())
	{
		body->SetSkeletalMesh(MESH.Object);
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance>WA(TEXT("/Game/Asset/anim/Aub.Aub_C"));
	if (WA.Succeeded())
	{
		body->SetAnimInstanceClass(WA.Class);
	}
	RootComponent = Camera;
	body->SetupAttachment(RootComponent);
	AIControllerClass = AMonsterAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ATestPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ATestPawn::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATestPawn::turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATestPawn::LookUp);

}

void ATestPawn::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void ATestPawn::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

void ATestPawn::turn(float NewAxisValue)
{

	AddControllerYawInput(NewAxisValue);
}

void ATestPawn::LookUp(float NewAxisValue)
{

	AddControllerPitchInput(NewAxisValue);

}
