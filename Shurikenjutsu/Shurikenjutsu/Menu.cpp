#include "Menu.h"

Menu::Menu(){}
Menu::~Menu(){}

MenuActionData Menu::Update()
{
	MenuActionData temp;
	temp.m_action = MENUACTION_EMPTY;

	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i].IsClicked())
		{
			temp.m_action = m_buttons[i].GetAction();
			return temp;
		}
	}
	
	for (unsigned int i = 0; i < m_checkboxes.size(); i++)
	{
		if (m_checkboxes[i].IsClicked())
		{
			temp.m_action = m_checkboxes[i].GetAction();
			temp.m_data = m_checkboxes[i].GetState();
			return temp;
		}
	}
	
	return temp;
}

void Menu::Render()
{
	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].Render();
	}

	for (unsigned int i = 0; i < m_checkboxes.size(); i++)
	{
		m_checkboxes[i].Render();
	}
}

void Menu::AddButton(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, std::string p_filename)
{
	MenuButton temp;
	temp.Initialize(p_x, p_y, p_width, p_height, p_action, p_filename);
	m_buttons.push_back(temp);
}

void Menu::AddCheckbox(float p_x, float p_y, float p_size, MENUACTION p_action, std::string p_filename)
{
	MenuCheckbox temp;
	temp.Initialize(p_x, p_y, p_size, p_action, p_filename);
	m_checkboxes.push_back(temp);
}

void Menu::AddPortrait(float p_x, float p_y, float p_width, float p_height, MENUACTION p_action, std::string p_filename)
{
	MenuButton temp;
	temp.Initialize(p_x, p_y, p_width, p_height, p_action, p_filename);
	m_buttons.push_back(temp);
}