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
#include "..\CommonLibs\CommonStructures.h"
#include "..\CommonLibs\NetworkLogger.h"
#include <vector>
#include <map>
#include <DirectXMath.h>
#include "Sound.h"

class ObjectManager;

class Network
{
public:

	Network(const Network&) = delete;
	Network& operator=(const Network&) = delete;

	static Network* GetInstance();

	bool Initialize();
	void InitValues();
	void Shutdown();

	void Update();

	void Connect(std::string p_ip);
	void Disconnect();

	void ChooseChar(int p_charNr, int p_toolNr, int p_team);

	bool ConnectedNow();
	bool IsConnected();

	void SendPlayerPos(float p_x, float p_y, float p_z);
	void SendPlayerDir(float p_dirX, float p_dirY, float p_dirZ);
	void SendLatestPos();
	void SendLatestDir();
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

	bool IsFanListUpdated();
	void SetHaveUpdateFanList();
	std::vector<FanNet> GetFanList();

	bool IsStickyTrapListUpdated();
	void SetHaveUpdateStickyTrapList();
	std::vector<StickyTrapNet> GetStickyTrapList();

	bool HasRespawned();
	void SetHaveRespawned();

	void DoMeleeAttack();
	void SendAbility(ABILITIES p_ability, float p_distanceFromPlayer);

	bool RoundRestarted();
	void SetHaveUpdatedAfterRestartedRound();
	bool RoundRestarting();
	int GetRestartingTimer();
	void SyncTimer();
	bool TimerSynced(double &p_min, double &p_sec);

	bool NewLevel();
	void SetHaveUpdateNewLevel();
	std::string LevelName();

	NETWORKSTATUS GetNetworkStatus();
	void SetNetworkStatusConnecting();

	void SendAnimationState(AnimationState p_state);
	int AnimationChanged(RakNet::RakNetGUID p_guid);

	bool HaveDashed();
	DirectX::XMFLOAT3 GetDashLocation();

	void SetObjectManager(ObjectManager* p_objectManager);
	void AddVolley(unsigned int p_id, float p_startX, float p_startY, float p_endX, float p_endY, RakNet::RakNetGUID p_guid);

	void SyncTeamScore();
	int GetRedTeamScore();
	int GetBlueTeamScore();
	int GetLastWinningTeam();
	
	bool GetMatchOver();
	bool GetRoundOver();
	int GetMatchWinningTeam();

	bool CheckIfNaginataStabAttackIsPerformed();
	void ResetNaginataStabBoolean();

	int GetLastPing();

	DealtDamageStruct GetDealtDamage();

	int GetTeam(RakNet::RakNetGUID p_guid);

	void SetSound(Sound* p_sound);

	void SpawnBloodParticles(RakNet::RakNetGUID p_guid);
	void SpawnBloodParticlesOnPlayers(RakNet::RakNetGUID p_guid);
	std::vector<int> GetBloodParticlesOnPlayers();

	bool IsSuddenDeath();
	int GetSuddenDeathBoxIndex();

	void RuneInvisPickedUp(RakNet::RakNetGUID p_player);

	void SetPlayerName(std::string p_playerName);
	std::string GetPlayerName(RakNet::RakNetGUID p_guid);
	int GetCharNr(RakNet::RakNetGUID p_guid);
	void SetVisiblePlayers(std::vector<RakNet::RakNetGUID> p_visiblePlayers);

	bool IsEnemyVisible(RakNet::RakNetGUID p_guid);

	void RoundOverText();
	void SendSpawnedRunes();
	void PoiText();
	void JoinedPlayerText();

	bool GetPoiSpawned();
	bool GetNewPlayerJoined();
	RakNet::RakString GetJustJoinedPlayerName();
	int GetJustJoinedPlayerTeam();

	PlayerNet GetPlayerByGuid(RakNet::RakNetGUID p_guid);

	void SendLobbyValues(int p_charNr, int p_toolNr, int p_team, bool p_isReady);
	std::vector<LobbyPlayers> GetPlayersInLobby();
	bool IsEveryoneElseReady();
	void SendStartGame();
	bool GetStartGame();

	void SetMyPlayerIsInLobby(bool p_state);
	bool GetMyPlayerIsInLobby();

private:
	void ClearListsAtNewRound();
	void UpdateSpikeTrap(RakNet::RakNetGUID p_guid, unsigned int p_spikeTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime, int p_team);
	void UpdateStickyTrap(RakNet::RakNetGUID p_guid, unsigned int p_stickyTrapId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime);
	void RemoveSpikeTrap(unsigned int p_spikeTrapId);
	void RemoveStickyTrap(unsigned int p_stickyTrapId);
	Network();
	~Network();
	
	static Network* m_instance;

	RakNet::RakString m_justJoinedPlayerName;
	int m_justJoinedPlayerTeam;

	NetworkLogger m_networkLogger;

	void ReceviePacket();
	void UpdateSmokeBomb(unsigned int p_smokebombId, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ, float p_lifetime);
	void UpdatePlayerPos(RakNet::RakNetGUID p_owner, float p_x, float p_y, float p_z);
	void UpdatePlayerPos(int p_id, float p_x, float p_y, float p_z);
	void UpdatePlayerDir(RakNet::RakNetGUID p_owner, float p_dirX, float p_dirY, float p_dirZ);
	void UpdatePlayerDir(int p_id, float p_dirX, float p_dirY, float p_dirZ);

