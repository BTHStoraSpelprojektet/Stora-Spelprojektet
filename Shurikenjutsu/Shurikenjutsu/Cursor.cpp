#include "Cursor.h"
#include "Window.h"
#include "GUIElement.h"
#include "TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"

Cursor::Cursor(){}
Cursor::~Cursor(){}

bool Cursor::Initialize()
{
	m_useCustomCursor = false;

	m_cursor = new GUIElement();
	if (!m_cursor->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f), 10.0f, 10.0f, TextureLibrary::GetInstance()->GetTexture(MINIMAP_RED_DOT_TEXTURE)))
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
		POINT point;
		GetCursorPos(&point);
		m_cursor->SetPosition(DirectX::XMFLOAT3((float)point.x, (float)point.y, 1.0f));
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