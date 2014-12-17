#ifndef DEBUGTEST_H_
#define DEBUGTEST_H_

#include <iostream>
#include <tchar.h>
#include "..\Shurikenjutsu\GTest\include\gtest\gtest.h"
#include "NormalState.h"

class Debug
{
public:
	Debug();
	~Debug();
	void RunTests(int p_argc, _TCHAR* p_argv[]);
};

#endif