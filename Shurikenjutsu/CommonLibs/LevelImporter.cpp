#include "LevelImporter.h"

#include <fstream>
#include <sstream>
#include <iostream>

LevelImporter::LevelImporter(std::string p_level){
	m_level = p_level;
}

void LevelImporter::LoadLevelFile(){
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

std::string LevelImporter::GetObjectName(std::string &p_tmpStr){
	int pos = p_tmpStr.find_last_of('_');

	if (pos == -1)
	{
		return p_tmpStr.substr(0, p_tmpStr.size() - 1);
	}
	else
	{
		return p_tmpStr.substr(0, pos);
	}
}

void LevelImporter::ReadBoundingBox(std::string &p_tmpStr, int p_currentWordTemp, float &p_x, float &p_y, float &p_z, float &p_rotateX, float &p_rotateY, float &p_rotateZ, float &p_boundingBoxWidth, float &p_boundingBoxHeight, float &p_boundingBoxDepth){
	if (p_currentWordTemp == 0){
		std::string objectName = GetObjectName(p_tmpStr);
	}
	else if (p_currentWordTemp == 1){
		p_x = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 2){
		p_y = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 3){
		p_z = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 4){
		p_rotateX = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 5){
		p_rotateY = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 6){
		p_rotateZ = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 7){
		p_boundingBoxWidth = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 8){
		p_boundingBoxHeight = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 9){
		p_boundingBoxDepth = (float)atof(p_tmpStr.c_str());

		LevelBoundingBox boundingBox;
		boundingBox.m_halfWidth = p_boundingBoxWidth;
		boundingBox.m_halfHeight = p_boundingBoxHeight;
		boundingBox.m_halfDepth = p_boundingBoxDepth;
		boundingBox.m_translationX = p_x;
		boundingBox.m_translationY = p_y;
		boundingBox.m_translationZ = p_z;
		boundingBox.m_rotationX = p_rotateX;
		boundingBox.m_rotationY = p_rotateY;
		boundingBox.m_rotationZ = p_rotateZ;
		m_levelBoundingBoxes.push_back(boundingBox);
		if (m_print)
		{
			std::cout << p_boundingBoxWidth << " " << p_boundingBoxHeight << " " << p_boundingBoxDepth << " " << p_x << " " << p_y << " " << p_z << " " << p_rotateX << " " << -p_rotateY << " " << p_rotateZ << "\n";
		}

	}

}

void LevelImporter::ReadLevelObject(std::string &p_tmpStr, int p_currentWordTemp, bool &p_isPointOfInterest, std::string &p_pointOfInterestType, bool &p_isAnimatedObject, bool &p_isParticleEmitter, std::string &p_particleEmitterType, bool &p_isSpawnPoint, int &p_currentTeam, bool &p_isShadowShape, std::string &p_currentShadowShape, std::string &p_filePathToModel, float &p_x, float &p_y, float &p_z, float &p_rotateX, float &p_rotateY, float &p_rotateZ){


	if (p_currentWordTemp == 0){

		std::string objectName = GetObjectName(p_tmpStr);

		if (objectName.find("spawnPoint") != std::string::npos)
		{
			p_isSpawnPoint = true;
			if (m_print)
			{
				std::cout << objectName << " ";
			}
			std::string cTeam = p_tmpStr.substr(p_tmpStr.size() - 2, 1);
			p_currentTeam = atoi(cTeam.c_str());
			if (m_print)
			{
				std::cout << "Team: " << cTeam << " | " << "\n";
			}
		}
		else if (objectName.find("ShadowShapes") != std::string::npos)
		{
			p_isShadowShape = true;

			//char * c = new char[objectName.size() + 1];
			p_currentShadowShape.resize(p_tmpStr.size());
			memcpy(&p_currentShadowShape[0], p_tmpStr.c_str(), p_tmpStr.size());

			//c[objectName.size()] = '\0';
			std::cout << "";
			//currentShadowShape = c;
		}
		else if (objectName.find("ParticleEmitter") != std::string::npos){
			p_isParticleEmitter = true;
			p_particleEmitterType = p_tmpStr.substr(16, p_tmpStr.size());
		}
		else if (objectName.find("POI") != std::string::npos){
			p_isPointOfInterest = true;
			p_particleEmitterType = p_tmpStr.substr(4, p_tmpStr.size());
		}
		else
		{
			if (objectName.find("Animated") != std::string::npos){
				p_isAnimatedObject = true;
				objectName = objectName.substr(0, objectName.size() - 9);
			}

			p_filePathToModel.append("../Shurikenjutsu/Models/");
			p_filePathToModel.append(objectName);
			p_filePathToModel.append("Shape.SSP");

			if (m_print)
			{
				std::cout << p_filePathToModel << "\n";
			}
		}
	}

	else if (p_currentWordTemp == 1){
		p_x = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 2){
		p_y = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 3){
		p_z = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 4){
		p_rotateX = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 5){
		p_rotateY = (float)atof(p_tmpStr.c_str());
	}
	else if (p_currentWordTemp == 6){
		p_rotateZ = (float)atof(p_tmpStr.c_str());

		if (p_isSpawnPoint){
			SpawnPoint spawnPoint;
			spawnPoint.m_team = p_currentTeam;
			spawnPoint.m_translationX = p_x;
			spawnPoint.m_translationY = p_y;
			spawnPoint.m_translationZ = -p_z;
			spawnPoint.m_rotationX = p_rotateX;
			spawnPoint.m_rotationY = -p_rotateY;
			spawnPoint.m_rotationZ = p_rotateZ;
			m_spawnPoints.push_back(spawnPoint);
			if (m_print)
			{
				std::cout << p_x << " " << p_y << " " << p_z << " " << p_rotateX << " " << -p_rotateY << " " << p_rotateZ << "\n";
			}
		}
		else if (p_isShadowShape){
			if (m_print){
				std::cout << ">>" << p_currentShadowShape.substr(p_currentShadowShape.length() - 2, 1).c_str() << "\n";
			}
			if (strcmp(p_currentShadowShape.substr(p_currentShadowShape.length() - 2, 1).c_str(), "A") == 0){
				tmpPointA.x = p_x;
				tmpPointA.y = -p_z;

			}
			else if (strcmp(p_currentShadowShape.substr(p_currentShadowShape.length() - 2, 1).c_str(), "B") == 0){
				tmpPointB.x = p_x;
				tmpPointB.y = -p_z;

				Line ShadowShapeLine;
				ShadowShapeLine.a = tmpPointA;
				ShadowShapeLine.b = tmpPointB;
				m_shadowShapes.push_back(ShadowShapeLine);
			}
		}
		else if (p_isParticleEmitter){
			ParticleEmitter particleEmitter;

			particleEmitter.m_translationX = p_x;
			particleEmitter.m_translationY = p_y;
			particleEmitter.m_translationZ = -p_z;
			particleEmitter.m_rotationX = p_rotateX;
			particleEmitter.m_rotationY = -p_rotateY;
			particleEmitter.m_rotationZ = p_rotateZ;

			if (p_particleEmitterType.find("BrazierFire") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_BrazierFire;
			}
			else if (p_particleEmitterType.find("BrazierSparks") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_FireSpark;
			}
			else if (p_particleEmitterType.find("Smoke") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_Smoke;
			}
			else if (p_particleEmitterType.find("LeafTree") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_LeafTree;
			}
			else if (p_particleEmitterType.find("LeafSakura") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_LeafSakura;
			}
			else if (p_particleEmitterType.find("LeafAcerPalmatum") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_LeafAcerPalmatum;
			}
			else if (p_particleEmitterType.find("WorldMist") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_WorldMist;
			}
			else if (p_particleEmitterType.find("WorldDust") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_WorldDust;
			}
			else if (p_particleEmitterType.find("Fireflies") != std::string::npos){
				particleEmitter.type = EmitterType::EmitterType_Fireflies;
			}
			else{
				//Set a defualt type
				particleEmitter.type = EmitterType::EmitterType_Smoke;
			}

			m_particleEmitter.push_back(particleEmitter);
		}
		else if (p_isPointOfInterest){
			POI poi;

			poi.m_translationX = p_x;
			poi.m_translationY = p_y;
			poi.m_translationZ = -p_z;
			poi.m_rotationX = p_rotateX;
			poi.m_rotationY = -p_rotateY;
			poi.m_rotationZ = p_rotateZ;

			if (p_particleEmitterType.find("Heal") != std::string::npos){
				poi.type = PointOfInterestType::PointOfInterestType_Heal;
			}
			else if (p_particleEmitterType.find("Invisible") != std::string::npos){
				poi.type = PointOfInterestType::PointOfInterestType_Invisible;
			}
			else if (p_particleEmitterType.find("Shield") != std::string::npos){
				poi.type = PointOfInterestType::PointOfInterestType_Shield;
			}

			m_POIPoints.push_back(poi);
		}
		else{
			if (p_isAnimatedObject){
				AnimatedObject animatedObject;
				animatedObject.m_filePath = p_filePathToModel.c_str();
				animatedObject.m_translationX = p_x;
				animatedObject.m_translationY = p_y;
				animatedObject.m_translationZ = -p_z;
				animatedObject.m_rotationX = p_rotateX;
				animatedObject.m_rotationY = -p_rotateY;
				animatedObject.m_rotationZ = p_rotateZ;
				m_animatedObjects.push_back(animatedObject);
				if (m_print)
				{
					std::cout << animatedObject.m_filePath << " " << p_x << " " << p_y << " " << p_z << " " << p_rotateX << " " << -p_rotateY << " " << p_rotateZ << "\n";
				}
			}
			else{
				CommonObject object;
				object.m_filePath = p_filePathToModel.c_str();
				object.m_translationX = p_x;
				object.m_translationY = p_y;
				object.m_translationZ = -p_z;
				object.m_rotationX = p_rotateX;
				object.m_rotationY = -p_rotateY;
				object.m_rotationZ = p_rotateZ;
				m_objects.push_back(object);
				if (m_print)
				{
					std::cout << object.m_filePath << " " << p_x << " " << p_y << " " << p_z << " " << p_rotateX << " " << -p_rotateY << " " << p_rotateZ << "\n";
				}
				//DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(rotateX, -rotateY, rotateZ);
				//DirectX::XMFLOAT3 translation = DirectX::XMFLOAT3(x, y, -z);

				//object.Initialize(filePathToModel.c_str(), translation);
				//object.SetRotation(rotation);

				//p_objectManager->AddStaticObject(object);
			}
		}
	}
}

bool LevelImporter::ReadData(){
	if (levelData.size() == 0){
		return false;
	}
	float x, y, z, rotateX, rotateY, rotateZ, /*rotateW,*/ boundingBoxWidth, boundingBoxHeight, boundingBoxDepth;
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
		bool isShadowShape = false;
		bool isParticleEmitter = false;
		bool isPointOfInterest = false;
		bool isAnimatedObject = false;
		int currentTeam = 0;
		std::string currentShadowShape = "";
		std::string particleEmitterType = "";
		std::string pointOfinterestType = "";
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

			else if ((currentLineTemp > 2) && (currentLineTemp < (unsigned int)(headerSize + 1 + numberOfBoundingBoxesToSkip)))
			{
				ReadBoundingBox(tmpStr, currentWordTemp, x, y, z, rotateX, rotateY, rotateZ, boundingBoxWidth, boundingBoxHeight, boundingBoxDepth);
			}

			else if (currentLineTemp >(unsigned int)(headerSize + numberOfBoundingBoxesToSkip) && currentLineTemp < (unsigned int)(numberOfObjects + headerSize + numberOfBoundingBoxesToSkip))
			{
				ReadLevelObject(tmpStr, currentWordTemp, isPointOfInterest, pointOfinterestType, isAnimatedObject, isParticleEmitter, particleEmitterType, isSpawnPoint, currentTeam, isShadowShape, currentShadowShape, filePathToModel, x, y, z, rotateX, rotateY, rotateZ);
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

std::vector<LevelImporter::POI> LevelImporter::GetPOIPoints()
{
	return m_POIPoints;
}

std::vector<Line> LevelImporter::GetShadowsShapes(){
	return m_shadowShapes;
}

std::vector<LevelImporter::ParticleEmitter> LevelImporter::GetParticleEmitters(){
	return m_particleEmitter;
}

std::vector<LevelImporter::LevelBoundingBox> LevelImporter::GetLevelBoundingBoxes(){
	return m_levelBoundingBoxes;
}

std::vector<LevelImporter::CommonObject> LevelImporter::GetObjects()
{
	return m_objects;
}

std::vector<LevelImporter::AnimatedObject> LevelImporter::GetAnimatedObjects()
{
	return m_animatedObjects;
}


LevelImporter::~LevelImporter(){

}