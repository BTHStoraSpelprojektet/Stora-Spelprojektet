#ifndef DEBUGDOT
#define DEBUGDOT

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

class DebugDot
{
public:
	void Initialize(DirectX::XMFLOAT3 p_centrum, int p_resolution, DirectX::XMFLOAT3 p_color);
	void Shutdown();

	void Render();

	void UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);

private:
	ID3D11Buffer* m_mesh;
	int m_vertices;
	float m_radius;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT3 m_color;
};
#endif;