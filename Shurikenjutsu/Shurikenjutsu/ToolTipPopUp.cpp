#include "ToolTipPopUp.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "InputManager.h"
#include "GUIText.h"
#include "Globals.h"
#include "MenuItem.h"


ToolTipPopUp::ToolTipPopUp(){}
ToolTipPopUp::~ToolTipPopUp(){}
void ToolTipPopUp::Initialize(float p_xPos, float p_yPos, std::string p_text , float p_size, float p_backGroundWidth, float p_backGroundHeight ,float p_bgOffset)
{
	m_text = new GUIText();
	m_text->Initialize(p_text, 25.0f, p_xPos, p_yPos + p_size, 0xff000000);
	m_visible = false;
	

	m_xMin = p_xPos - (p_size * 0.5f);
	m_xMax = p_xPos + (p_size * 0.5f);
	m_yMin = p_yPos - (p_size * 0.5f);
	m_yMax = p_yPos + (p_size * 0.5f);

	m_halfScreenX = GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - GLOBAL::GetInstance().BORDER_SIZE;
	m_halfScreenY = GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.5f - (GLOBAL::GetInstance().BORDER_SIZE + GLOBAL::GetInstance().TITLE_BORDER_SIZE) * 0.5f;

	m_toolTipBG = new MenuItem();
	m_toolTipBG->Initialize(p_xPos, p_yPos + 75.0f + p_bgOffset, p_backGroundWidth, p_backGroundHeight, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/textBox.png"));
	

}
void ToolTipPopUp::Render()
{
	if (m_visible)
	{
		m_toolTipBG->Render();
		m_text->Render();
	}
}
void ToolTipPopUp::Update()
{
	InputManager *tIM = InputManager::GetInstance();
	float mouseX = tIM->GetMousePositionX() - m_halfScreenX;
	float mouseY = (tIM->GetMousePositionY() - m_halfScreenY)*-1;

	if (mouseX > m_xMin && mouseX < m_xMax)
	{
		if ( mouseY >= m_yMin && mouseY <= m_yMax)
		{
			m_visible = true;
		}
		else
		{
			m_visible = false;
		}
	}
	else
	{
		m_visible = false;
	}
}
void ToolTipPopUp::Shutdown()
{
	if (m_toolTipBG != nullptr)
	{
		m_toolTipBG->Shutdown();
		delete m_toolTipBG;
		m_toolTipBG = nullptr;
	}
	if (m_text != nullptr)
	{
		m_text->Shutdown();
		delete m_text;
		m_text = nullptr;
	}
}