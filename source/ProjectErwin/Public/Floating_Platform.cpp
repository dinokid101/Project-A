// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Floating_Platform.h"


// Sets default values
AFloating_Platform::AFloating_Platform():
fTimeSpeed(MakeShareable(new float (10.0f))),
fFlyingZ  (MakeShareable(new float (10.0f)))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloating_Platform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloating_Platform::Tick( float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DeltaSeconds = *fTimeSpeed;
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float DeltaHeight = (FMath::Sin(*RunningTime_ + DeltaSeconds) - FMath::Sin(*RunningTime_));
	NewLocation.Z += DeltaHeight * (*fFlyingZ);
	*RunningTime_ += DeltaSeconds;
	SetActorLocation(NewLocation);
}

