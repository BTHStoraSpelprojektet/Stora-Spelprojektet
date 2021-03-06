#ifndef SYSTEM
#define SYSTEM

//#define WIN32_LEAN_AND_MEAN

#include "Network.h"

class MemoryChecker;
class Sound;
class Timer;
class Debug;
class ChooseState;
class MenuState;
class PlayingState;
class GameState;
class Cursor;
class Window;

class System
{
public:
	bool Initialize(int p_argc, _TCHAR* p_argv[]);
	void Shutdown();
	void Run();


private:
	void Update();
	void Render();

	Window *m_window;
	Timer* m_timer;

	std::string m_title;
	int m_previousFPS;

	MenuState* m_menuState;
	ChooseState* m_chooseNinjaState;
	GameState* m_gameState;
	PlayingState* m_playingState;
	Cursor *m_cursor;

	Sound* m_sound;

	MemoryChecker* m_memoryCheker;
};
#endif