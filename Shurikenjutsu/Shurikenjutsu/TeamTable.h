#ifndef TEAMTABLE_H
#define TEAMTABLE_H

#include <vector>

class MenuItem;

struct CharacterToolWrapper
{
	MenuItem *m_ninja;
	MenuItem *m_tool;
};
class TeamTable
{

public:
	TeamTable();
	~TeamTable();
	void Initialize(float p_startXPos, float p_startYPos, int p_team);
	void Shutdown();
	void Render();
	void AddTeamMate(int p_ninja, int p_tool);
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
};

#endif