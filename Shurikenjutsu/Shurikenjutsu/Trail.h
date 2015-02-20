#ifndef TRAIL
#define TRAIL

#include <d3d11.h>
#include <DirectXMath.h>

class Trail
{
public:
	bool Initialize(DirectX::XMFLOAT3 p_position);
	void Shutdown();

	void Update(DirectX::XMFLOAT3 p_position);
	void Render();

private:
	float m_pointsPerSecond;

	float m_timeToLive;
	float m_timePassed;

	float m_trailWidth;

	DirectX::XMFLOAT4 m_color;
	ID3D11ShaderResourceView* m_texture;

	ID3D11Buffer* m_vertexBuffer;
	unsigned int m_vertices;
};
#endif