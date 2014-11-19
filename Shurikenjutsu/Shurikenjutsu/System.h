#ifndef SYSTEM
#define SYSTEM

#include "Window.h"
#include "GraphicsEngine.h"
#include "Timer.h"
#include "Camera.h"
#include "Model.h"

#include "ConsoleFunctions.h"
#include "Flags.h"
#include "Enumerations.h"

#include "Collisions.h"

class System
{
public:
	bool Initialize();
    void Run();

private:
    void Update();
    void Render();

	void TestCollisions();

	Window m_window;
	GraphicsEngine m_graphicsEngine;
	Timer m_timer;
	Camera m_camera;

	std::string m_title;
	int m_previousFPS;

	Model m_plane;
	Collisions m_collision;


};
#endif