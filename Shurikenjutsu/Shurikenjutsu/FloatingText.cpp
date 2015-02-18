#include "FloatingText.h"
#include "Globals.h"


void FloatingText::Initialize()
{
	m_receivedDamage = new GUIText();
	m_receivedDamage->Initialize("00000000", 20.0f, 20.0f, 0.0f, 0xff0000ff);
	m_timer = 0;
}
void FloatingText::Update()
{
	m_timer -= GLOBAL::GetInstance().GetDeltaTime();
	
	UINT32 temp = m_receivedDamage->GetColor();

	//Sänka de två första sifrerna med 51 





}
void FloatingText::Shutdown()
{
	if (m_receivedDamage != nullptr)
	{
		m_receivedDamage->Shutdown();
		delete m_receivedDamage;
		m_receivedDamage = nullptr;
	}
}
void FloatingText::Render()
{
	m_receivedDamage->Render();
}
void FloatingText::ResetTimer()
{
	m_timer = 5.0f;
}