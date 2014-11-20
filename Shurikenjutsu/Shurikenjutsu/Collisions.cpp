#include "Collisions.h"


Collisions::Collisions(){}
Collisions::~Collisions(){}
bool Collisions::SphereSphereCollision(Sphere p_sphere1, Sphere p_sphere2)
{
	DirectX::BoundingSphere sphere1 = DirectX::BoundingSphere(p_sphere1.m_position, p_sphere1.m_radius);
	DirectX::BoundingSphere sphere2 = DirectX::BoundingSphere(p_sphere2.m_position, p_sphere2.m_radius);

	if (sphere1.Intersects(sphere2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::BoxBoxCollision(Box p_box1, Box p_box2)
{
	DirectX::BoundingBox box1 = DirectX::BoundingBox(p_box1.m_center, p_box1.m_extents);
	DirectX::BoundingBox box2 = DirectX::BoundingBox(p_box2.m_center, p_box2.m_extents);

	if (box1.Intersects(box2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::SphereBoxCollision(Sphere p_sphere, Box p_box)
{
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);

	if (box.Intersects(sphere))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::FrustrumSphereCollision(Frustum p_frustum, Sphere p_sphere)
{
	DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	bool temp = frustum.Intersects(sphere);

	if (temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::FrustrumBoxCollision(Frustum p_frustum, Box p_box)
{
	DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);

	if (frustum.Intersects(box))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::RaySphereCollision(Ray p_ray, Sphere p_sphere)
{
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_ray.m_position.x, p_ray.m_position.y, p_ray.m_position.z, 0.0f);
	DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_ray.m_direction.x, p_ray.m_direction.y, p_ray.m_direction.z, 0.0f));

	if (sphere.Intersects(rayOrigin, rayDirection, p_ray.m_distance))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Collisions::RayBoxCollision(Ray p_ray, Box p_box)
{
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
	DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_ray.m_position.x, p_ray.m_position.y, p_ray.m_position.z, 0.0f);
	DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_ray.m_direction.x, p_ray.m_direction.y, p_ray.m_direction.z, 0.0f));

	if (box.Intersects(rayOrigin, rayDirection, p_ray.m_distance))
	{
		return true;
	}
	else
	{
		return false;
	}
}