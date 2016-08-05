// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "PickUp.h"


// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//this->SetActorEnableCollision(false);

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APickUp::WasCollected_Implementation()
{
	FString PickUpDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("%s collected"), *PickUpDebugString)
}

bool const APickUp::bIsActive()
{
	return bActive;
}
