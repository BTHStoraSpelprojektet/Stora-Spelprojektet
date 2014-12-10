#ifndef PLAYINGSTATE
#define PLAYINGSTATE


#define WIN32_LEAN_AND_MEAN
#include "GameState.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "GraphicsEngine.h"
#include "Camera.h"
#include "..\CommonLibs\Level.h"
#include "Collisions.h"
#include <d3d9.h>
#include "DebugDraw.h"

class PlayingStateTest :
	public GameState
{
public:
	PlayingStateTest();
	~PlayingStateTest();
	virtual bool Initialize();
	void Shutdown();
	virtual void Update();
	virtual void Render();
	void ToggleFullscreen(bool p_fullscreen);

private:
	void MeleeAttack();
	void BasicPicking();
	DirectX::XMFLOAT3 NormalizeFloat3(DirectX::XMFLOAT3 p_f);

	PlayerManager m_playerManager;
	ObjectManager m_objectManager;
	Camera m_camera;

	float twoPi = 6.28318530718f;

	// ========== DEBUG TEMP LINES ==========
	float m_mouseX;
	float m_mouseY;

	DebugCircle m_circle1;
	DebugCircle m_circle2;
	DebugCircle m_circle3;

	DebugDot m_debugDot;
	// ========== DEBUG TEMP LINES ==========
};

#endif PLAYINGSTATE