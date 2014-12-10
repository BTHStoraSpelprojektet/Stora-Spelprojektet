#include "MapManager.h"


MapManager::MapManager()
{
}


MapManager::~MapManager()
{
}

bool MapManager::Initialize(std::string p_levelName)
{
	Level level(p_levelName);

	m_boundingBoxes = std::vector<Box>();
	m_mapObjects = level.GetObjects();
	m_levelBoundingBoxes = level.getLevelBoundingBoxes();

	for each (LevelImporter::CommonObject mapObject in m_mapObjects)
	{
		std::vector<Box> boundingBoxes = ModelLibrary::GetInstance()->GetModel(mapObject.m_filePath)->GetBoundingBoxes();

		for each(Box boundingBox in boundingBoxes)
		{
			boundingBox.m_center.x += mapObject.m_translationX;
			boundingBox.m_center.y += mapObject.m_translationY;
			boundingBox.m_center.z += mapObject.m_translationZ;
			m_boundingBoxes.push_back(boundingBox);
		}
	}

	for each(LevelImporter::LevelBoundingBox levelBoundingBox in m_levelBoundingBoxes)
	{
		Box boundingBox = Box(levelBoundingBox.m_translationX, levelBoundingBox.m_translationY, levelBoundingBox.m_translationZ, 2 * levelBoundingBox.m_halfWidth, 2 * levelBoundingBox.m_halfHeight, 2 * levelBoundingBox.m_halfDepth);

		//m_boundingBoxes.push_back(boundingBox);
	}

	return true;
}

void MapManager::Shutdown()
{
}

std::vector<Box> MapManager::GetBoundingBoxes()
{
	return m_boundingBoxes;
}