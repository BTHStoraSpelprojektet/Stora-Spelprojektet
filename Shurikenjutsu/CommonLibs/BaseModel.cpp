#include "BaseModel.h"
#include "ModelImporter.h"

BaseModel::BaseModel(){}
BaseModel::~BaseModel(){}

bool BaseModel::LoadModel(const char* p_filepath)
{
	ModelImporter importer;
	importer.ImportModel(p_filepath);

	MeshData mData = importer.GetMesh();

	m_boundingBoxes = mData.m_boundingBoxes;

	return true;
}

void BaseModel::Shutdown(){}

std::vector<Box> BaseModel::GetBoundingBoxes()
{
	return m_boundingBoxes;
}

std::vector<Sphere> BaseModel::GetBoundingSpheres()
{
	return m_boundingSpheres;
}