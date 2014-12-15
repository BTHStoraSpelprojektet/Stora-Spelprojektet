#ifndef ANIMATIONCONTROL
#define ANIMATIONCONTROL

#include <vector>
#include <string>
#include "Structures.h"

class AnimationControl
{
public:
	bool CreateNewStack(AnimationStack p_newStack);
	std::vector<DirectX::XMFLOAT4X4> UpdateAnimation();

	bool IsAnimated();
	void SetIkDirection(DirectX::XMFLOAT3 p_direction);

private:
	void CombineMatrices(int* p_index, BoneFrame* p_jointArms, BoneFrame* p_jointLegs, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation);
	DirectX::XMVECTOR ApplyIK(DirectX::XMVECTOR& p_quaternion);

	std::vector<AnimationStack> m_animationStacks;

	double m_frameArms;
	double m_frameLegs;

	DirectX::XMFLOAT3 m_ikDirection;
	DirectX::XMVECTOR m_rotationAxis;

	std::vector<DirectX::XMFLOAT4X4> m_boneTransforms;
	std::vector<BindPose> m_bindPoses;
};

#endif;