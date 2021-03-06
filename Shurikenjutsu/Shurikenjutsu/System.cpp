#include "System.h"
#include "Sound.h"
#include "Timer.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "GraphicsEngine.h"
#include "GUIManager.h"
#include "ChooseState.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "Camera.h"
#include "GameState.h"
#include "Model.h"
#include "InputManager.h"
#include "Globals.h"
#include "Cursor.h"
#include "ParticleRenderer.h"
#include "DeathBoard.h"
#include "TrailRenderer.h"
#include "MemoryChecker.h"
#include "DebugText.h"
#include "Settings.h"
#include "Window.h"
//#include <vld.h>

bool System::Initialize(int p_argc, _TCHAR* p_argv[])
{
	Settings::GetInstance()->LoadSettingsFile();
	Settings* temp = Settings::GetInstance();
	// Set default game state.
	m_chooseNinjaState = new ChooseState();
	m_menuState = new MenuState();
	m_playingState = new PlayingState();
	m_gameState = m_menuState;

	// Set starting window values.
	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = false;
	GLOBAL::GetInstance().FULLSCREEN = Settings::GetInstance()->m_fullscreen;
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

	GLOBAL::GetInstance().CAMERA_MOVING = !Settings::GetInstance()->m_cameraMode;
	GLOBAL::GetInstance().CAMERA_SPECTATE = false;

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
	m_window = new Window();
	m_window->Initialize(window);
	ConsolePrintSuccess("Window created successfully.");
	std::string size = "Window size: " + std::to_string(window.width);
	size.append("x" + std::to_string(window.height));
	ConsolePrintText(size);
	ConsoleSkipLines(1);

	// Update window title.
	m_title = "Shurikenjutsu";
	m_window->SetTitle(m_title);

	// Initialize the graphics engine.
	GraphicsEngine::Initialize(m_window->GetHandle(), (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, (float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH, (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT, GLOBAL::GetInstance().FULLSCREEN);
	GraphicsEngine::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GraphicsEngine::SetSceneFog(0.0f, 500.0f, 0.01f);
	GraphicsEngine::SetShadowMapDimensions((float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH, (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT);
	GraphicsEngine::TurnOnAlphaBlending();
	GraphicsEngine::SetVsync(Settings::GetInstance()->m_vsync);
	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = false;

	// Initialize the trail renderer.
	TrailRenderer::GetInstance().Initialize(GraphicsEngine::GetDevice());

	// Initialize model library.
	ConsolePrintText("Loading all models...");
	ModelLibrary::GetInstance()->Initialize(new Model());
	ConsolePrintSuccess("All models loaded.");
	ConsoleSkipLines(1);

	ConsolePrintText("Loading all textures...");
	TextureLibrary::GetInstance()->Initialize();
	ConsolePrintSuccess("All textures loaded.");
	ConsoleSkipLines(1);

	// Initialize timer.
	m_previousFPS = 0;
	m_timer = new Timer();
	m_timer->Initialize();
	m_timer->StartTimer();
	ConsolePrintSuccess("Timer initialized successfully.");
	ConsoleSkipLines(1);

	m_sound = new Sound();
	if (!m_sound->Initialize())
	{
		ConsolePrintError("Sound Initialize failed.");
		ConsoleSkipLines(1);
	}
	else
	{
		ConsolePrintSuccess("Sound initialized successfully.");
		ConsoleSkipLines(1);
		//m_sound->PlaySound(PLAYSOUND::PLAYSOUND_BACKGROUND_SOUND);
		m_sound->StartMusic();
		m_playingState->SetSound(m_sound);
		m_menuState->setSound(m_sound);

		if (Settings::GetInstance()->m_muteSound)
		{
			GLOBAL::GetInstance().VOLUME_ON = false;
			m_sound->MuteEverything();
		}

		else
		{
			GLOBAL::GetInstance().VOLUME_ON = true;
			m_sound->UnMuteEverything();
		}
	}

	// Initialize current GameState
	m_gameState->Initialize();

	// Input: Register keys
	ConsolePrintText("Registering all input keys...");
	InputManager::GetInstance()->Initialize();
	InputManager::GetInstance()->RegisterKey(VkKeyScan('w'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('a'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('s'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('d'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('q'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('e'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('l'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('v'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('r'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('o'));
	InputManager::GetInstance()->RegisterKey(VkKeyScan('m'));
	InputManager::GetInstance()->RegisterKey(VK_UP);
	InputManager::GetInstance()->RegisterKey(VK_LEFT);
	InputManager::GetInstance()->RegisterKey(VK_DOWN);
	InputManager::GetInstance()->RegisterKey(VK_RIGHT);
	InputManager::GetInstance()->RegisterKey(VK_ESCAPE);
	InputManager::GetInstance()->RegisterKey(VK_TAB);
	InputManager::GetInstance()->RegisterKey(VK_F1);
	InputManager::GetInstance()->RegisterKey(VK_F2);
	InputManager::GetInstance()->RegisterKey(VK_SPACE);
	InputManager::GetInstance()->RegisterKey(VK_CONTROL);
	ConsolePrintSuccess("Input keys registered.");
	ConsoleSkipLines(1);

	// Initialize the network.
	Network::GetInstance()->Initialize();
	ConsolePrintSuccess("Network initialized successfully.");
	ConsoleSkipLines(1);

	// Initialize the cursor.
	m_cursor = new Cursor();
	if (!m_cursor->Initialize())
	{
		return false;
	}

	// Initialize memory checker
	m_memoryCheker = new MemoryChecker();
	if (!m_memoryCheker->Initialize())
	{
		return false;
	}

	// Initialize debug text
	if (!DebugText::GetInstance()->Initialize())
	{
		ConsolePrintError("Debug text Initialize failed.");
		ConsoleSkipLines(1);
		return false;
	}

	if (!DeathBoard::GetInstance()->Initialize())
	{
		return false;
	}

	GraphicsEngine::ClearSSAO();
	return true;
}

void System::Shutdown()
{
	// Shutdown input.
	InputManager::GetInstance()->Shutdown();

	// Shutdown network
	Network::GetInstance()->Shutdown();

	// Shutdown texture lib
	TextureLibrary::GetInstance()->Shutdown();

	if (m_sound)
	{
		m_sound->Shutdown();
		delete m_sound;
		m_sound = 0;
	}

	if (m_cursor != nullptr)
	{
		m_cursor->Shutdown();
		delete m_cursor;
		m_cursor = nullptr;
	}

	GUIManager::GetInstance()->Shutdown();


	//Shutdown current state
	if (m_menuState != nullptr)
	{
		m_menuState->ShutdownExit();
		m_menuState->Shutdown();
		delete m_menuState;
		m_menuState = nullptr;
	}
	if (m_playingState != nullptr)
	{
		m_playingState->ShutdownExit();
		m_playingState->Shutdown();
		delete m_playingState;
		m_playingState = nullptr;
	}
	if (m_chooseNinjaState != nullptr)
	{
		m_chooseNinjaState->ShutdownExit();
		m_chooseNinjaState->Shutdown();
		delete m_chooseNinjaState;
		m_chooseNinjaState = nullptr;
	}

	if (m_timer)
	{
		m_timer->Shutdown();
		delete m_timer;
		m_timer = nullptr;
	}

	ParticleRenderer::GetInstance()->Shutdown();

	// Shutdown model library
	ModelLibrary::GetInstance()->Shutdown();

	// Shutdown graphics engine.
	GraphicsEngine::Shutdown();

	DeathBoard::GetInstance()->Shutdown();

	TrailRenderer::GetInstance().Shutdown();

	if (m_memoryCheker != nullptr)
	{
		m_memoryCheker->Shutdown();
		delete m_memoryCheker;
		m_memoryCheker = nullptr;
	}

	DebugText::GetInstance()->Shutdown();

	Settings::GetInstance()->SaveSettingsFile();
	Settings::GetInstance()->Shutdown();
	if (m_window != nullptr)
	{
		delete m_window;
		m_window = nullptr;
	}
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
	m_timer->Update();

	// Get the delta time to use for animation etc.
	GLOBAL::GetInstance().SetDeltaTime(m_timer->GetDeltaTime());

	// Update border size
	RECT windowRect;
	GetWindowRect(m_window->GetHandle(), &windowRect);
	RECT clientRect;
	GetClientRect(m_window->GetHandle(), &clientRect);
	GLOBAL::GetInstance().BORDER_SIZE = (float)((windowRect.right - windowRect.left) - (clientRect.right - clientRect.left)) * 0.5f;
	GLOBAL::GetInstance().TITLE_BORDER_SIZE = (float)((windowRect.bottom - windowRect.top) - (clientRect.bottom - clientRect.top)) - 2.0f * GLOBAL::GetInstance().BORDER_SIZE;

	if (FLAG_FPS == 1)
	{
		int fps = m_timer->GetFPS();

		if (fps != m_previousFPS)
		{
			GLOBAL::GetInstance().FPS = std::to_string(m_timer->GetFPS());
			m_previousFPS = fps;
		}
	}

	std::string levelName;
	switch (m_gameState->Update())
	{
	case GAMESTATESWITCH_CHOOSENINJA:
		m_gameState = m_chooseNinjaState;
		m_gameState->Shutdown();
		levelName = Network::GetInstance()->LevelName();
		m_gameState->Initialize(levelName);
		Network::GetInstance()->SetObjectManager(m_chooseNinjaState->GetObjectManager());
		Network::GetInstance()->SetSound(m_sound);
		Network::GetInstance()->SetMyPlayerIsInLobby(true);
		m_cursor->LargeSize();
		break;
	case GAMESTATESWITCH_PLAY:
		m_gameState = m_playingState;
		m_playingState->SetSound(m_sound);
		m_playingState->Shutdown();
		levelName = Network::GetInstance()->LevelName();
		m_gameState->Initialize(levelName);
		Network::GetInstance()->SetObjectManager(m_playingState->GetObjectManager());
		Network::GetInstance()->SetSound(m_sound);
		m_sound->StopMusic();
		m_cursor->SmallSize();
		break;
	case GAMESTATESWITCH_MENU:
		m_gameState = m_menuState;
		m_gameState->EscapeIsPressed();
		m_cursor->LargeSize();
		break;
	}
	
	m_sound->Update();
	m_cursor->Update();

	// Update network
	Network::GetInstance()->Update();

	// Quick escape.
	if (InputManager::GetInstance()->IsKeyClicked(VK_ESCAPE))
	{
		if (m_gameState == m_menuState)
		{
			m_gameState->EscapeIsPressed();
		}
		if (m_gameState == m_chooseNinjaState)
		{
			//Back to menu
			m_gameState->EscapeIsPressed();
			m_gameState = m_menuState;
			m_gameState->EscapeIsPressed();
		}
		if (m_gameState == m_playingState)
		{
			//In game menum
			m_gameState->EscapeIsPressed();
		}
	}

	m_memoryCheker->Update();
	DebugText::GetInstance()->Update();
}

// Render game scene here.
void System::Render()
{
	// Clear the scene to begin rendering.
	GraphicsEngine::Clear();

	// Render Current GameState
	m_gameState->Render();

	TrailRenderer::GetInstance().RenderTrails();

	// Render Particles
	GraphicsEngine::TurnOnAlphaBlending();
	GraphicsEngine::SetDepthStateForParticles();
	ParticleRenderer::GetInstance()->Render();	

	// The need to switch back to the original depth stencil state is not needed yet, since GUI switches it to be completely off

	//Render GUI
	GraphicsEngine::TurnOffDepthStencil();

	DebugText::GetInstance()->Render();
	GraphicsEngine::PrepareRenderGUI();
	GUIManager::GetInstance()->Render();

	// Render cursor
	m_cursor->Render();
	GraphicsEngine::TurnOffAlphaBlending();
	GraphicsEngine::TurnOnDepthStencil();

	// Present the result.
	GraphicsEngine::Present();
}
