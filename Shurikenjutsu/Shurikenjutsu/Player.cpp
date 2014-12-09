#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
	float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility)
{
	if (!MovingObject::Initialize(p_filepath, p_pos, p_direction, p_speed))
	{
		return false;
	}
	SetDamage(p_damage);
	m_spells = p_spells;
	SetHealth(p_health);
	SetAgility(p_agility);
	SetAttackDirection(DirectX::XMFLOAT3(0, 0, 0));

	m_inputManager = InputManager::GetInstance();

	return true;
}

void Player::Shutdown()
{
	MovingObject::Shutdown();
}

void Player::UpdateMe(double p_deltaTime)
{
	// Move
	bool moved = false;
	float x, y, z;

	x = 0;
	y = 0;
	z = 0;

	m_playerPrevPos = m_position;
	Box charBox = Box(m_position, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	bool up = Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(0.0f, 0.0f, 36.0f), DirectX::XMFLOAT3(40.0f, 1.0f, 1.0f)));
	bool down = Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(0.0f, 0.0f, -33.0f), DirectX::XMFLOAT3(40.0f, 1.0f, 1.0f)));
	bool left = Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(-35.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)));
	bool right = Collisions::BoxBoxCollision(charBox, Box(DirectX::XMFLOAT3(35.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(1.0f, 1.0f, 40.0f)));
	if (m_inputManager->IsKeyPressed(VkKeyScan('w')))
	{
		if (!up)
		{ 
		z += 1;
		moved = true;
	}
	}

	if (m_inputManager->IsKeyPressed(VkKeyScan('a')))
	{
		if (!left)
		{
		x += -1;
		moved = true;
	}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('s')))
	{
		if (!down)
		{
		z += -1;
		moved = true;
	}
	}
	if (m_inputManager->IsKeyPressed(VkKeyScan('d')))
	{
		if (!right)
		{
		x += 1;
		moved = true;
	}
	}

	DirectX::XMVECTOR tempVector = DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(x, y, z));
	tempVector = DirectX::XMVector3Normalize(tempVector);
	DirectX::XMFLOAT3 tempFloat;
	DirectX::XMStoreFloat3(&tempFloat, tempVector);
	SetDirection(tempFloat);
	if (moved || Network::ConnectedNow())
	{
		SendPosition(DirectX::XMFLOAT3(m_position.x + m_direction.x * m_speed * (float)p_deltaTime, m_position.y + m_direction.y * m_speed * (float)p_deltaTime, m_position.z + m_direction.z * m_speed * (float)p_deltaTime));
	}

	// Melee attack
	if (InputManager::GetInstance()->IsLeftMouseClicked())
	{
		Network::DoMeleeAttack();
	}

	// Cast shuriken
	if (InputManager::GetInstance()->IsRightMouseClicked())
	{
		Network::AddShurikens(GetPosition().x, 1.0f, GetPosition().z, GetAttackDirection().x, GetAttackDirection().y, GetAttackDirection().z);
	}
}

void Player::Update(double p_deltaTime)
{
}

void Player::SetDamage(float p_damage)
{
	m_damage = p_damage;
}

float Player::GetDamage() const
{
	return m_damage;
}

void Player::SetHealth(unsigned int p_health)
{
	if (p_health < 0)
	{
		m_health = 0;
	}
	else
	{
		m_health = p_health;
	}	
}

unsigned int Player::GetHealth() const
{
	return m_health;
}

void Player::SetAgility(float p_agility)
{
	m_agility = p_agility;
}

float Player::GetAgility() const
{
	return m_agility;
}

