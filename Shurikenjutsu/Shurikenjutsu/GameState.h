#ifndef GAMESTATE
#define GAMESTATE

#include "GraphicsEngine.h"

class GameState
{
public:
	GameState();
	~GameState();
	virtual bool Initialize(ID3D11Device* p_device, GraphicsEngine *p_graphicsEngine);
	virtual void Shutdown();	
	virtual void Update(double p_deltaTime, ID3D11Device* p_device);
	virtual void Render(GraphicsEngine* p_graphicsEngine);

};

#endif // !GAMESTATE


