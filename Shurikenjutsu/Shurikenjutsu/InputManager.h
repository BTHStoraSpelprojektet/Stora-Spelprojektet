#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "KButtonEvent.h"
#include <vector>
#include "Windows.h"
#include "Windowsx.h"
#include "ConsoleFunctions.h"

enum MouseButtonState
{

};

class InputManager
{
public:
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	static InputManager* GetInstance();

	void Shutdown();

	void UpdateInput(UINT p_message, WPARAM p_wParam, LPARAM p_lParam);
	void ClearInput();

	bool IsKeyClicked(int p_vkey) const;
	bool IsKeyPressed(int p_vkey) const;

	int GetMousePositionX() const;
	int GetMousePositionY() const;

	bool IsLeftMousePressed() const;
	bool IsLeftMouseClicked() const;
	bool IsRightMousePressed() const;
	bool IsRightMouseClicked() const;

	void RegisterKey(int p_vkey);

private:
	static InputManager* m_instance;

	InputManager();
	~InputManager();

	std::vector<KButtonEvent> m_events; // Keyboard buttons

	ButtonEvent m_leftMouseB;
	ButtonEvent m_rightMouseB;

	int m_mousePositionX;
	int m_mousePositionY;
};

#endif