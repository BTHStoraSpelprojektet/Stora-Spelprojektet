#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "GUIElement.h"
#include "InputManager.h"

enum MENUACTION
{
	MENUACTION_BACK,
	MENUACTION_PLAY,
	MENUACTION_OPTIONS,
	MENUACTION_VSYNC,
	MENUACTION_FULLSCREEN,
	MENUACTION_IP,
	MENUACTION_CONNECT,
	MENUACTION_EMPTY,
};

class MenuItem
{
public:
	MenuItem();
	~MenuItem();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action);
	bool Initialize(float p_x, float p_y, float p_size, MENUACTION p_action);
	void Render();
	virtual bool IsClicked();
	MENUACTION GetAction();

protected:

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement m_border;
	GUIElement m_background;

	MENUACTION m_action;
};

#endif // !MENUITEM_H_