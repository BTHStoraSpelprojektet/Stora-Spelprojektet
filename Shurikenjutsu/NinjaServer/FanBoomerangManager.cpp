#include "FanBoomerangManager.h"
#include "..\CommonLibs\ModelNames.h"

FanBoomerangManager::FanBoomerangManager(){}
FanBoomerangManager::~FanBoomerangManager(){}

bool FanBoomerangManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	m_fans = std::vector<FanNet>();

	m_boundingBoxes = ModelLibrary::GetInstance()->GetModel(SMOKE_BOMB)->GetBoundingBoxes();
	
	return true;
}

void FanBoomerangManager::Shutdown()
{

}

void FanBoomerangManager::Update(double p_deltaTime)
{
	// Update all the fans
	for (unsigned int i = 0; i < m_fans.size(); i++)
	{
		// Update life, it sucks
		if (m_fans[i].lifeTime > 0)
		{
			m_fans[i].lifeTime -= (float)p_deltaTime;
			m_fans[i].x += m_fans[i].dirX*m_fans[i].speed*(float)p_deltaTime;
			m_fans[i].y += m_fans[i].dirY*m_fans[i].speed*(float)p_deltaTime;
			m_fans[i].z += m_fans[i].dirZ*m_fans[i].speed*(float)p_deltaTime;
		}
		else
		{
			m_fans[i].x += m_fans[i].dirX*m_fans[i].speed*(float)-p_deltaTime;
			m_fans[i].y += m_fans[i].dirY*m_fans[i].speed*(float)-p_deltaTime;
			m_fans[i].z += m_fans[i].dirZ*m_fans[i].speed*(float)-p_deltaTime;
		}
		
	}

	UpdateClients();
}

void FanBoomerangManager::Add(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ)
{
	FanNet fan;
	fan.x = p_posX;
	fan.y = p_posY;
	fan.z = p_posZ;
	fan.dirX = p_dirX;
	fan.dirY = p_dirY;
	fan.dirZ = p_dirZ;
	fan.id = GetUniqueId();
	fan.guid = p_guid;
	fan.lifeTime = 3.0f;
	fan.speed = SHURIKEN_SPEED;
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

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
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
		bitStream.Write(m_fans[i].y);
		bitStream.Write(m_fans[i].z);
		bitStream.Write(m_fans[i].dirX);
		bitStream.Write(m_fans[i].dirY);
		bitStream.Write(m_fans[i].dirZ);
		bitStream.Write(m_fans[i].speed);
	}

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
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

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
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