// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MO(TEXT("/Game/StarterContent/Props/SM_Door"));
	if (MO.Succeeded())
	{
		body->SetStaticMesh(MO.Object);
	}
	static ConstructorHelpers::FObjectFinder<UCurveFloat>KO(TEXT("/Game/Asset/Curve/Door.Door"));
	if (KO.Succeeded())
	{
		DoorCurve = KO.Object;
	}
	RootComponent = body;
	
	open = false;
	
	body->SetRelativeRotation(body->GetRelativeRotation());
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	
		ABLOG_S(Warning);
		/*FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;
		TimelineCallback.BindUFunction(this, FName("ControlDoor"));
		TimelineFinishedCallback.BindUFunction(this, FName("SetState"));
		
		MyTimeline.AddInterpFloat(DoorCurve, TimelineCallback);
		MyTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);
	*/
	
}





// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ControlDoor();
}

void ADoor::ControlDoor()
{
	DoorRotation = body->GetRelativeRotation();
	
	if (open)
	{
		body->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, RotateValue, DoorRotation.Roll)), 0.1f));
	}
	else
	{
		//if(DoorRotation!=FRotator::ZeroRotator)
		body->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f,0.0f, DoorRotation.Roll)), 0.1f));
	}
}

void ADoor::ToggleDoor()
{
	
	APawn* ourPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	FVector PawnLocation = ourPawn->GetActorLocation();
	FVector Direction =GetActorLocation() - PawnLocation;
	
	Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());
	
			if (Direction.X > 0.0f)
			{
				RotateValue = 90.0f;
			}
			else
			{
				RotateValue = -90.0f;
			}
			
			if (open==true&&(RotateValue == 90 || RotateValue == -90))
				open = false;
			else
				open = true;
}


