#ifndef GLOBALS
#define GLOBALS

class GLOBAL
{
public:
	static GLOBAL& GetInstance();

	bool FULLSCREEN;

	int MAX_SCREEN_HEIGHT;
	int MAX_SCREEN_WIDTH;

	int MIN_SCREEN_HEIGHT;
	int MIN_SCREEN_WIDTH;

	int CURRENT_SCREEN_HEIGHT;
	int CURRENT_SCREEN_WIDTH;

	bool isNotSwitchingFullscreen;
	bool flyingCamera;

	void SetDeltaTime(double p_deltaTime);
	double GetDeltaTime();

private:
	GLOBAL() {};
	GLOBAL(GLOBAL const&);              
	void operator=(GLOBAL const&);
	double DELTATIME;
};
#endif