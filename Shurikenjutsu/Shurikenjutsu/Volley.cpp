#include "Volley.h"
#include "VolleyObject.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"

Volley::Volley(){}
Volley::~Volley(){}

bool Volley::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition)
{
	m_timer = 0.0f;

	AddRandomProjectiles(8, p_startPosition, p_endPosition);
	return true;
}

void Volley::Shutdown()
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Shutdown();
	}
}

bool Volley::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		bool remove = m_projectiles[i]->Update(m_timer);
		if (remove)
		{
			m_projectiles.erase(m_projectiles.begin() + i);
			i--;
		}

		if (m_projectiles.size() == 0)
		{
			return true;
		}
	}
	return false;
}

void Volley::Render()
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Render();
	}
}

void Volley::RenderDepth()
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->RenderDepth();
	}
}

void Volley::AddRandomProjectiles(int p_amount, DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition)
{
	float angle = DirectX::XM_2PI / p_amount;

	DirectX::XMFLOAT3 endPosition = p_endPosition;
	VolleyObject* projectile = new VolleyObject;
	projectile->Initialize(SHURIKEN_MODEL_NAME, p_startPosition, endPosition);
	m_projectiles.push_back(projectile);

	for (int i = 0; i < p_amount; i++)
	{
		endPosition = DirectX::XMFLOAT3(p_endPosition.x + cosf(angle*i)*VOLLEY_RADIUS*3.0f, p_endPosition.y, p_endPosition.z + sinf(angle*i)*VOLLEY_RADIUS*3.0f);
		projectile = new VolleyObject;
		projectile->Initialize(SHURIKEN_MODEL_NAME, p_startPosition, endPosition);
		m_projectiles.push_back(projectile);
	}
}