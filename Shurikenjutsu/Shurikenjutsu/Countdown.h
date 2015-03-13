#ifndef COUNTDOWN_H_
#define COUNTDOWN_H_
#define WIN32_LEAN_AND_MEAN

class GUIText;
class GUIElement;

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
	GUIText* m_cdText;
	bool m_renderCd;
	GUIText* m_roundTeamText;
	bool m_renderRoundTeam;
	GUIElement* m_victDefTexture;

	float m_minSize;
	float m_maxSize;
	int m_prevTime;
	float m_currentSize;

	unsigned int m_redColor;
	unsigned int m_blueColor;
};

#endif