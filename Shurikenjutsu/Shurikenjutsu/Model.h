#ifndef MODEL
#define MODEL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

#include "GraphicsEngine.h"
#include "Buffer.h"
#include "ConsoleFunctions.h"
#include "..\CommonLibs\ModelImporter.h"
#include "..\CommonLibs\BaseModel.h"
#include "AnimationControl.h"

class Model : public BaseModel
{
public:
	bool LoadModel(const char* p_filepath);
	ID3D11ShaderResourceView* LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels);
	void Shutdown();

	void Update();

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView* GetNormalMap();
	int GetVertexCount();

	void ResetModel();

	std::vector<Box> GetBoundingBoxes()const;
	std::vector<DirectX::XMFLOAT3> GetShadowPoints()const;
	std::vector<AnimationStack> GetAnimationStacks()const;

protected:

};
#endif;