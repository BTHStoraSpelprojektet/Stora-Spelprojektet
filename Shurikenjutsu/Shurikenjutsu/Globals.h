#ifndef GLOBALS
#define GLOBALS

#include <string>

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
	bool CAMERA_MOVING;
	bool CAMERA_SPECTATE;

	void SetDeltaTime(double p_deltaTime);
	double GetDeltaTime();

	float BORDER_SIZE;
	float TITLE_BORDER_SIZE;

	std::string FPS;

private:
	GLOBAL() {};
	GLOBAL(GLOBAL const&);              
	void operator=(GLOBAL const&);
	double DELTATIME;
};
#endif