// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GateActor.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class EPlayerSide:uint8
{
	None UMETA(DisplayName="None"),
	Right UMETA(DisplayName="Right Side"),
	Left UMETA(DisplayName="Left Side")
};

UCLASS()
class TESTTASKFAROMSALAMON_API AGateActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//MARK:Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly)
	EPlayerSide Side=EPlayerSide::None;
};
