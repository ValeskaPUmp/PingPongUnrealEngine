// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PingPongHUD.generated.h"

class UScoreWidget;
/**
 * 
 */
UCLASS()
class TESTTASKFAROMSALAMON_API APingPongHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UScoreWidget> ScoreWidgetClass;

	UPROPERTY(Transient)
	UScoreWidget* ScoreWidget;
};
