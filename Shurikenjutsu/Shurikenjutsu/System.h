#ifndef SYSTEM
#define SYSTEM

//#define WIN32_LEAN_AND_MEAN

#include "Network.h"
#include "Window.h"
#include "GraphicsEngine.h"

#include "Camera.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "..\CommonLibs\ModelLibrary.h"

#include "ConsoleFunctions.h"

#include "Debug.h"

#include "PlayingStateTest.h"
#include "Timer.h"
#include "Sound.h"
#include "GUIManager.h"

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

	float m_oldMouseX;
	float m_oldMouseY;

	DirectionalLight m_directionalLight;
	Camera m_lightCamera;
	
	GameState* m_gameState;

	Sound* m_sound;

};
#endif