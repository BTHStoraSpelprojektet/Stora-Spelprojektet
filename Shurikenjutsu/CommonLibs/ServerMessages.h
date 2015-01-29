#ifndef SERVERMESSAGES_H_
#define SERVERMESSAGES_H_

#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

struct Cooldowns
{
	float shurikenCD;
	float meleeSwingCD;
	float dashCD;
	float megaShurikenCD;
};

struct PlayerNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	RakNet::RakNetGUID guid;
	int team;
	float maxHP;
	float currentHP;
	bool isAlive;
	float gcd;
	Cooldowns cooldownAbilites;
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
	RakNet::RakNetGUID guid;
};
enum Messages
{
	ID_NR_CONNECTIONS = ID_USER_PACKET_ENUM + 1,
	ID_DOWNLOAD_PLAYERS,
	ID_PLAYER_MOVED,
	ID_PLAYER_ROTATED,
	ID_SHURIKEN_THROWN,
	ID_SHURIKEN_REMOVE,
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
	ID_PLAYER_ANIMATION_CHANGED,
	ID_SPIKETRAP_THROW,
	ID_SPIKETRAP_REMOVE
};

#endif