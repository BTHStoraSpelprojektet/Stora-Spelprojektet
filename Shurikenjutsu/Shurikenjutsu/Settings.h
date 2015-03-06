#ifndef SETTINGS_H_
#define SETTINGS_H_

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
};

#endif