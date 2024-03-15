// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallActor.generated.h"

UCLASS()
class TESTTASKFAROMSALAMON_API ABallActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//MARK:Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UFUNCTION()
	void HitActor(UPrimitiveComponent* HitComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FVector Velocity=FVector(300,300,0);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddImpulse(const FVector& Impulse) const;
};
