// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h" 
#include "movercubo.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(100, 100, 100));

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");

	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingComponent");
	RootComponent = MyMesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/SM_Pixel_Enemy_1.SM_Pixel_Enemy_1'"));

	if (MeshAsset.Object != nullptr)
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}

	MyMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RotatingComponent->RotationRate = FRotator(10, 0, 10);

	


}

void APickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickedUp.ExecuteIfBound();
	auto Message = FString::Printf(TEXT("%s me disparo  "), *(OtherActor->GetName()));
	
	//auto Message = FString::Printf(TEXT("%s la velocidad es "),(velocidad));
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);



}
// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

