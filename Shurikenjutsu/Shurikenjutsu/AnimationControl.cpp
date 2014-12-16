#include "AnimationControl.h"
#include "Globals.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	m_frameArms = 0;
	m_frameLegs = 0;

	m_ikDirection = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_rotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	m_bindPoses.clear();
	m_bindPoses = p_newStack.m_bindPoses;

	return true;
}

std::vector<DirectX::XMFLOAT4X4> AnimationControl::UpdateAnimation()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	m_frameArms += deltaTime * 20;
	m_frameLegs += deltaTime * 20;

	if (m_frameArms >= (m_animationStacks[4].m_endFrame - 1))
		m_frameArms = 0.0f;

	if (m_frameLegs >= (m_animationStacks[2].m_endFrame - 1))
		m_frameLegs = 0.0f;

	DirectX::XMVECTOR startQuaternion = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	DirectX::XMVECTOR startTranslation = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

	int* index = new int(0);
	CombineMatrices(index, m_animationStacks[4].m_root[(int)m_frameArms], m_animationStacks[1].m_root[(int)m_frameLegs], startQuaternion, startTranslation);
	delete[] index;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_jointArms, BoneFrame* p_jointLegs, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation)
{
	DirectX::XMVECTOR quaternionArms = DirectX::XMVectorSet(p_jointArms->m_quaternion[0], p_jointArms->m_quaternion[1], p_jointArms->m_quaternion[2], p_jointArms->m_quaternion[3]);
	DirectX::XMVECTOR quaternionLegs = DirectX::XMVectorSet(p_jointLegs->m_quaternion[0], p_jointLegs->m_quaternion[1], p_jointLegs->m_quaternion[2], p_jointLegs->m_quaternion[3]);
	DirectX::XMVECTOR quaternion = DirectX::XMQuaternionMultiply(quaternionArms, quaternionLegs);
	DirectX::XMVECTOR orientQuaternion = DirectX::XMVectorSet(p_jointArms->m_orientQuaternion[0], p_jointArms->m_orientQuaternion[1], p_jointArms->m_orientQuaternion[2], p_jointArms->m_orientQuaternion[3]);

	quaternion = DirectX::XMQuaternionMultiply(quaternion, orientQuaternion);

	if (strcmp(p_jointArms->m_name, "SpineIK") == 0)
	{
		DirectX::XMMATRIX rot = DirectX::XMMatrixRotationQuaternion(p_parentQuaternion);
		m_rotationAxis = DirectX::XMVector3TransformNormal(m_rotationAxis, rot);

		//quaternion = ApplyIK(quaternion);
		m_rotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	}

	DirectX::XMMATRIX parentMatrix = DirectX::XMMatrixRotationQuaternion(p_parentQuaternion);
	parentMatrix.r[3].m128_f32[0] = p_parentTranslation.m128_f32[0];
	parentMatrix.r[3].m128_f32[1] = p_parentTranslation.m128_f32[1];
	parentMatrix.r[3].m128_f32[2] = p_parentTranslation.m128_f32[2];

	float combinedTranslation[3];
	combinedTranslation[0] = (p_jointArms->m_translation[0] + p_jointLegs->m_translation[0]) / 2;
	combinedTranslation[1] = (p_jointArms->m_translation[1] + p_jointLegs->m_translation[1]) / 2;
	combinedTranslation[2] = (p_jointArms->m_translation[2] + p_jointLegs->m_translation[2]) / 2;

	DirectX::XMVECTOR jointTranslation = DirectX::XMVectorSet(combinedTranslation[0], combinedTranslation[1], combinedTranslation[2], 1.0f);

	jointTranslation = DirectX::XMVector4Transform(jointTranslation, parentMatrix);

	quaternion = DirectX::XMQuaternionMultiply(quaternion, p_parentQuaternion);

	DirectX::XMMATRIX transformMatrix = DirectX::XMMatrixRotationQuaternion(quaternion);
	transformMatrix.r[3].m128_f32[0] = jointTranslation.m128_f32[0];
	transformMatrix.r[3].m128_f32[1] = jointTranslation.m128_f32[1];
	transformMatrix.r[3].m128_f32[2] = jointTranslation.m128_f32[2];	

	DirectX::XMMATRIX bindPose = DirectX::XMLoadFloat4x4(&m_animationStacks[0].m_bindPoses[*p_index].m_bindPoseTransform);
	transformMatrix = DirectX::XMMatrixMultiply(bindPose, transformMatrix);
	DirectX::XMStoreFloat4x4(&m_boneTransforms[*p_index], DirectX::XMMatrixTranspose(transformMatrix));

	for (unsigned int i = 0; i < p_jointArms->m_children.size(); i++)
	{
		(*p_index)++;
		CombineMatrices(p_index, p_jointArms->m_children[i], p_jointLegs->m_children[i], quaternion, jointTranslation);
	}
}

DirectX::XMVECTOR AnimationControl::ApplyIK(DirectX::XMVECTOR& p_quaternion)
{
	// m_ikDirection angle.
	DirectX::XMVECTOR appliedIkQuaternion = DirectX::XMQuaternionRotationAxis(m_rotationAxis, (float)m_frameArms / 20.0f);  
	appliedIkQuaternion = DirectX::XMQuaternionMultiply(appliedIkQuaternion, p_quaternion);

	return appliedIkQuaternion;
}

bool AnimationControl::IsAnimated()
{
	if (m_animationStacks.size() > 0)
		return true;

	return false;
}

void AnimationControl::SetIkDirection(DirectX::XMFLOAT3 p_direction)
{
	m_ikDirection = p_direction;
}