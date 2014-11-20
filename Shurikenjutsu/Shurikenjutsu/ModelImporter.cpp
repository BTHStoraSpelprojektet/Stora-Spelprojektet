#include "ModelImporter.h"

bool ModelImporter::ImportModel(const char* p_filepath)
{
	//Import Mesh
	std::ifstream inputFile;
	inputFile.open(p_filepath, std::ios::binary);

	inputFile.seekg(0, std::ios::end);
	long fileSize = (long)inputFile.tellg();
	inputFile.seekg(0);

	void* data = malloc(fileSize);
	inputFile.read((char*)data, fileSize);
	inputFile.close();


	int readPosition = 0;
	readPosition += sizeof(int);
	readPosition += 64;
	readPosition += (sizeof(float) * 16);

	memcpy(&m_importedMesh.animated, (char*)data + readPosition, sizeof(bool));
	readPosition += sizeof(bool);

	int vertexVectorSize = 0;
	memcpy(&vertexVectorSize, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);
	
	for (int i = 0; i < vertexVectorSize; i++)
	{
		Vertex temp(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
		memcpy(&temp, (char*)data + readPosition, sizeof(Vertex));
		readPosition += sizeof(Vertex);
		m_importedMesh.vertices.push_back(temp);
	}

	memcpy(&m_importedMesh.textureMapSize, (char*)data + readPosition, (sizeof(unsigned int)* 3));
	readPosition += (sizeof(unsigned int)* 3);
	
	m_importedMesh.textureMap = (char*)malloc(0);
	int combinedTextureSize = m_importedMesh.textureMapSize[0] * m_importedMesh.textureMapSize[1] * m_importedMesh.textureMapSize[2];
	if (combinedTextureSize > 0)
	{
		m_importedMesh.textureMap = (char*)realloc(m_importedMesh.textureMap, combinedTextureSize);
		memcpy(m_importedMesh.textureMap, (char*)data + readPosition, combinedTextureSize);
		readPosition += combinedTextureSize;
	}

	free(data);
	return true;
}

MeshData ModelImporter::GetMesh()
{
	return m_importedMesh;
}