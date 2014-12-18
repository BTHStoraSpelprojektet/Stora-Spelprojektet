#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include "GameState.h"
#include <stack>
#include "Menu.h"

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	bool Initialize();
	GAMESTATESWITCH Update();
	void Render();

private:

	std::stack<Menu> m_menues;
	Menu m_main;
	Menu m_options;
};

#endif