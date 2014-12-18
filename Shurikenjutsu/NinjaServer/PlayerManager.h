#ifndef PLAYERMANAGERSERVER_H_
#define PLAYERMANAGERSERVER_H_

#include <iostream>

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerGlobals.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\CommonEnums.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "CollisionManager.h"
#include "ShurikenManager.h"
#include <vector>

class CollisionManager;
class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName);
	void Shutdown();
	void Update(double p_deltaTime);

	std::vector<PlayerNet> GetPlayers();
	std::vector<Box> GetBoundingBoxes(int p_index);
	void AddPlayer(RakNet::RakNetGUID p_guid, int p_nrOfConnections);
	void MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dashed);
	void RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ);	
	void RemovePlayer(RakNet::RakNetGUID p_guid);
	void BroadcastPlayers();
	void RespawnPlayer(RakNet::RakNetGUID p_guid);
	void DamagePlayer(RakNet::RakNetGUID p_guid, int p_damage);
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	int GetPlayerIndex(RakNet::RakNetGUID p_guid);

	int GetPlayerHealth(RakNet::RakNetGUID p_guid);
	void ResetHealth(RakNet::RakNetGUID p_guid);

	void UsedAbility(int p_index, ABILITIES p_ability);
	bool CanUseAbility(int p_index, ABILITIES p_ability);
	void ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_readAbility, CollisionManager &p_collisionManager, ShurikenManager &p_shurikenManager, int p_nrOfConnections);


private:	
	void SendInvalidMessage(RakNet::RakNetGUID p_guid);
	LevelImporter::SpawnPoint GetSpawnPoint(int p_team);
	void UpdateHealth(RakNet::RakNetGUID p_guid, int p_health, bool p_isAlive);

	RakNet::RakPeerInterface *m_serverPeer;

	std::vector<PlayerNet> m_players;
	std::vector<LevelImporter::SpawnPoint> m_spawnPoints;
	std::vector<Box> m_boundingBoxes;

	float m_gcd;
	int m_playerHealth;
};

#endif