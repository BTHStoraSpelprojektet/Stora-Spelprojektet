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
	bool m_increasingOpacity;
	float m_opacity;

	GUIElement* m_flashEffect;
};
#endif