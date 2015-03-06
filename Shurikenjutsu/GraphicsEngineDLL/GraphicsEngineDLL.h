#ifdef GRAPHICSENGINEDLL_EXPORTS
#define GRAPHICSENGINEDLL_API __declspec(dllexport)
#else
#define GRAPHICSENGINEDLL_API __declspec(dllimport)
#endif


namespace GraphicsEngine
{
	class GE
	{
	public:
		//static GRAPHICSENGINEDLL_API bool SphereSphereCollision(DirectX::XMFLOAT3 p_sphere1Pos, float p_sphere1Rad, DirectX::XMFLOAT3 p_sphere2, float p_sphere2Rad);
		//static GRAPHICSENGINEDLL_API bool BoxBoxCollision(DirectX::XMFLOAT3 p_box1Center, DirectX::XMFLOAT3 p_box1Extents, DirectX::XMFLOAT3 p_box2Center, DirectX::XMFLOAT3 p_box2Extents);
		//static GRAPHICSENGINEDLL_API bool SphereBoxCollision(DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents);

		//static GRAPHICSENGINEDLL_API bool RaySphereCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT4 p_rayDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius, float &p_returnValue);
		//static GRAPHICSENGINEDLL_API float RayBoxCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_boxCenter, DirectX::XMFLOAT3 p_boxExtents);

		//static GRAPHICSENGINEDLL_API bool RayOBBCollision(DirectX::XMFLOAT3 p_rayOrigin, DirectX::XMFLOAT3 p_rayDirection, DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT4 p_OBBDirection, float &p_returnValue);
		//static GRAPHICSENGINEDLL_API bool OBBOBBCollision(DirectX::XMFLOAT3 p_OBB1Position, DirectX::XMFLOAT3 p_OBB1Extents, DirectX::XMFLOAT4 p_OBB1Direction, DirectX::XMFLOAT3 p_OBB2Position, DirectX::XMFLOAT3 p_OBB2Extents, DirectX::XMFLOAT4 p_OBB2Direction);
		//static GRAPHICSENGINEDLL_API bool OBBSphereCollision(DirectX::XMFLOAT3 p_OBBPosition, DirectX::XMFLOAT3 p_OBBExtents, DirectX::XMFLOAT4 p_OBBDirection, DirectX::XMFLOAT3 p_spherePosition, float p_sphereRadius);

		//static GRAPHICSENGINEDLL_API bool MeleeAttackCollision(DirectX::XMFLOAT3 p_attackerPosition, float p_attackerRadius, DirectX::XMFLOAT3 p_attackDir, DirectX::XMFLOAT3 p_defenderCenter, DirectX::XMFLOAT3 p_defenderExtents, float p_defenderRadius);



	};
}
