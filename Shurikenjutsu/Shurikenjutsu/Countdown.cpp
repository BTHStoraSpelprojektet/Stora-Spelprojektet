#include "Countdown.h"


Countdown::Countdown(){}
Countdown::~Countdown(){}

bool Countdown::Initialize()
{
	m_cdText = GUIText();
	m_cdText.Initialize("5", 100.0f, 0.0f, 0.0f, 0xffffffff);
	return true;
}

void Countdown::Shutdown()
{
	m_cdText.Shutdown();
}

void Countdown::Update()
{
}

void Countdown::Render()
{
	m_cdText.Render();
}