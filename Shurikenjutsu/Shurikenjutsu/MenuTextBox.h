#ifndef MENUTEXTBOX_H_
#define MENUTEXTBOX_H_

#include "MenuButton.h"
#include <string>

class GUIText;
class MenuTextBox : public MenuButton
{
public:
	MenuTextBox();
	~MenuTextBox();

	bool Initialize(float p_x, float p_y, float p_width, float p_height, int p_maxChars, std::string p_text);
	void Shutdown();
	void Render();
	bool Update();
	void ToConsole();
	std::string GetText();

private:
	bool IsClicked();
	void GetInput();

	bool m_active;
	char* m_text;
	int m_counter;
	int m_maxChars;
	GUIText* m_guiText;

};
#endif