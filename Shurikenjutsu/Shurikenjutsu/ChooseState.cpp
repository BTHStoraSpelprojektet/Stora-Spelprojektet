#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Network.h"
#include "GUIText.h"
#include "CharacterAbilityDescription.h"
#include "TextureLibrary.h"

// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;

// LEFT / RIGHT
const float NEXTWIDTH = 100.0f;
const float NEXTHEIGHT = 98.0f;

// PORTRAIT
const float PORTRAITWIDTH = 200.0f;
const float PORTRAITHEIGHT = 200.0f;

// TOOL TEXTURE
const float TOOLWIDTH = 50.0f;
const float TOOLHEIGHT = 50.0f;

// OFFSET
const float OFFSET = 10.0f;

ChooseState::ChooseState(){}
ChooseState::~ChooseState(){}

bool ChooseState::Initialize()
{
	nrOfNinjas = 3;
	currentNinja = 0;
	nrOfTools = 3;
	currentTool = 0;
	m_chooseButton = new Menu();

	// Play
	m_chooseButton->AddButton(0.0f, -OFFSET - 150.0f, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_PLAY);
	
	// Back
	m_chooseButton->AddButton(0.0f, -BUTTONHEIGHT - 150.0f - 2.0f*OFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);

	// Next ninja, right button
	m_chooseButton->AddButton(BUTTONWIDTH*0.5f + NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTNINJA);

	// Prev ninja, left button
	m_chooseButton->AddButton(-BUTTONWIDTH*0.5f - NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVNINJA);

	//Prev tool, left button
	m_chooseButton->AddButton(-70.0f, -10.0f, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVTOOL);
	
	//Next tool, right button
	m_chooseButton->AddButton(70.0f, -10.0f, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTTOOL);

	//Test tool texture
	//m_chooseButton->AddButton(0.0f, 0.0f, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_Caltrops.png"), MENUACTION_PREVTOOL);

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	//m_ninjas[3] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));
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
	if (m_chooseButton != nullptr)
	{
		m_chooseButton->Shutdown();
		delete m_chooseButton;
		m_chooseButton = nullptr;
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
	MenuActionData action = m_chooseButton->Update();
	
	switch (action.m_action)
	{
	case MENUACTION_PLAY:
		Network::GetInstance()->ChooseChar(currentNinja, currentTool);
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
	}

	return GAMESTATESWITCH_NONE;
}

void ChooseState::Render()
{
	m_chooseButton->Render();

	m_ninjas[currentNinja]->Render();
	m_tools[currentTool]->Render();
	m_abilityDescription[currentNinja]->Render();
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
}