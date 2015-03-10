#include "Settings.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

// Constants
const std::string path = "../Shurikenjutsu/Settings/Settings.cfg";
const LPCSTR dirPath = "../Shurikenjutsu/Settings";

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

// Load settings
void Settings::LoadSettingsFile()
{
	std::ifstream myfile;
	std::string line;
	myfile.open(path, std::ios::in);

	if (myfile.is_open())
	{
		std::getline(myfile, line);
		m_name = line;

		std::getline(myfile, line);
		m_ip = line;

		std::getline(myfile, line);
		m_fullscreen = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_vsync = atoi(line.c_str()) ? 1 : 0;

		myfile.close();
	}
	else
	{
		GenerateDefaultSettings();
		CreateDirectory(dirPath, NULL);
	}
}

// Save settings
void Settings::SaveSettingsFile()
{
	std::ofstream myfile;
	myfile.open(path, std::ios::out | std::ios::trunc);
	if (myfile.is_open())
	{
		myfile << m_name << std::endl;
		myfile << m_ip << std::endl;
		myfile << m_fullscreen << std::endl;
		myfile << m_vsync << std::endl;
		myfile.close();
	}
}

void Settings::GenerateDefaultSettings()
{
	m_name = "UnknownNinja";
	m_ip = "194.47.150.130";
	m_fullscreen = false;
	m_vsync = false;
}