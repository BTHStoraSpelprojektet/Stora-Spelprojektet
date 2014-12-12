#include "ShurikenManager.h"


ShurikenManager::ShurikenManager()
{
}


ShurikenManager::~ShurikenManager()
{
}

bool ShurikenManager::Initialize(RakNet::RakPeerInterface *p_serverPeer, std::string p_levelName, std::string p_modelName)
{
	m_serverPeer = p_serverPeer;
	m_shurikenSetTimeLeft = 2.0f;

	m_shurikens = std::vector<ShurikenNet>();

	m_boundingBoxes = ModelLibrary::GetInstance()->GetModel(p_modelName)->GetBoundingBoxes();

	return true;
}

void ShurikenManager::Shutdown()
{
}

void ShurikenManager::Update(double p_deltaTime)
{
	UpdateShurikens(p_deltaTime);
}

void ShurikenManager::AddShuriken(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ)
{
	// Check if you can add shuriken
	int count = 0;
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_shurikens[i].guid == p_guid)
		{
			count++;
		}
	}

	// If true then add shuriken
	if (count < 5)
	{
		ShurikenNet shuriken;
		shuriken.x = p_posX;
		shuriken.y = p_posY;
		shuriken.z = p_posZ;
		shuriken.dirX = p_dirX;
		shuriken.dirY = p_dirY;
		shuriken.dirZ = p_dirZ;
		shuriken.shurikenId = GetShurikenUniqueId();
		shuriken.guid = p_guid;
		shuriken.lifeTime = m_shurikenSetTimeLeft;
		shuriken.speed = 20.0f;
		m_shurikens.push_back(shuriken);

		RakNet::BitStream wBitStream;
		wBitStream.Write((RakNet::MessageID)ID_SHURIKEN_THROWN);
		wBitStream.Write(shuriken.x);
		wBitStream.Write(shuriken.y);
		wBitStream.Write(shuriken.z);
		wBitStream.Write(shuriken.dirX);
		wBitStream.Write(shuriken.dirY);
		wBitStream.Write(shuriken.dirZ);
		wBitStream.Write(shuriken.shurikenId);
		wBitStream.Write(shuriken.guid);
		wBitStream.Write(shuriken.speed);

		m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
	}
}

void ShurikenManager::RemoveShuriken(unsigned int p_id)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		if (m_shurikens[i].shurikenId == p_id)
		{
			BroadcastDestoyedShuriken(p_id);
			m_shurikens.erase(m_shurikens.begin() + i);
			break;
		}
	}
}

void ShurikenManager::UpdateShurikens(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_shurikens.size(); i++)
	{
		m_shurikens[i].lifeTime -= (float)p_deltaTime;

		// Check if the time has run out for the shuriken and remove it
		if (m_shurikens[i].lifeTime <= 0)
		{
			// Send removal of shuriken to clients
			BroadcastDestoyedShuriken(m_shurikens[i].shurikenId);

			m_shurikens.erase(m_shurikens.begin() + i);
			i--;
		}
	}
}

void ShurikenManager::BroadcastDestoyedShuriken(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SHURIKEN_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

unsigned int ShurikenManager::GetShurikenUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_shurikens.size(); i++)
		{
			if (m_shurikens[i].shurikenId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}

std::vector<ShurikenNet> ShurikenManager::GetShurikens()
{
	return m_shurikens;
}

float ShurikenManager::GetShurikenPosX(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index > (int)m_shurikens.size() - 1)
	{
		return 0;
	}

	float lifeTime = m_shurikenSetTimeLeft - m_shurikens[p_index].lifeTime;
	return m_shurikens[p_index].x + m_shurikens[p_index].dirX * m_shurikens[p_index].speed * lifeTime;
}

float ShurikenManager::GetShurikenPosY(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_shurikens.size() - 1)
	{
		return 0;
	}

	float lifeTime = m_shurikenSetTimeLeft - m_shurikens[p_index].lifeTime;
	return m_shurikens[p_index].y + m_shurikens[p_index].dirY * m_shurikens[p_index].speed * lifeTime;
}

float ShurikenManager::GetShurikenPosZ(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_shurikens.size() - 1)
	{
		return 0;
	}

	float lifeTime = m_shurikenSetTimeLeft - m_shurikens[p_index].lifeTime;
	return m_shurikens[p_index].z + m_shurikens[p_index].dirZ * m_shurikens[p_index].speed * lifeTime;
}

std::vector<Box> ShurikenManager::GetBoundingBoxes(int p_index)
{
	std::vector<Box> boundingBoxes = std::vector<Box>();

	// Check so index is not out of bounds
	if (p_index < 0 || p_index >(int)m_shurikens.size() - 1)
	{
		return boundingBoxes;
	}

	for (unsigned int i = 0; i < m_boundingBoxes.size(); i++)
	{
		Box box = m_boundingBoxes[i];
		box.m_center.x += GetShurikenPosX(p_index);
		box.m_center.y += GetShurikenPosY(p_index);
		box.m_center.z += GetShurikenPosZ(p_index);

		boundingBoxes.push_back(box);
	}

	return boundingBoxes;
}