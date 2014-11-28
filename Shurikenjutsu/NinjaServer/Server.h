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
	RakNet::RakPeerInterface *m_serverPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;
	ReplicaManager* m_replicaManager;
	RakNet::NetworkIDManager* m_networkIDManager;
};

#endif SERVER