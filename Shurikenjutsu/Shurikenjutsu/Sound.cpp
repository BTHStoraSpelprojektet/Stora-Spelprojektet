#include "Sound.h"
#include <iostream>
#include "fmod_errors.h"

#include "../CommonLibs/CommonStructures.h"
Sound::Sound(){}
Sound::~Sound(){}

bool Sound::Initialize()
{
	// Create the interface
	m_result = FMOD::System_Create(&m_system);
	FMODErrorCheck(m_result);

	m_result = m_system->init(512, FMOD_INIT_NORMAL, 0);
	FMODErrorCheck(m_result);

	FMODErrorCheck(m_system->createChannelGroup(NULL, &masterChannelGroup));
	FMODErrorCheck(m_system->createChannelGroup(NULL, &channelEffects));
	FMODErrorCheck(m_system->createChannelGroup(NULL, &channelAmbient));
	FMODErrorCheck(m_system->createChannelGroup(NULL, &channelMusic));

	int FMOD_MODE = FMOD_3D_LINEARROLLOFF;
	//int FMOD_MODE = FMOD_DEFAULT;

	m_result = m_system->createStream("../Shurikenjutsu/Sound/BG_music2.wav", FMOD_DEFAULT, 0, &m_backgroundSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KunaiHit.wav", FMOD_MODE, 0, &m_kunaiHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KunaiHitObjects.wav", FMOD_MODE, 0, &m_kunaiHitOBjectsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KunaiThrow.wav", FMOD_MODE, 0, &m_kunaiThrowSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/AirCut.wav", FMOD_MODE, 0, &m_airCutSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/DashGrassSteps.wav", FMOD_MODE, 0, &m_dashStepsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenThrow.wav", FMOD_MODE, 0, &m_shurikenThrowSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenHit.wav", FMOD_MODE, 0, &m_shurikenHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenHitObjects.wav", FMOD_MODE, 0, &m_shurikenHitObjectsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KatanaHit.wav", FMOD_MODE, 0, &m_katanaHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/MegaShurikenHit.wav", FMOD_MODE, 0, &m_megaShurikenHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/MegaShurikenHitObjects.wav", FMOD_MODE, 0, &m_megaShurikenHitObjectsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/SmokeBomb.wav", FMOD_MODE, 0, &m_smokeBombSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/Whip.wav", FMOD_MODE, 0, &m_whipAirSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/WhipHit.wav", FMOD_MODE, 0, &m_whipHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/WhipRotate.wav", FMOD_MODE, 0, &m_whipRotateSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/Naginata.wav", FMOD_MODE, 0, &m_naginataAirSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/NaginataHit.wav", FMOD_MODE, 0, &m_naginataHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/NaginataSlash.wav", FMOD_MODE, 0, &m_naginataAirStabSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/VolleyHit.wav", FMOD_MODE, 0, &m_volleyHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/VolleyThrow.wav", FMOD_MODE, 0, &m_volleyThrowSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/Bubble.wav", FMOD_MODE, 0, &m_bubleSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/Fire.wav", FMOD_MODE, 0, &m_fireSound);
	FMODErrorCheck(m_result);

	//Background ambient sound set to FMOD_2D to sound everywhere
	m_result = m_system->createSound("../Shurikenjutsu/Sound/Wind.wav", FMOD_2D, 0, &m_windSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/Bird.wav", FMOD_MODE, 0, &m_birdSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/StepsOnLeaves.wav", FMOD_MODE, 0, &m_stepsLeavesSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/DeathMale.wav", FMOD_MODE, 0, &m_maleDeathSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/DeathFemale.wav", FMOD_MODE, 0, &m_femaleDeathSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/MaleHurt.wav", FMOD_MODE, 0, &m_maleHurtSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/FemaleHurt.wav", FMOD_MODE, 0, &m_femaleHurtSound);
	FMODErrorCheck(m_result);
	
	m_result = m_system->createSound("../Shurikenjutsu/Sound/CountdownBeep.wav", FMOD_2D, 0, &m_countdownBeep);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneInvisibility.wav", FMOD_MODE, 0, &m_runeInvisibility);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneInvisibilitySpawn.wav", FMOD_MODE, 0, &m_runeInvisibilitySpawn);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneInvisibilityPickup.wav", FMOD_MODE, 0, &m_runeInvisibilityPickup);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneHeal.wav", FMOD_MODE, 0, &m_runeHeal);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneHealSpawn.wav", FMOD_MODE, 0, &m_runeHealSpawn);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneHealPickup.wav", FMOD_MODE, 0, &m_runeHealPickup);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneShield.wav", FMOD_MODE, 0, &m_runeShield);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneShieldSpawn.wav", FMOD_MODE, 0, &m_runeShieldSpawn);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/RuneShieldPickup.wav", FMOD_MODE, 0, &m_runeShieldPickup);
	FMODErrorCheck(m_result);

	// EXTRA KOD FÖR EXTRA KOLLAR

	// Check version
	/*m_result = m_system->getVersion(&m_version);
	FMODErrorCheck(m_result);

	if (m_version < FMOD_VERSION)
	{
		std::cout << "Error! You are using an old version of FMOD " << m_version << ". This program requires " << FMOD_VERSION << std::endl;    
		return false;
	}

	// Get nmber of sound cars 
	m_result = m_system->getNumDrivers(&m_numDrivers);
	FMODErrorCheck(m_result);

	// NO Soundcards (diasble sound)
	if (m_numDrivers == 0)
	{
		m_result = m_system->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
		FMODErrorCheck(m_result);
	}
	// At least one sound card
	else
	{
		// Get the capabilites of the default (0) sound card
		m_result = m_system->getDriverInfo(0, m_name, 256, 0, 0, &m_speakerMode, 0);
	}*/

	return true;
}

