#ifndef TIMER
#define TIMER

#include <Windows.h>

class Timer
{
public:
	bool Initialize();
	void StartTimer();
	void Update();

	double GetTotalTime();
	double GetDeltaTime();
	int GetFPS();

private:
	double m_frequency;
	__int64 m_startTime;

	__int64 m_previousDeltaCounts;
	double m_deltaTime;

	double m_seconds;
	int m_frames;
	int m_FPS;
};
#endif;