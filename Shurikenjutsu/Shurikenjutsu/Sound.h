#ifndef SOUND_H_
#define SOUND_H_

#include "fmod.hpp"

enum PLAYSOUND
{
	PLAYSOUND_BACKGROUND_SOUND
};

class Sound
{
public:
	Sound();
	~Sound();

	bool Initialize();
	void Shutdown();
	void Update();

	void FMODErrorCheck(FMOD_RESULT p_result);
	void PlaySound(PLAYSOUND p_playSound);

private:
	FMOD::System *m_system;
	FMOD_RESULT m_result;
	unsigned int m_version;
	int m_numDrivers;
	FMOD_SPEAKERMODE m_speakerMode;
	//FMOD_Caps caps;
	char m_name[256];


	FMOD::Sound *m_backgroundSound;
	FMOD::Channel *m_channel;
};
#endif