#ifndef SERVER
#define SERVER

#include <iostream>

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\GetTime.h"
#include "..\CommonLibs\RakNet\NetworkIDManager.h"
#include "..\CommonLibs\RakNet\RakPeer.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ReplicaManager.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <vector>
#include "PlayerManager.h"
#include "ShurikenManager.h"
#include "MapManager.h"

#pragma comment(lib, "PhysicsDll.lib")
#include "PhysicsDll.h"

class Server
{
public:
	Server();
	~Server();
	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);
	void ReceviePacket();
private:
	void CheckCollisions();
	void MeleeAttack(RakNet::RakNetGUID p_guid);

	RakNet::RakPeerInterface *m_serverPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

	int m_nrOfConnections;
	std::string m_levelName;
	std::string m_shurikenModelName;
	std::string m_playerModelName;
	PlayerManager m_playerManager;
	ShurikenManager m_shurikenManager;
	MapManager m_mapManager;
};

#endif SERVER