#ifndef SOUND_H_
#define SOUND_H_

#include "fmod.hpp"

enum PLAYSOUND
{
	PLAYSOUND_BACKGROUND_SOUND,
	PLAYSOUND_KUNAI_THROW_SOUND,
	PLAYSOUND_KUNAI_HIT_SOUND,
	PLAYSOUND_AIR_CUT_SOUND,
	PLAYSOUND_KATANA_HIT_SOUND,
	PLAYSOUND_DASH_STEPS_SOUND,
	PLAYSOUND_SHURIKEN_THROW_SOUND,
	PLAYSOUND_SHURIKEN_HIT_SOUND,
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
	void PlaySound(PLAYSOUND p_playSound, float volume = 1.0f);

private:
	FMOD::System *m_system;
	FMOD_RESULT m_result;
	unsigned int m_version;
	int m_numDrivers;
	FMOD_SPEAKERMODE m_speakerMode;
	//FMOD_Caps caps;
	char m_name[256];


	FMOD::Sound *m_backgroundSound;
	FMOD::Sound *m_kunaiThrowSound;
	FMOD::Sound *m_kunaiHitSound;
	FMOD::Sound *m_shurikenThrowSound;
	FMOD::Sound *m_shurikenHitSound;
	FMOD::Sound *m_airCutSound;
	FMOD::Sound *m_katanaHitSound;
	FMOD::Sound *m_dashStepsSound;
	FMOD::Channel *m_channel;
};
#endif