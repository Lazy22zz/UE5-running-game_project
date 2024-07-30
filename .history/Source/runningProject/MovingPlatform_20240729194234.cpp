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

	SetActorLocation(CurrentLocation);

	float exact_move_distance = FVector::Dist(StartLocation, CurrentLocation);

	

	if(exact_move_distance > required_move_dist){
		FVector moving_direct = movingVelocity.GetSafeNormal();
		StartLocation = StartLocation + movingVelocity * moving_direct;
		movingVelocity = - movingVelocity;
	}
}


