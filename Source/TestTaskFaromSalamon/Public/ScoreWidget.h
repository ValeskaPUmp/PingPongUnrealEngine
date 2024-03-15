// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UEditableTextBox;
enum class EGameState : uint8;
UCLASS()
class TESTTASKFAROMSALAMON_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	
	void UpdateScore(int32 LeftSidePoints,int32 RightSizePoints);
	
	void GameStateChange(EGameState GameState);

	//MARK:Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(BindWidget))
	UEditableTextBox* LeftScoreTextBlock;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(BindWidget))
	UEditableTextBox* RightScoreTextBlock;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(BindWidget))
	UEditableTextBox* CurrentGameStateTextBlock;
};
