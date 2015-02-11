#include "BaseModel.h"
#include "ModelImporter.h"

BaseModel::BaseModel(){}
BaseModel::BaseModel(BaseModel &other){}
BaseModel::~BaseModel(){}

bool BaseModel::LoadModel(const char* p_filepath)
{
	ModelImporter importer;
	importer.ImportModel(p_filepath);

	MeshData* mData = importer.GetMesh();

	m_boundingBoxes = mData->m_boundingBoxes;
	m_boundingSpheres = mData->m_boundingSpheres;
	m_vertexCount = 0;
	free(mData->m_normalMap);
	free(mData->m_textureMap);
	importer.Shutdown();
	return true;
}

void BaseModel::Shutdown()
{
	for (unsigned int i = 0; i < m_animationStacks.size(); i++)
	{
		m_animationStacks[i].Shutdown();
	}
}

std::vector<Box> BaseModel::GetBoundingBoxes()
{
	return m_boundingBoxes;
}

std::vector<Sphere> BaseModel::GetBoundingSpheres()
{
	return m_boundingSpheres;
}