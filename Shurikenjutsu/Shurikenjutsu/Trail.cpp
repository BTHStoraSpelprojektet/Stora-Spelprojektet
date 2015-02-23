#include "Trail.h"
#include "TextureLibrary.h"
#include "Globals.h"
#include "GraphicsEngine.h"
#include "ConsoleFunctions.h"

Trail::Trail()
{
	m_pointsPerSecond = 0.0f;
	m_timeSinceLastEmission = 0.0f;
	m_timeToEmit = true;
	m_emiting = true;
	m_listDead = false;

	m_TrailPointLifeTime = 0.0f;

	m_trailWidth = 0.0f;

	m_color = DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	m_texture = nullptr;

	m_points.clear();
	m_vertexBuffer = nullptr;
}

Trail::~Trail()
{
	Shutdown();
}

bool Trail::Initialize(float p_pointsPerSecond, float p_timeToLive, float p_trailWidth, DirectX::XMFLOAT4 p_color, std::string p_texturePath)
{
	m_pointsPerSecond = p_pointsPerSecond;
	m_timeSinceLastEmission = 0.0f;
	m_timeToEmit = true;
	m_emiting = true;
	m_listDead = false;

	// Output errors if points live to short.
	m_TrailPointLifeTime = p_timeToLive;
	if (m_TrailPointLifeTime < (1.0f / m_pointsPerSecond))
	{	
		m_TrailPointLifeTime = (1.0f / m_pointsPerSecond) * 2.0f;

		ConsolePrintError("A trails point life time was set to less than (1 / points per second), which means a point will die before a new one is emitted, making a trail impossible.");
		ConsolePrintRequest("The trails point life time was automatically set to (1 / m_pointsPerSecond * 2) to make a trail possible.");
	}

	m_trailWidth = p_trailWidth;

	m_color = p_color;
	m_texture = TextureLibrary::GetInstance()->GetTexture(p_texturePath);

	m_points.clear();

	m_vertexBuffer = nullptr;
	std::vector<TrailPoint> dummyData;

	// Set up description for the dynamic vertex buffer.
	D3D11_BUFFER_DESC vertexBufferDescription;
	vertexBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDescription.ByteWidth = sizeof(TrailPoint);
	vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDescription.MiscFlags = 0;
	vertexBufferDescription.StructureByteStride = 0;

	// Get a pointer to the vertex data.
	D3D11_SUBRESOURCE_DATA vertexBuffer;
	vertexBuffer.pSysMem = &dummyData;
	vertexBuffer.SysMemPitch = 0;
	vertexBuffer.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	if (FAILED(GraphicsEngine::GetInstance()->GetDevice()->CreateBuffer(&vertexBufferDescription, &vertexBuffer, &m_vertexBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create trail dynamic vertex buffer.");
		return false;
	}

	return true;
}

void Trail::Shutdown()
{
	if (m_texture)
	{
		m_texture->Release();
		delete m_texture;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		delete m_vertexBuffer;
	}

	m_points.clear();
	m_timeToEmit = false;
	m_emiting = false;
	m_listDead = true;
}

void Trail::Update(DirectX::XMFLOAT3 p_position, float p_angle)
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	// Increase time for all points in the trail.
	for (unsigned int i = 0; i < m_points.size(); i++)
	{
		m_points[i].m_timeValues.y += (float)deltaTime;
	}

	// Clear old points.
	ClearOldPoints();

	if (m_emiting)
	{
		// Increase point emission timer, and emit a point if it is time to do so.
		m_timeSinceLastEmission += (float)deltaTime;
		if (m_timeSinceLastEmission > (1.0f / m_pointsPerSecond))
		{
			EmitPoint(p_position, p_angle);
			m_timeSinceLastEmission = 0.0f;

			m_listDead = false;
		}
	}
}

void Trail::Render()
{
	// Update vertex buffer.
	D3D11_MAPPED_SUBRESOURCE resource;
	GraphicsEngine::GetInstance()->GetContext()->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	memcpy(resource.pData, &m_points[0], sizeof(TrailPoint) * m_points.size());
	GraphicsEngine::GetInstance()->GetContext()->Unmap(m_vertexBuffer, 0);

	// Call render.
	TrailRenderer::GetInstance().RenderTrail(m_vertexBuffer, m_points.size(), m_texture);
}

void Trail::StopEmiting()
{
	m_emiting = false;
}

bool Trail::IsTrailDead()
{
	return m_listDead;
}

void Trail::EmitPoint(DirectX::XMFLOAT3 p_position, float p_angle)
{
	TrailPoint point;

	if (m_points.size() == 0)
	{
		// First top point.
		point.m_position = p_position;
		point.m_angle = p_angle;
		point.m_width = m_trailWidth;
		point.m_timeValues = DirectX::XMFLOAT2(m_TrailPointLifeTime, 0.0f);
		point.m_color = m_color;
		point.m_endpoint = false;
		m_points.push_back(point);

		// Bottom point, create one for the first point.
		point.m_position = DirectX::XMFLOAT3(p_position.x - cos(p_angle) * m_trailWidth, p_position.y, p_position.z - sin(p_angle) * m_trailWidth);
		point.m_angle = p_angle;
		point.m_width = m_trailWidth;
		point.m_timeValues = DirectX::XMFLOAT2(m_TrailPointLifeTime, 0.0f);
		point.m_color = m_color;
		point.m_endpoint = true;
		m_points.push_back(point);
	}

	else
	{
		// Top point.
		point.m_position = p_position;
		point.m_angle = p_angle;
		point.m_width = m_trailWidth;
		point.m_timeValues = DirectX::XMFLOAT2(m_TrailPointLifeTime, 0.0f);
		point.m_color = m_color;
		point.m_endpoint = false;
		m_points.push_back(point);

		// Bottom point, use previous top.
		m_points.push_back(m_points[m_points.size() - 2]);
	}
}

void Trail::ClearOldPoints()
{
	// Look for living points.
	for (unsigned int i = 0; i < m_points.size(); i++)
	{
		if (m_points[i].m_timeValues.y < m_points[i].m_timeValues.x)
		{ 
			// If all the points live, simply do nothing and return. 
			if (i == 0)
			{
				return;
			}

			// Erase the points that are old, and then move the end point bool.
			else
			{
				m_points.erase(m_points.begin(), m_points.begin() + i);
				m_points[1].m_endpoint = true;

				return;
			}
		}
	}

	// Else, if all the points are old, clear everything. 
	m_points.clear();
	m_listDead = true;
}