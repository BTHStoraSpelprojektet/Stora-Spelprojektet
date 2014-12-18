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
#include "DebugDraw.h"
//#include "ParticleEmitter.h"
#include "Frustum.h"
#include "GameState.h"

class PlayingStateTest : public GameState
{
public:
	PlayingStateTest();
	~PlayingStateTest();
	bool Initialize();
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

	// ========== DEBUG TEMP LINES ==========
	float m_mouseX;
	float m_mouseY;

	DebugCircle m_circle1;
	DebugCircle m_circle2;
	DebugCircle m_circle3;

	DebugDot m_debugDot;

	//ParticleEmitter m_particles;
	// ========== DEBUG TEMP LINES ==========

	Frustum m_frustum;
};
#endif PLAYINGSTATE