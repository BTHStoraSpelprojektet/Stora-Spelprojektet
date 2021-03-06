#ifndef BASEMODEL_H_
#define BASEMODEL_H_

#include "CommonStructures.h"
#include <d3d11.h>
#include "../CommonLibs/ModelImporter.h"

class BaseModel
{
public:
	BaseModel();
	BaseModel(BaseModel&);
	~BaseModel();

	virtual bool LoadModel(const char* p_filepath);
	virtual void Shutdown();
	void ServerShutdown();

	std::vector<Box> GetBoundingBoxes();
	std::vector<Sphere> GetBoundingSpheres();
protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	std::vector<AnimationStack> m_animationStacks;

	int m_vertexCount;

	std::vector<Line> m_shadowLines;
	std::vector<Box> m_boundingBoxes;
	std::vector<Sphere> m_boundingSpheres;
	Sphere m_frustumSphere;
	MeshData mData;
	ModelImporter* m_importer;
};

#endif