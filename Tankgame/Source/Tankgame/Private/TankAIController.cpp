// Fill out your copyright notice in the Description page of Project Settings.

#include "Tankgame.h"
#include "TankAIController.h"
#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is not looking for anything"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is looking for %s"), *(PlayerTank->GetName()));
	}

}

ATank * ATankAIController::GetControlledTank()
{
	return	Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}
