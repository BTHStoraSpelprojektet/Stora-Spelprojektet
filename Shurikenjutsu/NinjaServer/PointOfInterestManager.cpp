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

	m_nrOfRunes = 3;

	DirectX::XMFLOAT3 spawnPoints[3];
	spawnPoints[0] = DirectX::XMFLOAT3(m_POISpawnPoints[0].m_translationX, m_POISpawnPoints[0].m_translationY, m_POISpawnPoints[0].m_translationZ);
	spawnPoints[1] = DirectX::XMFLOAT3(m_POISpawnPoints[1].m_translationX, m_POISpawnPoints[1].m_translationY, m_POISpawnPoints[1].m_translationZ);
	spawnPoints[2] = DirectX::XMFLOAT3(m_POISpawnPoints[2].m_translationX, m_POISpawnPoints[2].m_translationY, m_POISpawnPoints[2].m_translationZ);

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
	RakNet::BitStream bitStream;
	bitStream.Write((RakNet::MessageID)ID_SPAWN_RUNES);
	m_serverPeer->Send(&bitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}

void PointOfInterestManager::PickUpRunes(int p_index, RakNet::RakNetGUID p_guid)
{
	RakNet::BitStream bitStream;

	
	switch (p_index)
	{
	case 0:
	{
		bitStream.Write((RakNet::MessageID)ID_LOTUS_PICKED_UP);
		break;
	}
	case 1:
	{
		bitStream.Write((RakNet::MessageID)ID_SHIELD_PICKED_UP);
		break;
	}
	case 2:
	{
		bitStream.Write((RakNet::MessageID)ID_INVIS_PICKED_UP);
		break;
	}
	default:
		bitStream.Write((RakNet::MessageID)ID_LOTUS_PICKED_UP);
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

std::vector<Box> PointOfInterestManager::GetBoundingBoxes(int p_index)
{
	switch (p_index)
	{
	case 0:
	{
		return m_lotusBoundingBoxes;
		break;
	}
	case 1:
	{
		return m_shieldBoundingBoxes;
		break;
	}
	case 2:
	{
		return m_invisBoundingBoxes;
		break;
	}
	default:
		break;
	}

	return m_lotusBoundingBoxes;
}