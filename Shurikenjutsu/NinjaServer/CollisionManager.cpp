#include "CollisionManager.h"


void CollisionManager::Initialize(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList)
{
	m_staticBoxList = std::vector<OBB>();
	m_staticSphereList = std::vector<Sphere>();
	SetLists(p_staticBoxList, p_staticSphereList);
}

void CollisionManager::SetLists(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList)
{

	for (unsigned int i = 0; i < p_staticBoxList.size(); i++)
	{
		m_staticBoxList.push_back(p_staticBoxList[i]);
	}

	for (unsigned int i = 0; i < p_staticSphereList.size(); i++)
	{
		m_staticSphereList.push_back(p_staticSphereList[i]);
	}
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

		// Check so the player aren't already dead
		if (!playerList[i].isAlive)
		{
			continue;
		}

		DirectX::XMFLOAT3 spherePos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 boxPosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		DirectX::XMFLOAT3 boxExtent = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		// Make collision test
		if (IntersectionTests::Intersections::MeleeAttackCollision(spherePos, KATANA_RANGE, attackDirection, boxPosition, boxExtent, 2.5f))
		{
			// Damage the player
			p_playerManager->DamagePlayer(playerList[i].guid, (int)KATANA_DAMAGE);
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
		std::vector<Box> shurikenBoundingBoxes; 
		if (shurikenList[i].megaShuriken)
		{
			shurikenBoundingBoxes = p_shurikenManager->GetMegaBoundingBoxes(i);
		}
		else
		{
			shurikenBoundingBoxes = p_shurikenManager->GetBoundingBoxes(i);
		}
		

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

			// Check so the player aren't already dead
			if (!playerList[j].isAlive)
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
					if (BoxBoxTest(playerBoundingBoxes[l], shurikenBoundingBoxes[k]))
					{
						int damage = shurikenList[i].megaShuriken ? MEGASHURIKEN_DAMAGE : SHURIKEN_DAMAGE;
						
						p_playerManager->DamagePlayer(playerList[j].guid, damage);

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

			if (collisionFound)
			{
				break;
			}
		}

		// Go through maps bounding boxes
		for (unsigned int j = 0; j < shurikenBoundingBoxes.size(); j++)
		{
			// Box list
			for (unsigned int k = 0; k < m_staticBoxList.size(); k++)
			{
				if (OBBOBBTest(m_staticBoxList[k], OBB(shurikenBoundingBoxes[j].m_center, shurikenBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f))))
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

			// Sphere list
			for (unsigned int k = 0; k < m_staticSphereList.size(); k++)
			{
				Sphere sphere = m_staticSphereList[k];
				if (sphere.m_position.y + sphere.m_radius < shurikenBoundingBoxes[j].m_center.y - shurikenBoundingBoxes[j].m_extents.y || sphere.m_position.y - sphere.m_radius > shurikenBoundingBoxes[j].m_center.y + shurikenBoundingBoxes[j].m_extents.y)
				{
					sphere.m_position.y = shurikenBoundingBoxes[j].m_center.y;
				}
				if (OBBSphereTest(OBB(shurikenBoundingBoxes[j].m_center, shurikenBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)), sphere))
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

float CollisionManager::CalculateDashRange(PlayerNet p_attackingPlayer, PlayerManager* p_playerManager)
{
	DirectX::XMFLOAT3 rayDirection = DirectX::XMFLOAT3(p_attackingPlayer.dirX, 0.1f, p_attackingPlayer.dirZ);
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(p_attackingPlayer.x, 0.1f, p_attackingPlayer.z);
	Ray* ray = new Ray(rayPos, rayDirection);
	float dashLength = DASH_MAX_RANGE;
	std::vector<float> distancesToTarget;
	std::vector<float> rayLengths;

	// Go through static boxes
	for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
	{
		if (Collisions::RayOBBCollision(ray, m_staticBoxList[i]))
		{
			if (ray->m_distance != 0)
			{
				rayLengths.push_back(ray->m_distance);
			}
		}
	}
	// Go through static spheres
	for (unsigned int i = 0; i < m_staticSphereList.size(); i++)
	{
		Sphere tmpSphere = m_staticSphereList[i];
		tmpSphere.m_position.y = 0.1f;
		if (Collisions::RaySphereCollision(ray, tmpSphere))
		{
			if (ray->m_distance != 0)
			{
				rayLengths.push_back(ray->m_distance);
			}
		}
	}

	//Go through the shortest intersecting object
	for (unsigned int i = 0; i < rayLengths.size(); i++)
	{
		if (rayLengths[i] < dashLength)
		{
			dashLength = rayLengths[i];
		}
	}

	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	// Go through player list
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		// Get the players bounding boxes
		std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(i);
		for (unsigned int j = 0; j < playerBoundingBoxes.size(); j++)
		{
			Box box = playerBoundingBoxes[j];
			if (Collisions::RayBoxCollision(ray,  box))
			{
				distancesToTarget.push_back(ray->m_distance);
			}
		}
	}
	//Get the shortest intersecting distance
	for (unsigned int i = 0; i < distancesToTarget.size(); i++)
	{
		if ((distancesToTarget[i] < dashLength) && (distancesToTarget[i] > 0))
		{
			dashLength = distancesToTarget[i];
		}
	}
	return dashLength;
}

void CollisionManager::CalculateSmokeBombLocation()
{

}
//Private
bool CollisionManager::OBBOBBTest(OBB p_OBB1, OBB p_OBB2)
{
	if (IntersectionTests::Intersections::SphereSphereCollision(p_OBB1.m_center, p_OBB1.m_radius, p_OBB2.m_center, p_OBB2.m_radius))
	{
		return IntersectionTests::Intersections::OBBOBBCollision(p_OBB1.m_center, p_OBB1.m_extents, p_OBB1.m_direction, p_OBB2.m_center, p_OBB2.m_extents, p_OBB2.m_direction);
	}
	return false;
}
bool CollisionManager::BoxBoxTest(Box p_box1, Box p_box2)
{
	if (IntersectionTests::Intersections::SphereSphereCollision(p_box1.m_center, p_box1.m_radius, p_box2.m_center, p_box2.m_radius))
	{
		return IntersectionTests::Intersections::BoxBoxCollision(p_box1.m_center, p_box1.m_extents, p_box2.m_center, p_box2.m_extents);
	}
	return false;
}

bool CollisionManager::OBBSphereTest(OBB p_OBB, Sphere p_sphere)
{
	if (IntersectionTests::Intersections::SphereSphereCollision(p_OBB.m_center, p_OBB.m_radius, p_sphere.m_position, p_sphere.m_radius))
	{
		return IntersectionTests::Intersections::OBBSphereCollision(p_OBB.m_center, p_OBB.m_extents, p_OBB.m_direction, p_sphere.m_position, p_sphere.m_radius);
	}
	return false;
}