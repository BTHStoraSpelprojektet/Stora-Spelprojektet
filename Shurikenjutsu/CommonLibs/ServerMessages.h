#ifndef SERVERMESSAGES_H_
#define SERVERMESSAGES_H_

#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

struct PlayerNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	RakNet::RakNetGUID guid;
	int team;
	int maxHP;
	int currentHP;
	float gcd;
};

struct ShurikenNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	unsigned int shurikenId;
	RakNet::RakNetGUID guid;
	float lifeTime;
	float speed;
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
	ID_ABILITY
};

#endif