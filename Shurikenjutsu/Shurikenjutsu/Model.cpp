#include "Model.h"

bool Model::LoadModel(ID3D11Device* p_device, const char* p_filepath)
{
	// Initialize world matrix.
	m_worldMatrix = DirectX::XMMatrixIdentity();

	// Load Mesh.
	ModelImporter importer;
	importer.ImportModel("../Shurikenjutsu/Models/pPipeShape1.SSP");
	
	MeshData mData = importer.GetMesh();
	//TODO build mesh here.

	// Save mesh to buffer.
	m_mesh = Buffer::CreateBuffer(BUFFERTYPE_VERTEX, p_device, mData.vertices);
	m_vertexCount = mData.vertices.size();

	LoadTexture(p_device, mData.textureMapSize, mData.textureMap);

	return true;
}

bool Model::LoadTexture(ID3D11Device* p_device, unsigned int p_mapSize[3], char* p_pixels)
{
	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.Width = p_mapSize[0];
	textureDesc.Height = p_mapSize[1];
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
	data.SysMemPitch = p_mapSize[0] * 4;
	data.SysMemSlicePitch = 0;

	ID3D11Texture2D* texture;
	p_device->CreateTexture2D(&textureDesc, &data, &texture);

	D3D11_SHADER_RESOURCE_VIEW_DESC sRVDesc;
	sRVDesc.Format = textureDesc.Format;
	sRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	sRVDesc.Texture2D.MipLevels = textureDesc.MipLevels;
	sRVDesc.Texture2D.MostDetailedMip = 0;
	p_device->CreateShaderResourceView(texture, &sRVDesc, &m_texture);

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