#include "LevelImporter.h"

LevelImporter::LevelImporter(std::string p_level){
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

std::string LevelImporter::getObjectName(std::string &tmpStr){
	int pos = tmpStr.find_last_of('_');

	if (pos == -1)
	{
		return tmpStr.substr(0, tmpStr.size() - 1);
	}
	else
	{
		return tmpStr.substr(0, pos);
	}
}

void LevelImporter::readBoundingBox(std::string &tmpStr, int currentWordTemp, float &x, float &y, float &z, float &rotateX, float &rotateY, float &rotateZ, float &boundingBoxWidth, float &boundingBoxHeight, float &boundingBoxDepth){
	if (currentWordTemp == 0){
		std::string objectName = getObjectName(tmpStr);
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
		boundingBoxWidth = (float)atof(tmpStr.c_str());
	}
	else if (currentWordTemp == 8){
		boundingBoxHeight = (float)atof(tmpStr.c_str());
	}
	else if (currentWordTemp == 9){
		boundingBoxDepth = (float)atof(tmpStr.c_str());

		LevelBoundingBox boundingBox;
		boundingBox.m_halfWidth = boundingBoxWidth;
		boundingBox.m_halfHeight = boundingBoxHeight;
		boundingBox.m_halfDepth = boundingBoxDepth;
		boundingBox.m_translationX = x;
		boundingBox.m_translationY = y;
		boundingBox.m_translationZ = z;
		boundingBox.m_rotationX = rotateX;
		boundingBox.m_rotationY = rotateY;
		boundingBox.m_rotationZ = rotateZ;
		m_levelBoundingBoxes.push_back(boundingBox);
		if (m_print)
		{
			std::cout << boundingBoxWidth << " " << boundingBoxHeight << " " << boundingBoxDepth << " " << x << " " << y << " " << z << " " << rotateX << " " << -rotateY << " " << rotateZ << "\n";
		}

	}

}

void LevelImporter::readLevelObject(std::string &tmpStr, int currentWordTemp, bool &isSpawnPoint, std::string &filePathToModel, float &x, float &y, float &z, float &rotateX, float &rotateY, float &rotateZ){
	

	int currentTeam = 0;
	if (currentWordTemp == 0){

		std::string objectName = getObjectName(tmpStr);

		if (objectName.find("spawnPoint") != std::string::npos)
		{
			isSpawnPoint = true;
			if (m_print)
			{
				std::cout << objectName << " ";
			}
			std::string cTeam = tmpStr.substr(tmpStr.size() - 2, 1);
			currentTeam = atoi(cTeam.c_str());
			if (m_print)
			{
				std::cout << "Team: " << cTeam << " | " << "\n";
			}
		}

		else
		{
			filePathToModel.append("../Shurikenjutsu/Models/");
			filePathToModel.append(objectName);
			filePathToModel.append("Shape.SSP");

			if (m_print)
			{
				std::cout << filePathToModel << "\n";
			}
		}
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

		//TODO: Read rotation from file
		//DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(0.0f, 3.141592f / 2.0f, 0.0f);

		if (isSpawnPoint){
			SpawnPoint spawnPoint;
			spawnPoint.m_team = currentTeam;
			spawnPoint.m_translationX = x;
			spawnPoint.m_translationY = y;
			spawnPoint.m_translationZ = z;
			spawnPoint.m_rotationX = rotateX;
			spawnPoint.m_rotationY = -rotateY;
			spawnPoint.m_rotationZ = rotateZ;
			m_spawnPoints.push_back(spawnPoint);
			if (m_print)
			{
				std::cout << x << " " << y << " " << z << " " << rotateX << " " << -rotateY << " " << rotateZ << "\n";
			}
		}
		else{
			CommonObject object;
			object.m_filePath = filePathToModel.c_str();
			object.m_translationX = x;
			object.m_translationY = y;
			object.m_translationZ = -z;
			object.m_rotationX = rotateX;
			object.m_rotationY = -rotateY;
			object.m_rotationZ = rotateZ;
			m_objects.push_back(object);
			if (m_print)
			{
				std::cout << object.m_filePath << " " << x << " " << y << " " << z << " " << rotateX << " " << -rotateY << " " << rotateZ << "\n";
			}
			//DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(rotateX, -rotateY, rotateZ);
			//DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(x, y, -z);

			//object.Initialize(filePathToModel.c_str(), translation);
			//object.SetRotation(rotation);

			//p_objectManager->AddStaticObject(object);
		}
	}
}

bool LevelImporter::readData(){
	if (levelData.size() == 0){
		return false;
	}
	float x, y, z, rotateX, rotateY, rotateZ, rotateW, boundingBoxWidth, boundingBoxHeight, boundingBoxDepth;
	int numberOfBoundingBoxesToSkip = 0;
	int numberOfObjects = 0;
	int headerSize = 2;
	for (unsigned int currentLineTemp = 0; currentLineTemp < levelData.size(); currentLineTemp++)
	{
		std::string filePathToModel = "";
		std::vector<std::string> temp = levelData.at(currentLineTemp);
		if (temp.at(0).empty()){
			continue;
		}
		bool isSpawnPoint = false;
		for (unsigned int currentWordTemp = 0; currentWordTemp < temp.size(); currentWordTemp++)
		{
			std::string tmpStr = temp.at(currentWordTemp);

			if (tmpStr.empty()){
				continue;
			}

			if (currentLineTemp == 1){
				if (currentWordTemp == 3){
					numberOfObjects = atoi(tmpStr.c_str());
				}
			}
			else if (currentLineTemp == 2){
				if (currentWordTemp == 4){
					numberOfBoundingBoxesToSkip = atoi(tmpStr.c_str());
				}
			}
			else if ((currentLineTemp > 2) && (currentLineTemp < (headerSize + 1 + numberOfBoundingBoxesToSkip))){
				readBoundingBox(tmpStr, currentWordTemp, x, y, z, rotateX, rotateY, rotateZ, boundingBoxWidth, boundingBoxHeight, boundingBoxDepth);
			}
			else if (currentLineTemp > (headerSize + numberOfBoundingBoxesToSkip) && currentLineTemp < (numberOfObjects + headerSize + numberOfBoundingBoxesToSkip)){
				readLevelObject(tmpStr, currentWordTemp, isSpawnPoint, filePathToModel, x, y, z, rotateX, rotateY, rotateZ);

			}
		}
		if (m_print)
		{
			std::cout << "";
		}
	}
	levelData.clear();
	return true;
}

std::vector<LevelImporter::SpawnPoint> LevelImporter::GetSpawnPoints(){
	return m_spawnPoints;
}

std::vector<LevelImporter::LevelBoundingBox> LevelImporter::getLevelBoundingBoxes(){
	return m_levelBoundingBoxes;
}

std::vector<LevelImporter::CommonObject> LevelImporter::GetObjects()
{
	return m_objects;
}

LevelImporter::~LevelImporter(){

}