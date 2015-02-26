#include "PointOfInterest.h"
#include "ParticleEmitter.h"
#include "Globals.h"

PointOfInterest::PointOfInterest(){}
PointOfInterest::~PointOfInterest(){}

bool PointOfInterest::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed);

	m_sparkles = new ParticleEmitter();
	m_sparkles->Initialize(GraphicsEngine::GetInstance()->GetDevice(), m_position, m_direction, DirectX::XMFLOAT2(0.1f, 0.1f), PARTICLE_PATTERN_POI_SPARKLE);
	SparkleState(true);
	m_active = true;
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

	return;
}

void PointOfInterest::Update()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	
	// Rotate rune
	m_rotation.y += (float)(2.0f * deltaTime); // Rotation speed

	// Update particle emitter
	Sparkle();
	
	return;
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