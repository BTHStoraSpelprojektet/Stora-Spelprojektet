#ifndef SMOKEBOMBMANAGER_H
#define SMOKEBOMBMANAGER_H
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>
class SmokeBombManager
{
public:
	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);
};


#endif