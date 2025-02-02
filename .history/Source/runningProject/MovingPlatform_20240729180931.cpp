// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + movingVelocity * DeltaTime;

	float dist_Distance = FVector::Dist(StartLocation, CurrentLocation);

	SetActorLocation(CurrentLocation);

	if(dist < dist_Distance){
		FVector moving_direct = movingVelocity.GetSafeNormal();
		StartLocation = StartLocation + movingVelocity * dist_Distance;
		movingVelocity = -movingVelocity;
	}
}


