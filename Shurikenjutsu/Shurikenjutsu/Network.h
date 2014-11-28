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

	static bool Initialize();
	static void Shutdown();

	static void Update();

	static void AddReference(DefaultReplica* p_replica);
	static void RemoveReference(DefaultReplica* p_replica);
	//static void RemoveObject(DefaultReplica* p_replica);

	static std::vector<PlayerReplica*> GetOtherPlayers();
	static std::vector<ShurikenReplica*> GetShurikens();
	static bool ConnectedNow();
	static bool IsConnected();
private:
	Network() {};
	static void ReceviePacket();

	static RakNet::RakPeerInterface *m_clientPeer;
	static RakNet::SocketDescriptor m_socketDesc;
	static RakNet::Packet *m_packet;
	static ReplicaManager* m_replicaManager;

	static bool m_connected;
	static bool m_prevConnected;
};

#endif