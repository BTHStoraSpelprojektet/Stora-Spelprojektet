#ifndef GLOBALS
#define GLOBALS

#include <string>
#include <DirectXMath.h>

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
	bool APE_ON;

	void SetDeltaTime(double p_deltaTime);
	double GetDeltaTime();

	float BORDER_SIZE;
	float TITLE_BORDER_SIZE;

	DirectX::XMFLOAT4 TEAMCOLOR_BLUE = DirectX::XMFLOAT4(0.0f, 0.07f, 0.71f, 1.0f);
	DirectX::XMFLOAT4 TEAMCOLOR_RED = DirectX::XMFLOAT4(0.71f, 0.0f, 0.03f, 1.0f);;

	std::string FPS;

	bool VOLUME_ON;

private:
	GLOBAL() {};
	GLOBAL(GLOBAL const&);              
	void operator=(GLOBAL const&);
	double DELTATIME;
};
#endif