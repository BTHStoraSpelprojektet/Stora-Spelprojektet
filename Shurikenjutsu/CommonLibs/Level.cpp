#include "Level.h"
#include <iostream>
#include <string>

Level::Level(std::string p_level){
	if (!LoadLevel(p_level)){
		std::cout << "Level not loaded\n";
	}
}

Level::~Level(){}

bool Level::LoadLevel(std::string p_level){

	LevelImporter levelImporter(p_level);

	levelImporter.LoadLevelFile();

	bool loaded = levelImporter.ReadData();

	m_spawnPoints = levelImporter.GetSpawnPoints();

	m_shadowShapes = levelImporter.GetShadowsShapes();

	m_particleEmitter = levelImporter.GetParticleEmitters();

	m_levelBoundingBoxes = levelImporter.GetLevelBoundingBoxes();

	m_objects = levelImporter.GetObjects();

	m_animatedObjects = levelImporter.GetAnimatedObjects();

	return loaded;
}

std::vector<LevelImporter::SpawnPoint> Level::GetSpawnPoints(){
	return m_spawnPoints;
}

std::vector<Line> Level::GetShadowsShapes(){
	return m_shadowShapes;
}

std::vector<LevelImporter::ParticleEmitter> Level::GetParticleEmitters(){
	return m_particleEmitter;
}

std::vector<LevelImporter::LevelBoundingBox> Level::GetLevelBoundingBoxes(){
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

