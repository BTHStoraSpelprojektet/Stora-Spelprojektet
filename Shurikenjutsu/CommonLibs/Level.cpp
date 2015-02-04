#include "Level.h"
#include <iostream>
#include <string>

Level::Level(std::string p_level){
	if (!loadLevel(p_level)){
		std::cout << "Level not loaded\n";
	}
}

Level::~Level(){}

bool Level::loadLevel(std::string p_level){
	LevelImporter levelImporter(p_level);

	levelImporter.loadLevelFile();

	bool loaded = levelImporter.readData();

	m_spawnPoints = levelImporter.GetSpawnPoints();

	m_shadowShapes = levelImporter.GetShadowsShapes();

	m_levelBoundingBoxes = levelImporter.getLevelBoundingBoxes();

	m_objects = levelImporter.GetObjects();

	return loaded;
}

std::vector<LevelImporter::SpawnPoint> Level::GetSpawnPoints(){
	return m_spawnPoints;
}

std::vector<Line> Level::GetShadowsShapes(){
	return m_shadowShapes;
}

std::vector<LevelImporter::LevelBoundingBox> Level::getLevelBoundingBoxes(){
	return m_levelBoundingBoxes;
}

std::vector<LevelImporter::CommonObject> Level::GetObjects()
{
	return m_objects;
}

