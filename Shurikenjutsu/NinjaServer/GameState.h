#ifndef GAMESTATESERVER_H_
#define GAMESTATESERVER_H_

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "PlayerManager.h"
#include "ShurikenManager.h"
#include "..\CommonLibs\ModelNames.h"
#include "FanBoomerangManager.h"

class MapManager;
class CollisionManager;
class SpikeManager;
class ProjectileManager;

class GameState
{
public:
	GameState();
	~GameState();

	virtual bool Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName);
	virtual bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	virtual bool Initialize(std::string p_levelName);
	virtual void Shutdown();
	virtual void Update(double p_deltaTime);
	
public:
	void AddPlayer(RakNet::RakNetGUID p_guid, int p_charNr);
	void RemovePlayer(RakNet::RakNetGUID p_guid);
	bool MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dash);
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	int GetPlayerIndex(RakNet::RakNetGUID p_guid);
	bool RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ);
	bool CanUseAbility(int p_index, ABILITIES p_ability);
	void UsedAbility(int p_index, ABILITIES p_ability);
	void ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_ability, float p_distanceFromPlayer);
	void BroadcastPlayers();
protected:
	RakNet::RakPeerInterface* m_serverPeer;
	PlayerManager* m_playerManager;
	ShurikenManager* m_shurikenManager;
	SmokeBombManager* m_smokeBombManager;
	SpikeManager *m_spikeManager;
	MapManager* m_mapManager;
	CollisionManager* m_collisionManager;
	FanBoomerangManager* m_fanBoomerangManager;
	ProjectileManager* m_projectileManager;
};

#endif