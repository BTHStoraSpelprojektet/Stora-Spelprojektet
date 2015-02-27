#ifndef POINTOFINTERESTMANAGER_H_
#define POINTOFINTERESTMANAGER_H_

#include <vector>
#include "../CommonLibs/CommonStructures.h"
#include "PointOfInterest.h"

class PointOfInterestManager
{
public:
	PointOfInterestManager();
	~PointOfInterestManager();

	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);
	void Render();
	void RenderDepth();

	void RoundRestart();
	void PickUpRunes(OBB p_OBB);
	void SpawnRunes(int p_index, float p_x, float p_y, float p_z);
	void CollisionCheck();
private:

	int m_nrOfRunes;
	std::vector<PointOfInterest> m_runes;

};
#endif // !POINTOFINTERESTMANAGER_H_