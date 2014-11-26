#ifndef PLAYINGSTATE
#define PLAYINGSTATE

#include "GameState.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "GraphicsEngine.h"
#include "Camera.h"

class PlayingState :
	public GameState
{
public:
	PlayingState();
	~PlayingState();
	virtual bool Initialize(ID3D11Device* p_device, GraphicsEngine *p_graphicsEngine);
	virtual void Update(double p_deltaTime, ID3D11Device* p_device);
	virtual void Render(GraphicsEngine* p_graphicsEngine);
	

private:
	PlayerManager m_playerManager;
	ObjectManager m_objectManager;
	Camera m_camera;
};

#endif PLAYINGSTATE