#ifndef WINDOW
#define WINDOW

#include <Windows.h>
#include "Structures.h"

class Window
{
public:
	bool Initialize(WindowRectangle p_window);
	HWND GetHandle();
	void SetTitle(std::string p_title);

private:
	HWND m_handle;

	static LRESULT CALLBACK WndProc(HWND p_windowHandle, UINT p_message, WPARAM p_wParam, LPARAM p_lParam);
};
#endif