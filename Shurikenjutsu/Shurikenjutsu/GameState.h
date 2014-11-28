#ifndef GAMESTATE
#define GAMESTATE

#include "GraphicsEngine.h"

class GameState
{
public:
	GameState();
	~GameState();
	virtual bool Initialize();
	virtual void Shutdown();	
	virtual void Update(double p_deltaTime);
	virtual void Render();
	virtual void RenderAlpha();
	virtual void ToggleFullscreen(bool p_fullscreen);
};

#endif // !GAMESTATE


