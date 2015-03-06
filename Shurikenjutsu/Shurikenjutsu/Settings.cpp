#include "Settings.h"

Settings* Settings::m_instance;

Settings::Settings(){}

Settings::~Settings(){}

Settings* Settings::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Settings();
	}

	return m_instance;
}

void Settings::Shutdown()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}