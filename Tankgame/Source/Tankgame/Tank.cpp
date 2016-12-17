// Fill out your copyright notice in the Description page of Project Settings.

#include "Tankgame.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("TurretRotation", this, &ATank::RotateTurret);
	InputComponent->BindAxis("GunElevation", this, &ATank::GunElevator);
	InputComponent->BindAxis("RotateBody", this, &ATank::RotateBody);
	InputComponent->BindAxis("MoveBody", this, &ATank::MoveBody);

}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor On"));
	Turret = TurretFromBP;
}

void ATank::SetGunChildActor(UChildActorComponent * GunFromBP)
{
	Gun = GunFromBP;
}

void ATank::SetBodyChildActor(UChildActorComponent * BodyFromBP)
{
	Body = BodyFromBP;
}


void ATank::RotateBody(float Speed)
{
	if (!Body){return;}
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Body->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}

void ATank::MoveBody(float Speed)
{
	if (!Body){return;}
	float Distance = GetWorld()->DeltaTimeSeconds * Speed * MoveSpeed;
	Body->AddRelativeLocation(Body->GetForwardVector()*Distance);
}

void ATank::GunElevator(float Speed)
{
	if (!Gun) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Gun->AddRelativeRotation(FRotator(Rotation, 0.f, 0.f));
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Turret->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}
