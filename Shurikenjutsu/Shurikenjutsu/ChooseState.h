#ifndef CHOOSESTATE_H_
#define CHOOSESTATE_H_

#define WIN32_LEAN_AND_MEAN

#include "GameState.h"

class Menu;
class MenuItem;

class ChooseState : public GameState
{
public:
	ChooseState();
	~ChooseState();

	bool Initialize();
	GAMESTATESWITCH Update();
	void Render();
	void NextNinja();
	void PrevNinja();

private:
	Menu* m_chooseButton;

	MenuItem *m_ninjas[4];

	int currentNinja;
	int nrOfNinjas;
};
#endif // !CHOOSESTATE_H_