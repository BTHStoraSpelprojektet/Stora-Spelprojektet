#ifndef MODELIMPORTER
#define MODELIMPORTER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Structures.h"

struct BoneFrame
{
	char m_name[64];

	float m_translation[3];
	float m_quarternion[4];
	float m_rotEuler[3];
	double m_scale[3];

	int m_childrenCount;
	std::vector<BoneFrame*> m_children;
};

struct BindPose
{
	float m_bindPoseTransform[16];
	float m_geometricTransform[16];
};

struct AnimationStack
{
	char m_name[64];
	int m_endFrame;
	int m_jointCount;

	std::vector<BoneFrame*> m_root;
	std::vector<BindPose> m_bindPoses;
};

struct MeshData
{
	//char name[64];
	//float worldMatrix[16];

	bool m_animated;
	//unsigned int vertexCount;
	std::vector<Vertex> vertices;

	unsigned int m_textureMapSize[3];
	char* m_textureMap;
	unsigned int m_normalMapSize[3];
	char* m_normalMap;

	//unsigned int animationStackCount;
	std::vector<AnimationStack> m_stacks;
};

class ModelImporter
{
public:
	bool ImportModel(const char* p_filepath);

	MeshData GetMesh();

private:
	MeshData m_importedMesh;
};

#endif;