#ifndef DEATHBOARD_H_
#define DEATHBOARD_H_

#include <DirectXMath.h>
#include "../CommonLibs/CommonEnums.h"
#include "GUIElement.h"

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
	void KillHappened(int p_ninjaKilling, int p_ninjaKilled, ABILITIES p_abilityUsed);

private:
	DeathBoard();
	~DeathBoard();
	static DeathBoard* m_instance;

	void ChangeOrder(int p_index);

	DirectX::XMFLOAT3 m_originalPos;
	GUIElement m_killer[5];
	GUIElement m_deadGuy[5];
	GUIElement m_killAbility[5];

	double m_deathTimer[5];
	int m_nrOfDeaths;
};

#endif // !DEATHBOARD_H_
