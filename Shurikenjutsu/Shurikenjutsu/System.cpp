#include "System.h"
PlayingStateTest System::playingState;
bool System::Initialize(int p_argc, _TCHAR* p_argv[])
{
	bool result = true;

	// Set default game state.
	playingState = PlayingStateTest();
	m_gameState = &System::playingState;

	// Set starting window values.
	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = false;
	GLOBAL::GetInstance().FULLSCREEN = false;
	GLOBAL::GetInstance().MAX_SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
	GLOBAL::GetInstance().MAX_SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	GLOBAL::GetInstance().MIN_SCREEN_WIDTH = 1280;
	GLOBAL::GetInstance().MIN_SCREEN_HEIGHT = 1024;

	if (GLOBAL::GetInstance().FULLSCREEN)
	{
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	}
	else
	{
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MIN_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MIN_SCREEN_HEIGHT;
	}

	ConsolePrintSuccess("Application initialized.");
	ConsoleSkipLines(1);

	// Set console position.
	HWND console = GetConsoleWindow();
	MoveWindow(console, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH + 5, 0, 670, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, true);
	SetWindowTextA(console, "Shurikenjitsu Debug Console");

	// Hide the console if we are not debugging.
	if (FLAG_DEBUG != 1)
	{
		ShowWindow(console, SW_HIDE);
	}

	// Initialize the window.
	WindowRectangle window = WindowRectangle(0, 0, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
	m_window.Initialize(window);
	ConsolePrintSuccess("Window created successfully.");
	std::string size = "Window size: " + std::to_string(window.width);
	size.append("x" + std::to_string(window.height));
	ConsolePrintText(size);
	ConsoleSkipLines(1);

	// Update window title.
	m_title = "Shurikenjutsu";
	m_window.SetTitle(m_title);

	// Initialize the graphics engine.
	GraphicsEngine::Initialize(m_window.GetHandle());
	GraphicsEngine::SetClearColor(0.0f, 0.6f, 0.9f, 1.0f);
	GraphicsEngine::SetSceneFog(0.0f, 500.0f, 0.01f);
	GraphicsEngine::SetShadowMapDimensions((float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH, (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT);
	GraphicsEngine::TurnOffAlphaBlending();
	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = false;

	// Initialize model library.
	ModelLibrary::GetInstance()->Initialize();
	ConsolePrintSuccess("All models successfully loaded.");
	ConsoleSkipLines(1);

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	// Initialize current GameState
	m_gameState->Initialize();

	// Input: Register keys
	InputManager::GetInstance()->RegisterKey(VkKeyScan('w'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('a'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('s'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('d'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('c'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('f'));
	InputManager::GetInstance()->RegisterKey(VK_UP);
	InputManager::GetInstance()->RegisterKey(VK_LEFT);
	InputManager::GetInstance()->RegisterKey(VK_DOWN);
	InputManager::GetInstance()->RegisterKey(VK_RIGHT);
	ConsolePrintSuccess("Input keys registered.");
	ConsoleSkipLines(1);

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.25f, 0.25f, 0.25f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.1f, 0.1f, 0.1f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVectorSet(1.0f, -2.0f, 1.0f, 0.0f);
	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);
	m_lightCamera.Initialize();
	m_lightCamera.ResetCameraToLight();
	ConsolePrintSuccess("Light source and light camera initialized successfully.");
	ConsoleSkipLines(1);

	// Run all tests that are in the debug class.
	if (FLAG_RUN_TESTS == 1)
	{
		m_debug.RunTests(p_argc, p_argv);
	}

	// Initialize network
	Network::Initialize();
	ConsolePrintSuccess("Network initialized successfully.");
	ConsoleSkipLines(1);

	return result;
}

void System::Shutdown()
{
	// Shutdown input.
	InputManager::GetInstance()->Shutdown();

	//Shutdown current state
	m_gameState->Shutdown();

	// Shutdown graphics engine.
	GraphicsEngine::Shutdown(); // TODO, this does nothing so far.

	// Shutdown network
	Network::Shutdown();

	// Shutdown model library
	ModelLibrary::GetInstance()->Shutdown();
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
			// Update Input
			InputManager::GetInstance()->UpdateInput(message.message, message.wParam, message.lParam);

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		else
		{
			Update();
			if (!GLOBAL::GetInstance().SWITCHING_SCREEN_MODE)
			{
				Render();
			}
			
			// Clear Used Input
			InputManager::GetInstance()->ClearInput();
		}
	}

	// Shutdown.
	Shutdown();
}

// Update game logic here.
void System::Update()
{
	// Update the timer to enable delta time and FPS measurements.
	m_timer.Update();

	// Get the delta time to use for animation etc.
	GLOBAL::GetInstance().DELTATIME = m_timer.GetDeltaTime();

	if (FLAG_FPS == 1)
	{
		int fps = m_timer.GetFPS();

		if (fps != m_previousFPS)
		{
			std::string title = m_title + " (FPS: ";
			title.append(std::to_string(m_timer.GetFPS()) + ") ");

			m_window.SetTitle(title);

			m_previousFPS = fps;
		}
	}

	m_gameState->Update(GLOBAL::GetInstance().DELTATIME);
	
	// Update network
	Network::Update();

	// Quick escape.
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	GraphicsEngine::Clear();

	// Render Current GameState
	m_gameState->Render();

	// Present the result.
	GraphicsEngine::Present();
}
