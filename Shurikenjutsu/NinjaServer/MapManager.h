#ifndef MAPMANAGER_H_
#define MAPMANAGER_H_

#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"

class MapManager
{
public:
	MapManager();
	~MapManager();

	bool Initialize(std::string p_levelName);
	void Shutdown();

	std::vector<OBB> GetBoundingBoxes();	
private:
	std::vector<OBB> TransformToOBB(std::vector<Box> p_boxList, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_rotation);

	std::vector<LevelImporter::CommonObject> m_mapObjects;
	std::vector<OBB> m_boundingBoxes;
	std::vector<LevelImporter::LevelBoundingBox> m_levelBoundingBoxes;
};

#endif