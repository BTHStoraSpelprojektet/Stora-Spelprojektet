#include "Cursor.h"
#include "Window.h"
#include "GUIElement.h"
#include "TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"

Cursor::Cursor(){}
Cursor::~Cursor(){}

bool Cursor::Initialize(HWND p_hwnd)
{
	m_useCustomCursor = false;
	m_hwnd = p_hwnd;

	m_cursor = new GUIElement();
	if (!m_cursor->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f), 40.0f, 40.0f, TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE)))
	{
		return false;
	}


	return true;
}

void Cursor::Shutdown()
{
	if (m_cursor != NULL)
	{
		delete m_cursor;
	}
}

void Cursor::Update()
{
	if (m_useCustomCursor)
	{
		POINT mousePos;
		GetCursorPos(&mousePos);
		
		RECT windowRect;		
		GetWindowRect(m_hwnd, &windowRect);

		RECT clientRect;
		GetClientRect(m_hwnd, &clientRect);
		
		float borderSize = (float)((windowRect.right - windowRect.left) - (clientRect.right - clientRect.left)) * 0.5f;
		float titleBorderSize = (float)((windowRect.bottom - windowRect.top) - (clientRect.bottom - clientRect.top)) - 2.0f * borderSize;

		clientRect.left = windowRect.left + borderSize;
		clientRect.top = windowRect.top + borderSize + titleBorderSize;
		clientRect.right += clientRect.left;
		clientRect.bottom += clientRect.top;

		float halfWidth = (float)(clientRect.right - clientRect.left) * 0.5f;
		float halfHeight = (float)(clientRect.bottom - clientRect.top) * 0.5f;

		m_cursor->SetPosition(DirectX::XMFLOAT3((float)(mousePos.x - clientRect.left) - halfWidth, -((float)(mousePos.y - clientRect.top) - halfHeight), 1.0f));

	}
}

void Cursor::Render()
{
	if (m_useCustomCursor)
	{
		m_cursor->QueueRender();
	}
}

void Cursor::SetCustomCursor(bool p_useCustom)
{
	m_useCustomCursor = p_useCustom;
	ShowCursor(!m_useCustomCursor);
}