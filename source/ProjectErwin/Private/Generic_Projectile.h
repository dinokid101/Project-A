// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef GENERIC_PROJECTILE_H
//#define GENERIC_PROJECTILE_H

#include "GameFramework/Actor.h"
#include "Generic_Projectile.generated.h"

UCLASS()
class PROJECTERWIN_API AGeneric_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneric_Projectile(const FObjectInitializer & ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
		USphereComponent * CollisionComp;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Movement")
		UProjectileMovementComponent * ProjectileMovement;

	//inits velocity in the shoot direction
	void InitVelocity(const FVector & ShootDirection);
	
};

//#endif