#include "TextureLibrary.h"
#include "ParticleEmitter.h"
#include "ConsoleFunctions.h"
#include "Globals.h"
#include "GraphicsEngine.h"
#include "ParticleRenderer.h"
#include "PointLights.h"

ParticleEmitter::ParticleEmitter(){}
ParticleEmitter::~ParticleEmitter(){}

bool ParticleEmitter::Initialize(ID3D11Device* p_device, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction, DirectX::XMFLOAT2 p_size, PARTICLE_PATTERN p_pattern)
{
	m_pattern = p_pattern;

	m_color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_emitterPosition = p_position;

	DirectX::XMStoreFloat3(&m_emitterDirection, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&p_direction)));
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());

	// Load the texture.
	m_mesh = nullptr;
	m_particleTexture = 0;

	// Set maximum number of particles, and the number of particles to emit per second.
	switch (m_pattern)
	{
		case(PARTICLE_PATTERN_SMOKE) :
		{
			InitParticles(50.0f, 75, DirectX::XMFLOAT3(1.0f, 0.5f, 1.0f), 3.0f, 0.1f, 1.25f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/smokeParticle_texture.png"));

			break;
		}
		case(PARTICLE_PATTERN_WORLD_MIST) :
		{
			InitParticles(125.0f, 125, DirectX::XMFLOAT3(35.0f, 5.2f, 45.0f), 3.0f, 0.1f, 300.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/WorldMistParticle.png"));

			break;
		}
		case(PARTICLE_PATTERN_WORLD_DUST) :
		{
			//Border limit
			m_emitBorderLeft = 45.0f;
			float hight = 3.0f;
			float topBottomSpawnLimit = 45.0f;

			InitParticles(500.0f, 2000, DirectX::XMFLOAT3(topBottomSpawnLimit, hight, m_emitBorderLeft), 2.0f, 0.1f, FLT_MAX, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/WorldDustParticle2.png"));

			break;
		}
		case(PARTICLE_PATTERN_FIRE) :
		{
			InitParticles(100.0f, 100, DirectX::XMFLOAT3(0.3f, 0.1f, 0.3f), 1.5f, 0.5f, 1.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/fireParticle_texture2.png"));
			break;
		}
		case(PARTICLE_PATTERN_FIRE_SPARK) :
		{
			InitParticles(0.5f, 5, DirectX::XMFLOAT3(0.3f, 0.1f, 0.3f), 2.5f, 2.0f, 2.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/fireSparkParticle.png"));

			break;
		}
		case(PARTICLE_PATTERN_FIREFLIES) :
		{
			InitParticles(10.0f, 50, DirectX::XMFLOAT3(3.0f, 0.3f, 3.0f), 0.0f, 0.0f, 30.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/FireFlies.png"));

			break;
		}
		case(PARTICLE_PATTERN_PINK_LEAVES) :
		{
			InitParticles(1.0f, 100, DirectX::XMFLOAT3(4.3f, 0.1f, 4.3f), 1.5f, 0.4f, 60.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/sakuraLeafParticle_texture.png"));

			break;
		}
		case(PARTICLE_PATTERN_GREEN_LEAVES) :
		{
			InitParticles(1.0f, 100, DirectX::XMFLOAT3(4.3f, 0.1f, 4.3f), 1.0f, 0.4f, 60.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/greenLeafParticle_texture.png"));

			break;
		}		

		case(PARTICLE_PATTERN_ACERPALMATUM_LEAVES) :
		{
			InitParticles(1.0f, 100, DirectX::XMFLOAT3(4.3f, 0.1f, 4.3f), 1.0f, 0.4f, 60.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/AcerPlamatumLeafParticle.png"));

			break;
		}
		case(PARTICLE_PATTERN_POI_SPARKLE) :
		{
			InitParticles(50.0f, 50, DirectX::XMFLOAT3(1.5f, 0.5f, 1.5f), 1.0f, 0.5f, 0.75f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Particle_Sparkle.png"));

			break;
		}
		case(PARTICLE_PATTERN_BUBBLES) :
		{
			InitParticles(10.0f, 50, DirectX::XMFLOAT3(2.0f, 0.1f, 2.0f), 0.75f, 0.2f, 2.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/bubbleparticle2.png"));
			
			break;
		}
		case(PARTICLE_PATTERN_BLOODHIT) :
		{
			InitParticles(200.0f, 1000, DirectX::XMFLOAT3(0.2f, 0.2f, 0.2f), 0.5f, 1.0f, 0.5f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/BloodParticle.png"));
			break;
		}
		case(PARTICLE_PATTERN_SUDDENDEATH) :
		{
			InitParticles(50.0f, 500, DirectX::XMFLOAT3(13.0f,0.0f,13.0f), 1.0f, 0.1f, 7.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/BloodParticle.png"));
			break;
		}
		default:
		{
			return false;
		}
	}

	// Initialize the counters to 0.
	m_currentParticles = 0;
	m_time = 0.0f;

	// Create the list of particles and initialize them as dead particles to begin with.
	m_particleList = new Particle[m_maxParticles];
	for (unsigned int i = 0; i < m_maxParticles; i++)
	{
		m_particleList[i] = Particle();
	}

	// Set size of particles.
	m_particleSize = p_size;

	// Calculate the maximum number of vertices.
	m_vertices = m_maxParticles * 6;

	// Create the mesh and initialize every vertex to 0.
	m_mesh = new ParticleVertex[m_vertices];
	memset(m_mesh, 0, (sizeof(ParticleVertex) * m_vertices));

	// Set up description for the dynamic vertex buffer.
	D3D11_BUFFER_DESC vertexBufferDescription;
	vertexBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDescription.ByteWidth = sizeof(ParticleVertex) * m_vertices;
	vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDescription.MiscFlags = 0;
	vertexBufferDescription.StructureByteStride = 0;

	// Get a pointer to the vertex data.
	D3D11_SUBRESOURCE_DATA vertexBuffer;
	vertexBuffer.pSysMem = m_mesh;
	vertexBuffer.SysMemPitch = 0;
	vertexBuffer.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	m_vertexBuffer = 0;
	if (FAILED(p_device->CreateBuffer(&vertexBufferDescription, &vertexBuffer, &m_vertexBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create particle vertex buffer.");
		return false;
	}

	m_emit = false;
	return true;
}

void ParticleEmitter::InitParticles(float p_particlesPerSecond, float p_maxParticles, DirectX::XMFLOAT3 p_emitionPositionOffset, float p_velocity, float p_velocityVariation, float p_timeToLive, ID3D11ShaderResourceView* p_particleTexture){
	m_particlesPerSecond = p_particlesPerSecond;
	m_maxParticles = (unsigned int)p_maxParticles;

	// Set the random offset limits for the particles when emitted.
	m_emitionPositionOffset = p_emitionPositionOffset;

	// Set velocity and its variation.
	m_velocity = p_velocity;
	m_velocityVariation = p_velocityVariation;

	m_timeToLive = p_timeToLive;

	m_particleTexture = p_particleTexture;
}

void ParticleEmitter::Shutdown()
{
	if (m_particleList != nullptr)
	{
		delete[] m_particleList;
		m_particleList = nullptr;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = nullptr;
	}

	if (m_mesh != nullptr)
	{
		delete[] m_mesh;
		m_mesh = nullptr;
	}

	if (m_particleTexture != nullptr)
	{
		m_particleTexture = nullptr;
	}
}

void ParticleEmitter::Update()
{
	// Remove the old, inactive, particles.
	ClearOldParticles();

	// Emit new particles.
	EmitParticles();

	// Update the particles.
	UpdateParticles();

	// Update the dynamic vertex buffer with the new position of each particle.
	UpdateBuffers();
}

void ParticleEmitter::Render()
{
	ParticleRenderer::GetInstance()->QueueRender(this);
}

void ParticleEmitter::EmitParticles()
{
	// Set emit to false to begin with.
	bool emit = m_emit;

	// Add the delta time.
	m_time += (float)GLOBAL::GetInstance().GetDeltaTime();

	// Check if it is time to emit more particles.
	if (m_time > (1.0f / m_particlesPerSecond) || m_pattern == PARTICLE_PATTERN_BLOODHIT)
	{
		// If there are particles to be emited, emit one per frame.
		if ((emit == true) && ((unsigned int)m_currentParticles < (m_maxParticles - 1)))
		{
			// Increment counter.
			m_currentParticles++;

			// Generate randomized values for the particle.
			DirectX::XMFLOAT3 position = m_emitterPosition;
			position.x += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.x;
			position.y += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.y;
			position.z += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.z;

			float velocity = m_velocity + (((float)rand() - (float)rand()) / RAND_MAX) * m_velocityVariation;
			float rotation = ((float)rand() - (float)rand() / RAND_MAX) * (DirectX::XM_PI * 2);

			// If we want to use alpha blending, the particles must be sorted by Z depth.
			int index = 0;
			bool found = false;
			while (!found)
			{
				if ((m_particleList[index].m_alive == false) || (m_particleList[index].m_position.y < position.y))
				{
					found = true;
				}

				else
				{
					index++;
				}
			}

			// Now that we know the location to insert into, we need to copy the array over by one position from the index to make room for the new particle.
			int i = m_currentParticles;
			int j = i - 1;

			while (i != index)
			{
				// Copy data.
				m_particleList[i].m_position = m_particleList[j].m_position;
				m_particleList[i].m_direction = m_particleList[j].m_direction;
				m_particleList[i].m_color = m_particleList[j].m_color;
				m_particleList[i].m_velocity = m_particleList[j].m_velocity;
				m_particleList[i].m_alive = m_particleList[j].m_alive;
				m_particleList[i].m_timeToLive = m_particleList[j].m_timeToLive;
				m_particleList[i].m_timePassed = m_particleList[j].m_timePassed;
				m_particleList[i].m_rotation = m_particleList[j].m_rotation;
				m_particleList[i].m_opacity = m_particleList[j].m_opacity;

				i--;
				j--;
			}

			// Now insert the particle into the array in the correct Z depth order.
			switch (m_pattern)
			{
				case(PARTICLE_PATTERN_SMOKE) :
				{
					// Set a random direction in xz.
					float angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;
					DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(cos(angle), 0.0f, sin(angle));

					// Randomize a color.
					float color = (((float)rand() - (float)rand()) / RAND_MAX) * 0.05f;

					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = direction;
					m_particleList[index].m_color = DirectX::XMFLOAT4(m_color.x - color, m_color.y - color, m_color.z - color, 1.0f);
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_WORLD_MIST) : 
				{
					// Set a random direction in xz.
					float angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;
					DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(cos(angle), 0.0f, sin(angle));

					// Randomize a color.
					float color = (((float)rand() - (float)rand()) / RAND_MAX) * 0.05f;

					m_particleList[index].m_position = position;
					m_particleList[index].m_initPosition = position;
					m_particleList[index].m_direction = direction;
					m_particleList[index].m_color = DirectX::XMFLOAT4(m_color.x - color, m_color.y - color, m_color.z - color, 0.0f);
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = rotation;
					m_particleList[index].m_opacity = 0.0f;

					break;
				}

				case(PARTICLE_PATTERN_WORLD_DUST) : 
				{
					// Set a random direction in xz.
					float angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;
					DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(cos(angle), 0.0f, sin(angle));

					// Randomize a color.
					float color = (((float)rand() - (float)rand()) / RAND_MAX) * 0.05f;

					m_particleList[index].m_position = position;
					m_particleList[index].m_initPosition = position;

					// Move to setting.
					m_particleList[index].m_initPosition.x = -m_emitBorderLeft;

					m_particleList[index].m_direction = direction;
					m_particleList[index].m_color = DirectX::XMFLOAT4(m_color.x - color, m_color.y - color, m_color.z - color, 1.0f);
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_FIRE) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_FIREFLIES) :
				{
					m_particleList[index].m_direction = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
					m_particleList[index].m_position = position;
					m_particleList[index].m_color = DirectX::XMFLOAT4(m_color.x, m_color.y, m_color.z, 0.0f);
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 0.0f;

					break;
				}

				case(PARTICLE_PATTERN_FIRE_SPARK) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_PINK_LEAVES) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = m_emitterDirection;
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_GREEN_LEAVES) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = m_emitterDirection;
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_ACERPALMATUM_LEAVES) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = m_emitterDirection;
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_POI_SPARKLE) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = rotation;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_BUBBLES) :
				{
					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 1.0f;

					break;
				}

				case(PARTICLE_PATTERN_BLOODHIT) :
				{
					// Set a random direction in xz.
					float angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;
					DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(cos(angle), sin(angle), sin(angle));

					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = direction;
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 0.0f;
					break;
				}
				case(PARTICLE_PATTERN_SUDDENDEATH) :
				{
					// Set a random direction in xz.
					float angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;
					DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(cos(angle), sin(angle), sin(angle));

					m_particleList[index].m_position = position;
					m_particleList[index].m_direction = direction;
					m_particleList[index].m_color = m_color;
					m_particleList[index].m_velocity = velocity;
					m_particleList[index].m_alive = true;
					m_particleList[index].m_timeToLive = m_timeToLive;
					m_particleList[index].m_timePassed = 0.0f;
					m_particleList[index].m_rotation = 0.0f;
					m_particleList[index].m_opacity = 0.0f;
					break;
				}

				default:
				{
					break;
				}
			}
		}

		m_time = 0.0f;
	}
}

void ParticleEmitter::UpdateParticles()
{
	// Update the particles to move upwards from their position.
	switch (m_pattern)
	{
		// Smoke moves outwards in a circle.
		case(PARTICLE_PATTERN_SMOKE) :
		{
			if (m_particleList != nullptr){
				for (int i = 0; i < m_currentParticles; i++)
				{
					float halfTime = m_particleList[i].m_timeToLive / 2.0f;
					float angle = 30.0f * (float)3.14159265359 / 180;
					float height = 3.0f;
					float ySpeed = (height + 0.5f * 9.82f * halfTime * halfTime) / (halfTime * sinf(angle));

					// Fly in an arc in the given xz direction.
					m_particleList[i].m_position.x = m_particleList[i].m_position.x + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime() * m_particleList[i].m_direction.x;
					m_particleList[i].m_position.y = (ySpeed * m_particleList[i].m_timePassed * sinf(angle) - 0.5f * 9.82f * m_particleList[i].m_timePassed * m_particleList[i].m_timePassed);
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime() * m_particleList[i].m_direction.z;

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case(PARTICLE_PATTERN_WORLD_MIST) :
		{
			if (m_particleList != nullptr){
				for (int i = 0; i < m_currentParticles; i++)
				{
					float halfTime = m_particleList[i].m_timeToLive / 2.0f;
					float angle = 30.0f * (float)3.14159265359 / 180;
					float height = 3.0f;
					float ySpeed = (height + 0.5f * 9.82f * halfTime * halfTime) / (halfTime * sinf(angle));

					m_particleList[i].m_position.y = m_particleList[i].m_position.y;

					float xWindOffset = GetWindOffsetX(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);
					float zWindOffset = GetWindOffsetZ(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);

					m_particleList[i].m_position.x = m_particleList[i].m_position.x + xWindOffset;
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + zWindOffset;

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case PARTICLE_PATTERN_WORLD_DUST:
		{
			if (m_particleList != NULL){
				for (int i = 0; i < m_currentParticles; i++)
				{
					float angle = 30.0f * (float)3.14159265359 / 180;
					float height = 3.0f;

					m_particleList[i].m_position.y = m_particleList[i].m_position.y;

					float xWindOffset = GetWindOffsetX(m_particleList[i].m_timePassed, 100);
					float zWindOffset = GetWindOffsetZ(m_particleList[i].m_timePassed, 100);

					m_particleList[i].m_position.x = m_particleList[i].m_position.x + (xWindOffset * m_particleList[i].m_velocity);
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + (zWindOffset * m_particleList[i].m_velocity);

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		// Fire just moves right up, ignoring direction.
		case(PARTICLE_PATTERN_FIRE) :
		{
				if (m_particleList != nullptr)
				{
				PointLight fireLight;
				fireLight.m_ambient = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
				fireLight.m_diffuse = DirectX::XMVectorSet(1.6f, 0.8f, 0.0f, 0.0f);
				fireLight.m_specular = DirectX::XMVectorSet(0.8f, 0.4f, 0.0f, 0.0f);

				fireLight.m_position = DirectX::XMFLOAT3(m_emitterPosition.x, m_emitterPosition.y + 0.2f, m_emitterPosition.z);
				fireLight.m_range = 5.0f;
				
				PointLights::GetInstance()->AddLight(fireLight);

				for (int i = 0; i < m_currentParticles; i++)
				{
					float timeToDirectionChange = m_particleList[i].m_timeToLive / 4.0f;
					float xWindOffset = GetWindOffsetX(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);
					float zWindOffset = GetWindOffsetZ(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);

					if (timeToDirectionChange>m_particleList[i].m_timePassed)
					{
						m_particleList[i].m_position.x = m_particleList[i].m_position.x;
					}

					else
					{
						m_particleList[i].m_position.x = m_particleList[i].m_position.x + (xWindOffset / 2.5f);
					}

						m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + (zWindOffset / 2.5f);

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case(PARTICLE_PATTERN_FIREFLIES) :
		{
				if (m_particleList != nullptr)
				{
				for (int i = 0; i < m_currentParticles; i++)
				{
					m_particleList[i].m_position.x = m_particleList[i].m_position.x;

					m_particleList[i].m_position.y = m_particleList[i].m_position.y;
					m_particleList[i].m_position.z = m_particleList[i].m_position.z;

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case(PARTICLE_PATTERN_FIRE_SPARK) :
		{
				if (m_particleList != nullptr)
				{
				for (int i = 0; i < m_currentParticles; i++)
				{
					float timeToDirectionChange = m_particleList[i].m_timeToLive / 10.0f;
					float xWindOffset = GetWindOffsetX(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);
					float zWindOffset = GetWindOffsetZ(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);

					if (timeToDirectionChange>m_particleList[i].m_timePassed)
					{
						m_particleList[i].m_position.x = m_particleList[i].m_position.x;
					}

					else
					{
						m_particleList[i].m_position.x = m_particleList[i].m_position.x + (xWindOffset / 2.5f);
					}

						m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + (zWindOffset / 2.5f);

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case(PARTICLE_PATTERN_PINK_LEAVES) :
		{
			FallingLeafUpdate();

			break;
		}

		case(PARTICLE_PATTERN_GREEN_LEAVES) :
		{
			FallingLeafUpdate();

			break;
		}

		case(PARTICLE_PATTERN_ACERPALMATUM_LEAVES) :
		{
			FallingLeafUpdate();

			break;
		}

			case(PARTICLE_PATTERN_POI_SPARKLE) :
		{
			if (m_particleList != nullptr)
			{
				for (int i = 0; i < m_currentParticles; i++)
				{
						// Fly upwards.
						m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime();

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}

			break;
		}

		case(PARTICLE_PATTERN_BUBBLES) :
		{
			if (m_particleList != nullptr)
			{
				for (int i = 0; i < m_currentParticles; i++)
				{
					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}
			break;
		}

		case(PARTICLE_PATTERN_BLOODHIT) :
		{
			if (m_particleList != nullptr)
			{
				for (int i = 0; i < m_currentParticles; i++)
				{
					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();

					m_particleList[i].m_position.x = m_particleList[i].m_position.x + (m_particleList[i].m_direction.x * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.y = m_particleList[i].m_position.y + (m_particleList[i].m_direction.y * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + (m_particleList[i].m_direction.z * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}
			break;
		}
		case(PARTICLE_PATTERN_SUDDENDEATH) :
		{
			if (m_particleList != nullptr)
			{
				for (int i = 0; i < m_currentParticles; i++)
				{
					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();

					m_particleList[i].m_position.x = m_particleList[i].m_position.x + (m_particleList[i].m_direction.x * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.y = m_particleList[i].m_position.y + (m_particleList[i].m_direction.y * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
					m_particleList[i].m_position.z = m_particleList[i].m_position.z + (m_particleList[i].m_direction.z * m_particleList[i].m_velocity) * (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}
			break;
		}
										
		default:
		{
			break;
		}
	}
}

void ParticleEmitter::FallingLeafUpdate()
{
	if (m_particleList != nullptr)
	{
		for (int i = 0; i < m_currentParticles; i++)
		{
			if (m_particleList[i].m_position.y > 0.2f)
			{
				float angle = m_particleList[i].m_timePassed*2.5f;

				//Make the leaves fall nicely
				m_particleList[i].m_position.x = m_particleList[i].m_position.x +sinf(angle) * (float)GLOBAL::GetInstance().GetDeltaTime();
						m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime() * m_particleList[i].m_direction.y;
				m_particleList[i].m_position.z = m_particleList[i].m_position.z;

						float xWindOffset = GetWindOffsetX(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);
						float zWindOffset = GetWindOffsetZ(m_particleList[i].m_timePassed, m_particleList[i].m_timeToLive);
						m_particleList[i].m_position.x = m_particleList[i].m_position.x + xWindOffset;
						m_particleList[i].m_position.z = m_particleList[i].m_position.z + zWindOffset;
					}

					// Add time passed.
					m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
				}
			}
}

float ParticleEmitter::GetWindOffsetX(float p_timePassed, float p_timeToLive)
{
	float angle = m_globalWindAngleDegree * (float)3.14159265359 / 180;

	return ((p_timePassed / p_timeToLive) / 60)*cosf(angle)*m_globalWindSpeed;
}

float ParticleEmitter::GetWindOffsetZ(float p_timePassed, float p_timeToLive)
{
	float angle = m_globalWindAngleDegree * (float)3.14159265359 / 180;

	return ((p_timePassed / p_timeToLive) / 60)*sinf(angle)*m_globalWindSpeed;
}

float ParticleEmitter::FadeIn(Particle* p_particle, float p_timeToFade)
{
	p_particle->m_opacity;
	float increment = 0.001f;
	if (p_particle->m_timeToFadeInPassed>p_timeToFade*increment)
	{
		if (p_particle->m_opacity < 1.0f)
		{
			p_particle->m_opacity += increment;
			p_particle->m_timeToFadeInPassed = 0;
	}

		else
		{
			p_particle->m_opacity = 1.0f;
}
	}

	p_particle->m_timeToFadeInPassed += (float)GLOBAL::GetInstance().GetDeltaTime();
	return p_particle->m_opacity;
}

float ParticleEmitter::FadeOut(Particle* p_particle, float p_timeToFade)
{
	float opacity = p_particle->m_opacity;

	if (p_particle->m_timePassed > p_particle->m_timeToLive * p_timeToFade)
	{
		opacity = ((-opacity / (p_particle->m_timeToLive * p_timeToFade)) * (p_particle->m_timePassed - p_particle->m_timeToLive * p_timeToFade)) + opacity;
	}

	return opacity;
}

void ParticleEmitter::ClearOldParticles()
{
	// Kill all dying particles.
	for (unsigned int i = 0; i < m_maxParticles; i++)
	{
		if (m_particleList != nullptr)
		{
			if (m_particleList[i].m_timePassed > m_particleList[i].m_timeToLive)
			{
				m_currentParticles--;

				// Now move all the live particles, to keep the array sorted.
				for (unsigned int j = i; j < m_maxParticles - 1; j++)
				{
					m_particleList[j].m_position = m_particleList[j + 1].m_position;
					m_particleList[j].m_direction = m_particleList[j + 1].m_direction;
					m_particleList[j].m_color = m_particleList[j + 1].m_color;
					m_particleList[j].m_velocity = m_particleList[j + 1].m_velocity;
					m_particleList[j].m_alive = m_particleList[j + 1].m_alive;
					m_particleList[j].m_timeToLive = m_particleList[j + 1].m_timeToLive;
					m_particleList[j].m_timePassed = m_particleList[j + 1].m_timePassed;
					m_particleList[j].m_rotation = m_particleList[j + 1].m_rotation;
					m_particleList[j].m_opacity = m_particleList[j + 1].m_opacity;
				}

				m_particleList[m_maxParticles - 1].m_alive = false;
				m_particleList[m_maxParticles - 1].m_timePassed = 0.0f;
			}
		}
	}
}

void ParticleEmitter::UpdateBuffers()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	ParticleVertex* vertex;

	// Initialize vertex array to zeros.
	memset(m_mesh, 0, (sizeof(ParticleVertex) * m_vertices));

	// Build the mesh using the particle list, every particle is made of two triangles.
	for (int i = 0; i < m_currentParticles; i++)
	{
		m_mesh[i].m_position = m_particleList[i].m_position;

		switch (m_pattern)
		{
			case PARTICLE_PATTERN_SMOKE:
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);
				break;
			}

			case PARTICLE_PATTERN_FIRE:
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				if (m_particleList[i].m_timePassed > m_particleList[i].m_timeToLive * 0.7f)
				{
					if (m_particleList[i].m_timeToScaleChange > 0.1f)
					{
						if (m_mesh[i].m_size.x > 0 && m_mesh[i].m_size.y > 0)
						{
							float newScaleX = m_mesh[i].m_size.x - 0.1f;
							float newScaleY = m_mesh[i].m_size.y - 0.1f;
							m_mesh[i].m_size = DirectX::XMFLOAT2(newScaleX, newScaleY);
						m_particleList[i].m_timeToScaleChange = 0;
						}
					}

				m_particleList[i].m_timeToScaleChange += (float)GLOBAL::GetInstance().GetDeltaTime();

				}

				break;
			}

			case PARTICLE_PATTERN_FIRE_SPARK:
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);
			}

			case PARTICLE_PATTERN_FIREFLIES:
			{
				m_particleList[i].m_opacity = FadeIn(&m_particleList[i], 3);
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				break;
			}

			case PARTICLE_PATTERN_WORLD_MIST:
			{
				m_particleList[i].m_opacity = FadeIn(&m_particleList[i], 0.001f);

					if (m_particleList[i].m_position.x>30.0f && m_particleList[i].m_position.z>50.0f)
					{
						m_particleList[i].m_position = m_particleList[i].m_initPosition;
					}

				break;
			}

			case PARTICLE_PATTERN_POI_SPARKLE:
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				break;
			}

			case PARTICLE_PATTERN_WORLD_DUST:
			{
				if (m_particleList[i].m_position.x>m_emitBorderLeft)
				{
					m_particleList[i].m_position.x = m_particleList[i].m_initPosition.x;
					m_particleList[i].m_position.y = m_particleList[i].m_initPosition.y;
					m_particleList[i].m_position.z = m_particleList[i].m_initPosition.z;

					m_particleList[i].m_timePassed = 0;
				}

				break;
			}

			case PARTICLE_PATTERN_BLOODHIT:
			{
				m_particleList[i].m_opacity = FadeIn(&m_particleList[i], 0.01f);
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);
			}

			case(PARTICLE_PATTERN_GREEN_LEAVES) :
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				break;
			}

			case(PARTICLE_PATTERN_PINK_LEAVES) :
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				break;
			}

			case(PARTICLE_PATTERN_ACERPALMATUM_LEAVES) :
			{
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);

				break;
			}

			case PARTICLE_PATTERN_SUDDENDEATH:
			{
				m_particleList[i].m_opacity = FadeIn(&m_particleList[i], 0.01f);
				m_particleList[i].m_opacity = FadeOut(&m_particleList[i], 0.5f);
			}

			default:
			{
				m_particleList[i].m_opacity = 1.0f;

				break;
			}
		}

		m_mesh[i].m_color = DirectX::XMFLOAT4(m_particleList[i].m_color.x, m_particleList[i].m_color.y, m_particleList[i].m_color.z, m_particleList[i].m_opacity);
		m_mesh[i].m_size = DirectX::XMFLOAT2(m_particleSize.x, m_particleSize.y);
		m_mesh[i].m_rotation = m_particleList[i].m_rotation;
	}

	// Lock the dynamic vertex buffer.
	if (FAILED(GraphicsEngine::GetInstance()->GetContext()->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource)))
	{
		ConsolePrintErrorAndQuit("Failed to map particle buffer.");
		return;
	}

	// Get a pointer to the data in the vertex buffer.
	vertex = (ParticleVertex*)mappedResource.pData;

	// Copy the mesh to the vertex buffer.
	memcpy(vertex, (void*)m_mesh, (sizeof(ParticleVertex) * m_vertices));

	// Unlock the vertex buffer.
	GraphicsEngine::GetInstance()->GetContext()->Unmap(m_vertexBuffer, 0);
}

ID3D11ShaderResourceView* ParticleEmitter::LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels)
{
	HRESULT hr;
	ID3D11ShaderResourceView* textureSRV = NULL;

	int combinedSize = p_width * p_height * p_depth;
	if (combinedSize > 0)
	{
		D3D11_TEXTURE2D_DESC textureDesc;
		textureDesc.Width = p_width;
		textureDesc.Height = p_height;
		textureDesc.MipLevels = 1;
		textureDesc.ArraySize = 1;
		textureDesc.SampleDesc.Count = 1;
		textureDesc.SampleDesc.Quality = 0;
		textureDesc.Usage = D3D11_USAGE_DEFAULT;
		textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		textureDesc.CPUAccessFlags = 0;
		textureDesc.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA data;
		data.pSysMem = (void*)p_pixels;
		data.SysMemPitch = p_width * 4;
		data.SysMemSlicePitch = 0;

		ID3D11Texture2D* texture = NULL;
		hr = GraphicsEngine::GetInstance()->GetDevice()->CreateTexture2D(&textureDesc, &data, &texture);
		if (FAILED(hr))
		{
			ConsolePrintError("Failed creating CreateTexture2D - particleemmiter");
		}

		D3D11_SHADER_RESOURCE_VIEW_DESC sRVDesc;
		sRVDesc.Format = textureDesc.Format;
		sRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		sRVDesc.Texture2D.MipLevels = textureDesc.MipLevels;
		sRVDesc.Texture2D.MostDetailedMip = 0;
		hr = GraphicsEngine::GetInstance()->GetDevice()->CreateShaderResourceView(texture, &sRVDesc, &textureSRV);
		if (FAILED(hr))
		{
			ConsolePrintError("Failed creating shaderresource - particleemmiter");
		}

		texture->Release();
	}

	return textureSRV;
}

void ParticleEmitter::UpdateMatrix(DirectX::XMFLOAT4X4 p_world)
{
	m_worldMatrix = p_world;
}

void ParticleEmitter::UpdatePosition(DirectX::XMFLOAT3 p_position)
{
	m_emitterPosition = p_position;
}

void ParticleEmitter::UpdateDirection(DirectX::XMFLOAT3 p_direction)
{
	m_emitterDirection = p_direction;
}


void ParticleEmitter::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_emitterPosition = p_position;
}

void ParticleEmitter::SetEmitParticleState(bool p_emit)
{
	m_emit = p_emit;
}

int ParticleEmitter::GetParticleCount()
{
	return m_currentParticles;
}

ID3D11Buffer* ParticleEmitter::GetVertexBuffer()
{
	return m_vertexBuffer;
}

unsigned int ParticleEmitter::GetVertices()
{
	return m_vertices;
}

DirectX::XMFLOAT4X4 ParticleEmitter::GetWorldMatrix()
{
	return m_worldMatrix;
}

ID3D11ShaderResourceView* ParticleEmitter::GetParticleTexture()
{
	return m_particleTexture;
}

void ParticleEmitter::SetColor(DirectX::XMFLOAT4 p_color)
{
	m_color = p_color;
}