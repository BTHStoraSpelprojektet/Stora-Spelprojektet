#ifndef MENU_H_
#define MENU_H_

#include "MenuButton.h"
#include "MenuCheckbox.h"
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
	void Render();
	void AddButton(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, const wchar_t *p_filename);
	void AddCheckbox(float p_x, float p_y, float p_size, MENUACTION p_action, const wchar_t *p_filename);
	void AddPortrait(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, const wchar_t *p_filename);

private:
	
	std::vector<MenuButton> m_buttons;
	std::vector<MenuCheckbox> m_checkboxes;
};

#endif