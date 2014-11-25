#include "System.h"

bool System::Initialize()
{
    bool result = true;

	ConsolePrintSuccess("Application initialized.");
	ConsoleSkipLines(1);

	// Set console position.
	HWND console = GetConsoleWindow();
	MoveWindow(console, 50, 50, 670, 1000, true);
	SetWindowTextA(console, "Shurikenjitsu Debug Console");

	// Initialize the window.
	WindowRectangle window = WindowRectangle(730, 50, GLOBAL_SCREEN_WIDTH, GLOBAL_SCREEN_HEIGHT);
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

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	// Initialize the camera.
	m_flyCamera = false;
	m_camera.Initialize();
	float l_aspectRatio = (float)((window.width - 16) / (window.height - 39));
	m_camera.UpdateAspectRatio(l_aspectRatio);
	ConsolePrintSuccess("Camera initialized successfully.");
	ConsoleSkipLines(1);
	
	// Reset the camera for initial use.
	ResetCamera();
	
	// REMOVE THIS LATER.
	m_plane.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/FloorShape.SSP");

	m_character.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/cubemanWnP.SSP");
	DirectX::XMVECTOR rotation = DirectX::XMVectorSet(0.0f, 3.141592f / 2.0f, 0.0f, 0.0f);
	m_character.Rotate(rotation);
	DirectX::XMVECTOR translation = DirectX::XMVectorSet(0.0f, 0.0f, -2.0f, 0.0f);
	m_character.Translate(translation);

	m_animatedCharacter.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/StickManAnimatedShape.SSP");
	translation = DirectX::XMVectorSet(0.0f, 0.0f, -4.0f, 0.0f);
	m_animatedCharacter.Translate(translation);

	m_object.LoadModel(m_graphicsEngine.GetDevice(), "../Shurikenjutsu/Models/DecoratedObjectShape.SSP");
	m_object.Rotate(rotation);
	translation = DirectX::XMVectorSet(0.0f, 0.0f, 2.0f, 0.0f);
	m_object.Translate(translation);

	//Run all tests that are in the debug class
	m_debug.RunTests();

	// Input: Register keys
	InputManager* input = InputManager::GetInstance();
	input->RegisterKey(VkKeyScan('w'));

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.5f, 0.5f, 0.35f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.3f, 0.3f, 0.23f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.2f, 0.2f, 0.2f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);

    return result;
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
			
			// Render if the window is active.
			if (GetForegroundWindow() == m_window.GetHandle())
			{
				Render();
			}
			
			// Clear Used Input
			InputManager::GetInstance()->ClearInput();
		}
	}

	// Shutdown Input
	InputManager::GetInstance()->Shutdown();
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

	// Enable camera flying if in debug mode.
	if (FLAG_DEBUG == 1)
	{
		MoveCamera(deltaTime);
	}

	m_graphicsEngine.SetSceneDirectionalLight(m_directionalLight);
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	m_graphicsEngine.Clear();

	// Start rendering alpha blended.
	m_graphicsEngine.TurnOnAlphaBlending();

	// Stop rendering alpha blended.
	m_graphicsEngine.TurnOffAlphaBlending();

	m_graphicsEngine.Render(SHADERTYPE_SCENE, m_plane.GetMesh(), m_plane.GetVertexCount(), m_plane.GetWorldMatrix(), m_plane.GetTexture());
	m_graphicsEngine.Render(SHADERTYPE_SCENE, m_character.GetMesh(), m_character.GetVertexCount(), m_character.GetWorldMatrix(), m_character.GetTexture());
	m_graphicsEngine.Render(SHADERTYPE_SCENE, m_object.GetMesh(), m_object.GetVertexCount(), m_object.GetWorldMatrix(), m_object.GetTexture());

	// Present the result.
	m_graphicsEngine.Present();
}

void System::MoveCamera(double p_dt)
{
	// Start moving the camera with the C key.
	if ((GetAsyncKeyState('C') & 0x8000) && m_flyCamera == false)
	{
		ShowCursor(false);
		m_flyCamera = true;

		POINT l_position;
		GetCursorPos(&l_position);

		m_oldMouseX = (float)l_position.x;
		m_oldMouseY = (float)l_position.y;
	}

	if (m_flyCamera)
	{
		float deltaTime = (float)p_dt;

		// Rotate and pitch the camera.
		POINT l_position;
		GetCursorPos(&l_position);

		float dx = DirectX::XMConvertToRadians(0.25f * static_cast<float>(l_position.x - m_oldMouseX));
		float dy = DirectX::XMConvertToRadians(0.25f * static_cast<float>(l_position.y - m_oldMouseY));
		m_camera.Pitch(dy);
		m_camera.Rotate(dx);

		SetCursorPos((int)m_oldMouseX, (int)m_oldMouseY);

		// Move the camera using W, S, A, D keys.
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_camera.Walk(10.0f * deltaTime);
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			m_camera.Walk(-10.0f * deltaTime);
		}

		if (GetAsyncKeyState('A') & 0x8000)
		{
			m_camera.Strafe(-10.0f * deltaTime);
		}

		if (GetAsyncKeyState('D') & 0x8000)
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
}

void System::ResetCamera()
{
	// Reset camera.
	DirectX::XMVECTOR position = DirectX::XMVectorSet(0.0f, 20.0f, -10.0f, 0.0f);
	DirectX::XMVECTOR target = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);

	m_camera.UpdatePosition(position);
	m_camera.UpdateTarget(target);

	// Look vector.
	DirectX::XMVECTOR look = DirectX::XMVectorSet(0.0f, -20.0f, 10.0f, 0.0f);
	look = DirectX::XMVector3Normalize(look);
	m_camera.UpdateLook(look);

	// Up vector.
	DirectX::XMVECTOR right = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR up = DirectX::XMVectorSet(0.0f, 10.0f, -20.0f, 0.0f);
	up = DirectX::XMVector3Cross(look, right);
	up = DirectX::XMVector3Normalize(up);
	m_camera.UpdateUpVector(up);

	// Right vector.
	right = DirectX::XMVector3Cross(up, look);
	right = DirectX::XMVector3Normalize(right);
	m_camera.UpdateRight(right);

	// Projection data.
	m_camera.UpdateFieldOfView(3.141592f * 0.5f);
	m_camera.UpdateAspectRatio(GLOBAL_SCREEN_HEIGHT / GLOBAL_SCREEN_WIDTH);
	m_camera.UpdateClippingPlanes(0.001f, 40.0f);
	m_camera.UpdateViewMatrix();
	m_camera.UpdateProjectionMatrix();

	m_graphicsEngine.SetSceneViewAndProjection(m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());
}