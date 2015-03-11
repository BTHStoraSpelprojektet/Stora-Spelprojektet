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

	bool Initialize(RakNet::RakPeerInterface *p_serverPeer, std::vector<std::string> p_levelsName, int p_currentLevel);
	void Shutdown();
	void Update(double p_deltaTime);

	void RoundRestart();
	void PickUpRunes(POINTOFINTERESTTYPE p_poiType, RakNet::RakNetGUID p_guid);
	void SpawnRunes();
	bool IsRuneActive(int p_index);
	std::vector<Box> GetBoundingBoxes(POINTOFINTERESTTYPE p_poiType);
	void AbilityUsed();

	void DownloadRunes(RakNet::RakNetGUID p_guid);

private:
	void CancelRune(POINTOFINTERESTTYPE p_runeType);

	RakNet::RakPeerInterface *m_serverPeer;
	int m_nrOfRunes;

	std::vector<LevelImporter::POI> m_POISpawnPoints;
	std::vector<Box> m_lotusBoundingBoxes;
	std::vector<Box> m_shieldBoundingBoxes;
	std::vector<Box> m_invisBoundingBoxes;

	bool m_lotusActive;
	bool m_shieldActive;
	bool m_invisActive;
	bool canceledShield;
	bool canceledInvis;
	float m_invisActiveTimer;
	float m_shieldActiveTimer;
};
#endif // !POINTOFINTERESTMANAGER_H_