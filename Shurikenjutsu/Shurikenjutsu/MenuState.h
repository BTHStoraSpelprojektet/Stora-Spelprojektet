#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include <stack>
#include "Network.h"

class GUIText;
class Menu;
class MenuIpBox;

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	bool Initialize();
	GAMESTATESWITCH Update();
	void Shutdown();
	void Render();

private:

	std::stack<Menu*> m_menues;
	Menu* m_main;
	Menu* m_options;
	Menu* m_play;
	Menu* m_connecting;

	MenuIpBox* m_ipbox;
	bool m_hideIpBox;
	GUIText* m_ipboxText;
};

#endif