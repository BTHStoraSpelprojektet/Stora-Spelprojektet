#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "MenuItem.h"

class MenuButton : public MenuItem
{
public:
	MenuButton();
	~MenuButton();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, MENUACTION p_action);
	bool Initialize(float p_x, float p_y, float p_size, ID3D11ShaderResourceView* p_texture, MENUACTION p_action);

	virtual bool IsClicked();
	MENUACTION GetAction();

protected:
	MENUACTION m_action;
};

#endif // MENUBUTTON_H_