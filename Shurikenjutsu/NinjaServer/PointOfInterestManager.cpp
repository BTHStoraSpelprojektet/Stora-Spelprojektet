#include "PointOfInterestManager.h"
#include <DirectXMath.h>
#include "../CommonLibs/ModelNames.h"
#include "Collisions.h"
#include "../CommonLibs/Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "PlayerManager.h"


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
	for (unsigned int i = 0; i < m_lotusBoundingBoxes.size(); i++)
	{
		m_lotusBoundingBoxes[i].m_center.x += m_POISpawnPoints[0].m_translationX;
		m_lotusBoundingBoxes[i].m_center.y += m_POISpawnPoints[0].m_translationY;
		m_lotusBoundingBoxes[i].m_center.z += m_POISpawnPoints[0].m_translationZ;
	}

	m_invisBoundingBoxes = ModelLibrary::GetInstance()->GetModel(RUNE_INVIS)->GetBoundingBoxes();
	for (unsigned int i = 0; i < m_invisBoundingBoxes.size(); i++)
	{
		m_invisBoundingBoxes[i].m_center.x += m_POISpawnPoints[1].m_translationX;
		m_invisBoundingBoxes[i].m_center.y += m_POISpawnPoints[1].m_translationY;
		m_invisBoundingBoxes[i].m_center.z += m_POISpawnPoints[1].m_translationZ;
	}
	
	m_shieldBoundingBoxes = ModelLibrary::GetInstance()->GetModel(RUNE_SHIELD)->GetBoundingBoxes();
	for (unsigned int i = 0; i < m_shieldBoundingBoxes.size(); i++)
	{
		m_shieldBoundingBoxes[i].m_center.x += m_POISpawnPoints[2].m_translationX;
		m_shieldBoundingBoxes[i].m_center.y += m_POISpawnPoints[2].m_translationY;
		m_shieldBoundingBoxes[i].m_center.z += m_POISpawnPoints[2].m_translationZ;
	}
	
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

void PointOfInterestManager::PickUpRunes(POINTOFINTERESTTYPE p_poiType, RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;
	
	switch (p_poiType)
	{
	case POINTOFINTERESTTYPE_HEAL:
	{
		m_lotusActive = false;
		bitStream.Write((RakNet::MessageID)ID_LOTUS_PICKED_UP);
		break;
	}
	case POINTOFINTERESTTYPE_SHIELD:
	{
		m_shieldActive = false;
		bitStream.Write((RakNet::MessageID)ID_SHIELD_PICKED_UP);
		break;
	}
	case POINTOFINTERESTTYPE_INVISIBLE:
	{
		m_invisActive = false;
		bitStream.Write((RakNet::MessageID)ID_INVIS_PICKED_UP);
		break;
	}
	default:
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

std::vector<Box> PointOfInterestManager::GetBoundingBoxes(POINTOFINTERESTTYPE p_poiType)
{
	switch (p_poiType)
	{
	case POINTOFINTERESTTYPE_HEAL:
		return m_lotusBoundingBoxes;
		break;
	case POINTOFINTERESTTYPE_INVISIBLE:
		return m_invisBoundingBoxes;
		break;
	case POINTOFINTERESTTYPE_SHIELD:
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