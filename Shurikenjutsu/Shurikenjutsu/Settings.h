#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>

class Settings
{
public:
	Settings(const Settings&) = delete;
	Settings& operator=(const Settings&) = delete;

	static Settings* GetInstance();

	void Shutdown();

private:
	static Settings* m_instance;

	Settings();
	~Settings();

	std::string m_name;
	bool m_vsync;
	bool m_fullscreen;
	

};

#endif