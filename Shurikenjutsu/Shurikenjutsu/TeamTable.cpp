#include "TeamTable.h"
#include "MenuItem.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "Globals.h"


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
	m_toolOffset = PORTRAITWIDTH * 2.0f;
	if (p_team == 2)
	{
		m_toolOffset *= -1;
	}
}
void TeamTable::Shutdown()
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
}
void TeamTable::Render()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Render();
		m_teamList[i].m_tool->Render();
	}
}
void TeamTable::AddTeamMate(int p_ninja, int p_tool)
{
	CharacterToolWrapper temp;
	temp.m_tool = new MenuItem();
	temp.m_ninja = new MenuItem();


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

	m_startYPos -= PORTRAITHEIGHT * 1.1f;
	
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