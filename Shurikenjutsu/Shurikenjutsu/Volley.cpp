#include "Volley.h"
#include "MovingObject.h"
#include "Globals.h"
#include "..\CommonLibs\ModelNames.h"

Volley::Volley(){}
Volley::~Volley(){}

bool Volley::Initialize(DirectX::XMFLOAT3 p_startPosition, DirectX::XMFLOAT3 p_endPosition)
{
	m_startPosition = p_startPosition;
	m_endPosition = p_endPosition;

	m_timer = 0.0f;

	
	float x = (p_endPosition.x - p_startPosition.x);
	float z = (p_endPosition.z - p_startPosition.z);
	float length = sqrtf(x*x + z*z);
	m_percentX = x / length;
	m_percentZ = z / length;
	m_speed = length;
	m_angle = asinf((9.82f * length) / (m_speed * m_speed)) * 0.5f;
	m_lastPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	AddRandomProjectiles(8);
	return true;
}

void Volley::Shutdown()
{
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i]->Shutdown();
	}
}

void Volley::Update()
{
	m_timer += (float)GLOBAL::GetInstance().GetDeltaTime();

	DirectX::XMFLOAT3 directions = DirectX::XMFLOAT3(m_endPosition.x - m_startPosition.x, m_endPosition.y - m_startPosition.y, m_endPosition.z - m_startPosition.z);
	DirectX::XMStoreFloat3(&directions, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&directions)));

	float x = m_speed * m_timer * cosf(m_angle) * m_percentX;
	float y = m_speed * m_timer * sinf(m_angle) - 0.5f * 9.82f * m_timer * m_timer;
	float z = m_speed * m_timer * cosf(m_angle) * m_percentZ;
	
	for (unsigned int i = 0; i < m_projectiles.size(); i++)
	{
		DirectX::XMFLOAT3 position = m_projectiles[i]->GetPosition();
		DirectX::XMFLOAT3 direction = m_projectiles[i]->GetDirection();

		DirectX::XMFLOAT3 newDirection = DirectX::XMFLOAT3(x - m_lastPosition.x, y - m_lastPosition.y, z - m_lastPosition.z);
		DirectX::XMStoreFloat3(&newDirection, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&newDirection)));
		newDirection = DirectX::XMFLOAT3(direction.x + newDirection.x, direction.y + newDirection.y, direction.z + newDirection.z);
		DirectX::XMStoreFloat3(&newDirection, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&newDirection)));
		m_projectiles[i]->SetDirection(newDirection);
		DirectX::XMFLOAT3 newPosition = DirectX::XMFLOAT3(position.x + direction.x*m_projectiles[i]->GetSpeed()*(float)GLOBAL::GetInstance().GetDeltaTime(), position.y + direction.y*m_projectiles[i]->GetSpeed()*(float)GLOBAL::GetInstance().GetDeltaTime(), position.z + direction.z*m_projectiles[i]->GetSpeed()*(float)GLOBAL::GetInstance().GetDeltaTime());
		m_projectiles[i]->SetPosition(DirectX::XMFLOAT3(newPosition.x, newPosition.y, newPosition.z));
	}
	m_lastPosition = DirectX::XMFLOAT3(x, y, z);
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

void Volley::AddRandomProjectiles(int p_amount)
{
	DirectX::XMFLOAT3 castDirection = DirectX::XMFLOAT3(m_endPosition.x - m_startPosition.x, m_endPosition.y - m_startPosition.y, m_endPosition.z - m_startPosition.z);
	DirectX::XMStoreFloat3(&castDirection, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&castDirection)));

	float angle = DirectX::XM_2PI / p_amount;

	float angles = atan2f(m_endPosition.z - m_startPosition.z, m_endPosition.x - m_startPosition.x);

	for (int i = 0; i < p_amount; i++)
	{
		DirectX::XMFLOAT3 direction;
		DirectX::XMStoreFloat3(&direction, DirectX::XMVector3Rotate(DirectX::XMVectorSet(0, 1, 0, 0), DirectX::XMQuaternionRotationRollPitchYaw(0, angles, angle*i)));

		DirectX::XMStoreFloat3(&direction, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&direction)));
		MovingObject* projectile = new MovingObject;
		projectile->Initialize(SHURIKEN_MODEL_NAME, m_startPosition, direction, 3.0f);
		m_projectiles.push_back(projectile);
		projectile = new MovingObject;
		projectile->Initialize(SHURIKEN_MODEL_NAME, m_startPosition, direction, 2.0f);
		m_projectiles.push_back(projectile);
		projectile = new MovingObject;
		projectile->Initialize(SHURIKEN_MODEL_NAME, m_startPosition, direction, 1.0f);
		m_projectiles.push_back(projectile);	
	}
}