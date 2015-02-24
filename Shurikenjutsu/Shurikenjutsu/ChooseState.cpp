#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "GUIText.h"
#include "CharacterAbilityDescription.h"
#include "TextureLibrary.h"
#include "Globals.h"
#include <ctime>
#include "Network.h"

// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;

// LEFT / RIGHT
const float NEXTWIDTH = 100.0f;
const float NEXTHEIGHT = 98.0f;

// TOOL TEXTURE
const float TOOLWIDTH = 50.0f;
const float TOOLHEIGHT = 50.0f;

// OFFSET
const float OFFSET = 10.0f;

ChooseState::ChooseState(){}
ChooseState::~ChooseState(){}



/*TODO
 - Random knapp i mitten
 - Visualisera vilket lag man är med i
 - Backgrund
 - Popup text
 - 



*/
bool ChooseState::Initialize()
{
	m_screenHeight = (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
	m_screenWidth = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH;
	m_portraitHeight = m_screenHeight / 5.12f;
	m_portraitWidth = m_screenWidth / 6.4f;

	m_redTeamScore = new GUIText();
	m_blueTeamScore = new GUIText();

	m_redTeamScore->Initialize("0", 50.0f, -m_screenWidth * 0.1f, m_screenHeight * 0.33f, 0xff0000ff);
	m_blueTeamScore->Initialize("0", 50.0f, m_screenWidth * 0.1f, m_screenHeight * 0.33f, 0xffff0000);

	m_blueTeam = new TeamTable();
	m_redTeam = new TeamTable();
	m_redTeam->Initialize(-m_screenWidth * 0.5f, m_screenHeight * 0.33f);
	m_blueTeam->Initialize(m_screenWidth * 0.5f, m_screenHeight * 0.33f);
	
	m_myTeam = 0;

	nrOfNinjas = 3;
	currentNinja = 0;
	nrOfTools = 3;
	currentTool = 0;
	m_chooseNinja = new Menu();

	m_chooseNinja->AddButton(-m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/redteam.png"), MENUACTION_PICK_RED_TEAM);

	m_chooseNinja->AddButton(m_screenWidth / 3.0f, m_screenHeight * 0.1f, m_screenWidth / 4.0f, m_screenHeight / 1.7f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/blueteam.png"), MENUACTION_PICK_BLUE_TEAM);

	m_chooseNinja->AddButton(-m_screenWidth * 0.5f + BUTTONWIDTH * 0.5f, -m_screenHeight * 0.5f + BUTTONHEIGHT*0.5f, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);

	m_chooseNinja->AddButton(m_screenWidth * 0.5f - BUTTONWIDTH * 0.5f, -m_screenHeight * 0.5f + BUTTONHEIGHT*0.5f, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_RANDOM_TEAM);

	// Next ninja, right button
	m_chooseNinja->AddButton(BUTTONWIDTH*0.5f + NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTNINJA);

	// Prev ninja, left button
	m_chooseNinja->AddButton(-BUTTONWIDTH*0.5f - NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVNINJA);

	//Prev tool, left button
	m_chooseNinja->AddButton(-70.0f, -10.0f, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVTOOL);

	//Next tool, right button
	m_chooseNinja->AddButton(70.0f, -10.0f, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTTOOL);

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	//m_ninjas[3] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, m_portraitHeight*0.5f + BUTTONHEIGHT*0.5f + OFFSET, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, m_portraitHeight*0.5f + BUTTONHEIGHT*0.5f + OFFSET, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, m_portraitHeight*0.5f + BUTTONHEIGHT*0.5f + OFFSET, m_portraitWidth, m_portraitHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));
	//m_ninjas[3]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja4.png"));

	m_tools[0] = new MenuItem();
	m_tools[1] = new MenuItem();
	m_tools[2] = new MenuItem();
	m_tools[0]->Initialize(0.0f, TOOLHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET - 95.0f, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_Caltrops.png"));
	m_tools[1]->Initialize(0.0f, TOOLHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET - 95.0f, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_SmokeBomb.png"));
	m_tools[2]->Initialize(0.0f, TOOLHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET - 95.0f, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_StickyTARP.png"));

	m_abilityDescription[0] = new CharacterAbilityDescription();
	m_abilityDescription[1] = new CharacterAbilityDescription();
	m_abilityDescription[2] = new CharacterAbilityDescription();
	m_abilityDescription[0]->Initialize(1);
	m_abilityDescription[1]->Initialize(2);
	m_abilityDescription[2]->Initialize(3);
	return true;
}

void ChooseState::Shutdown()
{
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
}

GAMESTATESWITCH ChooseState::Update()
{
	//NextNinja();
	//NextTool();
	UpdateTeams();

	m_redTeamScore->SetText(std::to_string(Network::GetInstance()->GetRedTeamScore()));
	m_blueTeamScore->SetText(std::to_string(Network::GetInstance()->GetBlueTeamScore()));
	MenuActionData action = m_chooseNinja->Update();
	
	switch (action.m_action)
	{
	case MENUACTION_PLAY:
		Network::GetInstance()->ChooseChar(currentNinja, currentTool, m_myTeam);
		return GAMESTATESWITCH_PLAY;
		break;
	case MENUACTION_BACK:
		Network::GetInstance()->Disconnect();
		return GAMESTATESWITCH_MENU;
		break;
	case MENUACTION_NEXTNINJA:
		NextNinja();
		break;
	case MENUACTION_PREVNINJA:
		PrevNinja();
		break;
	case MENUACTION_NEXTTOOL:
		NextTool();
		break;
	case MENUACTION_PREVTOOL:
		PrevTool();
		break;
	case MENUACTION_PICK_BLUE_TEAM://////////////////////////////////
		if (m_blueTeam->GetNumberOfPlayers() >= 4)
		{
			m_myTeam = 1;
		}
		else
		{
			m_myTeam = 2;
		}
		break;
	case MENUACTION_PICK_RED_TEAM:///////////////////////////////////
		if (m_redTeam->GetNumberOfPlayers() >= 4)
		{
			m_myTeam = 2;
		}
		else
		{
			m_myTeam = 1;
		}
		break;
	case MENUACTION_RANDOM_TEAM://////////////////////////////////
		m_myTeam = 0;
		break;
	case MENUACTION_RANDOM_NINJA:///////////////////////////////////

		RandomNinja();
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
			m_redTeam->AddTeamMate(tempPlayerList[i].charNr, tempPlayerList[i].toolNr, 1);
		}
		else
		{
			m_blueTeam->AddTeamMate(tempPlayerList[i].charNr, tempPlayerList[i].toolNr, 2);
		}
	}
}

void ChooseState::Render()
{
	m_chooseNinja->Render();

	m_ninjas[currentNinja]->Render();
	m_tools[currentTool]->Render();
	m_abilityDescription[currentNinja]->Render();
	m_redTeamScore->Render();
	m_blueTeamScore->Render();
	m_redTeam->Render();
	m_blueTeam->Render();
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
	currentTool = std::rand() % 4 + 1;
	currentNinja = std::rand() % 4 + 1;
}
