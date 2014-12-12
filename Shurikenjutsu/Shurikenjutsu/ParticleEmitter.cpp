#include "ParticleEmitter.h"

bool ParticleEmitter::Initialize(ID3D11Device* p_device, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction, DirectX::XMFLOAT2 p_size, PARTICLE_PATTERN p_pattern)
{
	m_pattern = p_pattern;

	m_color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	m_emitterPosition = p_position;

	DirectX::XMStoreFloat3(&m_emitterDirection, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&p_direction)));
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());

	// Load the texture.
	m_mesh = 0;
	m_particleTexture = 0;

	// Set maximum number of particles, and the number of particles to emit per second.
	switch (m_pattern)
	{
		case(PARTICLE_PATTERN_SMOKE) :
		{
			m_particlesPerSecond = 50.0f;
			m_maxParticles = 75;

			// Set the random offset limits for the particles when emitted.
			m_emitionPositionOffset = DirectX::XMFLOAT3(1.0f, 0.5f, 1.0f);

			// Set velocity and its variation.
			m_velocity = 2.5f;
			m_velocityVariation = 0.1f;

			m_timeToLive = 2.0f;

			ModelImporter importer;
			importer.ImportModel("Models/SmokeParticle.SSP");
			m_particleTexture = LoadTexture(importer.GetMesh().m_textureMapSize[0], importer.GetMesh().m_textureMapSize[1], importer.GetMesh().m_textureMapSize[2], importer.GetMesh().m_textureMap);

			break;
		}

		case(PARTICLE_PATTERN_FIRE) :
		{
			m_particlesPerSecond = 10.0f;
			m_maxParticles = 20;

			// Set the random offset limits for the particles when emitted.
			m_emitionPositionOffset = DirectX::XMFLOAT3(0.1f, 0.1f, 0.1f);

			// Set velocity and its variation.
			m_velocity = 0.5f;
			m_velocityVariation = 0.1f;

			m_timeToLive = 1.0f;

			ModelImporter importer;
			importer.ImportModel("Models/FireParticle.SSP");
			m_particleTexture = LoadTexture(importer.GetMesh().m_textureMapSize[0], importer.GetMesh().m_textureMapSize[1], importer.GetMesh().m_textureMapSize[2], importer.GetMesh().m_textureMap);

			break;
		}

		default:
		{
			break;
		}
	}

	// Initialize the counters to 0.
	m_currentParticles = 0;
	m_time = 0.0f;

	// Create the list of particles and initialize them as dead particles to begin with.
	m_particleList = new Particle[m_maxParticles];
	for (unsigned int i = 0; i < m_maxParticles; i++)
	{
		m_particleList[i].m_alive = false;
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

	return true;
}

void ParticleEmitter::Shutdown()
{
	if (m_particleTexture)
	{
		m_particleTexture->Release();
		m_particleTexture = 0;
	}

	if (m_particleList)
	{
		delete[] m_particleList;
		m_particleList = 0;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
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
	GraphicsEngine::RenderParticles(m_vertexBuffer, m_vertices, m_worldMatrix, m_particleTexture);
}

void ParticleEmitter::EmitParticles()
{
	// Set emit to false to begin with.
	bool emit = false;

	// Add the delta time.
	m_time += (float)GLOBAL::GetInstance().GetDeltaTime();

	// Check if it is time to emit more particles.
	if (m_time > (1.0f / m_particlesPerSecond))
	{
		m_time = 0.0f;
		emit = true;
	}

	// If there are particles to be emited, emit one per frame.
	if ((emit == true) && (m_currentParticles < (m_maxParticles - 1)))
	{
		// Increment counter.
		m_currentParticles++;

		// Generate randomized values for the particle.
		DirectX::XMFLOAT3 position = m_emitterPosition;
		position.x += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.x;
		position.y += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.y;
		position.z += (((float)rand() - (float)rand()) / RAND_MAX) * m_emitionPositionOffset.z;

		float velocity = m_velocity + (((float)rand() - (float)rand()) / RAND_MAX) * m_velocityVariation;

		// If we want to use alpha blending, the particles must be sorted by Z depth.
		int index = 0;
		bool found = false;
		while (!found)
		{
			if ((m_particleList[index].m_alive == false) || (m_particleList[index].m_position.y > position.y))
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
			m_particleList[i].m_position	= m_particleList[j].m_position;
			m_particleList[i].m_direction	= m_particleList[j].m_direction;
			m_particleList[i].m_color		= m_particleList[j].m_color;
			m_particleList[i].m_velocity	= m_particleList[j].m_velocity;
			m_particleList[i].m_alive		= m_particleList[j].m_alive;
			m_particleList[i].m_timeToLive	= m_particleList[j].m_timeToLive;
			m_particleList[i].m_timePassed	= m_particleList[j].m_timePassed;
			m_particleList[i].m_rotation	= m_particleList[j].m_rotation;

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

				// Randomize again to get a rotation.
				angle = (((float)rand() - (float)rand()) / RAND_MAX) * 6.283185f;

				// Randomize a color.
				float color = (((float)rand() - (float)rand()) / RAND_MAX) * 0.1f;

				m_particleList[index].m_position = position;
				m_particleList[index].m_direction = direction;
				m_particleList[index].m_color = DirectX::XMFLOAT4(m_color.x + color, m_color.y + color, m_color.z + color, 1.0f);
				m_particleList[index].m_velocity = velocity;
				m_particleList[index].m_alive = true;
				m_particleList[index].m_timeToLive = m_timeToLive;
				m_particleList[index].m_timePassed = 0.0f;
				m_particleList[index].m_rotation = angle;

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

				break;
			}

			default:
			{
				break;
			}
		}
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
			for (unsigned int i = 0; i < m_currentParticles; i++)
			{
				// TODO b�gformel.

				// Fly in an arc in the given xz direction.
				m_particleList[i].m_position.x = m_particleList[i].m_position.x + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime() * m_particleList[i].m_direction.x;
				//m_particleList[i].m_position.y = ;
				m_particleList[i].m_position.z = m_particleList[i].m_position.z + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime() * m_particleList[i].m_direction.z;

				// Add time passed.
				m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
			}

			break;
		}

		// Fire just moves right up, ignoring direction.
		case(PARTICLE_PATTERN_FIRE) :
		{
			for (unsigned int i = 0; i < m_currentParticles; i++)
			{
				// TODO kanske ge droppform.

				// Burn upwards, ignoring direction.
				//m_particleList[i].m_position.x = ;
				m_particleList[i].m_position.y = m_particleList[i].m_position.y + m_particleList[i].m_velocity * (float)GLOBAL::GetInstance().GetDeltaTime();
				//m_particleList[i].m_position.z = ;

				// Add time passed.
				m_particleList[i].m_timePassed += (float)GLOBAL::GetInstance().GetDeltaTime();
			}

			break;
		}

		default:
		{
			break;
		}
	}
}

