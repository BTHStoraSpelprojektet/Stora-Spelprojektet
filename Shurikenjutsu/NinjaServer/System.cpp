#include "System.h"


System::System()
{
}


System::~System()
{
}

bool System::Initialize()
{
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
		}
	}

	// Shutdown
}