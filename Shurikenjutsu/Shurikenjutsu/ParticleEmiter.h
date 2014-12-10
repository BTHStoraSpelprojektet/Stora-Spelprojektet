#ifndef EMITER
#define EMITER

#include <d3d11.h>
#include <DirectXMath.h>

#include "ConsoleFunctions.h"
#include "Globals.h"
#include "Enumerations.h"

class ParticleEmiter
{
public:
	bool Initialize(ID3D11Device* p_device, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction, float p_size, PARTICLE_PATTERN p_pattern);
	void Shutdown();

	void Update(ID3D11DeviceContext* p_context);
	void Render(ID3D11DeviceContext* p_context);

	void  SetPosition(DirectX::XMFLOAT3 p_position);
	void  SetDirection(DirectX::XMFLOAT3 p_direction);
	void  SetColor(DirectX::XMFLOAT4 p_color);

private:
	void ClearOldParticles();
	void EmitParticles();
	void UpdateParticles();
	void UpdateBuffers(ID3D11DeviceContext* p_deviceContext);

	PARTICLE_PATTERN m_pattern;
	DirectX::XMFLOAT3 m_emitterPosition;
	DirectX::XMFLOAT3 m_emitterDirection;
	DirectX::XMFLOAT3 m_emitionPositionOffset;
	DirectX::XMFLOAT4 m_color;

	ID3D11ShaderResourceView* m_particleTexture;
	float m_particleSize;

	float m_velocity;
	float m_velocityVariation;

	float m_particlesPerSecond;
	float m_time;

	unsigned int m_maxParticles;
	unsigned int m_currentParticles;

	struct Particle
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT3 m_direction;
		DirectX::XMFLOAT4 m_color;

		float m_velocity;

		bool m_alive;

		float m_timeToLive;
		float m_timePassed;
	};
	Particle* m_particleList;
	
	struct ParticleVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_UVCoordinates;
		DirectX::XMFLOAT4 m_color;
	};
	ParticleVertex* m_mesh;

	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_indexBuffer;

	unsigned int m_vertices;
	unsigned int m_indices;
};
#endif