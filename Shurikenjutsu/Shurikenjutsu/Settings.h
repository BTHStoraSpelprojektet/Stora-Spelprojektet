#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>
#include <vector>

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
	bool m_muteSound;
	bool m_ssao;
	bool m_dof;
	bool m_cameraMode;

private:
	void GenerateDefaultSettings();

	static Settings* m_instance;

	Settings();
	~Settings();
};

#endif