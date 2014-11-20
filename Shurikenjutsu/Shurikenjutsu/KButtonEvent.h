#ifndef KBUTTONEVENT_H_
#define KBUTTONEVENT_H_

#include "ButtonEvent.h"

class KButtonEvent : public ButtonEvent
{
public:
	KButtonEvent();
	~KButtonEvent();

	bool Initialize(int p_vkey);
	int GetButton() const;

private:
	int m_key;
};

#endif

