#include "MemoryChecker.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <string>
#include "DebugText.h"

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
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

	// Check virtual ram used
	SIZE_T vkbmu = (virtualMemUsedByMe / (SIZE_T)1024.0); // virtual KB memory used
	SIZE_T vmbmu = (vkbmu / (SIZE_T)1024.0); // virtual MB memory used
	m_virtualMBUsed = (int)vmbmu;

	// Check physical ram used
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
	SIZE_T pkbmu = (physMemUsedByMe / (SIZE_T)1024.0); // physical KB memory used
	SIZE_T pmbmu = (pkbmu / (SIZE_T)1024.0); // physical MB memory used
	m_physicalMBUsed = (int)pmbmu;

	// Set values to debugText
	DebugText::GetInstance()->SetVRAMText(m_virtualMBUsed);
	DebugText::GetInstance()->SetRAMText(m_physicalMBUsed);
}

int MemoryChecker::GetVitrualMBUsed()
{
	return m_virtualMBUsed;
}

int MemoryChecker::GetPhysicalMBUsed()
{
	return m_physicalMBUsed;
}