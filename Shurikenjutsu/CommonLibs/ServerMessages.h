#ifndef SERVERMESSAGES_H_
#define SERVERMESSAGES_H_

#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"
#include "..\CommonLibs\RakNet\RakString.h"

struct PlayerNet
{
	RakNet::RakString name;
	float x, y, z;
	float dirX, dirY, dirZ;
	RakNet::RakNetGUID guid;
	int id;
	int team;
	float maxHP;
	float currentHP;
	int charNr;
	int toolNr;
	bool isAlive;
	float gcd;
	float dotDamage;
	float hotHeal;
	bool invis;
	int kills;
	int deaths;
	float shield;
	bool hasHealPOI;
};

struct ShurikenNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	unsigned int shurikenId;
	RakNet::RakNetGUID guid;
	float lifeTime;
	float speed;
	bool megaShuriken;
};

struct ProjectileNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	unsigned int uniqueId;
	int projType;
	RakNet::RakNetGUID guid;
	float lifeTime;
	float speed;
};

struct FanNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	unsigned int id;
	RakNet::RakNetGUID guid;
	float lifeTime;
	float speed;
};

struct SmokeBombNet
{
	unsigned int smokeBombId;
	float startX, startZ, endX, endZ;
	float lifeTime;
};
struct SpikeNet
{
	unsigned int spikeId;
	float startX, startZ, endX, endZ;
	float lifeTime, timeToLand;
	int team;
	RakNet::RakNetGUID guid;
};
struct StickyTrapNet
{
	unsigned int stickyTrapId;
	float startX, startZ, endX, endZ;
	float lifeTime, timeToLand;
	RakNet::RakNetGUID guid;
	int team;
};
struct VolleyNet
{
	unsigned int id;
	float startX, startZ, endX, endZ;
	float timeToLand;
	float speed;
	bool playedLandSound;
	RakNet::RakNetGUID guid;
};

enum NETWORKSTATUS
{
	NETWORKSTATUS_CONNECTING,
	NETWORKSTATUS_CONNECTED,
	NETWORKSTATUS_LOST,
	NETWORKSTATUS_TIMEOUT,
	NETWORKSTATUS_NONE
};

enum Messages
{
	ID_NR_CONNECTIONS = ID_USER_PACKET_ENUM + 1,
	ID_LEVELNAME,
	ID_DOWNLOAD_PLAYERS,
	ID_PLAYER_MOVED,
	ID_PLAYER_ROTATED,
	ID_SHURIKEN_THROWN,
	ID_SHURIKEN_REMOVE,
	ID_PROJECTILE_THROWN,
	ID_PROJECTILE_REMOVE,
	ID_RESPAWN_PLAYER,
	ID_MELEE_ATTACK,
	ID_PLAYER_INVALID_MOVE,
	ID_PLAYER_HP_CHANGED,
	ID_ABILITY,
	ID_ROUND_OVER,
	ID_RESTARTED_ROUND,
	ID_RESTARTING_ROUND,
	ID_RESTARTING_ROUND_TIMER,
	ID_SMOKEBOMB_THROW,
	ID_SMOKEBOMB_REMOVE,
	ID_MATCH_OVER,
	ID_NEW_LEVEL,
	ID_START_GAME,
	ID_PLAYER_ANIMATION_CHANGED,
	ID_SPIKETRAP_THROW,
	ID_SPIKETRAP_REMOVE,
	ID_DASH_TO_LOCATION,
	ID_CHOOSE_CHAR,
	ID_CONNECTION_NOTIFICATION,
	ID_FAN_THROWN,
	ID_FAN_REMOVE,
	ID_FAN_UPDATE,
	ID_FAN_DEAD_UPDATE,
	ID_VOLLEY_THROWN,
	ID_TIMER_SYNC,
	ID_STICKYTRAP_THROW,
	ID_STICKYTRAP_REMOVE,
	ID_SEND_TEAM_SCORE,
	ID_NAGINATA_STAB_HAS_OCCURED,
	ID_HAS_INFLICTED_DAMAGE,
	ID_PLAYER_MOVE_AND_ROTATE,
	ID_DEATHBOARDKILL,
	ID_PLAY_SOUND_ABILITY,
	ID_PLAY_SOUND,
	ID_PLAY_AMBIENT_SOUND,
	ID_STOP_AMBIENT_SOUND,
	ID_SEND_SUDDEN_DEATH,
	ID_INITIATE_SUDDEN_DEATH_BOX,
	ID_SCOREBOARDKILL,
	ID_SPAWN_3_RUNES,
	ID_SPAWN_SINGLE_RUNE,
	ID_DESPAWN_RUNE,
	ID_DOWNLOAD_RUNES,
	ID_RUNE_PICKED_UP,
	ID_LOTUS_PICKED_UP,
	ID_SHIELD_PICKED_UP,
	ID_INVIS_PICKED_UP,
	ID_RUNE_SHIELD_CANCEL,
	ID_RUNE_INVIS_CANCEL,
	ID_SEND_VISIBLE_PLAYERS,
	ID_POI_HEALING_BOOL,
	ID_SHIELD_UPDATE,
	ID_THROW_FLASHGRENADE,
	ID_LOBBY_CHOOSE
};

#endif