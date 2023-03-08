// Fill out your copyright notice in the Description page of Project Settings.


#include "monster.h"
#include "firstCharacter.h"
#include "Item.h"
// Sets default values
Amonster::Amonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MO(TEXT("/Game/StarterContent/Shapes/Shape_Plane"));
	if (MO.Succeeded())
	{
		body->SetStaticMesh(MO.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>MA(TEXT("/Game/Asset/moster.moster"));
	if (MA.Succeeded())
	{
		Metarial = MA.Object;
	}
	RootComponent = Box;
	
	
	body->SetupAttachment(RootComponent);
	Box->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	body->SetRelativeRotation(FRotator(0.0f, 90.0f, 90.0f));
	body->SetMaterial(0,Metarial);
	moveing = 1.0f;
	OneVector = FVector(moveing,0.0f, 0.0f);
	
}

// Called when the game starts or when spawned
void Amonster::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &Amonster::OnOverlapBegin);
	
}

// Called every frame
void Amonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	Running();
}


void Amonster::Running()
{
	Box->SetRelativeLocation(Box->GetRelativeLocation()+OneVector);
}

void Amonster::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	auto ItemActor = Cast<AItem>(UGameplayStatics::GetActorOfClass(GetWorld(),AItem::StaticClass()));

	if ((OtherActor != this) && (OtherComp != nullptr))
	{
		ABLOG_S(Warning);
	}
}

