#ifndef LEVELIMPORTER_H_
#define LEVELIMPORTER_H_

#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "CommonStructures.h"
class string;

class LevelImporter
{
public:
	struct SpawnPoint
	{
		int m_team;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	struct LevelBoundingBox{
		float m_halfWidth;
		float m_halfHeight;
		float m_halfDepth;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	struct CommonObject
	{
		std::string m_filePath;
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
	};

	LevelImporter::LevelImporter(std::string p_level);
	~LevelImporter();

	void loadLevelFile();
	bool readData();
	std::vector<SpawnPoint> GetSpawnPoints();
	std::vector<Line> LevelImporter::GetShadowsShapes();
	std::vector<LevelBoundingBox> getLevelBoundingBoxes();
	std::vector<CommonObject> GetObjects();
	
protected:
	std::string m_level;
	std::vector<std::vector<std::string>> levelData;
	
	std::vector<Line> m_shadowShapes;
	std::vector<SpawnPoint> m_spawnPoints;
	std::vector<LevelBoundingBox> m_levelBoundingBoxes;
	std::vector<CommonObject> m_objects;

	std::string getObjectName(std::string &tmpStr);
	void readBoundingBox(std::string &tmpStr, int currentWordTemp, float &x, float &y, float &z, float &rotateX, float &rotateY, float &rotateZ, float &boundingBoxWidth, float &boundingBoxHeight, float &boundingBoxDepth);
	void readLevelObject(std::string &tmpStr, int currentWordTemp, bool &isParticleEmitter, bool &isSpawnPoint, int &currentTeam, bool &isShadowShape, std::string &currentShadowShape, std::string &filePathToModel, float &x, float &y, float &z, float &rotateX, float &rotateY, float &rotateZ);

	Point tmpPointA;
	Point tmpPointB;

	bool m_print = false;
};

#endif LEVELIMPORTER_H_