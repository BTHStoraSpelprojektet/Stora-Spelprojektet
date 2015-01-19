#ifndef CHOOSESTATE_H_
#define CHOOSESTATE_H_

#include "GameState.h"
#include "Menu.h"

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
	Menu m_chooseButton;
	int currentNinja;
	int nrOfNinjas;
};
#endif // !CHOOSESTATE_H_