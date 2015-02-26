#ifndef POINTOFINTERESTMANAGER_H_
#define POINTOFINTERESTMANAGER_H_

#include <vector>
#include "../CommonLibs/CommonStructures.h"

class PointOfInterest;

class PointOfInterestManager
{
public:
	PointOfInterestManager();
	~PointOfInterestManager();

	bool Initialize();
	void Shutdown();
	void Update();
	void Render();
	void RenderDepth();

	void RoundRestart();
	void PickUpRunes(OBB p_OBB);
	void SpawnRunes();

private:

	int m_nrOfRunes;
	std::vector<PointOfInterest> m_runes;


};
#endif // !POINTOFINTERESTMANAGER_H_