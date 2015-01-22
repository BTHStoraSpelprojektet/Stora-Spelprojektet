#ifndef MODELIMPORTER
#define MODELIMPORTER


#include "CommonStructures.h"
class string;

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
	std::vector<Sphere> m_boundingSpheres;
	std::vector<DirectX::XMFLOAT3> m_shadowPoints;
	Sphere m_frustumSphere;
};

class ModelImporter
{
public:
	bool ImportModel(const char* p_filepath);
	int ReadHierarchy(BoneFrame* bone, void* data, int readPosition);

	MeshData GetMesh();

private:
	void CheckVertices(float x, float y, float z);

	DirectX::XMFLOAT3 m_averageVertexPosition;
	MeshData m_importedMesh;
};

#endif;