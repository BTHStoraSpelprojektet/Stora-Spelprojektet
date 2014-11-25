#include "System.h"


System::System()
{
}


System::~System()
{
}

bool System::Initialize()
{
	m_server.Initialize();

	return true;
}

void System::Run()
{
	// Go through windows message loop.
	MSG message = { 0 };


	while (message.message != WM_QUIT)
	{
		// Translate and dispatch message.
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		else
		{
			// Update();
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				message.message = WM_QUIT;
			}

			m_server.Update();
		}
	}

	// Shutdown
	m_server.Shutdown();
}