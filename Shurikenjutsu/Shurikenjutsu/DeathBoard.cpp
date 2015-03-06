#include "DeathBoard.h"
#include "GUIElement.h"
#include "..\CommonLibs\TextureLibrary.h"
#include "Globals.h"
#include "../CommonLibs/ModelNames.h"
#include "../CommonLibs/CommonEnums.h"
#include "Network.h"

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
	m_originalPos = DirectX::XMFLOAT3((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - 40, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT* 0.5f - 30, 0);
	m_redColor = 0xff0700B6;
	m_blueColor = 0xffB71300;
	for (int i = 0; i < 5; i++)
	{
		m_deathTimer[i] = 0.0;
	}

	DirectX::XMFLOAT3 position = m_originalPos;

	for (int i = 0; i < 5; i++)
	{
		// Background
		m_background[i] = GUIElement();
		m_background[i].Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_BACKGROUND));

		// Dead guy
		m_deadGuy[i] = GUIText();
		m_deadGuy[i].Initialize("Name", 35.0f, position.x, position.y, 0xFFFFFFFF);
		m_deadGuy[i].SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		position.x -= (m_deadGuy[i].GetWidth() + 22.5f);

		// Ability
		m_killAbility[i] = GUIElement();
		m_killAbility[i].Initialize(position, 50.0f, 50.0f, TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_NINJA1));
		position.x -= 22.5f;

		// Killer
		m_killer[i] = GUIText();
		m_killer[i].Initialize("Name", 35.0f, position.x, position.y, 0xFFFFFFFF);
		m_killer[i].SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);


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
	m_originalPos = DirectX::XMFLOAT3((float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH * 0.5f - 40, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT* 0.5f - 30, 0);

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
			m_background[i].QueueRender();
			m_killer[i].Render();
			m_killAbility[i].QueueRender();
			m_deadGuy[i].Render();
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

void DeathBoard::KillHappened(RakNet::RakNetGUID p_ninjaKilling, RakNet::RakNetGUID p_ninjaKilled, ABILITIES p_abilityUsed)
{
	DeathEverywhere();
	
	int team;
	DirectX::XMFLOAT3 position = m_originalPos;
	position.y -= (55 * m_nrOfDeaths);

	// Dead guy
	m_deadGuy[m_nrOfDeaths].SetPosition(position.x, position.y);
	m_deadGuy[m_nrOfDeaths].SetText(Network::GetInstance()->GetPlayerName(p_ninjaKilled));
	team = Network::GetInstance()->GetTeam(p_ninjaKilled);
	if (team == 1)
	{
		m_deadGuy[m_nrOfDeaths].SetColor(m_redColor);
	}
	else if (team == 2)
	{
		m_deadGuy[m_nrOfDeaths].SetColor(m_blueColor);
	}
	position.x -= (m_deadGuy[m_nrOfDeaths].GetWidth() + 22.5f);

	// Ability
	m_killAbility[m_nrOfDeaths].SetPosition(position);
	position.x -= 30.0f;

	// Killer
	m_killer[m_nrOfDeaths].SetPosition(position.x, position.y);
	m_killer[m_nrOfDeaths].SetText(Network::GetInstance()->GetPlayerName(p_ninjaKilling));
	team = Network::GetInstance()->GetTeam(p_ninjaKilling);
	if (team == 1)
	{
		m_killer[m_nrOfDeaths].SetColor(m_redColor);
	}
	else if (team == 2)
	{
		m_killer[m_nrOfDeaths].SetColor(m_blueColor);
	}

	// Background
	DirectX::XMFLOAT2 size = DirectX::XMFLOAT2(m_deadGuy[m_nrOfDeaths].GetWidth() + 70.0f + m_killer[m_nrOfDeaths].GetWidth(), m_background[m_nrOfDeaths].GetSize().y);
	DirectX::XMFLOAT3 pos = position;
	pos.x = m_originalPos.x - size.x * 0.5f + 10.0f;
	m_background[m_nrOfDeaths].SetPosition(pos);
	m_background[m_nrOfDeaths].SetSize(size);

	int charNr;
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
		charNr = Network::GetInstance()->GetCharNr(p_ninjaKilling);
		if (charNr == 0)
		{
			m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N1MELEE));
		}
		else if (charNr == 1)
		{
			m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N2MELEE));
		}
		else if (charNr == 2)
		{
			m_killAbility[m_nrOfDeaths].SetTexture(TextureLibrary::GetInstance()->GetTexture(DEATHBOARD_N3MELEE));
		}
		
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
		// Background
		DirectX::XMFLOAT3 backgroundPos = m_background[i + 1].GetPosition();
		backgroundPos.y = m_background[i].GetPosition().y;
		m_background[i].SetPosition(backgroundPos);

		// Killer
		m_killer[i].SetText(m_killer[i + 1].GetText());
		m_killer[i].SetPosition(m_killer[i + 1].GetOriginPosX(), m_killer[i].GetOriginPosY());

		// Ability
		DirectX::XMFLOAT3 abilityPos = m_killAbility[i + 1].GetPosition();
		abilityPos.y = m_killAbility[i].GetPosition().y;
		m_killAbility[i].SetPosition(abilityPos);
		m_killAbility[i].SetTexture(m_killAbility[i + 1].GetTexture());

		// Dead guy
		m_deadGuy[i].SetText(m_deadGuy[i + 1].GetText());
		m_deadGuy[i].SetPosition(m_deadGuy[i + 1].GetOriginPosX(), m_deadGuy[i].GetOriginPosY());

		// Timer
		m_deathTimer[i] = m_deathTimer[i + 1];
	}
}