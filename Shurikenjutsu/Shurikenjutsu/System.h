#ifndef SYSTEM
#define SYSTEM

//#define WIN32_LEAN_AND_MEAN

#include "Network.h"
#include "Window.h"

class Sound;
class Timer;
class Debug;
class ChooseState;
class MenuState;
class PlayingStateTest;
class GameState;

class System
{
public:
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
	void Shutdown();
	void Run();


private:
	void Update();
	void Render();

	Window m_window;
	Timer* m_timer;
	Debug* m_debug;

	std::string m_title;
	int m_previousFPS;

	MenuState* m_menuState;
	ChooseState* m_chooseNinjaState;
	GameState* m_gameState;
	PlayingStateTest* m_playingState;

	Sound* m_sound;
};
#endif