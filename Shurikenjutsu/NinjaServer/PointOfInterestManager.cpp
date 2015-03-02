#include "PointOfInterestManager.h"
#include <DirectXMath.h>
#include "../CommonLibs/ModelNames.h"
#include "Collisions.h"
#include "../CommonLibs/Level.h"
#include "..\CommonLibs\ModelLibrary.h"


PointOfInterestManager::PointOfInterestManager()
{
	
}


PointOfInterestManager::~PointOfInterestManager()
{
}


bool PointOfInterestManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{
	m_serverPeer = p_serverPeer;

	Level level(LEVEL_NAME);
	m_POISpawnPoints = level.GetPOIPoints();
	m_lotusActive = false;
	m_shieldActive = false;
	m_invisActive = false;
	m_nrOfRunes = 3;

	m_lotusBoundingBoxes = ModelLibrary::GetInstance()->GetModel(RUNE_LOTUS)->GetBoundingBoxes();
	m_shieldBoundingBoxes = ModelLibrary::GetInstance()->GetModel(RUNE_SHIELD)->GetBoundingBoxes();
	m_invisBoundingBoxes = ModelLibrary::GetInstance()->GetModel(RUNE_INVIS)->GetBoundingBoxes();

	return true;
}

void PointOfInterestManager::Shutdown()
{
	
}

void PointOfInterestManager::Update(double p_deltaTime)
{
	
}

void PointOfInterestManager::SpawnRunes()
{
	m_lotusActive = true;
	m_shieldActive = true;
	m_invisActive = true;
	// Todo add runes
	RakNet::BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_SPAWN_RUNES);
	for (int i = 0; i < 3; i++)
	{
		bitStream.Write(m_POISpawnPoints[i].type);
		bitStream.Write(m_POISpawnPoints[i].m_translationX);
		bitStream.Write(m_POISpawnPoints[i].m_translationY);
		bitStream.Write(m_POISpawnPoints[i].m_translationZ);

	}
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PointOfInterestManager::PickUpRunes(PointOfInterestType p_poiType, RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;
	
	switch (p_poiType)
	{
	case PointOfInterestType_Heal:
	{
		bitStream.Write((RakNet::MessageID)ID_LOTUS_PICKED_UP);
		// Add sound
		break;
	}
	case PointOfInterestType_Shield:
	{
		bitStream.Write((RakNet::MessageID)ID_SHIELD_PICKED_UP);
		break;
	}
	case PointOfInterestType_Invisible:
	{
		bitStream.Write((RakNet::MessageID)ID_INVIS_PICKED_UP);
		break;
	}
	default:
		bitStream.Write((RakNet::MessageID)ID_RUNE_PICKED_UP);
		break;
	}
	bitStream.Write(p_guid);

	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PointOfInterestManager::RoundRestart()
{
	Shutdown();
	//Initialize();
}

std::vector<Box> PointOfInterestManager::GetBoundingBoxes(PointOfInterestType p_poiType)
{
	switch (p_poiType)
	{
	case PointOfInterestType_Heal:
		return m_lotusBoundingBoxes;
		break;
	case PointOfInterestType_Invisible:
		return m_invisBoundingBoxes;
		break;
	case PointOfInterestType_Shield:
		return m_shieldBoundingBoxes;
		break;
	default:
		break;
	}

	return m_lotusBoundingBoxes;
}

bool PointOfInterestManager::IsRuneActive(int p_index)
{
	switch (p_index)
	{
	case 0:
		return m_lotusActive;
		break;
	case 1:
		return m_invisActive;
		break;
	case 2:
		return m_shieldActive;
		break;
	default:
		return false;
		break;
	}
	return false;
}