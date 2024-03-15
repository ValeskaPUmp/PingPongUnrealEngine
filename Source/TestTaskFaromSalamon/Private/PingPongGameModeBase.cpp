// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongGameModeBase.h"

#include "BallActor.h"
#include "EngineUtils.h"
#include "PingPongGameStateBase.h"
#include "PlatformPawn.h"
#include "Camera/CameraActor.h"

DEFINE_LOG_CATEGORY(LogServerInfo)

void APingPongGameModeBase::StartGame()
{
	BallActor->SetActorLocation(StartBallLocation);
	const float ImpulseX=FMath::RandBool()?StartBallImpulse.X:StartBallImpulse.X*-1;
	const float ImpulseY=FMath::RandBool()?StartBallImpulse.Y:StartBallImpulse.Y*-1;
	BallActor->AddImpulse(FVector(ImpulseX,ImpulseY,0));
}

void APingPongGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if(PlatformPawns.IsEmpty())
	{
		OnBeginPlay.AddUObject(this,&ThisClass::PostLogin,NewPlayer);
		return;
	}

	check(PlayerCounter<2)
	NewPlayer->Possess(PlatformPawns[PlayerCounter]);
	NewPlayer->SetViewTarget(CameraActor);
	++PlayerCounter;
	UE_LOG(LogServerInfo,Log,TEXT("Player %d joined to game."),PlayerCounter);
	if(PlayerCounter==2)
	{
		StartGame();
		GameStateBase->SetGameState(EGameState::Playing);
		UE_LOG(LogServerInfo,Log,TEXT("Starting game"))
	}else{
		GameStateBase->SetGameState(EGameState::WaitForPlayer);
	}
}

APawn* APingPongGameModeBase::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
	return nullptr;
}

void APingPongGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GameStateBase=Cast<APingPongGameStateBase>(GetWorld()->GetGameState());
	FindActors();
	OnBeginPlay.Broadcast();
}

void APingPongGameModeBase::FindActors()
{
	TActorRange<ACameraActor> CameraActors(GetWorld());
	int i=0;
	for(ACameraActor* Camera:CameraActors)
	{
		check(i==0)//check whether the world contains only one camera.
		CameraActor=Camera;
		++i;
	}

	TActorRange<ABallActor> BallActors(GetWorld());
	int k=0;
	for(ABallActor* Ball:BallActors)
	{
		check(k==0)//check whether the world contains only one ball.
		BallActor=Ball;
		++k;
	}

	TArray<AActor*> Pawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),APlatformPawn::StaticClass(),Pawns);
	check(Pawns.Num()==2)//check whether the world contains only two platform pawns.
	PlatformPawns.Add(Cast<APlatformPawn>(Pawns[0]));
	PlatformPawns.Add(Cast<APlatformPawn>(Pawns[1]));
}

