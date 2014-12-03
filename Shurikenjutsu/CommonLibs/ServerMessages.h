#ifndef SERVERMESSAGES_H_
#define SERVERMESSAGES_H_

#include "..\CommonLibs\RakNet\MessageIdentifiers.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

struct PlayerNet
{
	float x, y, z;
	float dirX, dirY, dirZ;
	RakNet::RakNetGUID guid;
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

struct SpawnPoint
{
	float x, y, z;

	SpawnPoint(float p_x, float p_y, float p_z)
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}
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
	ID_MELEE_ATTACK
};

#endif