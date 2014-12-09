#include "BoundingBoxModel.h"


BoundingBoxModel::BoundingBoxModel()
{
}


BoundingBoxModel::~BoundingBoxModel()
{
}

bool BoundingBoxModel::LoadModel(const char* p_filepath)
{
	ModelImporter importer;
	importer.ImportModel(p_filepath);

	MeshData mData = importer.GetMesh();

	m_boundingBoxes = mData.m_boundingBoxes;

	return true;
}

void BoundingBoxModel::Shutdown()
{
}

std::vector<Box> BoundingBoxModel::GetBoundingBoxes()
{
	return m_boundingBoxes;
}