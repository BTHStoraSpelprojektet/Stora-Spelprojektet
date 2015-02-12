#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "AnimatedObject.h"
#include "Object.h"


class CollisionManager
{
public:
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;

	void Initialize(std::vector<Object> p_StaticObjectList, std::vector<AnimatedObject*> p_animatedObjectList, std::vector<Box> p_outerWallList);
	static CollisionManager* GetInstance();

	void Shutdown();
	
	void Update(float p_pickedx, float p_pickedZ);
	std::vector<OBB> CalculateLocalPlayerCollisionWithStaticBoxes(OBB p_playerBox, float p_speed, DirectX::XMFLOAT3 p_direction);
	std::vector<Sphere> CalculateLocalPlayerCollisionWithStaticSpheres(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction);
	float CalculateDashLength(Ray* p_ray);
	bool CalculateRayLength(Ray* p_ray, float p_rayDistance);
	float CalculateMouseDistanceFromPlayer(DirectX::XMFLOAT3 p_playerPos);
	bool CheckCollisionWithAllStaticObjects(Sphere p_sphere);

private:

	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_instance;
	void SetLists(std::vector<Object> p_StaticObjectList, std::vector<AnimatedObject*> p_animatedObjectList, std::vector<Box> p_outerWallList);
	std::vector<OBB> m_staticBoxList;
	std::vector<Sphere> m_staticSphereList;
	DirectX::XMFLOAT2 m_pickedLocation;
};

#endif