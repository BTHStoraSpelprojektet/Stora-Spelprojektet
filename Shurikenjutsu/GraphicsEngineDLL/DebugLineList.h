#ifndef DEBUGLINELIST
#define DEBUGLINELIST

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

class DebugLineList
{ 
public:
	void Initialize(DirectX::XMFLOAT3 p_color);
	void Shutdown();

	void AddLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint);
	void RemoveLine(int p_index);

	void Render();

	void UpdateWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix);

private:
	std::vector<DirectX::XMFLOAT3> m_lines;
	ID3D11Buffer* m_mesh;
	int m_vertices;

	DirectX::XMFLOAT4X4 m_worldMatrix;
	DirectX::XMFLOAT3 m_color;
};
#endif;