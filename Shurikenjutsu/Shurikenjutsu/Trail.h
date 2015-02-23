#ifndef TRAIL
#define TRAIL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>
#include <vector>
#include "TrailRenderer.h"

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

	std::vector<TrailPoint> m_points;
	ID3D11Buffer* m_vertexBuffer;
};
#endif