void Player::SendPosition(DirectX::XMFLOAT3 p_pos)
{
	Box noReturnBox = Box(DirectX::XMFLOAT3(-100.0f, -100.0f, -100.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
	Box tempBox = CheckCollisionWithObjects();
	if (tempBox.m_center.x != noReturnBox.m_center.x)
	{
		float x = m_playerPrevPos.x;
		float z = m_playerPrevPos.z;
		Box playerBox = Box(m_position, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

		//vector fr�n xPositive till l�dans center.
		float xPosLength = CalculateLengthBetween2Points(DirectX::XMFLOAT3(playerBox.m_center.x + playerBox.m_extents.x, playerBox.m_center.y, playerBox.m_center.z), tempBox.m_center);

		//vector fr�n xNegative till l�dans center.
		float xNegLength = CalculateLengthBetween2Points(DirectX::XMFLOAT3(playerBox.m_center.x - playerBox.m_extents.x, playerBox.m_center.y, playerBox.m_center.z), tempBox.m_center);

		//vector fr�n zPositive till l�dans center.
		float zPosLength = CalculateLengthBetween2Points(DirectX::XMFLOAT3(playerBox.m_center.x, playerBox.m_center.y, playerBox.m_center.z + playerBox.m_extents.z), tempBox.m_center);

		//vector fr�n zNegative till l�dans center.
		float zNegLength = CalculateLengthBetween2Points(DirectX::XMFLOAT3(playerBox.m_center.x, playerBox.m_center.y, playerBox.m_center.z - playerBox.m_extents.z), tempBox.m_center);

		float zTemp = zPosLength - zNegLength;
		if ((int)zTemp == 0)
		{
			z = p_pos.z;
		}
		else
		{
			int i = 0;
		}

		float xTemp = xPosLength - xNegLength;				
		if ((int)xTemp == 0)
		{
			x = p_pos.x;
		}
		else
		{
			int i = 0;
		}
		MovingObject::SetPosition(DirectX::XMFLOAT3(x, m_position.y, z));
	}
	else
	{
		MovingObject::SetPosition(p_pos);
	}

	if (Network::IsConnected())
	{
		DirectX::XMFLOAT3 pos = GetPosition();
		Network::SendPlayerPos(pos.x, pos.y, pos.z);
	}
}

void Player::SetPosition(DirectX::XMFLOAT3 p_pos)
{
	Object::SetPosition(p_pos);
}
DirectX::XMFLOAT3 Player::GetFacingDirection()
{
	return Object::GetRotation();
}
void Player::SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection)
{
	Object::SetRotation(p_facingDirection);
}

DirectX::XMFLOAT3 Player::GetAttackDirection()
{
	return m_attackDir;
}

void Player::SetMyAttackDirection(DirectX::XMFLOAT3 p_attackDir)
{
	m_attackDir = p_attackDir;
	CalculateFacingAngle();

	if (Network::IsConnected())
	{
		DirectX::XMFLOAT3 dir = GetAttackDirection();
		Network::SendPlayerDir(dir.x, dir.y, dir.z);
	}
}

void Player::SetAttackDirection(DirectX::XMFLOAT3 p_attackDir)
{
	m_attackDir = p_attackDir;
	CalculateFacingAngle();
}

RakNet::RakNetGUID Player::GetGuID()
{
	return m_guid;
}

void Player::SetGuID(RakNet::RakNetGUID p_guid)
{
	m_guid = p_guid;
}

void Player::CalculateFacingAngle()
{
	DirectX::XMFLOAT3 v1 = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3 v2 = GetAttackDirection();

	float x = (v1.x * v2.z) - (v2.x * v1.z);
	float y = (v1.x * v2.x) - (v1.z * v2.z);

	float faceAngle = atan2(y, x) - 1.57079632679f;
	SetFacingDirection(DirectX::XMFLOAT3(GetFacingDirection().x, faceAngle, GetFacingDirection().z));
}
void Player::SetCollidingObjects(std::vector<Object> p_ModelList)
{
	m_modelList = p_ModelList;
}
Box Player::CheckCollisionWithObjects()
{
	Box playerBox = Box(m_position, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	if (m_modelList.size() > 0)
	{
		std::vector<Object> modelList = m_modelList;
		for (unsigned int i = 0; i < modelList.size(); i++)
		{
			std::vector<Box> boxList = modelList[i].GetModel()->GetBoundingBoxes();
			if (boxList.size() != 0)
			{
				for (unsigned int j = 0; j < boxList.size(); j++)
				{
					Box box = boxList[j];
					playerBox.m_center.x = m_position.x + m_direction.x * m_speed * (float)GLOBAL::GetInstance().DELTATIME;
					playerBox.m_center.y = m_position.y + m_direction.y * m_speed * (float)GLOBAL::GetInstance().DELTATIME;
					playerBox.m_center.z = m_position.z + m_direction.z * m_speed * (float)GLOBAL::GetInstance().DELTATIME;

					box.m_center.x += modelList[i].GetPosition().x;
					box.m_center.y += modelList[i].GetPosition().y;
					box.m_center.z += modelList[i].GetPosition().z;
		/*			DirectX::XMMATRIX wm = DirectX::XMLoadFloat4x4(&Object::GetWorldMatrix());
					DirectX::XMVECTOR boxVector = DirectX::XMVectorSet(box.m_center.x, box.m_center.y, box.m_center.z, 1.0f);
					DirectX::XMVector4Transform(boxVector, wm);

					
					DirectX::XMStoreFloat3(&box.m_center, boxVector);
*/
					if (Collisions::BoxBoxCollision(playerBox, box))
					{
						return box;
					}
				}
			}
		}
	}
	return Box(DirectX::XMFLOAT3(-100.0f,-100.0f,-100.0f), DirectX::XMFLOAT3(0.0f,0.0f,0.0f));
}

float Player::CalculateLengthBetween2Points(DirectX::XMFLOAT3 p_1, DirectX::XMFLOAT3 p_2)
{
	return std::sqrt((p_2.x - p_1.x)*(p_2.x - p_1.x) + (p_2.z - p_1.z) * (p_2.z - p_1.z));
}