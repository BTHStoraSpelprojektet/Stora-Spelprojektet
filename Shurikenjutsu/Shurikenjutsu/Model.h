#ifndef MODEL
#define MODEL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

#include "..\CommonLibs\BaseModel.h"
#include "AnimationControl.h"
#include "../CommonLibs/ModelImporter.h"

class Model : public BaseModel
{
public:
	Model();
	Model(Model&);
	~Model();
	bool LoadModel(const char* p_filepath);
	ID3D11ShaderResourceView* LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels);
	void ShutdownModel();

	void Update();

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView* GetNormalMap();
	int GetVertexCount();

	void ResetModel();

	std::vector<Box> GetBoundingBoxes()const;
	std::vector<Sphere> GetBoundingSpheres()const;
	std::vector<Line> GetShadowLines()const;
	std::vector<AnimationStack> GetAnimationStacks()const;
	Sphere GetFrustumSphere()const;

protected:
	ModelImporter* importer;
};
#endif;