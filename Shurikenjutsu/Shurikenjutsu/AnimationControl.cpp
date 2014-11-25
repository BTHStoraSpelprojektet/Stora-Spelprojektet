#include "AnimationControl.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	return true;
}

std::vector<DirectX::XMMATRIX> AnimationControl::UpdateAnimation(double p_dT)
{
	int* index = new int(0);
	CombineMatrices(index, m_animationStacks[0].m_root[0], DirectX::XMMatrixIdentity());
	delete[] index;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_joint, DirectX::XMMATRIX& p_parentTransform)
{
	float qx = p_joint->m_quarternion[0];
	float qy = p_joint->m_quarternion[1];
	float qz = p_joint->m_quarternion[2];
	float qw = p_joint->m_quarternion[3];

	DirectX::XMMATRIX transformMatrix = DirectX::XMMatrixSet(
		1.0f - 2.0f*qy*qy - 2.0f*qz*qz, 2.0f*qx*qy + 2.0f*qz*qw, 2.0f*qx*qz - 2.0f*qy*qw, 0.0f,
		2.0f*qx*qy - 2.0f*qz*qw, 1.0f - 2.0f*qx*qx - 2.0f*qz*qz, 2.0f*qy*qz + 2.0f*qx*qw, 0.0f,
		2.0f*qx*qz + 2.0f*qy*qw, 2.0f*qy*qz - 2.0f*qx*qw, 1.0f - 2.0f*qx*qx - 2.0f*qy*qy, 0.0f,
		p_joint->m_translation[0], p_joint->m_translation[1], p_joint->m_translation[2], 1.0f
		);

	transformMatrix = DirectX::XMMatrixMultiply(transformMatrix, p_parentTransform);

	DirectX::FXMMATRIX bindPose = m_animationStacks[0].m_bindPoses[*p_index].m_bindPoseTransform;
	DirectX::XMVECTOR determinant = DirectX::XMMatrixDeterminant(bindPose);
	DirectX::XMMATRIX bindPoseInverse = DirectX::XMMatrixInverse(&determinant, bindPose);
	m_boneTransforms[*p_index] = DirectX::XMMatrixTranspose(DirectX::XMMatrixMultiply(bindPoseInverse, transformMatrix));

	for (unsigned int i = 0; i < p_joint->m_children.size(); i++)
	{
		(*p_index)++;
		CombineMatrices(p_index, p_joint->m_children[i], transformMatrix);
	}
}

bool AnimationControl::IsAnimated()
{
	if (m_animationStacks.size() > 0)
		return true;

	return false;
}