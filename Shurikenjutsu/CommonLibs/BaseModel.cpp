#include "BaseModel.h"
#include "ModelImporter.h"

BaseModel::BaseModel(){}
BaseModel::BaseModel(BaseModel &other){}
BaseModel::~BaseModel(){}

bool BaseModel::LoadModel(const char* p_filepath)
{
	m_importer = new ModelImporter();
	m_importer->ImportModel(p_filepath);
	mData = m_importer->GetMesh();

	m_boundingBoxes = mData.m_boundingBoxes;
	m_boundingSpheres = mData.m_boundingSpheres;
	m_vertexCount = 0;
	free(mData.m_normalMap);
	free(mData.m_textureMap);

	mData.Shutdown();
	return true;
}

void BaseModel::Shutdown()
{
	for (unsigned int i = 0; i < m_animationStacks.size(); i++)
	{
		m_animationStacks[i].Shutdown();
	}
}

void BaseModel::ServerShutdown()
{
	if (m_importer != nullptr)
	{
		delete m_importer;
		m_importer = nullptr;
	}

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