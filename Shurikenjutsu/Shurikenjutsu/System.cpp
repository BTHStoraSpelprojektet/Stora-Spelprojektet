#include "System.h"

bool System::Initiliaze()
{
    bool result = true;

	ConsolePrintText("Application initialized.");

	// Set console position.
	HWND console = GetConsoleWindow();
	MoveWindow(console, 50, 50, 670, 1000, true);
	SetWindowTextA(console, "Shurikenjitsu Debug Console");

	// Initialize the window.
	WindowRectangle window = WindowRectangle(730, 50, 1000, 1000);
	m_window.Initialize(window);
	ConsolePrintSuccess("Window created successfully.");

	// Initialize directX.
	m_directX.Initialize(m_window.GetHandle());
	ConsolePrintSuccess("DirectX initialized successfully.");
	std::string version = "DirectX version: " + CreateTitle(m_directX.GetVersion());
	ConsolePrintText(version);

	// Update window title.
	std::string title = "Shurikenjitsu [" + CreateTitle(m_directX.GetVersion()) + "]";
	m_window.SetTitle(title.c_str());
	
    return result;
}

void System::Run()
{
	MSG l_message = { 0 };

	while (l_message.message != WM_QUIT)
	{
		// Translate and dispatch message.
		if (PeekMessage(&l_message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&l_message);
			DispatchMessage(&l_message);
		}

		else
		{
			Update();
			Render();
		}
	}
}

void System::Update()
{
    // Update game logic.
}

void System::Render()
{
    // Render game scene.
}

std::string System::CreateTitle(D3D_FEATURE_LEVEL p_version)
{
	switch (p_version)
	{
		case(D3D_FEATURE_LEVEL_11_1) :
		{
			return "DirectX 11.1";
		}

		case(D3D_FEATURE_LEVEL_11_0) :
		{

			return "DirectX 11.0";
		}

		case(D3D_FEATURE_LEVEL_10_1) :
		{
			return "DirectX 10.1";
		}

		case(D3D_FEATURE_LEVEL_10_0) :
		{
			return "DirectX 10.0";
		}

		default:
		{
			ConsolePrintError("Creating title from version failed.");
			return "ERROR";
		}
	}
}