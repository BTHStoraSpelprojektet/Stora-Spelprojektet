#ifndef MODEL
#define MODEL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

#include "GraphicsEngine.h"
#include "Buffer.h"
#include "ConsoleFunctions.h"
#include "ModelImporter.h"
#include "AnimationControl.h"

class Model
{
public:
	bool LoadModel(const char* p_filepath);
	ID3D11ShaderResourceView* LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels);
	void Shutdown();

	void Update(double p_dt);

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView* GetNormalMap();
	int GetVertexCount();
	std::vector<DirectX::XMMATRIX> GetAnimation();

	void ResetModel();

protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	AnimationControl m_animationController;
	std::vector<DirectX::XMMATRIX> boneTransforms;

	int m_vertexCount;
	
	std::vector<Box> m_boundingBoxes;
};
#endif;