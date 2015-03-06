#include "MenuTextBox.h"
#include "Globals.h"
#include "TextureLibrary.h"
#include "InputManager.h"
#include "..\CommonLibs\ModelNames.h"
#include "ConsoleFunctions.h"
#include "GUIText.h"

MenuTextBox::MenuTextBox(){}
MenuTextBox::~MenuTextBox(){}


bool MenuTextBox::Initialize(float p_x, float p_y, float p_width, float p_height, int p_maxChars, std::string p_text)
{
	MenuItem::Initialize(p_x, p_y, p_width, p_height, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/ipbox.png"));

	m_maxChars = p_maxChars;

	if ((unsigned int)m_maxChars < p_text.size())
	{
		m_counter = m_maxChars;
	}
	else
	{
		m_counter = p_text.size();
	}

	m_active = false;

	m_text = new char[m_maxChars];

	for (int i = 0; i < m_maxChars; i++)
	{
		if ((unsigned int)i == p_text.size())
		{
			m_text[i] = '\0';
			break;
		}

		m_text[i] = p_text[i];
	}

	m_guiText = new GUIText;
	m_guiText->Initialize(GetText(), 36.0f, p_x, p_y, 0xff333333);

	return true;
}

bool MenuTextBox::Initialize(ID3D11ShaderResourceView* p_texture, float p_x, float p_y, float p_width, float p_height, int p_maxChars, std::string p_text)
{
	MenuItem::Initialize(p_x, p_y, p_width, p_height, p_texture);

	m_maxChars = p_maxChars;

	if ((unsigned int)m_maxChars < p_text.size())
	{
		m_counter = m_maxChars;
	}
	else
	{
		m_counter = p_text.size();
	}

	m_active = false;

	m_text = new char[m_maxChars];

	for (int i = 0; i < m_maxChars; i++)
	{
		if ((unsigned int)i == p_text.size())
		{
			m_text[i] = '\0';
			break;
		}

		m_text[i] = p_text[i];
	}

	m_guiText = new GUIText;
	m_guiText->Initialize(GetText(), 36.0f, p_x - 90.0f, p_y, 0xff333333);
	m_guiText->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
	m_guiText->SetText(GetText());

	return true;
}

void MenuTextBox::Shutdown()
{
	MenuButton::Shutdown();

	delete[] m_text;
	m_text = 0;

	if (m_guiText != nullptr)
	{
		m_guiText->Shutdown();
		delete m_guiText;
		m_guiText = nullptr;
	}
}

void MenuTextBox::Render()
{
	MenuButton::Render();
	m_guiText->Render();
}

bool MenuTextBox::Update()
{
	bool temp = IsClicked();

	GetInput();

	return temp;
}

bool MenuTextBox::IsClicked()
{
	InputManager* input = InputManager::GetInstance();

	if (input->IsLeftMouseClicked())
	{
		if (MenuButton::IsClicked())
		{
			m_active = true;
			return true;
		}
		else
		{
			
			m_active = false;
		}
	}

	return false;
}

void MenuTextBox::GetInput()
{
	if (m_active)
	{
		char temp = InputManager::GetInstance()->GetLastCharRead();

		// Is not nothing?
		if (temp != '\0')
		{
			//'Enter' / 'Return'
			if (temp == '\r')
			{
				m_active = false;
			}
			else if (temp == '\b')
			{
				if (m_counter > 0)
				{
					m_text[--m_counter] = '\0';
					m_guiText->SetText(GetText());
				}
			}

			else
			{
				if (m_counter < m_maxChars)
				{
					m_text[m_counter++] = temp;
					m_guiText->SetText(GetText());
				}
			}
		}
	}
}

void MenuTextBox::ToConsole()
{
	std::cout << "Textbox: ";
	for (int i = 0; i < m_maxChars - 1; i++)
	{
		std::cout << m_text[i];
	}
	std::cout << std::endl;
}

std::string MenuTextBox::GetText()
{
	std::string temp(m_text, m_text + m_counter);
	return temp;
}