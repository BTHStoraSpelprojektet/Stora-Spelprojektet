#ifndef MAPMANAGER_H_
#define MAPMANAGER_H_

#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"

class MapManager
{
public:
	MapManager();
	~MapManager();

	bool Initialize(std::string p_levelName);
	void Shutdown();

	std::vector<Box> GetBoundingBoxes();
private:
	std::vector<LevelImporter::CommonObject> m_mapObjects;
	std::vector<Box> m_boundingBoxes;
	std::vector<LevelImporter::LevelBoundingBox> m_levelBoundingBoxes;
};

#endif