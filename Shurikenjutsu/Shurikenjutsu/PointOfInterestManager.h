#ifndef POINTOFINTERESTMANAGER_H_
#define POINTOFINTERESTMANAGER_H_

#include <vector>
//#include "PointOfInterest.h"

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


private:
	void SpawnRunes();
	void PickUprunes();

	int m_nrOfRunes;
	std::vector<PointOfInterest> m_runes;


};
#endif // !POINTOFINTERESTMANAGER_H_