#include "FlashBang.h"
#include "GUIElement.h"

FalshBang& FalshBang::GetInstance()
{
	static FalshBang instance;

	return instance;
}

bool FalshBang::Initialize()
{
	m_flashed = false;
	m_increasingOpacity = false;
	m_opacity = 0.0f;

	// TODO, initialisera m_flashEffect.

	return true;
}

void FalshBang::Shutdown()
{
	if (m_flashEffect != nullptr)
	{
		delete m_flashEffect;
		m_flashEffect = nullptr;
	}
}

void FalshBang::TrowFlash(DirectX::XMFLOAT3 p_position)
{
	// TODO, kasta ny modell.
}

void FalshBang::UpdateFlashBangs()
{
	// TODO, uppdatera modeller.
}

void FalshBang::GetFlashed()
{
	m_flashed = true;
	m_increasingOpacity = true;
}

void FalshBang::InterruptFlash()
{
	m_flashed = false;
	m_increasingOpacity = false;
	m_opacity = 0.0f;
}

void FalshBang::UpdateEffect()
{
	// TODO, räkna opacity bla bla.
}

void FalshBang::RenderEffect()
{
	m_flashEffect->QueueRender();
}