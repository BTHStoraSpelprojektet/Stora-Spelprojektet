#include "Countdown.h"
#include "Network.h"
#include "Globals.h"

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

	m_render = true;
	return true;
}

void Countdown::Shutdown()
{
	m_cdText.Shutdown();
}

void Countdown::Update()
{
	// Check so a round is restarting
	if (Network::GetInstance()->RoundRestarting() && Network::GetInstance()->GetRestartingTimer() <= 5)
	{
		m_render = true;
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
			m_render = false;
		}
		m_prevTime = time;
	}
	else
	{
		m_render = false;
		m_prevTime = -1;
	}
}

void Countdown::Render()
{
	if (m_render)
	{
		m_cdText.Render();
	}
}