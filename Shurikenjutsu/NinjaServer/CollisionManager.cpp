#include "CollisionManager.h"
#include "PlayerManager.h"
#include "SpikeManager.h"
#include "ShurikenManager.h"
#include "ProjectileManager.h"
#include "FanBoomerangManager.h"
#include "VolleyManager.h"

void CollisionManager::Initialize(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList)
{
	m_staticBoxList = std::vector<OBB>();
	m_staticSphereList = std::vector<Sphere>();
	SetLists(p_staticBoxList, p_staticSphereList);
	m_deltaTime = 0;
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

void CollisionManager::NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager, ABILITIES p_ability)
{
	float range;
	float damage;
	switch (p_ability)
	{
	case ABILITIES_MELEESWING:
		range = KATANA_RANGE;
		damage = KATANA_DAMAGE;
		break;
	case ABILITIES_NAGINATASLASH:
		range = NAGINATA_RANGE;
		damage = NAGINATA_DAMAGE;
		break;
	default:
		range = 0;
		damage = 0;
		break;
	}
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
		float attackAngle = 1.047f;
		DirectX::XMFLOAT3 attackingPlayerPos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, 0.0f , attackingPlayer.dirZ);
		DirectX::XMFLOAT3 defendingPlayerPos = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		DirectX::XMFLOAT3 defendingPlayerBoxExtents = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);

		DirectX::XMFLOAT3 vectorFromAttackerToDefender = DirectX::XMFLOAT3(defendingPlayerPos.x - attackingPlayerPos.x, 0.0f, defendingPlayerPos.z - attackingPlayerPos.z);
		//Ta reda på den jävla vinkel hellvetet... -.-' om den är inom vissa parametrar så kör nästa beräkning
		// Make collision test
		if (IntersectionTests::Intersections::SphereBoxCollision(attackingPlayerPos, range, defendingPlayerPos, defendingPlayerBoxExtents))
		{//IntersectionTests::Intersections::MeleeAttackCollision(attackingPlayerPos, range, attackDirection, defendingPlayerPos, defendingPlayerBoxExtents, range)

			if (true)
			{
				if (!IntersectingObjectWhenAttacking(attackingPlayerPos, defendingPlayerPos))
				{
					// Damage the player
					p_playerManager->DamagePlayer(playerList[i].guid, damage);
					break;
				}
			}
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
						float damage = shurikenList[i].megaShuriken ? (float)MEGASHURIKEN_DAMAGE : (float)SHURIKEN_DAMAGE;
						
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

void CollisionManager::ProjectileCollisionChecks(ProjectileManager* p_projectileManager, PlayerManager* p_playerManager)
{
	float radius = 1.0f;
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<ProjectileNet> projectileList = p_projectileManager->GetProjectiles();
	for (unsigned int i = 0; i < projectileList.size(); i++)
	{
		bool collisionFound = false;

		// Get the shuriken bounding boxes
		std::vector<Box> projectileBoundingBoxes;
		if (projectileList[i].projType == 0)
		{
			//projectileBoundingBoxes = p_projectileManager->GetBoundingBoxes(i);
		}
		else if (projectileList[i].projType == 1)
		{
			//projectileBoundingBoxes = p_projectileManager->GetMegaBoundingBoxes(i);
		}
		else //if (projectileList[i].projType == 2)
		{
			projectileBoundingBoxes = p_projectileManager->GetKunaiBoundingBoxes(i);
		}


		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			// This is so you don't collide with your own shurikens
			if (playerList[j].guid == projectileList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet shootingPlayer = p_playerManager->GetPlayer(projectileList[i].guid);
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
			for (unsigned int k = 0; k < projectileBoundingBoxes.size(); k++)
			{
				for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
				{
					if (BoxBoxTest(playerBoundingBoxes[l], projectileBoundingBoxes[k]))
					{
						float damage = KUNAI_DAMAGE;//= projectileList[i].megaShuriken ? (float)MEGASHURIKEN_DAMAGE : (float)SHURIKEN_DAMAGE;

						p_playerManager->DamagePlayer(playerList[j].guid, damage);

						// Remove shuriken
						p_projectileManager->RemoveProjectile(projectileList[i].uniqueId);
						projectileList.erase(projectileList.begin() + i);
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
		for (unsigned int j = 0; j < projectileBoundingBoxes.size(); j++)
		{
			// Box list
			for (unsigned int k = 0; k < m_staticBoxList.size(); k++)
			{
				if (OBBOBBTest(m_staticBoxList[k], OBB(projectileBoundingBoxes[j].m_center, projectileBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f))))
				{
					// Remove shuriken
					p_projectileManager->RemoveProjectile(projectileList[i].uniqueId);
					projectileList.erase(projectileList.begin() + i);
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
				if (sphere.m_position.y + sphere.m_radius < projectileBoundingBoxes[j].m_center.y - projectileBoundingBoxes[j].m_extents.y || sphere.m_position.y - sphere.m_radius > projectileBoundingBoxes[j].m_center.y + projectileBoundingBoxes[j].m_extents.y)
				{
					sphere.m_position.y = projectileBoundingBoxes[j].m_center.y;
				}
				if (OBBSphereTest(OBB(projectileBoundingBoxes[j].m_center, projectileBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)), sphere))
				{
					// Remove shuriken
					p_projectileManager->RemoveProjectile(projectileList[i].uniqueId);
					projectileList.erase(projectileList.begin() + i);
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

void CollisionManager::FanCollisionChecks(double p_deltaTime, FanBoomerangManager* p_fanBoomerangManager, PlayerManager* p_playerManager)
{
	float radius = 1.0f;
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<FanNet>fanList = p_fanBoomerangManager->GetObjects();
	for (unsigned int i = 0; i < fanList.size(); i++)
	{
		bool collisionFound = false;
		// Get the fans position
		float newPosX = p_fanBoomerangManager->GetPosX(i);
		float newPosY = p_fanBoomerangManager->GetPosY(i);
		float newPosZ = p_fanBoomerangManager->GetPosZ(i);

		// Get the fan bounding boxes
		std::vector<Box> fanBoundingBoxes;

		fanBoundingBoxes = p_fanBoomerangManager->GetBoundingBoxes(i);
		
		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			if (fanList[i].lifeTime <= 0)
			{
				if (playerList[j].guid == fanList[i].guid)
				{
					// Get the players bounding boxes
					std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(j);

					// Make collision test
					for (unsigned int k = 0; k < fanBoundingBoxes.size(); k++)
					{
						for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
						{
							if (BoxBoxTest(playerBoundingBoxes[l], fanBoundingBoxes[k]))
							{
								p_fanBoomerangManager->Remove(fanList[i].id);
								fanList.erase(fanList.begin() + i);
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

			if (collisionFound)
			{
				break;
			}

			// This is so you don't collide with your own fan if it's alive.
			if (playerList[j].guid == fanList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet shootingPlayer = p_playerManager->GetPlayer(fanList[i].guid);
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
			for (unsigned int k = 0; k < fanBoundingBoxes.size(); k++)
			{
				for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
				{
					if (BoxBoxTest(playerBoundingBoxes[l], fanBoundingBoxes[k]))
					{
						float damage = FANBOOMERANG_DAMAGE*(float)p_deltaTime;

						p_playerManager->DamagePlayer(playerList[j].guid, damage);
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

		if (collisionFound)
		{
			continue;
		}

		if (fanList[i].lifeTime <= -0.3f)
		{
			// Go through maps bounding boxes
			for (unsigned int j = 0; j < fanBoundingBoxes.size(); j++)
			{
				// Box list
				for (unsigned int k = 0; k < m_staticBoxList.size(); k++)
				{
					if (OBBOBBTest(m_staticBoxList[k], OBB(fanBoundingBoxes[j].m_center, fanBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f))))
					{
						// Remove
						p_fanBoomerangManager->Remove(fanList[i].id);
						fanList.erase(fanList.begin() + i);
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
					if (sphere.m_position.y + sphere.m_radius < fanBoundingBoxes[j].m_center.y - fanBoundingBoxes[j].m_extents.y || sphere.m_position.y - sphere.m_radius > fanBoundingBoxes[j].m_center.y + fanBoundingBoxes[j].m_extents.y)
					{
						sphere.m_position.y = fanBoundingBoxes[j].m_center.y;
					}
					if (OBBSphereTest(OBB(fanBoundingBoxes[j].m_center, fanBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)), sphere))
					{
						// Remove
						p_fanBoomerangManager->Remove(fanList[i].id);
						fanList.erase(fanList.begin() + i);
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

		else
		{
			// Go through maps bounding boxes
			for (unsigned int j = 0; j < fanBoundingBoxes.size(); j++)
			{
				// Box list
				for (unsigned int k = 0; k < m_staticBoxList.size(); k++)
				{
					if (OBBOBBTest(m_staticBoxList[k], OBB(fanBoundingBoxes[j].m_center, fanBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f))))
					{
						// END LIFE!
						p_fanBoomerangManager->SetLifeTime(i, 0.0f);

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
					if (sphere.m_position.y + sphere.m_radius < fanBoundingBoxes[j].m_center.y - fanBoundingBoxes[j].m_extents.y || sphere.m_position.y - sphere.m_radius > fanBoundingBoxes[j].m_center.y + fanBoundingBoxes[j].m_extents.y)
					{
						sphere.m_position.y = fanBoundingBoxes[j].m_center.y;
					}
					if (OBBSphereTest(OBB(fanBoundingBoxes[j].m_center, fanBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)), sphere))
					{
						// END LIFE!
						p_fanBoomerangManager->SetLifeTime(i, 0.0f);

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
}

float CollisionManager::CalculateDashRange(RakNet::RakNetGUID p_guid, PlayerNet p_attackingPlayer, PlayerManager* p_playerManager)
{
	PlayerNet tempPlayer = p_attackingPlayer;
	float returnValue = DashLengthCalculation(p_guid, tempPlayer, p_playerManager);

	tempPlayer.x -= 0.5f;
	float test1 = DashLengthCalculation(p_guid, tempPlayer, p_playerManager);
	
	tempPlayer = p_attackingPlayer;
	tempPlayer.x += 0.5f;
	float test2 = DashLengthCalculation(p_guid, tempPlayer, p_playerManager);

	tempPlayer = p_attackingPlayer;
	tempPlayer.z -= 0.5f;
	float test3 = DashLengthCalculation(p_guid, tempPlayer, p_playerManager);

	tempPlayer = p_attackingPlayer;
	tempPlayer.z += 0.5f;
	float test4 = DashLengthCalculation(p_guid, tempPlayer, p_playerManager);

	if (returnValue > test1)
	{
		returnValue = test1;
	}
	if (returnValue > test2)
	{
		returnValue = test2;
	}
	if (returnValue > test3)
	{
		returnValue = test3;
	}
	if (returnValue > test4)
	{
		returnValue = test4;
	}
	
	return returnValue;

}

void CollisionManager::SpikeTrapCollisionChecks(SpikeManager* p_spikeManager, PlayerManager* p_playerManager)
{
	float radius = 1.0f;
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<SpikeNet> spikeList = p_spikeManager->GetSpikeTraps();
	for (unsigned int i = 0; i < spikeList.size(); i++)
	{
		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			// This is so you don't collide with your own shurikens
			if (playerList[j].guid == spikeList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet owner = p_playerManager->GetPlayer(spikeList[i].guid);
			if (playerList[j].team == owner.team)
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
			for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
			{
				if (spikeList[i].timeToLand <= 0)
				{
					DirectX::XMFLOAT3 spikeTrapPos = DirectX::XMFLOAT3(spikeList[i].endX, playerBoundingBoxes[l].m_center.y, spikeList[i].endZ);
					if (SphereSphereTest(Sphere(spikeTrapPos, SPIKE_RADIUS), Sphere(playerBoundingBoxes[l].m_center, playerBoundingBoxes[l].m_radius)))
					{
						float damage = SPIKE_DAMAGE * m_deltaTime;
						p_playerManager->DamagePlayer(playerList[j].guid, damage);
						break;
					}
				}
			}
		}
	}
}

void CollisionManager::WhipPrimaryAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager)
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

		DirectX::XMFLOAT3 attackPosition = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 spherePosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		Ray* whipRay = new Ray(attackPosition, attackDirection);
		float *distance = new float(0);
		// Make collision test
		if (IntersectionTests::Intersections::RaySphereCollision(whipRay->m_position, whipRay->m_direction, spherePosition, 1.0f, distance))
		{
			if (*distance <= WHIP_RANGE)
			{
				if (!IntersectingObjectWhenAttacking(attackPosition, DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z)))
				{
				// Damage the player
				p_playerManager->DamagePlayer(playerList[i].guid, WHIP_DAMAGE);
				break;
				}
			}
		}
	}
}

void CollisionManager::WhipSecondaryAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager)
{
	PlayerNet attackingPlayer = p_playerManager->GetPlayer(p_guid);
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	DirectX::XMFLOAT3 attackPosition = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
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

		DirectX::XMFLOAT3 spherePosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);

		// Make collision test
		if (IntersectionTests::Intersections::SphereSphereCollision(attackPosition, WHIP_SP_RANGE, spherePosition, 1.0f))
		{
			if (!IntersectingObjectWhenAttacking(attackPosition, DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z)))
			{
			// Damage the player
			p_playerManager->DamagePlayer(playerList[i].guid, WHIP_SP_DAMAGE);
		}
	}
}
}

void CollisionManager::NaginataStabAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager)
{
	NaginataStabAttacks temp;
	temp.m_timer = 0;
	temp.m_guid = p_guid;
	temp.m_performNaginataStabAttack = true;
	m_performingStabAttackList.push_back(temp);
	
	p_playerManager->NaginataStabAttackPerformed(p_guid);
}

void CollisionManager::NaginataStbDot( PlayerManager* p_playerManager)
{
	for (unsigned int j = 0; j < m_performingStabAttackList.size(); j++)
	{
		m_performingStabAttackList[j].m_timer += m_deltaTime;
		if (m_performingStabAttackList[j].m_performNaginataStabAttack)
		{
			PlayerNet attackingPlayer = p_playerManager->GetPlayer(m_performingStabAttackList[j].m_guid);
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	DirectX::XMFLOAT3 attackPosition = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
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

		DirectX::XMFLOAT3 boxExtent = DirectX::XMFLOAT3(NAGINATASTAB_BOXEXTENTX, NAGINATASTAB_BOXEXTENTY, NAGINATASTAB_BOXEXTENTZ);
		DirectX::XMFLOAT3 spherePosition = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, attackingPlayer.dirY, attackingPlayer.dirZ);

		float faceAngle = atan2(attackDirection.x, attackDirection.z);

		// Rotate around y axis
		DirectX::XMFLOAT3 rotatinAxis = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);

		// Update rec location.
		DirectX::XMFLOAT4 rotationQuaternion;
		DirectX::XMStoreFloat4(&rotationQuaternion, DirectX::XMQuaternionRotationAxis(DirectX::XMLoadFloat3(&rotatinAxis), faceAngle));
		
		attackPosition = DirectX::XMFLOAT3(attackPosition.x + attackDirection.x * boxExtent.z, attackPosition.y, attackPosition.z + attackDirection.z * boxExtent.z);

		// Make collision test
		if (IntersectionTests::Intersections::OBBSphereCollision(attackPosition, boxExtent, rotationQuaternion, spherePosition, CHARACTER_ENEMY_BOUNDINGSPHERE))
		{
			if (!IntersectingObjectWhenAttacking(DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z), DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z)))
			{
				// Damage the player
						p_playerManager->DamagePlayer(playerList[i].guid, NAGINATASTAB_DAMAGE * m_deltaTime);
					}
				}
			}
			if (m_performingStabAttackList[j].m_timer > NAGINATASTAB_DURATION)
			{
				m_performingStabAttackList[j].m_timer = 0;
				m_performingStabAttackList[j].m_performNaginataStabAttack = false;
				m_performingStabAttackList.erase(m_performingStabAttackList.begin() + j);
			}
			}
		}
	}
void CollisionManager::SetDeltaTime(float p_deltaTime)
{
	m_deltaTime = p_deltaTime;
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
bool CollisionManager::SphereSphereTest(Sphere p_spikeTrap, Sphere p_player)
{
	return IntersectionTests::Intersections::SphereSphereCollision(p_spikeTrap.m_position, p_spikeTrap.m_radius, p_player.m_position, p_player.m_radius);
}
bool CollisionManager::IntersectingObjectWhenAttacking(DirectX::XMFLOAT3 p_attackingPlayerPos, DirectX::XMFLOAT3 p_defendingPlayerPos)
{
	DirectX::XMFLOAT3 vectorFromA2B = DirectX::XMFLOAT3(p_defendingPlayerPos.x - p_attackingPlayerPos.x, 0.0f, p_defendingPlayerPos.z - p_attackingPlayerPos.z);
	float distance = sqrt(vectorFromA2B.x * vectorFromA2B.x + vectorFromA2B.z * vectorFromA2B.z);

	Ray* ray = new Ray(p_attackingPlayerPos, vectorFromA2B);
	std::vector<float> listOfDistances;

	for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
	{
		if (RayOBBTest(ray, m_staticBoxList[i]))
		{
			listOfDistances.push_back(ray->m_distance);
		}
	}
	for (unsigned int i = 0; i < m_staticSphereList.size(); i++)
	{
		if (RaySphereTest(ray, m_staticSphereList[i]))
		{
			listOfDistances.push_back(ray->m_distance);
		}
	}	
	for (unsigned int i = 0; i < listOfDistances.size(); i++)
	{
		if (distance > listOfDistances[i])
		{
			return true;
		}
	}
	return false;
}
bool CollisionManager::RayOBBTest(Ray *p_ray, OBB p_Obb)
{
	float *temp = new float(0);
	if (IntersectionTests::Intersections::RayOBBCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_Obb.m_center, p_Obb.m_extents, p_Obb.m_direction, temp))
	{
		p_ray->m_distance = *temp;
		return true;
	}
	else
	{
		return false;
	}
}
bool CollisionManager::RaySphereTest(Ray *p_ray, Sphere p_sphere)
{
	float *temp = new float(0);
	if (IntersectionTests::Intersections::RaySphereCollision(p_ray->m_position, p_ray->m_direction, p_sphere.m_position, p_sphere.m_radius, temp))
	{
		p_ray->m_distance = *temp;
		return true;
	}
	else
	{
		return false;
	}
}

void CollisionManager::VolleyCollisionChecks(VolleyManager* p_volleyManager, PlayerManager* p_playerManager)
{
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<VolleyNet> volleyList = p_volleyManager->GetObjects();
	for (unsigned int i = 0; i < volleyList.size(); i++)
	{
		bool remove = false;
		// Go through player list
		for (unsigned int j = 0; j < playerList.size(); j++)
		{
			// This is so you don't collide with your own shurikens
			if (playerList[j].guid == volleyList[i].guid)
			{
				continue;
			}

			// Check so you are not on the same team
			PlayerNet owner = p_playerManager->GetPlayer(volleyList[i].guid);
			if (playerList[j].team == owner.team)
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
			if (volleyList[i].timeToLand <= 0.0f)
			{
				for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
				{
					DirectX::XMFLOAT3 volleyPos = DirectX::XMFLOAT3(volleyList[i].endX, playerBoundingBoxes[l].m_center.y, volleyList[i].endZ);
					if (SphereSphereTest(Sphere(volleyPos, VOLLEY_RADIUS), Sphere(playerBoundingBoxes[l].m_center, playerBoundingBoxes[l].m_radius)))
					{
						float damage = VOLLEY_DAMAGE;
						p_playerManager->DamagePlayer(playerList[j].guid, damage);
						break;
					}
				}
				remove = true;
			}
		}

		// Remove dead volley
		if (remove)
		{
			p_volleyManager->Remove(i); // MAY WORK, BE CAUTIOUS!
			volleyList.erase(volleyList.begin() + i);
			i--;
		}
	}
}
float CollisionManager::DashLengthCalculation(RakNet::RakNetGUID p_guid, PlayerNet p_attackingPlayer, PlayerManager* p_playerManager)
{
	DirectX::XMFLOAT3 rayDirection = DirectX::XMFLOAT3(p_attackingPlayer.dirX, 0.1f, p_attackingPlayer.dirZ);
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(p_attackingPlayer.x, 0.1f, p_attackingPlayer.z);
	Ray* ray = new Ray(rayPos, rayDirection);
	float dashLength = DASH_MAX_RANGE;
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

	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	// Go through player list
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].guid != p_guid)
		{
			// Get the players bounding boxes
			std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(i);
			for (unsigned int j = 0; j < playerBoundingBoxes.size(); j++)
			{
				Box box = playerBoundingBoxes[j];
				if (Collisions::RayBoxCollision(ray, box))
				{
					rayLengths.push_back(ray->m_distance);
				}
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
	return dashLength;
}