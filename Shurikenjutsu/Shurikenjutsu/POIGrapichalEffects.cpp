#include "POIGrapichalEffects.h"
#include "GUIElement.h"
#include "ParticleEmitter.h"
#include "PointLights.h"
#include "Globals.h"
#include "../CommonLibs/TextureLibrary.h"

POIGrapichalEffects& POIGrapichalEffects::GetInstance()
{
	static POIGrapichalEffects instance;

	return instance;
}

bool POIGrapichalEffects::Initialize()
{
	m_healingParticles = new ParticleEmitter();
	m_healingParticles->Initialize(GraphicsEngine::GetInstance()->GetDevice(), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0), DirectX::XMFLOAT2(1.0f, 1.0f), PARTICLE_PATTERN_HEALING);
	m_healingParticles->SetEmitParticleState(false);
	m_heal = false;

	m_healingLight.m_ambient = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	m_healingLight.m_diffuse = DirectX::XMVectorSet(0.2f, 1.5f, 0.2f, 0.0f);
	m_healingLight.m_specular = DirectX::XMVectorSet(0.2f, 1.0f, 0.2f, 0.0f);
	m_healingLight.m_position.x = 0.0f;
	m_healingLight.m_position.y = -10.0f;
	m_healingLight.m_position.z = 0.0f;
	m_healingLight.m_range = 7.5f;

	m_stealthOverlay = new GUIElement();
	m_stealthOverlay->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/Particles/StealthOverlay.png"));

	m_shieldOverlay = new GUIElement();
	m_shieldOverlay->Initialize(DirectX::XMFLOAT3(0.0f, 35.0f, 0.0), 90.0f, 140.0f, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/Particles/ShieldOverlay.png"));

	m_shieldLight.m_ambient = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	m_shieldLight.m_diffuse = DirectX::XMVectorSet(5.0f, 5.0f, 5.0f, 0.0f);
	m_shieldLight.m_specular = DirectX::XMVectorSet(1.5f, 1.5f, 1.5f, 0.0f);
	m_shieldLight.m_position.x = 0.0f;
	m_shieldLight.m_position.y = -10.0f;
	m_shieldLight.m_position.z = 0.0f;
	m_shieldLight.m_range = 1.95f;

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
	m_healingParticles->UpdatePosition(p_position);
	m_healingParticles->Update();

	if (m_heal)
	{
		m_healingLight.m_position.x = p_position.x;
		m_healingLight.m_position.y = 1.0f;
		m_healingLight.m_position.z = p_position.z;
		PointLights::GetInstance()->AddLight(m_healingLight);
	}
}

void POIGrapichalEffects::RenderHealingEffect()
{
	m_healingParticles->Render();
}

void POIGrapichalEffects::RenderStealthEffect()
{
	m_stealthOverlay->QueueRender();
}

void POIGrapichalEffects::UpdateShieldEffect(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x, p_position.y + 1.1f, p_position.z);
	DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));
	position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 2.0f;
	position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 2.0f;
	position.z = 0.0f;
	m_shieldOverlay->SetPosition(position);

	m_shieldLight.m_position.x = p_position.x;
	m_shieldLight.m_position.y = 1.0f;
	m_shieldLight.m_position.z = p_position.z;
	PointLights::GetInstance()->AddLight(m_shieldLight);
}

void POIGrapichalEffects::RenderShieldEffect()
{
	m_shieldOverlay->QueueRender();
}