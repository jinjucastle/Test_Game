// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Door.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	wall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALL"));
	butten = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTEN"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MQ(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	if (MQ.Succeeded())
	{
		wall->SetStaticMesh(MQ.Object);
		butten->SetStaticMesh(MQ.Object);

	}
	
	wall->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.1f));
	
	RootComponent = wall;
	butten->SetupAttachment(wall);
	butten->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.5));
	butten->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	Box->SetupAttachment(wall);
	Box->InitBoxExtent(FVector(32.0f, 200.0f, 900.0f));
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::DownButten()
{ 
	butten->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto DoorP = Cast<ADoor>(UGameplayStatics::GetActorOfClass(GetWorld(), ADoor::StaticClass()));

	if ((OtherActor != this) && (OtherComp != nullptr))
	{
		ABLOG_S(Warning);
	}
}

