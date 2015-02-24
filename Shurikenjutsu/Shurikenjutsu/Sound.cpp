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
	FMODErrorCheck(m_system->createChannelGroup(NULL, &channelMusic));

	m_result = m_system->createStream("../Shurikenjutsu/Sound/BG_music.wav", FMOD_DEFAULT, 0, &m_backgroundSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KunaiHit.wav", FMOD_DEFAULT, 0, &m_kunaiHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KunaiThrow.wav", FMOD_DEFAULT, 0, &m_kunaiThrowSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/AirCut.wav", FMOD_DEFAULT, 0, &m_airCutSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/DashGrassSteps.wav", FMOD_DEFAULT, 0, &m_dashStepsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenThrow.wav", FMOD_DEFAULT, 0, &m_shurikenThrowSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenHit.wav", FMOD_DEFAULT, 0, &m_shurikenHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/ShurikenHitObjects.wav", FMOD_DEFAULT, 0, &m_shurikenHitObjectsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/KatanaHit.wav", FMOD_DEFAULT, 0, &m_katanaHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/MegaShurikenHit.wav", FMOD_DEFAULT, 0, &m_megaShurikenHitSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/MegaShurikenHitObjects.wav", FMOD_DEFAULT, 0, &m_megaShurikenHitObjectsSound);
	FMODErrorCheck(m_result);

	m_result = m_system->createSound("../Shurikenjutsu/Sound/SmokeBomb.wav", FMOD_DEFAULT, 0, &m_smokeBombSound);
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
	m_system->release();
}

void Sound::Update()
{
	m_system->update();
}

void Sound::FMODErrorCheck(FMOD_RESULT p_result)
{
	if (p_result != FMOD_OK)
	{
		std::cout << "FMOD error! (" << p_result << ") " << FMOD_ErrorString(p_result) << std::endl;
		std::exit(-1);
	}
}

void Sound::PlaySound(PLAYSOUND p_playSound, float volume)
{
	switch (p_playSound)
	{
	case PLAYSOUND_BACKGROUND_SOUND:
		m_backgroundSound->setMode(FMOD_LOOP_NORMAL);
		m_backgroundSound->setLoopCount(1);
		m_system->playSound(m_backgroundSound, channelMusic, true, &musicChannel);

		musicChannel->setChannelGroup(channelMusic);
		musicChannel->setVolume(m_musicVolume);
		musicChannel->setPaused(false);
		break;
	case PLAYSOUND_KUNAI_THROW_SOUND:
		m_kunaiThrowSound->setMode(FMOD_LOOP_OFF);
		m_kunaiThrowSound->setLoopCount(1);
		m_system->playSound(m_kunaiThrowSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_KUNAI_HIT_SOUND:
		m_kunaiHitSound->setMode(FMOD_LOOP_OFF);
		m_kunaiHitSound->setLoopCount(1);
		m_system->playSound(m_kunaiHitSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_AIR_CUT_SOUND:
		m_airCutSound->setMode(FMOD_LOOP_OFF);
		m_airCutSound->setLoopCount(1);
		m_system->playSound(m_airCutSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_KATANA_HIT_SOUND:
		m_katanaHitSound->setMode(FMOD_LOOP_OFF);
		m_katanaHitSound->setLoopCount(1);
		m_system->playSound(m_katanaHitSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_DASH_STEPS_SOUND:
		m_dashStepsSound->setMode(FMOD_LOOP_OFF);
		m_dashStepsSound->setLoopCount(1);
		m_system->playSound(m_dashStepsSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_SHURIKEN_THROW_SOUND:
		m_shurikenThrowSound->setMode(FMOD_LOOP_OFF);
		m_shurikenThrowSound->setLoopCount(1);
		m_system->playSound(m_shurikenThrowSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_SHURIKEN_HIT_SOUND:
		m_shurikenHitSound->setMode(FMOD_LOOP_OFF);
		m_shurikenHitSound->setLoopCount(1);
		m_system->playSound(m_shurikenHitSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND:
		m_shurikenHitObjectsSound->setMode(FMOD_LOOP_OFF);
		m_shurikenHitObjectsSound->setLoopCount(1);
		m_system->playSound(m_shurikenHitObjectsSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_MEGA_SHURIKEN_HIT_SOUND:
		m_megaShurikenHitSound->setMode(FMOD_LOOP_OFF);
		m_megaShurikenHitSound->setLoopCount(1);
		m_system->playSound(m_megaShurikenHitSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND:
		m_megaShurikenHitObjectsSound->setMode(FMOD_LOOP_OFF);
		m_megaShurikenHitObjectsSound->setLoopCount(1);
		m_system->playSound(m_megaShurikenHitObjectsSound, channelEffects, true, &effectChannel);
		break;
	case PLAYSOUND_SMOKE_BOMB_SOUND:
		m_smokeBombSound->setMode(FMOD_LOOP_OFF);
		m_smokeBombSound->setLoopCount(1);
		m_system->playSound(m_smokeBombSound, channelEffects, true, &effectChannel);
		break;
	default:
		break;
	}

	effectChannel->setChannelGroup(channelEffects);
	
	//Reset volume if to loud
	if (volume > 1.0f){
		volume = 1.0f;
	}
	effectChannel->setVolume(volume);
	effectChannel->setPaused(false);
}