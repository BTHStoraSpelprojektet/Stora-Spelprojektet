#ifndef SERVER
#define SERVER

#include <iostream>
/*
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\RakPeerInterface.h"
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\MessageIdentifiers.h"
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\RakNetTypes.h"  // MessageID
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\GetTime.h"
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\NetworkIDManager.h"
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\RakPeer.h"
#include "C:\Users\kalle\Documents\GitHub\Stora-Spelprojektet\Shurikenjutsu\CommonLibs\RakNet\BitStream.h"
*/
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
#include <vector>

class Server
{
public:
	Server();
	~Server();
	bool Initialize();
	void Shutdown();
	void Update();
	void ReceviePacket();
private:
	void MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z);
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	RakNet::RakPeerInterface *m_serverPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;
	//ReplicaManager* m_replicaManager;
	int m_nrOfConnections;
	std::vector<PlayerNet> m_players;
};

#endif SERVER