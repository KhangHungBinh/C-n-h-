// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponents.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankGun;

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankGun* BarrelToSet);
protected:
	UTankAimingComponents* TankAimingComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 80000;
};
