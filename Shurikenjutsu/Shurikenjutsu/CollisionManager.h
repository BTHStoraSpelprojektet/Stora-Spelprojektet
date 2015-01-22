#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Collisions.h"
#include "Globals.h"
#include "Object.h"

#include "..\CommonLibs\GameplayGlobalVariables.h"

class CollisionManager
{
public:
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;

	void Initialize(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/);
	static CollisionManager* GetInstance();
	
	void Update(float p_pickedx, float p_pickedZ);
	std::vector<OBB> CalculateLocalPlayerCollisionWithStaticBoxes(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction);
	std::vector<Sphere> CalculateLocalPlayerCollisionWithStaticSpheres(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction);
	float CalculateDashLength(Ray* p_ray);
	float CalculateMouseDistanceFromPlayer(DirectX::XMFLOAT3 p_playerPos);
private:

	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_instance;
	void SetLists(std::vector<Object> p_StaticObjectList, std::vector<Box> p_outerWallList/*, std::vector<Sphere> p_sphereObjectList*/);
	std::vector<OBB> m_staticBoxList;
	std::vector<Sphere> m_staticSphereList;
	DirectX::XMFLOAT2 m_pickedLocation;
	//std::vector<Sphere> m_sphereObjectList;
};

#endif