#ifndef DEATHBOARD_H_
#define DEATHBOARD_H_

#define WIN32_LEAN_AND_MEAN

#include <DirectXMath.h>
#include "../CommonLibs/CommonEnums.h"
#include "GUIElement.h"
#include "GUIText.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

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
	void KillHappened(RakNet::RakNetGUID p_ninjaKilling, RakNet::RakNetGUID p_ninjaKilled, ABILITIES p_abilityUsed);

private:
	DeathBoard();
	~DeathBoard();
	static DeathBoard* m_instance;

	void ChangeOrder(int p_index);

	DirectX::XMFLOAT3 m_originalPos;
	GUIText m_killer[5];
	GUIText m_deadGuy[5];
	GUIElement m_killAbility[5];

	double m_deathTimer[5];
	int m_nrOfDeaths;

	UINT32 m_redColor;
	UINT32 m_blueColor;
};

#endif // !DEATHBOARD_H_
