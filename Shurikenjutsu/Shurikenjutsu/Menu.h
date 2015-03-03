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

	virtual MenuActionData Update();
	virtual void Shutdown();
    virtual	void Render();
	void AddButton(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, MENUACTION p_action);
	int AddCheckbox(float p_x, float p_y, MENUACTION p_action, bool p_state);
	void AddTexture(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);
	bool GetCheckboxState(int p_index);
	void SetCheckboxState(int p_index, bool p_state);

private:
	
	std::vector<MenuButton*> m_buttons;
	std::vector<MenuCheckbox*> m_checkboxes;
	std::vector<MenuItem*> m_items;
};

#endif