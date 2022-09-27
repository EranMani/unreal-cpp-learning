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

	StartLocation = GetActorLocation();

	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (MoveVelocity * DeltaTime);

		SetActorLocation(CurrentLocation);

		float PlatformDistance = FVector::Dist(StartLocation, CurrentLocation);

		// Set the location of platform to the exact distance limit when reached
		if (PlatformDistance > MoveDistance)
		{
			float OverShoot = PlatformDistance - MoveDistance;
			FString ObjectName = GetName();
			UE_LOG(LogTemp, Display, TEXT("[%s] OverShoot distance %f"), *ObjectName, OverShoot);
			//UE_LOG(LogTemp, Display, TEXT("OverShoot distance: %f"), OverShoot);
			FVector MoveDirection = MoveVelocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MoveDistance;
			SetActorLocation(StartLocation);
			MoveVelocity = -MoveVelocity;
		}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("[%s] Rotating.."), *GetName());
}

