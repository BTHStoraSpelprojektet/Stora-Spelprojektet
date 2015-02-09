#ifndef SYSTEM
#define SYSTEM

#include "Server.h"
#include "..\CommonLibs\RakNet\WindowsIncludes.h"
#include "..\CommonLibs\Timer.h"
#include "Debug.h"

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
	Debug m_debug;

	bool m_firstUpdate;
};

#endif SYSTEM