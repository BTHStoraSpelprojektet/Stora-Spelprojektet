#ifndef INGAMEMENU_H_
#define INGAMEMENU_H_

class MenuButton;
class Menu;
const float BUTTONWIDTH = 301.0f;
const float BUTTONHEIGHT = 98.0f;
const float BUTTONOFFSET = 10.0f;
class InGameMenu
{
public:
	InGameMenu();
	~InGameMenu();

	void Initialize();
	void Shutdown();
	void Update();
	void Render();

private:
	Menu *m_menu;
	
};
#endif
