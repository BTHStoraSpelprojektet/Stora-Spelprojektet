#ifndef DEBUGSHAPE2D
#define DEBUGSHAPE2D

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

class DebugShape2D
{
public:
	DebugShape2D(std::vector<DirectX::XMFLOAT3> p_shape, DirectX::XMFLOAT3 p_color);
	~DebugShape2D();

	void Render();

	void UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);

private:
	ID3D11Buffer* m_mesh;
	int m_vertices;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT3 m_color;
};
#endif;