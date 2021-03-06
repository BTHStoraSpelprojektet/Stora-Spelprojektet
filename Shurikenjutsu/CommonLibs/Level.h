#ifndef LEVEL_H_
#define LEVEL_H_

#include "LevelImporter.h"
class string;

class Level
{
public:
	Level::Level(std::string level);
	~Level();

	bool LoadLevel(std::string p_level);
	std::vector<LevelImporter::SpawnPoint> GetSpawnPoints();
	std::vector<Line> Level::GetShadowsShapes();
	std::vector<LevelImporter::ParticleEmitter> Level::GetParticleEmitters();
	std::vector<LevelImporter::LevelBoundingBox> GetLevelBoundingBoxes();
	std::vector<LevelImporter::CommonObject> GetObjects();
	std::vector<LevelImporter::AnimatedObject> GetAnimatedObjects();
	std::vector<LevelImporter::POI> GetPOIPoints();
protected:
	int m_mapsizeX;
	int m_mapsizeY;
	std::vector<LevelImporter::SpawnPoint> m_spawnPoints;
	std::vector<Line> m_shadowShapes;
	std::vector<LevelImporter::ParticleEmitter> m_particleEmitter;
	std::vector<LevelImporter::LevelBoundingBox> m_levelBoundingBoxes;
	std::vector<LevelImporter::CommonObject> m_objects;
	std::vector<LevelImporter::AnimatedObject> m_animatedObjects;
	std::vector<LevelImporter::POI> m_POIPoints;
};

#endif LEVEL_H_