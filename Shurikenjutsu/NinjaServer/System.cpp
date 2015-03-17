#include "System.h"


System::System(){}
System::~System(){}

bool System::Initialize(int p_argc, _TCHAR* p_argv[])
{
	m_server.Initialize();

	// Initialize timer.
	m_timer.Initialize();
	m_timer.StartTimer();

	m_memoryChecker.Initialize();

	m_firstUpdate = true;
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

		if (GetAsyncKeyState(VK_ESCAPE) && GetAsyncKeyState(VK_F1))
		{
			PostQuitMessage(0);
		}
		else
		{
			Update();
		}
	}

	// Shutdown
	m_server.Shutdown();
	m_memoryChecker.Shutdown();
}

void System::Update()
{
	//Update timer
	m_timer.Update();

	double deltaTime = m_timer.GetDeltaTime();

	if (!m_firstUpdate)
	{
		m_server.Update(deltaTime);
		m_memoryChecker.Update(deltaTime);
	}
	m_firstUpdate = false;
}