#ifndef SYSTEM
#define SYSTEM

//#define WIN32_LEAN_AND_MEAN

#include "Network.h"
#include "Window.h"

class Sound;
class Timer;
class Debug;
class ChooseState;
class MenuState;
class PlayingStateTest;
class Camera;
class GameState;

class System
{
public:
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
	void Shutdown();
	void Run();


private:
	void Update();
	void Render();

	void TestCollisions();

	void RenderToShadowMap();
	Window m_window;
	Timer* m_timer;
	Debug* m_debug;

	std::string m_title;
	int m_previousFPS;

	float m_oldMouseX;
	float m_oldMouseY;

	DirectionalLight m_directionalLight;
	Camera* m_lightCamera;
	MenuState* m_menuState;
	ChooseState* m_chooseNinjaState;
	GameState* m_gameState;
	PlayingStateTest* m_playingState;

	Sound* m_sound;
};
#endif