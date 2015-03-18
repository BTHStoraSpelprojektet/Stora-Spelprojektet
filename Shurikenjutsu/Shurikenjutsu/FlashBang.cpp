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
#include "CollisionManager.h"
#include "Object.h"

FlashBang& FlashBang::GetInstance()
{
	static FlashBang instance;

	return instance;
}

bool FlashBang::Initialize()
{
	m_model = new Object();
	m_model->Initialize("../Shurikenjutsu/Models/flashbang_Shape.SSP", DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));

	m_flashbangs.clear();
	m_flashbangBangs.clear();

	m_flashed = false;
	m_opacityState = OPACITY_NONE;
	m_opacity = 0.0f;

	m_flashEffect = new GUIElement();
	m_flashEffect->Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 1500.0f, 1500.0f, TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/Particles/Flash.png"));

	return true;
}

void FlashBang::Shutdown()
{
	if (m_model != nullptr)
	{
		m_model->Shutdown();
		delete m_model;
		m_model = nullptr;
	}

	if (m_flashEffect != nullptr)
	{
		delete m_flashEffect;
		m_flashEffect = nullptr;
	}

	for (unsigned int i = 0; i < m_flashbangs.size(); i++)
	{
		/*m_flashbangs[i].m_particles->Shutdown();
		delete m_flashbangs[i].m_particles;
		m_flashbangs[i].m_particles = nullptr;*/

		m_flashbangs[i].m_trail->Shutdown();
		delete m_flashbangs[i].m_trail;
		m_flashbangs[i].m_trail = nullptr;
	}
	m_flashbangs.clear();

	for (unsigned int i = 0; i < m_flashbangBangs.size(); i++)
	{
		m_flashbangBangs[i].m_particles->Shutdown();
		delete m_flashbangBangs[i].m_particles;
		m_flashbangBangs[i].m_particles = nullptr;
	}
	m_flashbangBangs.clear();
}

void FlashBang::TrowFlash(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition)
{
	FlashbangBomb newBomb;

	newBomb.m_startPosition = p_startPosition;
	newBomb.m_currentPosition.x = p_startPosition.x;
	newBomb.m_currentPosition.y = 1.0f;
	newBomb.m_currentPosition.z = p_startPosition.z;

	newBomb.m_timePassed = 0.0f;
	newBomb.m_speed = 20.0f;
	newBomb.m_alive = true;

	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x * x + z * z);
	newBomb.m_percentX = x / length;
	newBomb.m_percentZ = z / length;
	newBomb.m_angle = asinf((9.82f * length) / (newBomb.m_speed * newBomb.m_speed)) * 0.5f;
	
	/*newBomb.m_particles = new ParticleEmitter();
	if (!newBomb.m_particles->Initialize(GraphicsEngine::GetDevice(), p_startPosition, DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(0.2f, 0.2f), PARTICLE_PATTERN_FIRE_TORCH))
	{
		ConsolePrintErrorAndQuit("A flashbang fuse emitter failed to initialize!");
	}
	newBomb.m_particles->SetEmitParticleState(true);*/

	newBomb.m_trail = new Trail();
	if (!newBomb.m_trail->Initialize(50.0f, 0.2f, 0.1f, DirectX::XMFLOAT4(0.83f, 0.86f, 0.06f, 1.0f), "../Shurikenjutsu/2DTextures/Particles/Trail.png"))
	{
		ConsolePrintErrorAndQuit("A flashbang trail failed to initialize!");
	}

	DirectX::XMStoreFloat4x4(&newBomb.m_worldMatrix, DirectX::XMMatrixIdentity());

	m_flashbangs.push_back(newBomb);
}

