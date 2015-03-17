#ifndef SYSTEM
#define SYSTEM

#include "Server.h"
#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "..\CommonLibs\Timer.h"
#include "MemoryChecker.h"
//#include <vld.h>

class System
{
public:
	System();
	~System();
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
	void Run();
private:
	void Update();

	Server m_server;
	Timer m_timer;
	MemoryChecker m_memoryChecker;

	bool m_firstUpdate;
};

#endif SYSTEM