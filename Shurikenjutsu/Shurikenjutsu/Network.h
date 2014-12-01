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
#include <map>

#include "ConsoleFunctions.h"

class Network
{
public:

	static bool Initialize();
	static void Shutdown();

	static void Update();

	static bool ConnectedNow();
	static bool IsConnected();

	static void SendPlayerPos(float p_x, float p_y, float p_z);
	static std::vector<PlayerNet> GetOtherPlayers();
	static PlayerNet GetMyPlayer();
	static void AddShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ);
	static std::vector <ShurikenNet> GetShurikens();
	static std::vector < ShurikenNet > m_shurikensList;

	static RakNet::RakNetGUID GetMyGUID();
	static bool IsPlayerListUpdated();
	static void SetHaveUpdatedPlayerList();

	static bool IsShurikenListUpdated();
	static void SetHaveUpdateShurikenList();

private:
	Network() {};
	static void ReceviePacket();
	static void UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z);
	static void CheckForRemovedPlayers(std::vector<RakNet::RakNetGUID> p_playerGuids);
	static bool IsGuidInList(std::vector<RakNet::RakNetGUID> p_playerGuids, RakNet::RakNetGUID p_guid);
	static void UpdateShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid);
	static void RemoveShuriken(unsigned int p_shurikenID);

	static RakNet::RakPeerInterface *m_clientPeer;
	static RakNet::SocketDescriptor m_socketDesc;
	static RakNet::Packet *m_packet;

	static bool m_connected;
	static bool m_prevConnected;
	static int m_connectionCount;
	static bool m_newOrRemovedPlayers;
	static bool m_shurikenListUpdated;
	static PlayerNet m_myPlayer;
	static std::vector<PlayerNet> m_enemyPlayers;
	
	
};

#endif