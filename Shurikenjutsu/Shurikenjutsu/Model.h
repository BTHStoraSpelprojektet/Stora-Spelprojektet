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
	bool LoadModel(ID3D11Device* p_device, const char* p_filepath);
	ID3D11ShaderResourceView* LoadTexture(ID3D11Device* p_device, unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels);
	void Shutdown();

	void Update(double p_dt);

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	DirectX::XMMATRIX GetWorldMatrix();
	int GetVertexCount();

	void Rotate(DirectX::XMVECTOR p_rotation);
	void Translate(DirectX::XMVECTOR p_translation);
	void Scale(DirectX::XMVECTOR p_scale);
	void ResetModel();

protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	AnimationControl m_animationController;

	int m_vertexCount;
	DirectX::XMMATRIX m_worldMatrix;
};
#endif;