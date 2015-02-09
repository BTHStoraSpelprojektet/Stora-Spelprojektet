#ifndef COUNTDOWN_H_
#define COUNTDOWN_H_

#include "GUIText.h"

class Countdown
{
public:
	Countdown();
	~Countdown();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();
private:
	GUIText m_cdText;
};

#endif