void Sound::Shutdown()
{
	for (unsigned int i = 0; i < ambientSoundEmitters.size(); i++)
	{
		ambientSoundEmitters[i]->isPlaying = false;
		ambientSoundEmitters[i]->m_channel->stop();
		delete ambientSoundEmitters[i];
	}
	ambientSoundEmitters.clear();

	for (unsigned int i = 0; i < defaultSoundEmitters.size(); i++)
	{
		defaultSoundEmitters[i]->isPlaying = false;
		defaultSoundEmitters[i]->m_channel->stop();
		delete defaultSoundEmitters[i];
	}
	defaultSoundEmitters.clear();

	m_system->release();
}

void Sound::Update(){
	GarbageCollectOldSounds();
	m_system->update();
}

void Sound::UpdateListenerPos(FMOD_VECTOR listener_pos, FMOD_VECTOR listener_forward, FMOD_VECTOR listener_up)
{
	m_system->set3DListenerAttributes(0, &listener_pos, NULL, &listener_forward, &listener_up);
}

void Sound::FMODErrorCheck(FMOD_RESULT p_result)
{
	if (p_result != FMOD_OK)
	{
		std::cout << "FMOD error! (" << p_result << ") " << FMOD_ErrorString(p_result) << std::endl;
		std::exit(-1);
	}
}

void Sound::StopMusic(){
	bool* isPLaying = new bool;
	
	musicChannel->isPlaying(isPLaying);
	if (*isPLaying){
		musicChannel->stop();
	}

	delete isPLaying;
}

void Sound::StartMusic(){
	bool* isPLaying = new bool;

	musicChannel->isPlaying(isPLaying);
	if (!*isPLaying){
		PlayBackgroundSound(PLAYSOUND_BACKGROUND_SOUND);
	}

	delete isPLaying;
}

void Sound::PlayBackgroundSound(PLAYSOUND p_playSound){
	switch (p_playSound)
	{
	case PLAYSOUND_BACKGROUND_SOUND:
		m_backgroundSound->setMode(FMOD_LOOP_NORMAL);
		m_backgroundSound->setLoopCount(-1);
		music_sound_id = m_system->playSound(m_backgroundSound, channelMusic, true, &musicChannel);

		musicChannel->setChannelGroup(channelMusic);
		musicChannel->setVolume(m_musicVolume);
		musicChannel->setPaused(false);
		break;
	}
}

