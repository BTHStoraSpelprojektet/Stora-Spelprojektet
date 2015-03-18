#ifndef FLASHBANG_H_
#define FLASHBANG_H_

#include <DirectXMath.h>
#include <vector>

class GUIElement;
class ParticleEmitter;
class Trail;
class GraphicsEngine;
class Object;

struct FlashbangBomb
{
	DirectX::XMFLOAT3 m_startPosition;
	DirectX::XMFLOAT3 m_currentPosition;

	//ParticleEmitter* m_particles;
	Trail* m_trail;

	float m_percentX;
	float m_percentZ;
	float m_angle;

	float m_timePassed;
	float m_speed;
	bool m_alive;

	DirectX::XMFLOAT4X4 m_worldMatrix;
};

struct FlashbangExplosions
{
	ParticleEmitter* m_particles;
	float m_timePassed;
	float m_timeToLive;
};

class FlashBang
{
public:
	static FlashBang& GetInstance();

	bool Initialize();
	void Shutdown();

	void TrowFlash(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition);
	void UpdateFlashbangs(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_playerDirection);
	void RenderFlashbangs();

	void GetFlashed();
	void InterruptFlash();
	void UpdateEffect();
	void RenderEffect();

	bool IsPlayerFlashed();

private:
	FlashBang(){};
	FlashBang(FlashBang const&);
	void operator=(FlashBang const&);

	void Impact(DirectX::XMFLOAT3 p_playerPosition, DirectX::XMFLOAT3 p_impactPosition, DirectX::XMFLOAT3 p_playerDirection);

	Object* m_model;

	std::vector<FlashbangBomb> m_flashbangs;
	std::vector<FlashbangExplosions> m_flashbangBangs;

	bool m_flashed;
	float m_opacity;
	float m_holdTime;
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