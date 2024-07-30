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

	FVector CurrentLocation = FVector((-1710.000000, 9570.000000, -1704.000000));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector StartLocation = SetActorLocation();

	CurrentLocation = CurentLocation + MovingVelocity * DeltaTime;

	float movingDist = FVector::dist(StartLocation, CurrentLocation);

	CurrentLocation = GetActorLocation(CurrentLocation);

	if(dist < movingDist){
		movingVelocity = -movingVelocity;
		FVector MovingDirection = movingVelocity.Getsafenormal();
		StartLocation = startLocation * 
	}



}

