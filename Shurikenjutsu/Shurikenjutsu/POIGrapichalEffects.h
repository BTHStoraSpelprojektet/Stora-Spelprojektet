#ifndef POIGRAPICHALEFFECTS_H_
#define POIGRAPICHALEFFECTS_H_

#include <DirectXMath.h>
#include "..\CommonLibs\CommonStructures.h"

class GUIElement;
class ParticleEmitter;
class PointLights;

class POIGrapichalEffects
{
public:
	static POIGrapichalEffects& GetInstance();

	bool Initialize();
	void Shutdown();
	
	void SetHealEmit(bool p_value);
	void UpdateHealingEffect(DirectX::XMFLOAT3 p_position);
	void RenderHealingEffect();

	void RenderStealthEffect();

	void SetShieldEmit(bool p_value);
	void UpdateShieldEffect(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);
	void RenderShieldEffect();

private:
	POIGrapichalEffects() {};
	POIGrapichalEffects(POIGrapichalEffects const&);
	void operator=(POIGrapichalEffects const&);

	ParticleEmitter* m_healingParticles;
	PointLight m_healingLight;
	bool m_heal;

	GUIElement* m_stealthOverlay;

	ParticleEmitter* m_shieldParticles;
	GUIElement* m_shieldOverlay;
	PointLight m_shieldLight;

	bool m_renderHeal;
	bool m_renderShield;
};

#endif