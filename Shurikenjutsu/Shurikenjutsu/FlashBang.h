#ifndef FLASHBANG_H_
#define FLASHBANG_H_

#include <DirectXMath.h>
#include <vector>

class GUIElement;
class ParticleEmitter;
class Trail;

struct FlashBomb
{
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT2 m_XYDirection;
	float m_angle;

	ParticleEmitter* m_particles;
	Trail* m_trail;
};

class FlashBang
{
public:
	static FlashBang& GetInstance();

	bool Initialize();
	void Shutdown();

	void TrowFlash(DirectX::XMFLOAT3 p_position);
	void UpdateFlashBangs();

	void GetFlashed();
	void InterruptFlash();
	void UpdateEffect();
	void RenderEffect();

private:
	FlashBang(){};
	FlashBang(FlashBang const&);
	void operator=(FlashBang const&);

	std::vector<FlashBomb> m_flashbangs;

	bool m_flashed;
	float m_opacity;
	float m_holdTime;
	float m_sizeVariation;
	float m_sizeDirection;
	enum OPACITY_STATE
	{
		OPACITY_INCREASE, 
		OPACITY_HOLD,
		OPACITY_DECREASE,
		OPACITY_NONE
	};
	OPACITY_STATE m_opacityState;

	GUIElement* m_flashEffect;
};
#endif