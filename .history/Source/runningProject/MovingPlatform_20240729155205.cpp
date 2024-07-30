// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	FVector StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurentLocation + MovingVelocity * DeltaTime;

	float movingDist = FVector::dist(StartLocation, CurrentLocation);

	CurrentLocation = SetActorLocation(CurrentLocation);

	if(dist < movingDist){
		FVector MovingDirection = movingVelocity.GetSafeNormal();
		StartLocation = startLocation * movingDist * MovingDirection;
		movingVelocity = -movingVelocity;
	}



}

