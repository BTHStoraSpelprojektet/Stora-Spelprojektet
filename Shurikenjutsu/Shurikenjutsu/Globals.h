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

	bool SWITCHING_SCREEN_MODE;
	bool CAMERA_FLYING;

	double DELTATIME;

private:
	GLOBAL() {};
	GLOBAL(GLOBAL const&);              
	void operator=(GLOBAL const&);
};
#endif