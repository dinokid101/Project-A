// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASpawnVolume::ASpawnVolume():
MinDelay(1.0f), MaxDelay(5.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//create box component to represent spawning location
	SpawnLocation = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawning Location"));
	RootComponent = SpawnLocation;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	SpawnDelay = FMath::FRandRange(MinDelay, MaxDelay);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnObject, SpawnDelay);
	
}

// Called every frame
void ASpawnVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin = SpawnLocation->Bounds.Origin;
	FVector SpawnExtent = SpawnLocation->Bounds.BoxExtent;

	const FVector BoxMin = SpawnOrigin - SpawnExtent;
	const FVector BoxMax = SpawnOrigin + SpawnExtent;
	return FMath::RandPointInBox(FBox(BoxMin, BoxMax));
}

void ASpawnVolume::SpawnObject()
{
	//check if we got something to spawn
	if (ObjectToSpawn)
	{
		//check if there's a valid world
		UWorld * const World = GetWorld();
		if (World)
		{
			//set spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			//get a random spawn location
			FVector SpawnLocation = GetRandomPointInVolume();

			//get a random rotation
			FRotator SpawnRotation;
			SpawnRotation.Yaw   = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll  = FMath::FRand() * 360.0f;

			//spawn the object
			APickUp * const Object= World->SpawnActor<APickUp>(ObjectToSpawn, SpawnLocation, SpawnRotation);

			SpawnDelay = FMath::FRandRange(MinDelay, MaxDelay);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnObject, SpawnDelay);
		}
	}
}
