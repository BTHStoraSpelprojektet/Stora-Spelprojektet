#include "SmokeBombManager.h"


bool SmokeBombManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{

	m_serverPeer = p_serverPeer;

	return true;
}
void SmokeBombManager::Shutdown(){}
void SmokeBombManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
	{
		m_smokeBombs[i].lifeTime -= (float)p_deltaTime;

		if (m_smokeBombs[i].lifeTime <= 0)
		{
			BroadcastEmptySmokeBombs(m_smokeBombs[i].smokeBombId);

			m_smokeBombs.erase(m_smokeBombs.begin() + i);
			i--;
		}
	}
}
void SmokeBombManager::AddSmokeBomb(float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ)
{
	float x = p_endPosX - p_startPosX;
	float z = p_endPosZ - p_startPosZ;
	float length = sqrtf(x*x + z*z);
	float angle = angle = asinf((9.82f * length) / (SMOKEBOMB_SPEED * SMOKEBOMB_SPEED)) * 0.5f;
	float speed = sqrtf((length * 9.82f) / (sinf(2 * angle)));
	float timeToLand = length / (speed * cosf(angle));

	SmokeBombNet temp;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.smokeBombId = GetSmokeBombUniqueId();
	temp.lifeTime = SMOKEBOMB_DURATION + timeToLand;
	m_smokeBombs.push_back(temp);
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_SMOKEBOMB_THROW);
	wBitStream.Write(temp.smokeBombId);
	wBitStream.Write(temp.startX);
	wBitStream.Write(temp.startZ);
	wBitStream.Write(temp.endX);
	wBitStream.Write(temp.endZ);
	wBitStream.Write(temp.lifeTime);


	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

unsigned int SmokeBombManager::GetSmokeBombUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
		{
			if (m_smokeBombs[i].smokeBombId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}
void SmokeBombManager::BroadcastEmptySmokeBombs(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SMOKEBOMB_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
std::vector<SmokeBombNet> SmokeBombManager::GetSmokeBombs()
{
	return m_smokeBombs;
}

float SmokeBombManager::GetCurrentDistanceFromPlayer()
{
	return m_currentDistanceFromPlayer;
}
void SmokeBombManager::SetCurrentDistanceFromPlayer(float p_distance)
{
	m_currentDistanceFromPlayer = p_distance;
}
void SmokeBombManager::ResetLists()
{
	m_smokeBombs.clear();
}