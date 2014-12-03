#include "ModelLibrary.h"

ModelLibrary* ModelLibrary::m_instance;

ModelLibrary::ModelLibrary(){}
ModelLibrary::~ModelLibrary(){}

void ModelLibrary::Initialize()
{
	// Load every model!
	std::string directoryPath = "../Shurikenjutsu/Models/";
	AddModel(directoryPath + "cubemanWnP.SSP");
	AddModel(directoryPath + "DecoratedObjectShape.SSP");
	AddModel(directoryPath + "Decorative_House_0Shape1.SSP");
	AddModel(directoryPath + "FloorShape.SSP");
	AddModel(directoryPath + "pillarShape.SSP");
	AddModel(directoryPath + "pPipeShape1.SSP");
	AddModel(directoryPath + "sakuraTreeShape.SSP");
	AddModel(directoryPath + "shurikenShape.SSP");
	AddModel(directoryPath + "StickManAnimatedShape.SSP");
}

void ModelLibrary::Shutdown()
{
	// Shutdown Models using iterator to loop through the map
	for (auto it = m_models.begin(); it != m_models.end(); it++)
	{
		it->second.Shutdown();
	}

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
	return &m_models[p_path];
}

void ModelLibrary::AddModel(std::string p_path)
{
	Model model;

	model.LoadModel(p_path.c_str());

	m_models[p_path] = model;
}