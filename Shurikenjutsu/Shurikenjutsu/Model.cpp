#include "Model.h"

bool Model::LoadModel(ID3D11Device* p_device, const char* p_filepath)
{
	// Initialize world matrix.
	m_worldMatrix = DirectX::XMMatrixIdentity();

	// Load Mesh.
	std::vector<Vertex> mesh;

	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, 1.0f, 2.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, 1.0f, 2.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, 2.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));

	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, 1.0f, 2.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, -1.0f, 2.0f), DirectX::XMFLOAT2(1.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, 2.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));

	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, 1.0f, -2.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, 1.0f, -2.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, -2.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));

	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, 1.0f, -2.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, -1.0f, -2.0f), DirectX::XMFLOAT2(1.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, -2.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));

	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f)));

	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));
	mesh.push_back(Vertex(DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f)));

	//TODO build mesh here.

	// Save mesh to buffer.
	m_mesh = Buffer::CreateBuffer(BUFFERTYPE_VERTEX, p_device, mesh);

	return true;
}

bool Model::LoadTexture(ID3D11Device* p_device, const char* p_filepath)
{
	// TODO load texture here.

	return true;
}

void Model::Shutdown()
{
	m_mesh->Release();
	m_mesh = 0;

	m_texture->Release();
	m_texture = 0;
}

void Model::Update(double p_dt)
{
	
}

ID3D11Buffer* Model::GetMesh()
{
	return m_mesh;
}

ID3D11ShaderResourceView* Model::GetTexture()
{
	return m_texture;
}

DirectX::XMMATRIX Model::GetWorldMatrix()
{
	return m_worldMatrix;
}