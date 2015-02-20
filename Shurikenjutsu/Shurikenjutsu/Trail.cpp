#include "Trail.h"

#include "TrailRenderer.h"
#include "TextureLibrary.h"
#include "Globals.h"
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

	m_segments.clear();
	m_vertexBuffer = nullptr;
	m_vertices = 0;
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

	m_segments.clear();
	m_vertexBuffer = nullptr;
	m_vertices = 0;

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

	m_segments.clear();
	m_vertices = 0;
	m_timeToEmit = false;
	m_emiting = false;
	m_listDead = true;
}

void Trail::Update(DirectX::XMFLOAT3 p_position, float p_angle)
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	// Increase time for all points in the trail.
	for (unsigned int i = 0; i < m_segments.size(); i++)
	{
		m_segments[i].m_top.m_timeValues.y += deltaTime;
		m_segments[i].m_bottom.m_timeValues.y += deltaTime;
	}

	// Clear old points.
	ClearOldPoints();

	if (m_emiting)
	{
		// Increase point emission timer, and emit a point if it is time to do so.
		m_timeSinceLastEmission += deltaTime;
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
	// TODO, call render.
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
	TrailSegment segment;

	if (m_segments.size() == 0)
	{
		// First top point.
		point.m_position = p_position;
		point.m_angle = p_angle;
		point.m_width = m_trailWidth;
		point.m_timeValues = DirectX::XMFLOAT2(m_TrailPointLifeTime, 0.0f);
		point.m_color = m_color;
		point.m_endpoint = false;
		segment.m_top = point;

		// Bottom point, create one for the first point.
		point.m_position = DirectX::XMFLOAT3(p_position.x - cos(p_angle) * m_trailWidth, p_position.y, p_position.z - sin(p_angle) * m_trailWidth);
		point.m_angle = p_angle;
		point.m_width = m_trailWidth;
		point.m_timeValues = DirectX::XMFLOAT2(m_TrailPointLifeTime, 0.0f);
		point.m_color = m_color;
		point.m_endpoint = true;
		segment.m_bottom = m_segments[m_segments.size() - 1].m_top;
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
		segment.m_top = point;

		// Bottom point, use previous top.
		segment.m_bottom = m_segments[m_segments.size() - 1].m_top;
	}

	// Add segment to list.
	m_segments.push_back(segment);
}

void Trail::ClearOldPoints()
{
	// Look for living points.
	for (unsigned int i = 0; i < m_segments.size(); i++)
	{
		if (m_segments[i].m_bottom.m_timeValues.y < m_segments[i].m_bottom.m_timeValues.x)
		{ 
			// If the all points live, simply do nothing and return. 
			if (i == 0)
			{
				return;
			}

			else
			{
				// TODO, clear list of old points.

				// TODO, dont forget to move the end point bool!

				return;
			}
		}
	}

	// Else, if the all points are old, clear everything. 
	m_segments.clear();
	m_listDead = true;
}