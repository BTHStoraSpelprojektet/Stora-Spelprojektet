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

std::vector<OBB> CollisionManager::CalculateLocalPlayerCollisionWithStaticBoxes(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction)
{
	std::vector<OBB> CollisionList;
	Sphere playerSphere = p_playerSphere;
	float speedXDeltaTime = p_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	if (m_staticBoxList.size() > 0)
	{
		for (unsigned int i = 0; i < m_staticBoxList.size(); i++)
		{
			OBB box = m_staticBoxList[i];

			playerSphere.m_position.x = p_playerSphere.m_position.x + p_direction.x * speedXDeltaTime;
			playerSphere.m_position.y = p_playerSphere.m_position.y + p_direction.y * speedXDeltaTime;
			playerSphere.m_position.z = p_playerSphere.m_position.z + p_direction.z * speedXDeltaTime;

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