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
class ToolTipPopUp;
class Camera;

enum CurrentTeam
{
	CURRENTTEAM_RED,
	CURRENTTEAM_BLUE,
	CURRENTTEAM_NONE
};
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
	ToolTipPopUp* m_toolDescription[3];
	MenuItem *m_questionMark;
	CharacterAbilityDescription *m_abilityDescription[4];
	GUIText* m_redTeamScore;
	GUIText* m_blueTeamScore;
	int currentNinja;
	int nrOfNinjas;
	int currentTool;
	int nrOfTools;
	float m_screenHeight;
	float m_screenWidth;
	bool m_isRandoming;
	CurrentTeam m_currentTeam;
	Camera *m_camera;



	float m_portraitWidth;
	float m_portraitHeight;
	float m_buttonWidth;
	float m_buttonHeight;
	float m_nextWidth;
	float m_nextHeight;
	float m_toolWidth;
	float m_toolHeight;

};


#endif // !CHOOSESTATE_H_