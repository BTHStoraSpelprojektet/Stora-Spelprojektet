#include "Model.h"

bool Model::LoadModel(const char* p_filepath)
{
	// Initialize world matrix.
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());

	// Load Mesh.
	ModelImporter importer;
	importer.ImportModel(p_filepath);
	
	MeshData mData = importer.GetMesh();

	// Save mesh to buffer.
	if (!mData.m_animated)
	{
		std::vector<VertexAnimated> nullVector;
		m_mesh = Buffer::CreateBuffer(BUFFERTYPE_VERTEX, GraphicsEngine::GetDevice(), mData.m_vertices, nullVector);
		m_vertexCount = mData.m_vertices.size();
	}
	else
	{
		std::vector<Vertex> nullVector;
		m_mesh = Buffer::CreateBuffer(BUFFERTYPE_VERTEXANIMATED, GraphicsEngine::GetDevice(), nullVector, mData.m_verticesAnimated);
		m_vertexCount = mData.m_verticesAnimated.size();
	}

	// Load Textures
	m_texture = LoadTexture(mData.m_textureMapSize[0], mData.m_textureMapSize[1], mData.m_textureMapSize[2], mData.m_textureMap);
	m_normalMap = LoadTexture(mData.m_normalMapSize[0], mData.m_normalMapSize[1], mData.m_normalMapSize[2], mData.m_normalMap);

	// Store animation stacks
	for (unsigned int i = 0; i < mData.m_stacks.size(); i++)
	{
		m_animationController.CreateNewStack(mData.m_stacks[i]);
	}

	// Store bounding box
	m_boundingBoxes = mData.m_boundingBoxes;

	free(mData.m_textureMap);
	free(mData.m_normalMap);

	return true;
}

ID3D11ShaderResourceView* Model::LoadTexture(unsigned int p_width, unsigned int p_height, unsigned int p_depth, char* p_pixels)
{
	ID3D11ShaderResourceView* textureSRV = NULL;

	int combinedSize = p_width * p_height * p_depth;
	if (combinedSize > 0)
	{
	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.Width = p_width;
	textureDesc.Height = p_height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA data;
	data.pSysMem = (void*)p_pixels;
	data.SysMemPitch = p_width * 4;
	data.SysMemSlicePitch = 0;

	ID3D11Texture2D* texture;
	GraphicsEngine::GetDevice()->CreateTexture2D(&textureDesc, &data, &texture);

	D3D11_SHADER_RESOURCE_VIEW_DESC sRVDesc;
	sRVDesc.Format = textureDesc.Format;
	sRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	sRVDesc.Texture2D.MipLevels = textureDesc.MipLevels;
	sRVDesc.Texture2D.MostDetailedMip = 0;
	GraphicsEngine::GetDevice()->CreateShaderResourceView(texture, &sRVDesc, &textureSRV);
	}

	return textureSRV;
}

void Model::Shutdown()
{
	m_mesh->Release();
	m_mesh = 0;

	m_texture->Release();
	m_texture = 0;

	m_normalMap->Release();
	m_normalMap = 0;
}

void Model::Update(double p_dt)
{
	if (m_animationController.IsAnimated())
	{
		boneTransforms = m_animationController.UpdateAnimation(p_dt);
	
}
}

ID3D11Buffer* Model::GetMesh()
{
	return m_mesh;
}

ID3D11ShaderResourceView* Model::GetTexture()
{
	return m_texture;
}

ID3D11ShaderResourceView* Model::GetNormalMap()
{
	return m_normalMap;
}

DirectX::XMFLOAT4X4 Model::GetWorldMatrix()
{
	return m_worldMatrix;
}

int Model::GetVertexCount()
{
	return m_vertexCount;
}

std::vector<DirectX::XMMATRIX> Model::GetAnimation()
{
	return boneTransforms;
}

void Model::Rotate(DirectX::XMFLOAT3 p_rotation)
{
	DirectX::XMMATRIX matrix = DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation));

	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMLoadFloat4x4(&m_worldMatrix) * matrix);
}

void Model::Translate(DirectX::XMFLOAT3 p_translation)
{
	DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_translation));

	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMLoadFloat4x4(&m_worldMatrix) * matrix);
}

void Model::Scale(DirectX::XMFLOAT3 p_scale)
{
	DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_scale));

	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMLoadFloat4x4(&m_worldMatrix) * matrix);
}

void Model::ResetModel()
{
	DirectX::XMStoreFloat4x4(&m_worldMatrix,DirectX::XMMatrixIdentity());
}

void Model::SetPosition(DirectX::XMFLOAT3 p_position)
{
	DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_position));

	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMLoadFloat4x4(&m_worldMatrix) * matrix);
}

void Model::UpdateWorldMatrix(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_scale, DirectX::XMFLOAT3 p_rotation)
{
	DirectX::XMMATRIX matrix =	DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&p_scale)) *
								DirectX::XMMatrixRotationRollPitchYawFromVector(DirectX::XMLoadFloat3(&p_rotation)) *
								DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&p_position));
								
	DirectX::XMStoreFloat4x4(&m_worldMatrix, matrix);
}

std::vector<Box> Model::GetBoundingBoxes()
{
	return m_boundingBoxes;
}