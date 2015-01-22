#ifndef GAMESTATE
#define GAMESTATE


enum GAMESTATESWITCH
{
	GAMESTATESWITCH_MENU,
	GAMESTATESWITCH_CHOOSENINJA,
	GAMESTATESWITCH_PLAY,
	GAMESTATESWITCH_NONE,
};

class GameState
{
public:
	GameState();
	~GameState();
	virtual bool Initialize();
	virtual void Shutdown();	
	virtual GAMESTATESWITCH Update();
	virtual void Render();
	virtual void RenderAlpha();
	virtual void ToggleFullscreen(bool p_fullscreen);
};

#endif // !GAMESTATE


