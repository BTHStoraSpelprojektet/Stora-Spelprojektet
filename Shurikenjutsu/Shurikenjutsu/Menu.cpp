#include "Menu.h"

Menu::Menu(){}
Menu::~Menu(){}

MenuActionData Menu::Update()
{
	MenuActionData temp;
	temp.m_action = MENUACTION_EMPTY;

	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i]->IsClicked())
		{
			temp.m_action = m_buttons[i]->GetAction();
			return temp;
		}
	}
	
	for (unsigned int i = 0; i < m_checkboxes.size(); i++)
	{
		if (m_checkboxes[i]->IsClicked())
		{
			temp.m_action = m_checkboxes[i]->GetAction();
			temp.m_data = m_checkboxes[i]->GetState();
			return temp;
		}
	}
	
	return temp;
}

void Menu::Shutdown()
{
	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->Shutdown();
		delete m_buttons[i];
	}
	m_buttons.clear();

	for (unsigned int i = 0; i < m_checkboxes.size(); i++)
	{
		m_checkboxes[i]->Shutdown();
		delete m_checkboxes[i];
	}
	m_checkboxes.clear();

	for (unsigned int i = 0; i < m_items.size(); i++)
	{
		m_items[i]->Shutdown();
		delete m_items[i];
	}
	m_items.clear();
}
void Menu::Render()
{
	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->Render();
	}

	for (unsigned int i = 0; i < m_checkboxes.size(); i++)
	{
		m_checkboxes[i]->Render();
	}

	for (unsigned int i = 0; i < m_items.size(); i++)
	{
		m_items[i]->Render();
	}
}

void Menu::AddButton(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture, MENUACTION p_action)
{
	MenuButton *temp;
	temp = new MenuButton();
	temp->Initialize(p_x, p_y, p_width, p_height, p_texture, p_action);
	m_buttons.push_back(temp);
}

int Menu::AddCheckbox(float p_x, float p_y, MENUACTION p_action, bool p_state)
{
	MenuCheckbox *temp;
	temp = new MenuCheckbox();
	temp->Initialize(p_x, p_y, p_action, p_state);
	m_checkboxes.push_back(temp);
	return m_checkboxes.size() - 1;
}

void Menu::AddTexture(float p_x, float p_y, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	MenuItem *temp;
	temp = new MenuItem();
	temp->Initialize(p_x, p_y, p_width, p_height, p_texture);
	m_items.push_back(temp);
}

bool Menu::GetCheckboxState(int p_index)
{
	return m_checkboxes[p_index]->GetState();
}

void Menu::SetCheckboxState(int p_index, bool p_state)
{
	m_checkboxes[p_index]->SetState(p_state);
}
