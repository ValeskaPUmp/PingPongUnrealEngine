// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"

#include "PingPongGameStateBase.h"
#include "Components/EditableTextBox.h"

void UScoreWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if(APingPongGameStateBase* GameStateBase=Cast<APingPongGameStateBase>(GetWorld()->GetGameState()))
	{
		GameStateBase->OnScoreUpdated.AddUObject(this,&ThisClass::UpdateScore);
		GameStateBase->OnGameStateChanged.AddUObject(this,&ThisClass::GameStateChange);
	}
}

void UScoreWidget::UpdateScore(int32 LeftSidePoints, int32 RightSizePoints)
{
	LeftScoreTextBlock->SetText(FText::AsNumber(LeftSidePoints));
	RightScoreTextBlock->SetText(FText::AsNumber(RightSizePoints));
}

void UScoreWidget::GameStateChange(EGameState GameState)
{
	CurrentGameStateTextBlock->SetText(UEnum::GetDisplayValueAsText(GameState));
}
