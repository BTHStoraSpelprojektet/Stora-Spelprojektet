#include "MapManager.h"

MapManager::MapManager(){}
MapManager::~MapManager(){}

bool MapManager::Initialize(std::string p_levelName)
{
	Level level(p_levelName);

	m_boundingBoxes = std::vector<OBB>();
	m_boundingSpheres = std::vector<Sphere>();
	m_mapObjects = level.GetObjects();
	m_mapAnimatedObjects = level.GetAnimatedObjects();
	m_levelBoundingBoxes = level.GetLevelBoundingBoxes();

	for each (LevelImporter::CommonObject mapObject in m_mapObjects)
	{
		DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(mapObject.m_translationX, mapObject.m_translationY, mapObject.m_translationZ);
		DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(mapObject.m_rotationX, mapObject.m_rotationY, mapObject.m_rotationZ);


		std::vector<Sphere> boundingSpheres = ModelLibrary::GetInstance()->GetModel(mapObject.m_filePath)->GetBoundingSpheres();
		std::vector<Sphere> sphereList = TransformToSphere(boundingSpheres, position, rotation);
		for each(Sphere sphere in sphereList)
		{
			Sphere tmp;
			tmp.m_position = DirectX::XMFLOAT3(sphere.m_position.x + (mapObject.m_translationX * mapObject.m_rotationX), sphere.m_position.y + (mapObject.m_translationY * mapObject.m_rotationY), sphere.m_position.z + (mapObject.m_translationZ * mapObject.m_rotationZ));
			tmp.m_radius = sphere.m_radius;
			m_boundingSpheres.push_back(tmp);
		}

		std::vector<Box> boundingBoxes = ModelLibrary::GetInstance()->GetModel(mapObject.m_filePath)->GetBoundingBoxes();
		std::vector<OBB> obbList = TransformToOBB(boundingBoxes, position, rotation);
		for each(OBB box in obbList)
		{
			m_boundingBoxes.push_back(box);
		}
	}

	for each(LevelImporter::AnimatedObject mapAnimatedObject in m_mapAnimatedObjects)
	{
		DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(mapAnimatedObject.m_translationX, mapAnimatedObject.m_translationY, mapAnimatedObject.m_translationZ);
		DirectX::XMFLOAT3 rotation = DirectX::XMFLOAT3(mapAnimatedObject.m_rotationX, mapAnimatedObject.m_rotationY, mapAnimatedObject.m_rotationZ);


		std::vector<Sphere> boundingSpheres = ModelLibrary::GetInstance()->GetInstance()->GetModel(mapAnimatedObject.m_filePath)->GetBoundingSpheres();
		std::vector<Sphere> sphereList = TransformToSphere(boundingSpheres, position, rotation);
		for each(Sphere sphere in sphereList)
		{
			Sphere tmp;
			tmp.m_position = DirectX::XMFLOAT3(sphere.m_position.x + (mapAnimatedObject.m_translationX * mapAnimatedObject.m_rotationX), sphere.m_position.y + (mapAnimatedObject.m_translationY * mapAnimatedObject.m_rotationY), sphere.m_position.z + (mapAnimatedObject.m_translationZ * mapAnimatedObject.m_rotationZ));
			tmp.m_radius = sphere.m_radius;
			m_boundingSpheres.push_back(tmp);
		}

		std::vector<Box> boundingBoxes = ModelLibrary::GetInstance()->GetModel(mapAnimatedObject.m_filePath)->GetBoundingBoxes();
		std::vector<OBB> obbList = TransformToOBB(boundingBoxes, position, rotation);
		for each(OBB box in obbList)
		{
			m_boundingBoxes.push_back(box);
		}
	}

	for each(LevelImporter::LevelBoundingBox levelBoundingBox in m_levelBoundingBoxes)
	{
		OBB boundingBox = OBB(levelBoundingBox.m_translationX, levelBoundingBox.m_translationY, levelBoundingBox.m_translationZ, levelBoundingBox.m_halfDepth,  levelBoundingBox.m_halfHeight, levelBoundingBox.m_halfWidth, DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
		

		m_boundingBoxes.push_back(boundingBox);
	}

	return true;
}

void MapManager::Shutdown()
{
}

std::vector<OBB> MapManager::GetBoundingBoxes()
{
	return m_boundingBoxes;
}

std::vector<Sphere> MapManager::GetBoundingSpheres()
{
	return m_boundingSpheres;
}

std::vector<OBB> MapManager::TransformToOBB(std::vector<Box> p_boxList, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_rotation)
{
	std::vector<OBB> obbList = std::vector<OBB>();

	DirectX::XMFLOAT4X4 world; 
	DirectX::XMFLOAT3 scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f); // scale = 1?

	DirectX::XMStoreFloat4x4(&world,	DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&scale)) *
										DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation)) *
										DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_position)));

	DirectX::XMFLOAT4 orientation;
	DirectX::XMStoreFloat4(&orientation, DirectX::XMQuaternionRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation)));

	for each(Box box in p_boxList)
	{
		OBB temp;
		temp.m_center = box.m_center;
		DirectX::XMFLOAT4 center = DirectX::XMFLOAT4(temp.m_center.x, temp.m_center.y, temp.m_center.z, 1.0f);
		DirectX::XMVECTOR transCenter = DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&center), DirectX::XMLoadFloat4x4(&world));
		DirectX::XMStoreFloat3(&temp.m_center, transCenter);
		temp.m_extents = box.m_extents;
		temp.m_direction = orientation;
		temp.CalculateRadius();

		obbList.push_back(temp);
	}

	return obbList;
}

std::vector<Sphere> MapManager::TransformToSphere(std::vector<Sphere> p_sphereInList, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_rotation)
{
	std::vector<Sphere> sphereOutList = std::vector<Sphere>();

	DirectX::XMFLOAT4X4 world;
	DirectX::XMFLOAT3 scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f); // scale = 1?

	DirectX::XMStoreFloat4x4(&world, DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&scale)) *
		DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation)) *
		DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_position)));

	DirectX::XMFLOAT4 orientation;
	DirectX::XMStoreFloat4(&orientation, DirectX::XMQuaternionRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation)));

	for each(Sphere sphere in p_sphereInList)
	{
		Sphere temp;
		temp.m_position = sphere.m_position;
		DirectX::XMFLOAT4 center = DirectX::XMFLOAT4(temp.m_position.x, temp.m_position.y, temp.m_position.z, 1.0f);
		DirectX::XMVECTOR transCenter = DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&center), DirectX::XMLoadFloat4x4(&world));
		DirectX::XMStoreFloat3(&temp.m_position, transCenter);
		temp.m_radius = sphere.m_radius;

		sphereOutList.push_back(temp);
	}

	return sphereOutList;
}