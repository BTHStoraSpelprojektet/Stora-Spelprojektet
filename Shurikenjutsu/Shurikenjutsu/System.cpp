#include "System.h"

bool System::Initiliaze()
{
    bool result = true;

	// Set console position.
	HWND console = GetConsoleWindow();
	MoveWindow(console, 50, 50, 670, 1000, true);

	// Initialize the window.
	WindowRectangle window = WindowRectangle(730, 50, 1000, 1000);
	m_window.Initialize(window);
	m_window.SetTitle("Shurikenjitsu");
	ConsolePrintSuccess("Window created successfully.");

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