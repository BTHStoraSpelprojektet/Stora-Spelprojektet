#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "GUIText.h"
#include "CharacterAbilityDescription.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "Globals.h"
#include <ctime>
#include "Network.h"
#include "ToolTipPopUp.h"
#include "TextResource.h"
#include "Camera.h"
#include "ObjectManager.h"
#include "..\CommonLibs\ModelNames.h"
#include "Frustum.h"
#include "Sound.h"
#include "PlayerManager.h"
#include "MenuButton.h"
#include "ScoreBoard.h"
#include "TeamTable.h"

ChooseState::ChooseState(){}
ChooseState::~ChooseState(){}

/*TODO
 - Texts - orkar!!!!! INTE!!!!
 */
void* ChooseState::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void ChooseState::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool ChooseState::Initialize(){
	return Initialize(LEVEL_NAME);
}

bool ChooseState::Initialize(std::string p_levelName)
{
	m_redTeamScore = new GUIText();
	m_blueTeamScore = new GUIText();
	m_blueTeam = new TeamTable();
	m_redTeam = new TeamTable();
	m_title = new MenuItem(); 
	m_tintedBackground = new MenuItem();
	m_chooseNinja = new Menu();
	m_questionMark = new MenuItem();

	m_currentTeam = CURRENTTEAM_NONE;
	m_isRandoming = false;
	m_screenHeight = (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
	m_screenWidth = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH;
	m_portraitHeight = 200.0f;
	m_portraitWidth = 200.0f;
	m_buttonWidth = 300.0f;
	m_buttonHeight = 100.0f; 
	m_nextWidth = 50.0f;
	m_nextHeight = 200.0f;
	m_toolWidth = 50.0f;
	m_toolHeight = 50.0f;
	m_nrOfNinjas = 3;
	m_currentNinja = 0;
	m_nrOfTools = 3;
	m_currentTool = 0;
	m_prevRandomNumber = 0;
	m_redTeamScore->Initialize("0",  50.0f, -m_screenWidth * 0.33f, m_screenHeight * 0.5f - 50.0f, 0xff0000ff);
	m_blueTeamScore->Initialize("0",  50.0f, m_screenWidth * 0.33f, m_screenHeight * 0.5f - 50.0f, 0xffff0000);
		
	float offset = 30.0f;
	float ninjaCycleHeight = -m_buttonHeight*0.5f +offset;
	float toolCycleHeight = /*m_toolHeight*0.5f - m_buttonHeight*0.5f */- 280.0f;
	float portraitYPos = ninjaCycleHeight;//ninjaCycleHeight + m_portraitHeight*0.5f - m_buttonHeight* 0.5f;
	float toolButtonSize = 60.0f;//m_screenHeight / 20.48f;
	float toolButtonXPos = 70.0f;

	m_redTeam->Initialize(-m_screenWidth * 0.5f, m_screenHeight * 0.33f, 1);
	m_blueTeam->Initialize(m_screenWidth * 0.5f, m_screenHeight * 0.33f, 2);
	m_tintedBackground->Initialize(0.0f, 0.0f, m_screenWidth, m_screenHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/bgTint.png"));
	m_title->Initialize(0.0f, m_screenHeight / 2.0f - m_buttonHeight * 0.5f, m_buttonWidth * 2.0f, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/chooseButton.png"));
	
	//the questionmark
	m_questionMark->Initialize(0.0f, 0.0f, m_screenHeight / 13.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/pickChara.png"));

	// pick red team
	m_chooseNinja->AddButton(-m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/redTeamLobby.png"), MENUACTION_PICK_RED_TEAM);

	// pick blue team
	m_chooseNinja->AddButton(m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/blueTeamLobby.png"), MENUACTION_PICK_BLUE_TEAM);
	
	// back button
	m_chooseNinja->AddButton(-m_screenWidth * 0.5f + m_buttonWidth * 0.5f + offset, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/back.png"), MENUACTION_BACK);
	
	// Play button
	m_playButton = new MenuButton();
	m_playButton->Initialize(m_screenWidth * 0.5f - m_buttonWidth * 0.5f - offset, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/play.png"), MENUACTION_PLAY);

	// Random Ninja button
	m_chooseNinja->AddButton(0.0f, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/randomButton.png"), MENUACTION_RANDOM_NINJA);

	// Next ninja, right button
	m_chooseNinja->AddButton(/*m_buttonWidth*0.5f + */m_nextWidth*0.5f + 120.0f, ninjaCycleHeight, m_nextWidth, m_nextHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/thinarrow_right.png"), MENUACTION_NEXTNINJA);

	// Prev ninja, left button
	m_chooseNinja->AddButton(/*-m_buttonWidth*0.5f -*/-m_nextWidth*0.5f - 120.0f, ninjaCycleHeight, m_nextWidth, m_nextHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/thinarrow_left.png"), MENUACTION_PREVNINJA);

	//Prev tool, left button
	m_chooseNinja->AddButton(-toolButtonXPos, toolCycleHeight, toolButtonSize, toolButtonSize, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/left.png"), MENUACTION_PREVTOOL);

	//Next tool, right button
	m_chooseNinja->AddButton(toolButtonXPos, toolCycleHeight, toolButtonSize, toolButtonSize, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/right.png"), MENUACTION_NEXTTOOL);

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja3.png"));

	m_tools[0] = new MenuItem();
	m_tools[1] = new MenuItem();
	m_tools[2] = new MenuItem();
	m_tools[0]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_Caltrops.png"));
	m_tools[1]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_SmokeBomb.png"));
	m_tools[2]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_StickyTARP.png"));

	m_ninjaPortBorder = new MenuItem();
	m_ninjaPortBorder->Initialize(0.0f, portraitYPos, 240, 240, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/portBG.png"));

	m_backgroundFrame = new MenuItem();
	m_backgroundFrame->Initialize(0.0f, 0.0f, 410, 440, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/lobby_bg.png"));

	float bgWidth = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 3.0f;
	float bgHeight = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 6.83f;
	m_toolDescription[0] = new ToolTipPopUp();
	m_toolDescription[1] = new ToolTipPopUp();
	m_toolDescription[2] = new ToolTipPopUp();
	m_toolDescription[0]->Initialize(0.0f, toolCycleHeight, SPIKES_DESCRIPTION, m_toolHeight, bgWidth, bgHeight, -25.0f);
	m_toolDescription[1]->Initialize(0.0f, toolCycleHeight, SMOKEBOMB_DESCRIPTION, m_toolHeight, bgWidth, bgHeight, -25.0f);
	m_toolDescription[2]->Initialize(0.0f, toolCycleHeight, STICKY_DESCRIPTION, m_toolHeight, bgWidth, bgHeight, -25.0f);
	
	m_abilityDescription[0] = new CharacterAbilityDescription();
	m_abilityDescription[1] = new CharacterAbilityDescription();
	m_abilityDescription[2] = new CharacterAbilityDescription();
	m_abilityDescription[0]->Initialize(1);
	m_abilityDescription[1]->Initialize(2);
	m_abilityDescription[2]->Initialize(3);

	m_camera = new Camera();
	m_camera->Initialize();
	m_camera->ResetCamera();

	// Load the level.
	Level level(p_levelName);

	m_objectManager = new ObjectManager();
	m_objectManager->SetSound(m_sound);
	m_objectManager->Initialize(&level);

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.18f*0.25, 0.34f*0.25, 0.48f*0.25, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.18f, 0.34f, 0.48f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(0.77f, 0.94f, 0.94f, 1.0f);
	m_directionalLight.m_direction = DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 0.0f));

	m_frustum = new Frustum();
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);

	m_playerManager = new PlayerManager();
	m_playerManager->Initialize(true);
	m_playerManager->UpdateFrustum(m_frustum);

	// Initialize the score board
	ScoreBoard::GetInstance()->Initialize();

	return true;
}

void ChooseState::Shutdown()
{
	if (m_playButton != nullptr)
	{
		m_playButton->Shutdown();
		delete m_playButton;
		m_playButton = nullptr;
	}
	if (m_tintedBackground != nullptr)
	{
		m_tintedBackground->Shutdown();
		delete m_tintedBackground;
		m_tintedBackground = nullptr;
	}
	if (m_title != nullptr)
	{
		m_title->Shutdown();
		delete m_title;
		m_title = nullptr;
	}
	if (m_playerManager != nullptr)
	{
		m_playerManager->Shutdown();
		delete m_playerManager;
		m_playerManager = nullptr;
	}
	if (m_frustum != nullptr)
	{
		m_frustum->Shutdown();
		delete m_frustum;
		m_frustum = nullptr;
	}
	if (m_objectManager != nullptr)
	{
		m_objectManager->Shutdown();
		delete m_objectManager;
		m_objectManager = nullptr;
	}
	if (m_camera != nullptr)
	{
		m_camera->Shutdown();
		delete m_camera;
		m_camera = nullptr;
	}
	if (m_redTeam != nullptr)
	{
		m_redTeam->Shutdown();
		delete m_redTeam;
		m_redTeam = nullptr;
	}
	if (m_blueTeam != nullptr)
	{
		m_blueTeam->Shutdown();
		delete m_blueTeam;
		m_blueTeam = nullptr;
	}
	if (m_redTeamScore != nullptr)
	{
		m_redTeamScore->Shutdown();
		delete m_redTeamScore;
		m_redTeamScore = nullptr;
	}
	if (m_blueTeamScore != nullptr)
	{
		m_blueTeamScore->Shutdown();
		delete m_blueTeamScore;
		m_blueTeamScore = nullptr;
	}
	if (m_chooseNinja != nullptr)
	{
		m_chooseNinja->Shutdown();
		delete m_chooseNinja;
		m_chooseNinja = nullptr;
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		if (m_ninjas[i] != nullptr)
		{
			m_ninjas[i]->Shutdown();
			delete m_ninjas[i];
			m_ninjas[i] = nullptr;
		}
	}

	for (unsigned int i = 0; i < 3; i++)
	{
		if (m_toolDescription[i] != nullptr)
		{
			m_toolDescription[i]->Shutdown();
			delete m_toolDescription[i];
			m_toolDescription[i] = nullptr;
		}
	}

	//needs fixin'
	for (unsigned int i = 0; i < 3; i++)
	{
		if (m_tools[i] != nullptr)
		{
			m_tools[i]->Shutdown();
			delete m_tools[i];
			m_tools[i] = nullptr;
		}
	}

	if (m_ninjaPortBorder != nullptr)
	{
		m_ninjaPortBorder->Shutdown();
		delete m_ninjaPortBorder;
		m_ninjaPortBorder = nullptr;
	}

	if (m_backgroundFrame != nullptr)
	{
		m_backgroundFrame->Shutdown();
		delete m_backgroundFrame;
		m_backgroundFrame = nullptr;
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		if (m_abilityDescription[i] != nullptr)
		{
			m_abilityDescription[i]->Shutdown();
			delete m_abilityDescription[i];
			m_abilityDescription[i] = nullptr;
		}
	}

	if (m_questionMark != nullptr)
	{
		m_questionMark->Shutdown();
		delete m_questionMark;
		m_questionMark = nullptr;
	}

	ScoreBoard::GetInstance()->Shutdown();
}

void ChooseState::ShutdownExit()
{
	if (m_objectManager != nullptr)
	{
		m_objectManager->ShutdownExit();
	}
}

ObjectManager* ChooseState::GetObjectManager()
{
	return m_objectManager;
}

GAMESTATESWITCH ChooseState::Update()
{
	// Update Camera position
	m_camera->MenuCameraRotation();

	m_objectManager->UpdateFrustum(m_frustum);
	m_playerManager->UpdateFrustum(m_frustum);

	// Update Directional Light's camera position
	m_directionalLight.m_cameraPosition = DirectX::XMLoadFloat3(&m_camera->GetPosition());
	m_playerManager->Update(true);

	// Update every object.
	m_objectManager->Update();


	if (m_isRandoming)
	{
		NextNinja();
		PrevTool();
	}
	else
	{
		m_abilityDescription[m_currentNinja]->Update();
		m_toolDescription[m_currentTool]->Update();
	}
	UpdateTeams();

	if (m_currentTeam == CURRENTTEAM_RED)
	{
		m_questionMark->SetPosition(m_redTeam->GetXPos(), m_redTeam->GetNextYPos());
		if (m_redTeam->GetNumberOfPlayers() == 4)
		{
			m_currentTeam = CURRENTTEAM_NONE;
		}
	}
	if (m_currentTeam == CURRENTTEAM_BLUE)
	{
		m_questionMark->SetPosition(m_blueTeam->GetXPos(), m_blueTeam->GetNextYPos());
		if (m_blueTeam->GetNumberOfPlayers() == 4)
		{
			m_currentTeam = CURRENTTEAM_NONE;
		}
	}
	if (m_currentTeam == CURRENTTEAM_NONE)
	{
		m_questionMark->SetPosition(0, m_screenHeight * 0.33f);
	}


	m_redTeamScore->SetText(std::to_string(Network::GetInstance()->GetRedTeamScore()));
	m_blueTeamScore->SetText(std::to_string(Network::GetInstance()->GetBlueTeamScore()));
	
	MenuActionData action = m_chooseNinja->Update();
	
	switch (action.m_action)
	{
	case MENUACTION_BACK:
			Network::GetInstance()->Disconnect();
			return GAMESTATESWITCH_MENU;
		break;
	case MENUACTION_NEXTNINJA:
		m_isRandoming = false;
		NextNinja();
		break;
	case MENUACTION_PREVNINJA:
		m_isRandoming = false;
		PrevNinja();
		break;
	case MENUACTION_NEXTTOOL:
		m_isRandoming = false;
		NextTool();
		break;
	case MENUACTION_PREVTOOL:
		m_isRandoming = false;
		PrevTool();
		break;
	case MENUACTION_PICK_BLUE_TEAM:
		if (m_currentTeam == CURRENTTEAM_BLUE)
		{
			m_currentTeam = CURRENTTEAM_NONE;
		}
		else if (m_blueTeam->GetNumberOfPlayers() < 4)
		{
			m_currentTeam = CURRENTTEAM_BLUE;
		}
		break;
	case MENUACTION_PICK_RED_TEAM:
		if (m_currentTeam == CURRENTTEAM_RED)
		{
			m_currentTeam = CURRENTTEAM_NONE;
		}
		else if (m_redTeam->GetNumberOfPlayers() < 4)
		{
			m_currentTeam = CURRENTTEAM_RED;
		}
		break;
	case MENUACTION_RANDOM_NINJA:
		/*if (m_isRandoming)
		{
			m_isRandoming = false;
		}
		else
		{
			m_isRandoming = true;
		}*/
		RandomNinja();	
		break;
	case MENUACTION_CLICKED_QUESTIONMARK:
		m_currentTeam = CURRENTTEAM_NONE;
		break;
	}

	ScoreBoard::GetInstance()->Update();

	if (m_playButton->IsClicked())
	{
		if (!Network::GetInstance()->GetMatchOver())
		{
			if (m_currentTeam == CURRENTTEAM_RED)
			{
				Network::GetInstance()->ChooseChar(m_currentNinja, m_currentTool, 1);
			}
			else if (m_currentTeam == CURRENTTEAM_BLUE)
			{
				Network::GetInstance()->ChooseChar(m_currentNinja, m_currentTool, 2);
			}
			else
			{
				Network::GetInstance()->ChooseChar(m_currentNinja, m_currentTool, 0);
			}
			Network::GetInstance()->SetHaveUpdateNewLevel();
			return GAMESTATESWITCH_PLAY;
		}
		else
		{
			return GAMESTATESWITCH_NONE;
		}
	}

	return GAMESTATESWITCH_NONE;
}

void ChooseState::UpdateTeams()
{
	m_redTeam->ClearList();
	m_blueTeam->ClearList();
	std::vector<PlayerNet> tempPlayerList = Network::GetInstance()->GetOtherPlayers();
	for (unsigned int i = 0; i < tempPlayerList.size(); i++)
	{
		if (tempPlayerList[i].team == 1)
		{
			m_redTeam->AddTeamMate(tempPlayerList[i].charNr, tempPlayerList[i].toolNr);
		}
		else
		{
			m_blueTeam->AddTeamMate(tempPlayerList[i].charNr, tempPlayerList[i].toolNr);
		}
	}
}

void ChooseState::Render()
{
	// Draw to the shadowmap.
	GraphicsEngine::BeginRenderToShadowMap();
	GraphicsEngine::PrepareRenderDepth();
	m_objectManager->RenderDepth();

	GraphicsEngine::PrepareRenderAnimatedDepth();
	m_objectManager->RenderAnimatedDepth();
	m_playerManager->RenderDepth(true);
	GraphicsEngine::SetShadowMap();

	GraphicsEngine::SetSceneDirectionalLight(m_directionalLight);

	// Render to the scene normally.
	GraphicsEngine::ClearRenderTargetsForGBuffers();
	GraphicsEngine::SetRenderTargetsForGBuffers();

	m_objectManager->RenderInstanced();
	GraphicsEngine::PrepareRenderScene();
	m_objectManager->Render();

	GraphicsEngine::PrepareRenderAnimated();
	m_objectManager->RenderAnimated();
	m_playerManager->Render(true);

	GraphicsEngine::RenderFoliage();
	GraphicsEngine::SetSSAOBuffer(m_camera->GetProjectionMatrix());
	GraphicsEngine::RenderSSAO();

	// Composition
	GraphicsEngine::SetScreenBuffer(m_directionalLight, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	GraphicsEngine::SetPointLightLightBuffer(m_camera->GetViewMatrix());
	GraphicsEngine::Composition();
	GraphicsEngine::ApplyDOF();

	GraphicsEngine::TurnOnDepthStencil();

	GraphicsEngine::ResetRenderTarget();

	m_tintedBackground->Render();
	m_backgroundFrame->Render();
	m_chooseNinja->Render();

	m_ninjas[m_currentNinja]->Render();
	m_tools[m_currentTool]->Render();
	m_ninjaPortBorder->Render();
	m_abilityDescription[m_currentNinja]->Render();
	//m_redTeamScore->Render();
	//m_blueTeamScore->Render();
	m_redTeam->Render();
	m_blueTeam->Render();
	m_questionMark->Render();
	m_toolDescription[m_currentTool]->Render();
	m_title->Render();

	if (!Network::GetInstance()->GetMatchOver())
	{
		m_playButton->Render();
	}
}

void ChooseState::NextNinja()
{
	m_currentNinja += 1;
	if (m_currentNinja >= m_nrOfNinjas)
	{
		m_currentNinja = 0;
	}
}

void ChooseState::PrevNinja()
{
	m_currentNinja -= 1;
	if (m_currentNinja < 0)
	{
		m_currentNinja = m_nrOfNinjas - 1;
	}
}

void ChooseState::NextTool()
{
	m_currentTool += 1;
	if (m_currentTool >= m_nrOfTools)
	{
		m_currentTool = 0;
	}
}

void ChooseState::PrevTool()
{
	m_currentTool -= 1;
	if (m_currentTool < 0)
	{
		m_currentTool = m_nrOfTools - 1;
	}
}

void ChooseState::EscapeIsPressed()
{
	Network::GetInstance()->Disconnect();
}

void ChooseState::RandomNinja()
{
	std::srand((unsigned int)std::time(0));
	int randomNumber = std::rand() % 9;
	while (m_prevRandomNumber == randomNumber)
	{
		randomNumber = std::rand() % 9;
	}
	if (randomNumber == 0)
	{
		m_currentNinja = 0;
		m_currentTool = 0;
	}
	else if (randomNumber == 1)
	{
		m_currentNinja = 0;
		m_currentTool = 1;
	}
	else if (randomNumber == 2)
	{
		m_currentNinja = 0;
		m_currentTool = 2;
	}
	else if (randomNumber == 3)
	{
		m_currentNinja = 1;
		m_currentTool = 0;
	}
	else if (randomNumber == 4)
	{
		m_currentNinja = 1;
		m_currentTool = 1;
	}
	else if (randomNumber == 5)
	{
		m_currentNinja = 1;
		m_currentTool = 2;
	}
	else if (randomNumber == 6)
	{
		m_currentNinja = 2;
		m_currentTool = 0;
	}
	else if (randomNumber == 7)
	{
		m_currentNinja = 2;
		m_currentTool = 1;
	}
	else if (randomNumber == 8)
	{
		m_currentNinja = 2;
		m_currentTool = 2;
	}
	m_prevRandomNumber = randomNumber;
}