	void UpdatePlayerKD(RakNet::RakNetGUID p_owner, int p_deaths, int p_kills);
	void UpdatePlayerID(RakNet::RakNetGUID p_owner, int p_id);
	void UpdatePlayerTeam(RakNet::RakNetGUID p_owner, int p_team);
	void UpdatePlayerHP(RakNet::RakNetGUID p_guid, float p_currentHP, bool p_isAlive);
	void UpdatePlayerHP(RakNet::RakNetGUID p_guid, float p_maxHP, float p_currentHP, bool p_isAlive);
	void UpdatePlayerChar(RakNet::RakNetGUID p_owner, int p_charNr, int p_toolNr);
	void UpdatePlayerInvis(RakNet::RakNetGUID p_guid, bool p_invis);
	void UpdatePlayerShield(RakNet::RakNetGUID p_guid, float p_shield);
	void UpdatePlayerName(RakNet::RakNetGUID p_guid, RakNet::RakString p_name);
	void CheckForRemovedPlayers(std::vector<RakNet::RakNetGUID> p_playerGuids);
	bool IsGuidInList(std::vector<RakNet::RakNetGUID> p_playerGuids, RakNet::RakNetGUID p_guid);
	void UpdateShurikens(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, bool p_megaShuriken);
	void ProjectileThrown(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_shurikenID, RakNet::RakNetGUID p_guid, float p_speed, int p_projType);
	void RespawnPlayer(float p_x, float p_y, float p_z);
	void RemoveShuriken(unsigned int p_shurikenID);
	void RemoveProjectile(unsigned int p_projId);
	void AddFans(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, unsigned int p_id, RakNet::RakNetGUID p_guid, float p_speed);
	void RemoveFan(unsigned int p_id);
	void UpdateFanLifeTime(unsigned int p_id, float p_lifeTime);
	void RemoveSmokeBomb(unsigned int p_smokeBombID);
	int GUIDToID(RakNet::RakNetGUID p_guid);
	void SendVisiblePlayers();
	void CancelRune(POINTOFINTERESTTYPE p_rune);
	void HandleHealingPOIBool(RakNet::RakNetGUID p_guid, bool p_value);
	void SpawnRune(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z);
	void SpawnRune(POINTOFINTERESTTYPE p_poiType, float p_x, float p_y, float p_z, bool p_makeSound);
	void DespawnRune(POINTOFINTERESTTYPE p_poiType);
	void RunePickedUp(POINTOFINTERESTTYPE p_poiType, RakNet::RakNetGUID p_guid);
	void UpdateShieldValue(RakNet::RakNetGUID p_guid, float p_shieldValue);

	RakNet::RakPeerInterface *m_clientPeer;
	RakNet::SocketDescriptor m_socketDesc;
	RakNet::Packet *m_packet;

	bool m_connected;
	bool m_prevConnected;
	

	int m_connectionCount;
	int m_previousCount;

	bool m_NaginataStabPerformed;
	bool m_newOrRemovedPlayers;
	bool m_shurikenListUpdated;
	bool m_smokebombListUpdated;
	bool m_spikeTrapListUpdated;
	bool m_stickyTrapListUpdated;
	bool m_fanListUpdated;
	bool m_respawned;
	bool m_invalidMove;
	bool m_roundRestarted;
	bool m_restartingRound;
	int m_timeRestarting;
	bool m_newLevel;
	bool m_dashed;
	bool m_timerSynced;
	double m_timerMin;
	double m_timerSec;
	std::string m_levelName;
	PlayerNet m_myPlayer;
	std::vector<PlayerNet> m_enemyPlayers;
	std::vector<ShurikenNet> m_shurikensList;
	std::vector<SmokeBombNet> m_smokeBombList;
	std::vector<SpikeNet> m_spikeTrapList;
	std::vector<StickyTrapNet> m_stickyTrapList;
	std::vector<FanNet> m_fanList;
	std::map<RakNet::RakNetGUID, AnimationState> m_playerAnimations;
	DirectX::XMFLOAT3 m_dashLocation;
	int m_redTeamScore;
	int m_blueTeamScore;
	int m_lastTeamWon;
	bool m_matchOver;
	bool m_roundOver;
	int m_matchWinningTeam;
	std::vector<Sound::SoundEmitter*> runeSoundEmitters;

	NETWORKSTATUS m_networkStatus;
	std::string m_ip;

	ObjectManager* m_objectManager;
	Sound* m_sound;

	double m_timeToPing;
	double m_pingTimer;

	bool m_poiSpawned;
	bool m_newPlayerJoined;

	float m_dealtDamage;
	DirectX::XMFLOAT3 m_dealtDamagePosition;
	bool m_suddenDeath;
	int m_suddenDeathBoxIndex;

	DirectX::XMFLOAT3 m_latestPos;
	DirectX::XMFLOAT3 m_latestDir;
	bool m_sendDir;
	bool m_sendPos;
	double m_timeToSendPos;
	double m_posTimer;
	std::string m_playerName;

	std::vector<int> m_visibleEnemies;
	std::vector<int> m_teamVisibleEnemies;

	std::vector<LobbyPlayers> m_lobbyPlayers;
	bool m_startGame;

	bool m_myPlayerIsInLobby;
};
#endif