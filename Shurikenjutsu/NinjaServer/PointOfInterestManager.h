#ifndef POINTOFINTERESTMANAGER_H_
#define POINTOFINTERESTMANAGER_H_

#include <vector>
#include "../CommonLibs/CommonStructures.h"
#include "..\CommonLibs\RakNet\RakPeerInterface.h"
#include "..\CommonLibs\RakNet\BitStream.h"
#include "..\CommonLibs\ServerMessages.h"
#include "../CommonLibs/LevelImporter.h"


class PointOfInterestManager
{
public:
	PointOfInterestManager();
	~PointOfInterestManager();

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer);
	void Shutdown();
	void Update(double p_deltaTime);

	void RoundRestart();
	void PickUpRunes(PointOfInterestType p_poiType, RakNet::RakNetGUID p_guid);
	void SpawnRunes();
	bool IsRuneActive(int p_index);
	std::vector<Box> GetBoundingBoxes(PointOfInterestType p_poiType);

private:
	RakNet::RakPeerInterface *m_serverPeer;
	int m_nrOfRunes;

	std::vector<LevelImporter::POI> m_POISpawnPoints;
	std::vector<Box> m_lotusBoundingBoxes;
	std::vector<Box> m_shieldBoundingBoxes;
	std::vector<Box> m_invisBoundingBoxes;

	bool m_lotusActive;
	bool m_shieldActive;
	bool m_invisActive;

};
#endif // !POINTOFINTERESTMANAGER_H_