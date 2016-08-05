// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef GALAAD_H
//#define GALAAD_H

#include "GameFramework/Character.h"
#include "Galaad.generated.h"

UCLASS()
class PROJECTERWIN_API AGalaad : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGalaad(const FObjectInitializer& ObjectIntializer); //CONSTRUCTOR

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//jumping functions
	UFUNCTION()
		void OnStartJump();
	UFUNCTION()
		void OnStopJump();

	//shooting option
	UFUNCTION()
		void TriggerOn();
	UFUNCTION()
		void TriggerOff();

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera)
        UCameraComponent * FPSViewComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent * FirstPersonMesh;

	UFUNCTION()
	AGalaad * GetUsableInView();

	FORCEINLINE class USphereComponent * GetCollectionSphere() const
	{
		return CollectionSphere;
	}
	
	UFUNCTION(BlueprintCallable, category = "Pick-Up")
		void CollectPickUp();

   protected:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	//movement functions
	UFUNCTION()
		void MoveForward(float Val);
	UFUNCTION()
		void MoveRight  (float Val);

	// check if the character is dead, i.e: hp is 0
	UFUNCTION()
		bool IsDead();

   private:
	   //class for containing private values, using the pimpl idiom
	   //create encapsulation process for data
	   class Galaad_Impl;
	   Galaad_Impl * PMPL;

	   UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Pick-Up", meta = (AllowPrivateAccess = "true"))
	   class USphereComponent* CollectionSphere;

	   //called when 
	 

};

//#endif