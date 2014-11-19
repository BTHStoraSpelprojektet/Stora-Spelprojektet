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
	void MoveCamera(double p_dt);
	void ResetCamera();

	Window m_window;
	GraphicsEngine m_graphicsEngine;
	Timer m_timer;
	Camera m_camera;

	std::string m_title;
	int m_previousFPS;

	Model m_plane;
	Model m_character;
	Model m_object;

	Collisions m_collision;

	bool m_flyCamera;
	float m_oldMouseX;
	float m_oldMouseY;
};
#endif