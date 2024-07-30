// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class RUNNINGPROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FVector StartLocation = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, category = "MovingPlatform")
	float required_move_dist = 0;

	UPROPERTY(EditAnywhere, category = "MovingPlatform")
	FVector movingVelocity = FVector(10, 0, 0);

private:
	void moving_platform(float DeltaTime);

	void rotating_platform(float DeltaTime);

	bool ShouldPlatformReturn();

};	
