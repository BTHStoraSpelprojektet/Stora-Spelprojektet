#ifndef MENUIPBOX_H_
#define MENUIPBOX_H_

#include "MenuButton.h"
#include <string>

class MenuIpBox : public MenuButton
{
public:
	MenuIpBox();
	~MenuIpBox();

	bool Initialize(float p_x, float p_y, float p_width, float p_height);

	bool IsClicked();
	void GetInput();
	void ToConsole();
	std::string GetIp();

private:
	void ResetIp();

	bool m_active;
	char m_ip[15];
	int m_counter;
};
#endif

