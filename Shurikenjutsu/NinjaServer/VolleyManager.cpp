#include "VolleyManager.h"

VolleyManager::VolleyManager(){}
VolleyManager::~VolleyManager(){}

bool VolleyManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;
	return true;
}

void VolleyManager::Shutdown(){}

void VolleyManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		m_volleys[i].timeToLand -= (float)p_deltaTime;
	}
}

void VolleyManager::Add(RakNet::RakNetGUID p_guid, float p_startPosX, float p_startPosZ, float p_endPosX, float p_endPosZ)
{
	float x = p_endPosX - p_startPosX;
	float z = p_endPosZ - p_startPosZ;
	float speedY = sqrtf(VOLLEY_HEIGHT / (2.0f*VOLLEY_GRAVITY));
	float timeToLand = 2.0f*speedY / VOLLEY_GRAVITY;

	VolleyNet temp;
	temp.startX = p_startPosX;
	temp.startZ = p_startPosZ;
	temp.endX = p_endPosX;
	temp.endZ = p_endPosZ;
	temp.id = GetUniqueId();
	temp.guid = p_guid;
	temp.timeToLand = timeToLand;
	temp.playedLandSound = false;
	m_volleys.push_back(temp);
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_VOLLEY_THROWN);
	wBitStream.Write(temp.id);
	wBitStream.Write(temp.startX);
	wBitStream.Write(temp.startZ);
	wBitStream.Write(temp.endX);
	wBitStream.Write(temp.endZ);
	wBitStream.Write(temp.guid);
	
	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void VolleyManager::Remove(int index)
{
	m_volleys.erase(m_volleys.begin() + index);
}

std::vector<VolleyNet> VolleyManager::GetObjects()
{
	return m_volleys;
}

unsigned int VolleyManager::GetUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_volleys.size(); i++)
		{
			if (m_volleys[i].id == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}

float VolleyManager::GetCurrentDistanceFromPlayer()
{
	return m_currentDistanceFromPlayer;
}

void VolleyManager::SetCurrentDistanceFromPlayer(float p_distance)
{
	m_currentDistanceFromPlayer = p_distance;
}
void VolleyManager::ResetLists()
{
	m_volleys.clear();
}
void VolleyManager::PlayedSound(int p_id)
{
	for (unsigned int i = 0; i < m_volleys.size(); i++)
	{
		if (m_volleys[i].id == p_id)
		{
			m_volleys[i].playedLandSound = true;
			break;
		}
	}
}