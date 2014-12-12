#include "CollisionManager.h"


void CollisionManager::Initialize(std::vector<OBB> p_StaticObjectList/*, std::vector<Sphere> p_sphereObjectList*/)
{
	SetLists(p_StaticObjectList/*, p_sphereObjectList*/);
}
void CollisionManager::SetLists(std::vector<OBB> p_StaticObjectList/*, std::vector<Sphere> p_sphereObjectList*/)
{

	for (unsigned int j = 0; j < p_StaticObjectList.size(); j++)
	{
		m_StaticObjectList.push_back(p_StaticObjectList[j]);
	}
	//for (unsigned int i = 0; i < p_sphereObjectList.size(); i++)
	//{
	//	m_sphereObjectList.push_back(p_sphereObjectList[i]);
	//}
}

std::vector<OBB> CollisionManager::CalculateLocalPlayerCollisionWithStaticObjects(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction, float p_deltaTime)
{
	std::vector<OBB> CollisionList;
	Sphere playerBox = p_playerSphere;
	float speedXDeltaTime = p_speed * p_deltaTime;
	if (m_StaticObjectList.size() > 0)
	{
		for (unsigned int i = 0; i < m_StaticObjectList.size(); i++)
		{
			OBB box = m_StaticObjectList[i];

			playerBox.m_position.x = p_playerSphere.m_position.x + p_direction.x * speedXDeltaTime;
			playerBox.m_position.y = p_playerSphere.m_position.y + p_direction.y * speedXDeltaTime;
			playerBox.m_position.z = p_playerSphere.m_position.z + p_direction.z * speedXDeltaTime;

			if (Collisions::OBBSphereCollision(box, playerBox))
			{
				CollisionList.push_back(box);
			}
		}
	}
	return CollisionList;
}
void CollisionManager::NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager)
{
	PlayerNet attackingPlayer = p_playerManager->GetPlayer(p_guid);
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		// So you don't collide with yourself.
		if (playerList[i].guid == attackingPlayer.guid)
		{
			continue;
		}

		// Check so you are not on the same team
		if (playerList[i].team == attackingPlayer.team)
		{
			continue;
		}

		DirectX::XMFLOAT3 spherePos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 boxPosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		DirectX::XMFLOAT3 boxExtent = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		// Make collision test
		if (IntersectionTests::Intersections::MeleeAttackCollision(spherePos, 2.5f, boxPosition, boxExtent, attackDirection))
		{
			// Respawn player
			p_playerManager->RespawnPlayer(playerList[i].guid);
			break;
		}
	}
}
void CollisionManager::ShurikenCollisionChecks(ShurikenManager* p_shurikenManager, PlayerManager* p_playerManager)
{
	float radius = 1.0f;
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<ShurikenNet> shurikenList = p_shurikenManager->GetShurikens();
	for (unsigned int i = 0; i < shurikenList.size(); i++)
	{
		bool collisionFound = false;
		// Get the shurikens position
		float newPosX = p_shurikenManager->GetShurikenPosX(i);
		float newPosY = p_shurikenManager->GetShurikenPosY(i);
		float newPosZ = p_shurikenManager->GetShurikenPosZ(i);

		// Get the shuriken bounding boxes
		std::vector<Box> shurikenBoundingBoxes = p_shurikenManager->GetBoundingBoxes(i);

		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			// This is so you don't collide with your own shurikens
			if (playerList[j].guid == shurikenList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet shootingPlayer = p_playerManager->GetPlayer(shurikenList[i].guid);
			if (playerList[j].team == shootingPlayer.team)
			{
				continue;
			}

			// Get the players bounding boxes
			std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(j);

			// Make collision test
			for (unsigned int k = 0; k < shurikenBoundingBoxes.size(); k++)
			{
				for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
				{
					if (IntersectionTests::Intersections::BoxBoxCollision(playerBoundingBoxes[l].m_center, playerBoundingBoxes[l].m_extents, shurikenBoundingBoxes[k].m_center, shurikenBoundingBoxes[k].m_extents))
					{
						// Remove shuriken
						p_shurikenManager->RemoveShuriken(shurikenList[i].shurikenId);
						shurikenList.erase(shurikenList.begin() + i);
						i--;

						// Respawn player
						p_playerManager->RespawnPlayer(playerList[j].guid);

						collisionFound = true;
						break;
					}
				}
				if (collisionFound)
				{
					break;
				}
			}

			if (collisionFound)
			{
				break;
			}
		}

		// Go through maps bounding boxes
		for (unsigned int j = 0; j < shurikenBoundingBoxes.size(); j++)
		{
			for (unsigned int k = 0; k < m_StaticObjectList.size(); k++)
			{
				if (IntersectionTests::Intersections::OBBOBBCollision(m_StaticObjectList[k].m_center, m_StaticObjectList[k].m_extents, m_StaticObjectList[k].m_direction,
					shurikenBoundingBoxes[j].m_center, shurikenBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)))
				{
					// Remove shuriken
					p_shurikenManager->RemoveShuriken(shurikenList[i].shurikenId);
					shurikenList.erase(shurikenList.begin() + i);
					i--;

					collisionFound = true;
					break;
				}
			}
			if (collisionFound)
			{
				break;
			}
		}
	}
}