#include "System.h"

bool System::Initialize(int p_argc, _TCHAR* p_argv[])
{
    bool result = true;

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

	// Initialize the camera.
	m_flyCamera = false;
	m_camera.Initialize();
	ConsolePrintSuccess("Camera initialized successfully.");
	ConsoleSkipLines(1);
	
	// REMOVE THIS LATER.
	m_plane.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/FloorShape.SSP");
	m_graphicsEngine.AddInstanceBuffer(1);

	m_character.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/cubemanWnP.SSP");
	m_graphicsEngine.AddInstanceBuffer(5);
	
	m_object.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	m_graphicsEngine.AddInstanceBuffer(3);
	//m_graphicsEngine.AddInstanceBuffer(1000);

	DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);
	m_character.Rotate(rotation);
	DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(0.0f, 0.0f, -2.0f);
	m_character.Translate(translation);

	m_animatedCharacter.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/StickManAnimatedShape.SSP");
	translation = DirectX::XMFLOAT3(5.0f, 0.0f, 0.0f);
	m_animatedCharacter.Translate(translation);

	m_object.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	m_object.Rotate(rotation);
	translation = DirectX::XMFLOAT3(0.0f, 0.0f, 2.0f);
	m_object.Translate(translation);

	//Run all tests that are in the debug class
	m_debug.RunTests(p_argc, p_argv);

	// Input: Register keys
	InputManager* input = InputManager::GetInstance();
	input->RegisterKey(VkKeyScan('w'));
	input->RegisterKey(VkKeyScan('a'));
	input->RegisterKey(VkKeyScan('s'));
	input->RegisterKey(VkKeyScan('d'));
	input->RegisterKey(VkKeyScan('f'));

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.5f, 0.5f, 0.5f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.1f, 0.1f, 0.1f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVectorSet(1.0f, -1.0f, 1.0f, 0.0f);
	m_graphicsEngine.SetSceneDirectionalLight(m_directionalLight);

	// Initialize PlayerManager
//	m_playerManager = new PlayerManager();
	m_playerManager.Initialize(m_graphicsEngine.GetDevice());

	// Reset the camera for initial use.
	ResetCamera();

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

	// Enable camera flying if in debug mode.
	if (FLAG_DEBUG == 1)
	{
		MoveCamera(deltaTime);
	}

	// Quick escape.
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('f')))
	{
		if (GLOBAL::GetInstance().FULLSCREEN)
		{
			ToggleFullscreen(false);
		}
		else
		{
			ToggleFullscreen(true);
		}
	}

	// Temporary "Shuriken" spawn
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		m_objectManager.AddShuriken(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/shurikenShape.SSP", m_playerManager.GetPosition(0), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f), 10.0f);
	}

	m_objectManager.Update(deltaTime);
	m_playerManager.Update(deltaTime);
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	m_graphicsEngine.Clear();

	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_plane.GetMesh(), m_plane.GetVertexCount(), m_plane.GetWorldMatrix(), m_plane.GetTexture(), 0, m_plane.GetAnimation());
	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_character.GetMesh(), m_character.GetVertexCount(), m_character.GetWorldMatrix(), m_character.GetTexture(), 1, m_character.GetAnimation());
	m_graphicsEngine.Render(SHADERTYPE_INSTANCED, m_object.GetMesh(), m_object.GetVertexCount(), m_object.GetWorldMatrix(), m_object.GetTexture(), 2, m_object.GetAnimation());

	m_graphicsEngine.Render(SHADERTYPE_ANIMATED, m_animatedCharacter.GetMesh(), m_animatedCharacter.GetVertexCount(), m_animatedCharacter.GetWorldMatrix(), m_animatedCharacter.GetTexture(), 0, m_animatedCharacter.GetAnimation());

	//m_graphicsEngine.Render(SHADERTYPE_SCENE, m_playerManager.GetModel(0).GetMesh(), m_playerManager.GetModel(0).GetVertexCount(), m_playerManager.GetModel(0).GetWorldMatrix(), m_playerManager.GetModel(0).GetTexture());
	std::vector<Player> tempList1 = m_playerManager.GetListOfPlayers();
	for (unsigned int i = 0; i < tempList1.size(); i++)
	{
		Model tempModel1 = tempList1[i].GetModel();
		m_graphicsEngine.Render(SHADERTYPE_SCENE, tempModel1.GetMesh(), tempModel1.GetVertexCount(), tempModel1.GetWorldMatrix(), tempModel1.GetTexture(), 1, tempModel1.GetAnimation());
	}

	// Start rendering alpha blended.
	m_graphicsEngine.TurnOnAlphaBlending();

	// Draw Shurikens
	std::vector<Shuriken> tempList = m_objectManager.GetListOfShurikens();
	for (unsigned int i = 0; i < tempList.size(); i++)
	{
		Model tempModel = tempList[i].GetModel();
		m_graphicsEngine.Render(SHADERTYPE_SCENE, tempModel.GetMesh(), tempModel.GetVertexCount(), tempModel.GetWorldMatrix(), tempModel.GetTexture(), 0, tempModel.GetAnimation());
	}

	// Stop rendering alpha blended.
	m_graphicsEngine.TurnOffAlphaBlending();



	// Present the result.
	m_graphicsEngine.Present();
}

