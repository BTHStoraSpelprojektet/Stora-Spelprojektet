#ifndef TEAMSTATUSBAR_H_
#define TEAMSTATUSBAR_H_

#define WIN32_LEAN_AND_MEAN

#include <map>
#include <vector>
#include <DirectXMath.h>
#include "..\CommonLibs\RakNet\RakNetTypes.h"

class GUIElement;
class GUIText;

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
	std::map<RakNet::RakNetGUID, GUIElement*> m_redColorPlayers;
	std::map<RakNet::RakNetGUID, GUIElement*> m_blueColorPlayers;
	std::vector<GUIElement*> m_redSquares;
	std::vector<GUIElement*> m_blueSquares;
	GUIElement* m_background;
	GUIElement* m_frame;
	GUIElement* m_deadPlayer;

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
	int m_myTeam;

	GUIText* m_redScore;
	GUIText* m_blueScore;

	double m_timeSec;
	double m_timeMin;
	GUIText* m_timerText;
};

#endif