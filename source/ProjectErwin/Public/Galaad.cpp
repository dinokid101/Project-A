// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Galaad.h"
#include "Damage.h"
#include "Generic_Effect.h"
#include "Generic_Projectile.h"
#include "PickUp.h"

typedef void * Wp_PH;
typedef void * Am_PH;
typedef void * HP_PH;
typedef void * EF_PH;

class AGalaad::Galaad_Impl
{
public:
	//constructors: basic, move and copy
	 //destructor, tough RAII is used
	 Galaad_Impl();
	~Galaad_Impl();
	 Galaad_Impl(Galaad_Impl & other);
	 Galaad_Impl(Galaad_Impl && other);

	 //copy and move assignement operators
	 Galaad_Impl & operator=(Galaad_Impl & other);
	 Galaad_Impl & operator=(Galaad_Impl && other);

	 //stats accessor functions
	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
	     FORCEINLINE float GetTotalHP() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE float GetCurrentHP() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE float GetMinDamage() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE float GetMaxDamage() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE _int16 WeapontCount() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE _int32 GetKillCount() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE _int32 GetDeathCount() const;

	 UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		 FORCEINLINE float GetDefense() const;

private:
	
	//player stats
	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	   TSharedPtr<float> Min_Damage_;

	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	   TSharedPtr<float> Max_Damage_;

	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	    TSharedPtr<float> Defense_;

	UPROPERTY(EditDefaultsOnly, Category = "Stats")
		TSharedPtr<float> HP_Total_;

	UPROPERTY(EditDefaultsOnly, Category = "Stats")
		TSharedPtr<float> HP_Current_;

	UPROPERTY(EditDefaultsOnly, Category = "Count")
		TSharedPtr<_int16> Weapon_Count_;

	UPROPERTY(EditDefaultsOnly, Category = "Count")
	    TSharedPtr<_int64> Kill_Count_;

	UPROPERTY(EditDefaultsOnly, Category = "Count")
		TSharedPtr<_int64> Death_Count_;

	TArray<TSharedPtr<Stats::Generic_Effect>> eApplied_Effects;

	//UPROPERTY(EditDefaultsOnly, Category ="PlayerCondition", Replicated)
//	float HP_Total_;

	// private functions
	UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		float CalculateDamage() const;

	UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		float AverageDamage() const;

	UFUNCTION(BluePrintCallable, Category = "PlayerStat")
		float ReduceDamage() const;

	UFUNCTION(BluePrintCallable, Category = "PlayerStat")
	  float const UseRange = 2.8;

};

AGalaad::Galaad_Impl::Galaad_Impl() :
Min_Damage_  (MakeShareable((new float(0)))),
Max_Damage_  (MakeShareable((new float(0)))),
Defense_     (MakeShareable((new float(0)))),
HP_Total_    (MakeShareable((new float(100.0f)))),
HP_Current_  (MakeShareable((new float(100.0f)))),
Weapon_Count_(MakeShareable((new _int16(1)))),
Kill_Count_  (MakeShareable((new _int64(0)))),
Death_Count_ (MakeShareable((new _int64(0))))
{  }

FORCEINLINE float AGalaad::Galaad_Impl::GetTotalHP() const
{
	return *HP_Total_;
}

FORCEINLINE float AGalaad::Galaad_Impl::GetCurrentHP()const
{
	return *HP_Current_;
}

FORCEINLINE float AGalaad::Galaad_Impl::GetMinDamage() const
{
	return *Min_Damage_;
}

FORCEINLINE float AGalaad::Galaad_Impl::GetMaxDamage() const
{
	return *Max_Damage_;
}

FORCEINLINE _int16 AGalaad::Galaad_Impl::WeapontCount() const
{
	return *Weapon_Count_;
}

FORCEINLINE _int32 AGalaad::Galaad_Impl::GetKillCount() const
{
	return *Kill_Count_;
}

FORCEINLINE _int32 AGalaad::Galaad_Impl::GetDeathCount() const
{
	return *Death_Count_;
}

FORCEINLINE float AGalaad::Galaad_Impl::GetDefense() const
{
	return *Defense_;
}

float AGalaad::Galaad_Impl::CalculateDamage() const
{
	return 0;
}

float AGalaad::Galaad_Impl::AverageDamage() const
{
	return (*Max_Damage_/(*Min_Damage_));
}

float AGalaad::Galaad_Impl::ReduceDamage() const
{
	return 0;
}


