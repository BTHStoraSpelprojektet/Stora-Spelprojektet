#ifndef COUNTDOWN_H_
#define COUNTDOWN_H_
#define WIN32_LEAN_AND_MEAN

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
	bool m_render;
};

#endif