#include "ChooseState.h"
#include "Menu.h"
#include "MenuItem.h"
#include "TextureLibrary.h"


ChooseState::ChooseState(){}
ChooseState::~ChooseState(){}
bool ChooseState::Initialize()
{
	nrOfNinjas = 4;
	currentNinja = 0;
	m_chooseButton = new Menu();
	// Play
	m_chooseButton->AddButton(0.0f, 0.0f, 360.0f, 60.0f, MENUACTION_PLAY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/play.png"));
	// Back
	m_chooseButton->AddButton(0.0f, -70.0f, 360.0f, 60.0f, MENUACTION_BACK, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/back.png"));

	// Next ninja, right button
	m_chooseButton->AddButton(150.0f, 70.0f, 60.0f, 60.0f, MENUACTION_NEXTNINJA, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/right.png"));

	// Prev ninja, left button
	m_chooseButton->AddButton(-150.0f, 70.0f, 60.0f, 60.0f, MENUACTION_PREVNINJA, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/left.png"));

	m_ninjas[0] = new MenuItem();
	m_ninjas[1] = new MenuItem();
	m_ninjas[2] = new MenuItem();
	m_ninjas[3] = new MenuItem();
	m_ninjas[0]->Initialize(0.0f, 190.0f, 220.0f, 300.0f, MENUACTION_EMPTY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	m_ninjas[1]->Initialize(0.0f, 190.0f, 220.0f, 300.0f, MENUACTION_EMPTY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	m_ninjas[2]->Initialize(0.0f, 190.0f, 220.0f, 300.0f, MENUACTION_EMPTY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));
	m_ninjas[3]->Initialize(0.0f, 190.0f, 220.0f, 300.0f, MENUACTION_EMPTY, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja4.png"));

	return true;
}

GAMESTATESWITCH ChooseState::Update()
{
	MenuActionData action = m_chooseButton->Update();

	switch (action.m_action)
	{
	case MENUACTION_PLAY:
		return GAMESTATESWITCH_PLAY;
		break;
	case MENUACTION_BACK:
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