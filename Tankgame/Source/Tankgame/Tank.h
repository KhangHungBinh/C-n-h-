// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void SetTurretChildActor(UChildActorComponent*TurretFromBP);
	
	UFUNCTION(BlueprintCallable, Category = "Tank")
		void SetGunChildActor(UChildActorComponent*GunFromBP);

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void SetBodyChildActor(UChildActorComponent*BodyFromBP);


private:
	void RotateBody(float Speed);
	void MoveBody(float Speed);
	void GunElevator(float Speed);
	void RotateTurret(float Speed);
	UChildActorComponent*Body = nullptr;
	UChildActorComponent*Turret = nullptr;
	UChildActorComponent*Gun = nullptr;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 120.f;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 120.f;
};
