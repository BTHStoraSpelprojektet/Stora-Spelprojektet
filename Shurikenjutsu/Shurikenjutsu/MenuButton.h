#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "MenuItem.h"

class MenuButton : public MenuItem
{
public:
	MenuButton();
	~MenuButton();

	bool IsClicked();


private:
	
};

#endif // MENUBUTTON_H_