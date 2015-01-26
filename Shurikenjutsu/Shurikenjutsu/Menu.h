#ifndef MENU_H_
#define MENU_H_

#include "MenuButton.h"
#include "MenuCheckbox.h"
#include "MenuIpBox.h"
#include <vector>

struct MenuActionData
{
	MENUACTION m_action;
	bool m_data;
};

class Menu
{
public:
	Menu();
	~Menu();

	MenuActionData Update();
	void Shutdown();
	void Render();
	void AddButton(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, ID3D11ShaderResourceView* p_texture);
	void AddCheckbox(float p_x, float p_y, MENUACTION p_action, bool p_state);
	void AddPortrait(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, ID3D11ShaderResourceView* p_texture);

private:
	
	std::vector<MenuButton*> m_buttons;
	std::vector<MenuCheckbox*> m_checkboxes;
};

#endif