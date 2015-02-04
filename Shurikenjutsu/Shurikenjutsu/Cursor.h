#ifndef CURSOR_H_
#define CURSOS_H_
#include <Windows.h>


class GUIElement;
class Cursor
{
public:
	Cursor();
	~Cursor();

	bool Initialize(HWND p_hwnd);
	void Shutdown();

	void Update();
	void Render();

	void SetCustomCursor(bool p_useCustom);



private:
	bool m_useCustomCursor;
	GUIElement *m_cursor;
	HWND m_hwnd;
	
};

#endif