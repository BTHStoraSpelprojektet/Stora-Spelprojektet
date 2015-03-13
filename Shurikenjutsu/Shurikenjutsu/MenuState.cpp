#include "MenuState.h"
#include "Menu.h"
#include "MenuTextBox.h"
#include "GUIText.h"
#include "Globals.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "GraphicsEngine.h"
#include "Camera.h"
#include "Frustum.h"
#include "..\CommonLibs\ModelNames.h"
#include "MenuItem.h"
#include "Settings.h"
#include "CreaditsScreen.h"
#include "Network.h"
#include <shellapi.h>
#include <Windows.h>
#include "..\CommonLibs\Flags.h"

// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
const float BUTTONOFFSET = 10.0f;

// CHECKBOX
const float CHECKBOXSIZE = 100.0f;

// VSYNC
const float VSYNCWIDTH = 254.0f;
const float VSYNCHEIGHT = 59.0f;

// FULLSCREEN
const float FULLSCREENWIDTH = 173.0f;
const float FULLSCREENHEIGHT = 58.0f;

// LOGO
const float LOGOPOSX = 0.0f;
const float LOGOPOSY = 250.0f;
const float LOGOWIDTH = 900.0f;
const float LOGOHEIGHT = 307.0f;

MenuState::MenuState(){}
MenuState::~MenuState(){}

void* MenuState::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void MenuState::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool MenuState::Initialize(){
	return Initialize(LEVEL_NAME);
}

