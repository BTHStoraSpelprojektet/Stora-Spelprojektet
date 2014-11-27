#include "Window.h"

bool Window::Initialize(WindowRectangle p_window)
{
	bool result = true;

	m_handle = 0;
	
	// Register window.
	WNDCLASS description;
	description.style = CS_HREDRAW | CS_VREDRAW;
	description.lpfnWndProc = WndProc;
	description.cbClsExtra = 0;
	description.cbWndExtra = 0;
	description.hInstance = GetModuleHandle(NULL);
	description.hIcon = LoadIcon(0, IDI_APPLICATION);
	description.hCursor = LoadCursor(0, IDC_ARROW);
	description.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	description.lpszMenuName = 0;
	description.lpszClassName = "Window Registered.";
	
	// If window registration fails, output an error message.
	if (!RegisterClass(&description))
	{
		ConsolePrintError("Window failed to register.");
		result = false;
	}
	
	// Create the window.
	
	m_handle = CreateWindow(description.lpszClassName, "Window Created.", WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, p_window.x, p_window.y, p_window.width, p_window.height, 0, 0, GetModuleHandle(NULL), 0);
	
	// Show and update the window.
	if (m_handle != 0)
	{
		ShowWindow(m_handle, 1);
		UpdateWindow(m_handle);
	}

	// If window creation fails, display an error message.
	else
	{
		ConsolePrintError("Window failed to create.");
		result = false;
		
	}
	
	return result;
}

LRESULT CALLBACK Window::WndProc(HWND p_windowHandle, UINT p_message, WPARAM p_wParam, LPARAM p_lParam)
{
	// Handle message.
	switch (p_message)
	{
		// Quit message:
		case(WM_DESTROY) :
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	// Default message procedure.
	return DefWindowProc(p_windowHandle, p_message, p_wParam, p_lParam);
}

void Window::SetTitle(std::string p_title)
{
	SetWindowTextA(m_handle, p_title.c_str());
}

HWND Window::GetHandle()
{
	return m_handle;
}