#include "FlashBang.h"
#include "GUIElement.h"
#include "Globals.h"
#include "ParticleEmitter.h"
#include "Trail.h"
#include "GraphicsEngine.h"
#include "../CommonLibs/GameplayGlobalVariables.h"
#include "../CommonLibs/TextureLibrary.h"
#include "../CommonLibs/ConsoleFunctions.h"
#include "../CommonLibs/CommonEnums.h"

FlashBang& FlashBang::GetInstance()
{
	static FlashBang instance;

	return instance;
}

bool FlashBang::Initialize()
{
	m_flashbangs.clear();

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

void FlashBang::TrowFlash(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition, DirectX::XMFLOAT3 p_direction)
{
	FlashBomb newBomb;

	newBomb.m_startPosition = p_startPosition;
	newBomb.m_endPosition = p_endPosition;
	newBomb.m_currentPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	newBomb.m_direction = p_direction;

	newBomb.m_particles = new ParticleEmitter();
	if (!newBomb.m_particles->Initialize(GraphicsEngine::GetDevice(), p_startPosition, DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(0.1f, 0.1f), PARTICLE_PATTERN_FLASHBANG_SPARKS));
	{
		ConsolePrintErrorAndQuit("A flashbang particle emitter failed to initialize!");
	}

	newBomb.m_trail = new Trail();
	if (!newBomb.m_trail->Initialize(50.0f, 0.2f, 0.2f, DirectX::XMFLOAT4(0.83f, 0.86f, 0.06f, 1.0f), "../Shurikenjutsu/2DTextures/Particles/Trail.png"))
	{
		ConsolePrintErrorAndQuit("A flashbang trail failed to initialize!");
	}
	newBomb.m_trail->StartEmiting();

	newBomb.m_alive = true;

	m_flashbangs.push_back(newBomb);
}

void FlashBang::UpdateFlashbangs()
{
	float angle = 0.0f;

	for (unsigned int i = 0; i < m_flashbangs.size(); i++)
	{
		// TODO, uppdatera positioner och angle.

		m_flashbangs[i].m_particles->SetPosition(m_flashbangs[i].m_currentPosition);
		m_flashbangs[i].m_particles->Update();
		m_flashbangs[i].m_trail->Update(m_flashbangs[i].m_currentPosition, angle);

		if (m_flashbangs[i].m_currentPosition.y < 0.0f)
		{
			m_flashbangs[i].m_alive = false;
		}
	}

	bool keepDeleting = true;
	while (keepDeleting)
	{
		for (unsigned int i = 0; i < m_flashbangs.size(); i++)
		{
			if (!m_flashbangs[i].m_alive)
			{
				m_flashbangs.erase(m_flashbangs.begin() + i);
				keepDeleting = true;

				break;
			}

			keepDeleting = false;
		}
	}
}

void FlashBang::RenderFlashbangs()
{
	for (unsigned int i = 0; i < m_flashbangs.size(); i++)
	{
		m_flashbangs[i].m_particles->Render();
		m_flashbangs[i].m_trail->Render();
	}
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

void FlashBang::UpdateEffect()
{
	if (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH != m_flashEffect->GetSize().x)
	{
		m_flashEffect->SetSize(DirectX::XMFLOAT2((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT));
	}

	if (m_flashed)
	{
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