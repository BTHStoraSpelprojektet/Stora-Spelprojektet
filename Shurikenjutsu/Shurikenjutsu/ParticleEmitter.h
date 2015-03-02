#ifndef EMITTER
#define EMITTER

#include <d3d11.h>
#include <DirectXMath.h>

#include "Enumerations.h"
#include "../CommonLibs/ModelImporter.h"

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();
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
	void SetSuddenDeathBoxLimits(float p_xMax, float p_xMin, float p_zMax, float p_zMin);

private:

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

	bool m_emit;

	float m_velocity;
	float m_velocityVariation;

	float m_particlesPerSecond;
	float m_time;

	float m_timeToLive;

	unsigned int m_maxParticles;
	int m_currentParticles;

	float m_emitBorderLeft;

	float m_globalWindAngleDegree = 0;
	float m_globalWindSpeed = 5.0f;

	struct Particle
	{
		DirectX::XMFLOAT3 m_initPosition;

		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT3 m_direction;
		DirectX::XMFLOAT4 m_color;
		float m_opacity = 0.0f;

		float m_velocity;
		float m_rotation;
		float m_velocityXZ = 1.0f;

		bool m_alive;

		float m_timeToLive;
		float m_timePassed;
		float m_timeToFadeInPassed = 0.0f;
		float m_timeToScaleChange = 0.0f;

		Particle()
		{
			m_initPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
			m_position = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
			m_direction = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
			m_color = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);

			m_opacity = 0.0f;
			m_velocity = 0.0f;
			m_rotation = 0.0f;
			m_velocityXZ = 1.0f;
			m_alive = false;
			m_timeToLive = 1.0f;
			m_timePassed = 0.0f;
			m_timeToFadeInPassed = 0.0f;
			m_timeToScaleChange = 0.0f;
		}
	};

	Particle* m_particleList;

	struct ParticleVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_size;
		DirectX::XMFLOAT4 m_color;
		float m_rotation;
	};

	ParticleVertex* m_mesh;

	ID3D11Buffer* m_vertexBuffer;
	unsigned int m_vertices;

	float GetWindOffsetX(float p_timePassed, float p_timeToLive);
	float GetWindOffsetZ(float p_timePassed, float p_timeToLive);
	float FadeIn(Particle* p_particle, float p_timeToFade);
	float FadeOut(Particle* p_particle, float p_timeToFade);

	void InitParticles(float p_particlesPerSecond, float p_maxParticles, DirectX::XMFLOAT3 p_emitionPositionOffset, float p_velocity, float p_velocityVariation, float p_timeToLive, ID3D11ShaderResourceView* p_particleTexture);
	void FallingLeafUpdate();
	


	float m_SDxMax;
	float m_SDxMin;
	float m_SDzMax;
	float m_SDzMin;
};
#endif