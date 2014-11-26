#include "System.h"
PlayingStateTest System::playingState;
bool System::Initialize()
{
    bool result = true;
	playingState = PlayingStateTest();
	//m_gameState = &m_playingState;
	gameState = &System::playingState;

	// Set starting window values.
	GLOBAL::GetInstance().FULLSCREEN = false;
	GLOBAL::GetInstance().MAX_SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
	GLOBAL::GetInstance().MAX_SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

	if (GLOBAL::GetInstance().FULLSCREEN)
	{
		GLOBAL::GetInstance().SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
		GLOBAL::GetInstance().SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	}
	else
	{
		GLOBAL::GetInstance().SCREEN_WIDTH = 1000;
		GLOBAL::GetInstance().SCREEN_HEIGHT = 1000;
	}

	ConsolePrintSuccess("Application initialized.");
	ConsoleSkipLines(1);

	// Set console position.
	HWND console = GetConsoleWindow();
	MoveWindow(console, GLOBAL::GetInstance().SCREEN_WIDTH, 0, 670, 1000, true);
	SetWindowTextA(console, "Shurikenjitsu Debug Console");

	// Initialize the window.
	WindowRectangle window = WindowRectangle(0, 0, GLOBAL::GetInstance().SCREEN_WIDTH, GLOBAL::GetInstance().SCREEN_HEIGHT);
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
	m_graphicsEngine.Initialize(m_window.GetHandle());
	m_graphicsEngine.SetClearColor(0.0f, 0.6f, 0.9f, 1.0f);
	m_graphicsEngine.SetSceneFog(0.0f, 100.0f, 0.01f);
	m_graphicsEngine.TurnOffAlphaBlending();
	m_render = true;

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	gameState->Initialize(m_graphicsEngine.GetDevice(), &m_graphicsEngine);

	// Initialize the camera.
	m_flyCamera = false;
	
	// Input: Register keys
	//InputManager* input = InputManager::GetInstance();
	InputManager::GetInstance()->RegisterKey(VkKeyScan('w'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('a'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('s'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('d'));

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.1f, 0.1f, 0.1f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f);
	m_graphicsEngine.SetSceneDirectionalLight(m_directionalLight);

    return result;
}

void System::Shutdown()
{
	// Shutdown input.
	InputManager::GetInstance()->Shutdown();

	// Shutdown graphics engine.
	m_graphicsEngine.Shutdown(); // TODO, this does nothing so far.
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
			if (m_render)
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
	double deltaTime = m_timer.GetDeltaTime();

	// Update animation
	m_animatedCharacter.Update(deltaTime);

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

	gameState->Update(deltaTime, m_graphicsEngine.GetDevice());

	// Quick escape.
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
	
	if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('f')))
	{
		/*if (GLOBAL::GetInstance().FULLSCREEN)
		{
			ToggleFullscreen(false);
		}
		else
		{
			ToggleFullscreen(true);
		}*/
	}
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	m_graphicsEngine.Clear();

/*	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_plane.GetMesh(), m_plane.GetVertexCount(), m_plane.GetWorldMatrix(), m_plane.GetTexture(), 0);
	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_character.GetMesh(), m_character.GetVertexCount(), m_character.GetWorldMatrix(), m_character.GetTexture(), 1);
	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_object.GetMesh(), m_object.GetVertexCount(), m_object.GetWorldMatrix(), m_object.GetTexture(), 2);
*/
	gameState->Render(&m_graphicsEngine);

	// Start rendering alpha blended.
	m_graphicsEngine.TurnOnAlphaBlending();

	// Stop rendering alpha blended.
	m_graphicsEngine.TurnOffAlphaBlending();

	// Present the result.
	m_graphicsEngine.Present();
}

/*void System::ToggleFullscreen(bool p_fullscreen)
{
	if (p_fullscreen)
	{
		m_render = false;

		// Go to fullscreen
		GLOBAL::GetInstance().SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
		GLOBAL::GetInstance().SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
		SetWindowPos(m_window.GetHandle(), HWND_TOP, 0, 0, GLOBAL::GetInstance().SCREEN_WIDTH, GLOBAL::GetInstance().SCREEN_HEIGHT, SWP_SHOWWINDOW);
		m_graphicsEngine.ToggleFullscreen(true);

		// Update aspect ratio.
		float aspectRatio = (float)GLOBAL::GetInstance().SCREEN_WIDTH / (float)GLOBAL::GetInstance().SCREEN_HEIGHT;
		m_camera.UpdateAspectRatio(aspectRatio);
		m_camera.UpdateProjectionMatrix();
		m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

		// Set both window positions.
		HWND console = GetConsoleWindow();
		MoveWindow(console, GLOBAL::GetInstance().SCREEN_WIDTH, 0, 670, 1000, true);

		m_render = true;
	}

	else
	{
		m_render = false;

		// Go to windowed mode.
		GLOBAL::GetInstance().SCREEN_WIDTH = 1000;
		GLOBAL::GetInstance().SCREEN_HEIGHT = 1000;
		m_graphicsEngine.ToggleFullscreen(false);

		// Update aspect ratio.
		float aspectRatio = (float)GLOBAL::GetInstance().SCREEN_WIDTH / (float)GLOBAL::GetInstance().SCREEN_HEIGHT;
		m_camera.UpdateAspectRatio(aspectRatio);
		m_camera.UpdateProjectionMatrix();
		m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

		// Set both window positions.
		HWND console = GetConsoleWindow();
		MoveWindow(console, GLOBAL::GetInstance().SCREEN_WIDTH, 0, 670, 1000, true);
		SetWindowPos(m_window.GetHandle(), HWND_TOP, 0, 0, GLOBAL::GetInstance().SCREEN_WIDTH, GLOBAL::GetInstance().SCREEN_HEIGHT, SWP_SHOWWINDOW);

		m_render = true;
	}
}*/