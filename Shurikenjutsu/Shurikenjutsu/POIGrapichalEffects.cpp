#include "POIGrapichalEffects.h"
#include "GUIElement.h"
#include "ParticleEmitter.h"
#include "Globals.h"
#include "../CommonLibs/TextureLibrary.h"
#include "GraphicsEngine.h"
#include "..\CommonLibs\CommonEnums.h"

POIGrapichalEffects& POIGrapichalEffects::GetInstance()
{
	static POIGrapichalEffects instance;

	return instance;
}

bool POIGrapichalEffects::Initialize()
{
	m_healingParticles = new ParticleEmitter();
	m_healingParticles->Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0), DirectX::XMFLOAT2(0.2f, 0.2f), PARTICLE_PATTERN_HEALING);
	m_healingParticles->SetEmitParticleState(true);
	m_heal = true;

	m_healingLight.m_ambient = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	m_healingLight.m_diffuse = DirectX::XMVectorSet(0.2f, 2.5f, 0.2f, 0.0f);
	m_healingLight.m_specular = DirectX::XMVectorSet(0.2f, 1.0f, 0.2f, 0.0f);
	m_healingLight.m_position.x = 0.0f;
	m_healingLight.m_position.y = -10.0f;
	m_healingLight.m_position.z = 0.0f;
	m_healingLight.m_range = 2.0f;
	
	m_stealthOverlay = new GUIElement();
	m_stealthOverlay->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/Particles/StealthOverlay.png"));

	m_shieldParticles = new ParticleEmitter();
	m_shieldParticles->Initialize(GraphicsEngine::GetDevice(), DirectX::XMFLOAT3(2.0f, 1.5f, 2.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), DirectX::XMFLOAT2(0.025f, 0.025f), PARTICLE_PATTERN_SHIELD);
	m_shieldParticles->SetEmitParticleState(true);

	m_shieldOverlay = new GUIElement();
	m_shieldOverlay->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0), 90.0f, 140.0f, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/Particles/ShieldOverlay3.png"));

	m_shieldLight.m_ambient = DirectX::XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	m_shieldLight.m_diffuse = DirectX::XMVectorSet(10.0f, 10.0f, 5.0f, 0.0f);
	m_shieldLight.m_specular = DirectX::XMVectorSet(2.5f, 2.5f, 2.5f, 0.0f);
	m_shieldLight.m_position.x = 0.0f;
	m_shieldLight.m_position.y = -10.0f;
	m_shieldLight.m_position.z = 0.0f;
	m_shieldLight.m_range = 1.6f;

	m_renderHeal = false;
	m_renderShield = false;

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

	if (m_shieldParticles != nullptr)
	{
		m_shieldParticles->Shutdown();
		delete m_shieldParticles;
		m_shieldParticles = nullptr;
	}
}

void POIGrapichalEffects::SetHealEmit(bool p_value)
{
	m_healingParticles->SetEmitParticleState(p_value);
	m_heal = p_value;
}

void POIGrapichalEffects::SetShieldEmit(bool p_value)
{
	m_shieldParticles->SetEmitParticleState(p_value);
}

void POIGrapichalEffects::UpdateHealingEffect(DirectX::XMFLOAT3 p_position)
{
	m_renderHeal = GraphicsEngine::IsVisibilityPointVisible(Point(p_position.x, p_position.z));
	m_healingParticles->UpdatePosition(p_position);
	m_healingParticles->Update();

	if (m_heal && m_renderHeal)
	{
		m_healingLight.m_position.x = p_position.x;
		m_healingLight.m_position.y = 1.0f;
		m_healingLight.m_position.z = p_position.z;
		GraphicsEngine::AddNewPointLight(m_healingLight);
	}
}

void POIGrapichalEffects::RenderHealingEffect()
{
	if (m_renderHeal)
	{
		m_healingParticles->Render();
	}
}

void POIGrapichalEffects::RenderStealthEffect()
{
	m_stealthOverlay->QueueRender();
}

void POIGrapichalEffects::UpdateShieldEffect(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	m_renderShield = GraphicsEngine::IsVisibilityPointVisible(Point(p_position.x, p_position.z));
	m_shieldParticles->UpdatePosition(DirectX::XMFLOAT3(p_position.x, p_position.y + 1.5f, p_position.z));
	m_shieldParticles->Update();

	DirectX::XMFLOAT4X4 vp;
	DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x, p_position.y + 1.1f, p_position.z);
	DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));
	position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 2.0f;
	position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 2.0f;
	position.z = 0.0f;
	m_shieldOverlay->SetPosition(position);

	if (m_renderShield)
	{
		m_shieldLight.m_position.x = p_position.x;
		m_shieldLight.m_position.y = 1.0f;
		m_shieldLight.m_position.z = p_position.z;
		GraphicsEngine::AddNewPointLight(m_shieldLight);
	}
}

void POIGrapichalEffects::RenderShieldEffect()
{
	if (m_renderShield)
	{
		m_shieldParticles->Render();
		m_shieldOverlay->QueueRender();
	}
}