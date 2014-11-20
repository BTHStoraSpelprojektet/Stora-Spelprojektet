#ifndef SYSTEM
#define SYSTEM

#include "Window.h"
#include "DirectX.h"
#include "Timer.h"
#include "Camera.h"

#include "ConsoleFunctions.h"
#include "Flags.h"
#include "InputManager.h"

class System
{
public:
	bool Initiliaze();
    void Run();

private:
    void Update();
    void Render();

	std::string CreateTitle(D3D_FEATURE_LEVEL p_version);

	Window m_window;
	DirectXWrapper m_directX;
	Timer m_timer;
	Camera m_camera;

	std::string m_title;
	int m_previousFPS;
};
#endif