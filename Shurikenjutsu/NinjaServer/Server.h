#ifndef SERVER
#define SERVER

#include <iostream>


#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ReplicaManager.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\CommonEnums.h"
#include <vector>
#include "MapManager.h"
#include "CollisionManager.h"

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
	CollisionManager m_collisionManager;
};

#endif SERVER