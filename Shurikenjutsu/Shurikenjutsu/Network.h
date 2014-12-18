#ifndef NETWORK_H_
#define NETWORK_H_

#define WIN32_LEAN_AND_MEAN

#include <iostream>

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
#include "..\CommonLibs\CommonEnums.h"
#include <vector>
#include <map>

#include "ConsoleFunctions.h"

class Network
{
public:

	Network(const Network&) = delete;
	Network& operator=(const Network&) = delete;

	static Network* GetInstance();

	bool Initialize();
	void Shutdown();

	void Update();

	bool ConnectedNow();
	bool IsConnected();

	void SendPlayerPos(float p_x, float p_y, float p_z);
	void SendPlayerDir(float p_dirX, float p_dirY, float p_dirZ);
	std::vector<PlayerNet> GetOtherPlayers();
	PlayerNet GetMyPlayer();
	void AddShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ);
	std::vector <ShurikenNet> GetShurikens();
	bool MadeInvalidMove();
	void UpdatedMoveFromInvalidMove();

	RakNet::RakNetGUID GetMyGUID();
	bool IsPlayerListUpdated();
	void SetHaveUpdatedPlayerList();

	bool IsShurikenListUpdated();
	void SetHaveUpdateShurikenList();

	bool HasRespawned();
	void SetHaveRespawned();

	void DoMeleeAttack();
	void SendAbility(ABILITIES p_ability);

	bool RoundRestarted();
	void SetHaveUpdatedAfterRestartedRound();

	bool NewLevel();
	void SetHaveUpdateNewLevel();
	std::string LevelName();

private:
	Network();
	~Network();
	
	static Network* m_instance;

	void ReceviePacket();
	void UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z);
	void UpdatePlayerDir(RakNet::RakNetGUID p_owner, float p_dirX, float p_dirY, float p_dirZ);
	void UpdatePlayerTeam(RakNet::RakNetGUID p_owner, int p_team);
	void UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_currentHP, bool p_isAlive);
	void UpdatePlayerHP(RakNet::RakNetGUID p_guid, int p_maxHP, int p_currentHP, bool p_isAlive);
	void CheckForRemovedPlayers(std::vector<RakNet::RakNetGUID> p_playerGuids);
	bool IsGuidInList(std::vector<RakNet::RakNetGUID> p_playerGuids, RakNet::RakNetGUID p_guid);
	void UpdateShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, bool p_megaShuriken);
	void RespawnPlayer(float p_x, float p_y, float p_z);
	void RemoveShuriken(unsigned int p_shurikenID);

	RakNet::RakPeerInterface *m_clientPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

	bool m_connected;
	bool m_prevConnected;

	int m_connectionCount;
	int m_previousCount;

	bool m_newOrRemovedPlayers;
	bool m_shurikenListUpdated;
	bool m_respawned;
	bool m_invalidMove;
	bool m_roundRestarted;
	bool m_newLevel;
	std::string m_levelName;
	PlayerNet m_myPlayer;
	std::vector<PlayerNet> m_enemyPlayers;
	std::vector<ShurikenNet> m_shurikensList;

};
#endif