// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "AFloating_Object.h"


// Sets default values
AAFloating_Object::AAFloating_Object():
FSeconds_    (MakeShareable((new float(5)))),
RunningTime_ (MakeShareable((new float(0))))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Plasa3d = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plasa3d"));
	RootComponent = Plasa3d;
}

// Called when the game starts or when spawned
void AAFloating_Object::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAFloating_Object::Tick( float DeltaTime )
{   
	Super::Tick( *FSeconds_ );
	/*
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(*RunningTime_ + *FSeconds_) - FMath::Sin(*RunningTime_));
	NewLocation.Z += DeltaHeight * 20.0f;
	*RunningTime_ += *FSeconds_;
	SetActorLocation(NewLocation);*/
}

