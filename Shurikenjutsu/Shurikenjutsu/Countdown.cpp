#include "Countdown.h"
#include "Network.h"
#include "Globals.h"

Countdown::Countdown(){}
Countdown::~Countdown(){}

bool Countdown::Initialize()
{
	m_cdText = GUIText();
	m_cdText.Initialize("", 200.0f, 0.0f, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT * 0.25f, 0xff0000ff);

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