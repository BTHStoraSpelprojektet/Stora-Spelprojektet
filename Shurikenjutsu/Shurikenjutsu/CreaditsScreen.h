#ifndef CREDITSCREEN_H_
#define CREDITSCREEN_H_
#include "Menu.h"

class GUIText;
class CreaditsScreen : public Menu
{
public:
	CreaditsScreen();
	~CreaditsScreen();
	void Initialize();
	void Shutdown();
	MenuActionData Update();
	void Render();
	void ResetTexts();

private:
	GUIText *m_developers;
	GUIText *m_music;

	float m_developersTextPositionY;
};

#endif