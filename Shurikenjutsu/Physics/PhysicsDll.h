#ifdef PHYSICSDLL_EXPORTS
#define PHYSICSDLL_API __declspec(dllexport)
#else
#define PHYSICSDLL_API __declspec(dllimport)
#endif

#include <DirectXCollision.h>

namespace IntersectionTests
{
	class Intersections
	{
	public:
		static PHYSICSDLL_API bool SphereSphereCollision(DirectX::XMFLOAT3 p_sphere1Pos, float p_sphere1Rad, DirectX::XMFLOAT3 p_sphere2, float p_sphere2Rad);
		static PHYSICSDLL_API bool BoxBoxCollision(DirectX::XMFLOAT3 p_box1Center, DirectX::XMFLOAT3 p_box1Extents, DirectX::XMFLOAT3 p_box2Center, DirectX::XMFLOAT3 p_box2Extents);
		static PHYSICSDLL_API bool SphereBoxCollision(DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents);

		//static PHYSICSDLL_API bool FrustrumSphereCollision(DllFrustum p_frustum, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius);
		//static PHYSICSDLL_API bool FrustrumBoxCollision(DllFrustum p_frustum, DllBox p_box);

		static PHYSICSDLL_API bool RaySphereCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius);
		static PHYSICSDLL_API bool RayBoxCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents);

		static PHYSICSDLL_API bool RayOBBCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT3 p_OBBDirection);
		static PHYSICSDLL_API bool OBBOBBCollision(DirectX::XMFLOAT3 p_OBB1Position, DirectX::XMFLOAT3 p_OBBE1xtents, DirectX::XMFLOAT3 p_OBB1Direction, DirectX::XMFLOAT3 p_OBB2Position, DirectX::XMFLOAT3 p_OBB2Extents, DirectX::XMFLOAT3 p_OBB2Direction);
		static PHYSICSDLL_API bool OBBSphereCollision(DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT3 p_OBBDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius);

		static PHYSICSDLL_API bool MeleeAttackCollision(DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents, DirectX::XMFLOAT3 p_direction);
	};		
}





//include in while where you want to reach the dll
/*

#pragma comment(lib, "PhysicsDll.lib")
#include "PhysicsDll.h"


*/