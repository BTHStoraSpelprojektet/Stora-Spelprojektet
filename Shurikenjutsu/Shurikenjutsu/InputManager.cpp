#include "InputManager.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include "Windowsx.h"
#include "Windows.h"
#include "KButtonEvent.h"
#include "ButtonEvent.h"

InputManager* InputManager::m_instance;

InputManager::InputManager(){}

InputManager::~InputManager(){}

InputManager* InputManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new InputManager();
	}

	return m_instance;
}

void InputManager::Initialize()
{

	m_leftMouseB = new ButtonEvent;
	m_rightMouseB = new ButtonEvent;
}
void InputManager::Shutdown()
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		delete m_events[i];
	}
	m_events.clear();


	delete m_leftMouseB;
	m_leftMouseB = nullptr;
	delete m_rightMouseB;
	m_rightMouseB = nullptr;
	delete m_instance;
	m_instance = nullptr;
}

void InputManager::UpdateInput(UINT p_message, WPARAM p_wParam, LPARAM p_lParam)
{
	
	// Updates the input for all the keys
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		switch (p_message)
		{
			case WM_KEYDOWN:
			{
				if (m_events[i]->GetButton() == p_wParam)
				{
					m_events[i]->SetState(BUTTON_EVENT_STATE_PRESSED);
				}
				break;
			}

			case WM_KEYUP:
			{
				if (m_events[i]->GetButton() == p_wParam)
				{
					m_events[i]->SetState(BUTTON_EVENT_STATE_CLICKED);
				}
				break;
			}
		}
	}
	switch (p_message)
	{
		// Update mouse
		case WM_MOUSEMOVE:
		{
			m_mousePositionX_prev = m_mousePositionX;
			m_mousePositionY_prev = m_mousePositionY;
			m_mousePositionX = GET_X_LPARAM(p_lParam);
			m_mousePositionY = GET_Y_LPARAM(p_lParam);
			break;
		}

		case WM_LBUTTONDOWN:
		{
			m_leftMouseB->SetState(BUTTON_EVENT_STATE_PRESSED);
			break;
		}

		case WM_LBUTTONUP:
		{
			m_leftMouseB->SetState(BUTTON_EVENT_STATE_CLICKED);
			break;
		}

		case WM_RBUTTONDOWN:
		{
			m_rightMouseB->SetState(BUTTON_EVENT_STATE_PRESSED);
			break;
		}

		case WM_RBUTTONUP:
		{
			m_rightMouseB->SetState(BUTTON_EVENT_STATE_CLICKED);
			break;
		}

		case WM_CHAR:
		{
			m_lastCharRead = (TCHAR)p_wParam;
			break;
		}
	}
}

void InputManager::ClearInput()
{
	if (m_leftMouseB->IsClicked())
	{
		m_leftMouseB->SetState(BUTTON_EVENT_STATE_NONE);
	}

	if (m_rightMouseB->IsClicked())
	{
		m_rightMouseB->SetState(BUTTON_EVENT_STATE_NONE);
	}

	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i]->IsClicked())
		{
			m_events[i]->SetState(BUTTON_EVENT_STATE_NONE);
		}
	}
	m_lastCharRead = '\0';

}

bool InputManager::IsKeyClicked(int p_vkey) const
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i]->GetButton() == p_vkey)
		{
			return m_events[i]->IsClicked();
		}
	}

	return false;
}

bool InputManager::IsKeyPressed(int p_vkey) const
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i]->GetButton() == p_vkey)
		{
			return m_events[i]->IsPressed();
		}
	}

	return false;
}

void InputManager::RegisterKey(int p_vkey)
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i]->GetButton() == p_vkey)
		{
			return;
		}
	}

	KButtonEvent *key = new KButtonEvent();
	key->Initialize(p_vkey);

	m_events.push_back(key);
}

int InputManager::GetMousePositionX() const
{
	return m_mousePositionX;
}

int InputManager::GetMousePositionY() const
{
	return m_mousePositionY;
}

int InputManager::GetMousePositionX_prev() const
{
	return m_mousePositionX_prev;
}

int InputManager::GetMousePositionY_prev() const
{
	return m_mousePositionY_prev;
}

bool InputManager::IsLeftMousePressed() const
{
	return m_leftMouseB->IsPressed();
}

bool InputManager::IsLeftMouseClicked() const
{
	return m_leftMouseB->IsClicked();
}

bool InputManager::IsRightMousePressed() const
{
	return m_rightMouseB->IsPressed();
}

bool InputManager::IsRightMouseClicked() const
{
	return m_rightMouseB->IsClicked();
}

char InputManager::GetLastCharRead() const
{
	return m_lastCharRead;
}

void InputManager::Set3DMousePosition(float p_x, float p_z)
{
	m_3DMouseX = p_x;
	m_3DMouseZ = p_z;
}

float InputManager::Get3DMousePositionX()
{
	return m_3DMouseX;
}
float InputManager::Get3DMousePositionZ()
{
	return m_3DMouseZ;
}