#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Model.h"
#include "ObjectManager.h"

class Level
{
public:
	Level::Level(ObjectManager* p_objectManager, std::string level);
	~Level();

	bool loadLevel(ObjectManager* p_objectManager, std::string p_level);
protected:
	int m_mapsizeX;
	int m_mapsizeY;

	std::vector<std::vector<std::string>> loadLevelFile(std::string p_level);
	void readData(ObjectManager* p_objectManager, std::vector<std::vector<std::string>> stringVector2);
};