bool MenuState::Initialize(std::string p_levelName)
{
	m_lastvsync = false;
	m_lastfullscreen = false;

	Settings* settings = Settings::GetInstance();

	// Initialize logo
	m_logo = new MenuItem();
	m_logo->Initialize(LOGOPOSX, LOGOPOSY, LOGOWIDTH, LOGOHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/Logo_Shurikenjutsu.png"));

	// Initialize options menu
	m_options = new Menu();
	m_vsyncIndex = m_options->AddCheckbox(BUTTONWIDTH - CHECKBOXSIZE*0.5f, 0.0f, MENUACTION_VSYNC, settings->m_vsync);
	m_lastvsync = settings->m_vsync;
	m_options->AddTexture(-BUTTONWIDTH + VSYNCWIDTH*0.5f, 0.0f, VSYNCWIDTH, VSYNCHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/vs_text.png"));

	m_fullscreenIndex = m_options->AddCheckbox(BUTTONWIDTH - CHECKBOXSIZE*0.5f, -CHECKBOXSIZE - BUTTONOFFSET, MENUACTION_FULLSCREEN, settings->m_fullscreen);
	m_lastfullscreen = settings->m_fullscreen;
	m_options->AddTexture(-BUTTONWIDTH + FULLSCREENWIDTH*0.5f, -CHECKBOXSIZE, FULLSCREENWIDTH, FULLSCREENHEIGHT - BUTTONOFFSET, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/fullscreen_text.png"));

	m_options->AddButton(BUTTONWIDTH*0.5f + 10.0f, -3.0f * CHECKBOXSIZE, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/back.png"), MENUACTION_BACK);
	m_options->AddButton(-BUTTONWIDTH*0.5f - 10.0f, -3.0f * CHECKBOXSIZE, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/apply.png"), MENUACTION_OPTIONAPPLY);

	// Initialize main menu
	m_main = new Menu();
	m_main->AddButton(0.0f, -BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/play.png"), MENUACTION_IP);
	m_main->AddButton(0.0f, -1.0f * BUTTONHEIGHT - 2.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/options.png"), MENUACTION_OPTIONS);
	m_main->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/credits.png"), MENUACTION_CREDITS);
	m_main->AddButton(0.0f, -3.0f * BUTTONHEIGHT - 4.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/quit.png"), MENUACTION_BACK);

	// Initialize creditsCreen
	m_creditScreen = new CreaditsScreen();
	m_creditScreen->Initialize();
	m_creditScreen->AddButton(-GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f + BUTTONWIDTH * 0.5f + 10.0f , -3.0f * BUTTONHEIGHT - 4.0f*BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/back.png"), MENUACTION_BACK);

	// Initialize play menu
	m_ipbox = new MenuTextBox();
	m_ipbox->Initialize(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/IPBox.png"), 0, -67, 394.0f, 67.0f, 15, settings->m_ip);
	m_hideIpBox = true;

	m_namebox = new MenuTextBox();
	m_namebox->Initialize(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/namebox.png"), 0, 0, 394.0f, 67.0f, 15, settings->m_name);

	m_play = new Menu();
	m_play->AddButton(0.0f, -2.0f * BUTTONHEIGHT - 3.0f * BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/connect.png"), MENUACTION_CONNECT);
	m_play->AddButton(0.0f, -3.0f * BUTTONHEIGHT - 4.0f * BUTTONOFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/back.png"), MENUACTION_BACK);
	m_play->AddButton(400.0f, -BUTTONOFFSET, BUTTONWIDTH * 0.5f, BUTTONHEIGHT* 0.5f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/host.png"), MENUACTION_HOST_SERVER);

	// Initialize connecting menu;
	m_connecting = new Menu();

	// Push main menu
	m_menues.push(m_main);

	// Initialize the camera.
	m_camera = new Camera();
	m_camera->Initialize();
	m_camera->ResetCamera();

	// Load the level.
	Level level(p_levelName);

	// Initialize the objectmanager.
	m_objectManager = new ObjectManager();
	m_objectManager->SetSound(m_sound);
	m_objectManager->Initialize(&level);

	// Frustum
	m_frustum = new Frustum();
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.18f*0.25, 0.34f*0.25, 0.48f*0.25, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.18f, 0.34f, 0.48f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.77f, 0.94f, 0.94f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 0.0f));

	InitializeCreditScreen();
	m_isPlayingBackgroundMusic = true;
	return true;
}

void MenuState::Shutdown()
{
	if (m_creditScreen != nullptr)
	{
		m_creditScreen->Shutdown();
		delete m_creditScreen;
		m_creditScreen = nullptr;
	}
	if (m_main != nullptr)
	{
		m_main->Shutdown();
		delete m_main;
		m_main = nullptr;
	}
	if (m_options != nullptr)
	{
		m_options->Shutdown();
		delete m_options;
		m_options = nullptr;
	}
	if (m_play != nullptr)
	{
		m_play->Shutdown();
		delete m_play;
		m_play = nullptr;
	}
	if (m_connecting != nullptr)
	{
		m_connecting->Shutdown();
		delete m_connecting;
		m_connecting = nullptr;
	}
	if (m_ipbox != nullptr)
	{
		m_ipbox->Shutdown();
		delete m_ipbox;
		m_ipbox = nullptr;
	}
	if (m_namebox != nullptr)
	{
		m_namebox->Shutdown();
		delete m_namebox;
		m_namebox = nullptr;
	}
	if (m_camera != nullptr)
	{
		m_camera->Shutdown();
		delete m_camera;
		m_camera = nullptr;
	}
	if (m_objectManager != nullptr)
	{
		m_objectManager->Shutdown();
		delete m_objectManager;
		m_objectManager = nullptr;
	}
	
	if (m_frustum != nullptr)
	{
		m_frustum->Shutdown();
		delete m_frustum;
		m_frustum = nullptr;
	}

	if (m_logo != nullptr)
	{
		m_logo->Shutdown();
		delete m_logo;
		m_logo = nullptr;
	}

	if (m_logo != NULL)
	{
		m_logo->Shutdown();
		delete m_logo;
		m_logo = NULL;
	}

	while (!m_menues.empty())
	{
		m_menues.pop();
	}
}

void MenuState::ShutdownExit()
{
	if (m_objectManager != nullptr)
	{
		m_objectManager->ShutdownExit();
	}
}

GAMESTATESWITCH MenuState::Update()
{
	MenuActionData action = m_menues.top()->Update();
	if (!m_hideIpBox)
	{
		m_ipbox->Update();
		m_namebox->Update();
	}

	// Check buttons
	switch (action.m_action)
	{
		case MENUACTION_BACK:
			m_hideIpBox = true;
			m_menues.pop();
			if (m_menues.empty())
			{
				PostQuitMessage(0);
			}
			break;

		case MENUACTION_IP:
			m_hideIpBox = false;
			m_menues.push(m_play);
			break;

		case MENUACTION_PLAY:
			break;
		case MENUACTION_CREDITS:
			m_creditScreen->ResetTexts();
			m_menues.push(m_creditScreen);
			break;

		case MENUACTION_CHOOSENINJA:
			return GAMESTATESWITCH_CHOOSENINJA;
			break;

		case MENUACTION_OPTIONS:
			m_menues.push(m_options);
			m_options->SetCheckboxState(m_vsyncIndex, m_lastvsync);
			m_options->SetCheckboxState(m_fullscreenIndex, m_lastfullscreen);
			break;

		case MENUACTION_CONNECT:
			m_menues.push(m_connecting);
			m_hideIpBox = true;
			Settings::GetInstance()->m_name = m_namebox->GetText();
			Settings::GetInstance()->m_ip = m_ipbox->GetText();
			Network::GetInstance()->SetPlayerName((std::string)m_namebox->GetText());
			Network::GetInstance()->Connect((std::string)m_ipbox->GetText());
			Network::GetInstance()->SetNetworkStatusConnecting();
			break;
		case MENUACTION_HOST_SERVER:
			if (StartLocalServer())
			{
				if (!GLOBAL::GetInstance().FULLSCREEN)
				{
					m_menues.push(m_connecting);
					m_hideIpBox = true;
					Settings::GetInstance()->m_name = m_namebox->GetText();
					Network::GetInstance()->SetPlayerName((std::string)m_namebox->GetText());
					Network::GetInstance()->Connect("127.0.0.1");
					Network::GetInstance()->SetNetworkStatusConnecting();
				}
				else
				{
					GraphicsEngine::ToggleFullscreen(false, (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
					m_menues.push(m_connecting);
					m_hideIpBox = true;
					Settings::GetInstance()->m_name = m_namebox->GetText();
					Network::GetInstance()->SetPlayerName((std::string)m_namebox->GetText());
					Network::GetInstance()->Connect("127.0.0.1");
					Network::GetInstance()->SetNetworkStatusConnecting();
					GraphicsEngine::ToggleFullscreen(true, (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
				}
			}
			break;
		case MENUACTION_OPTIONAPPLY:
			bool temp = m_options->GetCheckboxState(m_vsyncIndex);
			m_lastvsync = temp;
			GraphicsEngine::SetVsync(temp);
			Settings::GetInstance()->m_vsync = temp;

			temp = m_options->GetCheckboxState(m_fullscreenIndex);
			m_lastfullscreen = temp;
			Settings::GetInstance()->m_fullscreen = temp;

			if (!temp)
			{
				GLOBAL::GetInstance().FULLSCREEN = false;
				GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MIN_SCREEN_WIDTH;
				GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MIN_SCREEN_HEIGHT;
			}
			else
			{
				GLOBAL::GetInstance().FULLSCREEN = true;
				GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
				GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
			}
			GraphicsEngine::ToggleFullscreen(temp, (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
			std::string tempstring = m_ipbox->GetText();
			m_ipbox->Shutdown();
			m_ipbox->Initialize(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/IPBox.png"), 0, -67, 394.0f, 67.0f, 15, tempstring);
			m_hideIpBox = true;
			tempstring = m_namebox->GetText();
			m_namebox->Shutdown();
			m_namebox->Initialize(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/GUI/namebox.png"), 0, 0, 394.0f, 67.0f, 15, tempstring);
			break;

	}

	// Check network status
	NETWORKSTATUS ns = Network::GetInstance()->GetNetworkStatus();

	switch (ns)
	{
	case NETWORKSTATUS_NONE:
		break;

	case NETWORKSTATUS_TIMEOUT:
		m_menues.pop();
		m_hideIpBox = false;
		break;

	case NETWORKSTATUS_CONNECTED:
		m_menues.pop();
		m_hideIpBox = false;
		return GAMESTATESWITCH_CHOOSENINJA;
		break;

	}

	// Update Camera position
	m_camera->MenuCameraRotation();

	// Handles screen changes.
	if (GraphicsEngine::HasScreenChanged())
	{
		if (GLOBAL::GetInstance().FULLSCREEN)
		{
			m_camera->ToggleFullscreen(true);
		}
		
		else
		{
			m_camera->ToggleFullscreen(false);
		}

		GraphicsEngine::ScreenChangeHandled();
	}

	// Update Frustum
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);

	// Update Directional Light's camera position
	m_directionalLight.m_cameraPosition = DirectX::XMLoadFloat3(&m_camera->GetPosition());

	// Update every object.
	m_objectManager->UpdateRenderLists();

	// Update every object.
	m_objectManager->Update();

	return GAMESTATESWITCH_NONE;
}

void MenuState::Render()
{
	// Special case for ipbox
	if (!m_hideIpBox)
	{
		m_ipbox->Render();
		m_namebox->Render();
	}

	if (!m_menues.empty())
	{
		if (m_menues.top() != NULL)
		{
			m_menues.top()->Render();
		}
	}

	m_logo->Render();


	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();
	GraphicsEngine::PrepareRenderDepth();
	m_objectManager->RenderDepth();
	GraphicsEngine::PrepareRenderAnimatedDepth();
	m_objectManager->RenderAnimatedDepth();
	GraphicsEngine::SetShadowMap();

	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);

	// Render to the scene normally.
	GraphicsEngine::ClearRenderTargetsForGBuffers();
	GraphicsEngine::SetRenderTargetsForGBuffers();
	GraphicsEngine::PrepareRenderScene();
	m_objectManager->Render();

	GraphicsEngine::PrepareRenderAnimated();
	m_objectManager->RenderAnimated();

	GraphicsEngine::RenderFoliage();

	GraphicsEngine::SetSSAOBuffer(m_camera->GetProjectionMatrix());
	GraphicsEngine::RenderSSAO();

	// Composition
	GraphicsEngine::SetScreenBuffer(m_directionalLight, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	GraphicsEngine::SetPointLightLightBuffer(m_camera->GetViewMatrix());

	GraphicsEngine::Composition();
	GraphicsEngine::ApplyDOF();
	GraphicsEngine::ResetRenderTarget();
	GraphicsEngine::TurnOnDepthStencil();
}

void MenuState::EscapeIsPressed()
{
	m_hideIpBox = true;
	m_menues.pop();
	if (m_menues.empty())
	{
		PostQuitMessage(0);
	}
}

void MenuState::setSound(Sound* p_sound){
	m_sound = p_sound;
}

void MenuState::InitializeCreditScreen(){}

bool MenuState::StartLocalServer()
{
	HINSTANCE hRet;
	if (FLAG_DEBUG == 1)
	{
		hRet = ShellExecute(
			HWND_DESKTOP, //Parent window
			"open",       //Operation to perform
			"..\\Debug\\NinjaServer.exe",       //Path to program
			NULL,         //Parameters
			NULL,         //Default directory
			SW_SHOW);     //How to open
	}
	else
	{
		hRet = ShellExecute(
			HWND_DESKTOP, //Parent window
			"open",       //Operation to perform
			"..\\Release\\NinjaServer.exe",       //Path to program
			NULL,         //Parameters
			NULL,         //Default directory
			SW_SHOW);     //How to open
	}

	/*
	The function returns a HINSTANCE (not really useful in this case)
	So therefore, to test its result, we cast it to a LONG.
	Any value over 32 represents success!
	*/

	if ((LONG)hRet <= 32)
	{
		MessageBox(HWND_DESKTOP, "Unable to start program", "", MB_OK);
		return false;
	}
	return true;
}