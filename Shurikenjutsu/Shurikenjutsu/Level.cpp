#include "Level.h"

Level::Level(ObjectManager* p_objectManager, std::string p_level){
	if (!loadLevel(p_objectManager, p_level)){
		std::cout << "Level not loaded\n";
	}
}

bool Level::loadLevel(ObjectManager* p_objectManager, std::string p_level){
	LevelImporter levelImporter(p_objectManager, p_level);

	levelImporter.loadLevelFile();

	return levelImporter.readData(p_objectManager);
}

Level::~Level(){

}