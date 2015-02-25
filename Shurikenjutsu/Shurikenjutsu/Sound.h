#ifndef SOUND_H_
#define SOUND_H_

#include "fmod.hpp"
#include "..\CommonLibs\CommonEnums.h"
#include <vector>

class Sound
{
public:
	Sound();
	~Sound();

	struct SoundEmitter{
		float m_x, m_y, m_z;
		PLAYSOUND m_playSound;
		FMOD::Channel* m_ambientChannel;
		float m_totalMSLength;
		float m_timePassed;
		bool isPlaying = true;
	};

	bool Initialize();
	void Shutdown();
	void Update();

	void FMODErrorCheck(FMOD_RESULT p_result);
	void PlaySound(PLAYSOUND p_playSound, float p_volume = 1.0f);
	SoundEmitter* CreateAmbientSound(PLAYSOUND p_playSound, float p_x, float p_y, float p_z);
	void UpdateAmbientSound(float p_player_x, float p_player_y, float p_player_z);
	void StopAmbientSound(SoundEmitter* p_soundEmitter);
	void StartAmbientSound(SoundEmitter* p_soundEmitter);

	void StopMusic();
	void StartMusic();
	void StartStopMusic();
private:
	FMOD::System *m_system;
	FMOD_RESULT m_result;
	unsigned int m_version;
	int m_numDrivers;
	FMOD_SPEAKERMODE m_speakerMode;
	//FMOD_Caps caps;
	char m_name[256];
	float m_musicVolume = 0.7f;
	float m_defaultAmbientVolume = 0.4f;
	int music_sound_id = 0;

	void PlayAmbientSound(SoundEmitter* p_soundEmitter, float p_initialVolume = 0.0f);
	void setAmbientVolume(SoundEmitter* p_soundEmitter, float p_volume);

	FMOD::ChannelGroup *masterChannelGroup;

	FMOD::ChannelGroup *channelEffects;
	FMOD::Channel *effectChannel;

	FMOD::ChannelGroup *channelAmbient;
	
	//std::vector<FMOD::Channel*> ambientChannels;
	std::vector<SoundEmitter*> soundEmitters;

	FMOD::ChannelGroup *channelMusic;
	FMOD::Channel *musicChannel;

	FMOD::Sound *m_backgroundSound;
	FMOD::Sound *m_kunaiThrowSound;
	FMOD::Sound *m_kunaiHitSound;
	FMOD::Sound *m_kunaiHitOBjectsSound;
	FMOD::Sound *m_shurikenThrowSound;
	FMOD::Sound *m_shurikenHitSound;
	FMOD::Sound *m_shurikenHitObjectsSound;
	FMOD::Sound *m_megaShurikenHitSound;
	FMOD::Sound *m_megaShurikenHitObjectsSound;
	FMOD::Sound *m_smokeBombSound;
	FMOD::Sound *m_airCutSound;
	FMOD::Sound *m_katanaHitSound;
	FMOD::Sound *m_dashStepsSound;
	FMOD::Sound *m_whipAirSound;
	FMOD::Sound *m_whipRotateSound;
	FMOD::Sound *m_whipHitSound;
	FMOD::Sound *m_naginataAirSound;
	FMOD::Sound *m_naginataAirStabSound;
	FMOD::Sound *m_naginataHitSound;
	FMOD::Sound *m_volleyThrowSound;
	FMOD::Sound *m_volleyHitSound;
	FMOD::Sound *m_bubleSound;
	FMOD::Sound *m_fireSound;
	FMOD::Sound *m_windSound;
	FMOD::Sound *m_birdSound;
	FMOD::Sound *m_stepsLeavesSound;

	//FMOD::Channel *m_channel;
};
#endif