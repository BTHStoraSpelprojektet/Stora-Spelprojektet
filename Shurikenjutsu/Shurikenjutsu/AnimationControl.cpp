#include "AnimationControl.h"
#include "Globals.h"
#include <iostream>

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	m_forwardDirection = DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f);
	m_ikDirection = DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f);
	m_rotationAxis = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);

	m_bindPoses.clear();
	m_bindPoses = p_newStack.m_bindPoses;

	m_hipRotation = 0.0f;

	m_surujinChild = false;
	m_isAlive = true;
	m_stopAnimation = false;

	m_state = AnimationState::None;
	m_light = false;

	m_showTrail = false;

	return true;
}

std::vector<DirectX::XMFLOAT4X4> AnimationControl::UpdateAnimation()
{
	if (!m_isAlive && m_stopAnimation)
	{
		return m_boneTransforms;
	}

	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	m_frameArms += deltaTime * 20;
	m_frameLegs += deltaTime * 20;
	
	m_blendWeightArms = (float)(m_frameArms - (int)m_frameArms) / 2;	//24.0f
	m_blendWeightLegs = (float)(m_frameLegs - (int)m_frameLegs) / 2;

	if (m_frameArms >= (m_currentArms->m_endFrame - 1))
	{
		m_frameArms = 0.0f;
		m_attackAnimation = false;
		m_state = AnimationState::None;
		m_stopAnimation = true;

		if (!m_isAlive)
		{
			m_blendWeightArms = 1.0f;
			m_frameArms = m_currentArms->m_root.size() - 1;
		}
	}		

	if (m_frameLegs >= (m_currentLegs->m_endFrame - 1))
	{
		m_frameLegs = 0.0f;

		if (!m_isAlive)
		{
			m_blendWeightLegs = 1.0f;
			m_frameLegs = m_currentLegs->m_root.size() - 1;
		}
	}		

	DirectX::XMVECTOR startQuaternion = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	DirectX::XMVECTOR startTranslation = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

	int* index = new int(0);
	CombineMatrices(index, m_currentArms->m_root[(int)m_frameArms], m_currentLegs->m_root[(int)m_frameLegs], startQuaternion, startTranslation);
	delete index;

	m_surujinChild = false;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_jointArms, BoneFrame* p_jointLegs, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation)
{
	DirectX::XMVECTOR orientQuaternion = DirectX::XMVectorSet(p_jointArms->m_orientQuaternion[0], p_jointArms->m_orientQuaternion[1], p_jointArms->m_orientQuaternion[2], p_jointArms->m_orientQuaternion[3]);

	DirectX::XMVECTOR quaternionArms = DirectX::XMVectorSet(p_jointArms->m_quaternion[0], p_jointArms->m_quaternion[1], p_jointArms->m_quaternion[2], p_jointArms->m_quaternion[3]);

	DirectX::XMVECTOR quaternionLegs = DirectX::XMVectorSet(p_jointLegs->m_quaternion[0], p_jointLegs->m_quaternion[1], p_jointLegs->m_quaternion[2], p_jointLegs->m_quaternion[3]);

	quaternionArms = DirectX::XMQuaternionSlerp(DirectX::XMLoadFloat4(&m_QuaternionArms[*p_index]), quaternionArms, m_blendWeightArms);
	DirectX::XMStoreFloat4(&m_QuaternionArms[*p_index], quaternionArms);
	
	quaternionLegs = DirectX::XMQuaternionSlerp(DirectX::XMLoadFloat4(&m_QuaternionLegs[*p_index]), quaternionLegs, m_blendWeightLegs);
	DirectX::XMStoreFloat4(&m_QuaternionLegs[*p_index], quaternionLegs);
	
	if (strcmp(p_jointLegs->m_name, "HandR") == 0 ||
		strcmp(p_jointLegs->m_name, "HandL") == 0 ||
		strcmp(p_jointLegs->m_name, "ElbowR") == 0 ||
		strcmp(p_jointLegs->m_name, "ElbowL") == 0 ||
		strcmp(p_jointLegs->m_name, "ShoulderR") == 0 ||
		strcmp(p_jointLegs->m_name, "ShoulderL") == 0)
	{
		quaternionLegs = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if (strcmp(p_jointArms->m_name, "FootR") == 0 ||
		strcmp(p_jointArms->m_name, "FootL") == 0 ||
		strcmp(p_jointArms->m_name, "HipR") == 0 || 
		strcmp(p_jointArms->m_name, "HipL") == 0 ||
		strcmp(p_jointArms->m_name, "KneeR") == 0 ||
		strcmp(p_jointArms->m_name, "KneeL") == 0)
	{
		quaternionArms = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	}

	DirectX::XMVECTOR quaternion = DirectX::XMQuaternionMultiply(quaternionArms, quaternionLegs);

	DirectX::XMVECTOR jointTranslation = DirectX::XMVectorSet(p_jointArms->m_translation[0], p_jointArms->m_translation[1], p_jointArms->m_translation[2], 1.0f);

	DirectX::XMMATRIX parentMatrix = DirectX::XMMatrixRotationQuaternion(p_parentQuaternion);
	parentMatrix.r[3].m128_f32[0] = p_parentTranslation.m128_f32[0];
	parentMatrix.r[3].m128_f32[1] = p_parentTranslation.m128_f32[1];
	parentMatrix.r[3].m128_f32[2] = p_parentTranslation.m128_f32[2];

	if (strcmp(p_jointArms->m_name, "Hip") == 0)
	{
		DirectX::XMVECTOR hipRotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		hipRotationAxis = DirectX::XMVector3Rotate(hipRotationAxis, DirectX::XMQuaternionInverse(orientQuaternion));

		DirectX::XMVECTOR hipRotation = DirectX::XMQuaternionRotationAxis(hipRotationAxis, m_hipRotation);
		quaternion = DirectX::XMQuaternionMultiply(quaternion, hipRotation);

		jointTranslation = DirectX::XMVectorSet(p_jointLegs->m_translation[0], p_jointLegs->m_translation[1], p_jointLegs->m_translation[2], 1.0f);

		parentMatrix = DirectX::XMMatrixRotationY(m_hipRotation);
		parentMatrix.r[3].m128_f32[0] = p_parentTranslation.m128_f32[0];
		parentMatrix.r[3].m128_f32[1] = p_parentTranslation.m128_f32[1];
		parentMatrix.r[3].m128_f32[2] = p_parentTranslation.m128_f32[2];
	}

	quaternion = DirectX::XMQuaternionMultiply(quaternion, orientQuaternion);	

	if (strcmp(p_jointArms->m_name, "SpineIK") == 0)
	{
		DirectX::XMVECTOR quaternionParent = DirectX::XMQuaternionMultiply(orientQuaternion, p_parentQuaternion);

		DirectX::XMStoreFloat3(&m_rotationAxis, DirectX::XMVector3Rotate(DirectX::XMLoadFloat3(&m_rotationAxis), DirectX::XMQuaternionInverse(quaternionParent)));

		quaternion = ApplyIK(quaternion);
		m_rotationAxis = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
		m_forwardDirection = DirectX::XMFLOAT3(0.0f, 0.0f, -1.0f);
	}

	quaternion = DirectX::XMQuaternionMultiply(quaternion, p_parentQuaternion);

	jointTranslation = DirectX::XMVector4Transform(jointTranslation, parentMatrix);

	if (strcmp(p_jointArms->m_name, "lightEmitter") == 0)
	{
		m_light = true;
		m_lightPos = DirectX::XMFLOAT3(jointTranslation.m128_f32[0], jointTranslation.m128_f32[1], jointTranslation.m128_f32[2]);
	}

	DirectX::XMMATRIX transformMatrix = DirectX::XMMatrixRotationQuaternion(quaternion);
	transformMatrix.r[3].m128_f32[0] = jointTranslation.m128_f32[0];
	transformMatrix.r[3].m128_f32[1] = jointTranslation.m128_f32[1];
	transformMatrix.r[3].m128_f32[2] = jointTranslation.m128_f32[2];

	DirectX::XMMATRIX bindPose = DirectX::XMLoadFloat4x4(&m_animationStacks[0].m_bindPoses[*p_index].m_bindPoseTransform);
	transformMatrix = DirectX::XMMatrixMultiply(bindPose, transformMatrix);

	if (strcmp(p_jointArms->m_name, "Surujin9") == 0 || m_surujinChild == true)
	{
		if (m_state == AnimationState::Range || m_state == AnimationState::Special2)
		{
			// Scale lator
		}		
		else
		{			
			transformMatrix = DirectX::XMMatrixIdentity();
			transformMatrix.r[0].m128_f32[0] = 0.0f;
			transformMatrix.r[1].m128_f32[1] = 0.0f;
			transformMatrix.r[2].m128_f32[2] = 0.0f;
		}

		m_surujinChild = true;
	}	

	if (m_state == AnimationState::Range || m_state == AnimationState::Special2)
	{
		if (strcmp(p_jointArms->m_name, "Surujin10") == 0)
		{
			m_trailPosition = DirectX::XMFLOAT3(jointTranslation.m128_f32[0], jointTranslation.m128_f32[1], jointTranslation.m128_f32[2]);
			DirectX::XMFLOAT3 lastPos = DirectX::XMFLOAT3(m_boneTransforms[*p_index]._14, m_boneTransforms[*p_index]._24, m_boneTransforms[*p_index]._34);

			DirectX::XMFLOAT3 weaponDirection;
			weaponDirection.x = m_trailPosition.x - lastPos.x;
			weaponDirection.y = m_trailPosition.y - lastPos.y;
			weaponDirection.z = m_trailPosition.z - lastPos.z;

			m_trailAngle = atan2(weaponDirection.z, weaponDirection.x);
			m_showTrail = true;
		}
	}
	else
	{
		m_showTrail = false;
	}

	DirectX::XMStoreFloat4x4(&m_boneTransforms[*p_index], DirectX::XMMatrixTranspose(transformMatrix));

	for (unsigned int i = 0; i < p_jointArms->m_children.size(); i++)
	{
		(*p_index)++;
		CombineMatrices(p_index, p_jointArms->m_children[i], p_jointLegs->m_children[i], quaternion, jointTranslation);
	}

	if (p_jointArms->m_children.size() == 0)
	{
		m_surujinChild = false;
	}
}

DirectX::XMVECTOR AnimationControl::ApplyIK(DirectX::XMVECTOR& p_quaternion)
{
	DirectX::XMMATRIX forwardRotation = DirectX::XMMatrixRotationY(-m_hipRotation);
	DirectX::XMVECTOR lIkDirection = DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_ikDirection), forwardRotation);

	float cross = DirectX::XMVector3Cross(lIkDirection, DirectX::XMLoadFloat3(&m_forwardDirection)).m128_f32[1];
	float angle = acosf(DirectX::XMVector3Dot(lIkDirection, DirectX::XMLoadFloat3(&m_forwardDirection)).m128_f32[0]);

	if (cross > 0)
	{
		angle *= -1.0f;
	}

	DirectX::XMVECTOR appliedIkQuaternion = DirectX::XMQuaternionRotationAxis(DirectX::XMLoadFloat3(&m_rotationAxis), angle);
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
	if (!m_isAlive)
	{
		return;
	}

	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_direction);

	if (DirectX::XMVector3Length(direction).m128_f32[0] != 0.0f)
	{
		m_ikDirection = p_direction;
		m_ikLegDirection = p_direction;
	}
}

