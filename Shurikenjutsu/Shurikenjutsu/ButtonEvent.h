#ifndef BUTTONEVENT_H_
#define BUTTONEVENT_H_

enum ButtonEventState
{
	BUTTON_EVENT_STATE_PRESSED,
	BUTTON_EVENT_STATE_CLICKED,
	BUTTON_EVENT_STATE_NONE
};

class ButtonEvent
{
public:
	ButtonEvent();
	~ButtonEvent();

	bool IsPressed() const;
	bool IsClicked() const;

	void SetState(ButtonEventState p_state);
	

protected:
	ButtonEventState m_state;
};
#endif