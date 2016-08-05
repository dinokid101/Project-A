// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#ifndef SPAWN_VOLUME_H
//#define SPAWN_VOLUME_H

#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "SpawnVolume.generated.h"

UCLASS()
class PROJECTERWIN_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//accessor for spawn location
	FORCEINLINE UBoxComponent * GetLocation() const
	{
		return SpawnLocation;
	}

	//find a random point to spawn
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

protected:
	UPROPERTY(EditAnywhere, Category = "Spawing")
	TSubclassOf<class APickUp> ObjectToSpawn;

	FTimerHandle SpawnTimer;

	//min spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MinDelay;

	//max spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MaxDelay;

private:
	//box component to show spawning location
	UPROPERTY(VisibleAnywhere,BluePrintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	class UBoxComponent * SpawnLocation;

	void SpawnObject();

	//real spawn delay
	float SpawnDelay;
	
};

//#endif