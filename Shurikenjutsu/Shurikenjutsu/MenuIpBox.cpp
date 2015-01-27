#include "MenuIpBox.h"
#include "Globals.h"
#include "TextureLibrary.h"
#include "InputManager.h"

MenuIpBox::MenuIpBox(){}
MenuIpBox::~MenuIpBox(){}


bool MenuIpBox::Initialize(float p_x, float p_y, float p_width, float p_height)
{
	MenuItem::Initialize(p_x, p_y, p_width, p_height, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/tb_bg.png"));

	m_counter = 0;
	m_active = false;
	m_ip[0] = '1';
	m_ip[1] = '9';
	m_ip[2] = '4';
	m_ip[3] = '.';
	m_ip[4] = '4';
	m_ip[5] = '7';
	m_ip[6] = '.';
	m_ip[7] = '1';
	m_ip[8] = '5';
	m_ip[9] = '0';
	m_ip[10] = '.';
	m_ip[11] = '1';
	m_ip[12] = '3';
	m_ip[13] = '0';
	m_ip[14] = '\0';

	return true;
}

bool MenuIpBox::IsClicked()
{
	if (MenuButton::IsClicked())
	{
		m_active = true;
		m_counter = 0;
		ResetIp();
		return true;
	}

	else
	{
		m_active = false;
		return false;
	}
}

void MenuIpBox::GetInput()
{
	if (m_active)
	{
		char temp = InputManager::GetInstance()->GetLastCharRead();
		if (temp != '\0')
		{
			m_ip[m_counter] = temp;
			m_counter++;
			if (m_counter > 14)
			{
				m_active = false;
			}
		}
	}
}

void MenuIpBox::ToConsole()
{
	std::cout << "IPBox: ";
	for (unsigned int i = 0; i < 14; i++)
	{
		std::cout << m_ip[i];
	}
	std::cout << std::endl;
}

void MenuIpBox::ResetIp()
{
	for (unsigned int i = 0; i < 14; i++)
	{
		m_ip[i] = '\0';
	}

}

std::string MenuIpBox::GetIp()
{
	return m_ip;
}