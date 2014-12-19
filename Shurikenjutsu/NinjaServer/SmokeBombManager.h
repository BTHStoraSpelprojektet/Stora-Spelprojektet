#ifndef SMOKEBOMBMANAGER_H
#define SMOKEBOMBMANAGER_H
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>
#include "..\CommonLibs\GameplayGlobalVariables.h"
class SmokeBombManager
{
public:
	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
	void AddSmokeBomb(float p_posX, float p_posZ);


	std::vector<SmokeBombNet> GetSmokeBombs();
	unsigned int GetSmokeBombUniqueId();

	void BroadcastEmptySmokeBombs(unsigned int p_id);

private:
	RakNet::RakPeerInterface *m_serverPeer;
	
	std::vector<SmokeBombNet> m_smokeBombs;
};


#endif