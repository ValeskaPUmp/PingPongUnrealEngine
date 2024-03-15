// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongGameStateBase.h"

#include "PingPongGameModeBase.h"
#include "Net/UnrealNetwork.h"

DEFINE_LOG_CATEGORY(PingPongLog)
void APingPongGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	if(GetNetMode()<NM_Client)
	{
		GameModeBase=Cast<APingPongGameModeBase>(GetWorld()->GetAuthGameMode());
	}
}

void APingPongGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ThisClass,LeftSidePoints);
	DOREPLIFETIME(ThisClass,RightSidePoints);
	DOREPLIFETIME(ThisClass,CurrentGameState);
}

void APingPongGameStateBase::AddPointLeftSide()
{
	++LeftSidePoints;
	UE_LOG(PingPongLog,Log,TEXT("Current score: (%d)|(%d)"),LeftSidePoints,RightSidePoints)
	if(GameModeBase)
	{
		GameModeBase->StartGame();
	}
}

void APingPongGameStateBase::AddPointRightSide()
{
	++RightSidePoints;
	UE_LOG(PingPongLog,Log,TEXT("Current score: (%d)|(%d)"),LeftSidePoints,RightSidePoints)
	if(GameModeBase)
	{
		GameModeBase->StartGame();
	}
}

void APingPongGameStateBase::SetGameState(EGameState GameState)
{
	CurrentGameState=GameState;
}

void APingPongGameStateBase::OnRep_LeftSidePoints()
{
	OnScoreUpdated.Broadcast(LeftSidePoints,RightSidePoints);
}

void APingPongGameStateBase::OnRep_RightSidePoints()
{
	OnScoreUpdated.Broadcast(LeftSidePoints,RightSidePoints);
}

void APingPongGameStateBase::OnRep_CurrentGameState()
{
	OnGameStateChanged.Broadcast(CurrentGameState);
}
