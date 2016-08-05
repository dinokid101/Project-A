// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef SPATIAL_BEHAVIOR_H
//#define SPATIAL_BEHAVIOR_H

#define FGravityAcceleration 9.812

typedef float FSeconds;
typedef float FMiliSeconds;

typedef float FAngle;
typedef float FRadian;
typedef AActor* Object;

//vectorial field functions
namespace Rotation
{
	//rotation functions
	void DeltaComplete    (FSeconds DeltaTime, FSeconds RunningTime, Object AObject);
	void Vertical_Rotation(FSeconds DeltaTime, FSeconds RunningTime, Object AObject);
	
};
namespace Floatation
{
	//floatation functions
	void DeltaFloatation(FSeconds FTime, FSeconds RunningTime, Object AObject);
};
namespace Physics
{
	//misc physics behavior
}






//#endif