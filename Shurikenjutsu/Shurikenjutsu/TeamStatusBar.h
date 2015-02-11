#ifndef TEAMSTATUSBAR_H_
#define TEAMSTATUSBAR_H_

#define WIN32_LEAN_AND_MEAN

#include <map>
#include "Network.h"
#include "GUIElement.h"
#include "GUIText.h"

class TeamStatusBar
{
public:
	TeamStatusBar();
	~TeamStatusBar();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();
private:
	std::map<RakNet::RakNetGUID, GUIElement> m_redColorPlayers;
	std::map<RakNet::RakNetGUID, GUIElement> m_blueColorPlayers;
	std::vector<GUIElement> m_redSquares;
	std::vector<GUIElement> m_blueSquares;
	GUIElement m_background;
	GUIElement m_frame;


	void ResizeRedColorList();
	void ResizeBlueColorList();
	void AddRedSquare();
	void AddBlueSquare();

	std::string GetTextureName(int p_charNr);

	float m_dotSize;
	float m_dotPosOffset;
	float m_startOffset;
	DirectX::XMFLOAT3 m_originPos;
	bool m_addedMyself;

	GUIText m_redScore;
	GUIText m_blueScore;

	double m_timeSec;
	double m_timeMin;
	GUIText m_timerText;

	GUIText m_fpsTimer;
};

#endif