// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef FIRSTAIDKIT_H
//#define FIRSTAIDKIT_H


#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "FirstAidKit.generated.h"

UCLASS()
class PROJECTERWIN_API AFirstAidKit : public APickUp
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstAidKit();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//override WasCollected
	void WasCollected_Implementation() override;


private:

	class FAid_Priv;
	FAid_Priv * PMPL;
	
	
};

//#endif
