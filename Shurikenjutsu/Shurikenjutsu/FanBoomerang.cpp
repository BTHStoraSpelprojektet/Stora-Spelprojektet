#include "FanBoomerang.h"
#include "Globals.h"
#include "..\CommonLibs\GameplayGlobalVariables.h"
#include "Network.h"

FanBoomerang::FanBoomerang(){}
FanBoomerang::~FanBoomerang(){}

bool FanBoomerang::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id, RakNet::RakNetGUID p_owner)
{
	MovingObject::Initialize(p_filepath, p_pos, p_dir, p_speed);
	m_id = p_id;
	m_owner = p_owner;

	return true;
}

void FanBoomerang::Update(bool p_dead)
{
	m_rotation.y += SHURIKEN_ROTATION_SPEED * (float)GLOBAL::GetInstance().GetDeltaTime();

	if (p_dead)
	{
		PlayerNet player;
		player.charNr = -1;
		if (m_owner == Network::GetInstance()->GetMyGUID())
		{
			player = Network::GetInstance()->GetMyPlayer();
		}
		else
		{
			std::vector<PlayerNet> others = Network::GetInstance()->GetOtherPlayers();
			for (unsigned int i = 0; i < others.size(); i++)
			{
				if (others[i].guid == m_owner)
				{
					player = others[i];
					break;
				}
			}
		}

		if (player.charNr != -1)
		{
			// Calculate new direction
			float dirX = m_position.x - player.x;
			float dirZ = m_position.z - player.z;
			float length = sqrt(dirX*dirX + dirZ*dirZ);

			dirX /= length;
			dirZ /= length;

			m_direction.x = dirX;
			m_direction.z = dirZ;
			
			m_position.x += m_direction.x * m_speed * -(float)GLOBAL::GetInstance().GetDeltaTime();
			m_position.y += m_direction.y * m_speed * -(float)GLOBAL::GetInstance().GetDeltaTime();
			m_position.z += m_direction.z * m_speed * -(float)GLOBAL::GetInstance().GetDeltaTime();
		}
		
	}
	else
	{
		m_position.x += m_direction.x * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
		m_position.y += m_direction.y * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
		m_position.z += m_direction.z * m_speed * (float)GLOBAL::GetInstance().GetDeltaTime();
	}
}

unsigned int FanBoomerang::GetID()
{
	return m_id;
}
