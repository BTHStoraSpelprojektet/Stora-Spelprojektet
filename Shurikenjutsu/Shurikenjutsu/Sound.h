#ifndef SOUND_H_
#define SOUND_H_

#include "fmod.hpp"
#include "..\CommonLibs\CommonEnums.h"

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
	float m_musicVolume = 0.3f;

	FMOD::ChannelGroup *masterChannelGroup;

	FMOD::ChannelGroup *channelEffects;
	FMOD::Channel *effectChannel;

	FMOD::ChannelGroup *channelMusic;
	FMOD::Channel *musicChannel;

	FMOD::Sound *m_backgroundSound;
	FMOD::Sound *m_kunaiThrowSound;
	FMOD::Sound *m_kunaiHitSound;
	FMOD::Sound *m_shurikenThrowSound;
	FMOD::Sound *m_shurikenHitSound;
	FMOD::Sound *m_shurikenHitObjectsSound;
	FMOD::Sound *m_megaShurikenHitSound;
	FMOD::Sound *m_megaShurikenHitObjectsSound;
	FMOD::Sound *m_smokeBombSound;
	FMOD::Sound *m_airCutSound;
	FMOD::Sound *m_katanaHitSound;
	FMOD::Sound *m_dashStepsSound;
	FMOD::Channel *m_channel;
};
#endif