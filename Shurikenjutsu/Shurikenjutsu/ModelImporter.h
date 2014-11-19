#ifndef MODELIMPORTER
#define MODELIMPORTER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Structures.h"

struct BoneFrame
{
	char name[64];

	float translation[3];
	float quarternion[4];
	float rotEuler[3];
	double scale[3];

	int childrenCount;
	std::vector<BoneFrame*> children;
};

struct BindPose
{
	float bindPoseTransform[16];
	float geometricTransform[16];
};

struct AnimationStack
{
	char name[64];
	int endFrame;
	int jointCount;

	std::vector<BoneFrame*> root;
	std::vector<BindPose> bindPoses;
};

struct MeshData
{
	//char name[64];
	//float worldMatrix[16];

	bool animated;
	//unsigned int vertexCount;
	std::vector<Vertex> vertices;

	unsigned int textureMapSize[3];
	char* textureMap;
	unsigned int normalMapSize[3];
	char* normalMap;

	//unsigned int animationStackCount;
	std::vector<AnimationStack> stacks;
};

class ModelImporter
{
public:
	bool ImportModel(const char* p_filepath);

	MeshData m_importedMesh;
};

#endif;