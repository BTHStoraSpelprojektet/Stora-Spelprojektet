#ifndef SYSTEM
#define SYSTEM

#include "Server.h"
#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "..\CommonLibs\Timer.h"
//#include <iostream>

class System
{
public:
	System();
	~System();
	bool Initialize();
	void Run();
private:
	void Update();

	Server m_server;
	Timer m_timer;
};

#endif SYSTEM