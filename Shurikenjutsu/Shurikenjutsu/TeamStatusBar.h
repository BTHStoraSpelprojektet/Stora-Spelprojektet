#ifndef TEAMSTATUSBAR_H_
#define TEAMSTATUSBAR_H_

#define WIN32_LEAN_AND_MEAN

#include <map>
#include "Network.h"
#include "GUIElement.h"

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
	std::map<RakNet::RakNetGUID, GUIElement> redColorDots;
	std::map<RakNet::RakNetGUID, GUIElement> blueColorDots;

	void ResizeRedColorList();
	void ResizeBlueColorList();

	float m_dotSize;
	float m_dotPosOffset;
	DirectX::XMFLOAT3 m_originPos;
	bool m_addedMyself;
};

#endif