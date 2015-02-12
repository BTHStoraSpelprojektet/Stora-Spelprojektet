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
	bool m_renderCd;
	GUIText m_roundTeamText;
	bool m_renderRoundTeam;

	float m_minSize;
	float m_maxSize;
	int m_prevTime;
	float m_currentSize;

	UINT32 m_redColor;
	UINT32 m_blueColor;
};

#endif