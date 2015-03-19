#include "Settings.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <ctime>

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

		std::getline(myfile, line);
		m_muteSound = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_ssao = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_dof = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_cameraMode = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_apeToggle = atoi(line.c_str()) ? 1 : 0;

		std::getline(myfile, line);
		m_apeEnabled = atoi(line.c_str()) ? 1 : 0;

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
		myfile << m_muteSound << std::endl;
		myfile << m_ssao << std::endl;
		myfile << m_dof << std::endl;
		myfile << m_cameraMode << std::endl;
		myfile << m_apeToggle << std::endl;
		myfile << m_apeEnabled << std::endl;
		myfile.close();
	}
}

void Settings::GenerateDefaultSettings()
{
	std::vector<std::string> names;
	names.push_back("Akira");
	names.push_back("Kei");
	names.push_back("Mikoto");
	names.push_back("Jun");
	names.push_back("Ryou");
	names.push_back("Sora");
	names.push_back("Yuki");
	names.push_back("Mitsuki");
	names.push_back("Minato");
	names.push_back("Hachi");
	names.push_back("Tamahi");
	names.push_back("Sakae");
	names.push_back("Hiromu");
	names.push_back("Hikari");
	names.push_back("Itsuki");

	srand((unsigned int)time(NULL));
	int random = rand() % names.size();
	
	m_name = names[random];
	m_ip = "194.47.150.130";
	m_fullscreen = false;
	m_vsync = false;
	m_muteSound = false;
	m_ssao = true;
	m_dof = true;
	m_cameraMode = false;
	m_apeToggle = true;
	m_apeEnabled = false;
}