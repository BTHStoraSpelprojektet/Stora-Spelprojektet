#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include <DirectXMath.h>
class Object;
class AnimatedObject;

struct OBB;
struct Box;
struct Sphere;
struct Ray;

class CollisionManager
{
public:
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;

	void SetOuterWallList(std::vector<Box> p_outerWallList);
	static CollisionManager* GetInstance();

	void Shutdown();
	
	void Update(float p_pickedx, float p_pickedZ);
	std::vector<OBB> CalculateLocalPlayerCollisionWithStaticBoxes(OBB p_playerBox, float p_speed, DirectX::XMFLOAT3 p_direction);
	std::vector<Sphere> CalculateLocalPlayerCollisionWithStaticSpheres(Sphere p_playerSphere, float p_speed, DirectX::XMFLOAT3 p_direction);
	bool CalculateRayLength(Ray* p_ray, float p_rayDistance);
	float CalculateMouseDistanceFromPlayer(DirectX::XMFLOAT3 p_playerPos);
	bool CheckCollisionWithAllStaticObjects(Sphere p_sphere);
	float CalculateAttackPredictionRange(DirectX::XMFLOAT3 p_playerPos, DirectX::XMFLOAT3 p_direction, float p_lengthFromPlayer, bool p_throwStuff);
	void SetObjectsInFrustumList(std::vector<Object*> p_objectsInFrustumList, std::vector<AnimatedObject*> p_animatedObjectList);
	float CalculateOutliningRayDistance(Ray* p_ray);
	float CalculatThrowDistanceChekcingOuterWalls(Ray* p_ray);
	bool IntersectingObjectWhenAttacking(DirectX::XMFLOAT3 p_attackingPlayerPos, DirectX::XMFLOAT3 p_defendingPlayerPos, bool p_isThrowing);

private:	
	bool RayOBBTest(Ray *p_ray, OBB p_Obb);
	bool RaySphereTest(Ray *p_ray, Sphere p_sphere);
	float AttackPredictionLengthCalculation(DirectX::XMFLOAT3 p_playerPos, DirectX::XMFLOAT3 p_direction, float p_lengthFromPlayer, bool p_throwStuff);

	CollisionManager();
	~CollisionManager();
	static CollisionManager* m_instance;
	void SetLists(std::vector<Object*> p_StaticObjectList, std::vector<AnimatedObject*> p_animatedObjectList, std::vector<OBB> p_outerWallList);

	std::vector<OBB> m_staticBoxList;
	std::vector<OBB> m_treeTopBoxList;
	std::vector<Sphere> m_treeTopSphereList;
	std::vector<Sphere> m_staticSphereList;
	DirectX::XMFLOAT2 m_pickedLocation;
	std::vector<OBB> m_outerWallList;
};

#endif