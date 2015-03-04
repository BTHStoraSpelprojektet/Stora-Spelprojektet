#ifndef PLAYERMANAGERSERVER_H_
#define PLAYERMANAGERSERVER_H_

#include <iostream>
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "..\CommonLibs\CommonEnums.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "CollisionManager.h"
#include "ShurikenManager.h"
#include "SmokeBombManager.h"
#include <vector>

class FanBoomerangManager;
class SpikeManager;
class CollisionManager;
class ProjectileManager;
class StickyTrapManager;
class VolleyManager;

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
	void AddPlayer(RakNet::RakNetGUID p_guid, RakNet::RakString p_name, int p_charNr, int p_toolNr, int p_team);
	bool MovePlayer(RakNet::RakNetGUID p_guid, float p_x, float p_y, float p_z, int p_nrOfConnections, bool p_dashed);
	bool RotatePlayer(RakNet::RakNetGUID p_guid, float p_dirX, float p_dirY, float p_dirZ);	
	void RemovePlayer(RakNet::RakNetGUID p_guid);
	void BroadcastPlayers();
	void RespawnPlayer(RakNet::RakNetGUID p_guid);
	void DamagePlayer(RakNet::RakNetGUID p_defendingGuid, float p_damage, RakNet::RakNetGUID p_attackingGuid, ABILITIES p_usedAbility, bool p_suddenDeathDamage);
	bool CanSendDotDamage();
	PlayerNet GetPlayer(RakNet::RakNetGUID p_guid);
	int GetPlayerIndex(RakNet::RakNetGUID p_guid);

	float GetPlayerHealth(RakNet::RakNetGUID p_guid);
	void ResetHealth(RakNet::RakNetGUID p_guid);

	void UsedAbility(int p_index, ABILITIES p_ability);
	bool CanUseAbility(int p_index, ABILITIES p_ability);
	void NaginataStabAttackPerformed(RakNet::RakNetGUID p_guid);

	void ExecuteAbility(float p_deltaTime, RakNet::RakNetGUID p_guid, ABILITIES p_readAbility, CollisionManager &p_collisionManager, ShurikenManager &p_shurikenManager, SmokeBombManager &p_smokebomb, SpikeManager &p_spikeTrap, FanBoomerangManager &p_fanBoomerang, ProjectileManager &p_projectileManager, StickyTrapManager &p_stickyTrapManager, VolleyManager &p_volleyManager);
	void SendPlaySound(ABILITIES ability, float p_x, float p_y, float p_z);
	void SendPlaySound(PLAYSOUND sound, float p_x, float p_y, float p_z);
	void SendDealtDamage(RakNet::RakNetGUID p_attackingPlayerGUID, float p_damage, float p_x, float p_y, float p_z);
	void SetPlayerDotDamage(RakNet::RakNetGUID p_guid, float p_damage);
	
	void DeathBoard(int p_TakerNinja, int p_AttackerNinja, ABILITIES p_usedAbility);
	void ScoreBoard(RakNet::RakNetGUID p_deadID, RakNet::RakNetGUID p_killerID);

	void RuneLotusPickedUp(RakNet::RakNetGUID p_player);
	void HealPlayer();
	void RuneInvisPickedUp(RakNet::RakNetGUID p_player);

private:	
	void SendInvalidMessage(RakNet::RakNetGUID p_guid);
	LevelImporter::SpawnPoint GetSpawnPoint(int p_team);
	void UpdateHealth(RakNet::RakNetGUID p_guid, float p_health, bool p_isAlive);
	void UpdateHealth(RakNet::RakNetGUID p_guid, float p_health, bool p_isAlive, bool p_sendReliable);
	
	int GetTeamForPlayer();
	int GetIdForPlayer();

	RakNet::RakPeerInterface *m_serverPeer;

	std::vector<PlayerNet> m_players;
	std::vector<LevelImporter::SpawnPoint> m_spawnPoints;
	std::vector<Box> m_katanaBoundingBoxes;
	std::vector<Box> m_tessenBoundingBoxes;
	std::vector<Box> m_naginataBoundingBoxes;

	//float m_gcd;
	float m_playerHealth;

	void SendPlayerPos();
	void SendPlayerDir();
	void SendPlayerPosAndDir();
	double m_sendIntervall;
	double m_lastTimeSent;
	
	bool m_canSendDotDamage;
	bool m_haveSentDotDamage;
	double m_dotIntervall;
	double m_lastDotSent;
	
	double m_hotIntervall;
	double m_lastHotSent;
	bool m_canSendHotDamage;
	bool m_haveSentHotDamage;
};

#endif