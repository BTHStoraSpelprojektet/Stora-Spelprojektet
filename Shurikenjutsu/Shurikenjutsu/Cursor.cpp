#include "Cursor.h"
#include "Window.h"
#include "GUIElement.h"
#include "TextureLibrary.h"
#include "..\CommonLibs\ModelNames.h"
#include "Globals.h"
#include "InputManager.h"

Cursor::Cursor(){}
Cursor::~Cursor(){}

bool Cursor::Initialize()
{
	m_useCustomCursor = true;
	m_renderCursor = true;
	m_largeSize = 100.0f;
	m_smallSize = 50.0f;
	ShowCursor(!m_useCustomCursor && m_renderCursor);

	m_cursor = new GUIElement();
	if (!m_cursor->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f), m_largeSize, m_largeSize, TextureLibrary::GetInstance()->GetTexture(CURSOR_TEXTURE)))
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
		int mouseX = InputManager::GetInstance()->GetMousePositionX();
		int mouseY = InputManager::GetInstance()->GetMousePositionY();

		float halfScreenX = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - GLOBAL::GetInstance().BORDER_SIZE;
		float halfScreenY = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - (GLOBAL::GetInstance().BORDER_SIZE + GLOBAL::GetInstance().TITLE_BORDER_SIZE) * 0.5f;

		m_cursor->SetPosition(DirectX::XMFLOAT3((float)mouseX - halfScreenX, -((float)mouseY - halfScreenY), 1.0f));

	}
}

void Cursor::Render()
{
	if (m_useCustomCursor && m_renderCursor)
	{
		m_cursor->Render();
	}
}

void Cursor::SetCustomCursor(bool p_useCustom)
{
	m_useCustomCursor = p_useCustom;
	ShowCursor(!m_useCustomCursor && m_renderCursor);
}

void Cursor::SetRenderCursor(bool p_render)
{
	m_renderCursor = p_render;
	ShowCursor(!m_useCustomCursor && m_renderCursor);
}

void Cursor::LargeSize()
{
	m_cursor->SetSize(DirectX::XMFLOAT2(m_largeSize, m_largeSize));
}

void Cursor::SmallSize()
{
	m_cursor->SetSize(DirectX::XMFLOAT2(m_smallSize, m_smallSize));
}