void FlashBang::UpdateFlashbangs(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_playerDirection)
{
	float dt = (float)GLOBAL::GetInstance().GetDeltaTime();

	for (unsigned int i = 0; i < m_flashbangs.size(); i++)
	{
		m_flashbangs[i].m_timePassed += dt;

		float x = m_flashbangs[i].m_speed * m_flashbangs[i].m_timePassed * cosf(m_flashbangs[i].m_angle) * m_flashbangs[i].m_percentX;
		float y = m_flashbangs[i].m_speed * m_flashbangs[i].m_timePassed * sinf(m_flashbangs[i].m_angle) - 4.91f * m_flashbangs[i].m_timePassed * m_flashbangs[i].m_timePassed;
		float z = m_flashbangs[i].m_speed * m_flashbangs[i].m_timePassed * cosf(m_flashbangs[i].m_angle) * m_flashbangs[i].m_percentZ;

		m_flashbangs[i].m_currentPosition.x = m_flashbangs[i].m_startPosition.x + x;
		m_flashbangs[i].m_currentPosition.y = m_flashbangs[i].m_startPosition.y + 5.0f * y;
		m_flashbangs[i].m_currentPosition.z = m_flashbangs[i].m_startPosition.z + z;

		/*m_flashbangs[i].m_particles->SetPosition(m_flashbangs[i].m_currentPosition);
		m_flashbangs[i].m_particles->Update();*/
		m_flashbangs[i].m_trail->Update(m_flashbangs[i].m_currentPosition, atan2(m_flashbangs[i].m_percentZ, m_flashbangs[i].m_percentX));

		if (m_flashbangs[i].m_currentPosition.y < 0.0f && m_flashbangs[i].m_alive)
		{
			m_flashbangs[i].m_alive = false;

			Impact(p_position, m_flashbangs[i].m_currentPosition, p_playerDirection);
		}
	}

	for (unsigned int i = 0; i < m_flashbangBangs.size(); i++)
	{
		m_flashbangBangs[i].m_timePassed += dt;
		m_flashbangBangs[i].m_particles->Update();

		if (m_flashbangBangs[i].m_timePassed > m_flashbangBangs[i].m_timeToLive)
		{
			m_flashbangBangs[i].m_particles->SetEmitParticleState(false);
		}
	}

	bool keepDeleting = true;
	while (keepDeleting)
	{
		for (unsigned int i = 0; i < m_flashbangs.size(); i++)
		{
			if (!m_flashbangs[i].m_alive)
			{
				/*m_flashbangs[i].m_particles->Shutdown();
				delete m_flashbangs[i].m_particles;
				m_flashbangs[i].m_particles = nullptr;*/

				m_flashbangs[i].m_trail->Shutdown();
				delete m_flashbangs[i].m_trail;
				m_flashbangs[i].m_trail = nullptr;

				m_flashbangs.erase(m_flashbangs.begin() + i);

				break;
			}
		}

		keepDeleting = false;
	}

	keepDeleting = true;
	while (keepDeleting)
	{
		for (unsigned int i = 0; i < m_flashbangBangs.size(); i++)
		{
			if (m_flashbangBangs[i].m_particles->GetParticleCount() <= 0)
			{
				m_flashbangBangs[i].m_particles->Shutdown();
				delete m_flashbangBangs[i].m_particles;
				m_flashbangBangs[i].m_particles = nullptr;

				m_flashbangBangs.erase(m_flashbangBangs.begin() + i);

				break;
			}
		}

		keepDeleting = false;
	}
}

void FlashBang::RenderFlashbangs()
{
	for (unsigned int i = 0; i < m_flashbangs.size(); i++)
	{
		// TODO, updatera världsmatrisen och rendera alla bombs.

		/*m_flashbangs[i].m_particles->Render();*/
		m_flashbangs[i].m_trail->Render();
	}

	for (unsigned int i = 0; i < m_flashbangBangs.size(); i++)
	{
		m_flashbangBangs[i].m_particles->Render();
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

void FlashBang::Impact(DirectX::XMFLOAT3 p_playerPosition, DirectX::XMFLOAT3 p_impactPosition, DirectX::XMFLOAT3 p_playerDirection)
{
	float x = p_impactPosition.x - p_playerPosition.x;
	float z = p_impactPosition.z - p_playerPosition.z;

	if (!CollisionManager::GetInstance()->IntersectingObjectWhenAttacking(p_playerPosition, p_impactPosition, true))
	{
		float distance = sqrt(x * x + z * z);

		if (distance <= FLASHBANG_RADIUS)
		{
			float playerDirLeangth = sqrt(p_playerDirection.x * p_playerDirection.x + p_playerDirection.z * p_playerDirection.z);
			float playerToFlahLeangth = sqrt(x * x + z * z);

			float dotProduct = p_playerDirection.x * x + p_playerDirection.z * z;
			float angle = acos(dotProduct / (playerDirLeangth* playerToFlahLeangth));

			if (angle < DirectX::XM_PIDIV2)
			{
				GetFlashed();
			}
		}
	}

	FlashbangExplosions explosion;
	explosion.m_timePassed = 0.0f;
	explosion.m_timeToLive = 0.1f;
	explosion.m_particles = new ParticleEmitter();
	if (!explosion.m_particles->Initialize(GraphicsEngine::GetDevice(), p_impactPosition, DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT2(1.5f, 1.5f), PARTICLE_PATTERN_FLASHBANG_SPARKS))
	{
		ConsolePrintErrorAndQuit("A flashbang explosion emitter failed to initialize!");
	}
	explosion.m_particles->SetEmitParticleState(true);
	
	m_flashbangBangs.push_back(explosion);
}