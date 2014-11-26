#ifndef ANIMATIONCONTROL
#define ANIMATIONCONTROL

#include <vector>
#include <string>
#include "Structures.h"

struct BoneFrame
{
	char m_name[64];

	float m_translation[3];
	float m_quarternion[4];
	float m_orientQuarternion[4];
	float m_rotEuler[3];
	double m_scale[3];

	int m_childrenCount;
	std::vector<BoneFrame*> m_children;
};

struct BindPose
{
	DirectX::XMMATRIX m_bindPoseTransform;
	DirectX::XMMATRIX m_geometricTransform;
};

struct AnimationStack
{
	char m_name[64];
	int m_endFrame;
	int m_jointCount;

	std::vector<BoneFrame*> m_root;
	std::vector<BindPose> m_bindPoses;
};

class AnimationControl
{
public:
	bool CreateNewStack(AnimationStack p_newStack);
	std::vector<DirectX::XMMATRIX> UpdateAnimation(double p_dT);

	bool IsAnimated();

private:
	void CombineMatrices(int* p_index, BoneFrame* p_joint, DirectX::XMMATRIX& p_parentTransform);

	std::vector<AnimationStack> m_animationStacks;

	double m_frame;

	std::vector<DirectX::XMMATRIX> m_boneTransforms;
};

#endif;