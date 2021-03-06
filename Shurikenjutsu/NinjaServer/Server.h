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
#include "GameState.h"
#include "DebugState.h"
#include "NormalState.h"
#include "..\CommonLibs\NetworkLogger.h"

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
	GameState* m_gameState;
	int m_currentLevel;
	std::vector<std::string> m_levels;
	void Server::ReadLevels();

	NetworkLogger m_networkLogger;
};

#endif SERVER