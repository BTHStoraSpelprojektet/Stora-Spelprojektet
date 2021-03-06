#include "CollisionManager.h"
#include "PlayerManager.h"
#include "SpikeManager.h"
#include "ShurikenManager.h"
#include "ProjectileManager.h"
#include "FanBoomerangManager.h"
#include "VolleyManager.h"
#include "PointOfInterestManager.h"

void CollisionManager::Initialize(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList)
{
	m_staticBoxList = std::vector<OBB>();
	m_staticSphereList = std::vector<Sphere>();
	SetLists(p_staticBoxList, p_staticSphereList);
	m_deltaTime = 0;
	m_doneDashDamage = false;
}

void CollisionManager::SetLists(std::vector<OBB> p_staticBoxList, std::vector<Sphere> p_staticSphereList)
{

	for (unsigned int i = 0; i < p_staticBoxList.size(); i++)
	{
		if (p_staticBoxList[i].m_center.y > 6.0f)
		{
			continue;
		}
		else
		{
			m_staticBoxList.push_back(p_staticBoxList[i]);
		}
	}

	for (unsigned int i = 0; i < p_staticSphereList.size(); i++)
	{
		if (p_staticSphereList[i].m_position.y > 5.0f)
		{
			continue;
		}
		else
		{
			m_staticSphereList.push_back(p_staticSphereList[i]);
		}
	}
}

