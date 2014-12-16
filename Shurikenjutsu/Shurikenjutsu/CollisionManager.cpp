#include "CollisionManager.h"

CollisionManager* CollisionManager::m_instance;
CollisionManager::CollisionManager(){}
CollisionManager::~CollisionManager(){}
void CollisionManager::Initialize(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/)
{
	SetLists(p_StaticObjectList, p_outerWallList/*, p_sphereObjectList*/);
}
void CollisionManager::SetLists(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/)
{
	//m_StaticObjectList.push_back(OBB(p_outerWallList[0].m_center, p_outerWallList[0].m_extents.z, p_outerWallList[0].m_extents.y, p_outerWallList[0].m_extents.x, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)));
	m_StaticObjectList.push_back(OBB(p_outerWallList[0])); 
	m_StaticObjectList.push_back(OBB(p_outerWallList[1]));

	//m_StaticObjectList.push_back(OBB(p_outerWallList[2].m_center, p_outerWallList[2].m_extents.z, p_outerWallList[2].m_extents.y, p_outerWallList[2].m_extents.x, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f)));	//NOT WORKING
	m_StaticObjectList.push_back(OBB(p_outerWallList[2]));	
	m_StaticObjectList.push_back(OBB(p_outerWallList[3]));
	for (unsigned int i = 0; i < p_StaticObjectList.size(); i++)
	{
		std::vector<OBB> tempList = p_StaticObjectList[i].GetBoundingBoxes();
		if (tempList.size() != 0)
		{
			for (unsigned int j = 0; j < tempList.size(); j++)
			{ 
				m_StaticObjectList.push_back(tempList[j]);
			}
		}
	}

	//for (unsigned int i = 0; i < p_sphereObjectList.size(); i++)
	//{
	//	m_sphereObjectList.push_back(p_sphereObjectList[i]);
	//}
}
CollisionManager* CollisionManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CollisionManager();
	}
	return m_instance;
}

std::vector<OBB> CollisionManager::CalculateLocalPlayerCollisionWithStaticObjects(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction)
{
	std::vector<OBB> CollisionList;
	Sphere playerBox = p_playerSphere;
	float speedXDeltaTime = p_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
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

float CollisionManager::CalculateDashLength(Ray* p_ray)
{
	Ray* ray = p_ray;
	float dashLength = 10.0f;
	std::vector<float> rayLengths;

	for (int i = 0; i < m_StaticObjectList.size(); i++)
	{
		if (Collisions::RayOBBCollision(ray, m_StaticObjectList[i]));
		{
			if (ray->m_distance != 0)
			{
				rayLengths.push_back(ray->m_distance);
			}
		}
	}
	for (int i = 0; i < rayLengths.size(); i++)
	{
		if (rayLengths[i] < dashLength)
		{
			dashLength = rayLengths[i];
		}
	}

	return dashLength;
}