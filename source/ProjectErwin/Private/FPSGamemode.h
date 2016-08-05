// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef FPSGAMEMODE_H
//#define FPSGAMEMODE_H

#include "GameFramework/GameMode.h"
#include "FPSGamemode.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTERWIN_API AFPSGamemode : public AGameMode
{
	GENERATED_BODY()
		virtual void StartPlay() override;
	    AFPSGamemode(const FObjectInitializer &ObjectInitializer);
	



	
};

//#endif
