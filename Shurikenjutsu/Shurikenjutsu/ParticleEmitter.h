#ifndef EMITER
#define EMITER

#include <d3d11.h>
#include <DirectXMath.h>

#include "ConsoleFunctions.h"
#include "Globals.h"
#include "Enumerations.h"
#include "GraphicsEngine.h"
#include "../CommonLibs/ModelImporter.h"

class ParticleEmitter
{
public:
	bool Initialize(ID3D11Device* p_device, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction, DirectX::XMFLOAT2 p_size, PARTICLE_PATTERN p_pattern);
	void Shutdown();

	void Update();
	void Render();

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void SetDirection(DirectX::XMFLOAT3 p_direction);
	void SetColor(DirectX::XMFLOAT4 p_color);

	void UpdateMatrix(DirectX::XMFLOAT4X4 p_world);
	void UpdatePosition(DirectX::XMFLOAT3 p_position);
	void UpdateDirection(DirectX::XMFLOAT3 p_direction);

	void SetEmitParticleState(bool p_emit);

	int GetParticleCount();

private:

	bool m_emit;
	void ClearOldParticles();
	void EmitParticles();
	void UpdateParticles();
	void UpdateBuffers();
	ID3D11ShaderResourceView* LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels);

	PARTICLE_PATTERN m_pattern;
	DirectX::XMFLOAT3 m_emitterPosition;
	DirectX::XMFLOAT3 m_emitterDirection;
	DirectX::XMFLOAT3 m_emitionPositionOffset;
	DirectX::XMFLOAT4 m_color;
	DirectX::XMFLOAT4X4 m_worldMatrix;

	ID3D11ShaderResourceView* m_particleTexture;
	DirectX::XMFLOAT2 m_particleSize;

	float m_velocity;
	float m_velocityVariation;

	float m_particlesPerSecond;
	float m_time;

	float m_timeToLive;

	unsigned int m_maxParticles;
	unsigned int m_currentParticles;

	struct Particle
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT3 m_direction;
		DirectX::XMFLOAT4 m_color;

		float m_velocity;
		float m_rotation;

		bool m_alive;

		float m_timeToLive;
		float m_timePassed;
	};
	Particle* m_particleList;
	
	struct ParticleVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_size;
		DirectX::XMFLOAT4 m_color;
	};
	ParticleVertex* m_mesh;

	ID3D11Buffer* m_vertexBuffer;
	unsigned int m_vertices;
};
#endif