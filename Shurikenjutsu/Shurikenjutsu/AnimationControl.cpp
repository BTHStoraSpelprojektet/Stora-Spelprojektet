#include "AnimationControl.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	m_frame = 0;

	return true;
}

std::vector<DirectX::XMMATRIX> AnimationControl::UpdateAnimation(double p_dT)
{
	m_frame += p_dT * 20;

	if (m_frame >= (m_animationStacks[0].m_endFrame - 1))
		m_frame = 0.0f;

	int* index = new int(0);
	CombineMatrices(index, m_animationStacks[0].m_root[(int)m_frame], DirectX::XMMatrixIdentity());
	delete[] index;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_joint, DirectX::XMMATRIX& p_parentTransform)
{
	float qx = p_joint->m_quarternion[0];
	float qy = p_joint->m_quarternion[1];
	float qz = p_joint->m_quarternion[2];
	float qw = p_joint->m_quarternion[3];

	DirectX::XMMATRIX rotationMatrix = DirectX::XMMatrixSet(
		1.0f - 2.0f*qy*qy - 2.0f*qz*qz, 2.0f*qx*qy + 2.0f*qz*qw, 2.0f*qx*qz - 2.0f*qy*qw, 0.0f,
		2.0f*qx*qy - 2.0f*qz*qw, 1.0f - 2.0f*qx*qx - 2.0f*qz*qz, 2.0f*qy*qz + 2.0f*qx*qw, 0.0f,
		2.0f*qx*qz + 2.0f*qy*qw, 2.0f*qy*qz - 2.0f*qx*qw, 1.0f - 2.0f*qx*qx - 2.0f*qy*qy, 0.0f,
		0.0f,					 0.0f,					  0.0f,							  1.0f
	);

	float oqx = p_joint->m_orientQuarternion[0];
	float oqy = p_joint->m_orientQuarternion[1];
	float oqz = p_joint->m_orientQuarternion[2];
	float oqw = p_joint->m_orientQuarternion[3];

	DirectX::XMMATRIX orientationMatrix = DirectX::XMMatrixSet(
		1.0f - 2.0f*oqy*oqy - 2.0f*oqz*oqz, 2.0f*oqx*oqy + 2.0f*oqz*oqw, 2.0f*oqx*oqz - 2.0f*oqy*oqw, 0.0f,
		2.0f*oqx*oqy - 2.0f*oqz*oqw, 1.0f - 2.0f*oqx*oqx - 2.0f*oqz*oqz, 2.0f*oqy*oqz + 2.0f*oqx*oqw, 0.0f,
		2.0f*oqx*oqz + 2.0f*oqy*oqw, 2.0f*oqy*oqz - 2.0f*oqx*oqw, 1.0f - 2.0f*oqx*oqx - 2.0f*oqy*oqy, 0.0f,
		0.0f,						 0.0f,						  0.0f,								  1.0f
	);

	DirectX::XMMATRIX transformMatrix = DirectX::XMMatrixMultiply(rotationMatrix, orientationMatrix);
	transformMatrix.r[3].m128_f32[0] = p_joint->m_translation[0]; 
	transformMatrix.r[3].m128_f32[1] = p_joint->m_translation[1];
	transformMatrix.r[3].m128_f32[2] = p_joint->m_translation[2];

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