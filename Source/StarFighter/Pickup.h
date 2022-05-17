// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "movercubo.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Pickup.generated.h"


DECLARE_DELEGATE(FPickedupEventSignature)
UCLASS()
class STARFIGHTER_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	UPROPERTY()
		UBoxComponent* TriggerZone;
	UFUNCTION()
		
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//UFUNCTION()
	//virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	UPROPERTY()
		UStaticMeshComponent* MyMesh;
	//movimiento de rotacion
	UPROPERTY()
		URotatingMovementComponent* RotatingComponent;

	FPickedupEventSignature OnPickedUp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
