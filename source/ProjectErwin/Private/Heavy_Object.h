// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef HEAVY_OBJECT_H
//#define HEAVY_OBJECT_H

#include "GameFramework/Actor.h"
#include "Heavy_Object.generated.h"

UCLASS()
class PROJECTERWIN_API AHeavy_Object : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeavy_Object();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE UStaticMeshComponent * GetMesh() const
	{
		return Plasa3d;
	}

private:
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, category="Interactive", meta= (AllowPrivateAccess="true"))
	class UStaticMeshComponent * Plasa3d;
	
	
};

//#endif