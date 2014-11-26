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
#include "RakPeerInterface.h"
#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include "GetTime.h"
#include "NetworkIDManager.h"
#include "RakPeer.h"
#include "BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"

#define MAX_CLIENTS 10
#define SERVER_PORT 60000

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

};

#endif SERVER