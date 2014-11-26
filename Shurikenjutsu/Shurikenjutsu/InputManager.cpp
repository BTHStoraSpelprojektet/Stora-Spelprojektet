#include "InputManager.h"

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

void InputManager::Shutdown()
{
	m_events.clear();
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
				if (m_events[i].GetButton() == p_wParam)
				{
					m_events[i].SetState(BUTTON_EVENT_STATE_PRESSED);
				}
				break;
			}

			case WM_KEYUP:
			{
				if (m_events[i].GetButton() == p_wParam)
				{
					m_events[i].SetState(BUTTON_EVENT_STATE_CLICKED);
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
			m_mousePositionX = GET_X_LPARAM(p_lParam);
			m_mousePositionY = GET_Y_LPARAM(p_lParam);
			break;
		}

		case WM_LBUTTONDOWN:
		{
			m_leftMouseB.SetState(BUTTON_EVENT_STATE_PRESSED);
			break;
		}

		case WM_LBUTTONUP:
		{
			m_leftMouseB.SetState(BUTTON_EVENT_STATE_CLICKED);
			break;
		}

		case WM_RBUTTONDOWN:
		{
			m_rightMouseB.SetState(BUTTON_EVENT_STATE_PRESSED);
			break;
		}

		case WM_RBUTTONUP:
		{
			m_rightMouseB.SetState(BUTTON_EVENT_STATE_CLICKED);
			break;
		}
	}
}

void InputManager::ClearInput()
{
	if (m_leftMouseB.IsClicked())
	{
		m_leftMouseB.SetState(BUTTON_EVENT_STATE_NONE);
	}

	if (m_rightMouseB.IsClicked())
	{
		m_rightMouseB.SetState(BUTTON_EVENT_STATE_NONE);
	}

	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i].IsClicked())
		{
			m_events[i].SetState(BUTTON_EVENT_STATE_NONE);
		}
	}
}

bool InputManager::IsKeyClicked(int p_vkey) const
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i].GetButton() == p_vkey)
		{
			return m_events[i].IsClicked();
		}
	}

	return false;
}

bool InputManager::IsKeyPressed(int p_vkey) const
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i].GetButton() == p_vkey)
		{
			return m_events[i].IsPressed();
		}
	}

	return false;
}

void InputManager::RegisterKey(int p_vkey)
{
	for (unsigned int i = 0; i < m_events.size(); i++)
	{
		if (m_events[i].GetButton() == p_vkey)
		{
			return;
		}
	}

	KButtonEvent key;
	key.Initialize(p_vkey);

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

bool InputManager::IsLeftMousePressed() const
{
	return m_leftMouseB.IsPressed();
}

bool InputManager::IsLeftMouseClicked() const
{
	return m_leftMouseB.IsClicked();
}

bool InputManager::IsRightMousePressed() const
{
	return m_rightMouseB.IsPressed();
}

bool InputManager::IsRightMouseClicked() const
{
	return m_rightMouseB.IsClicked();
}
