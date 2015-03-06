#include "Settings.h"

Settings* Settings::m_instance;

Settings::Settings(){}

Settings::~Settings(){}

void Settings::Shutdown()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}