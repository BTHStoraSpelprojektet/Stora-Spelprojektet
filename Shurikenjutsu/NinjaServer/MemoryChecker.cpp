#include "MemoryChecker.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>

MemoryChecker::MemoryChecker(){}
MemoryChecker::~MemoryChecker(){}

bool MemoryChecker::Initialize()
{
	m_timeLeft = 0.0;
	m_updateTimer = 20.0;

	return true;
}

void MemoryChecker::Shutdown()
{
}

void MemoryChecker::Update(double p_deltaTime)
{
	m_timeLeft -= p_deltaTime;
	if (m_timeLeft < 0.0)
	{
		m_timeLeft = m_updateTimer;

		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		

		// Check virtual ram used
		SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
		SIZE_T vkbmu = (virtualMemUsedByMe / (SIZE_T)1024.0); // virtual KB memory used
		SIZE_T vmbmu = (vkbmu / (SIZE_T)1024.0); // virtual MB memory used
		

		// Check physical ram used
		SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
		SIZE_T pkbmu = (physMemUsedByMe / (SIZE_T)1024.0); // physical KB memory used
		SIZE_T pmbmu = (pkbmu / (SIZE_T)1024.0); // physical MB memory used

		#ifdef _DEBUG
			std::cout << "RAM: " << (int)pmbmu << " MB   VRAM: " << (int)vmbmu << " MB\n";
		#endif
	}
}