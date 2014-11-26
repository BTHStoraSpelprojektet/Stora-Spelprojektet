#ifndef SYSTEM
#define SYSTEM

#include <vector>

#include "Window.h"
#include "GraphicsEngine.h"
#include "Timer.h"
#include "Camera.h"
#include "Model.h"

#include "ConsoleFunctions.h"
#include "Flags.h"
#include "Enumerations.h"
#include "InputManager.h"

#include "Debug.h"
#include "Globals.h"


class System
{
public:
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
    void Run();

private:
    void Update();
    void Render();

	void TestCollisions();
	void MoveCamera(double p_dt);
	void ResetCamera();

	Window m_window;
	GraphicsEngine m_graphicsEngine;
	Timer m_timer;
	Camera m_camera;
	Debug m_debug;

	std::string m_title;
	int m_previousFPS;

	Model m_plane;
	Model m_character;
	Model m_object;

	bool m_flyCamera;
	float m_oldMouseX;
	float m_oldMouseY;

	DirectionalLight m_directionalLight;
};
#endif