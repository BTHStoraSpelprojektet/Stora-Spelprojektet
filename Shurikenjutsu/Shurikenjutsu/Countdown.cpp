#include "Countdown.h"
#include "Network.h"

Countdown::Countdown(){}
Countdown::~Countdown(){}

bool Countdown::Initialize()
{
	m_cdText = GUIText();
	m_cdText.Initialize("5", 100.0f, 0.0f, 0.0f, 0xffffffff);

	m_render = false;
	return true;
}

void Countdown::Shutdown()
{
	m_cdText.Shutdown();
}

void Countdown::Update()
{
	if (Network::GetInstance()->RoundRestarting() && Network::GetInstance()->GetRestartingTimer() <= 5)
	{
		m_render = true;
		m_cdText.SetText(std::to_string(Network::GetInstance()->GetRestartingTimer()));
	}
	else
	{
		m_render = false;
	}
}

void Countdown::Render()
{
	if (m_render)
	{
		m_cdText.Render();
	}
}