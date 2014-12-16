#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "GUIElement.h"
#include "InputManager.h"

class MenuButton
{
public:
	MenuButton();
	~MenuButton();

	bool Initialize(float p_x, float p_y, float p_width, float p_height);
	void Render();

private:

	bool IsClicked();

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement m_border;
	GUIElement m_background;
};

#endif // MENUBUTTON_H_