void AnimationControl::HandleInput(DirectX::XMFLOAT3 p_dir)
{
	if (!m_isAlive)
	{
		return;
	}

	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_dir);

	float directionAngle = DirectX::XMVector3AngleBetweenVectors(DirectX::XMLoadFloat3(&m_ikDirection), direction).m128_f32[0];

	float cross = DirectX::XMVector3Cross(DirectX::XMLoadFloat3(&m_ikDirection), DirectX::XMLoadFloat3(&m_forwardDirection)).m128_f32[1];

	if (DirectX::XMVector3Length(direction).m128_f32[0] == 0.0f)	// Idle
	{
		ChangeLayer(7, 6);
	}
	else if (directionAngle < (3.14f * 0.375f))			  // Forward
	{
		ChangeLayer(1, 0);
	}
	else if (directionAngle >(3.14f * 0.625f))			  // Back
	{
		ChangeLayer(3, 2);
	}
	else if (cross > 0)									 // Right
	{
		ChangeLayer(3, 5);
	}
	else                                                  // Left
	{
		ChangeLayer(3, 4);
	}

	ApplyLegDirection(direction, directionAngle, cross);
}

void AnimationControl::NetworkInput(DirectX::XMFLOAT3 p_dir)
{
	if (!m_isAlive)
	{
		return;
	}

	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_dir);

	float directionAngle = DirectX::XMVector3AngleBetweenVectors(DirectX::XMLoadFloat3(&m_ikLegDirection), direction).m128_f32[0];

	float cross = DirectX::XMVector3Cross(DirectX::XMLoadFloat3(&m_ikLegDirection), DirectX::XMLoadFloat3(&m_forwardDirection)).m128_f32[1];

	if (m_animationStacks.size() > 0)
	{  
		if (DirectX::XMVector3Length(direction).m128_f32[0] == 0.0f)	// Idle
		{
			ChangeLayer(7, 6);
		}
		else if (directionAngle < (3.14f * 0.375f))			  // Forward
		{
			ChangeLayer(1, 0);
		}
		else if (directionAngle >(3.14f * 0.625f))			  // Back
		{
			ChangeLayer(3, 2);
		}
		else if (cross > 0 && DirectX::XMVector3Length(direction).m128_f32[0] != 0.0f)		// Right
		{
			ChangeLayer(3, 5);
		}
		else																// Left
		{
			ChangeLayer(3, 4);
		}

		ApplyLegDirection(direction, directionAngle, cross);	
	}
}