// Sets default values
AGalaad::AGalaad(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//add 1st person camera
	FPSViewComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>
		(this, TEXT("First Person Camera"));
	FPSViewComponent->AttachParent = GetCapsuleComponent();

	//set camera position
	FPSViewComponent->RelativeLocation= FVector(0, 0, 50.0f +BaseEyeHeight);
	FPSViewComponent->bUsePawnControlRotation = true;

	//initiate 1st person mesh, turn shadows off
	FirstPersonMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>
		(this, TEXT("First Person Mesh"));
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->AttachParent = FPSViewComponent;
	FirstPersonMesh->bCastDynamicShadow = false;
	FirstPersonMesh->CastShadow = false;

	//3rd person mesh is invisible
	GetMesh()->SetOwnerNoSee(true);

	//movement specifications
	UCharacterMovementComponent * Misca= GetCharacterMovement();
	Misca->GravityScale = 1.5f ;
	Misca->JumpZVelocity = 620;
	Misca->bCanWalkOffLedgesWhenCrouching= true;
	Misca->MaxWalkSpeedCrouched = 200 ;

	//can crouch
	Misca->GetNavAgentPropertiesRef().bCanCrouch = true;

	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collection Sphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(2000.0f);
}

// Called when the game starts or when spawned
void AGalaad::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Let's kill some spiders!"));
	}
	
}

// Called every frame
void AGalaad::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	CollectPickUp();

}


void AGalaad::SetupPlayerInputComponent(UInputComponent *InputComponent)
{
	//keybindings
	InputComponent->BindAxis("MoveForward", this, &AGalaad::MoveForward); //W-S
	InputComponent->BindAxis("MoveRight"  , this, &AGalaad::MoveRight  ); // A-D

	//mouse
	InputComponent->BindAxis("Turn", this, &AGalaad::AddControllerYawInput); //Left-Right
	InputComponent->BindAxis("LookUp", this, &AGalaad::AddControllerPitchInput); //Up-Down

	//jumping

	InputComponent->BindAction("Jump", IE_Pressed, this, &AGalaad::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AGalaad::OnStopJump);

	InputComponent->BindAction("Collect", IE_Pressed, this, &AGalaad::CollectPickUp);

}

void AGalaad::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//get forward movement
		FRotator Rotation = Controller->GetControlRotation();
		//limit pitch when walking or falling 
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		//add movement
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}


}

void AGalaad::MoveRight(float Value)
{

	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}

}

void AGalaad::OnStartJump()
{
	bPressedJump = true;
}

void AGalaad::OnStopJump()
{
	bPressedJump = false;
};

bool AGalaad::IsDead()
{
	return (this->PMPL->GetCurrentHP() <= 0 ? true : false);
}


AGalaad * AGalaad::GetUsableInView()
{
FVector  CamLoc;
FRotator CamRot;

if (Controller == NULL)
return NULL;

//finds camera direction and point of view start and direction
Controller->GetPlayerViewPoint(CamLoc, CamRot);
const FVector TraceStart = CamLoc;
const FVector Direction  = CamRot.Vector();
const FVector TraceEnd   = TraceStart+(Direction * 2.8);

FCollisionQueryParams TraceParams(FName(TEXT("TraxeUsableActor")), true, this);
TraceParams.bTraceAsyncScene = true;
TraceParams.bReturnPhysicalMaterial = false;
TraceParams.bTraceComplex = true;

//FHitResult is passed in with trace function and holds the result
FHitResult Hit(ForceInit);
//GetWorld()->LineTraceSingle(Hit, TraceStart, TraceEnd, ECC_Visibility, FColor::Red, false);

return Cast<AGalaad>(Hit.GetActor());
}

void AGalaad::TriggerOn()
{

}

void AGalaad::TriggerOff()
{

}

void AGalaad::CollectPickUp()
{
	//get all overlapping actors into an array
	TArray<AActor*> Collected;
	CollectionSphere->GetOverlappingActors(Collected);
	//for each actor
	for (int32 current = 0; current<Collected.Num();++current)
	{ 
	    //cast actor o pick-up
		APickUp* const Test = Cast<APickUp>(Collected[current]);

	    //if the cast is succesful
		if (Test && !Test->IsPendingKill() && Test->bIsActive())
		{ 
	        //call pick-up collected pick-up
			Test->WasCollected();
	        //remove pick-up
			Test->Destroy();
		}
	}
}