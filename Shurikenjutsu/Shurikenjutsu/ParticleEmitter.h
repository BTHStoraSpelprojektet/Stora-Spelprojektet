#ifndef EMITER
#define EMITER

#include <d3d11.h>
#include <DirectXMath.h>

#include "Enumerations.h"
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

	ID3D11Buffer* GetVertexBuffer();
	unsigned int GetVertices();
	DirectX::XMFLOAT4X4 GetWorldMatrix();
	ID3D11ShaderResourceView* GetParticleTexture();

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

	float m_emitBorderLeft;

	//float m_globalWindAngleDegree = 315;
	float m_globalWindAngleDegree = 0;

	struct Particle
	{
		DirectX::XMFLOAT3 m_initPosition;

		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT3 m_direction;
		DirectX::XMFLOAT4 m_color;
		float opacity = 0.0f;


		float m_velocity;
		float m_rotation;
		float m_velocityXZ = 1.0f;

		bool m_alive;

		float m_timeToLive;
		float m_timePassed;
		float m_timeToFadeInPassed = 0.0f;
		float m_timeToScaleChange = 0.0f;
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


	float getWindOffsetX(float timePassed, float timeToLive);
	float getWindOffsetZ(float timePassed, float timeToLive);
	float fadeIn(ParticleVertex* mesh, Particle* particle, float timeToFade);
	float fadeOut(ParticleVertex* mesh, Particle* particle, float timeToFade);
};
#endif