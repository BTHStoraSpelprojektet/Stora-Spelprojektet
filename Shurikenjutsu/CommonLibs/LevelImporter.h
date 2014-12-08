#ifndef LEVELIMPORTER_H_
#define LEVELIMPORTER_H_

#define WIN32_LEAN_AND_MEAN
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class LevelImporter
{
public:
	struct SpawnPoint
	{
		int m_team;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	struct CommonObject
	{
		std::string m_filePath;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	LevelImporter::LevelImporter(std::string p_level);
	~LevelImporter();

	void loadLevelFile();
	bool readData();
	std::vector<SpawnPoint> GetSpawnPoints();
	std::vector<CommonObject> GetObjects();
protected:
	std::string m_level;
	std::vector<std::vector<std::string>> levelData;
	
	std::vector<SpawnPoint> m_spawnPoints;
	std::vector<CommonObject> m_objects;

	bool m_print = false;
};

#endif LEVELIMPORTER_H_