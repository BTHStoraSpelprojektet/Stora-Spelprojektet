#ifndef MODELLIBRARY_H_
#define MODELLIBRARY_H_

#include "Model.h"
#include "ModelImporter.h"
#include <unordered_map>
#include <string>

class ModelLibrary
{
public:
	ModelLibrary(const ModelLibrary&) = delete;
	ModelLibrary& operator=(const ModelLibrary&) = delete;

	void Shutdown();

	static ModelLibrary* GetInstance();

	Model* GetModel(std::string p_path);
	void AddModel(std::string p_path);

private:
	static ModelLibrary* m_instance;

	ModelLibrary();
	~ModelLibrary();

	std::unordered_map<std::string, Model> m_models;

};

#endif // !MODELLIBRARY_H_