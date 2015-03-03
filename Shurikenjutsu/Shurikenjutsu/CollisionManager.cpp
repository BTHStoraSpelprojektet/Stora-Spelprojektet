#include "CollisionManager.h"

#include "Collisions.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Globals.h"
CollisionManager* CollisionManager::m_instance;
CollisionManager::CollisionManager(){}
CollisionManager::~CollisionManager(){}

void CollisionManager::Initialize(std::vector<Object> p_StaticObjectList, std::vector<AnimatedObject*> p_animatedObjectList, std::vector<Box> p_outerWallList)
{
	m_staticBoxList = std::vector<OBB>();
	m_staticSphereList = std::vector<Sphere>();
	SetLists(p_StaticObjectList, p_animatedObjectList, p_outerWallList);
}

void CollisionManager::SetLists(std::vector<Object> p_StaticObjectList, std::vector<AnimatedObject*> p_animatedObjectList, std::vector<Box> p_outerWallList)
{
	m_staticBoxList.push_back(OBB(p_outerWallList[0]));
	m_staticBoxList.push_back(OBB(p_outerWallList[1]));

	m_staticBoxList.push_back(OBB(p_outerWallList[2]));
	m_staticBoxList.push_back(OBB(p_outerWallList[3]));

	// Go through all objects
	for (unsigned int i = 0; i < p_StaticObjectList.size(); i++)
	{
		std::vector<OBB> tempBoxList = p_StaticObjectList[i].GetBoundingBoxes();
		std::vector<Sphere> tempSphereList = p_StaticObjectList[i].GetBoundingSpheres();

		for (unsigned int j = 0; j < tempBoxList.size(); j++)
		{ 
			tempBoxList[j].CalculateRadius();
			m_staticBoxList.push_back(tempBoxList[j]);
		}
		for (unsigned int j = 0; j < tempSphereList.size(); j++)
		{
			m_staticSphereList.push_back(tempSphereList[j]);
		}
	}

	// Go through all animated objects
	for (unsigned int i = 0; i < p_animatedObjectList.size(); i++)
	{
		std::vector<OBB> tempBoxList = p_animatedObjectList[i]->GetBoundingBoxes();
		std::vector<Sphere> tempSphereList = p_animatedObjectList[i]->GetBoundingSpheres();

		for (unsigned int j = 0; j < tempBoxList.size(); j++)
		{
			tempBoxList[j].CalculateRadius();
			m_staticBoxList.push_back(tempBoxList[j]);
		}
		for (unsigned int j = 0; j < tempSphereList.size(); j++)
		{
			m_staticSphereList.push_back(tempSphereList[j]);
		}
	}
}

CollisionManager* CollisionManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CollisionManager();
	}
	return m_instance;
}

void CollisionManager::Shutdown()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

std::vector<OBB> CollisionManager::CalculateLocalPlayerCollisionWithStaticBoxes(OBB p_playerBox, float p_speed, DirectX::XMFLOAT3 p_direction)
{
	std::vector<OBB> CollisionList;
	if (p_playerBox.m_radius < 0)
	{
		return CollisionList;
	}
	Sphere playerSphere = Sphere(p_playerBox.m_center, p_playerBox.m_radius);
	float speedXDeltaTime = p_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	if (m_staticBoxList.size() > 0)
	{
		for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
		{
			OBB box = m_staticBoxList[i];

			playerSphere.m_position.x = p_playerBox.m_center.x + p_direction.x * speedXDeltaTime;
			playerSphere.m_position.y = p_playerBox.m_center.y + p_direction.y * speedXDeltaTime;
			playerSphere.m_position.z = p_playerBox.m_center.z + p_direction.z * speedXDeltaTime;

			if (playerSphere.m_position.y + playerSphere.m_radius < box.m_center.y - box.m_extents.y)
			{
				// Sphere bellow box
				playerSphere.m_position.y = p_playerBox.m_center.y + p_playerBox.m_extents.y - playerSphere.m_radius;
			}
			if (playerSphere.m_position.y - playerSphere.m_radius > box.m_center.y + box.m_extents.y)
			{
				// Sphere above box
				playerSphere.m_position.y = p_playerBox.m_center.y - p_playerBox.m_extents.y + playerSphere.m_radius;
			}
			if (Collisions::OBBSphereCollision(box, playerSphere))
			{
				CollisionList.push_back(box);
			}
		}
	}
	return CollisionList;
}

bool CollisionManager::CheckCollisionWithAllStaticObjects(Sphere p_sphere)
{
	if (m_staticBoxList.size() > 0)
	{
		for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
		{
			OBB temp = m_staticBoxList[i];
			temp.m_center.y = p_sphere.m_position.y;
			if (Collisions::SphereSphereCollision(Sphere(temp.m_center, temp.m_radius), p_sphere))
			{
				if (Collisions::OBBSphereCollision(temp, p_sphere))
				{
					return true;
				}
			}
		}
	}
	if (m_staticSphereList.size() > 0)
	{
		for (unsigned int i = 0; i < m_staticSphereList.size(); i++)
		{
			Sphere tempSphere = m_staticSphereList[i];
			tempSphere.m_position.y = p_sphere.m_position.y;
			if (Collisions::SphereSphereCollision(tempSphere, p_sphere))
			{
				return true;
			}
		}
	}
	return false;
}

