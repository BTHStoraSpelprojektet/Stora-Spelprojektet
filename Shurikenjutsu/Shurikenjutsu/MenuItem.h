#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "GUIElement.h"
#include "InputManager.h"

enum MENUACTION
{
	MENUACTION_BACK,
	MENUACTION_PLAY,
	MENUACTION_CHOOSENINJA,
	MENUACTION_NEXTNINJA,
	MENUACTION_PREVNINJA,
	MENUACTION_OPTIONS,
	MENUACTION_VSYNC,
	MENUACTION_FULLSCREEN,

	MENUACTION_EMPTY,
};

class MenuItem
{
public:
	MenuItem();
	~MenuItem();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, std::string p_filename);
	bool Initialize(float p_x, float p_y, float p_size, MENUACTION p_action, std::string p_filename);
	void Render();
	virtual bool IsClicked();
	MENUACTION GetAction();
	void SetBackgroundTexture(std::string p_filename);

protected:

	float m_x;
	float m_y;
	float m_width;
	float m_height;

	GUIElement m_background;

	MENUACTION m_action;
};

#endif // !MENUITEM_H_