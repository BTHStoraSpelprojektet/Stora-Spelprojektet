#include "TeamTable.h"
#include "MenuItem.h"
#include "TextureLibrary.h"


TeamTable::TeamTable(){}
TeamTable::~TeamTable(){}
// PORTRAIT
const float PORTRAITWIDTH = 200.0f;
const float PORTRAITHEIGHT = 200.0f;

// TOOL TEXTURE
const float TOOLWIDTH = 50.0f;
const float TOOLHEIGHT = 50.0f;
// BUTTON
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
// OFFSET
const float OFFSET = 10.0f;

void TeamTable::Initialize(float p_startXPos, float p_startYPos)
{
	m_startXPos = p_startXPos;
	m_startYPos = p_startYPos;

}
void TeamTable::Shutdown()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Shutdown();
		m_teamList[i].m_tool->Shutdown();
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
		temp.m_ninja->Initialize(m_startXPos, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja1.png"));
	}
	else if (p_ninja == 1)
	{
		temp.m_ninja->Initialize(m_startXPos, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja2.png"));
	}
	else
	{
		temp.m_ninja->Initialize(m_startXPos, m_startYPos, PORTRAITWIDTH, PORTRAITHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/ninja3.png"));
	}

	if (p_tool == 0)
	{
		temp.m_tool->Initialize(0.0f, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_Caltrops.png"));
	}
	else if (p_tool == 1)
	{
		temp.m_tool->Initialize(0.0f, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_SmokeBomb.png"));
	}
	else
	{
		temp.m_tool->Initialize(0.0f, m_startYPos, TOOLWIDTH, TOOLHEIGHT, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/TB_StickyTARP.png"));
	}

	m_startYPos -= 50.0f;
	
	m_teamList.push_back(temp);
}
void TeamTable::ClearList()
{
	for (unsigned int i = 0; i < m_teamList.size(); i++)
	{
		m_teamList[i].m_ninja->Shutdown();
		m_teamList[i].m_tool->Shutdown();
	}
	m_teamList.clear();
}