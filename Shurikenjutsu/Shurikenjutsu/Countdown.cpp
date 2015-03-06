#include "Countdown.h"
#include "Network.h"
#include "Globals.h"
#include "..\CommonLibs\TextureLibrary.h"

Countdown::Countdown(){}
Countdown::~Countdown(){}

bool Countdown::Initialize()
{
	m_minSize = 50.0f;
	m_maxSize = 250.0f;
	m_prevTime = 0;
	m_currentSize = m_minSize;
	m_redColor = 0xff0700B6;
	m_blueColor = 0xffB71300;

	m_cdText = GUIText();
	m_cdText.Initialize("", 50.0f, 0.0f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.25f, m_redColor);

	m_roundTeamText = GUIText();
	m_roundTeamText.Initialize("", 50.0f, 0.0f, -(GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.25f), 0xffffffff);

	m_victDefTexture = GUIElement();
	m_victDefTexture.Initialize(DirectX::XMFLOAT3(0.0f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.25f, 0.0f), 340.0f, 125.0f, TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/victory.png"));

	m_renderCd = true;
	m_renderRoundTeam = false;
	return true;
}

void Countdown::Shutdown()
{
	m_cdText.Shutdown();
	m_roundTeamText.Shutdown();
}

void Countdown::Update()
{
	// Check if a round is restarting for text
	if (Network::GetInstance()->RoundRestarting())
	{
		int lastTeamWon = Network::GetInstance()->GetLastWinningTeam();
		// Red victory
		if (lastTeamWon == 1 && m_roundTeamText.GetColor() != m_redColor)
		{
			m_roundTeamText.SetText("Red team won this round!");
			m_roundTeamText.SetColor(m_redColor);
		}
		// Blue victory
		else if (lastTeamWon == 2 && m_roundTeamText.GetColor() != m_blueColor)
		{
			m_roundTeamText.SetText("Blue team won this round!");
			m_roundTeamText.SetColor(m_blueColor);
		}
		m_renderRoundTeam = true;
	}
	else
	{
		m_renderRoundTeam = false;
	}
	// Check so a round is restarting for timer
	if (Network::GetInstance()->RoundRestarting() && Network::GetInstance()->GetRestartingTimer() <= 5)
	{
		m_renderCd = true;
		int time = Network::GetInstance()->GetRestartingTimer();
		// if statement check if a new number is to be displayed (1 sec have passed)
		if (time != m_prevTime)
		{
			// Check who won and set color depending on team
			int lastTeamWon = Network::GetInstance()->GetLastWinningTeam();
			if (lastTeamWon == 1 && m_cdText.GetColor() != m_redColor)
			{
				m_cdText.SetColor(m_redColor);
			}
			else if (lastTeamWon == 2 && m_cdText.GetColor() != m_blueColor)
			{
				m_cdText.SetColor(m_blueColor);
			}
			m_currentSize = m_minSize;
			m_cdText.SetSize(m_currentSize);
			m_cdText.SetText(std::to_string(time));
		}
		else
		{
			// Increase the size up to maxSize
			m_currentSize += 600.0f * (float)GLOBAL::GetInstance().GetDeltaTime();
			if (m_currentSize > m_maxSize)
			{
				m_currentSize = m_maxSize;
			}
			m_cdText.SetSize(m_currentSize);
		}
		// Just so it dont render the first frame
		if (m_prevTime == -1)
		{
			m_renderCd = false;
		}
		m_prevTime = time;
	}
	// Check if a match is over
	else if (Network::GetInstance()->GetMatchOver())
	{
		m_renderCd = false;
		if (Network::GetInstance()->GetMatchWinningTeam() == Network::GetInstance()->GetMyPlayer().team)
		{
			// Victory
			m_victDefTexture.SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/victory.png"));
		}
		else
		{
			// Defeat
			m_victDefTexture.SetTexture(TextureLibrary::GetInstance()->GetTexture("../Shurikenjutsu/2DTextures/defeat.png"));
		}
	}
	else
	{
		m_renderCd = false;
		m_prevTime = -1;
	}
}

void Countdown::Render()
{
	if (m_renderCd)
	{
		m_cdText.Render();
	}

	if (m_renderRoundTeam)
	{
		m_roundTeamText.Render();
	}

	if (Network::GetInstance()->GetMatchOver())
	{
		m_victDefTexture.QueueRender();
	}
}