void AnimationControl::ChangeLayer(int p_armIndex, int p_legIndex)
{
	if (m_attackAnimation != true)
	{
		m_currentArms = &m_animationStacksArray[p_armIndex];
	}

	m_currentLegs = &m_animationStacksArray[p_legIndex];
}

void AnimationControl::ApplyLegDirection(DirectX::XMVECTOR& p_direction, float p_directionAngle, float p_cross)
{
	float crossD = DirectX::XMVector3Cross(DirectX::XMLoadFloat3(&m_ikLegDirection), p_direction).m128_f32[1];

	float forwardAngle = DirectX::XMVector3AngleBetweenVectors(DirectX::XMLoadFloat3(&m_forwardDirection), DirectX::XMLoadFloat3(&m_ikLegDirection)).m128_f32[0];

	const float low = 3.14f * 0.125f;
	float lowMid = 3.14f * 0.375f;
	const float highMid = 3.14f * 0.625f;
	const float high = 3.14f * 0.875f;

	//Turn rate! when standing still!
	if (DirectX::XMVector3Length(p_direction).m128_f32[0] == 0.0f)
	{	
		if (p_cross > 0)
		{
			float radianHip = atan2(sin((6.28f - forwardAngle) - m_hipRotation), cos((6.28f - forwardAngle) - m_hipRotation));

			if (radianHip > low || radianHip < -low)
			{
				m_hipRotation += radianHip * 0.05f;
				ChangeLayer(7, 15);
			}			
		}
		else
		{
			float radianHip = atan2(sin(forwardAngle - m_hipRotation), cos(forwardAngle - m_hipRotation));

			if (radianHip > low || radianHip < -low)
			{
				m_hipRotation += radianHip * 0.05f;
				ChangeLayer(7, 15);
			}
		}

		return;
	}	
	//

	// Determines which way the legs are turned when running.
	if (crossD > 0)
	{
		if (p_directionAngle < lowMid && p_directionAngle > low && p_cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + p_directionAngle);
		}
		else if (p_directionAngle < lowMid && p_directionAngle > low && p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - p_directionAngle);
		}
		else if (p_directionAngle < high && p_directionAngle > highMid && p_cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + p_directionAngle) - 3.14f;
		}
		else if (p_directionAngle < high && p_directionAngle > highMid && p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - (p_directionAngle - 3.14f));
		}
		else if (p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle);
		}
		else
		{
			m_hipRotation = CalculateLegDirection(forwardAngle);
		}
	}
	else
	{
		if (p_directionAngle < lowMid && p_directionAngle > low && p_cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - p_directionAngle);
		}
		else if (p_directionAngle < lowMid && p_directionAngle > low && p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + p_directionAngle);
		}
		else if (p_directionAngle < high && p_directionAngle > highMid && p_cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - (p_directionAngle - 3.14f));
		}
		else if (p_directionAngle < high && p_directionAngle > highMid && p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + p_directionAngle) - 3.14f;
		}
		else if (p_cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle);
		}
		else
		{
			m_hipRotation = CalculateLegDirection(forwardAngle);
		}
	}
}

