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
		int team;
		DirectX::XMFLOAT3 translation;
		DirectX::XMFLOAT3 rotation;
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
};