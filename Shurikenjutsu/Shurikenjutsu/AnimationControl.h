#ifndef ANIMATIONCONTROL
#define ANIMATIONCONTROL

#include <vector>
#include <string>
#include "Structures.h"

class AnimationControl
{
public:
	bool CreateNewStack(AnimationStack p_newStack);
	std::vector<DirectX::XMMATRIX> UpdateAnimation();

	bool IsAnimated();

private:
	void CombineMatrices(int* p_index, BoneFrame* p_joint, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation);

	std::vector<AnimationStack> m_animationStacks;

	double m_frame;

	std::vector<DirectX::XMMATRIX> m_boneTransforms;
};

#endif;