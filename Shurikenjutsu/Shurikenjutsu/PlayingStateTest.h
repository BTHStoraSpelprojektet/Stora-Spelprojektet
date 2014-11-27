#ifndef PLAYINGSTATE
#define PLAYINGSTATE

#include "GameState.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "GraphicsEngine.h"
#include "Camera.h"

class PlayingStateTest :
	public GameState
{
public:
	PlayingStateTest();
	~PlayingStateTest();
	virtual bool Initialize();
	void Shutdown();
	virtual void Update(double p_deltaTime);
	virtual void Render();
	void RenderAlpha();
	void ToggleFullscreen(bool p_fullscreen);

private:
	PlayerManager m_playerManager;
	ObjectManager m_objectManager;
	Camera m_camera;
};

#endif PLAYINGSTATE