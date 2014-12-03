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
#include <vector>

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
	void MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ);
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	void RemovePlayer(RakNet::RakNetGUID p_guid);
	void BroadcastPlayers();
	void RespawnPlayer(RakNet::RakNetGUID p_guid);

	void AddShuriken(RakNet::RakNetGUID, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ);
	void UpdateShurikens(double p_deltaTime);
	void BroadcastDestoyedShuriken(unsigned int p_id);
	unsigned int GetShurikenUniqueId();

	void CheckCollisions();

	RakNet::RakPeerInterface *m_serverPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

	int m_nrOfConnections;
	float m_shurikenSetTimeLeft;
	std::vector<PlayerNet> m_players;
	std::vector<ShurikenNet> m_shurikens;
	std::vector<SpawnPoint> m_spawnPoints;
};

#endif SERVER