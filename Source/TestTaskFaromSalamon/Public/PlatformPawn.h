// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlatformPawn.generated.h"

class UFloatingPawnMovement;
class UCameraComponent;

UCLASS()
class TESTTASKFAROMSALAMON_API APlatformPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlatformPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//MARK:Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float Velocity=5.;

	UFUNCTION(Reliable,Server)
	void UpdateLocation(FVector NewLocation);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveUpAxis(float AxisValue);

};
