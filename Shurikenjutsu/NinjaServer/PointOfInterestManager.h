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
	void PickUpRunes(int p_index, RakNet::RakNetGUID p_guid);
	void SpawnRunes();
	std::vector<Box> GetBoundingBoxes(int p_index);

private:
	RakNet::RakPeerInterface *m_serverPeer;
	int m_nrOfRunes;

	std::vector<LevelImporter::POI> m_POISpawnPoints;
	std::vector<Box> m_lotusBoundingBoxes;
	std::vector<Box> m_shieldBoundingBoxes;
	std::vector<Box> m_invisBoundingBoxes;

};
#endif // !POINTOFINTERESTMANAGER_H_