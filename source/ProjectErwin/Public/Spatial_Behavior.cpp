// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Spatial_Behavior.h"

void Floatation::DeltaFloatation(FSeconds FTime, FSeconds RunningTime, Object AObject)
{

		FVector NewLocation = AObject->GetActorLocation();
		float DeltaHeight = (FMath::Sin(RunningTime + FTime) - FMath::Sin(RunningTime));
		NewLocation.Z += DeltaHeight * 20.0f;
		RunningTime += FTime;
		AObject->SetActorLocation(NewLocation);
}

void Rotation::DeltaComplete(FSeconds DeltaTime, FSeconds RunningTime, Object AObject)
{
		FRotator Rot = AObject->GetActorRotation();
		float DeltaRotation = (FMath::Sin(RunningTime + DeltaTime) + FMath::Sin(DeltaTime));
		Rot.Yaw += DeltaRotation * 5.0f;
		AObject->SetActorRotation(Rot);
}

void Rotation::Vertical_Rotation(FSeconds DeltaTime, FSeconds RunningTime, Object AObject)
{
	FRotator Rot = AObject->GetActorRotation();
	float DeltaRotation = (FMath::Sin(RunningTime + DeltaTime) + FMath::Sin(DeltaTime));
	Rot.Yaw += DeltaRotation * 5.0f;
	AObject->SetActorRotation(Rot);
}

