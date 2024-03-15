// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPawn.h"

#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APlatformPawn::APlatformPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled=true;
	
	StaticMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	FloatingPawnMovement=CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	SetRootComponent(StaticMesh);

	//Setup replication
	StaticMesh->SetIsReplicated(true);
	StaticMesh->BodyInstance.bLockZTranslation=true;
	StaticMesh->BodyInstance.bLockYTranslation=true;
	StaticMesh->BodyInstance.bSimulatePhysics=false;
}

// Called when the game starts or when spawned
void APlatformPawn::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformPawn::UpdateLocation_Implementation(FVector NewLocation)
{
	SetActorLocation(NewLocation);
}

void APlatformPawn::MoveUpAxis(float Axis)
{
	FVector ResultVector=FVector(Velocity*Axis,0.,0.);
	AddMovementInput(ResultVector);
	UpdateLocation(GetActorLocation());
}

// Called every frame
void APlatformPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlatformPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

