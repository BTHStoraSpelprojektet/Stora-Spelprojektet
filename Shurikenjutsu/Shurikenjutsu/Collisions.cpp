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
bool Collisions::FrustrumSphereCollision(Frustum p_frustum, Sphere p_sphere)
{
	DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	return frustum.Intersects(sphere);
}
bool Collisions::FrustrumBoxCollision(Frustum p_frustum, Box p_box)
{
	DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
	return frustum.Intersects(box);
}
bool Collisions::RaySphereCollision(Ray* p_ray, Sphere p_sphere)
{
	return IntersectionTests::Intersections::RaySphereCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_sphere.m_position, p_sphere.m_radius);
}
bool Collisions::RayBoxCollision(Ray *p_ray, Box p_box)
{
	return IntersectionTests::Intersections::RayBoxCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_box.m_center, p_box.m_extents);
}
bool Collisions::RayOBBCollision(Ray *p_ray, OBB p_OBB)
{	
	return IntersectionTests::Intersections::RayOBBCollision(p_ray->m_position, DirectX::XMFLOAT3(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z), p_OBB.m_center, p_OBB.m_extents, DirectX::XMFLOAT3(p_OBB.m_direction.x, p_OBB.m_direction.y, p_OBB.m_direction.z));
}
bool Collisions::OBBOBBCollision(OBB p_OBB1, OBB p_OBB2)
{
	return IntersectionTests::Intersections::OBBOBBCollision(p_OBB1.m_center, p_OBB1.m_extents, DirectX::XMFLOAT3(p_OBB1.m_direction.x, p_OBB1.m_direction.y, p_OBB1.m_direction.z),p_OBB2.m_center, p_OBB2.m_extents, DirectX::XMFLOAT3(p_OBB2.m_direction.x, p_OBB2.m_direction.y, p_OBB2.m_direction.z));
}
bool Collisions::OBBSphereCollision(OBB p_OBB, Sphere p_sphere)
{
	return IntersectionTests::Intersections::OBBSphereCollision(p_OBB.m_center, p_OBB.m_extents, DirectX::XMFLOAT3(p_OBB.m_direction.x, p_OBB.m_direction.y, p_OBB.m_direction.z), p_sphere.m_position, p_sphere.m_radius);
}
bool Collisions::MeleeAttackCollision(Sphere p_sphere, Box p_box, DirectX::XMFLOAT3 p_direction)
{
	float tempBoxRadius;
	if (p_box.m_extents.x > p_box.m_extents.x)
	{
		tempBoxRadius = p_box.m_extents.x;
	}
	else
	{
		tempBoxRadius = p_box.m_extents.z;
	}

	if (SphereSphereCollision(p_sphere, Sphere(p_box.m_center, tempBoxRadius)))
	{
		DirectX::XMFLOAT3 temp;
		temp.x = p_sphere.m_position.x + p_direction.x * p_sphere.m_radius;
		temp.y = p_sphere.m_position.y + p_direction.y * p_sphere.m_radius;
		temp.z = p_sphere.m_position.z + p_direction.z * p_sphere.m_radius;
		if (SphereBoxCollision(Sphere(temp, p_sphere.m_radius), p_box))
		{
			return true;
		}
	}
	return false;
}