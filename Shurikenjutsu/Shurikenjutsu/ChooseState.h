#ifndef CHOOSESTATE_H_
#define CHOOSESTATE_H_

#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include <stack>
#include <vector>
#include "TeamTable.h"

class Menu;
class MenuItem;
class GUIText;
class CharacterAbilityDescription;


class ChooseState : public GameState
{
public:
	ChooseState();
	~ChooseState();

	void Shutdown();
	bool Initialize();
	GAMESTATESWITCH Update();
	void Render();
	void NextNinja();
	void PrevNinja();
	void NextTool();
	void PrevTool();
	void EscapeIsPressed();

private:
	void UpdateTeams();
	void RandomNinja();

	Menu* m_chooseNinja;
	TeamTable* m_redTeam;
	TeamTable* m_blueTeam;
	

	MenuItem *m_ninjas[4];
	MenuItem *m_tools[3];
	CharacterAbilityDescription *m_abilityDescription[4];
	GUIText* m_redTeamScore;
	GUIText* m_blueTeamScore;
	int currentNinja;
	int nrOfNinjas;
	int currentTool;
	int nrOfTools;
	float m_screenHeight;
	float m_screenWidth;

	float m_portraitWidth;
	float m_portraitHeight;
	int m_myTeam;
};


#endif // !CHOOSESTATE_H_