#include "ChooseState.h"


ChooseState::ChooseState()
{
}


ChooseState::~ChooseState()
{
}

bool ChooseState::Initialize()
{
	nrOfNinjas = 4;
	currentNinja = 0;

	// Play
	m_chooseButton.AddButton(0, 0, 360.0f, 60.0f, MENUACTION_PLAY, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/play.png");
	//Back
	m_chooseButton.AddButton(0, -70, 360.0f, 60.0f, MENUACTION_BACK, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/back.png");

	// Next ninja, right button
	m_chooseButton.AddButton(150, 70, 60.0f, 60.0f, MENUACTION_NEXTNINJA, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/right.png");

	// Prev ninja, left button
	m_chooseButton.AddButton(-150, 70, 60.0f, 60.0f, MENUACTION_PREVNINJA, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/left.png");

	m_ninjas[0].Initialize(0, 190, 220.0f, 300.0f, MENUACTION_EMPTY, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/ninja1.png");
	m_ninjas[1].Initialize(0, 190, 220.0f, 300.0f, MENUACTION_EMPTY, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/ninja2.png");
	m_ninjas[2].Initialize(0, 190, 220.0f, 300.0f, MENUACTION_EMPTY, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/ninja3.png");
	m_ninjas[3].Initialize(0, 190, 220.0f, 300.0f, MENUACTION_EMPTY, (std::string)"C:/Users/kalle/Documents/GitHub/Stora-Spelprojektet/Shurikenjutsu/Shurikenjutsu/Buttons/ninja4.png");

	return true;
}

GAMESTATESWITCH ChooseState::Update()
{
	MenuActionData action = m_chooseButton.Update();

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
	m_chooseButton.Render();

	m_ninjas[currentNinja].Render();
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