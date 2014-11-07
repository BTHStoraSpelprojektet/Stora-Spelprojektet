#ifndef SYSTEM
#define SYSTEM

#include "Window.h"
#include "DirectX.h"
#include "ConsoleFunctions.h"

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
	DirectX m_directX;
};
#endif