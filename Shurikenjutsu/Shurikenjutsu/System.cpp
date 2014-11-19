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
	m_camera.Initialize();
	m_camera.CreateProjectionMatrix(90.0f, (float)window.height, (float)window.width, 0.001f, 100000.0f);
	m_camera.UpdateViewMatrix();
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
void System::TestCollisions()
{
	//Testing Collisions
	if (m_collision.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 5.0f, 0.0f, 5.0f)))
	{
		std::cout << "1. Sphere Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.SphereSphereCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Sphere(0.0f, 16.0f, 0.0f, 5.0f)))
	{
		std::cout << "2. Sphere Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "3. Box Box True" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.BoxBoxCollision(Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "4. Box Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.SphereBoxCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Box(11.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "5. Sphere Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.SphereBoxCollision(Sphere(0.0f, 0.0f, 0.0f, 10.0f), Box(16.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "6. Sphere Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "7. Frustum Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.FrustrumBoxCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Box(0.0f, 0.0f, 12.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "8. Frustum Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, 10.0f, 10.0f)))
	{
		std::cout << "9. Frustum Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.FrustrumSphereCollision(Frustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 10.0f), Sphere(0.0f, 0.0f, -10.0f, 10.0f)))
	{
		std::cout << "10. Frustum Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.RayBoxCollision(Ray(0.0f, 0.0f, 0.0f, 8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "11. Ray Box true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.RayBoxCollision(Ray(0.0f, 0.0f, 0.0f, -8.0f, 0.0f, 0.0f), Box(8.0f, 0.0f, 0.0f, 5.0f, 5.0f, 5.0f)))
	{
		std::cout << "12. Ray Box false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (m_collision.RaySphereCollision(Ray(0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)))
	{
		std::cout << "13. Ray Sphere true" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
	if (!m_collision.RaySphereCollision(Ray(0.0f, 0.0f, 0.0f, -10.0f, 0.0f, 0.0f), Sphere(10.0f, 0.0f, 0.0f, 5.0f)))
	{
		std::cout << "14. Ray Sphere false" << std::endl;
	}
	else
	{
		std::cout << "TestFailed" << std::endl;
	}
}