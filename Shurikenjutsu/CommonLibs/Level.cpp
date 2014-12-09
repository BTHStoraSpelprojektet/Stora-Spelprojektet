#include "Level.h"

Level::Level(std::string p_level){
	if (!loadLevel(p_level)){
		std::cout << "Level not loaded\n";
	}
}

bool Level::loadLevel(std::string p_level){
	LevelImporter levelImporter(p_level);

	levelImporter.loadLevelFile();

	bool loaded = levelImporter.readData();

	m_spawnPoints = levelImporter.GetSpawnPoints();

	m_levelBoundingBoxes = levelImporter.getLevelBoundingBoxes();

	m_objects = levelImporter.GetObjects();

	return loaded;
}

std::vector<LevelImporter::SpawnPoint> Level::GetSpawnPoints(){
	return m_spawnPoints;
}


std::vector<LevelImporter::CommonObject> Level::GetObjects()
{
	return m_objects;
}

Level::~Level(){

}