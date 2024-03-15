// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformPawn.h"
#include "GameFramework/PlayerController.h"
#include "PingPongPlayerController.generated.h"

class APlatformPawn;
/**
 * 
 */
UCLASS()
class TESTTASKFAROMSALAMON_API APingPongPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APingPongPlayerController();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void SetupInputComponent() override;
	
	virtual void OnPossess(APawn* InPawn) override;

	void MoveUpAxis(float Axis);
	
	UPROPERTY(Transient,Replicated)
	APlatformPawn* PlatformPawn;
};