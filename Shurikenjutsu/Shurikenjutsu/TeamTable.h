#ifndef TEAMTABLE_H
#define TEAMTABLE_H

#include <vector>
#include <dwrite.h>

class MenuItem;
class GUIText;

struct CharacterToolWrapper
{
	MenuItem *m_ninja;
	MenuItem *m_tool;
	GUIText* m_name;
	MenuItem* m_ready;
};
class TeamTable
{

public:
	TeamTable();
	~TeamTable();
	void Initialize(float p_startXPos, float p_startYPos, int p_team);
	void Shutdown();
	void Render();
	void AddTeamMate(int p_ninja, int p_tool, std::string p_name, bool p_isReady);
	void ClearList();
	int GetNumberOfPlayers();
	float GetXPos();
	float GetNextYPos();
private:
	std::vector<CharacterToolWrapper> m_teamList;

	float m_startXPos;
	float m_startYPos;
	float m_initialStartXPos;
	float m_initialStartYPos;
	float m_portraitOffset;
	float m_toolOffset;
	DWRITE_TEXT_ALIGNMENT m_nameAlignment;
};

#endif