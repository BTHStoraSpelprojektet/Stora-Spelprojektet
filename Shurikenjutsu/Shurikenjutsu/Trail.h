#ifndef TRAIL
#define TRAIL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

struct TrailPoint
{
	DirectX::XMFLOAT3 m_position;
	float m_angle;
	float m_width;
	DirectX::XMFLOAT2 m_timeValues;
	DirectX::XMFLOAT4 m_color;
	bool m_endpoint;
};

struct TrailSegment
{
	TrailPoint m_top;
	TrailPoint m_bottom;
};

class Trail
{
public:
	Trail();
	~Trail();

	bool Initialize(float p_pointsPerSecond, float p_timeToLive, float p_trailWidth, DirectX::XMFLOAT4 p_color, std::string p_texturePath);
	void Shutdown();

	void Update(DirectX::XMFLOAT3 p_position, float p_angle);
	void Render();

	void StopEmiting();
	bool IsTrailDead();

private:
	void EmitPoint(DirectX::XMFLOAT3 p_position, float p_angle);
	void ClearOldPoints();

	float m_pointsPerSecond;
	float m_timeSinceLastEmission;
	bool m_timeToEmit;
	bool m_emiting;
	bool m_listDead;

	float m_TrailPointLifeTime;

	float m_trailWidth;

	DirectX::XMFLOAT4 m_color;
	ID3D11ShaderResourceView* m_texture;

	std::vector<TrailSegment> m_segments;
	ID3D11Buffer* m_vertexBuffer;
	unsigned int m_vertices;
};
#endif