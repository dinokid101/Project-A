// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */

typedef float DeltaSecond;
typedef void* FUNCTOR_PLACEHOLDER;

namespace Stats /*member of namespace Stats, for monitorising*/
{

	enum class Damage_Type
	{
		Physical = 0x00, /*bullets, arrows, melee damage*/
		Poison   = 0x01, /*spiders, goo, deal damage over time*/
		Energy   = 0x02, /*magic projectiles, electricity, armor reduction*/
		Fire     = 0x03, /*flame, fire projectiles*/
		Frost    = 0x04, /*ice, freeze, frostbites*/
		Multiple = 0x05  /*attack does mixed types of damage, actions MultipleTypes array */
	};


	class PROJECTERWIN_API Damage
	{
	public:
		Damage(const Damage_Type & ttype, const float & fmin, const float & fmax, const float & fDuration, const bool & bIsBomb);
		Damage(const TArray<TSharedPtr<Damage_Type>> & ttype, const float & fmin, const float & fmax, 
			     const float & fDuration, const bool & bIsBomb);
	   ~Damage();
		Damage(const Damage & other);
		Damage(Damage &&other);

		Damage & operator=(const   Damage &  other);
		Damage & operator=(Damage && other);

		UFUNCTION(BluePrintCallable, Category = "Timer")
		bool bIsInstant();
		/*check if it's instant damage*/
		UFUNCTION(BluePrintCallable, Category = "Timer")
		bool bHasTimer();
		/*check if it deals damage over time*/

		DeltaSecond dGetTimer();
		/*return total timing of the damage effect, if it's instance return 0.01*/
		DeltaSecond dGetRemainingTimer();
		/*return remaining timer from the damage effect, if the damage isn't over time, return -1*/
		DeltaSecond dGetBombTimer();
		/*if the damage is bomb type, then return countdown else return -1*/

		UFUNCTION(BluePrintCallable, Category = "Range")
		float const GetMinDamage();
		/*return minimum damage from the range*/

		UFUNCTION(BluePrintCallable, Category = "Range")
		float const GetMaxDamage();
		/*return maximum damage from the range*/

		UFUNCTION(BluePrintCallable, Category = "Range")
		float const GetDamage();
		/*returns a random amount of damage in the given range*/

		UFUNCTION(BluePrintCallable, Category = "Modifier")
		void UpdateDamage(const size_t & modifier);

		UFUNCTION(BluePrintCallable, Category = "Modifier")
		void UpdateDamage(const size_t & DmgModifier, const size_t & DurationModifier);

		UFUNCTION(BluePrintCallable, Category = "Modifier")
		void UpdateDamage(const size_t & modifier, FUNCTOR_PLACEHOLDER modificator_formula);

		UFUNCTION(BluePrintCallable, Category = "Modifier")
		void UpdateDamage(const size_t & modifier1, const size_t & modifier2, FUNCTOR_PLACEHOLDER modificator_formula);

		UFUNCTION(BluePrintCallable, Category = "Modifier")
		void UpdateDamage(FUNCTOR_PLACEHOLDER modificator_formula, const size_t & count, ...);


	private:

		UPROPERTY(EditDefaultsOnly, Category = "")
		float const fCalculateDamage();

		UPROPERTY(EditDefaultsOnly, Category = "Switch")
		float const fReduceDamage();

		UPROPERTY(EditDefaultsOnly, Category = "Switch")
		bool bIsOverTime;
		UPROPERTY(EditDefaultsOnly, Category = "Switch")
		bool bIsBombType;
		UPROPERTY(EditDefaultsOnly, Category = "Switch")
		bool bIsDirect;
		UPROPERTY(EditDefaultsOnly, Category = "Switch")
		bool IsMultipleTypes;

		UPROPERTY(EditDefaultsOnly, Category = "Type")
		TArray<TSharedPtr<Damage_Type>> MultipleTypes;

		UPROPERTY(EditDefaultsOnly, Category = "Type")
		TSharedPtr<Damage_Type> tType;
		UPROPERTY(EditDefaultsOnly, Category = "Timer")
		TSharedPtr<DeltaSecond> dTotal_Timer;
		UPROPERTY(EditDefaultsOnly, Category = "Timer")
		TSharedPtr<DeltaSecond> dRemaining_Time;

		UPROPERTY(EditDefaultsOnly, Category = "Range")
		TSharedPtr<float> fMinDamage;
		UPROPERTY(EditDefaultsOnly, Category = "Range")
		TSharedPtr<float> fMaxDamage;


	};

}
