#include "ButtonEvent.h"


ButtonEvent::ButtonEvent()
{
	m_state = BUTTON_EVENT_STATE_NONE;
}


ButtonEvent::~ButtonEvent(){}



bool ButtonEvent::IsPressed() const
{
	if (m_state == BUTTON_EVENT_STATE_PRESSED)
	{
		return true;
	}

	return false;
}

bool ButtonEvent::IsClicked() const
{
	if (m_state == BUTTON_EVENT_STATE_CLICKED)
	{
		return true;
	}

	return false;
}

void ButtonEvent::SetState(ButtonEventState p_state)
{
	m_state = p_state;
}



