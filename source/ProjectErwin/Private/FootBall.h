// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef FOOTBALL_H
//#define FOOTBALL_H

#include "GameFramework/Actor.h"
#include "FootBall.generated.h"

UCLASS()
class PROJECTERWIN_API AFootBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFootBall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE UStaticMeshComponent * GetMesh() const
	{
		return Plasa3d;
	}

protected:
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, category = "Interactive", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent * Plasa3d;
	
};

//#endif