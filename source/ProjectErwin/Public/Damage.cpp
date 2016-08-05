// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Damage.h"

using namespace Stats;

Damage::Damage(const Damage_Type & ttype, const float & fmin, const float & fmax,
	              const float & fDuration=0, const bool & bIsBomb=false):
	tType       (MakeShareable((new Damage_Type(ttype)))),
	dTotal_Timer(MakeShareable((new float(fDuration)))),
	fMinDamage  (MakeShareable((new float(fmin)))),
	fMaxDamage  (MakeShareable((new float(fmax)))),
	bIsBombType (bIsBomb)
{
	bIsDirect   = *dTotal_Timer == 0 ? true : false;
	bIsOverTime = *dTotal_Timer &&  !bIsBombType ? true : false;
};

Damage::Damage(const TArray<TSharedPtr<Damage_Type>> & ttype, const float & fmin, const float & fmax,
	           const float & fDuration = 0, const bool & bIsBomb = false) :
	tType(MakeShareable(new Damage_Type(Damage_Type::Multiple))),
	dTotal_Timer (MakeShareable((new float(fDuration)))),
	fMinDamage   (MakeShareable((new float(fmin)))),
	fMaxDamage   (MakeShareable((new float(fmax)))),
	MultipleTypes(ttype),
	bIsBombType  (bIsBomb)
{
	bIsDirect   = *dTotal_Timer == 0 ? true : false;
	bIsOverTime = *dTotal_Timer &&  !bIsBombType ? true : false;
};

Damage::~Damage()
{
		//delete bIsBombType;
		//delete bIsDirect;
		//delete IsMultipleTypes;
}

Stats::Damage::Damage(const Damage & other)
{
	this->bIsOverTime = other.bIsOverTime;
	this->bIsBombType = other.bIsBombType;
	this->bIsDirect = other.bIsDirect;
	this->IsMultipleTypes = other.IsMultipleTypes;
	this->MultipleTypes = other.MultipleTypes;

	this->tType = other.tType;
	this->dTotal_Timer = other.dTotal_Timer;
	this->dRemaining_Time = other.dRemaining_Time;

	this->fMinDamage = other.fMinDamage;
	this->fMaxDamage = other.fMaxDamage;

}

Stats::Damage::Damage(Damage && other)
{
	this->bIsOverTime = other.bIsOverTime;
	this->bIsBombType = other.bIsBombType;
	this->bIsDirect = other.bIsDirect;
	this->IsMultipleTypes = other.IsMultipleTypes;
	this->MultipleTypes = other.MultipleTypes;

	this->tType = other.tType;
	this->dTotal_Timer = other.dTotal_Timer;
	this->dRemaining_Time = other.dRemaining_Time;

	this->fMinDamage = other.fMinDamage;
	this->fMaxDamage = other.fMaxDamage;

	other.tType           = nullptr;
	other.dTotal_Timer    = nullptr;
	other.dRemaining_Time = nullptr;

	other.fMinDamage = nullptr;
	other.fMaxDamage = nullptr;

	other.bIsOverTime     = nullptr;
	other.bIsBombType     = nullptr;
	other.bIsDirect       = nullptr;
	other.IsMultipleTypes = nullptr;
	//if(other.MultipleTypes.Empty()).RemoveAll();
}

Damage & Stats::Damage::operator=(const Damage & other)
{

	this->bIsOverTime = other.bIsOverTime;
	this->bIsBombType = other.bIsBombType;
	this->bIsDirect   = other.bIsDirect;
	this->IsMultipleTypes = other.IsMultipleTypes;
	this->MultipleTypes= other.MultipleTypes;

	this->tType=other.tType;
	this->dTotal_Timer=other.dTotal_Timer;
	this->dRemaining_Time=other.dRemaining_Time;

	this->fMinDamage=other.fMinDamage;
	this->fMaxDamage=other.fMaxDamage;

	return *this;
}

Damage & Stats::Damage::operator=(Damage && other)
{
	this->bIsOverTime = other.bIsOverTime;
	this->bIsBombType = other.bIsBombType;
	this->bIsDirect = other.bIsDirect;
	this->IsMultipleTypes = other.IsMultipleTypes;
	this->MultipleTypes = other.MultipleTypes;

	this->tType = other.tType;
	this->dTotal_Timer = other.dTotal_Timer;
	this->dRemaining_Time = other.dRemaining_Time;

	this->fMinDamage = other.fMinDamage;
	this->fMaxDamage = other.fMaxDamage;

	other.tType           = nullptr;
	other.dTotal_Timer    = nullptr;
	other.dRemaining_Time = nullptr;

	other.fMinDamage = nullptr;
	other.fMaxDamage = nullptr;

	other.bIsOverTime    =  nullptr;
	other.bIsBombType    =  nullptr;
	other.bIsDirect      =  nullptr;
	other.IsMultipleTypes=  nullptr;
//	if(IsMultipleTypes) other.MultipleTypes.RemoveAll();

	return *this;
}

bool Stats::Damage::bIsInstant()
{
	return this->bIsDirect;
}

bool Stats::Damage::bHasTimer()
{
	return this->bIsOverTime;
}

DeltaSecond Stats::Damage::dGetTimer()
{
	return  *dTotal_Timer;
}

DeltaSecond Stats::Damage::dGetRemainingTimer()
{
	return *dRemaining_Time;
}

DeltaSecond Stats::Damage::dGetBombTimer()
{
	return *dTotal_Timer-(*dTotal_Timer-*dRemaining_Time);
}

float const Stats::Damage::GetMinDamage()
{
	return *fMinDamage;
}

float const Stats::Damage::GetMaxDamage()
{
	return *fMaxDamage;
}

float const Stats::Damage::GetDamage()
{
	return fCalculateDamage();
}

void Stats::Damage::UpdateDamage(const size_t & modifier)
{
	*this->fMinDamage += modifier;
	*this->fMaxDamage += modifier;
}

void Stats::Damage::UpdateDamage(const size_t & DmgModifier, const size_t & DurationModifier)
{
	*this->fMinDamage += DmgModifier;
	*this->fMaxDamage += DmgModifier;

	*this->dTotal_Timer += DurationModifier;
}

void Stats::Damage::UpdateDamage(const size_t & modifier, FUNCTOR_PLACEHOLDER modificator_formula)
{
}

void Stats::Damage::UpdateDamage(const size_t & modifier1, const size_t & modifier2, FUNCTOR_PLACEHOLDER modificator_formula)
{
}

void Stats::Damage::UpdateDamage(FUNCTOR_PLACEHOLDER modificator_formula, const size_t & count, ...)
{
}


float const Stats::Damage::fCalculateDamage()
{
	
	/*create RNG in order to generate a random number*/

	return FMath::FRandRange(*fMinDamage,*fMaxDamage);

	//scrapped method
	//return _int64(Randomizer->FRand())% _int64((*fMaxDamage-*fMinDamage)+*fMinDamage);
	/* returns a random number inside the damage range
	* needs to be casted to integer values in order to get remainder value
	* substract min damage from max damage in order to don't mess higher bound when saving the lower bounds
	* add min in order to always get a low bound that is higher than 0
	*/
}

float const Stats::Damage::fReduceDamage()
{
	return -1;
}

