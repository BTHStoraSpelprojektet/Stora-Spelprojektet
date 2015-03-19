#include "TeamTable.h"
#include "MenuItem.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "Globals.h"
#include "GUIText.h"


TeamTable::TeamTable(){}
TeamTable::~TeamTable(){}
// PORTRAIT
const float PORTRAITWIDTH = 75.0f;
const float PORTRAITHEIGHT = 75.0f;

// TOOL TEXTURE
const float TOOLWIDTH = 50.0f;
const float TOOLHEIGHT = 50.0f;
// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
// Checkbox
const float CHECKBOXSIZE = 50.0f;
// OFFSET
const float OFFSET = 10.0f;

void TeamTable::Initialize(float p_startXPos, float p_startYPos, int p_team)
{
	m_startXPos = p_startXPos;
	m_startYPos = p_startYPos;
	m_initialStartXPos = p_startXPos;
	m_initialStartYPos = p_startYPos;
	m_portraitOffset = PORTRAITWIDTH * 2.0f;
	if (p_team == 2)
	{
		m_portraitOffset *= -1;
	}
	m_toolOffset = PORTRAITWIDTH;
	if (p_team == 2)
	{
		m_toolOffset *= -1;
	}

	m_nameAlignment = DWRITE_TEXT_ALIGNMENT_LEADING;
	if (p_team == 2)
	{
		m_nameAlignment = DWRITE_TEXT_ALIGNMENT_TRAILING;
	}
}
void TeamTable::Shutdown()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Shutdown();
		m_teamList[i].m_tool->Shutdown();
		m_teamList[i].m_name->Shutdown();
		m_teamList[i].m_ready->Shutdown();
		delete m_teamList[i].m_ninja;
		delete m_teamList[i].m_tool;
		delete m_teamList[i].m_name;
		delete m_teamList[i].m_ready;
		m_teamList[i].m_ninja = nullptr;
		m_teamList[i].m_tool = nullptr;
		m_teamList[i].m_name = nullptr;
		m_teamList[i].m_ready = nullptr;
	}
	m_teamList.clear();
}
void TeamTable::Render()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Render();
		m_teamList[i].m_tool->Render();
		m_teamList[i].m_name->Render();
		m_teamList[i].m_ready->Render();
	}
}
void TeamTable::AddTeamMate(int p_ninja, int p_tool, std::string p_name, bool p_isReady)
{
	CharacterToolWrapper temp;
	temp.m_tool = new MenuItem();
	temp.m_ninja = new MenuItem();
	temp.m_name = new GUIText();
	temp.m_ready = new MenuItem();

	// Ninja
	if (p_ninja == 0)
	{
		temp.m_ninja->Initialize(m_startXPos + m_portraitOffset, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja1.png"));
	}
	else if (p_ninja == 1)
	{
		temp.m_ninja->Initialize(m_startXPos + m_portraitOffset, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja2.png"));
	}
	else
	{
		temp.m_ninja->Initialize(m_startXPos + m_portraitOffset, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Ninjas/ninja3.png"));
	}
	// Tool
	if (p_tool == 0)
	{
		temp.m_tool->Initialize(m_startXPos + m_portraitOffset + m_toolOffset, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_Caltrops.png"));
	}
	else if (p_tool == 1)
	{
		temp.m_tool->Initialize(m_startXPos + m_portraitOffset + m_toolOffset, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_SmokeBomb.png"));
	}
	else if (p_tool == 2)
	{
		temp.m_tool->Initialize(m_startXPos + m_portraitOffset + m_toolOffset, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_StickyTARP.png"));
	}
	else
	{
		temp.m_tool->Initialize(m_startXPos + m_portraitOffset + m_toolOffset, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Abilities/TB_T_FlashBang.png"));
	}

	// Name
	temp.m_name->Initialize(p_name, 40.0f, m_startXPos + m_portraitOffset * 0.75f, m_startYPos - PORTRAITHEIGHT + 15.0f, 0xFFFFFFFF);
	temp.m_name->SetTextAlignment(m_nameAlignment);
	temp.m_name->SetText(p_name);

	// Ready
	if (p_isReady)
	{
		temp.m_ready->Initialize(m_startXPos + m_portraitOffset + m_toolOffset * 2.0f, m_startYPos, CHECKBOXSIZE, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/checkbox_checked.png"));
	}
	else
	{
		temp.m_ready->Initialize(m_startXPos + m_portraitOffset + m_toolOffset * 2.0f, m_startYPos, CHECKBOXSIZE, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/GUI/checkbox_empty.png"));
	}

	m_startYPos -= PORTRAITHEIGHT * 2.0f;
	
	m_teamList.push_back(temp);
}
void TeamTable::ClearList()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Shutdown();
		m_teamList[i].m_tool->Shutdown();
		delete m_teamList[i].m_ninja;
		delete m_teamList[i].m_tool;
		m_teamList[i].m_ninja = nullptr;
		m_teamList[i].m_tool = nullptr;
	}
	m_teamList.clear();
	m_startXPos = m_initialStartXPos;
	m_startYPos = m_initialStartYPos;
}

int TeamTable::GetNumberOfPlayers()
{
	return m_teamList.size();
}
float TeamTable::GetXPos()
{
	return m_startXPos + m_portraitOffset;
}
float TeamTable::GetNextYPos()
{
	float temp = m_startYPos;
	m_startYPos -= PORTRAITHEIGHT * 1.1f;
	return temp;
}