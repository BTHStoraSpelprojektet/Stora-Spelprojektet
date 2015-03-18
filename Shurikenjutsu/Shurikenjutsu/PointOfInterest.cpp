#include "PointOfInterest.h"
#include "ParticleEmitter.h"
#include "Globals.h"
#include "GraphicsEngine.h"

PointOfInterest::PointOfInterest(){}
PointOfInterest::~PointOfInterest(){}

bool PointOfInterest::Initialize(POINTOFINTERESTTYPE p_type, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, DirectX::XMFLOAT3 p_lightColor)
{
	MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed);

	m_type = p_type;
	m_positionLight = p_pos;
	m_lightColor = p_lightColor;

	m_sparkles = new ParticleEmitter();
	m_sparkles->Initialize(GraphicsEngine::GetDevice(), m_position, m_direction, DirectX::XMFLOAT2(0.1f, 0.1f), PARTICLE_PATTERN_POI_SPARKLE);
	SparkleState(true);
	m_active = false;
	return true;
}

void PointOfInterest::Shutdown()
{
	if (m_sparkles != nullptr)
	{
		m_sparkles->Shutdown();
		delete m_sparkles;
		m_sparkles = nullptr;
	}

	MovingObject::Shutdown();

	return;
}

void PointOfInterest::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	
	// Rotate rune
	m_rotation.y += (float)(1.0f * deltaTime); // Rotation speed

	// Update particle emitter
	Sparkle();

	SpawnLight();
	
	return;
}

void PointOfInterest::Render()
{
	MovingObject::Render();

	m_sparkles->Render();
}

void PointOfInterest::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	Object::SetPosition(p_pos);

	if (m_sparkles != nullptr)
	{
		m_sparkles->SetPosition(p_pos);
		m_positionLight = p_pos;
	}
}

void PointOfInterest::Sparkle()
{
	m_sparkles->Update();
	return;
}

void PointOfInterest::SparkleState(bool p_stateOn)
{
	m_sparkles->SetEmitParticleState(p_stateOn);
}

void PointOfInterest::SetActive(bool p_active)
{
	m_active = p_active;
}

bool PointOfInterest::IsActive()
{
	return m_active;
}

void PointOfInterest::PickedUp()
{
	// Fix, input effect here, send to network!

	return;
}

void PointOfInterest::SpawnLight()
{
	PointLight newLight;
	newLight.m_ambient = DirectX::XMVectorSet(m_lightColor.x, m_lightColor.y, m_lightColor.z, 0.0f);
	newLight.m_diffuse = DirectX::XMVectorSet(m_lightColor.x, m_lightColor.y, m_lightColor.z, 0.0f);
	newLight.m_specular = DirectX::XMVectorSet(m_lightColor.x, m_lightColor.y, m_lightColor.z, 0.0f);

	newLight.m_position = m_positionLight;
	newLight.m_position.y += 1.8f;
	newLight.m_range = 3.0f;

	GraphicsEngine::AddNewPointLight(newLight);
}

POINTOFINTERESTTYPE PointOfInterest::GetType()
{
	return m_type;
}