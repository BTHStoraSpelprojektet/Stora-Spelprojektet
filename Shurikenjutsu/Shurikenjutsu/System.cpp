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
	WindowRectangle window = WindowRectangle(730, 50, 1000, 1000);
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
	m_graphicsEngine.SetSceneFog(0.0f, 20.0f, 0.25f);

	// Initialize timer.
	m_previousFPS = 0;
	m_timer.Initialize();
	m_timer.StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	// Initialize the camera.
	m_angle = 0.0f;
	m_useCamera = false;
	m_camera.Initialize();
	float l_aspectRatio = (float)((window.width - 16) / (window.height - 39));
	m_camera.UpdateAspectRatio(l_aspectRatio);
	ResetCamera();
	ConsolePrintSuccess("Camera initialized successfully.");
	
	m_plane.LoadModel(m_graphicsEngine.GetDevice(), "lol");
	m_graphicsEngine.SetSceneMatrices(m_plane.GetWorldMatrix(), m_camera.GetViewMatrix(), m_camera.GetProjectionMatrix());

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
	m_graphicsEngine.Clear();

	m_graphicsEngine.Render(SHADERTYPE_SCENE, m_plane.GetMesh(), 6, NULL);

	// Present the result.
	m_graphicsEngine.Present();
}

void System::ResetCamera()
{
	// Reset camera.
	DirectX::XMVECTOR position = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR target = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	m_camera.UpdatePosition(position);
	m_camera.UpdateTarget(target);

	// Look vector.
	DirectX::XMVECTOR look = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	look = DirectX::XMVector3Normalize(look);
	m_camera.UpdateLook(look);

	// Up vector.
	DirectX::XMVECTOR right = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	up = DirectX::XMVector3Cross(look, right);
	up = DirectX::XMVector3Normalize(up);
	m_camera.UpdateUpVector(up);

	// Right vector.
	right = DirectX::XMVector3Cross(up, look);
	right = DirectX::XMVector3Normalize(right);
	m_camera.UpdateRight(right);

	// Projection data.
	m_camera.UpdateFieldOfView(3.14159265359f * 0.45f);
	m_camera.UpdateClippingPlanes(0.001f, 1000.0f);
	m_camera.UpdateViewMatrix();
	m_camera.UpdateProjectionMatrix();
}

void System::UpdateMovedCamera()
{
	m_camera.UpdateMovedCamera();
}