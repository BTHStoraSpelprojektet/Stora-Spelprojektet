#include "Timer.h"

#include <Windows.h>
bool Timer::Initialize()
{
	m_startTime = 0;
	m_frequency = 0.0;

	m_previousDeltaCounts = 0;
	m_deltaTime = 0.0;

	m_seconds = 0.0;
	m_frames = 0;
	m_FPS = 0;

	return true;
}

void Timer::Shutdown()
{
	return;
}

void Timer::StartTimer()
{
	LARGE_INTEGER value;

	// Query system for frequency.
	QueryPerformanceFrequency(&value);
	m_frequency = double(value.QuadPart);

	// Query system for number of counts.
	QueryPerformanceCounter(&value);
	m_startTime = value.QuadPart;
}

void Timer::Update()
{
	LARGE_INTEGER counts;
	QueryPerformanceCounter(&counts);

	// Calculate delta counts.
	__int64 deltaCounts = counts.QuadPart - m_previousDeltaCounts;

	// Set new previous time.
	m_previousDeltaCounts = counts.QuadPart;

	if (deltaCounts < 0.0f)
	{
		deltaCounts = (__int64)0.0f;
	}

	// Calculate delta time.
	m_deltaTime = float(deltaCounts) / m_frequency;

	// Calculate the FPS every second.
	m_frames++;
	m_seconds += m_deltaTime;

	if (m_seconds > 1.0f)
	{
		m_FPS = m_frames;
		m_frames = 0;
		m_seconds = 0;
	}
}

double Timer::GetTotalTime()
{
	LARGE_INTEGER time;

	QueryPerformanceCounter(&time);

	return double(time.QuadPart - m_startTime) / m_frequency;
}

double Timer::GetDeltaTime()
{
	return m_deltaTime;
}

int Timer::GetFPS()
{
	return m_FPS;
}