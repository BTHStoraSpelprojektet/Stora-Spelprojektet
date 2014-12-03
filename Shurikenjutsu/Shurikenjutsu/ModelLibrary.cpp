#include "ModelLibrary.h"

ModelLibrary* ModelLibrary::m_instance;

ModelLibrary::ModelLibrary(){}
ModelLibrary::~ModelLibrary(){}

void ModelLibrary::Shutdown()
{
	delete m_instance;
	m_instance = nullptr;
}

ModelLibrary* ModelLibrary::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ModelLibrary();
	}

	return m_instance;
}

Model* ModelLibrary::GetModel(std::string p_path)
{
	return &m_models[p_name];
}

void ModelLibrary::AddModel(std::string p_path)
{
	m_models[p_name] = p_model;
}