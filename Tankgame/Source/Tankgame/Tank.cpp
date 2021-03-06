// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponents.h"
#include "Tankgame.h"
#include "Tank.h"


void ATank::SetBarrelReference(UTankGun* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//No need to protect pointers added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponents>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


