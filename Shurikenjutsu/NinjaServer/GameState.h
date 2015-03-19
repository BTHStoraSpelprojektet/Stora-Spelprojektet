#ifndef GAMESTATESERVER_H_
#define GAMESTATESERVER_H_

#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "PlayerManager.h"
#include "ShurikenManager.h"
#include "..\CommonLibs\ModelNames.h"
#include "FanBoomerangManager.h"
#include <map>

class MapManager;
class CollisionManager;
class SpikeManager;
class ProjectileManager;
class VolleyManager;
class StickyTrapManager;
class PointOfInterestManager;

class GameState
{
public:
	GameState();
	~GameState();

	virtual bool Initialize(RakNet::RakPeerInterface *p_serverPeer, std::vector<std::string> p_levelsName, int p_currentLevel);
	virtual bool Initialize(int p_currentLevel);
	virtual void Shutdown();
	virtual void Update(double p_deltaTime);
	
public:
	void AddPlayer(RakNet::RakNetGUID p_guid, RakNet::RakString p_name, int p_charNr, int p_toolNr, int p_team);
	void RemovePlayer(RakNet::RakNetGUID p_guid);
	bool MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dash);
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	int GetPlayerIndex(RakNet::RakNetGUID p_guid);
	bool RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ);
	void ExecuteAbility(RakNet::RakNetGUID p_guid, ABILITIES p_ability, float p_distanceFromPlayer);
	void BroadcastPlayers();
	void SyncTime(RakNet::RakNetGUID p_guid);
	void SendCurrentTeamScore(RakNet::RakNetGUID p_guid);
	void UserConnected(RakNet::RakNetGUID p_guid);


	void UpdatePlayerVisibility(RakNet::RakNetGUID p_guid, std::vector<int> p_visiblePlayers);
	void AbilityUsedCancelInvis(RakNet::RakNetGUID p_guid);

	void SendCurrentRunes(RakNet::RakNetGUID p_guid);

	void SetPlayerInLobby(RakNet::RakNetGUID p_guid, int p_charNr, int p_toolNr, int p_team, std::string p_name, bool p_isReady);
	void SendStartGame();

protected:
	void UpdateTime(double p_deltaTime);
	void ResetTime();

	void SendSuddenDeathMessage(bool p_isSuddenDeath);

	RakNet::RakPeerInterface* m_serverPeer;
	PlayerManager* m_playerManager;
	ShurikenManager* m_shurikenManager;
	SmokeBombManager* m_smokeBombManager;
	SpikeManager *m_spikeManager;
	MapManager* m_mapManager;
	CollisionManager* m_collisionManager;
	FanBoomerangManager* m_fanBoomerangManager;
	ProjectileManager* m_projectileManager;
	StickyTrapManager* m_stickyTrapManager;
	VolleyManager* m_volleyManager;
	PointOfInterestManager* m_POIManager;

	std::map<int, int> m_winningTeams;
	double m_timeMin;
	double m_timeSec;
	bool m_roundRestarting;
	bool m_isSuddenDeath;
	float m_suddenDeathTimer;
	float m_suddenDeathMaxBoxExtentX;
	float m_suddenDeathMaxBoxExtentZ;
	bool m_runesSpawned;
	bool m_runeRespawn;
	float m_deltaTime;
	float m_shieldActiveTimer;
	float m_invisActiveTimer;

	std::vector<std::string> m_levelsName;
	unsigned int m_currentLevel;
};

#endif