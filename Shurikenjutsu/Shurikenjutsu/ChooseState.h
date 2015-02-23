#ifndef CHOOSESTATE_H_
#define CHOOSESTATE_H_

#define WIN32_LEAN_AND_MEAN

#include "GameState.h"

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
	Menu* m_chooseButton;

	MenuItem *m_ninjas[4];
	MenuItem *m_tools[3];
	CharacterAbilityDescription *m_abilityDescription[4];

	int currentNinja;
	int nrOfNinjas;
	int currentTool;
	int nrOfTools;
};
#endif // !CHOOSESTATE_H_