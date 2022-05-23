// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "movercubo.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFIGHTER_API Umovercubo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Umovercubo();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		float velocidad=5.0 ;
	UPROPERTY(EditAnywhere)
		float Limitex1=500.0 ;
	UPROPERTY(EditAnywhere)
		float Limitex2 =-500.0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:

	AActor* cubo;
	UPROPERTY(EditAnywhere)
		FVector posiciones ;
	float* p_velocidad = & velocidad;
	void SetVelocidad(float _velocidad);
	float GetVelocidad();
	int RandMax=10;
	int RandMin=1;
	int Numrand(int, int);
	float TiempoE;
	float direccion = 5.0;
};
