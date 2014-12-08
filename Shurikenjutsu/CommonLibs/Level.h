#ifndef LEVEL_H_
#define LEVEL_H_

#include <string>
#include "LevelImporter.h"

class Level
{
public:
	Level::Level(std::string level);
	~Level();

	bool loadLevel(std::string p_level);
	std::vector<LevelImporter::SpawnPoint> GetSpawnPoints();
	std::vector<LevelImporter::CommonObject> GetObjects();
protected:
	int m_mapsizeX;
	int m_mapsizeY;
	std::vector<LevelImporter::SpawnPoint> m_spawnPoints;
	std::vector<LevelImporter::CommonObject> m_objects;
};

#endif LEVEL_H_