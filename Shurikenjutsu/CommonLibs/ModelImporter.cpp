#include "ModelImporter.h"
#include <string>
#include <iostream>
#include <fstream>


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

	memcpy(&m_importedMesh.m_animated, (char*)data + readPosition, sizeof(bool));
	readPosition += sizeof(bool);

	int vertexVectorSize = 0;
	memcpy(&vertexVectorSize, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);
	
	m_importedMesh.m_frustumSphere.m_radius = 0.0f;
	m_averageVertexPosition = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
	if (!m_importedMesh.m_animated)
		for (int i = 0; i < vertexVectorSize; i++)
		{
			Vertex temp(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
			memcpy(&temp, (char*)data + readPosition, sizeof(Vertex));
			readPosition += sizeof(Vertex);

			CheckVertices(temp.m_position.x, temp.m_position.y, temp.m_position.z);

			m_importedMesh.m_vertices.push_back(temp);
		}
	else
		for (int i = 0; i < vertexVectorSize; i++)
		{
			VertexAnimated temp(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 0, 0 ,0);
			memcpy(&temp, (char*)data + readPosition, sizeof(VertexAnimated));
			readPosition += sizeof(VertexAnimated);

			CheckVertices(temp.m_position.x, temp.m_position.y, temp.m_position.z);

			m_importedMesh.m_verticesAnimated.push_back(temp);
		}

	m_averageVertexPosition.x /= vertexVectorSize;
	m_averageVertexPosition.y /= vertexVectorSize;
	m_averageVertexPosition.z /= vertexVectorSize;

	m_importedMesh.m_frustumSphere.m_position = m_averageVertexPosition;

	memcpy(&m_importedMesh.m_textureMapSize, (char*)data + readPosition, (sizeof(unsigned int)* 3));
	readPosition += (sizeof(unsigned int)* 3);
	
	m_importedMesh.m_textureMap = (char*)malloc(0);
	int combinedTextureSize = m_importedMesh.m_textureMapSize[0] * m_importedMesh.m_textureMapSize[1] * m_importedMesh.m_textureMapSize[2];
	if (combinedTextureSize > 0)
	{
		m_importedMesh.m_textureMap = (char*)realloc(m_importedMesh.m_textureMap, combinedTextureSize);
		memcpy(m_importedMesh.m_textureMap, (char*)data + readPosition, combinedTextureSize);
		readPosition += combinedTextureSize;
	}

	memcpy(&m_importedMesh.m_normalMapSize, (char*)data + readPosition, (sizeof(unsigned int)* 3));
	readPosition += (sizeof(unsigned int)* 3);

	m_importedMesh.m_normalMap = (char*)malloc(0);
	combinedTextureSize = m_importedMesh.m_normalMapSize[0] * m_importedMesh.m_normalMapSize[1] * m_importedMesh.m_normalMapSize[2];
	if (combinedTextureSize > 0)
	{
		m_importedMesh.m_normalMap = (char*)realloc(m_importedMesh.m_normalMap, combinedTextureSize);
		memcpy(m_importedMesh.m_normalMap, (char*)data + readPosition, combinedTextureSize);
		readPosition += combinedTextureSize;
	}

	//Read animation stacks from file.
	unsigned int stackCount = 0;
	memcpy(&stackCount, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);
	m_importedMesh.m_stacks.resize(stackCount);

	for (unsigned int i = 0; i < stackCount; i++)
	{
		memcpy(&m_importedMesh.m_stacks[i].m_name, (char*)data + readPosition, 64);
		readPosition += 64;

		memcpy(&m_importedMesh.m_stacks[i].m_endFrame, (char*)data + readPosition, sizeof(int));
		readPosition += sizeof(int);
		memcpy(&m_importedMesh.m_stacks[i].m_jointCount, (char*)data + readPosition, sizeof(int));
		readPosition += sizeof(int);

		for (int x = 0; x < m_importedMesh.m_stacks[i].m_endFrame - 1; x++)
		{
			BoneFrame* root = new BoneFrame;
			readPosition = ReadHierarchy(root, data, readPosition);
			m_importedMesh.m_stacks[i].m_root.push_back(root);
		}

		m_importedMesh.m_stacks[i].m_bindPoses.resize(m_importedMesh.m_stacks[i].m_jointCount);
		for (int x = 0; x < m_importedMesh.m_stacks[i].m_jointCount; x++)
		{
			memcpy(&m_importedMesh.m_stacks[i].m_bindPoses[x], (char*)data + readPosition, sizeof(BindPose));
			readPosition += sizeof(BindPose);
		}
	}

	unsigned int boundingBoxCount = 0;
	memcpy(&boundingBoxCount, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);

	if (boundingBoxCount < 10)
	{
		m_importedMesh.m_boundingBoxes.resize(boundingBoxCount);

		for (unsigned int i = 0; i < boundingBoxCount; i++)
		{
			memcpy(&m_importedMesh.m_boundingBoxes[i], (char*)data + readPosition, sizeof(Box));
			m_importedMesh.m_boundingBoxes[i].CalculateRadius();
			readPosition += sizeof(Box);
		}
	}

	unsigned int shadowVolumeCount = 0;
	memcpy(&shadowVolumeCount, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);

	if (shadowVolumeCount < 100)
	{
		m_importedMesh.m_shadowPoints.resize(shadowVolumeCount);

		for (unsigned int i = 0; i < shadowVolumeCount; i++)
		{
			memcpy(&m_importedMesh.m_shadowPoints[i], (char*)data + readPosition, (sizeof(float)* 3));
			readPosition += (sizeof(float)* 3);
		}
	}

	unsigned int boundingSphereCount = 0;
	memcpy(&boundingSphereCount, (char*)data + readPosition, sizeof(unsigned int));
	readPosition += sizeof(unsigned int);

	if (boundingSphereCount < 10)
	{
		m_importedMesh.m_boundingSpheres.resize(boundingSphereCount);

		for (unsigned int i = 0; i < boundingSphereCount; i++)
		{
			memcpy(&m_importedMesh.m_boundingSpheres[i], (char*)data + readPosition, (sizeof(Sphere)));
			readPosition += sizeof(Sphere);
		}
	}

	free(data);
	return true;
}

