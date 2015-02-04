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

	void SetDeltaTime(double p_deltaTime);
	double GetDeltaTime();

	float BORDER_SIZE;
	float TITLE_BORDER_SIZE;

private:
	GLOBAL() {};
	GLOBAL(GLOBAL const&);              
	void operator=(GLOBAL const&);
	double DELTATIME;
};
#endif