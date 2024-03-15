// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"

#include "PlatformPawn.h"
#include "Engine/StaticMeshActor.h"


// Sets default values
ABallActor::ABallActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	MeshComponent->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	if (GetNetMode()<NM_Client)//All hits handle only on server
	{
		MeshComponent->OnComponentHit.AddDynamic(this,&ThisClass::HitActor);
	}
}

void ABallActor::HitActor(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor->IsA<APlatformPawn>() || OtherActor->IsA<AStaticMeshActor>())
	{
		FVector ActorVelocity=GetVelocity();
		ActorVelocity.Normalize();
		AddImpulse(ActorVelocity);
	}
	
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallActor::AddImpulse(const FVector& Impulse) const
{
	MeshComponent->AddImpulse(Impulse*Velocity,NAME_None,true);
}

