// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongPlayerController.h"

#include "Net/UnrealNetwork.h"

APingPongPlayerController::APingPongPlayerController()
{
	bReplicates=true;
}

void APingPongPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APingPongPlayerController,PlatformPawn)
}

void APingPongPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(InputComponent)
	{
		InputComponent->BindAxis("MoveUp",this,&ThisClass::MoveUpAxis);
	}
}

void APingPongPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(APlatformPawn* PlayerPawn=Cast<APlatformPawn>(InPawn))
	{
		PlatformPawn=PlayerPawn;
	}
}

void APingPongPlayerController::MoveUpAxis(float Axis)
{
	if(FMath::IsNearlyEqual(0.,Axis))
	{
		return;
	}
	if(PlatformPawn)
	{
		PlatformPawn->MoveUpAxis(Axis);
	}
}
