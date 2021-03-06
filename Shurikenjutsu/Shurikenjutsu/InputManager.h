#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <vector>
class KButtonEvent;
class ButtonEvent;

typedef _W64 unsigned int UINT_PTR;
typedef long LPARAM;
typedef UINT_PTR WPARAM;
typedef unsigned int UINT;

class InputManager
{
public:
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	static InputManager* GetInstance();

	void Initialize();
	void Shutdown();

	void UpdateInput(UINT p_message, WPARAM p_wParam, LPARAM p_lParam);
	void ClearInput();

	bool IsKeyClicked(int p_vkey) const;
	bool IsKeyPressed(int p_vkey) const;

	int GetMousePositionX() const;
	int GetMousePositionY() const;
	int GetMousePositionX_prev() const;
	int GetMousePositionY_prev() const;

	bool IsLeftMousePressed() const;
	bool IsLeftMouseClicked() const;
	bool IsRightMousePressed() const;
	bool IsRightMouseClicked() const;

	void RegisterKey(int p_vkey);

	char GetLastCharRead() const;

	void Set3DMousePosition(float p_x, float p_z);
	float Get3DMousePositionX();
	float Get3DMousePositionZ();

private:
	static InputManager* m_instance;

	InputManager();
	~InputManager();

	std::vector<KButtonEvent*> m_events; // Keyboard buttons

	ButtonEvent *m_leftMouseB;
	ButtonEvent *m_rightMouseB;

	int m_mousePositionX;
	int m_mousePositionY;
	int m_mousePositionX_prev;
	int m_mousePositionY_prev;


	float m_3DMouseX;
	float m_3DMouseZ;

	char m_lastCharRead;
};

#endif