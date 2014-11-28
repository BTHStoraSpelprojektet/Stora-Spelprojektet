#include "Level.h"

Level::Level(ObjectManager* p_objectManager, std::string p_level){
	if (!loadLevel(p_objectManager, p_level)){
		std::cout << "Level not loaded\n";
	}
}



bool Level::loadLevel(ObjectManager* p_objectManager, std::string p_level){
	bool loaded = false;

	LevelImporter levelImporter(p_objectManager, p_level);

	levelImporter.loadLevelFile();

	levelImporter.readData(p_objectManager);

	/*std::vector<std::vector<std::string>> levelData;
	levelData = loadLevelFile(p_level);
	if (levelData.size() > 0){
		readData(p_objectManager, levelData);
		loaded = true;
	}*/
	return loaded;
}

Level::~Level(){

}