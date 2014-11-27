#ifndef NETWORK_H_
#define NETWORK_H_


#include <iostream>

//#include "..\CommonLibs\RakNet\RakPeerInterface.h"
//#include "..\CommonLibs\RakNet\NetworkIDManager.h"
//
//#include "..\CommonLibs\ServerGlobals.h"
//#include "..\CommonLibs\ReplicaManager.h"
//#include "..\CommonLibs\PlayerReplica.h"

#include "..\CommonLibs\RakNet\WindowsIncludes.h"

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\GetTime.h"
#include "..\CommonLibs\RakNet\NetworkIDManager.h"
#include "..\CommonLibs\RakNet\RakPeer.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ReplicaManager.h"
#include <vector>

#include "ConsoleFunctions.h"

class Network
{
public:
	Network();
	~Network();

	bool Initialize();
	void Shutdown();

	void Update();

	std::vector<PlayerReplica*> GetOtherPlayers();
	bool IsConnected();
private:
	void ReceviePacket();

	RakNet::RakPeerInterface *m_clientPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;
	ReplicaManager* m_replicaManager;

	bool m_connected;
};

#endif