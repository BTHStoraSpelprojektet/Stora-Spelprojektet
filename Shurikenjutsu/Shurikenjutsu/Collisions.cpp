#include "Collisions.h"


bool Collisions::SphereSphereCollision(Sphere p_sphere1, Sphere p_sphere2)
{
	DirectX::BoundingSphere sphere1 = DirectX::BoundingSphere(p_sphere1.m_position, p_sphere1.m_radius);
	DirectX::BoundingSphere sphere2 = DirectX::BoundingSphere(p_sphere2.m_position, p_sphere2.m_radius);
	return sphere1.Intersects(sphere2);
}
bool Collisions::BoxBoxCollision(Box p_box1, Box p_box2)
{
	DirectX::BoundingBox box1 = DirectX::BoundingBox(p_box1.m_center, p_box1.m_extents);
	DirectX::BoundingBox box2 = DirectX::BoundingBox(p_box2.m_center, p_box2.m_extents);
	return box1.Intersects(box2);
}
bool Collisions::SphereBoxCollision(Sphere p_sphere, Box p_box)
{
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	return box.Intersects(sphere);
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
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_ray->m_position.x, p_ray->m_position.y, p_ray->m_position.z, 0.0f);
	DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z, 0.0f));
	return sphere.Intersects(rayOrigin, rayDirection, p_ray->m_distance);
}
bool Collisions::RayBoxCollision(Ray *p_ray, Box p_box)
{
	DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
	DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_ray->m_position.x, p_ray->m_position.y, p_ray->m_position.z, 0.0f);
	DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z, 0.0f));
	return box.Intersects(rayOrigin, rayDirection, p_ray->m_distance);
}
bool Collisions::RayOBBCollision(Ray *p_ray, OBB p_OBB)
{
	DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_ray->m_position.x, p_ray->m_position.y, p_ray->m_position.z, 0.0f);
	DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_ray->m_direction.x, p_ray->m_direction.y, p_ray->m_direction.z, 0.0f));
	DirectX::BoundingOrientedBox obb;
	DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb, DirectX::BoundingBox(p_OBB.m_center, p_OBB.m_extents));
	return obb.Intersects(rayOrigin, rayDirection, p_ray->m_distance);
}
bool Collisions::OBBOBBCollision(OBB p_OBB1, OBB p_OBB2)
{
	DirectX::BoundingOrientedBox obb1;
	DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb1, DirectX::BoundingBox(p_OBB1.m_center, p_OBB1.m_extents));
	DirectX::BoundingOrientedBox obb2;
	DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb2, DirectX::BoundingBox(p_OBB2.m_center, p_OBB2.m_extents));
	return obb1.Intersects(obb2);
}

bool Collisions::OBBSphereCollision(OBB p_OBB, Sphere p_sphere)
{
	DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
	DirectX::BoundingOrientedBox obb;
	DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb, DirectX::BoundingBox(p_OBB.m_center, p_OBB.m_extents));

	return obb.Intersects(sphere);
}