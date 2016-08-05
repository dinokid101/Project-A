// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Generic_Projectile.h"


// Sets default values
AGeneric_Projectile::AGeneric_Projectile(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Use a sphere as collision presentation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BulletComp"));
	CollisionComp->InitSphereRadius(15.0f);
	RootComponent = CollisionComp;

	//Use a ProjectileMovementComponent to govern projectile's movement
	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT(" "));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.01f;
}

// Called when the game starts or when spawned
void AGeneric_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneric_Projectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGeneric_Projectile::InitVelocity(const FVector & ShootDirection)
{
	if (ProjectileMovement)
	{
		//set the projectile's velocity to the desired direction
		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
	}
}