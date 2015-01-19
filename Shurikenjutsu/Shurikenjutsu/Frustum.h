#ifndef FRUSTUM_H_
#define FRUSTUM_H_

#include <DirectXMath.h>
#include "..\CommonLibs\CommonStructures.h"

class Frustum
{
public:
	Frustum();
	Frustum(const Frustum&);
	~Frustum();

	void ConstructFrustum(float screenDepth, DirectX::XMFLOAT4X4 p_projectionMatrix, DirectX::XMFLOAT4X4 p_viewMatrix);

	bool CheckPoint(float p_x, float p_y, float p_z);
	bool CheckCube(float xCenter, float yCenter, float zCenter, float radius);
	bool CheckSphere(float xCenter, float yCenter, float zCenter, float radius);
	bool CheckSphere(Sphere p_sphere, float p_offset);
	bool CheckRectangle(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize);

private:
	DirectX::XMFLOAT4 m_planes[6];
};

#endif FRUSTUM_H_