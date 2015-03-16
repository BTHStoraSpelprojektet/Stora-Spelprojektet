#include "FlashBang.h"
#include "GUIElement.h"
#include "Globals.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "../CommonLibs/TextureLibrary.h"

FalshBang& FalshBang::GetInstance()
{
	static FalshBang instance;

	return instance;
}

bool FalshBang::Initialize()
{
	m_flashed = false;
	m_opacityState = OPACITY_NONE;
	m_opacity = 0.0f;

	m_flashEffect = new GUIElement();
	m_flashEffect->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 500.0f, 500.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Particles/Flash.png"));

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
	m_opacityState = OPACITY_INCREASE;
	m_holdTime = FLASHBANG_HOLD_TIME;
}

void FalshBang::InterruptFlash()
{
	m_flashed = false;
	m_opacityState = OPACITY_NONE;
	m_opacity = 0.0f;
}

void FalshBang::UpdateEffect()
{
	if (m_flashed)
	{
		switch (m_opacityState)
		{
			case(OPACITY_INCREASE) :
			{
				m_opacity += GLOBAL::GetInstance().GetDeltaTime() * 0.5;

				if (m_opacity >= 1.0f)
				{
					m_opacity = 1.0f;

					m_opacityState = OPACITY_HOLD;
				}

				break;
			}

			case(OPACITY_HOLD) :
			{
				m_holdTime -= GLOBAL::GetInstance().GetDeltaTime();

				if (m_holdTime <= 0.0f)
				{
					m_holdTime = 0.0f;

					m_opacityState = OPACITY_DECREASE;
				}

				break;
			}

			case(OPACITY_DECREASE) :
			{
				m_opacity -= GLOBAL::GetInstance().GetDeltaTime() * 0.5;

				if (m_opacity <= 0.0f)
				{
					m_opacity = 0.0f;

					m_opacityState = OPACITY_NONE;
				}

				break;
			}

			case(OPACITY_NONE) :
			{
				break;
			}

			default:
			{
				break;
			}
		}
	}
}

void FalshBang::RenderEffect()
{
	if (m_flashed)
	{
		m_flashEffect->QueueRender();
	}
}