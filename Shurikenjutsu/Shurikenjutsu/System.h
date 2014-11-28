#ifndef SYSTEM
#define SYSTEM

#define WIN32_LEAN_AND_MEAN

#include <vector>
#include "Network.h"
#include "Window.h"
#include "GraphicsEngine.h"
#include "Timer.h"
#include "Camera.h"
#include "Model.h"
#include "InputManager.h"
#include "ObjectManager.h"

#include "ConsoleFunctions.h"
#include "Flags.h"
#include "Enumerations.h"

#include "Debug.h"
#include "Globals.h"

#include "Player.h"
#include "PlayerManager.h"

#include "PlayingStateTest.h"

class System
{
public:
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
	void Shutdown();
    void Run();

	static PlayingStateTest playingState;

private:
    void Update();
    void Render();

	void TestCollisions();

	void RenderToShadowMap();
	Window m_window;
	Timer m_timer;
	Debug m_debug;

	std::string m_title;
	int m_previousFPS;

	bool m_flyCamera;
	float m_oldMouseX;
	float m_oldMouseY;

	DirectionalLight m_directionalLight;
	
	GameState* gameState;
};
#endif