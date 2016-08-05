// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef PICKUP_H
//#define PICKUP_H

#include "GameFramework/Actor.h"
#include "FRotating_Decoration.h"
#include "PickUp.generated.h"

UCLASS()
class PROJECTERWIN_API APickUp : public AFRotating_Decoration
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//when the pick up is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();

	virtual void WasCollected_Implementation();

	FORCEINLINE bool const bIsActive();


protected:

	bool bActive;
	
};

//#endif