#ifndef DEBUGRECTANGLE
#define DEBUGRECTANGLE

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"

class DebugRectangle
{
public:
	DebugRectangle();
	bool Initialize(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, DirectX::XMFLOAT3 p_color);
	void Shutdown();

	void Render();

	void UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);

private:
	ID3D11Buffer* m_mesh;
	int m_vertices;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT3 m_color;
};
#endif;