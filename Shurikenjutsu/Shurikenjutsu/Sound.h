#ifndef SOUND_H_
#define SOUND_H_

#include "FMOD\inc\fmod.hpp"
#include "..\CommonLibs\CommonEnums.h"
#include <vector>

class Sound
{
public:
	Sound();
	~Sound();

	struct SoundEmitter{
		//float m_x, m_y, m_z;
		PLAYSOUND m_playSound;
		FMOD::Channel* m_channel;
		FMOD_VECTOR m_pos;
		float m_totalMSLength;
		float m_timePassed;
		bool isPlaying = true;
	};

	bool Initialize();
	void Shutdown();
	void Update();
	void UpdateListenerPos(FMOD_VECTOR listener_pos, FMOD_VECTOR listener_forward, FMOD_VECTOR listener_up);

	void FMODErrorCheck(FMOD_RESULT p_result);
	//void PlaySound(PLAYSOUND p_playSound, float p_volume = 1.0f);
	SoundEmitter* CreateAmbientSound(PLAYSOUND p_playSound, float p_x, float p_y, float p_z);
	void UpdateAmbientSound(float p_player_x, float p_player_y, float p_player_z);
	void StopAmbientSound(SoundEmitter* p_soundEmitter);
	void StartAmbientSound(SoundEmitter* p_soundEmitter);
	Sound::SoundEmitter* CreateDefaultSound(PLAYSOUND p_playSound, float p_x, float p_y, float p_z);
	void ClearAmbientSounds();

	void StopMusic();
	void StartStopMusic();
	void StartMusic();

	void MuteEverything();
	void UnMuteEverything();
private:
	FMOD::System *m_system;
	FMOD_RESULT m_result;
	unsigned int m_version;
	int m_numDrivers;
	FMOD_SPEAKERMODE m_speakerMode;
	//FMOD_Caps caps;
	char m_name[256];
	float m_musicVolume;
	float m_defaultWindVolume;
	int music_sound_id = 0;

	void PlayAmbientSound(SoundEmitter* p_soundEmitter, float p_initialVolume = 0.0f);
	void setAmbientVolume(SoundEmitter* p_soundEmitter, float p_volume);
	void PlayDefaultSound(SoundEmitter* p_soundEmitter);
	void PlayBackgroundSound(PLAYSOUND p_playSound);
	void GarbageCollectOldSounds();

	FMOD::ChannelGroup *masterChannelGroup;

	FMOD::ChannelGroup *channelEffects;
	FMOD::Channel *effectChannel;

	FMOD::ChannelGroup *channelAmbient;
	
	//std::vector<FMOD::Channel*> ambientChannels;
	std::vector<SoundEmitter*> defaultSoundEmitters;
	std::vector<SoundEmitter*> ambientSoundEmitters;

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
	FMOD::Sound *m_maleDeathSound;
	FMOD::Sound *m_femaleDeathSound;
	FMOD::Sound *m_maleHurtSound;
	FMOD::Sound *m_femaleHurtSound;
	FMOD::Sound *m_countdownBeep;
	FMOD::Sound *m_countdownGong;
	FMOD::Sound *m_runeInvisibility;
	FMOD::Sound *m_runeInvisibilitySpawn;
	FMOD::Sound *m_runeInvisibilityPickup;
	FMOD::Sound *m_runeHeal;
	FMOD::Sound *m_runeHealSpawn;
	FMOD::Sound *m_runeHealPickup;
	FMOD::Sound *m_runeShield;
	FMOD::Sound *m_runeShieldSpawn;
	FMOD::Sound *m_runeShieldPickup;

	//FMOD::Channel *m_channel;
};
#endif