std::vector<Sphere> CollisionManager::CalculateLocalPlayerCollisionWithStaticSpheres(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction)
{
	std::vector<Sphere> collisionList;
	Sphere playerSphere = p_playerSphere;
	float speedXDeltaTime = p_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	
	for (unsigned int i = 0; i < m_staticSphereList.size(); i++)
	{
		Sphere staticSphere = m_staticSphereList[i];

		playerSphere.m_position.x = p_playerSphere.m_position.x + p_direction.x * speedXDeltaTime;
		playerSphere.m_position.y = p_playerSphere.m_position.y + p_direction.y * speedXDeltaTime;
		playerSphere.m_position.z = p_playerSphere.m_position.z + p_direction.z * speedXDeltaTime;


		// Check so they will collide in y, othersize put both at y:0
		if ((staticSphere.m_position.y + staticSphere.m_radius) <= (playerSphere.m_position.y - playerSphere.m_radius) || (playerSphere.m_position.y + playerSphere.m_radius) <= (staticSphere.m_position.y + staticSphere.m_radius))
		{
			staticSphere.m_position.y = 0;
			playerSphere.m_position.y = 0;
		}


		if (Collisions::SphereSphereCollision(staticSphere, playerSphere))
		{
			collisionList.push_back(m_staticSphereList[i]);
		}
	}

	return collisionList;
}

float CollisionManager::CalculateDashLength(Ray* p_ray)
{
	Ray* ray = p_ray;
	float dashLength = 10.0f;
	std::vector<float> rayLengths;

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
	for (unsigned int i = 0; i < rayLengths.size(); i++)
	{
		if (rayLengths[i] < dashLength)
		{
			dashLength = rayLengths[i];
		}
	}

	return dashLength;
}

bool CollisionManager::CalculateRayLength(Ray* p_ray, float p_rayDistance)
{
	Ray* ray = p_ray;
	float rayLength = p_rayDistance;
	std::vector<float> rayLengths;

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
	for (unsigned int i = 0; i < rayLengths.size(); i++)
	{
		if (rayLengths[i] < rayLength)
		{
			rayLength = rayLengths[i];
		}
	}
	if (rayLength < p_rayDistance)
			return true;

	return false;
	//return rayLength;
}

float CollisionManager::CalculateMouseDistanceFromPlayer(DirectX::XMFLOAT3 p_playerPos)
{
	float x = m_pickedLocation.x - p_playerPos.x;
	float y = m_pickedLocation.y - p_playerPos.z;
	float temp = sqrt((x*x) + (y*y));
	return temp;
}

void CollisionManager::Update(float p_pickedx, float p_pickedZ)
{
	m_pickedLocation.x = p_pickedx;
	m_pickedLocation.y = p_pickedZ;
}
float CollisionManager::CalculateAttackPredictionRange(DirectX::XMFLOAT3 p_playerPos, DirectX::XMFLOAT3 p_direction, float p_lengthFromPlayer, bool p_throwStuff)
{
	DirectX::XMFLOAT3 tempPlayerPos = p_playerPos;
	float returnValue = p_lengthFromPlayer;
	float test = AttackPredictionLengthCalculation(tempPlayerPos, p_direction, p_lengthFromPlayer, p_throwStuff);

	tempPlayerPos.x -= 0.5f;
	float test1 = AttackPredictionLengthCalculation(tempPlayerPos, p_direction, p_lengthFromPlayer, p_throwStuff);

	tempPlayerPos = p_playerPos;
	tempPlayerPos.x += 0.5f;
	float test2 = AttackPredictionLengthCalculation(tempPlayerPos, p_direction, p_lengthFromPlayer, p_throwStuff);

	tempPlayerPos = p_playerPos;
	tempPlayerPos.z -= 0.5f;
	float test3 = AttackPredictionLengthCalculation(tempPlayerPos, p_direction, p_lengthFromPlayer, p_throwStuff);

	tempPlayerPos = p_playerPos;
	tempPlayerPos.z += 0.5f;
	float test4 = AttackPredictionLengthCalculation(tempPlayerPos, p_direction, p_lengthFromPlayer, p_throwStuff);

	if (returnValue > test)
	{
		returnValue = test;
	}
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
float CollisionManager::AttackPredictionLengthCalculation(DirectX::XMFLOAT3 p_playerPos, DirectX::XMFLOAT3 p_direction, float p_lengthFromPlayer, bool p_throwStuff)
{
	float height = 0.03f;
	DirectX::XMFLOAT3 rayDirection = DirectX::XMFLOAT3(p_direction.x, height, p_direction.z);
	DirectX::XMFLOAT3 rayPos = DirectX::XMFLOAT3(p_playerPos.x, height, p_playerPos.z);
	Ray* ray = new Ray(rayPos, rayDirection);
	std::vector<float> rayLengths;
	float returnValue = p_lengthFromPlayer;

	// Go through static boxes
	for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
	{
		if (Collisions::RayOBBCollision(ray, m_staticBoxList[i]))
		{
			if (ray->m_distance != 0 )
			{
				if (p_throwStuff)
				{
					if (m_staticBoxList[i].m_extents.y > 1.8f)
					{
						rayLengths.push_back(ray->m_distance);
					}
				}
				else
				{
					rayLengths.push_back(ray->m_distance);
				}
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

	if (ray != nullptr)
	{
		delete ray;
		ray = nullptr;
	}

	//Go through the shortest intersecting object
	for (unsigned int i = 0; i < rayLengths.size(); i++)
	{
		if (rayLengths[i] < returnValue)
		{
			returnValue = rayLengths[i];
		}
	}
	return returnValue;
}