int ModelImporter::ReadHierarchy(BoneFrame* bone, void* data, int readPosition)
{
	memcpy(&bone->m_name, (char*)data + readPosition, 64);
	readPosition += 64;
	memcpy(&bone->m_translation, (char*)data + readPosition, (sizeof(float)* 3));
	readPosition += (sizeof(float)* 3);
	memcpy(&bone->m_quaternion, (char*)data + readPosition, (sizeof(float)* 4));
	readPosition += (sizeof(float)* 4);
	memcpy(&bone->m_orientQuaternion, (char*)data + readPosition, (sizeof(float)* 4));
	readPosition += (sizeof(float)* 4);
	memcpy(&bone->m_rotEuler, (char*)data + readPosition, (sizeof(float)* 3));
	readPosition += (sizeof(float)* 3);
	memcpy(&bone->m_scale, (char*)data + readPosition, (sizeof(double)* 3));
	readPosition += (sizeof(double)* 3);

	memcpy(&bone->m_childrenCount, (char*)data + readPosition, (sizeof(int)));
	readPosition += (sizeof(int));

	for (int y = 0; y < bone->m_childrenCount; y++)
	{
		BoneFrame* child = new BoneFrame;
		readPosition = ReadHierarchy(child, data, readPosition);
		bone->m_children.push_back(child);
	}

	return readPosition;
}

void ModelImporter::CheckVertices(float x, float y, float z)
{
	m_averageVertexPosition.x += x;
	m_averageVertexPosition.y += y;
	m_averageVertexPosition.z += z;

	if (x < 0)
	{
		x *= -1;
	}
	if (z < 0)
	{
		z *= -1;
	}

	if (m_importedMesh.m_frustumSphere.m_radius < x)
	{
		m_importedMesh.m_frustumSphere.m_radius = x;
	}
	if (m_importedMesh.m_frustumSphere.m_radius < z)
	{
		m_importedMesh.m_frustumSphere.m_radius = z;
	}	
}

MeshData ModelImporter::GetMesh()
{
	return m_importedMesh;
}