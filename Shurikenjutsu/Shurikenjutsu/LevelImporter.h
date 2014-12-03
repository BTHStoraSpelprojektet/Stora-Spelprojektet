#ifndef LEVELIMPORTER_H_
#define LEVELIMPORTER_H_

#define WIN32_LEAN_AND_MEAN
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Model.h"
#include "ObjectManager.h"

class LevelImporter
{
public:
	struct SpawnPoint{
		int m_team;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	LevelImporter::LevelImporter(ObjectManager* p_objectManager, std::string p_level);
	~LevelImporter();

	void loadLevelFile();
	bool readData(ObjectManager* p_objectManager);
	std::vector<SpawnPoint> getSpawnPoints();
protected:
	ObjectManager* m_objectManager;
	std::string m_level;
	std::vector<std::vector<std::string>> levelData;
	
	std::vector<SpawnPoint> m_spawnPoints;

	bool m_print = false;
};

#endif LEVELIMPORTER_H_