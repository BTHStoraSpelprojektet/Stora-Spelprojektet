#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "TextureLibrary.h"
#include "Network.h"

// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;

// LEFT / RIGHT
const float NEXTWIDTH = 100.0f;
const float NEXTHEIGHT = 98.0f;

// PORTRAIT
const float PORTRAITWIDTH = 242.0f;
const float PORTRAITHEIGHT = 300.0f;

// OFFSET
const float OFFSET = 10.0f;

ChooseState::ChooseState(){}
ChooseState::~ChooseState(){}

bool ChooseState::Initialize()
{
	nrOfNinjas = 3;
	currentNinja = 0;
	m_chooseButton = new Menu();

	// Play
	m_chooseButton->AddButton(0.0f, -OFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"), MENUACTION_PLAY);
	
	// Back
	m_chooseButton->AddButton(0.0f, -BUTTONHEIGHT - 2.0f*OFFSET, BUTTONWIDTH, BUTTONHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"), MENUACTION_BACK);

	// Next ninja, right button
	m_chooseButton->AddButton(BUTTONWIDTH*0.5f + NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"), MENUACTION_NEXTNINJA);

	// Prev ninja, left button
	m_chooseButton->AddButton(-BUTTONWIDTH*0.5f - NEXTWIDTH*0.5f, BUTTONHEIGHT + OFFSET, NEXTWIDTH, NEXTHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"), MENUACTION_PREVNINJA);

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	//m_ninjas[3] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));
	//m_ninjas[3]->Initialize(0.0f, PORTRAITHEIGHT*0.5f + BUTTONHEIGHT*0.5f + OFFSET, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja4.png"));

	return true;
}

GAMESTATESWITCH ChooseState::Update()
{
	MenuActionData action = m_chooseButton->Update();
	
	switch (action.m_action)
	{
	case MENUACTION_PLAY:
		Network::GetInstance()->ChooseChar(currentNinja);
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
	}

	return GAMESTATESWITCH_NONE;
}

void ChooseState::Render()
{
	m_chooseButton->Render();

	m_ninjas[currentNinja]->Render();
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