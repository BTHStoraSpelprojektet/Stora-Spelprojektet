#include "ProjectileManager.h"
#include "../CommonLibs/ModelNames.h"

ProjectileManager::ProjectileManager()
{
}


ProjectileManager::~ProjectileManager()
{
}

bool ProjectileManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	m_projectiles = std::vector<ProjectileNet>();

	m_shurikenBoundingBoxes = ModelLibrary::GetInstance()->GetModel(SHURIKEN_MODEL_NAME)->GetBoundingBoxes();
	m_megaShurikenBoundingBoxes = ModelLibrary::GetInstance()->GetModel(MEGA_SHURIKEN_MODEL_NAME)->GetBoundingBoxes();
	m_kunaiBoundingBoxes = ModelLibrary::GetInstance()->GetModel(KUNAI_MODEL_NAME)->GetBoundingBoxes();

	return true;
}

void ProjectileManager::Shutdown()
{

}

void ProjectileManager::Update(double p_deltaTime)
{
	UpdateProjectiles(p_deltaTime);
}

void ProjectileManager::UpdateProjectiles(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i].lifeTime -= (float)p_deltaTime;

		// Check if the time has run out for the shuriken and remove it
		if (m_projectiles[i].lifeTime <= 0)
		{
			// Send removal of shuriken to clients
			BroadcastDestoyedProjectile(m_projectiles[i].uniqueId);

			m_projectiles.erase(m_projectiles.begin() + i);
			i--;
		}
	}
}

void ProjectileManager::AddProjectile(RakNet::RakNetGUID p_guid, float p_posX, float p_posY, float p_posZ, float p_dirX, float p_dirY, float p_dirZ, int p_ability)
{
	switch (p_ability)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}

	ProjectileNet tempProj;
	tempProj.x = p_posX;
	tempProj.y = p_posY;
	tempProj.z = p_posZ;
	tempProj.dirX = p_dirX;
	tempProj.dirY = p_dirY;
	tempProj.dirZ = p_dirZ;
	tempProj.uniqueId = GetProjectileUniqueId();
	tempProj.projType = 2;
	tempProj.guid = p_guid;
	tempProj.lifeTime = KUNAI_DURATION;
	tempProj.speed = KUNAI_SPEED;
	m_projectiles.push_back(tempProj);

	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PROJECTILE_THROWN);
	wBitStream.Write(tempProj.x);
	wBitStream.Write(tempProj.y);
	wBitStream.Write(tempProj.z);
	wBitStream.Write(tempProj.dirX);
	wBitStream.Write(tempProj.dirY);
	wBitStream.Write(tempProj.dirZ);
	wBitStream.Write(tempProj.projType);
	wBitStream.Write(tempProj.uniqueId);
	wBitStream.Write(tempProj.guid);
	wBitStream.Write(tempProj.speed);

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

unsigned int ProjectileManager::GetProjectileUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_projectiles.size(); i++)
		{
			if (m_projectiles[i].uniqueId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}

void ProjectileManager::RemoveProjectile(unsigned int p_id)
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		if (m_projectiles[i].uniqueId == p_id)
		{
			BroadcastDestoyedProjectile(p_id);
			m_projectiles.erase(m_projectiles.begin() + i);
			break;
		}
	}
}

void ProjectileManager::BroadcastDestoyedProjectile(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PROJECTILE_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, UNRELIABLE, 3, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

std::vector<ProjectileNet> ProjectileManager::GetProjectiles()
{
	return m_projectiles;
}

std::vector<Box> ProjectileManager::GetKunaiBoundingBoxes(int p_index)
{
	std::vector<Box> boundingBoxes = std::vector<Box>();

	// Check so index is not out of bounds
	if (p_index < 0 || p_index >(int)m_projectiles.size() - 1)
	{
		return boundingBoxes;
	}

	for (unsigned int i = 0; i < m_kunaiBoundingBoxes.size(); i++)
	{
		Box box = m_kunaiBoundingBoxes[i];
		box.m_center.x += GetProjectilePosX(p_index);
		box.m_center.y += GetProjectilePosY(p_index);
		box.m_center.z += GetProjectilePosZ(p_index);

		boundingBoxes.push_back(box);
	}

	return boundingBoxes;
}

float ProjectileManager::GetProjectilePosX(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_projectiles.size() - 1)
	{
		return 0;
	}

	float setTimeLeft = m_projectiles[p_index].projType == 1 ? MEGASHURIKEN_DURATION : SHURIKEN_DURATION;
	if (m_projectiles[p_index].projType == 2)
		setTimeLeft = KUNAI_DURATION;
	float lifeTime = setTimeLeft - m_projectiles[p_index].lifeTime;
	return m_projectiles[p_index].x + m_projectiles[p_index].dirX * m_projectiles[p_index].speed * lifeTime;
}

float ProjectileManager::GetProjectilePosY(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_projectiles.size() - 1)
	{
		return 0;
	}

	float setTimeLeft = m_projectiles[p_index].projType == 1 ? MEGASHURIKEN_DURATION : SHURIKEN_DURATION;
	if (m_projectiles[p_index].projType == 2)
		setTimeLeft = KUNAI_DURATION;
	float lifeTime = setTimeLeft - m_projectiles[p_index].lifeTime;
	return m_projectiles[p_index].y + m_projectiles[p_index].dirY * m_projectiles[p_index].speed * lifeTime;
}

float ProjectileManager::GetProjectilePosZ(int p_index)
{
	// Check the index value is in the range of the vector
	if (p_index < 0 || p_index >(int)m_projectiles.size() - 1)
	{
		return 0;
	}

	float setTimeLeft = m_projectiles[p_index].projType == 1 ? MEGASHURIKEN_DURATION : SHURIKEN_DURATION;
	if (m_projectiles[p_index].projType == 2)
		setTimeLeft = KUNAI_DURATION;
	float lifeTime = setTimeLeft - m_projectiles[p_index].lifeTime;
	return m_projectiles[p_index].z + m_projectiles[p_index].dirZ * m_projectiles[p_index].speed * lifeTime;
}

void ProjectileManager::ResetLists()
{
	m_projectiles.clear();
}