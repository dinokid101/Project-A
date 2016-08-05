// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "FRotating_Decoration.h"

//#define Tck

// Sets default values
AFRotating_Decoration::AFRotating_Decoration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFRotating_Decoration::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFRotating_Decoration::Tick(float DeltaTime)
{
	AAFloating_Object::Tick(DeltaTime);
	FRotator Rot = GetActorRotation();
	float DeltaRotation = (FMath::Sin(*RunningTime_+DeltaTime)+FMath::Sin(DeltaTime));
	Rot.Yaw += DeltaRotation * 5.0f;
	SetActorRotation(Rot);

}

