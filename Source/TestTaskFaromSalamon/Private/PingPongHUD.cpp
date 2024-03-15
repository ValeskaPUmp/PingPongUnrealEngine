// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongHUD.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ScoreWidget.h"

void APingPongHUD::BeginPlay()
{
	Super::BeginPlay();
	ScoreWidget=CreateWidget<UScoreWidget>(UGameplayStatics::GetPlayerController(GetWorld(),0),ScoreWidgetClass);
	if(ScoreWidget)
	{
		ScoreWidget->AddToViewport();
	}
}
