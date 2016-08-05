// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */

namespace Stats
{
	enum class Effect_Category
	/*
	* buff affects character positively, eg hp/damage boost
	* debuff affect character negatively, eg armor/damage penalty
	* offensive applies to enemies on attack (or via chance on attack)
	*/
	{
		Buff      = 0x00,
	    Debuff    = 0x01,
		Offensive = 0x02
	};

	enum class Effect_Type
	{
		Damage_Buff_Amount  = 0x00,
		Damage_Buff_Percent = 0x01,
		/*increase damage done by player*/

		Armor_Buff_Amount   = 0x02,
		Armor_Buff_Percent  = 0x03,
		/*increase damage reduction for the player*/
		 
		Health_Buff_Amount  = 0x04,
		Health_Buff_Percent = 0x05,
		/*increase total health for the player*/
		
		Velocity_Buff_Amount  = 0x06,
		Velocity_Buff_Percent = 0x07,
		/*increase speed for the player*/

		AttSpd_Buff_Amount  = 0x08,
		AttSpd_Buff_Percent = 0x09,
		/*increase attack speed for the player*/

		Damage_Debuff_Amount  = 0x0A,
		Damage_Debuff_Percent = 0x0B,
		/*decrease damage done by player*/

		Armor_Debuff_Amount  = 0x0C,
		Armor_Debuff_Percent = 0x0D,
		/*decrease damage reduction for the player*/

		Health_Debuff_Amount  = 0x0E,
		Health_Debuff_Percent = 0x0F,
		/*decrease total health for the player*/

		Velocity_Debuff_Amount  = 0x10,
		Velocity_Debuff_Percent = 0x11,
		/*decrease speed for the player*/

		AttSpd_Debuff_Amount  = 0x12,
		AttSpd_Debuff_Percent = 0x13,
		/*decrease attack speed for the player*/

		Armor_offense_Amount  = 0x14,
		Armor_offense_Percent = 0x15,
		/*decrease damage reduction for the foe*/

		Health_offense_Amount  = 0x16,
		Health_offense_Percent = 0x17,
		/*decrease total health for the foe*/

		Velocity_offense_Amount  = 0x18,
		Velocity_offense_Percent = 0x19,
		/*decrease speed for the foe*/

		AttSpd_offense_Amount  = 0x1A,
		AttSpd_offense_Percent = 0x1B
		/*decrease attack speed for the foe*/
	};

	enum class Effect_Timer
	{
		Instant =0x00,
		OverTime=0x01,
		TimeBomb=0x02
	};

class PROJECTERWIN_API Generic_Effect
{
public:
	Generic_Effect();
    virtual ~Generic_Effect();
	Generic_Effect(const Generic_Effect & other);
	Generic_Effect(Generic_Effect && other);

	Generic_Effect & operator=(const Generic_Effect & other);
	Generic_Effect & operator=(Generic_Effect && other);

	virtual Effect_Category const cGetCategory();
	virtual Effect_Type     const eGetType    ();

	virtual bool const bGetTotalDurarion    ()=0;
	virtual bool const bGetRemainingDuration()=0;

	virtual bool const bIsInstant  ();
	virtual bool const bIsOverTime ();
	virtual bool const bIsTimeBomb ();

	virtual void const vStart  () = 0;
	virtual void const vTrigger() = 0;
	virtual void const vDispel () = 0;
	virtual void const vTick   () = 0;
	virtual void const vFinish () = 0;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Specifiers")
	TSharedPtr<Effect_Type>     eType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Specifiers")
	TSharedPtr<Effect_Category> cCategory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Specifiers")
	TSharedPtr<Effect_Timer>    tTimer_Type;
};

}
