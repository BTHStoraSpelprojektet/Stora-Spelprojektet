#include "MemoryChecker.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <string>

MemoryChecker::MemoryChecker(){}
MemoryChecker::~MemoryChecker(){}

bool MemoryChecker::Initialize()
{
	m_virtualMBUsed = 0;
	m_physicalMBUsed = 0;
	return true;
}

void MemoryChecker::Shutdown()
{
}

void MemoryChecker::Update()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	bool test = GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

	SIZE_T vkbmu = (virtualMemUsedByMe / (SIZE_T)1024.0);
	SIZE_T vmbmu = (vkbmu / (SIZE_T)1024.0);
	m_virtualMBUsed = (int)vmbmu;


	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
	SIZE_T pkbmu = (physMemUsedByMe / (SIZE_T)1024.0);
	SIZE_T pmbmu = (pkbmu / (SIZE_T)1024.0);
	m_physicalMBUsed = (int)pmbmu;
}

int MemoryChecker::GetVitrualMBUsed()
{
	return m_virtualMBUsed;
}

int MemoryChecker::GetPhysicalMBUsed()
{
	return m_physicalMBUsed;
}