#include "KButtonEvent.h"


KButtonEvent::KButtonEvent(){}


KButtonEvent::~KButtonEvent(){}

int KButtonEvent::GetButton() const
{
	return m_key;
}

bool KButtonEvent::Initialize(int p_vkey)
{
	m_key = p_vkey;
	m_state = BUTTON_EVENT_STATE_NONE;

	return true;
}