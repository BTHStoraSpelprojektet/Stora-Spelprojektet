#ifndef DEATHBOARD_H_
#define DEATHBOARD_H_

#include <DirectXMath.h>

class GUIElement;

class DeathBoard
{
public:
	DeathBoard(const DeathBoard&) = delete;
	DeathBoard& operator=(const DeathBoard&) = delete;

	static DeathBoard* GetInstance();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();
	
	void DeathEverywhere();


private:
	DeathBoard();
	~DeathBoard();
	static DeathBoard* m_instance;

	//DirectX::XMFLOAT3 m_originalPos;
	GUIElement* m_killer;
	GUIElement* m_deadGuy;
	GUIElement* m_killAbility;

	double m_deathTimer;
};

#endif // !DEATHBOARD_H_
