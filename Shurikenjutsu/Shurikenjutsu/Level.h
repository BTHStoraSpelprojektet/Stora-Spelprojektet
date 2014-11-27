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
	Level::Level(ObjectManager* p_objectManager, std::string mapName);
	~Level();
protected:
	int m_mapsizeX;
	int m_mapsizeY;
};