float AnimationControl::CalculateLegDirection(float p_forwardAngle)
{
	float piDivFour = 0.785000026f;
	int a = (int)(p_forwardAngle / piDivFour);
	float b = p_forwardAngle / piDivFour;

	for (unsigned int i = 0; i < 8; i++)
	{
		if (a == i)
		{
			if (b >(0.5f + i))
			{
				a++;
			}
			break;
		}
	}

	return piDivFour * a;
}

void AnimationControl::FindAndReferenceLayers()
{
	std::string m_animationNames[] = { "RunF", "RunA", "RunB", "RunAB", 
									   "RunL", "RunR", "IdleL", "IdleA", 
									   "DeadL", "DeadA", "Melee", "Range",
									   "Tool", "Spec1", "Spec2", "Turn"};

	m_animationStacksArray = new AnimationStack[m_animationStacks.size()];

	for (unsigned int i = 0; i < m_animationStacks.size(); i++)
	{
		for (unsigned int j = 0; j < 16; j++)
		{
			if (strcmp(m_animationStacks[i].m_name, m_animationNames[j].c_str()) == 0)
			{
				m_animationStacksArray[j] = m_animationStacks[i];
			}
		}		
	}

	m_currentLegs = &m_animationStacksArray[6];
	m_currentArms = &m_animationStacksArray[7];

	m_blendWeightArms = 0.0f;
	m_blendWeightLegs = 0.0f;

	m_QuaternionArms.resize(m_animationStacksArray[0].m_jointCount);
	m_QuaternionLegs.resize(m_animationStacksArray[0].m_jointCount);
	for (int i = 0; i < m_animationStacksArray[0].m_jointCount; i++)
	{
		DirectX::XMVECTOR temp = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

		DirectX::XMStoreFloat4(&m_QuaternionArms[i], temp);
		DirectX::XMStoreFloat4(&m_QuaternionLegs[i], temp);
	}
}

