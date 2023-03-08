// Fill out your copyright notice in the Description page of Project Settings.


#include "firstCharacter.h"
#include "Item.h"
#include "MonsterAIController.h"
// Sets default values
AfirstCharacter::AfirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	hand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("hand"));
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MO(TEXT("/Game/Asset/Mesh/HeroFPP"));
	if (MO.Succeeded())
	{
		hand->SetSkeletalMesh(MO.Object);

	}
	/*static ConstructorHelpers::FObjectFinder<USkeletalMesh>MA(TEXT("/Game/Asset/Mesh/GenericMale"));
	if (MA.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MA.Object);
	}
	*/
	RootComponent = GetCapsuleComponent();
	GetCapsuleComponent()->SetCapsuleSize(30.0f, 88.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Charactor"));
	Camera->SetupAttachment(RootComponent);
	hand->SetupAttachment(RootComponent);
	hand->SetCollisionProfileName(TEXT("NoCollision"));
	hand->bCastDynamicShadow = false;
	hand->CastShadow = false;

	/*GetMesh()->SetCollisionProfileName(TEXT("Charactor"));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetOwnerNoSee(true);*/
	hand->SetRelativeLocation(FVector(120.0f, 0.0f, -10.0f));
	hand->SetRelativeRotation(FRotator(50.0f, 0.0f, 0.0f));
	
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight+26.0f));
	bUseControllerRotationPitch = true;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	door = nullptr;
	Check2 = false;

	//AIControllerClass = AMonsterAIController::StaticClass();
	//AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AfirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	MyDelegate.BindUFunction(this, FName("CallDelegate"));
	if (MyDelegate.IsBound())
	{
		MyDelegate.Execute();
	}

}

// Called every frame
void AfirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Hit;
	FVector Start = Camera->GetComponentLocation();
	FVector ForwardVector = Camera->GetForwardVector();
	FVector End = (ForwardVector * 200.0f) + Start;
	FCollisionQueryParams CollisionParams;

	//DrawDebugLine(GetWorld(), Start, End, FColor::Black, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (Hit.bBlockingHit)
		{
			if (Hit.GetActor()->GetClass()->IsChildOf(ADoor::StaticClass()))
			{
				
				door = Cast<ADoor>(Hit.GetActor());
			}
			else
				{
					door = nullptr;
				}
			if (Hit.GetActor()->GetClass()->IsChildOf(AItem::StaticClass()))
			{
				Item = Cast<AItem>(Hit.GetActor());
			}
			else
			{
				Item = nullptr;
			}
		}
	}
	

	ChangeSpead(Check);
}

// Called to bind functionality to input
void AfirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AfirstCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AfirstCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AfirstCharacter::turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AfirstCharacter::LookUp);

	PlayerInputComponent->BindAction(TEXT("Running"), IE_Pressed, this, &AfirstCharacter::RunOn);
	PlayerInputComponent->BindAction(TEXT("Running"), IE_Released, this, &AfirstCharacter::RunOut);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::openDoor);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::PushButten);
	//PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::testWidget);
}

void AfirstCharacter::CallDelegate()
{
	ABLOG_S(Warning);
}

void AfirstCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AfirstCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

void AfirstCharacter::turn(float NewAxisValue)
{
	
	AddControllerYawInput(NewAxisValue);
}

void AfirstCharacter::LookUp(float NewAxisValue)
{
	
	AddControllerPitchInput(NewAxisValue);

}



void AfirstCharacter::ChangeSpead(bool Cheacking)
{
	if (Cheacking)
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	else
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void AfirstCharacter::RunOn()
{
	Check = true;
}
void AfirstCharacter::RunOut()
{
	Check = false;
}

void AfirstCharacter::openDoor()
{
	if (door)
	{
		door->ToggleDoor();
		ABLOG_S(Warning);
	}
}
void AfirstCharacter::testWidget()
{
	Check2 = true;
	ABLOG_S(Warning);
}

void AfirstCharacter::PushButten()
{
	if (Item)
	{
		Item->DownButten();
		ABLOG_S(Warning);
	}
}

