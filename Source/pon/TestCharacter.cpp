// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "firstCharacter.h"
#include "firstPlayerController.h"
#include "MonsterAIController.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MESH(TEXT("/Game/CharacterBodyFX/Mannequin/Character/Mesh/SK_Mannequin"));
	if (MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MESH.Object);
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance>WA(TEXT("/Game/Asset/anim/Aub.Aub_C"));
	if (WA.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WA.Class);
	}
	RootComponent = GetCapsuleComponent();
	
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0));
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Charactor"));
	bUseControllerRotationPitch = true;
	AIControllerClass = AMonsterAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	BodyCheck = false;
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATestCharacter::OnCharacterBegieOverlap);
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ATestCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ATestCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATestCharacter::turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATestCharacter::LookUp);
}

void ATestCharacter::OnCharacterBegieOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto CharacterP = Cast<AfirstCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstCharacter::StaticClass()));
	auto ControllerP = Cast<AfirstPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if ((OtherActor != this) && (OtherComp != nullptr) && (OtherActor == CharacterP))
	{
		if (!BodyCheck)
		{
			ControllerP->TestVir();
		}
			ABLOG_S(Warning);
			BodyCheck = true;
	}
}

void ATestCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void ATestCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

void ATestCharacter::turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void ATestCharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}

