#include "Model.h"

bool Model::LoadModel(ID3D11Device* p_device, const char* p_filepath)
{
	// Initialize world matrix.
	m_worldMatrix = DirectX::XMMatrixIdentity();

	// Load Mesh.
	ModelImporter importer;
	importer.ImportModel("../Shurikenjutsu/Models/pPipeShape1.SSP");

	// Save mesh to buffer.
	m_mesh = Buffer::CreateBuffer(BUFFERTYPE_VERTEX, p_device, importer.m_importedMesh.vertices);
	m_vertexCount = importer.m_importedMesh.vertices.size();

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

int Model::GetVertexCount()
{
	return m_vertexCount;
}

void Model::Rotate(DirectX::XMVECTOR p_rotation)
{
	DirectX::XMMATRIX l_matrix = DirectX::XMMatrixRotationRollPitchYawFromVector(p_rotation);

	m_worldMatrix = m_worldMatrix * l_matrix;
}

void Model::Translate(DirectX::XMVECTOR p_translation)
{
	DirectX::XMMATRIX l_matrix = DirectX::XMMatrixTranslationFromVector(p_translation);

	m_worldMatrix = m_worldMatrix * l_matrix;
}

void Model::Scale(DirectX::XMVECTOR p_scale)
{
	DirectX::XMMATRIX l_matrix = DirectX::XMMatrixScalingFromVector(p_scale);

	m_worldMatrix = m_worldMatrix * l_matrix;
}

void Model::ResetModel()
{
	m_worldMatrix = DirectX::XMMatrixIdentity();
}