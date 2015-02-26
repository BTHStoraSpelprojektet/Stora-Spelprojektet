#include "DebugText.h"

DebugText* DebugText::m_instance;

DebugText::DebugText(){}
DebugText::~DebugText(){}

DebugText* DebugText::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new DebugText();
	}

	return m_instance;
}

bool DebugText::Initialize()
{
	return true;
}

void DebugText::Shutdown()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void DebugText::Update()
{
}

void DebugText::Render()
{
}