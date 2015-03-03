#pragma once
class MemoryChecker
{
public:
	MemoryChecker();
	~MemoryChecker();

	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);

private:
	double m_timeLeft;
	double m_updateTimer;
};

