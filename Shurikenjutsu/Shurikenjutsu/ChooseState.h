#ifndef CHOOSESTATE_H_
#define CHOOSESTATE_H_

#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include <stack>
#include <vector>
#include "..\CommonLibs\CommonStructures.h"

class Menu;
class MenuItem;
class GUIText;
class MenuButton;
class CharacterAbilityDescription;
class ToolTipPopUp;
class Camera;
class ObjectManager;
class Frustum;
class Sound;
class PlayerManager;
class TeamTable;

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

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	void Shutdown();
	void ShutdownExit();
	bool Initialize();
	bool Initialize(std::string p_levelName);
	ObjectManager* GetObjectManager();
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
	MenuItem *m_title;
	MenuItem *m_tintedBackground;
	MenuItem *m_ninjaPortBorder;
	MenuItem *m_backgroundFrame;
	ToolTipPopUp* m_toolDescription[3];
	MenuItem *m_questionMark;
	CharacterAbilityDescription *m_abilityDescription[4];
	GUIText* m_redTeamScore;
	GUIText* m_blueTeamScore;
	std::vector<GUIText> m_keyBinds;
	int m_currentNinja;
	int m_nrOfNinjas;
	int m_currentTool;
	int m_nrOfTools;
	float m_screenHeight;
	float m_screenWidth;
	bool m_isRandoming;
	CurrentTeam m_currentTeam;
	MenuButton* m_playButton;

	Camera *m_camera;
	ObjectManager* m_objectManager;
	Sound* m_sound;
	Frustum* m_frustum;
	DirectionalLight m_directionalLight;
	PlayerManager *m_playerManager;


	float m_portraitWidth;
	float m_portraitHeight;
	float m_buttonWidth;
	float m_buttonHeight;
	float m_nextWidth;
	float m_nextHeight;
	float m_toolWidth;
	float m_toolHeight;

	int m_prevRandomNumber;
};


#endif // !CHOOSESTATE_H_