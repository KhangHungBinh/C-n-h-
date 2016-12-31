// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankGun.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class TANKGAME_API UTankGun : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 30;//TODO Set
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = -10;//TODO Set

};
