// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#ifndef FLOATING_OBJECT_H
//#define FLOATING_OBJECT_H

#include "GameFramework/Actor.h"
#include "AFloating_Object.generated.h"

UCLASS()
class PROJECTERWIN_API AAFloating_Object : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAFloating_Object();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE UStaticMeshComponent * ReturnMesh() const
	{
		return Plasa3d;
	};

 protected:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, category="Parameters")
	 TSharedPtr<float> RunningTime_;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Parameters")
	 TSharedPtr<float> FSeconds_;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent * Plasa3d;

 private:

};

//#endif
