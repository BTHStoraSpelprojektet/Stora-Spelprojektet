#ifndef PLAYINGSTATE
#define PLAYINGSTATE
#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "GraphicsEngine.h"
#include "Camera.h"
#include "Collisions.h"
#include "DebugDraw.h"
#include "Frustum.h"
#include "GameState.h"

class PlayingStateTest : public GameState
{
public:
	PlayingStateTest();
	~PlayingStateTest();
	virtual bool Initialize();
	virtual bool Initialize(std::string p_levelName);
	void Shutdown();
	GAMESTATESWITCH Update();
	void Render();
	void ToggleFullscreen(bool p_fullscreen);

private:
	void BasicPicking();
	DirectX::XMFLOAT3 NormalizeFloat3(DirectX::XMFLOAT3 p_f);

	PlayerManager m_playerManager;
	ObjectManager m_objectManager;
	Camera m_camera;

	float twoPi = 6.28318530718f;

	bool m_updateFrustum;

	// ========== DEBUG LINES ==========
	float m_mouseX;
	float m_mouseY;

	DebugDot m_debugDot;
	// ========== DEBUG LINES ==========

	Frustum m_frustum;
};
#endif PLAYINGSTATE