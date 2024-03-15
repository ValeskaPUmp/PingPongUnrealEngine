// Fill out your copyright notice in the Description page of Project Settings.


#include "GateActor.h"

#include "BallActor.h"
#include "PingPongGameStateBase.h"
#include "Components/BoxComponent.h"


// Sets default values
AGateActor::AGateActor()
{
	MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	BoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(MeshComponent);
	BoxComponent->SetupAttachment(MeshComponent);
	MeshComponent->SetIsReplicated(false);
	MeshComponent->BodyInstance.bSimulatePhysics=false;
}

// Called when the game starts or when spawned
void AGateActor::BeginPlay()
{
	Super::BeginPlay();
	if (GetNetMode()<NM_Client)//All overlaps handle only on server
	{
		BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::OnActorOverlap);
	}
}

void AGateActor::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if(OtherActor->IsA<ABallActor>())
	{
		if(APingPongGameStateBase* GameStateBase=Cast<APingPongGameStateBase>(GetWorld()->GetGameState()))
		{
			switch (Side)
			{
			case EPlayerSide::Right:
				GameStateBase->AddPointLeftSide();
				break;
			case EPlayerSide::Left:
				GameStateBase->AddPointRightSide();
				break;
			}
		}
	}
	
}