void System::MoveCamera(double p_dt)
{
	// Start moving the camera with the C key.
	if (GetAsyncKeyState('C') & 0x8000 && !m_flyCamera)
	{
		ShowCursor(false);
		m_flyCamera = true;

		POINT position;
		GetCursorPos(&position);

		m_oldMouseX = (float)position.x;
		m_oldMouseY = (float)position.y;
	}

	if (m_flyCamera)
	{
		float deltaTime = (float)p_dt;

		// Rotate and pitch the camera.
		POINT position;
		GetCursorPos(&position);

		float dx = DirectX::XMConvertToRadians(0.25f * static_cast<float>(position.x - m_oldMouseX));
		float dy = DirectX::XMConvertToRadians(0.25f * static_cast<float>(position.y - m_oldMouseY));
		m_camera.Pitch(dy);
		m_camera.Rotate(dx);

		SetCursorPos((int)m_oldMouseX, (int)m_oldMouseY);

		// Move the camera using W, S, A, D keys.
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_camera.Walk(10.0f * deltaTime);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_camera.Walk(-10.0f * deltaTime);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_camera.Strafe(-10.0f * deltaTime);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_camera.Strafe(10.0f * deltaTime);
		}

		// Update the camera.
		m_camera.UpdateMovedCamera();

		// Set shader variables from the camera.
		m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

		// Reset the camera when BACKSPACE key is pressed.
		if (GetAsyncKeyState(VK_BACK))
		{
			ShowCursor(true);
			m_flyCamera = false;
			ResetCamera();
		}
	}

	else
	{
		// Lock Camera
		DirectX::XMFLOAT3 playerPosition = m_playerManager.GetPosition(0);
		DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(playerPosition.x, playerPosition.y + 20.0f, playerPosition.z - 10.0f);
		DirectX::XMFLOAT3 target = playerPosition;

		m_camera.UpdatePosition(position);
		m_camera.UpdateTarget(target);
		m_camera.UpdateViewMatrix();
		m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());
	}

}

void System::ResetCamera()
{
	// Reset camera.
	DirectX::XMFLOAT3 playerPosition = m_playerManager.GetPosition(0);

	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(playerPosition.x, playerPosition.y + 20.0f, playerPosition.z - 10.0f);

	DirectX::XMFLOAT3 target = playerPosition;

	m_camera.UpdatePosition(position);
	m_camera.UpdateTarget(target);

	// Projection data.
	float aspectRatio = (float)GLOBAL::GetInstance().SCREEN_WIDTH / (float)GLOBAL::GetInstance().SCREEN_HEIGHT;
	m_camera.UpdateAspectRatio(aspectRatio);
	m_camera.UpdateFieldOfView(3.141592f * 0.5f);
	m_camera.UpdateClippingPlanes(0.001f, 40.0f);
	m_camera.UpdateViewMatrix();
	m_camera.UpdateProjectionMatrix();

	m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());
}

void System::ToggleFullscreen(bool p_fullscreen)
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
}