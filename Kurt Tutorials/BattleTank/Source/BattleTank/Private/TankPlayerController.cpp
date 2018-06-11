// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	
	
	auto PosessedTank = GetControlledTank();

	if(!PosessedTank){ UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play: not posessed")); }
	else { UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play: %s posessed"), *PosessedTank->GetName()); }

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}