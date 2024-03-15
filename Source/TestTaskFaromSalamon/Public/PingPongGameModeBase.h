// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PingPongGameModeBase.generated.h"

class APlatformPawn;
class ABallActor;
class APingPongGameStateBase;

DECLARE_MULTICAST_DELEGATE(FOnBeginPlay)

DECLARE_LOG_CATEGORY_EXTERN(LogServerInfo,Log,All)

UCLASS()
class TESTTASKFAROMSALAMON_API APingPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void StartGame();

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;

	FOnBeginPlay OnBeginPlay;

protected:
	int32 PlayerCounter=0;
	
	UPROPERTY(Transient)
	APingPongGameStateBase* GameStateBase=nullptr;

	UPROPERTY(Transient)
	ACameraActor* CameraActor=nullptr;

	UPROPERTY(Transient)
	ABallActor* BallActor=nullptr;

	UPROPERTY(Transient)
	TArray<APlatformPawn*> PlatformPawns;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FVector StartBallLocation=FVector(400,400,100);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FVector StartBallImpulse=FVector(40,40,0);

	virtual void BeginPlay() override;

	void FindActors();
};
