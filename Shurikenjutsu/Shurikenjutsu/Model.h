#ifndef MODEL
#define MODEL

#include <d3d11.h>
#include <DirectXMath.h>
#include <string>

#include "GraphicsEngine.h"
#include "Buffer.h"
#include "ConsoleFunctions.h"

class Model
{
public:
	bool LoadModel(ID3D11Device* p_device, const char* p_filepath);
	bool LoadTexture(ID3D11Device* p_device, const char* p_filepath);
	void Shutdown();

	void Update(double p_dt);

	ID3D11Buffer* GetMesh();
	ID3D11ShaderResourceView* GetTexture();
	DirectX::XMMATRIX GetWorldMatrix();

protected:
	ID3D11Buffer* m_mesh;
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_normalMap;

	DirectX::XMMATRIX m_worldMatrix;
};
#endif;