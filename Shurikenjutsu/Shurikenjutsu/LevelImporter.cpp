#include "LevelImporter.h"

LevelImporter::LevelImporter(ObjectManager* p_objectManager, std::string p_level){
	m_objectManager = p_objectManager;
	m_level = p_level;
}

void LevelImporter::loadLevelFile(){
	std::ifstream infile(m_level, std::ifstream::in);
	std::string line;

	int currentLine = 0;
	int currentWord = 0;
	int numberOfObjects = 0;

	std::vector<std::vector<std::string>> stringVector2;
	std::vector<std::string> stringVector;
	std::stringstream ss;
	std::string s = "";
	char c;
	while (infile.get(c)) {
		ss << c;
		if (c == ' '){
			s = ss.str();
			stringVector.push_back(s);

			ss.str("");
			ss.clear();

			currentWord++;
		}
		else if (c == '\n'){
			s = ss.str();
			stringVector.push_back(s);
			stringVector2.push_back(stringVector);
			stringVector.clear();

			ss.str("");
			ss.clear();

			currentLine++;
		}

	}

	infile.close();

	levelData = stringVector2;
}

bool LevelImporter::readData(ObjectManager* p_objectManager){
	if (levelData.size() == 0){
		return false;
	}
	float x, y, z, rotateX, rotateY, rotateZ, rotateW;
	for (unsigned int currentLineTemp = 0; currentLineTemp < levelData.size(); currentLineTemp++)
	{
		Model model;
		std::vector<std::string> temp = levelData.at(currentLineTemp);
		for (unsigned int currentWordTemp = 0; currentWordTemp < temp.size(); currentWordTemp++)
		{
			if (currentLineTemp > 1){
				std::string tmpStr = temp.at(currentWordTemp);
				if (currentWordTemp == 0){
					std::string filePathToModel = "";
					filePathToModel.append("../Shurikenjutsu/Models/");
					int pos = tmpStr.find('_');

					if (pos == -1){
						filePathToModel.append(tmpStr.substr(0, tmpStr.size() - 1));
					}
					else{
						filePathToModel.append(tmpStr.substr(0, pos));
					}
					filePathToModel.append("Shape.SSP");

					std::cout << filePathToModel << "\n";

					model.LoadModel(filePathToModel.c_str());

				}

				else if (currentWordTemp == 1){
					x = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 2){
					y = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 3){
					z = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 4){
					rotateX = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 5){
					rotateY = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 6){
					rotateZ = (float)atof(tmpStr.c_str());
				}
				else if (currentWordTemp == 7){
					rotateW = (float)atof(tmpStr.c_str());

					//TODO: Read rotation from file
					//DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);

					DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(rotateX, -rotateY, rotateZ);
					model.Rotate(rotation);

					DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(x, y, -z);
					model.Translate(translation);

					p_objectManager->AddStaticModel(model);
				}

			}
		}
		std::cout << "\n";
	}
	levelData.clear();
	return true;
}

LevelImporter::~LevelImporter(){

}