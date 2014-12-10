#include "AnimationControl.h"
#include "Globals.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	m_frame = 0;

	return true;
}

std::vector<DirectX::XMMATRIX> AnimationControl::UpdateAnimation()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	m_frame += deltaTime * 20;

	if (m_frame >= (m_animationStacks[1].m_endFrame - 1))
		m_frame = 0.0f;

	DirectX::XMVECTOR startQuaternion = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	DirectX::XMVECTOR startTranslation = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

	int* index = new int(0);
	CombineMatrices(index, m_animationStacks[1].m_root[(int)m_frame], startQuaternion, startTranslation);
	delete[] index;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_joint, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation)
{
	DirectX::XMVECTOR quaternion = DirectX::XMVectorSet(p_joint->m_quaternion[0], p_joint->m_quaternion[1], p_joint->m_quaternion[2], p_joint->m_quaternion[3]);
	DirectX::XMVECTOR orientQuaternion = DirectX::XMVectorSet(p_joint->m_orientQuaternion[0], p_joint->m_orientQuaternion[1], p_joint->m_orientQuaternion[2], p_joint->m_orientQuaternion[3]);

	quaternion = DirectX::XMQuaternionMultiply(quaternion, orientQuaternion);

	DirectX::XMMATRIX parentMatrix = DirectX::XMMatrixRotationQuaternion(p_parentQuaternion);
	parentMatrix.r[3].m128_f32[0] = p_parentTranslation.m128_f32[0];
	parentMatrix.r[3].m128_f32[1] = p_parentTranslation.m128_f32[1];
	parentMatrix.r[3].m128_f32[2] = p_parentTranslation.m128_f32[2];

	DirectX::XMVECTOR jointTranslation = DirectX::XMVectorSet(p_joint->m_translation[0], p_joint->m_translation[1], p_joint->m_translation[2], 1.0f);

	jointTranslation = DirectX::XMVector4Transform(jointTranslation, parentMatrix);

	quaternion = DirectX::XMQuaternionMultiply(quaternion, p_parentQuaternion);

	DirectX::XMMATRIX transformMatrix = DirectX::XMMatrixRotationQuaternion(quaternion);
	transformMatrix.r[3].m128_f32[0] = jointTranslation.m128_f32[0];
	transformMatrix.r[3].m128_f32[1] = jointTranslation.m128_f32[1];
	transformMatrix.r[3].m128_f32[2] = jointTranslation.m128_f32[2];

	DirectX::FXMMATRIX bindPose = m_animationStacks[0].m_bindPoses[*p_index].m_bindPoseTransform;
	m_boneTransforms[*p_index] = DirectX::XMMatrixTranspose(DirectX::XMMatrixMultiply(bindPose, transformMatrix));

	for (unsigned int i = 0; i < p_joint->m_children.size(); i++)
	{
		(*p_index)++;
		CombineMatrices(p_index, p_joint->m_children[i], quaternion, jointTranslation);
	}
}

bool AnimationControl::IsAnimated()
{
	if (m_animationStacks.size() > 0)
		return true;

	return false;
}