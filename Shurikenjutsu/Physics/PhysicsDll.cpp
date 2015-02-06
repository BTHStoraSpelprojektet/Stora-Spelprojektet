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
	bool Intersections::RaySphereCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT4 p_rayDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, float *p_returnValue)
	{
		float temp;
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_spherePosition, p_sphereRadius);
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, p_rayDirection.w));
		bool boolValue = sphere.Intersects(rayOrigin, rayDirection, temp);
		*p_returnValue = temp;
		return boolValue;
	}
	float Intersections::RayBoxCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents)
	{
		float temp = 0;
		DirectX::BoundingBox box = DirectX::BoundingBox(p_boxCenter, p_boxExtents);
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, 0.0f));
		bool temp2 = box.Intersects(rayOrigin, rayDirection, temp);
		return temp;
	}
	bool Intersections::RayOBBCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT4 p_OBBDirection, float* p_returnValue)
	{
		float temp2 = 0;
		DirectX::XMVECTOR rayOrigin = DirectX::XMVectorSet(p_rayOrigin.x, p_rayOrigin.y, p_rayOrigin.z, 0.0f);
		DirectX::XMVECTOR rayDirection = DirectX::XMVector3Normalize(DirectX::XMVectorSet(p_rayDirection.x, p_rayDirection.y, p_rayDirection.z, 0.0f));
		DirectX::BoundingOrientedBox obb;
		obb.Center = p_OBBPosition;
		obb.Extents = p_OBBExtents;
		obb.Orientation = p_OBBDirection; 
		float asdf;
		bool temp = obb.Intersects(rayOrigin,rayDirection, asdf);
		*p_returnValue = asdf;
		//bool temp = obb.Intersects(rayOrigin, rayDirection, p_returnValue);
		return temp;
	}
	bool Intersections::OBBOBBCollision(DirectX::XMFLOAT3 p_OBB1Position, DirectX::XMFLOAT3 p_OBB1Extents, DirectX::XMFLOAT4 p_OBB1Direction, DirectX::XMFLOAT3 p_OBB2Position, DirectX::XMFLOAT3 p_OBB2Extents, DirectX::XMFLOAT4 p_OBB2Direction)
	{
		DirectX::BoundingOrientedBox obb1;
		DirectX::BoundingOrientedBox obb2;
		obb1.Center = p_OBB1Position;
		obb1.Extents = p_OBB1Extents;
		obb1.Orientation = p_OBB1Direction;
		obb2.Center = p_OBB2Position;
		obb2.Extents = p_OBB2Extents;
		obb2.Orientation = p_OBB2Direction;
		return obb1.Intersects(obb2);
	}

	bool Intersections::OBBSphereCollision(DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT4 p_OBBDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius)
	{
		DirectX::BoundingSphere sphere = DirectX::BoundingSphere(p_spherePosition, p_sphereRadius);
		DirectX::BoundingOrientedBox obb = DirectX::BoundingOrientedBox(p_OBBPosition, p_OBBExtents, p_OBBDirection);

		return obb.Intersects(sphere);
	}

	bool Intersections::MeleeAttackCollision(DirectX::XMFLOAT3 p_attackerPosition, float p_attackerRadius, DirectX::XMFLOAT3 p_attackDir, DirectX::XMFLOAT3 p_defenderCenter, DirectX::XMFLOAT3 p_defenderExtents, float p_defenderRadius)
	{
		if (SphereSphereCollision(p_attackerPosition, p_attackerRadius, p_defenderCenter, p_defenderRadius))
		{
			DirectX::XMFLOAT3 temp;
			temp.x = p_attackerPosition.x + p_attackDir.x * p_attackerRadius;
			temp.y = p_attackerPosition.y + p_attackDir.y * p_attackerRadius;
			temp.z = p_attackerPosition.z + p_attackDir.z * p_attackerRadius;
			if (SphereBoxCollision(temp, p_attackerRadius, p_defenderCenter, p_defenderExtents))
			{
				return true;
			}
		}
		return false;
	}
}