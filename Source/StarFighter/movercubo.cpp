// Fill out your copyright notice in the Description page of Project Settings.


#include "movercubo.h"
#include "Engine/World.h"

// Sets default values for this component's properties
Umovercubo::Umovercubo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	// ...
}


// Called when the game starts
void Umovercubo::BeginPlay()
{
	Super::BeginPlay();
	TiempoE = GetWorld()->GetRealTimeSeconds();
	cubo = GetOwner();


	// ...
	
}


// Called every frame
void Umovercubo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
		
		

		posiciones.X = velocidad + cubo->GetActorLocation().X;
		posiciones.Y = direccion + cubo->GetActorLocation().Y;
		posiciones.Z = cubo->GetActorLocation().Z;
		cubo->SetActorLocation(posiciones);


		if (GetWorld()->GetRealTimeSeconds() - TiempoE > 3.0f) {

			TiempoE = GetWorld()->GetRealTimeSeconds();
			int numerop = Numrand(1,10);
			if (numerop > 5) {

				direccion *=-1;
			}
			
		}


		if (cubo->GetActorLocation().X > Limitex1 || cubo->GetActorLocation().Y > 500|| cubo->GetActorLocation().X < Limitex2)
		{
			
			velocidad *= -1;
			//cubo->SetActorLocation(FVector(-440, -20, 70));
		}
	

}

void Umovercubo::SetVelocidad(float _velocidad)
{
	velocidad += _velocidad;
}

float Umovercubo::GetVelocidad()
{
	return velocidad;
}

int Umovercubo::Numrand(int min, int max)
{
	return FMath::RandRange(min,max);
}

