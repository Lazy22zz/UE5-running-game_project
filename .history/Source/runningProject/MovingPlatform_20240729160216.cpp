// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Moving platform forward
		// Get the local platform location
	FVector CurrentLocation = GetActorLocation();

		// provide a forward vector
	CurrentLocation = CurrentLocation + movingVelocity * DeltaTime ;
		
		// Set the actor location
	SetActorLocation(CurrentLocation);

	// Moving platform back
		// check the diff 
	float dist = FVector::Dist(StartLocation, CurrentLocation);

	if (dist > required_stop_distance){
		FVector MovingDirection = MovingPlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MovingDirection * dist;
		MovingPlatformVelocity = - MovingPlatformVelocity;
	}


}


