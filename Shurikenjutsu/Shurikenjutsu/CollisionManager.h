#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Collisions.h"
#include "Globals.h"
#include "Object.h"


class CollisionManager
{
public:
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;

	void Initialize(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/);
	static CollisionManager* GetInstance();


	std::vector<OBB> CalculateLocalPlayerCollisionWithStaticObjects(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction);
	std::vector<bool> OuterWallCollision(Sphere p_playerSphere);
private:

	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_instance;
	void SetLists(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/);
	std::vector<OBB> m_StaticObjectList;
	std::vector<Box> m_outerWallList;
	//std::vector<Sphere> m_sphereObjectList;
};

#endif