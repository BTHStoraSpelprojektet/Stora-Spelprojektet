#ifndef MENUCHECKBOX_H_
#define MENUCHECKBOX_H_

#include "MenuItem.h"

class MenuCheckbox : public MenuItem
{
public:
	MenuCheckbox();
	~MenuCheckbox();

	bool Initialize(float p_x, float p_y, MENUACTION p_action, bool p_state);
	bool IsClicked();
	bool GetState()const;
	void SetState(bool p_state);

private:
	bool m_state;
};

#endif