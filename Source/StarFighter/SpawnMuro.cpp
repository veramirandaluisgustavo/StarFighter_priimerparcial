// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnMuro.h"

// Sets default values
ASpawnMuro::ASpawnMuro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnMuro::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

