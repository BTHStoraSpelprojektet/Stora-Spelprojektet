#include "FlashBang.h"
#include "GUIElement.h"
#include "Globals.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "../CommonLibs/TextureLibrary.h"

FlashBang& FlashBang::GetInstance()
{
	static FlashBang instance;

	return instance;
}

bool FlashBang::Initialize()
{
	m_flashed = false;
	m_opacityState = OPACITY_NONE;
	m_opacity = 0.0f;

	m_flashEffect = new GUIElement();
	m_flashEffect->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 1500.0f, 1500.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Particles/Flash.png"));

	m_sizeVariation = 0.0f;
	m_sizeDirection = 1.0f;

	return true;
}

void FlashBang::Shutdown()
{
	if (m_flashEffect != nullptr)
	{
		delete m_flashEffect;
		m_flashEffect = nullptr;
	}
}

void FlashBang::TrowFlash(DirectX::XMFLOAT3 p_position)
{
	// TODO, kasta ny modell.
}

void FlashBang::UpdateFlashBangs()
{
	// TODO, uppdatera modeller.
}

void FlashBang::GetFlashed()
{
	m_flashed = true;
	m_opacityState = OPACITY_INCREASE;
	m_holdTime = FLASHBANG_HOLD_TIME;
}

void FlashBang::InterruptFlash()
{
	m_flashed = false;
	m_opacityState = OPACITY_NONE;
	m_opacity = 0.0f;
}

void FlashBang::UpdateEffect(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection)
{
	if (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH != m_flashEffect->GetSize().x)
	{
		m_flashEffect->SetSize(DirectX::XMFLOAT2((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT));
	}

	if (m_flashed)
	{
		/*DirectX::XMFLOAT4X4 vp;
		DirectX::XMStoreFloat4x4(&vp, DirectX::XMLoadFloat4x4(&p_view) * DirectX::XMLoadFloat4x4(&p_projection));
		DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(p_position.x, p_position.y + 1.5f, p_position.z);
		DirectX::XMStoreFloat3(&position, DirectX::XMVector3TransformCoord(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat4x4(&vp)));
		position.x *= GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 2.0f;
		position.y *= position.z * GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 2.0f;
		position.z = 0.0f;
		m_flashEffect->SetPosition(position);*/

		switch (m_opacityState)
		{
			case(OPACITY_INCREASE) :
			{
				m_opacity += (float)GLOBAL::GetInstance().GetDeltaTime() * 7.5f;

				if (m_opacity >= 1.0f)
				{
					m_opacity = 1.0f;
					m_opacityState = OPACITY_HOLD;
				}

				break;
			}

			case(OPACITY_HOLD) :
			{
				m_holdTime -= (float)GLOBAL::GetInstance().GetDeltaTime();

				if (m_holdTime <= 0.0f)
				{
					m_holdTime = FLASHBANG_HOLD_TIME;
					m_opacityState = OPACITY_DECREASE;
				}

				break;
			}

			case(OPACITY_DECREASE) :
			{
				m_opacity -= (float)GLOBAL::GetInstance().GetDeltaTime() * 0.4f;

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

		m_sizeVariation += ((float)GLOBAL::GetInstance().GetDeltaTime() * 25.0f) * m_sizeDirection;

		if (m_sizeVariation > 10.0f)
		{
			m_sizeDirection = -1.0f;
		}

		else if (m_sizeVariation < -10.0f)
		{
			m_sizeDirection = 1.0f;
		}

		m_flashEffect->SetSize(DirectX::XMFLOAT2((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH + m_sizeVariation, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT + m_sizeVariation));
		m_flashEffect->SetOpacity(m_opacity);
	}
}

void FlashBang::RenderEffect()
{
	if (m_flashed)
	{
		m_flashEffect->QueueRender();
	}
}