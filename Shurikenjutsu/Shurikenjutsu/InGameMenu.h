#ifndef INGAMEMENU_H_
#define INGAMEMENU_H_

#include "Menu.h"

const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
const float BUTTONOFFSET = 10.0f;

enum IN_GAME_MENU_ACTION
{
	IN_GAME_MENU_RESUME,
	IN_GAME_MENU_CONTINUE,
	IN_GAME_MENU_TO_MAIN,
	IN_GAME_MENU_QUIT,
	IN_GAME_MENU_IDLE
};

class InGameMenu
{
public:
	InGameMenu();
	~InGameMenu();

	void Initialize();
	void Shutdown();
	IN_GAME_MENU_ACTION Update();
	void Render();

private:
	Menu *m_menu;
	
};
#endif
