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

	m_POIPoints = levelImporter.GetPOIPoints();

	m_shadowShapes = levelImporter.GetShadowsShapes();

	m_particleEmitter = levelImporter.GetParticleEmitters();

	m_levelBoundingBoxes = levelImporter.getLevelBoundingBoxes();

	m_objects = levelImporter.GetObjects();

	m_animatedObjects = levelImporter.GetAnimatedObjects();

	return loaded;
}

std::vector<LevelImporter::SpawnPoint> Level::GetSpawnPoints(){
	return m_spawnPoints;
}

std::vector<LevelImporter::POI> Level::GetPOIPoints()
{
	return m_POIPoints;
}

std::vector<Line> Level::GetShadowsShapes(){
	return m_shadowShapes;
}

std::vector<LevelImporter::ParticleEmitter> Level::GetParticleEmitters(){
	return m_particleEmitter;
}

std::vector<LevelImporter::LevelBoundingBox> Level::getLevelBoundingBoxes(){
	return m_levelBoundingBoxes;
}

std::vector<LevelImporter::CommonObject> Level::GetObjects()
{
	return m_objects;
}

std::vector<LevelImporter::AnimatedObject> Level::GetAnimatedObjects()
{
	return m_animatedObjects;
}

