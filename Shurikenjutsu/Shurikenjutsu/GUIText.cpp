#include "GUIText.h"


GUIText::GUIText()
{
}


GUIText::~GUIText()
{
}

bool GUIText::Initialize(std::string p_text, float p_size, float p_x, float p_y, UINT32 p_color)
{
	

	SetText(p_text);
	m_size = p_size;
	m_posx = p_x;
	m_posy = p_y;
	m_color = p_color;
	return true;
}

void GUIText::Render()
{
	GUIManager::GetInstance()->AddToRenderQueue(this);
}

void GUIText::SetText(std::string p_text)
{
	m_text = p_text;
}

void GUIText::SetPosition(float p_x, float p_y)
{
	m_posx = p_x;
	m_posy = p_y;
}

void GUIText::SetSize(float p_size)
{
	m_size = p_size;
}

void GUIText::SetColor(UINT32 p_color)
{
	m_color = p_color;
}

std::string GUIText::GetText()
{
	return m_text;
}

float GUIText::GetPositionX()
{
	return m_posx;
}

float GUIText::GetPositionY()
{
	return m_posy;
}

float GUIText::GetSize()
{
	return m_size;
}

UINT32 GUIText::GetColor()
{
	return m_color;
}
