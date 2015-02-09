#include "StickyTrapManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

bool StickyTrapManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	return true;
}
void StickyTrapManager::Shutdown(){}
void StickyTrapManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
	{
		m_stickyTrapList[i].lifeTime -= (float)p_deltaTime;
		m_stickyTrapList[i].timeToLand -= (float)p_deltaTime;

		if (m_stickyTrapList[i].lifeTime <= 0)
		{
			BroadcastEmptyStickyTraps(m_stickyTrapList[i].stickyTrapId);

			m_stickyTrapList.erase(m_stickyTrapList.begin() + i);
			i--;
		}
	}
}
void StickyTrapManager::AddStickyTrap(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ)
{
	float x = p_endPosX - p_startPosX;
	float z = p_endPosZ - p_startPosZ;
	float length = sqrtf(x*x + z*z);
	float angle = angle = asinf((9.82f * length) / (STICKY_TRAP_SPEED * STICKY_TRAP_SPEED)) * 0.5f;
	float speed = sqrtf((length * 9.82f) / (sinf(2 * angle)));
	float timeToLand = length / (speed * cosf(angle));

	StickyTrapNet temp;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.stickyTrapId = GetSpikeTrapUniqueId();
	temp.lifeTime = STICKY_TRAP_DURATION + timeToLand;
	temp.guid = p_guid;
	temp.timeToLand = timeToLand;
	m_stickyTrapList.push_back(temp);
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_STICKYTRAP_THROW);
	wBitStream.Write(temp.stickyTrapId);
	wBitStream.Write(temp.startX);
	wBitStream.Write(temp.startZ);
	wBitStream.Write(temp.endX);
	wBitStream.Write(temp.endZ);
	wBitStream.Write(temp.lifeTime);
	wBitStream.Write(temp.guid);

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
unsigned int StickyTrapManager::GetSpikeTrapUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_stickyTrapList.size(); i++)
		{
			if (m_stickyTrapList[i].stickyTrapId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}
void StickyTrapManager::BroadcastEmptyStickyTraps(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_STICKYTRAP_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
std::vector<StickyTrapNet> StickyTrapManager::GetStickyTraps()
{
	return m_stickyTrapList;
}

float StickyTrapManager::GetCurrentDistanceFromPlayer()
{
	return m_currentDistanceFromPlayer;
}
void StickyTrapManager::SetCurrentDistanceFromPlayer(float p_distance)
{
	m_currentDistanceFromPlayer = p_distance;
}