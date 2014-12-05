#include "ModelLibrary.h"

ModelLibrary* ModelLibrary::m_instance;

ModelLibrary::ModelLibrary(){}
ModelLibrary::~ModelLibrary(){}

void ModelLibrary::Initialize()
{
	// Load every model!
	LoadModelDirectory();
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

void ModelLibrary::LoadModelDirectory()
{

	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

		
	// Find the first file in the directory.
	hFind = FindFirstFile("../Shurikenjutsu/Models/*", &ffd);

	// Skip the ".." file
	FindNextFile(hFind, &ffd);

	// Relevant files
	while (FindNextFile(hFind, &ffd) != 0)
	{
		AddModel("../Shurikenjutsu/Models/" + (std::string)ffd.cFileName);
		std::cout << "ModelLibrary: " << ffd.cFileName << " loaded"<< std::endl;
	}
	
	std::cout << std::endl;

	FindClose(hFind);
}