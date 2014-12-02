#pragma once
#include <DirectXCollision.h>
#include "Structures.h"
#pragma comment(lib, "PhysicsDll.lib")
#include "PhysicsDll.h"

class Collisions
{
public:

	static bool SphereSphereCollision(Sphere p_sphere1, Sphere p_sphere2);
	static bool BoxBoxCollision(Box p_box1, Box p_box2);
	static bool SphereBoxCollision(Sphere p_sphere, Box p_box);

	static bool FrustrumSphereCollision(Frustum p_frustum, Sphere p_sphere);
	static bool FrustrumBoxCollision(Frustum p_frustum, Box p_box);

	static bool RaySphereCollision(Ray *p_ray, Sphere p_sphere);
	static bool RayBoxCollision(Ray *p_ray, Box p_box);

	static bool RayOBBCollision(Ray *p_ray, OBB p_OBB);
	static bool OBBOBBCollision(OBB p_OBB1, OBB p_OBB2);
	static bool OBBSphereCollision(OBB p_OBB, Sphere p_sphere);
	static bool MeleeAttackCollision(Sphere p_sphere, Box p_box, DirectX::XMFLOAT3 p_direction);
};

