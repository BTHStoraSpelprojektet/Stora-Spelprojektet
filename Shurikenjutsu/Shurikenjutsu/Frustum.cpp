#include "Frustum.h"


Frustum::Frustum()
{
}

Frustum::Frustum(const Frustum&)
{

}


Frustum::~Frustum()
{
}

void Frustum::ConstructFrustum(float screenDepth, DirectX::XMFLOAT4X4 p_projectionMatrix, DirectX::XMFLOAT4X4 p_viewMatrix)
{
	float zMinimum, r;
	DirectX::XMFLOAT4X4 matrix;

	// Calc min Z dist in frustum
	zMinimum = -p_projectionMatrix._43 / p_projectionMatrix._33;
	r = screenDepth / (screenDepth - zMinimum);
	p_projectionMatrix._33 = r;
	p_projectionMatrix._43 = -r * zMinimum;

	// Create the frustum matrix from the view matrix and updated proj matrix
	DirectX::XMStoreFloat4x4(&matrix, DirectX::XMMatrixMultiply(DirectX::XMLoadFloat4x4(&p_viewMatrix), DirectX::XMLoadFloat4x4(&p_projectionMatrix)));
	// Calc near plane frustum
	m_planes[0].x = matrix._14 + matrix._13;
	m_planes[0].y = matrix._24 + matrix._23;
	m_planes[0].z = matrix._34 + matrix._33;
	m_planes[0].w = matrix._44 + matrix._43;
	DirectX::XMStoreFloat4(&m_planes[0], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[0])));

	// Calc far plane frustum
	m_planes[1].x = matrix._14 - matrix._13;
	m_planes[1].y = matrix._24 - matrix._23;
	m_planes[1].z = matrix._34 - matrix._33;
	m_planes[1].w = matrix._44 - matrix._43;
	DirectX::XMStoreFloat4(&m_planes[1], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[1])));

	// Calc left plane frustum
	m_planes[2].x = matrix._14 + matrix._11;
	m_planes[2].y = matrix._24 + matrix._21;
	m_planes[2].z = matrix._34 + matrix._31;
	m_planes[2].w = matrix._44 + matrix._41;
	DirectX::XMStoreFloat4(&m_planes[2], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[2])));

	// Calc right plane frustum
	m_planes[3].x = matrix._14 - matrix._11;
	m_planes[3].y = matrix._24 - matrix._21;
	m_planes[3].z = matrix._34 - matrix._31;
	m_planes[3].w = matrix._44 - matrix._41;
	DirectX::XMStoreFloat4(&m_planes[3], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[3])));

	// Calc top plane frustum
	m_planes[4].x = matrix._14 - matrix._12;
	m_planes[4].y = matrix._24 - matrix._22;
	m_planes[4].z = matrix._34 - matrix._32;
	m_planes[4].w = matrix._44 - matrix._42;
	DirectX::XMStoreFloat4(&m_planes[4], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[4])));
	
	// Calc bottom plane frustum
	m_planes[5].x = matrix._14 + matrix._12;
	m_planes[5].y = matrix._24 + matrix._22;
	m_planes[5].z = matrix._34 + matrix._32;
	m_planes[5].w = matrix._44 + matrix._42;
	DirectX::XMStoreFloat4(&m_planes[5], DirectX::XMPlaneNormalize(DirectX::XMLoadFloat4(&m_planes[5])));

	return;
}

bool Frustum::CheckPoint(float p_x, float p_y, float p_z)
{
	// Check if the point is inside all six planes of the view frustum
	for (int i = 0; i < 6; i++)
	{
		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(p_x, p_y, p_z))).m128_f32[0] < 0.0f)
		{
			return false;
		}
	}

	return true;
}

bool Frustum::CheckCube(float xCenter, float yCenter, float zCenter, float radius)
{
	// Check if any one point is in the view frustum
	for (int i = 0; i < 6; i++)
	{
		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - radius), (yCenter - radius), (zCenter - radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + radius), (yCenter - radius), (zCenter - radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - radius), (yCenter + radius), (zCenter - radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + radius), (yCenter + radius), (zCenter - radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - radius), (yCenter - radius), (zCenter + radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + radius), (yCenter - radius), (zCenter + radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - radius), (yCenter + radius), (zCenter + radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + radius), (yCenter + radius), (zCenter + radius)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		return false;
	}

	return true;
}

bool Frustum::CheckSphere(float xCenter, float yCenter, float zCenter, float radius)
{
	// Check if the radius of the sphere is inside the view frustum
	for (int i = 0; i < 6; i++)
	{
		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter), (yCenter), (zCenter)))).m128_f32[0] < -radius)
		{
			return false;
		}
	}

	return true;
}
bool Frustum::CheckSphere(Sphere p_sphere, float p_offset)
{
	return CheckSphere(p_sphere.m_position.x, p_sphere.m_position.y, p_sphere.m_position.z, p_sphere.m_radius + p_offset);
}


bool Frustum::CheckRectangle(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize)
{
	// Check if any one point is in the view frustum
	for (int i = 0; i < 6; i++)
	{
		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - xSize), (yCenter - ySize), (zCenter - zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + xSize), (yCenter - ySize), (zCenter - zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - xSize), (yCenter + ySize), (zCenter - zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + xSize), (yCenter + ySize), (zCenter - zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - xSize), (yCenter - ySize), (zCenter + zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + xSize), (yCenter - ySize), (zCenter + zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter - xSize), (yCenter + ySize), (zCenter + zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		if (DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(&m_planes[i]), DirectX::XMLoadFloat3(&DirectX::XMFLOAT3((xCenter + xSize), (yCenter + ySize), (zCenter + zSize)))).m128_f32[0] >= 0.0f)
		{
			continue;
		}

		return false;
	}

	return true;
}