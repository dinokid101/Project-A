// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Heavy_Object.h"


// Sets default values
AHeavy_Object::AHeavy_Object()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Plasa3d = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plasa 3d"));
	RootComponent = Plasa3d;

	//simulate physics duh
	GetMesh()->SetSimulatePhysics(true);

	//set body mass
	FBodyInstance * BInst = Plasa3d->GetBodyInstance();
	BInst->bOverrideMass = 1;
	BInst->MassInKg=825.0f;
	
}

// Called when the game starts or when spawned
void AHeavy_Object::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeavy_Object::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

