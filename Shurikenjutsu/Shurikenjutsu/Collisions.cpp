#include "Collisions.h"


bool Collisions::SphereSphereCollision(Sphere p_sphere1, Sphere p_sphere2)
{
	return IntersectionTests::Intersections::SphereSphereCollision(p_sphere1.m_position, p_sphere1.m_radius, p_sphere2.m_position, p_sphere2.m_radius);
}
bool Collisions::BoxBoxCollision(Box p_box1, Box p_box2)
{
	return IntersectionTests::Intersections::BoxBoxCollision(p_box1.m_center, p_box1.m_extents,p_box2.m_center, p_box2.m_extents);
}
bool Collisions::SphereBoxCollision(Sphere p_sphere, Box p_box)
{
	return IntersectionTests::Intersections::SphereBoxCollision(p_sphere.m_position, p_sphere.m_radius, p_box.m_center, p_box.m_extents);
}
bool Collisions::RaySphereCollision(Ray* p_ray, Sphere p_sphere)
{
	return IntersectionTests::Intersections::RaySphereCollision(p_ray->m_position, p_ray->m_direction, p_sphere.m_position, p_sphere.m_radius, &p_ray->m_distance);
}
bool Collisions::RayBoxCollision(Ray *p_ray, Box p_box)
{
	p_ray->m_distance = IntersectionTests::Intersections::RayBoxCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_box.m_center, p_box.m_extents);
	if (p_ray->m_distance == 0)
	{
		return false;
	}
	return true;
}
bool Collisions::RayOBBCollision(Ray *p_ray, OBB p_OBB)
{	
	bool temp = IntersectionTests::Intersections::RayOBBCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_OBB.m_center, p_OBB.m_extents, p_OBB.m_direction, &p_ray->m_distance);
	//bool temp2 = RayBoxCollision(p_ray, Box(p_OBB.m_center, p_OBB.m_extents));

	return temp;
}
bool Collisions::OBBOBBCollision(OBB p_OBB1, OBB p_OBB2)
{
	return IntersectionTests::Intersections::OBBOBBCollision(p_OBB1.m_center, p_OBB1.m_extents, p_OBB1.m_direction,p_OBB2.m_center, p_OBB2.m_extents, p_OBB2.m_direction);
}
bool Collisions::OBBSphereCollision(OBB p_OBB, Sphere p_sphere)
{
	return IntersectionTests::Intersections::OBBSphereCollision(p_OBB.m_center, p_OBB.m_extents, p_OBB.m_direction, p_sphere.m_position, p_sphere.m_radius);
}
bool Collisions::MeleeAttackCollision(Sphere p_sphere, Box p_box, DirectX::XMFLOAT3 p_attDirection)
{
	return IntersectionTests::Intersections::MeleeAttackCollision(p_sphere.m_position, p_sphere.m_radius, p_attDirection, p_box.m_center, p_box.m_extents, p_box.m_radius);
}