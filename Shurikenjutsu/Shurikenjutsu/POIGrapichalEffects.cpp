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
	return true;
}

void POIGrapichalEffects::Shutdown()
{

}

void POIGrapichalEffects::StartHealing()
{

}

void POIGrapichalEffects::StopHealing()
{

}

void POIGrapichalEffects::UpdateHealingEffect(DirectX::XMFLOAT3 p_position)
{

}

void POIGrapichalEffects::RenderHealingEffect()
{

}


void POIGrapichalEffects::RenderStealthEffect()
{

}

void POIGrapichalEffects::UpdateShieldEffect(DirectX::XMFLOAT3 p_position)
{

}

void POIGrapichalEffects::RenderShieldEffect()
{

}