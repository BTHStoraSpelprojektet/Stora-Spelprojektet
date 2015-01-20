#include "Sound.h"
#include <iostream>

Sound::Sound()
{
}


Sound::~Sound()
{
}

bool Sound::Initialize()
{
	// Create the interface
	m_result = FMOD::System_Create(&m_system);
	FMODErrorCheck(m_result);

	m_result = m_system->init(512, FMOD_INIT_NORMAL, 0);
	FMODErrorCheck(m_result);

	m_result = m_system->createStream("../Shurikenjutsu/Sound/257375__zagi2__slap-bass-brass-loop.wav", FMOD_DEFAULT, 0, &m_backgroundSound);
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

void Sound::PlaySound(PLAYSOUND p_playSound)
{
	switch (p_playSound)
	{
	case PLAYSOUND_BACKGROUND_SOUND:
		m_backgroundSound->setMode(FMOD_LOOP_NORMAL);
		m_backgroundSound->setLoopCount(1);
		m_system->playSound(m_backgroundSound, 0, false, 0);
		break;
	default:
		break;
	}
}