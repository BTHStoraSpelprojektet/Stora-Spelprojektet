#include "DeathBoard.h"
#include "GUIElement.h"
#include "TextureLibrary.h"
#include "Globals.h"
#include "../CommonLibs/ModelNames.h"
#include "../CommonLibs/CommonEnums.h"

DeathBoard* DeathBoard::m_instance;

DeathBoard::DeathBoard(){}
DeathBoard::~DeathBoard(){}

DeathBoard* DeathBoard::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new DeathBoard();
	}

	return m_instance;
}

bool DeathBoard::Initialize()
{
	m_originalPos = DirectX::XMFLOAT3((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - 140, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT* 0.5f - 30, 0);
	for (int i = 0; i < 5; i++)
	{
		m_deathTimer[i] = 0.0;
	}
	m_killer[0] = GUIElement();
	m_deadGuy[0] = GUIElement();
	m_killAbility[0] = GUIElement();

	DirectX::XMFLOAT3 position = m_originalPos;

	for (int i = 0; i < 5; i++)
	{
		m_killer[i].Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA1));
		position.x += 55;

		m_killAbility[i].Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILLARROW));
		position.x += 55;

		m_deadGuy[i].Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA1));
	}
	m_nrOfDeaths = -1;

	return true;
}

void DeathBoard::Shutdown()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}

}

void DeathBoard::Update()
{
	if (m_nrOfDeaths != -1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (m_deathTimer[i] > 0.0)
			{
				m_deathTimer[i] -= GLOBAL::GetInstance().GetDeltaTime();
				if (m_deathTimer[i] <= 0.0)
				{
					ChangeOrder(i);
					m_nrOfDeaths -= 1;
				}
			}
		}
	}
}

void DeathBoard::Render()
{	
	for (int i = 0; i < 5; i++)
	{
		if (m_deathTimer[i] > 0)
		{
			m_killer[i].QueueRender();
			m_killAbility[i].QueueRender();
			m_deadGuy[i].QueueRender();
		}
	}
}

void DeathBoard::DeathEverywhere()
{
	if ( m_nrOfDeaths < 4 )
	{
		m_nrOfDeaths += 1;
	}
	
	m_deathTimer[m_nrOfDeaths] = 5.0;
}

void DeathBoard::KillHappened(int p_ninjaKilling, int p_ninjaKilled, ABILITIES p_abilityUsed)
{
	DeathEverywhere();
	
	DirectX::XMFLOAT3 position = m_originalPos;
	position.y -= (55 * m_nrOfDeaths);

	m_killer[m_nrOfDeaths].SetPosition(position);
	position.x += 55;
	m_killAbility[m_nrOfDeaths].SetPosition(position);
	position.x += 55;
	m_deadGuy[m_nrOfDeaths].SetPosition(position);
	

	switch (p_ninjaKilling)
	{
	case 0:
		m_killer[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA1));
		break;
	case 1:
		m_killer[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA2));
		break;
	case 2:
		m_killer[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA3));
		break;
	default:
		break;
	}

	switch (p_ninjaKilled)
	{
	case 0:
		m_deadGuy[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA1));
		break;
	case 1:
		m_deadGuy[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA2));
		break;
	case 2:
		m_deadGuy[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA3));
		break;
	default:
		break;
	}

	switch (p_abilityUsed)
	{
	case ABILITIES_SHURIKEN:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N1RANGED));
		break;
	case ABILITIES_DASH:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N1Q));
		break;
	case ABILITIES_MELEESWING:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N1MELEE));
		break;
	case ABILITIES_MEGASHURIKEN:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N1E));
		break;
	case ABILITIES_SMOKEBOMB:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILLARROW));
		break;
	case ABILITIES_SPIKETRAP:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_CALPTROPS));
		break;
	case ABILITIES_WHIP_PRIMARY:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N2RANGED));
		break;
	case ABILITIES_WHIP_SECONDARY:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N2E));
		break;
	case ABILITIES_FANBOOMERANG:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N2Q));
		break;
	case ABILITIES_NAGINATASLASH:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N3MELEE));
		break;
	case ABILITIES_KUNAI:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N3RANGED));
		break;
	case ABILITIES_STICKY_TRAP:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_KILLARROW));
		break;
	case ABILITIES_NAGAINATASTAB:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N3Q));
		break;
	case ABILITIES_VOLLEY:
		m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N3E));
		break;
	default:
		break;
	}

}

void DeathBoard::ChangeOrder(int p_index)
{
	if (p_index >= 4)
	{
		return;
	}

	for (int i = p_index; i < 4; i++)
	{
		m_killer[i].SetTexture(m_killer[i + 1].GetTexture());
		m_killAbility[i].SetTexture(m_killAbility[i + 1].GetTexture());
		m_deadGuy[i].SetTexture(m_deadGuy[i + 1].GetTexture());

		m_deathTimer[i] = m_deathTimer[i + 1];
	}
}