void CollisionManager::NormalMeleeAttack(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager, ABILITIES p_ability)
{
	float range;
	float damage;
	float attackAngle;
	switch (p_ability)
	{
	case ABILITIES_MELEESWING:
		range = KATANA_RANGE;
		damage = KATANA_DAMAGE;
		attackAngle = KATANA_ATTACKANGLE;
		break;
	case ABILITIES_FANMELEE:
		range = FANMELEE_RANGE;
		damage = FANMELEE_DAMAGE;
		attackAngle = FANMELEE_ATTACKANGLE;
		break;
	case ABILITIES_NAGINATASLASH:
		range = NAGINATA_RANGE;
		damage = NAGINATA_DAMAGE;
		attackAngle = NAGINATA_ATTACKANGLE;
		break;
	default:
		range = 0;
		damage = 0;
		attackAngle = 0;
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
		DirectX::XMFLOAT3 attackingPlayerPos = DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z);
		DirectX::XMFLOAT3 attackDirection = DirectX::XMFLOAT3(attackingPlayer.dirX, 0.0f, attackingPlayer.dirZ);
		DirectX::XMFLOAT3 defendingPlayerPos = DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z);
		//DirectX::XMFLOAT3 defendingPlayerBoxExtents = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		float attackingPlayerExtraCircleRadius = 0.3f;
		DirectX::XMFLOAT3 attackingPlayerExtraCircle = DirectX::XMFLOAT3(attackingPlayerPos.x - (attackDirection.x /* * attackingPlayerExtraCircleRadius */), attackingPlayerPos.y, attackingPlayerPos.z - (attackDirection.z/* * attackingPlayerExtraCircleRadius */));

		DirectX::XMFLOAT3 vectorFromAttackerToDefender = DirectX::XMFLOAT3(defendingPlayerPos.x - attackingPlayerExtraCircle.x, 0.0f, defendingPlayerPos.z - attackingPlayerExtraCircle.z);
		//Ta reda p� den j�vla vinkel hellvetet... -.-' om den �r inom vissa parametrar s� k�r n�sta ber�kning
		// Make collision test
		if (IntersectionTests::Intersections::SphereSphereCollision(attackingPlayerPos, range, defendingPlayerPos, CHARACTER_ENEMY_BOUNDINGSPHERE))
		{
			if (!IntersectionTests::Intersections::SphereSphereCollision(attackingPlayerExtraCircle, attackingPlayerExtraCircleRadius, defendingPlayerPos, 0.5f))
			{
				DirectX::XMFLOAT3 A = attackDirection;
				float aLength = sqrt(A.x * A.x + A.z * A.z);
				DirectX::XMFLOAT3 B = vectorFromAttackerToDefender;
				float bLength = sqrt(B.x * B.x + B.z * B.z);
				float dotProduct = A.x * B.x + A.z * B.z;
				//A*B = |A| * |B| * cos(vinkel)
				float angle = acos(dotProduct / (aLength * bLength));

				if (angle < attackAngle)
				{
					if (!IntersectingObjectWhenAttacking(attackingPlayerPos, defendingPlayerPos, false))
					{
						// Damage the player
						p_playerManager->DamagePlayer(playerList[i].guid, damage, attackingPlayer.guid, p_ability, false);
						break;
					}
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
						
						p_playerManager->DamagePlayer(playerList[j].guid, damage, shurikenList[i].guid, ABILITIES_SHURIKEN, false);

						// Remove shuriken
						if (shurikenList[i].megaShuriken){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
						}
						else{
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
						}
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
					if (shurikenList[i].megaShuriken){
						p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
					}
					else{
						p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
					}
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
				if (sphere.m_position.y > 6.0f)
				{
					continue;
				}
				if (sphere.m_position.y + sphere.m_radius < shurikenBoundingBoxes[j].m_center.y - shurikenBoundingBoxes[j].m_extents.y || sphere.m_position.y - sphere.m_radius > shurikenBoundingBoxes[j].m_center.y + shurikenBoundingBoxes[j].m_extents.y)
				{
					sphere.m_position.y = shurikenBoundingBoxes[j].m_center.y;
				}
				if (OBBSphereTest(OBB(shurikenBoundingBoxes[j].m_center, shurikenBoundingBoxes[j].m_extents, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)), sphere))
				{
					// Remove shuriken
					if (shurikenList[i].megaShuriken){
						p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
					}
					else{
						p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, newPosX, newPosY, newPosZ);
					}
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
	ABILITIES ability;
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
			ability = ABILITIES_SHURIKEN;
		}
		else if (projectileList[i].projType == 1)
		{
			//projectileBoundingBoxes = p_projectileManager->GetMegaBoundingBoxes(i);
			ability = ABILITIES_MEGASHURIKEN;
		}
		else //if (projectileList[i].projType == 2)
		{
			projectileBoundingBoxes = p_projectileManager->GetKunaiBoundingBoxes(i);
			ability = ABILITIES_KUNAI;
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

						p_playerManager->DamagePlayer(playerList[j].guid, damage, projectileList[i].guid, ability,false);

						// Remove shuriken
						if (j < projectileBoundingBoxes.size()){
							if (ability == ABILITIES::ABILITIES_KUNAI){
								p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_KUNAI_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
							}
							else if (ability == ABILITIES::ABILITIES_SHURIKEN){
								p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
							}
							else if (ability == ABILITIES::ABILITIES_MEGASHURIKEN){
								p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
							}
						}

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
					if (j < projectileBoundingBoxes.size()){
						if (ability == ABILITIES::ABILITIES_KUNAI){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_KUNAI_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
						else if (ability == ABILITIES::ABILITIES_SHURIKEN){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
						else if (ability == ABILITIES::ABILITIES_MEGASHURIKEN){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
					}
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
					if (j < projectileBoundingBoxes.size()){
						if (ability == ABILITIES::ABILITIES_KUNAI){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_KUNAI_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
						else if (ability == ABILITIES::ABILITIES_SHURIKEN){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
						else if (ability == ABILITIES::ABILITIES_MEGASHURIKEN){
							p_playerManager->SendPlaySound(PLAYSOUND::PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND, projectileBoundingBoxes[j].m_center.x, projectileBoundingBoxes[j].m_center.y, projectileBoundingBoxes[j].m_center.z);
						}
					}
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

		if (!CheckIfPlayerIsConnected(fanList[i].guid, p_playerManager))
		{
			p_fanBoomerangManager->Remove(fanList[i].id);
			fanList.erase(fanList.begin() + i);
			i--;
			continue;
		}
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
						if (playerList[j].dotDamage > 1.0f && p_playerManager->CanSendDotDamage())
						{
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, playerList[j].dotDamage + damage);
							p_playerManager->DamagePlayer(playerList[j].guid, playerList[j].dotDamage, fanList[i].guid, ABILITIES_FANBOOMERANG, false);
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, 0.0f);
						}
						else
						{
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, playerList[j].dotDamage + damage);
						}
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
					if (sphere.m_position.y > 6.0f)
					{
						continue;
					}
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
					if (sphere.m_position.y > 6.0f)
					{
						continue;
					}
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
	m_doneDashDamage = false;
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
	if (returnValue <= 0)
	{
		returnValue = 0.0;
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
						if (playerList[j].dotDamage > 1.0f && p_playerManager->CanSendDotDamage())
						{
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, playerList[j].dotDamage + (SPIKE_DAMAGE * m_deltaTime));
							p_playerManager->DamagePlayer(playerList[j].guid, playerList[j].dotDamage, owner.guid, ABILITIES_SPIKETRAP, false);
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, 0.0f);
						}
						else
						{
							p_playerManager->SetPlayerDotDamage(playerList[j].guid, playerList[j].dotDamage + (SPIKE_DAMAGE * m_deltaTime));
						}
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
		float distance = 0;
		// Make collision test
		if (IntersectionTests::Intersections::RaySphereCollision(whipRay->m_position, whipRay->m_direction, spherePosition, 1.0f, distance))
		{
			if (distance <= WHIP_RANGE)
			{
				if (!IntersectingObjectWhenAttacking(attackPosition, DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z), true))
				{
					// Damage the player
					p_playerManager->DamagePlayer(playerList[i].guid, WHIP_DAMAGE, attackingPlayer.guid, ABILITIES_WHIP_PRIMARY, false);

					if (whipRay != nullptr)
					{
						delete whipRay;
						whipRay = nullptr;
					}
					break;
				}
			}
		}

		if (whipRay != nullptr)
		{
			delete whipRay;
			whipRay = nullptr;
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
			if (!IntersectingObjectWhenAttacking(attackPosition, DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z), true))
			{
				// Damage the player
				p_playerManager->DamagePlayer(playerList[i].guid, WHIP_SP_DAMAGE, attackingPlayer.guid, ABILITIES_WHIP_SECONDARY, false);
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

void CollisionManager::NaginataStbDot(PlayerManager* p_playerManager)
{
	for (unsigned int j = 0; j < m_performingStabAttackList.size(); j++)
	{
		m_performingStabAttackList[j].m_timer += m_deltaTime;
		if (m_performingStabAttackList[j].m_performNaginataStabAttack)
		{
			PlayerNet attackingPlayer = p_playerManager->GetPlayer(m_performingStabAttackList[j].m_guid);
			if (attackingPlayer.isAlive)
			{
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
						if (!IntersectingObjectWhenAttacking(DirectX::XMFLOAT3(attackingPlayer.x, attackingPlayer.y, attackingPlayer.z), DirectX::XMFLOAT3(playerList[i].x, playerList[i].y, playerList[i].z), true))
						{
							// Damage the player
							if (playerList[i].dotDamage > 1.0f && p_playerManager->CanSendDotDamage())
							{
								p_playerManager->SetPlayerDotDamage(playerList[i].guid, playerList[i].dotDamage + (NAGINATASTAB_DAMAGE * m_deltaTime));
								p_playerManager->DamagePlayer(playerList[i].guid, playerList[i].dotDamage, attackingPlayer.guid, ABILITIES_NAGAINATASTAB, false);
								p_playerManager->SetPlayerDotDamage(playerList[i].guid, 0.0f);
							}
							else
							{
								p_playerManager->SetPlayerDotDamage(playerList[i].guid, playerList[i].dotDamage + (NAGINATASTAB_DAMAGE * m_deltaTime));
							}
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
}

void CollisionManager::SetDeltaTime(float p_deltaTime)
{
	m_deltaTime = p_deltaTime;
}

void CollisionManager::SuddenDeathDot(float p_deltaTime, PlayerManager* p_playerManager)
{
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();

	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].isAlive)
		{
			Sphere playerSphere = Sphere(playerList[i].x, playerList[i].y, playerList[i].z, CHARACTER_ENEMY_BOUNDINGSPHERE);

			if (playerList[i].x > 12.0f || playerList[i].x < -12.0f || playerList[i].z > 12.0f || playerList[i].z < -12.0f)
			{
				// Damage the player
				if (playerList[i].dotDamage > 2.0f && p_playerManager->CanSendDotDamage())
				{
					p_playerManager->SetPlayerDotDamage(playerList[i].guid, playerList[i].dotDamage + (SUDDEN_DEATH_DAMAGE * m_deltaTime));
					p_playerManager->DamagePlayer(playerList[i].guid, playerList[i].dotDamage, playerList[i].guid, ABILITIES_SD_SMOKE, true);
					p_playerManager->SetPlayerDotDamage(playerList[i].guid, 0.0f);
				}

				else
				{
					p_playerManager->SetPlayerDotDamage(playerList[i].guid, playerList[i].dotDamage + (SUDDEN_DEATH_DAMAGE * m_deltaTime));
				}
			}
		}
	}
}

//Private
bool CollisionManager::CheckIfPlayerIsConnected(RakNet::RakNetGUID p_guid, PlayerManager* p_playerManager)
{
	std::vector<PlayerNet> playerList =  p_playerManager->GetPlayers();
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		if (playerList[i].guid == p_guid)
		{
			return true;
		}
	}

	return false;
}
bool CollisionManager::DoesIndexExistInList(int p_index, std::vector<int> p_list)
{
	for (unsigned int i = 0; i < p_list.size(); i++)
	{
		if (p_index == p_list[i])
		{
			return true;
		}
	}
	return false;
}
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
bool CollisionManager::IntersectingObjectWhenAttacking(DirectX::XMFLOAT3 p_attackingPlayerPos, DirectX::XMFLOAT3 p_defendingPlayerPos, bool p_isThrowing)
{
	DirectX::XMFLOAT3 vectorFromA2B = DirectX::XMFLOAT3(p_defendingPlayerPos.x - p_attackingPlayerPos.x, 0.0f, p_defendingPlayerPos.z - p_attackingPlayerPos.z);
	float distance = sqrt(vectorFromA2B.x * vectorFromA2B.x + vectorFromA2B.z * vectorFromA2B.z);

	Ray* ray = new Ray(p_attackingPlayerPos, vectorFromA2B);
	std::vector<float> listOfDistances;

	for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
	{
		if (RayOBBTest(ray, m_staticBoxList[i]))
		{
			if (p_isThrowing)
			{
				if (m_staticBoxList[i].m_extents.y > 1.8f)
				{
					listOfDistances.push_back(ray->m_distance);
				}
			}
			else
			{
				listOfDistances.push_back(ray->m_distance);
			}
		}
	}
	for (unsigned int i = 0; i < m_staticSphereList.size(); i++)
	{
		if (RaySphereTest(ray, m_staticSphereList[i]))
		{
			listOfDistances.push_back(ray->m_distance);
		}
	}	

	if (ray != nullptr)
	{
		delete ray;
		ray = nullptr;
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
	float temp = 0;
	if (IntersectionTests::Intersections::RayOBBCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_Obb.m_center, p_Obb.m_extents, p_Obb.m_direction, temp))
	{
		p_ray->m_distance = temp;
		return true;
	}
	else
	{
		return false;
	}
}
bool CollisionManager::RaySphereTest(Ray *p_ray, Sphere p_sphere)
{
	float temp = 0;
	if (IntersectionTests::Intersections::RaySphereCollision(p_ray->m_position, p_ray->m_direction, p_sphere.m_position, p_sphere.m_radius, temp))
	{
		p_ray->m_distance = temp;
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
						p_playerManager->DamagePlayer(playerList[j].guid, damage, owner.guid, ABILITIES_VOLLEY, false);
						break;
					}
				}
				remove = true;
			}
		}

		//Try to only play the sound once
		if (volleyList[i].timeToLand <= 0.0f && !volleyList[i].playedLandSound){
			volleyList[i].playedLandSound = true;
			p_volleyManager->PlayedSound(volleyList[i].id);
			p_playerManager->SendPlaySound(ABILITIES_VOLLEY, volleyList[i].endX, 0, volleyList[i].endZ);
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
			if (ray->m_distance > 0)
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

	
	// Se if we dashed through a player
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	int team = p_playerManager->GetPlayer(p_guid).team;
	// Go through player list
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		// Check so it isn't yourself
		// Check so you are not on the same team
		// Check so the player is still alive
		if (playerList[i].guid != p_guid && playerList[i].team != team && playerList[i].isAlive)
		{
			// Get the players bounding boxes
			std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(i);
			for (unsigned int j = 0; j < playerBoundingBoxes.size(); j++)
			{
				Box box = playerBoundingBoxes[j];
				if (Collisions::RayBoxCollision(ray, box))
				{
					// Check so distance to player is smaller than the dash distance (we have dashed through a player)
					if (ray->m_distance < dashLength)
					{
						if (!m_doneDashDamage)
						{
							// Damage player
							p_playerManager->DamagePlayer(playerList[i].guid, DASH_DAMAGE, p_guid, ABILITIES_DASH, false);
							m_doneDashDamage = true;
						}
					}
				}
			}
		}
	}

	if (ray != nullptr)
	{
		delete ray;
		ray = nullptr;
	}
	return dashLength;
}

