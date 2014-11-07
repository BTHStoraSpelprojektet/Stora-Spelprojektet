#ifndef SYSTEM
#define SYSTEM

#include "Window.h"
#include "ConsoleFunctions.h"

class System
{
public:
	bool Initiliaze();
    void Run();

private:
    void Update();
    void Render();

	Window m_window;
};
#endif