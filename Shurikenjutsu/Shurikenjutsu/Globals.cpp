#include "Globals.h"

GLOBAL& GLOBAL::GetInstance()
{
	static GLOBAL instance;

	return instance;
}