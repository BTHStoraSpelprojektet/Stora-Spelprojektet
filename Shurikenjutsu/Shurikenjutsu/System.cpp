#include "System.h"
PlayingStateTest System::playingState;
bool System::Initialize(int p_argc, _TCHAR* p_argv[])
{
	bool result = true;
	playingState = PlayingStateTest();
	//m_gameState = &m_playingState;
	gameState = &System::playingState;

	GLOBAL::GetInstance().isNotSwitchingFullscreen = false;

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
	GraphicsEngine::Initialize(m_window.GetHandle());
	GraphicsEngine::SetClearColor(0.0f, 0.6f, 0.9f, 1.0f);
	GraphicsEngine::SetSceneFog(0.0f, 100.0f, 0.01f);
	GraphicsEngine::TurnOffAlphaBlending();
	GLOBAL::GetInstance().isNotSwitchingFullscreen = true;

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	gameState->Initialize();

	// Initialize the camera.
	m_flyCamera = false;
	
	// REMOVE THIS LATER.
	m_plane.LoadModel("../Shurikenjutsu/Models/FloorShape.SSP");
	GraphicsEngine::AddInstanceBuffer(1);

	m_character.LoadModel("../Shurikenjutsu/Models/cubemanWnP.SSP");
	GraphicsEngine::AddInstanceBuffer(5);
	
	m_object.LoadModel("../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	GraphicsEngine::AddInstanceBuffer(3);

	DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);
	m_character.Rotate(rotation);
	DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(0.0f, 0.0f, -2.0f);
	m_character.Translate(translation);

	m_animatedCharacter.LoadModel("../Shurikenjutsu/Models/StickManAnimatedShape.SSP");
	translation = DirectX::XMFLOAT3(5.0f, 0.0f, 0.0f);
	m_animatedCharacter.Translate(translation);

	m_object.LoadModel("../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	m_object.Rotate(rotation);
	translation = DirectX::XMFLOAT3(0.0f, 0.0f, 2.0f);
	m_object.Translate(translation);

	//Run all tests that are in the debug class
	m_debug.RunTests(p_argc, p_argv);

	// Input: Register keys
	//InputManager* input = InputManager::GetInstance();
	InputManager::GetInstance()->RegisterKey(VkKeyScan('w'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('a'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('s'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('d'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('c'));
	InputManager::GetInstance()->RegisterKey(VK_UP);
	InputManager::GetInstance()->RegisterKey(VK_LEFT);
	InputManager::GetInstance()->RegisterKey(VK_DOWN);
	InputManager::GetInstance()->RegisterKey(VK_RIGHT);

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.1f, 0.1f, 0.1f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f);
	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);

	return result;
}

void System::Shutdown()
{
	// Shutdown input.
	InputManager::GetInstance()->Shutdown();

	//Shutdown current state
	gameState->Shutdown();

	// Shutdown graphics engine.
	GraphicsEngine::Shutdown(); // TODO, this does nothing so far.
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
			if (GLOBAL::GetInstance().isNotSwitchingFullscreen)
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

	gameState->Update(deltaTime);

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

	GraphicsEngine::Render(SHADERTYPE_INSTANCED, m_plane.GetMesh(), m_plane.GetVertexCount(), m_plane.GetWorldMatrix(), m_plane.GetTexture(), 0, m_plane.GetAnimation());
	GraphicsEngine::Render(SHADERTYPE_INSTANCED, m_character.GetMesh(), m_character.GetVertexCount(), m_character.GetWorldMatrix(), m_character.GetTexture(), 1, m_character.GetAnimation());
	GraphicsEngine::Render(SHADERTYPE_INSTANCED, m_object.GetMesh(), m_object.GetVertexCount(), m_object.GetWorldMatrix(), m_object.GetTexture(), 2, m_object.GetAnimation());

	GraphicsEngine::Render(SHADERTYPE_ANIMATED, m_animatedCharacter.GetMesh(), m_animatedCharacter.GetVertexCount(), m_animatedCharacter.GetWorldMatrix(), m_animatedCharacter.GetTexture(), 0, m_animatedCharacter.GetAnimation());

	// Render Current GameState
	gameState->Render();

	// Start rendering alpha blended.
	GraphicsEngine::TurnOnAlphaBlending();

	// Stop rendering alpha blended.
	GraphicsEngine::TurnOffAlphaBlending();

	// Present the result.
	GraphicsEngine::Present();
}