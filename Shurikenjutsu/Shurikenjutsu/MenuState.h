#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include <stack>
#include "Network.h"

class GUIText;
class Menu;
class MenuIpBox;
class ObjectManager;
class Frustum;
class Camera;
class MenuItem;

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize();
	void Shutdown();
	void ShutdownExit();

	GAMESTATESWITCH Update();
	void Render();

	void EscapeIsPressed();

	void setSound(Sound* p_sound);
private:

	std::stack<Menu*> m_menues;
	Menu* m_main;
	Menu* m_options;
	Menu* m_play;
	Menu* m_connecting;

	MenuIpBox* m_ipbox;
	bool m_hideIpBox;
	GUIText* m_ipboxText;
	GUIText* m_ipText;

	bool m_lastvsync;
	bool m_lastfullscreen;
	int m_vsyncIndex;
	int m_fullscreenIndex;

	//Background
	ObjectManager* m_objectManager;
	Camera* m_camera;
	Frustum* m_frustum;
	DirectionalLight m_directionalLight;
	MenuItem* m_logo;

	Sound* m_sound;
};

#endif