void ParticleEmitter::ClearOldParticles()
{
	// Kill all dying particles.
	for (unsigned int i = 0; i < m_maxParticles; i++)
	{
		if (m_particleList[i].m_timePassed > m_particleList[i].m_timeToLive)
		{
			m_particleList[i].m_alive = false;
			m_currentParticles--;

			// Now move all the live particles, to keep the array sorted.
			for (unsigned int j = i; j < m_maxParticles - 1; j++)
			{
				m_particleList[j].m_position	= m_particleList[j + 1].m_position;
				m_particleList[j].m_direction	= m_particleList[j + 1].m_direction;
				m_particleList[j].m_color		= m_particleList[j + 1].m_color;
				m_particleList[j].m_velocity	= m_particleList[j + 1].m_velocity;
				m_particleList[j].m_alive		= m_particleList[j + 1].m_alive;
				m_particleList[j].m_timeToLive	= m_particleList[j + 1].m_timeToLive;
				m_particleList[j].m_timePassed	= m_particleList[j + 1].m_timePassed;
				m_particleList[j].m_rotation	= m_particleList[j + 1].m_rotation;
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
	for (unsigned int i = 0; i < m_currentParticles; i++)
	{
		m_mesh[i].m_position = m_particleList[i].m_position;
		m_mesh[i].m_size = DirectX::XMFLOAT2(m_particleSize.x, m_particleSize.y);
		m_mesh[i].m_color = DirectX::XMFLOAT4(m_particleList[i].m_color.x, m_particleList[i].m_color.y, m_particleList[i].m_color.z, 1.0f - m_particleList[i].m_timePassed / m_particleList[i].m_timeToLive);
	}

	// Lock the dynamic vertex buffer.
	if (FAILED(GraphicsEngine::GetContext()->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource)))
	{
		ConsolePrintErrorAndQuit("Failed to map particle buffer.");
		return;
	}

	// Get a pointer to the data in the vertex buffer.
	vertex = (ParticleVertex*)mappedResource.pData;

	// Copy the mesh to the vertex buffer.
	memcpy(vertex, (void*)m_mesh, (sizeof(ParticleVertex) * m_vertices));

	// Unlock the vertex buffer.
	GraphicsEngine::GetContext()->Unmap(m_vertexBuffer, 0);
}

ID3D11ShaderResourceView* ParticleEmitter::LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels)
{
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

		ID3D11Texture2D* texture;
		GraphicsEngine::GetDevice()->CreateTexture2D(&textureDesc, &data, &texture);

		D3D11_SHADER_RESOURCE_VIEW_DESC sRVDesc;
		sRVDesc.Format = textureDesc.Format;
		sRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		sRVDesc.Texture2D.MipLevels = textureDesc.MipLevels;
		sRVDesc.Texture2D.MostDetailedMip = 0;
		GraphicsEngine::GetDevice()->CreateShaderResourceView(texture, &sRVDesc, &textureSRV);
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