#ifndef LEVELIMPORTER_H_
#define LEVELIMPORTER_H_

#define WIN32_LEAN_AND_MEAN
#include <vector>
#include "CommonStructures.h"
#include "CommonEnums.h"
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

	struct POI
	{
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ; 
		PointOfInterestType type;
	};

	struct ParticleEmitter{
		float m_translationX;
		float m_translationY;
		float m_translationZ;
		float m_rotationX;
		float m_rotationY;
		float m_rotationZ;
		EmitterType type;
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

	struct AnimatedObject
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

	void LoadLevelFile();
	bool ReadData();
	std::vector<SpawnPoint> GetSpawnPoints();
	std::vector<Line> LevelImporter::GetShadowsShapes();
	std::vector<ParticleEmitter> LevelImporter::GetParticleEmitters();
	std::vector<LevelBoundingBox> GetLevelBoundingBoxes();
	std::vector<CommonObject> GetObjects();
	std::vector<AnimatedObject> GetAnimatedObjects();
	
protected:
	std::string m_level;
	std::vector<std::vector<std::string>> levelData;
	
	std::vector<Line> m_shadowShapes;
	std::vector<SpawnPoint> m_spawnPoints;
	std::vector<ParticleEmitter> m_particleEmitter;
	std::vector<POI> m_POIPoints;
	std::vector<LevelBoundingBox> m_levelBoundingBoxes;
	std::vector<CommonObject> m_objects;
	std::vector<AnimatedObject> m_animatedObjects;

	std::string GetObjectName(std::string &p_tmpStr);
	void ReadBoundingBox(std::string &p_tmpStr, int p_currentWordTemp, float &p_x, float &p_y, float &p_z, float &p_rotateX, float &p_rotateY, float &p_rotateZ, float &p_boundingBoxWidth, float &p_boundingBoxHeight, float &p_boundingBoxDepth);
	void ReadLevelObject(std::string &p_tmpStr, int p_currentWordTemp, bool &p_isPointOfInterest, std::string &p_pointOfInterestType, bool &p_isAnimatedObject, bool &p_isParticleEmitter, std::string &p_particleEmitterType, bool &p_isSpawnPoint, int &p_currentTeam, bool &p_isShadowShape, std::string &p_currentShadowShape, std::string &p_filePathToModel, float &p_x, float &p_y, float &p_z, float &p_rotateX, float &p_rotateY, float &p_rotateZ);

	Point tmpPointA;
	Point tmpPointB;

	bool m_print = false;
};

#endif LEVELIMPORTER_H_