// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectErwin.h"
#include "Generic_Effect.h"

using namespace Stats;

Generic_Effect::Generic_Effect()
{
}

Generic_Effect::~Generic_Effect()
{
}

Stats::Generic_Effect::Generic_Effect(const Generic_Effect & other)
{
}

Stats::Generic_Effect::Generic_Effect(Generic_Effect && other)
{
}

Generic_Effect & Stats::Generic_Effect::operator=(const Generic_Effect & other)
{
	// TODO: insert return statement here
	return *this;
}

Generic_Effect & Stats::Generic_Effect::operator=(Generic_Effect && other)
{
	// TODO: insert return statement here
	return *this;
}

Stats::Effect_Category const Stats::Generic_Effect::cGetCategory()
{
	return *cCategory;
}

Stats::Effect_Type const Stats::Generic_Effect::eGetType()
{
	return *eType;
}

bool const Stats::Generic_Effect::bIsInstant()
{
	return *tTimer_Type==Effect_Timer::Instant ? true : false;
}

bool const Stats::Generic_Effect::bIsOverTime()
{
	return *tTimer_Type == Effect_Timer::OverTime ? true : false;
}

bool const Stats::Generic_Effect::bIsTimeBomb()
{
	return *tTimer_Type == Effect_Timer::TimeBomb ? true : false;
}