void CollisionManager::POICollisionChecks(PointOfInterestManager* p_POIManager, PlayerManager* p_playerManager)
{
	std::vector<PlayerNet> playerList = p_playerManager->GetPlayers();
	std::vector<Box> lotusBBox = p_POIManager->GetBoundingBoxes(POINTOFINTERESTTYPE_HEAL);
	std::vector<Box> shieldBBox = p_POIManager->GetBoundingBoxes(POINTOFINTERESTTYPE_SHIELD);
	std::vector<Box> invisBBox = p_POIManager->GetBoundingBoxes(POINTOFINTERESTTYPE_INVISIBLE);

	// Go through player list
	for (unsigned int j = 0; j < playerList.size(); j++)
	{
		// Check so the player aren't already dead
		if (!playerList[j].isAlive)
		{
			continue;
		}

		// Get the players bounding boxes
		std::vector<Box> playerBoundingBoxes = p_playerManager->GetBoundingBoxes(j);

		// Make collision test
		for (unsigned int k = 0; k < lotusBBox.size(); k++)
		{
			for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
			{
				if (p_POIManager->IsRuneActive(POINTOFINTERESTTYPE_HEAL))
				{
					if (BoxBoxTest(playerBoundingBoxes[l], lotusBBox[k]))
					{
						p_playerManager->RuneLotusPickedUp(playerList[j].guid);
						p_POIManager->PickUpRunes(POINTOFINTERESTTYPE_HEAL, playerList[j].guid);
						p_playerManager->SendPlaySound(PLAYSOUND_RUNE_HEAL_PICKUP_SOUND, playerBoundingBoxes[l].m_center.x, playerBoundingBoxes[l].m_center.y, playerBoundingBoxes[l].m_center.z);
					}
				}
			}
		}

		// Make collision test
		for (unsigned int k = 0; k < invisBBox.size(); k++)
		{
			for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
			{
				if (p_POIManager->IsRuneActive(POINTOFINTERESTTYPE_INVISIBLE))
				{
					if (BoxBoxTest(playerBoundingBoxes[l], invisBBox[k]))
					{
						p_playerManager->RuneInvisPickedUp(playerList[j].guid);
						p_POIManager->PickUpRunes(POINTOFINTERESTTYPE_INVISIBLE, playerList[j].guid);
						p_playerManager->SendPlaySound(PLAYSOUND_RUNE_INVISIBLE_PICKUP_SOUND, playerBoundingBoxes[l].m_center.x, playerBoundingBoxes[l].m_center.y, playerBoundingBoxes[l].m_center.z);
					}
				}
			}
		}

		// Make collision test
		for (unsigned int k = 0; k < shieldBBox.size(); k++)
		{
			for (unsigned int l = 0; l < playerBoundingBoxes.size(); l++)
			{
				if (p_POIManager->IsRuneActive(POINTOFINTERESTTYPE_SHIELD))
				{
					if (BoxBoxTest(playerBoundingBoxes[l], shieldBBox[k]))
					{
						p_playerManager->RuneShieldPickedUp(playerList[j].guid);
						p_POIManager->PickUpRunes(POINTOFINTERESTTYPE_SHIELD, playerList[j].guid);
						p_playerManager->SendPlaySound(PLAYSOUND_RUNE_SHIELD_PICKUP_SOUND, playerBoundingBoxes[l].m_center.x, playerBoundingBoxes[l].m_center.y, playerBoundingBoxes[l].m_center.z);
					}
				}
			}
		}
	}
}