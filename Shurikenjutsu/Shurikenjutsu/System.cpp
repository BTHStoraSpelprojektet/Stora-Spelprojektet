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

	// Update window title.
	m_title = "Shurikenjutsu";
	m_window.SetTitle(m_title);

	// Initialize directX.
	m_directX.Initialize(m_window.GetHandle());
	m_directX.Present();
	ConsolePrintSuccess("DirectX initialized successfully.");
	std::string version = "DirectX version: " + CreateTitle(m_directX.GetVersion());
	ConsolePrintText(version);

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");

	m_camera.Initialize();
	m_camera.CreateProjectionMatrix(70.0f, window.height, window.width, 1.0f, 1000.0f);
	m_camera.UpdateViewMatrix();
	
    return result;
}

void System::Run()
{
	// Go through windows message loop.
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

// Update game logic here.
void System::Update()
{
	// Update the timer to enable delta time and FPS measurements.
	m_timer.Update();

	// Get the delta time to use for animation etc.
	double deltaTime = m_timer.GetDeltaTime();

	if (FLAG_FPS == 1)
	{
		// Print the FPS if the flag is set.
		if (m_timer.GetFPS() != m_previousFPS)
		{
			std::string title = m_title + " (FPS: ";
			title.append(std::to_string(m_timer.GetFPS()) + ") ");

			m_window.SetTitle(title);
		}
	}
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	m_directX.Clear();


	// Present the result.
	m_directX.Present();
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