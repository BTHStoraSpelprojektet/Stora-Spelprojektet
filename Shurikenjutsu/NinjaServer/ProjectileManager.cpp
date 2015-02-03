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
	for (unsigned int i = 0; i < m_Projectiles.size(); i++)
	{
		m_Projectiles[i].lifeTime -= (float)p_deltaTime;

		// Check if the time has run out for the shuriken and remove it
		if (m_Projectiles[i].lifeTime <= 0)
		{
			// Send removal of shuriken to clients
			BroadcastDestoyedProjectile(m_Projectiles[i].projId);

			m_Projectiles.erase(m_Projectiles.begin() + i);
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
	tempProj.x = p_posX;
	tempProj.y = p_posY;
	tempProj.z = p_posZ;
	tempProj.dirX = p_dirX;
	tempProj.dirY = p_dirY;
	tempProj.dirZ = p_dirZ;
	tempProj.projId = GetProjectileUniqueId();
	tempProj.guid = p_guid;
	tempProj.lifeTime = KUNAI_DURATION;
	tempProj.speed = KUNAI_SPEED;
	m_Projectiles.push_back(tempProj);

	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_PROJECTILE_THROWN);
	wBitStream.Write(tempProj.x);
	wBitStream.Write(tempProj.y);
	wBitStream.Write(tempProj.z);
	wBitStream.Write(tempProj.dirX);
	wBitStream.Write(tempProj.dirY);
	wBitStream.Write(tempProj.dirZ);
	wBitStream.Write(tempProj.projId);
	wBitStream.Write(tempProj.guid);
	wBitStream.Write(tempProj.speed);

	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

unsigned int ProjectileManager::GetProjectileUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_Projectiles.size(); i++)
		{
			if (m_Projectiles[i].projId == ID)
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
	for (unsigned int i = 0; i < m_Projectiles.size(); i++)
	{
		if (m_Projectiles[i].projId == p_id)
		{
			BroadcastDestoyedProjectile(p_id);
			m_Projectiles.erase(m_Projectiles.begin() + i);
			break;
		}
	}
}

void ProjectileManager::BroadcastDestoyedProjectile(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_PROJECTILE_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}