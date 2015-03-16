#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#define WIN32_LEAN_AND_MEAN

#include "GameState.h"
#include <stack>
#include "..\CommonLibs\CommonStructures.h"

class GUIText;
class Menu;
class MenuTextBox;
class ObjectManager;
class Frustum;
class Camera;
class MenuItem;
class CreaditsScreen;
class Sound;


class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize();
	bool Initialize(std::string p_levelName);
	void Shutdown();
	void ShutdownExit();

	GAMESTATESWITCH Update();
	void Render();

	void EscapeIsPressed();

	void setSound(Sound* p_sound);
private:
	void InitializeCreditScreen();
	bool StartLocalServer();
	void OptionsApply();


	std::stack<Menu*> m_menues;
	Menu* m_main;
	Menu* m_options;
	Menu* m_play;
	Menu* m_connecting;
	CreaditsScreen* m_creditScreen;

	MenuTextBox* m_ipbox;
	MenuTextBox* m_namebox;
	bool m_hideIpBox;

	// Checkbox Indexes
	int m_vsyncIndex;
	int m_fullscreenIndex;
	int m_dofIndex;
	int m_ssaoIndex;
	int m_soundMuteIndex;
	int m_cameraModeIndex;
	int m_apeMode;

	//Background
	ObjectManager* m_objectManager;
	Camera* m_camera;
	Frustum* m_frustum;
	DirectionalLight m_directionalLight;
	MenuItem* m_logo;

	Sound* m_sound;
	bool m_isPlayingBackgroundMusic;
};

#endif