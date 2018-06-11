// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PosessedTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PosessedTank) { UE_LOG(LogTemp, Warning, TEXT("AI controller begin play: not posessed")); }
	else { UE_LOG(LogTemp, Warning, TEXT("AI controller begin play: %s posessed"), *PosessedTank->GetName()); }

	if (!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("AI controller begin play: PlayerController not detected")); }
	else { UE_LOG(LogTemp, Warning, TEXT("AI controller %s targeting player controller %s"), *PosessedTank->GetName(),  *PlayerTank->GetName()); }

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
