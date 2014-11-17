#ifndef SYSTEM
#define SYSTEM

#include "Window.h"
#include "GraphicsEngine.h"
#include "Timer.h"

#include "ConsoleFunctions.h"
#include "Flags.h"

class System
{
public:
	bool Initialize();
    void Run();

private:
    void Update();
    void Render();

	Window m_window;
	GraphicsEngine m_graphicsEngine;
	Timer m_timer;

	std::string m_title;
	int m_previousFPS;
};
#endif