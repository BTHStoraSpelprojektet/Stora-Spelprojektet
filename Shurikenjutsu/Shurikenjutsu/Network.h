#ifndef NETWORK_H_
#define NETWORK_H_

#define WIN32_LEAN_AND_MEAN

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
#include "..\CommonLibs\ServerMessages.h"
#include <vector>

#include "ConsoleFunctions.h"

class Network
{
public:

	static bool Initialize();
	static void Shutdown();

	static void Update();

	//static void AddReference(DefaultReplica* p_replica);
	//static void RemoveReference(DefaultReplica* p_replica);
	//static void RemoveObject(DefaultReplica* p_replica);

	//static std::vector<PlayerReplica*> GetOtherPlayers();
	static bool ConnectedNow();
	static bool IsConnected();

	static void SendPlayerPos(float p_x, float p_y, float p_z);
	static std::vector<PlayerNet> GetOtherPlayers();
	static PlayerNet GetMyPlayer();
	static void AddShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_id, RakNet::RakNetGUID p_owner);

private:
	Network() {};
	static void ReceviePacket();
	static void UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z);

	static RakNet::RakPeerInterface *m_clientPeer;
	static RakNet::SocketDescriptor m_socketDesc;
	static RakNet::Packet *m_packet;
	//static ReplicaManager* m_replicaManager;

	static bool m_connected;
	static bool m_prevConnected;
	static int m_connectionCount;
	static PlayerNet m_myPlayer;
	static std::vector<PlayerNet> m_enemyPlayers;
	
};

#endif