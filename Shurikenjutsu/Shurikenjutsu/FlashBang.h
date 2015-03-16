#ifndef FLASHBANG_H_
#define FLASHBANG_H_

#include <DirectXMath.h>

class GUIElement;

class FalshBang
{
public:
	static FalshBang& GetInstance();

	bool Initialize();
	void Shutdown();

	void TrowFlash(DirectX::XMFLOAT3 p_position);
	void UpdateFlashBangs();

	void GetFlashed();
	void InterruptFlash();
	void UpdateEffect();
	void RenderEffect();

private:
	FalshBang(){};
	FalshBang(FalshBang const&);
	void operator=(FalshBang const&);

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