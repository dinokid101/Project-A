// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h" // all hail our spider lord and messiah
#include "FPSGamemode.h"
#include "Engine.h"
#include "Galaad.h"



AFPSGamemode::AFPSGamemode(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject
		(TEXT("Pawn'/Game/Models/Placeholder/BluePrint_MainChar.BluePrint_MainChar_C'")); //model

	if (PlayerPawnObject.Class != NULL)
		DefaultPawnClass = PlayerPawnObject.Class;

}
//^(?([^\r\n])\s)*[^\s+?/]+[^\n]*$

void AFPSGamemode::StartPlay() //when starting
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO HEROES"));
	}

}
