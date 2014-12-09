#include "Globals.h"

GLOBAL& GLOBAL::GetInstance()
{
	static GLOBAL instance;

	return instance;
}

void GLOBAL::SetDeltaTime(double p_deltaTime)
{
	DELTATIME = p_deltaTime;
}

double GLOBAL::GetDeltaTime()
{
	return DELTATIME;
}