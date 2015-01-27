#ifndef NETWORK_H_
#define NETWORK_H_

#define WIN32_LEAN_AND_MEAN


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


enum NETWORKSTATUS
{
	NETWORKSTATUS_CONNECTING,
	NETWORKSTATUS_CONNECTED,
	NETWORKSTATUS_LOST,
	NETWORKSTATUS_TIMEOUT,
	NETWORKSTATUS_NONE
};

class Network
{
public:

	Network(const Network&) = delete;
	Network& operator=(const Network&) = delete;

	static Network* GetInstance();

	bool Initialize();
	void Shutdown();

	void Update();

	void Connect(std::string p_ip);

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

	bool IsSmokeBombListUpdated();
	void SetHaveUpdateSmokeBombList();
	std::vector<SmokeBombNet> GetSmokeBombs();

	bool IsSpikeTrapListUpdated();
	void SetHaveUpdateSpikeTrapList();
	std::vector<SpikeNet> GetSpikeTraps();

	bool HasRespawned();
	void SetHaveRespawned();

	void DoMeleeAttack();
	void SendAbility(ABILITIES p_ability, float p_distanceFromPlayer);

	bool RoundRestarted();
	void SetHaveUpdatedAfterRestartedRound();

	bool NewLevel();
	void SetHaveUpdateNewLevel();
	std::string LevelName();

	NETWORKSTATUS GetNetworkStatus();
	void SetNetworkStatusConnecting();

	void SendAnimationState(AnimationState p_state);
	int AnimationChanged(RakNet::RakNetGUID p_guid);

private:

	void UpdateSpikeTrap(unsigned int p_spikeTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime);
	void RemoveSpikeTrap(unsigned int p_spikeTrapId);
	Network();
	~Network();
	
	static Network* m_instance;

	void ReceviePacket();
	void UpdateSmokeBomb(unsigned int p_smokebombId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime);
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

	void RemoveSmokeBomb(unsigned int p_smokeBombID);
	RakNet::RakPeerInterface *m_clientPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

	bool m_connected;
	bool m_prevConnected;
	

	int m_connectionCount;
	int m_previousCount;

	bool m_newOrRemovedPlayers;
	bool m_shurikenListUpdated;
	bool m_smokebombListUpdated;
	bool m_spikeTrapListUpdated;	
	bool m_respawned;
	bool m_invalidMove;
	bool m_roundRestarted;
	bool m_newLevel;
	std::string m_levelName;
	PlayerNet m_myPlayer;
	std::vector<PlayerNet> m_enemyPlayers;
	std::vector<ShurikenNet> m_shurikensList;
	std::vector<SmokeBombNet> m_smokeBombList;
	std::vector<SpikeNet> m_spikeTrapList;
	std::map<RakNet::RakNetGUID, AnimationState> m_playerAnimations;

	NETWORKSTATUS m_networkStatus;
	std::string m_ip;

};
#endif