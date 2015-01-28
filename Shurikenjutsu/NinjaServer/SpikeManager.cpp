#include "SpikeManager.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

bool SpikeManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	return true;
}
void SpikeManager::Shutdown(){}
void SpikeManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
	{
		m_spikeTrapList[i].lifeTime -= (float)p_deltaTime;

		if (m_spikeTrapList[i].lifeTime <= 0)
		{
			BroadcastEmptySpikeTraps(m_spikeTrapList[i].spikeId);

			m_spikeTrapList.erase(m_spikeTrapList.begin() + i);
			i--;
		}
	}
}
void SpikeManager::AddSpikeTrap(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ)
{
	float x = p_endPosX - p_startPosX;
	float z = p_endPosZ - p_startPosZ;
	float length = sqrtf(x*x + z*z);
	float angle = angle = asinf((9.82f * length) / (SPIKE_SPEED * SPIKE_SPEED)) * 0.5f;
	float speed = sqrtf((length * 9.82f) / (sinf(2 * angle)));
	float timeToLand = length / (speed * cosf(angle));

	SpikeNet temp;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.spikeId = GetSpikeTrapUniqueId();
	temp.lifeTime = timeToLand;
	m_spikeTrapList.push_back(temp);
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_SPIKETRAP_THROW);
	wBitStream.Write(temp.spikeId);
	wBitStream.Write(temp.startX);
	wBitStream.Write(temp.startZ);
	wBitStream.Write(temp.endX);
	wBitStream.Write(temp.endZ);
	wBitStream.Write(temp.lifeTime);
	
	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
unsigned int SpikeManager::GetSpikeTrapUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_spikeTrapList.size(); i++)
		{
			if (m_spikeTrapList[i].spikeId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}
void SpikeManager::BroadcastEmptySpikeTraps(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SPIKETRAP_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
std::vector<SpikeNet> SpikeManager::GetSpikeTraps()
{
	return m_spikeTrapList;
}

float SpikeManager::GetCurrentDistanceFromPlayer()
{
	return m_currentDistanceFromPlayer;
}
void SpikeManager::SetCurrentDistanceFromPlayer(float p_distance)
{
	m_currentDistanceFromPlayer = p_distance;
}