void Sound::StartStopMusic(){
	bool* isPLaying = new bool;
	musicChannel->isPlaying(isPLaying);

	if (*isPLaying){
		StopMusic();
	}
	else if (!*isPLaying){
		StartMusic();
	}
	delete isPLaying;
}

void Sound::PlayDefaultSound(SoundEmitter* p_soundEmitter){
	switch (p_soundEmitter->m_playSound)
	{
	case PLAYSOUND_KUNAI_THROW_SOUND:
	{
		m_kunaiThrowSound->setMode(FMOD_LOOP_OFF);
		m_kunaiThrowSound->setLoopCount(1);
		m_system->playSound(m_kunaiThrowSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_KUNAI_HIT_SOUND:
	{
		m_kunaiHitSound->setMode(FMOD_LOOP_OFF);
		m_kunaiHitSound->setLoopCount(1);
		m_system->playSound(m_kunaiHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_KUNAI_HIT_OBJECTS_SOUND:
	{
		m_kunaiHitOBjectsSound->setMode(FMOD_LOOP_OFF);
		m_kunaiHitOBjectsSound->setLoopCount(1);
		m_system->playSound(m_kunaiHitOBjectsSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_AIR_CUT_SOUND:
	{
		m_airCutSound->setMode(FMOD_LOOP_OFF);
		m_airCutSound->setLoopCount(1);
		m_system->playSound(m_airCutSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_KATANA_HIT_SOUND:
	{
		m_katanaHitSound->setMode(FMOD_LOOP_OFF);
		m_katanaHitSound->setLoopCount(1);
		m_system->playSound(m_katanaHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_DASH_STEPS_SOUND:
	{
		m_dashStepsSound->setMode(FMOD_LOOP_OFF);
		m_dashStepsSound->setLoopCount(1);
		m_system->playSound(m_dashStepsSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_SHURIKEN_THROW_SOUND:
	{
		m_shurikenThrowSound->setMode(FMOD_LOOP_OFF);
		m_shurikenThrowSound->setLoopCount(1);
		m_system->playSound(m_shurikenThrowSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_SHURIKEN_HIT_SOUND:
	{
		m_shurikenHitSound->setMode(FMOD_LOOP_OFF);
		m_shurikenHitSound->setLoopCount(1);
		m_system->playSound(m_shurikenHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND:
	{
		m_shurikenHitObjectsSound->setMode(FMOD_LOOP_OFF);
		m_shurikenHitObjectsSound->setLoopCount(1);
		m_system->playSound(m_shurikenHitObjectsSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_MEGA_SHURIKEN_HIT_SOUND:
	{
		m_megaShurikenHitSound->setMode(FMOD_LOOP_OFF);
		m_megaShurikenHitSound->setLoopCount(1);
		m_system->playSound(m_megaShurikenHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND:
	{
		m_megaShurikenHitObjectsSound->setMode(FMOD_LOOP_OFF);
		m_megaShurikenHitObjectsSound->setLoopCount(1);
		m_system->playSound(m_megaShurikenHitObjectsSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_SMOKE_BOMB_SOUND:
	{
		m_smokeBombSound->setMode(FMOD_LOOP_OFF);
		m_smokeBombSound->setLoopCount(1);
		m_system->playSound(m_smokeBombSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_WHIP_AIR_SOUND:
	{
		m_whipAirSound->setMode(FMOD_LOOP_OFF);
		m_whipAirSound->setLoopCount(1);
		m_system->playSound(m_whipAirSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_WHIP_ROTATE_SOUND:
	{
		m_whipRotateSound->setMode(FMOD_LOOP_OFF);
		m_whipRotateSound->setLoopCount(1);
		m_system->playSound(m_whipRotateSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_WHIP_HIT_SOUND:
	{
		m_whipHitSound->setMode(FMOD_LOOP_OFF);
		m_whipHitSound->setLoopCount(1);
		m_system->playSound(m_whipHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_NAGINATA_AIR_SOUND:
	{
		m_naginataAirSound->setMode(FMOD_LOOP_OFF);
		m_naginataAirSound->setLoopCount(1);
		m_system->playSound(m_naginataAirSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_NAGINATA_STAB_SOUND:
	{
		m_naginataAirStabSound->setMode(FMOD_LOOP_OFF);
		m_naginataAirStabSound->setLoopCount(1);
		m_system->playSound(m_naginataAirStabSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_NAGINATA_HIT_SOUND:
	{
		m_naginataHitSound->setMode(FMOD_LOOP_OFF);
		m_naginataHitSound->setLoopCount(1);
		m_system->playSound(m_naginataHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_VOLLEY_THROW_SOUND:
	{
		m_volleyThrowSound->setMode(FMOD_LOOP_OFF);
		m_volleyThrowSound->setLoopCount(1);
		m_system->playSound(m_volleyThrowSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_VOLLEY_HIT_SOUND:
	{
		m_volleyHitSound->setMode(FMOD_LOOP_OFF);
		m_volleyHitSound->setLoopCount(1);
		m_system->playSound(m_volleyHitSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_BUBLE_SOUND:
	{
		m_bubleSound->setMode(FMOD_LOOP_OFF);
		m_bubleSound->setLoopCount(1);
		m_system->playSound(m_bubleSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_MALE_DEATH_SOUND:
	{
		m_maleDeathSound->setMode(FMOD_LOOP_OFF);
		m_maleDeathSound->setLoopCount(1);
		m_system->playSound(m_maleDeathSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_FEMALE_DEATH_SOUND:
	{
		m_femaleDeathSound->setMode(FMOD_LOOP_OFF);
		m_femaleDeathSound->setLoopCount(1);
		m_system->playSound(m_femaleDeathSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_MALE_HURT_SOUND:
	{
		m_maleHurtSound->setMode(FMOD_LOOP_OFF);
		m_maleHurtSound->setLoopCount(1);
		m_system->playSound(m_maleHurtSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_FEMALE_HURT_SOUND:
	{
		m_femaleHurtSound->setMode(FMOD_LOOP_OFF);
		m_femaleHurtSound->setLoopCount(1);
		m_system->playSound(m_femaleHurtSound, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_COUNTDOWN_BEEP_SOUND:
	{
		m_countdownBeep->setMode(FMOD_LOOP_OFF);
		m_countdownBeep->setLoopCount(1);
		m_system->playSound(m_countdownBeep, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_INVISIBLE_SPAWN_SOUND:
	{
		m_runeInvisibilitySpawn->setMode(FMOD_LOOP_OFF);
		m_runeInvisibilitySpawn->setLoopCount(1);
		m_system->playSound(m_runeInvisibilitySpawn, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_INVISIBLE_PICKUP_SOUND:
	{
		m_runeInvisibilityPickup->setMode(FMOD_LOOP_OFF);
		m_runeInvisibilityPickup->setLoopCount(1);
		m_system->playSound(m_runeInvisibilityPickup, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_HEAL_SPAWN_SOUND:
	{
		m_runeHealSpawn->setMode(FMOD_LOOP_OFF);
		m_runeHealSpawn->setLoopCount(1);
		m_system->playSound(m_runeHealSpawn, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_HEAL_PICKUP_SOUND:
	{
		m_runeHealPickup->setMode(FMOD_LOOP_OFF);
		m_runeHealPickup->setLoopCount(1);
		m_system->playSound(m_runeHealPickup, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_SHIELD_SPAWN_SOUND:
	{
		m_runeShieldSpawn->setMode(FMOD_LOOP_OFF);
		m_runeShieldSpawn->setLoopCount(1);
		m_system->playSound(m_runeShieldSpawn, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_SHIELD_PICKUP_SOUND:
	{
		m_runeShieldPickup->setMode(FMOD_LOOP_OFF);
		m_runeShieldPickup->setLoopCount(1);
		m_system->playSound(m_runeShieldPickup, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	default:
	{
		break;
	}
	}
	
	p_soundEmitter->m_channel->setChannelGroup(channelEffects);
	p_soundEmitter->m_channel->set3DMinMaxDistance(0, 30);

	//Reset volume if to loud
	//if (p_initialVolume > 1.0f){
//		p_initialVolume = 1.0f;
	//}
	p_soundEmitter->m_channel->setVolume(1.0f);
	p_soundEmitter->m_channel->setPaused(false);
	p_soundEmitter->m_channel->set3DAttributes(&p_soundEmitter->m_pos, NULL, NULL);
}

void Sound::CreateDefaultSound(PLAYSOUND p_playSound, float p_x, float p_y, float p_z)
{
	SoundEmitter* soundEmitter = new SoundEmitter;
	soundEmitter->m_playSound = p_playSound;
	soundEmitter->m_pos.x = p_x;
	soundEmitter->m_pos.y = p_y;
	soundEmitter->m_pos.z = p_z;

	//float distance = sqrtf(((p_x - soundEmitter->m_x)*(p_x - soundEmitter->m_x) + (p_z - soundEmitter->m_z)*(p_z - soundEmitter->m_z)));
	//float soundDistanceGain = 4.0f;
	//float volume = 1.0f / (distance / soundDistanceGain);

	defaultSoundEmitters.push_back(soundEmitter);
	PlayDefaultSound(soundEmitter);

}

void Sound::GarbageCollectOldSounds(){
	int elementToEarse = -1;
	for (unsigned int i = 0; i < defaultSoundEmitters.size(); i++)
	{
		bool isPlaying;
		defaultSoundEmitters[i]->m_channel->isPlaying(&isPlaying);
		if (!isPlaying){
			delete defaultSoundEmitters[i];
			elementToEarse = i;
			//Only delete one sound per loop
			break;
		}
	}
	if (elementToEarse != -1){
		defaultSoundEmitters.erase(defaultSoundEmitters.begin() + elementToEarse);
	}
}

void Sound::ClearAmbientSounds(){
	for (unsigned int i = 0; i < ambientSoundEmitters.size(); i++)
	{
		ambientSoundEmitters[i]->isPlaying = false;
		ambientSoundEmitters[i]->m_channel->stop();
		delete ambientSoundEmitters[i];
	}
	ambientSoundEmitters.clear();
}

Sound::SoundEmitter* Sound::CreateAmbientSound(PLAYSOUND p_playSound, float p_x, float p_y, float p_z)
{
	SoundEmitter* soundEmitter = new SoundEmitter;
	soundEmitter->m_playSound = p_playSound;
	soundEmitter->m_pos.x = p_x;
	soundEmitter->m_pos.y = p_y;
	soundEmitter->m_pos.z = p_z;

	PlayAmbientSound(soundEmitter);

	ambientSoundEmitters.push_back(soundEmitter);

	return soundEmitter;
}

void Sound::UpdateAmbientSound(float p_player_x, float p_player_y, float p_player_z)
{
	for (unsigned int i = 0; i < ambientSoundEmitters.size(); i++)
	{
		/*FMOD_VECTOR* pos = new FMOD_VECTOR;
		pos->x = ambientSoundEmitters[i]->m_pos->x;
		pos->y = ambientSoundEmitters[i]->m_y;
		pos->z = ambientSoundEmitters[i]->m_z;*/

		ambientSoundEmitters[i]->m_channel->set3DAttributes(&ambientSoundEmitters[i]->m_pos, NULL, NULL);
		////Not necessary for 3D sound
		//float distance = sqrtf(((p_player_x - soundEmitters[i]->m_x)*(p_player_x - soundEmitters[i]->m_x) + (p_player_z - soundEmitters[i]->m_z)*(p_player_z - soundEmitters[i]->m_z)));
		//float soundDistanceGain = 1.0f;
		//float volume = 1.0f / (distance / soundDistanceGain);
		//setAmbientVolume(soundEmitters[i], volume);
		////Set sound volume to 1 instead
		setAmbientVolume(ambientSoundEmitters[i], 1.0f);
		
	}
}

void Sound::StopAmbientSound(SoundEmitter* p_soundEmitter){
	p_soundEmitter->isPlaying = false;
}

void Sound::StartAmbientSound(SoundEmitter* p_soundEmitter){
	p_soundEmitter->isPlaying = true;
}

void Sound::PlayAmbientSound(SoundEmitter* p_soundEmitter, float p_initialVolume){
	switch (p_soundEmitter->m_playSound)
	{
	case PLAYSOUND_FIRE_SOUND:
	{
		m_fireSound->setMode(FMOD_LOOP_NORMAL);
		m_fireSound->setLoopCount(-1);
		m_system->playSound(m_fireSound, channelAmbient, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_BIRD_SOUND:
	{
		m_birdSound->setMode(FMOD_LOOP_NORMAL);
		m_birdSound->setLoopCount(-1);
		m_system->playSound(m_birdSound, channelAmbient, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_WIND_SOUND:
	{
		m_windSound->setMode(FMOD_LOOP_NORMAL);
		m_windSound->setLoopCount(-1);
		m_system->playSound(m_windSound, channelAmbient, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_STEPS_LEAVES_SOUND:
	{
		m_stepsLeavesSound->setMode(FMOD_LOOP_NORMAL);
		m_stepsLeavesSound->setLoopCount(-1);
		m_system->playSound(m_stepsLeavesSound, channelAmbient, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_SHIELD_SOUND:
	{
		m_runeShield->setMode(FMOD_LOOP_OFF);
		m_runeShield->setLoopCount(1);
		m_system->playSound(m_runeShield, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_HEAL_SOUND:
	{
		m_runeHeal->setMode(FMOD_LOOP_OFF);
		m_runeHeal->setLoopCount(1);
		m_system->playSound(m_runeHeal, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	case PLAYSOUND_RUNE_INVISIBLE_SOUND:
	{
		m_runeInvisibility->setMode(FMOD_LOOP_OFF);
		m_runeInvisibility->setLoopCount(1);
		m_system->playSound(m_runeInvisibility, channelEffects, true, &p_soundEmitter->m_channel);
		break;
	}
	default:
	{
		break;
	}
	}

	p_soundEmitter->m_channel->setChannelGroup(channelAmbient);
	p_soundEmitter->m_channel->set3DMinMaxDistance(0, 25);

	//Reset volume if to loud
	if (p_initialVolume > 1.0f){
		p_initialVolume = 1.0f;
	}
	p_soundEmitter->m_channel->setVolume(0.0f);
	p_soundEmitter->m_channel->setPaused(false);
}

void Sound::setAmbientVolume(SoundEmitter* p_soundEmitter, float p_volume){

	//If wind always same volume
	if (p_soundEmitter->m_playSound == PLAYSOUND::PLAYSOUND_WIND_SOUND){
		p_soundEmitter->m_channel->setPaused(true);
		p_soundEmitter->m_channel->setVolume(m_defaultWindVolume);
		p_soundEmitter->m_channel->setPaused(false);
		return;
	}

	if (p_volume > 1.0f){
		p_volume = 1.0f;
	}
	else if (p_volume < 0.1f){
		p_volume = 0.0f;
	}
	if (p_soundEmitter->isPlaying){
		p_soundEmitter->m_channel->setPaused(true);
		p_soundEmitter->m_channel->setVolume(p_volume);
		p_soundEmitter->m_channel->setPaused(false);
	}
	else{
		p_soundEmitter->m_channel->setPaused(true);
		p_soundEmitter->m_channel->setVolume(0.0f);
		p_soundEmitter->m_channel->setPaused(false);
	}
}