#ifndef SYSTEM
#define SYSTEM

#include <Windows.h>
#include <iostream>

class System
{
public:
	System();
	~System();
	bool Initialize();
	void Run();
private:
	Server m_server;
};

#endif SYSTEM