void AnimationControl::AnimatedObjectLayers()
{
	m_animationStacksArray = new AnimationStack[m_animationStacks.size()];

	for (unsigned int i = 0; i < m_animationStacks.size(); i++)
	{
		m_animationStacksArray[i] = m_animationStacks[i];
	}

	m_currentArms = &m_animationStacksArray[1];
	m_currentLegs = &m_animationStacksArray[0];

	m_blendWeightArms = 0.0f;
	m_blendWeightLegs = 0.0f;

	m_QuaternionArms.resize(m_animationStacksArray[0].m_jointCount);
	m_QuaternionLegs.resize(m_animationStacksArray[0].m_jointCount);
	for (int i = 0; i < m_animationStacksArray[0].m_jointCount; i++)
	{
		DirectX::XMVECTOR temp = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

		DirectX::XMStoreFloat4(&m_QuaternionArms[i], temp);
		DirectX::XMStoreFloat4(&m_QuaternionLegs[i], temp);
	}
}

void AnimationControl::Shutdown()
{
	delete[] m_animationStacksArray;
	m_animationStacksArray = NULL;
}

void AnimationControl::ChangeAnimationState(AnimationState p_newState)
{
	if (p_newState == AnimationState::Death)
	{
		m_currentArms = &m_animationStacksArray[9];
		m_currentLegs = &m_animationStacksArray[8];
		m_isAlive = false;
		m_attackAnimation = true;
		m_stopAnimation = false;
		m_frameArms = 0.0f;
		m_frameLegs = 0.0f;
	}
	else if (p_newState == AnimationState::Spawn)
	{
		m_isAlive = true;
	}
	else if (!m_attackAnimation && m_isAlive == true)
	{
		m_frameArms = 0.0f;
		m_attackAnimation = true;
		m_state = p_newState;

		if (p_newState == AnimationState::Melee)
		{
			m_currentArms = &m_animationStacksArray[10];
		}
		else if (p_newState == AnimationState::Range)
		{
			m_currentArms = &m_animationStacksArray[11];
		}
		else if (p_newState == AnimationState::Special1)
		{
			m_currentArms = &m_animationStacksArray[13];
		}
		else if (p_newState == AnimationState::Special2)
		{
			m_currentArms = &m_animationStacksArray[14];
		}
		else if (p_newState == AnimationState::Tool)
		{
			m_currentArms = &m_animationStacksArray[12];
		}		
	}	
	else
	{
		m_currentArms = &m_animationStacksArray[7];
	}
}

std::vector<DirectX::XMFLOAT4X4> AnimationControl::GetBoneTransforms()
{
	return m_boneTransforms;
}

bool AnimationControl::IsLight()
{
	return m_light;
}

DirectX::XMFLOAT3 AnimationControl::GetLightPosition()
{
	return m_lightPos;
}

DirectX::XMFLOAT3 AnimationControl::GetTrailPosition()
{
	return m_trailPosition;
}

float AnimationControl::GetTrailAngle()
{
	return m_trailAngle;
}

bool AnimationControl::ShowTrail()
{
	return m_showTrail;
}