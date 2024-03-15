// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PingPongGameStateBase.generated.h"
class APingPongGameModeBase;

DECLARE_LOG_CATEGORY_EXTERN(PingPongLog, Log, All)

UENUM(BlueprintType)
enum class EGameState:uint8
{
	None UMETA(DispayName="None"),
	Playing UMETA(DisplayName="Playing"),
	WaitForPlayer UMETA(DisplayName="Wait for player")
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged,EGameState);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnScoreUpdated,int32,int32);

UCLASS()
class TESTTASKFAROMSALAMON_API APingPongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual  void BeginPlay() override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	void AddPointLeftSide();

	void AddPointRightSide();

	void SetGameState(EGameState GameState);

	FOnScoreUpdated OnScoreUpdated;

	FOnGameStateChanged OnGameStateChanged;
protected:
	UPROPERTY(ReplicatedUsing=OnRep_LeftSidePoints)
	int32 LeftSidePoints=0;

	UPROPERTY(ReplicatedUsing=OnRep_RightSidePoints)
	int32 RightSidePoints=0;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentGameState)
	EGameState CurrentGameState=EGameState::None;

	UPROPERTY(Transient)
	APingPongGameModeBase* GameModeBase=nullptr;

	UFUNCTION()
	void OnRep_LeftSidePoints();

	UFUNCTION()
	void OnRep_RightSidePoints();

	UFUNCTION()
	void OnRep_CurrentGameState();
	
};
