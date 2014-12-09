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

	void Update( );

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView* GetNormalMap();
	int GetVertexCount();

	void ResetModel();

	std::vector<Box> GetBoundingBoxes();
	std::vector<AnimationStack> GetAnimationStacks();

protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	std::vector<AnimationStack> m_animationStacks;

	int m_vertexCount;
	
	std::vector<Box> m_boundingBoxes;
};
#endif;