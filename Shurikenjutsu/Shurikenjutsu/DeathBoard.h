#ifndef DEATHBOARD_H_
#define DEATHBOARD_H_

#define WIN32_LEAN_AND_MEAN

#include <DirectXMath.h>
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "../CommonLibs/CommonEnums.h"

class GUIText;
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
	void KillHappened(RakNet::RakNetGUID p_ninjaKilling, RakNet::RakNetGUID p_ninjaKilled, ABILITIES p_abilityUsed);

private:
	DeathBoard();
	~DeathBoard();
	static DeathBoard* m_instance;

	void ChangeOrder(int p_index);

	DirectX::XMFLOAT3 m_originalPos;
	GUIText* m_killer;
	GUIText* m_deadGuy;
	GUIElement* m_killAbility;
	GUIElement* m_background;

	double m_deathTimer[5];
	int m_nrOfDeaths;

	UINT32 m_redColor;
	UINT32 m_blueColor;
};

#endif // !DEATHBOARD_H_
