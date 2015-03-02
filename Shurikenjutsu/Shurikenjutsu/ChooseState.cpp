#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "GUIText.h"
#include "CharacterAbilityDescription.h"
#include "TextureLibrary.h"
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
#include "PointLights.h"

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

bool ChooseState::Initialize()
{
	m_currentTeam = CURRENTTEAM_NONE;
	m_isRandoming = false;
	m_screenHeight = (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
	m_screenWidth = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH;
	m_portraitHeight = 200.0f;
	m_portraitWidth = 200.0f;
	m_buttonWidth = m_screenWidth / 4.27f;
	m_buttonHeight = m_screenHeight / 10.24f; 
	m_nextWidth = m_screenWidth / 12.80f;
	m_nextHeight = m_screenHeight / 10.24f;
	m_toolWidth = m_nextWidth * 0.5f;
	m_toolHeight = m_nextHeight * 0.5f;
	nrOfNinjas = 3;
	currentNinja = 0;
	nrOfTools = 3;
	currentTool = 0;
	m_redTeamScore = new GUIText();
	m_blueTeamScore = new GUIText();
	m_redTeamScore->Initialize("0", 50.0f, -m_screenWidth * 0.1f, m_screenHeight * 0.33f, 0xff0000ff);
	m_blueTeamScore->Initialize("0", 50.0f, m_screenWidth * 0.1f, m_screenHeight * 0.33f, 0xffff0000);
	
	
	float offset = 30.0f;
	float ninjaCycleHeight = -m_buttonHeight*0.5f + offset;
	float toolCycleHeight = m_toolHeight*0.5f - m_buttonHeight*0.5f- 150.0f;
	float portraitYPos = ninjaCycleHeight + m_portraitHeight*0.5f - m_buttonHeight* 0.5f;
	float toolButtonSize = m_screenHeight / 20.48f;
	float toolButtonXPos = m_screenHeight / 18.29f;

	m_blueTeam = new TeamTable();
	m_redTeam = new TeamTable();
	m_redTeam->Initialize(-m_screenWidth * 0.5f, m_screenHeight * 0.33f, 1);
	m_blueTeam->Initialize(m_screenWidth * 0.5f, m_screenHeight * 0.33f, 2);
	m_title = new MenuItem(); 
	m_tintedBackground = new MenuItem();
	m_chooseNinja = new Menu();
	m_questionMark = new MenuItem();
	m_tintedBackground->Initialize(0.0f, 0.0f, m_screenWidth, m_screenHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/bgTint.png"));
	m_title->Initialize(0.0f, m_screenHeight / 2.0f - m_buttonHeight * 0.5f, m_buttonWidth * 2.0f, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/chooseButton.png"));
	//the questionmark
	m_questionMark->Initialize(0.0f, 0.0f, m_screenHeight / 13.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/pickChara.png"));

	// pick red team
	m_chooseNinja->AddButton(-m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/redTeamLobby.png"), MENUACTION_PICK_RED_TEAM);

	// pick blue team
	m_chooseNinja->AddButton(m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/blueTeamLobby.png"), MENUACTION_PICK_BLUE_TEAM);
	
	// back button
	m_chooseNinja->AddButton(-m_screenWidth * 0.5f + m_buttonWidth * 0.5f + offset, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);

	// Play button
	m_chooseNinja->AddButton(m_screenWidth * 0.5f - m_buttonWidth * 0.5f - offset, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_PLAY);

	// Random Ninja button
	m_chooseNinja->AddButton(0.0f, -m_screenHeight * 0.5f + m_buttonHeight*0.5f + offset, m_buttonWidth, m_buttonHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/randomButton.png"), MENUACTION_RANDOM_NINJA);

	// Next ninja, right button
	m_chooseNinja->AddButton(m_buttonWidth*0.5f + m_nextWidth*0.5f, ninjaCycleHeight, m_nextWidth, m_nextHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTNINJA);

	// Prev ninja, left button
	m_chooseNinja->AddButton(-m_buttonWidth*0.5f - m_nextWidth*0.5f, ninjaCycleHeight, m_nextWidth, m_nextHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVNINJA);

	//Prev tool, left button
	m_chooseNinja->AddButton(-toolButtonXPos, toolCycleHeight, toolButtonSize, toolButtonSize, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVTOOL);

	//Next tool, right button
	m_chooseNinja->AddButton(toolButtonXPos, toolCycleHeight, toolButtonSize, toolButtonSize, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTTOOL);

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, portraitYPos, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));

	m_tools[0] = new MenuItem();
	m_tools[1] = new MenuItem();
	m_tools[2] = new MenuItem();
	m_tools[0]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_Caltrops.png"));
	m_tools[1]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_SmokeBomb.png"));
	m_tools[2]->Initialize(0.0f, toolCycleHeight, m_toolWidth, m_toolHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_StickyTARP.png"));

	m_toolDescription[0] = new ToolTipPopUp();
	m_toolDescription[1] = new ToolTipPopUp();
	m_toolDescription[2] = new ToolTipPopUp();
	m_toolDescription[0]->Initialize(0.0f, toolCycleHeight, SPIKES_DESCRIPTION, m_toolHeight);
	m_toolDescription[1]->Initialize(0.0f, toolCycleHeight, SMOKEBOMB_DESCRIPTION, m_toolHeight);
	m_toolDescription[2]->Initialize(0.0f, toolCycleHeight, STICKY_DESCRIPTION, m_toolHeight);

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
	Level level(LEVEL_NAME);

	m_objectManager = new ObjectManager();
	m_objectManager->SetSound(m_sound);
	m_objectManager->Initialize(&level);

	// Initialize directional light
	m_directionalLight.m_ambient = DirectX::XMVectorSet(0.4f, 0.4f, 0.4f, 1.0f);
	m_directionalLight.m_diffuse = DirectX::XMVectorSet(0.4f, 0.4f, 1.125f, 1.0f);
	m_directionalLight.m_specular = DirectX::XMVectorSet(5.525f, 5.525f, 5.525f, 1.0f);
	DirectX::XMFLOAT4 direction = DirectX::XMFLOAT4(-1.0f, -4.0f, -2.0f, 1.0f);
	DirectX::XMStoreFloat4(&direction, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat4(&direction), DirectX::XMLoadFloat4x4(&m_camera->GetViewMatrix())));
	m_directionalLight.m_direction = DirectX::XMVector3Normalize(DirectX::XMLoadFloat4(&direction));

	m_frustum = new Frustum();
	m_frustum->ConstructFrustum(1000, m_camera->GetProjectionMatrix(), m_camera->GetViewMatrix());
	m_objectManager->UpdateFrustum(m_frustum);

	m_playerManager = new PlayerManager();
	m_playerManager->Initialize(true);
	m_playerManager->UpdateFrustum(m_frustum);

	return true;
}

void ChooseState::Shutdown()
{

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
		m_abilityDescription[currentNinja]->Update();
		m_toolDescription[currentTool]->Update();
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
	case MENUACTION_PLAY:
		if (m_currentTeam == CURRENTTEAM_RED)
		{
			Network::GetInstance()->ChooseChar(currentNinja, currentTool, 1);
		}
		else if (m_currentTeam == CURRENTTEAM_BLUE)
		{
			Network::GetInstance()->ChooseChar(currentNinja, currentTool, 2);
		}
		else
		{
			Network::GetInstance()->ChooseChar(currentNinja, currentTool, 0);
		}
		return GAMESTATESWITCH_PLAY;
		break;
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
		if (m_isRandoming)
		{
			m_isRandoming = false;
		}
		else
		{
			m_isRandoming = true;
		}
		//RandomNinja();
		break;
	case MENUACTION_CLICKED_QUESTIONMARK:
		m_currentTeam = CURRENTTEAM_NONE;
		break;
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
	GraphicsEngine::GetInstance()->BeginRenderToShadowMap();
	m_objectManager->RenderDepth();
	m_playerManager->RenderDepth(true);
	GraphicsEngine::GetInstance()->SetShadowMap();

	GraphicsEngine::GetInstance()->SetSceneDirectionalLight(m_directionalLight);

	// Render to the scene normally.
	GraphicsEngine::GetInstance()->ClearRenderTargetsForGBuffers();
	GraphicsEngine::GetInstance()->SetRenderTargetsForGBuffers();
	m_objectManager->Render();
	m_playerManager->Render(true);

	GraphicsEngine::GetInstance()->RenderFoliage();
	GraphicsEngine::GetInstance()->SetSSAOBuffer(m_camera->GetProjectionMatrix());
	GraphicsEngine::GetInstance()->RenderSSAO();

	// Composition
	GraphicsEngine::GetInstance()->SetScreenBuffer(m_directionalLight, m_camera->GetProjectionMatrix());
	PointLights::GetInstance()->SetLightBuffer(m_camera->GetViewMatrix());

	GraphicsEngine::GetInstance()->Composition();
	GraphicsEngine::GetInstance()->ApplyDOF();

	GraphicsEngine::GetInstance()->TurnOnDepthStencil();

	GraphicsEngine::GetInstance()->ResetRenderTarget();

	m_tintedBackground->Render();
	m_chooseNinja->Render();

	m_ninjas[currentNinja]->Render();
	m_tools[currentTool]->Render();
	m_abilityDescription[currentNinja]->Render();
	m_redTeamScore->Render();
	m_blueTeamScore->Render();
	m_redTeam->Render();
	m_blueTeam->Render();
	m_questionMark->Render();
	m_toolDescription[currentTool]->Render();
	m_title->Render();
}

void ChooseState::NextNinja()
{
	currentNinja += 1;
	if (currentNinja >= nrOfNinjas )
	{
		currentNinja = 0;
	}
}

void ChooseState::PrevNinja()
{
	currentNinja -= 1;
	if (currentNinja < 0)
	{
		currentNinja = nrOfNinjas - 1;
	}
}

void ChooseState::NextTool()
{
	currentTool += 1;
	if (currentTool >= nrOfTools)
	{
		currentTool = 0;
	}
}

void ChooseState::PrevTool()
{
	currentTool -= 1;
	if (currentTool < 0)
	{
		currentTool = nrOfTools - 1;
	}
}

void ChooseState::EscapeIsPressed()
{
		Network::GetInstance()->Disconnect();
	}

void ChooseState::RandomNinja()
{
	std::srand((unsigned int)std::time(0));
	currentTool = std::rand() % 3;
	currentNinja = std::rand() % 3;
}
