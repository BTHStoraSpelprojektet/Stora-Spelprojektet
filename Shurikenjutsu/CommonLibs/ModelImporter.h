#ifndef MODELIMPORTER
#define MODELIMPORTER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CommonStructures.h"

struct MeshData
{
	bool m_animated;
	std::vector<Vertex> m_vertices;
	std::vector<VertexAnimated> m_verticesAnimated;

	unsigned int m_textureMapSize[3];
	char* m_textureMap;
	unsigned int m_normalMapSize[3];
	char* m_normalMap;

	std::vector<AnimationStack> m_stacks;
	std::vector<Box> m_boundingBoxes;
	std::vector<DirectX::XMFLOAT3> m_shadowPoints;
};

class ModelImporter
{
public:
	bool ImportModel(const char* p_filepath);
	int ReadHierarchy(BoneFrame* bone, void* data, int readPosition);

	MeshData GetMesh();

private:
	MeshData m_importedMesh;
};

#endif;