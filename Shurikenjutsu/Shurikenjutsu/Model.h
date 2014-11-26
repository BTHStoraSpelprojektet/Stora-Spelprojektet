#ifndef MODEL
#define MODEL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

#include "GraphicsEngine.h"
#include "Buffer.h"
#include "ConsoleFunctions.h"
#include "ModelImporter.h"

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

	void Rotate(DirectX::XMFLOAT3 p_rotation);
	void Translate(DirectX::XMFLOAT3 p_translation);
	void Scale(DirectX::XMFLOAT3 p_scale);

	void SetPosition(DirectX::XMFLOAT3 p_position);
	void UpdateWorldMatrix(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_scale, DirectX::XMFLOAT3 p_rotation); 

	void ResetModel();

protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	int m_vertexCount;
	DirectX::XMFLOAT4X4 m_worldMatrix;
};
#endif;