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

	moving_platform(DeltaTime);

	rotating_platform(DeltaTime);
}

void AMovingPlatform::moving_platform(float DeltaTime)
{
	

	if(shouldPlatformReturn()){
		FVector moving_direct = movingVelocity.GetSafeNormal();
		StartLocation = StartLocation + moving_direct * FVector::Dist(StartLocation, GetActorLocation());
		movingVelocity = - movingVelocity;
	}
	else{
		FVector CurrentLocation = GetActorLocation();

		CurrentLocation = CurrentLocation + movingVelocity * DeltaTime;

		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::rotating_platform(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("this is a rotating_platform function"));
}


bool AMovingPlatform::shouldPlatformReturn()
{
	float exact_move_distance = GetDistanceMoved();
	return exact_move_distance > required_move_dist;
}

float AMovingPlatform::GetDistanceMoved() const
{
	float return_value = 0.0;
	return_value = FVector::Dist(StartLocation, GetActorLocation());
	return return_value;
}

