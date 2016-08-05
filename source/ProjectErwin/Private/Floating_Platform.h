// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef FLOATING_PLATFORM_H
//#define FLOATING_PLATFORM_H

#include "GameFramework/Actor.h"
#include "AFloating_Object.h"
#include "Floating_Platform.generated.h"

UCLASS()
class PROJECTERWIN_API AFloating_Platform : public AAFloating_Object
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloating_Platform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	//UPROPERTY(EditAnywhere,BlueprintReadWrite, category = "DeltaValue")
		TSharedPtr<float> fFlyingZ;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite, category = "DeltaValue")
		TSharedPtr<float> fTimeSpeed;
	
	
};

//#endif