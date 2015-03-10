#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>

class Settings
{
public:
	Settings(const Settings&) = delete;
	Settings& operator=(const Settings&) = delete;

	static Settings* GetInstance();
	void LoadSettingsFile();
	void SaveSettingsFile();
	void Shutdown();

	std::string m_name;
	std::string m_ip;
	bool m_vsync;
	bool m_fullscreen;

private:
	void GenerateDefaultSettings();

	static Settings* m_instance;
	Settings();
	~Settings();

	
};

#endif