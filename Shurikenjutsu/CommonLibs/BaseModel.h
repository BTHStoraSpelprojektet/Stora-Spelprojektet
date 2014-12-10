#ifndef BASEMODEL_H_
#define BASEMODEL_H_

#include "CommonStructures.h"
#include <vector>
#include "ModelImporter.h"
#include <d3d11.h>

class BaseModel
{
public:
	BaseModel();
	~BaseModel();

	virtual bool LoadModel(const char* p_filepath);
	virtual void Shutdown();

	std::vector<Box> GetBoundingBoxes();
protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	std::vector<AnimationStack> m_animationStacks;

	int m_vertexCount;

	std::vector<DirectX::XMFLOAT3> m_shadowPoints;
	std::vector<Box> m_boundingBoxes;
};

#endif