#ifndef MODELLIBRARY_H_
#define MODELLIBRARY_H_

#include "Model.h"
#include <unordered_map>
#include <string>

class ModelLibrary
{
public:
	ModelLibrary(const ModelLibrary&) = delete;
	ModelLibrary& operator=(const ModelLibrary&) = delete;
	
	void Initialize();
	void Shutdown();

	static ModelLibrary* GetInstance();

	Model* ModelLibrary::GetModel(std::string p_path);
	

private:
	void AddModel(std::string p_path);

	static ModelLibrary* m_instance;

	ModelLibrary();
	~ModelLibrary();

	std::unordered_map<std::string, Model> m_models;
};

#endif // !MODELLIBRARY_H_