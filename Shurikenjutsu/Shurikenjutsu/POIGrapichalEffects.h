#ifndef POIGRAPICHALEFFECTS_H_
#define POIGRAPICHALEFFECTS_H_

#include <DirectXMath.h>
#include "Structures.h"
#include "GraphicsEngine.h"

class GUIElement;
class ParticleEmitter;
class PointLights;

class POIGrapichalEffects
{
public:
	static POIGrapichalEffects& GetInstance();

	bool Initialize();
	void Shutdown();

	void StartHealing();
	void StopHealing();
	void UpdateHealingEffect(DirectX::XMFLOAT3 p_position);
	void RenderHealingEffect();

	void RenderStealthEffect();

	void UpdateShieldEffect(DirectX::XMFLOAT3 p_position);
	void RenderShieldEffect();

private:
	POIGrapichalEffects() {};
	POIGrapichalEffects(POIGrapichalEffects const&);
	void operator=(POIGrapichalEffects const&);

	ParticleEmitter* m_healingParticles;
	PointLight m_healingLight;
	bool m_heal;

	GUIElement* m_stealthOverlay;

	GUIElement* m_shieldOverlay;
};

#endif