#include "POIGrapichalEffects.h"
#include "GUIElement.h"
#include "ParticleEmitter.h"
#include "PointLights.h"

POIGrapichalEffects& POIGrapichalEffects::GetInstance()
{
	static POIGrapichalEffects instance;

	return instance;
}

bool POIGrapichalEffects::Initialize()
{
	m_healingParticles->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(0.0f, -10.0f, 0.0), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0), DirectX::XMFLOAT2(1.0f, 1.0f), PARTICLE_PATTERN_HEALING);
	m_healingParticles->SetEmitParticleState(false);
	m_heal = false;

	m_healingLight.m_ambient = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	m_healingLight.m_diffuse = DirectX::XMVectorSet(0.2f, 1.5f, 0.2f, 0.0f);
	m_healingLight.m_specular = DirectX::XMVectorSet(0.2f, 1.0f, 0.2f, 0.0f);
	m_healingLight.m_position.x = 0.0f;
	m_healingLight.m_position.y = -10.0f;
	m_healingLight.m_position.z = 0.0f;
	m_healingLight.m_range = 5.0f;

	return true;
}

void POIGrapichalEffects::Shutdown()
{
	if (m_healingParticles != nullptr)
	{
		m_healingParticles->Shutdown();
		delete m_healingParticles;
		m_healingParticles = nullptr;
	}

	if (m_stealthOverlay != nullptr)
	{
		delete m_stealthOverlay;
		m_stealthOverlay = nullptr;
	}

	if (m_shieldOverlay != nullptr)
	{
		delete m_shieldOverlay;
		m_shieldOverlay = nullptr;
	}
}

void POIGrapichalEffects::StartHealing()
{
	m_healingParticles->SetEmitParticleState(true);
	m_heal = true;
}

void POIGrapichalEffects::StopHealing()
{
	m_healingParticles->SetEmitParticleState(false);
	m_heal = false;
}

void POIGrapichalEffects::UpdateHealingEffect(DirectX::XMFLOAT3 p_position)
{
	if (m_heal)
	{
		m_healingParticles->UpdatePosition(p_position);
		m_healingParticles->Update();

		m_healingLight.m_position = p_position;
		PointLights::GetInstance()->AddLight(m_healingLight);
	}
}

void POIGrapichalEffects::RenderHealingEffect()
{
	m_healingParticles->Render();
}

void POIGrapichalEffects::RenderStealthEffect()
{
	m_stealthOverlay->Render();
}

void POIGrapichalEffects::UpdateShieldEffect(DirectX::XMFLOAT3 p_position)
{
	m_shieldOverlay->SetPosition(p_position);
}

void POIGrapichalEffects::RenderShieldEffect()
{
	m_shieldOverlay->Render();
}