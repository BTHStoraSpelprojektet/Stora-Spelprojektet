#ifndef MODELLIBRARY_H_
#define MODELLIBRARY_H_

#include <windows.h>
#include <unordered_map>
class string;
#include "BaseModel.h"

class ModelLibrary
{
public:
	ModelLibrary(const ModelLibrary&) = delete;
	ModelLibrary& operator=(const ModelLibrary&) = delete;
	
	void Initialize(BaseModel *p_modelTypes);
	void Shutdown();

	static ModelLibrary* GetInstance();

	BaseModel* ModelLibrary::GetModel(std::string p_path);
	

private:
	void AddModel(std::string p_path, BaseModel *p_modelTypes);
	void LoadModelDirectory(BaseModel *p_modelTypes);

	static ModelLibrary* m_instance;

	ModelLibrary();
	~ModelLibrary();

	std::unordered_map<std::string, BaseModel> m_models;
};

#endif // !MODELLIBRARY_H_