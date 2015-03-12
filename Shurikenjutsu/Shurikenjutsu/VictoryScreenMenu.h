#ifndef VICTORYSCREENMENU_H_
#define VICTORYSCREENMENU_H_

enum IN_GAME_MENU_ACTION;
class Menu;
class GUIElement;

class VictoryScreenMenu
{
public:
	VictoryScreenMenu();
	~VictoryScreenMenu();

	bool Initialize();
	void Shutdown();

	IN_GAME_MENU_ACTION Update();
	void Render();
private:
	Menu* m_menu;
	GUIElement* m_background;
};

#endif