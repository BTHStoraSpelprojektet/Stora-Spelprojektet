#include "ChooseState.h"


ChooseState::ChooseState()
{
}


ChooseState::~ChooseState()
{
}

bool ChooseState::Initialize()
{
	nrOfNinjas = 1;
	currentNinja = 0;

	m_chooseButton.AddButton(0, 0, 360.0f, 60.0f, MENUACTION_PLAY);
	m_chooseButton.AddButton(150, 70, 60.0f, 60.0f, MENUACTION_NEXTNINJA);	
	m_chooseButton.AddButton(-150, 70, 60.0f, 60.0f, MENUACTION_PREVNINJA);

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

	switch (currentNinja)
	{
	case 0:
		// Render first ninja
		break;
	default:
		break;
	}
}

void ChooseState::NextNinja()
{
	if (currentNinja < nrOfNinjas - 1)
	{
		currentNinja += 1;
	}
}

void ChooseState::PrevNinja()
{
	if (currentNinja > 0)
	{
		currentNinja -= 1;
	}
}