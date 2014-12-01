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
	LevelImporter::LevelImporter(ObjectManager* p_objectManager, std::string p_level);
	~LevelImporter();

	void loadLevelFile();
	bool readData(ObjectManager* p_objectManager);
protected:
	ObjectManager* m_objectManager;
	std::string m_level;
	std::vector<std::vector<std::string>> levelData;
};

#endif LEVELIMPORTER_H_