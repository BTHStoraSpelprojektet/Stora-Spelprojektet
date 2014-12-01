#ifndef LEVEL_H_
#define LEVEL_H_

#include <string>
#include "ObjectManager.h"
#include "LevelImporter.h"

class Level
{
public:
	Level::Level(ObjectManager* p_objectManager, std::string level);
	~Level();

	bool loadLevel(ObjectManager* p_objectManager, std::string p_level);
protected:
	int m_mapsizeX;
	int m_mapsizeY;
};

#endif LEVEL_H_