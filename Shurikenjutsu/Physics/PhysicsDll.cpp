// Physics.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#define PHYSICSDLL_EXPORTS
#include "PhysicsDll.h"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace IntersectionTests
{
	bool Intersections::SphereSphereCollision(DirectX::XMFLOAT3 p_sphere1Pos, float p_sphere1Rad, DirectX::XMFLOAT3 p_sphere2, float p_sphere2Rad)
	{
		DirectX::BoundingSphere sphere1 = DirectX::BoundingSphere(p_sphere1Pos, p_sphere1Rad);
		DirectX::BoundingSphere sphere2 = DirectX::BoundingSphere(p_sphere2, p_sphere2Rad);
		return sphere1.Intersects(sphere2);
	}
	bool Intersections::BoxBoxCollision(DirectX::XMFLOAT3 p_box1Center, DirectX::XMFLOAT3 p_box1Extents, DirectX::XMFLOAT3 p_box2Center, DirectX::XMFLOAT3 p_box2Extents)
	{
		DirectX::BoundingBox box1 = DirectX::BoundingBox(p_box1Center, p_box1Extents);
		DirectX::BoundingBox box2 = DirectX::BoundingBox(p_box2Center, p_box2Extents);
		return box1.Intersects(box2);
	}
	bool Intersections::SphereBoxCollision(DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents)
	{
		DirectX::BoundingBox box = DirectX::BoundingBox(p_boxCenter, p_boxExtents);
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_spherePosition, p_sphereRadius);
		return box.Intersects(sphere);
	}
/*	bool Intersections::FrustrumSphereCollision(DllFrustum p_frustum, DllSphere p_sphere)
	{
		DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_sphere.m_position, p_sphere.m_radius);
		return frustum.Intersects(sphere);
	}
	bool Intersections::FrustrumBoxCollision(DllFrustum p_frustum, DllBox p_box)
	{
		DirectX::BoundingFrustum frustum = DirectX::BoundingFrustum(p_frustum.m_position, p_frustum.m_direction, p_frustum.m_rightAngle, p_frustum.m_leftAngle, p_frustum.m_topAngle, p_frustum.m_bottomAngle, p_frustum.m_nearDistance, p_frustum.m_farDistance);
		DirectX::BoundingBox box = DirectX::BoundingBox(p_box.m_center, p_box.m_extents);
		return frustum.Intersects(box);
	}*/
	bool Intersections::RaySphereCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius)
	{
		float temp;
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_spherePosition, p_sphereRadius);
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, 0.0f));
		return sphere.Intersects(rayOrigin, rayDirection, temp);
	}
	bool Intersections::RayBoxCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents)
	{
		float temp;
		DirectX::BoundingBox box = DirectX::BoundingBox(p_boxCenter, p_boxExtents);
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, 0.0f));
		return box.Intersects(rayOrigin, rayDirection, temp);
	}
	bool Intersections::RayOBBCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT3 p_OBBDirection)
	{
		float temp;
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, 0.0f));
		DirectX::BoundingOrientedBox obb;
		DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb, DirectX::BoundingBox(p_OBBPosition, p_OBBExtents));
		return obb.Intersects(rayOrigin, rayDirection, temp);
	}
	bool Intersections::OBBOBBCollision(DirectX::XMFLOAT3 p_OBB1Position, DirectX::XMFLOAT3 p_OBBE1xtents, DirectX::XMFLOAT3 p_OBB1Direction, DirectX::XMFLOAT3 p_OBB2Position, DirectX::XMFLOAT3 p_OBB2Extents, DirectX::XMFLOAT3 p_OBB2Direction)
	{//TODO fix this shit
		DirectX::BoundingOrientedBox obb1;
		DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb1, DirectX::BoundingBox(p_OBB1Position, p_OBBE1xtents));
		DirectX::BoundingOrientedBox obb2;
		DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb2, DirectX::BoundingBox(p_OBB2Position, p_OBB2Extents));
		return obb1.Intersects(obb2);
	}

	bool Intersections::OBBSphereCollision(DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT3 p_OBBDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius)
	{
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_spherePosition, p_sphereRadius);
		DirectX::BoundingOrientedBox obb;
		DirectX::BoundingOrientedBox::CreateFromBoundingBox(obb, DirectX::BoundingBox(p_OBBPosition, p_OBBExtents));

		return obb.Intersects(sphere);
	}
	bool Intersections::MeleeAttackCollision(DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents, DirectX::XMFLOAT3 p_direction)
	{
		float tempBoxRadius;
		if (p_boxExtents.x > p_boxExtents.z)
		{
			tempBoxRadius = p_boxExtents.x;
		}
		else
		{
			tempBoxRadius = p_boxExtents.z;
		}

		if (SphereSphereCollision(p_spherePosition, p_sphereRadius, p_boxCenter, tempBoxRadius))
		{
			DirectX::XMFLOAT3 temp;
			temp.x = p_spherePosition.x + p_direction.x * p_sphereRadius;
			temp.y = p_spherePosition.y + p_direction.y * p_sphereRadius;
			temp.z = p_spherePosition.z + p_direction.z * p_sphereRadius;
			if (SphereBoxCollision(temp, p_sphereRadius, p_boxCenter, p_boxExtents))
			{
				return true;
			}
		}
		return false;
	}
}