#include "FanBoomerangManager.h"
#include "..\CommonLibs\ModelNames.h"

FanBoomerangManager::FanBoomerangManager(){}
FanBoomerangManager::~FanBoomerangManager(){}

bool FanBoomerangManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	m_fans = std::vector<FanNet>();

	m_boundingBoxes = ModelLibrary::GetInstance()->GetModel(FANBOOMERANG_MODEL_NAME)->GetBoundingBoxes();

	m_sendIntervall = 0.02;
	m_lastTimeSent = 0.0;
	
	return true;
}

void FanBoomerangManager::Shutdown()
{

}

void FanBoomerangManager::Update(double p_deltaTime, PlayerManager* p_playerManager)
{
	std::vector<PlayerNet> players = p_playerManager->GetPlayers();

	// Update all the fans
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		float previousLifeTime = m_fans[i].lifeTime;
		m_fans[i].lifeTime -= (float)p_deltaTime;
		if (m_fans[i].lifeTime > 0)
		{
			m_fans[i].x += m_fans[i].dirX*m_fans[i].speed*(float)p_deltaTime;
			m_fans[i].y += m_fans[i].dirY*m_fans[i].speed*(float)p_deltaTime;
			m_fans[i].z += m_fans[i].dirZ*m_fans[i].speed*(float)p_deltaTime;
		}
		else
		{
			if (previousLifeTime >= 0)
			{
				BroadcastLifetime(m_fans[i].id, m_fans[i].lifeTime);
			}
			for (unsigned int j = 0; j < players.size(); j++)
			{
				if (m_fans[i].guid == players[j].guid)
				{
					// Calculate new direction
					float dirX = m_fans[i].x - players[j].x;
					float dirZ = m_fans[i].z - players[j].z;
					float length = sqrt(dirX*dirX + dirZ*dirZ);

					dirX /= length;
					dirZ /= length;

					m_fans[i].dirX = dirX;
					m_fans[i].dirZ = dirZ;

					m_fans[i].x += m_fans[i].dirX*m_fans[i].speed*(float)-p_deltaTime;
					m_fans[i].y += m_fans[i].dirY*m_fans[i].speed*(float)-p_deltaTime;
					m_fans[i].z += m_fans[i].dirZ*m_fans[i].speed*(float)-p_deltaTime;
				}
			}
		}
	}
}

void FanBoomerangManager::Add(float p_deltaTime, RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ)
{
	FanNet fan;
	fan.x = p_posX + p_dirX;
	fan.y = p_posY;
	fan.z = p_posZ + p_dirZ;
	fan.dirX = p_dirX;
	fan.dirY = p_dirY;
	fan.dirZ = p_dirZ;
	fan.id = GetUniqueId();
	fan.guid = p_guid;
	fan.lifeTime = FANBOOMERANG_DURATION;
	fan.speed = FANBOOMERANG_SPEED;
	m_fans.push_back(fan);

	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_FAN_THROWN);
	wBitStream.Write(fan.x);
	wBitStream.Write(fan.y);
	wBitStream.Write(fan.z);
	wBitStream.Write(fan.dirX);
	wBitStream.Write(fan.dirY);
	wBitStream.Write(fan.dirZ);
	wBitStream.Write(fan.id);
	wBitStream.Write(fan.guid);
	wBitStream.Write(fan.speed);

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void FanBoomerangManager::Remove(unsigned int p_id)
{
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		if (m_fans[i].id == p_id)
		{
			BroadcastDestoyed(p_id);
			m_fans.erase(m_fans.begin() + i);
			break;
		}
	}
}

void FanBoomerangManager::UpdateClients()
{
	int nrOfFans = m_fans.size();

	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_FAN_UPDATE);
	bitStream.Write(nrOfFans);

	for (int i = 0; i < nrOfFans; i++)
	{
		bitStream.Write(m_fans[i].id);
		bitStream.Write(m_fans[i].x);
		bitStream.Write(m_fans[i].z);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

std::vector<FanNet> FanBoomerangManager::GetObjects()
{
	return m_fans;
}

std::vector<Box> FanBoomerangManager::GetBoundingBoxes(int p_index)
{
	std::vector<Box> boundingBoxes = std::vector<Box>();

	// Check so index is not out of bounds
	if (p_index < 0 || p_index >(int)m_fans.size() - 1)
	{
		return boundingBoxes;
	}

	for (unsigned int i = 0; i < m_boundingBoxes.size(); i++)
	{
		Box box = m_boundingBoxes[i];
		box.m_center.x += GetPosX(p_index);
		box.m_center.y += GetPosY(p_index);
		box.m_center.z += GetPosZ(p_index);

		boundingBoxes.push_back(box);
	}

	return boundingBoxes;
}

float FanBoomerangManager::GetPosX(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_fans.size() - 1)
	{
		return 0;
	}

	return m_fans[p_index].x;
}

float FanBoomerangManager::GetPosY(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_fans.size() - 1)
	{
		return 0;
	}

	return m_fans[p_index].y;
}

float FanBoomerangManager::GetPosZ(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_fans.size() - 1)
	{
		return 0;
	}

	return m_fans[p_index].z;
}

void FanBoomerangManager::BroadcastDestoyed(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_FAN_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

unsigned int FanBoomerangManager::GetUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_fans.size(); i++)
		{
			if (m_fans[i].id == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}

float FanBoomerangManager::SetLifeTime(int p_index, float p_lifeTime)
{
	return m_fans[p_index].lifeTime = p_lifeTime;
}

void FanBoomerangManager::ResetLists()
{
	m_fans.clear();
}

void FanBoomerangManager::BroadcastLifetime(unsigned int p_id, float p_lifeTime)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_FAN_DEAD_UPDATE);
	bitStream.Write(p_id);
	bitStream.Write(p_lifeTime);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}