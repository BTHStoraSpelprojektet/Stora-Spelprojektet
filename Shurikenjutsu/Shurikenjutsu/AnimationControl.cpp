#include "AnimationControl.h"
#include "Globals.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);
	m_boneTransforms.resize(p_newStack.m_jointCount);

	m_frameArms = 0;
	m_frameLegs = 0;

	m_forwardDirection = DirectX::XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f);
	m_ikDirection = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	m_rotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	m_bindPoses.clear();
	m_bindPoses = p_newStack.m_bindPoses;

	m_hipRotation = 0.0f;

	return true;
}

std::vector<DirectX::XMFLOAT4X4> AnimationControl::UpdateAnimation()
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();

	m_frameArms += deltaTime * 20;
	m_frameLegs += deltaTime * 20;

	if (m_frameArms >= (m_currentArms.m_endFrame - 1))
	{
		m_frameArms = 0.0f;
		m_attackAnimation = false;
	}		

	if (m_frameLegs >= (m_currentLegs.m_endFrame - 1))
	{
		m_frameLegs = 0.0f;
	}		

	DirectX::XMVECTOR startQuaternion = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	DirectX::XMVECTOR startTranslation = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

	int* index = new int(0);
	CombineMatrices(index, m_currentArms.m_root[(int)m_frameArms], m_currentLegs.m_root[(int)m_frameLegs], startQuaternion, startTranslation);
	delete[] index;

	return m_boneTransforms;
}

void AnimationControl::CombineMatrices(int* p_index, BoneFrame* p_jointArms, BoneFrame* p_jointLegs, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation)
{
	DirectX::XMVECTOR orientQuaternion = DirectX::XMVectorSet(p_jointArms->m_orientQuaternion[0], p_jointArms->m_orientQuaternion[1], p_jointArms->m_orientQuaternion[2], p_jointArms->m_orientQuaternion[3]);

	DirectX::XMVECTOR quaternionArms = DirectX::XMVectorSet(p_jointArms->m_quaternion[0], p_jointArms->m_quaternion[1], p_jointArms->m_quaternion[2], p_jointArms->m_quaternion[3]);

	DirectX::XMVECTOR quaternionLegs = DirectX::XMVectorSet(p_jointLegs->m_quaternion[0], p_jointLegs->m_quaternion[1], p_jointLegs->m_quaternion[2], p_jointLegs->m_quaternion[3]);

	if (strcmp(p_jointArms->m_name, "HandR") == 0 ||
		strcmp(p_jointArms->m_name, "HandL") == 0 ||
		strcmp(p_jointArms->m_name, "ShoulderR") == 0 ||
		strcmp(p_jointArms->m_name, "ShoulderL") == 0)
	{
		quaternionLegs = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if (strcmp(p_jointLegs->m_name, "FootR") == 0 || 
		strcmp(p_jointLegs->m_name, "FootL") == 0 || 
		strcmp(p_jointArms->m_name, "HipR") == 0 || 
		strcmp(p_jointArms->m_name, "HipL") == 0 ||
		strcmp(p_jointArms->m_name, "KneeR") == 0 ||
		strcmp(p_jointArms->m_name, "KneeL") == 0)
	{
		quaternionArms = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	}

	DirectX::XMVECTOR quaternion = DirectX::XMQuaternionMultiply(quaternionArms, quaternionLegs);

	if (strcmp(p_jointArms->m_name, "Hip") == 0)
	{
		DirectX::XMVECTOR hipRotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		hipRotationAxis = DirectX::XMVector3Rotate(hipRotationAxis, DirectX::XMQuaternionInverse(orientQuaternion));

		DirectX::XMVECTOR hipRotation = DirectX::XMQuaternionRotationAxis(hipRotationAxis, m_hipRotation);
		quaternion = DirectX::XMQuaternionMultiply(quaternion, hipRotation);
	}

	quaternion = DirectX::XMQuaternionMultiply(quaternion, orientQuaternion);	

	if (strcmp(p_jointArms->m_name, "SpineIK") == 0)
	{
		DirectX::XMVECTOR quaternionParent = DirectX::XMQuaternionMultiply(orientQuaternion, p_parentQuaternion);

		m_rotationAxis = DirectX::XMVector3Rotate(m_rotationAxis, DirectX::XMQuaternionInverse(p_parentQuaternion));

		quaternion = ApplyIK(quaternion);
		m_rotationAxis = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		m_forwardDirection = DirectX::XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f);
	}

	DirectX::XMMATRIX parentMatrix = DirectX::XMMatrixRotationQuaternion(p_parentQuaternion);
	parentMatrix.r[3].m128_f32[0] = p_parentTranslation.m128_f32[0];
	parentMatrix.r[3].m128_f32[1] = p_parentTranslation.m128_f32[1];
	parentMatrix.r[3].m128_f32[2] = p_parentTranslation.m128_f32[2];

	DirectX::XMVECTOR jointTranslation = DirectX::XMVectorSet(p_jointArms->m_translation[0], p_jointArms->m_translation[1], p_jointArms->m_translation[2], 1.0f);

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
	DirectX::XMMATRIX forwardRotation = DirectX::XMMatrixRotationY(-m_hipRotation);
	m_ikDirection = DirectX::XMVector3TransformNormal(m_ikDirection, forwardRotation);

	float cross = DirectX::XMVector3Cross(m_ikDirection, m_forwardDirection).m128_f32[1];
	float angle = acosf(DirectX::XMVector3Dot(m_ikDirection, m_forwardDirection).m128_f32[0]);

	if (cross > 0)
	{
		angle *= -1.0f;
	}

	DirectX::XMVECTOR appliedIkQuaternion = DirectX::XMQuaternionRotationAxis(m_rotationAxis, angle);
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
	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_direction);

	if (DirectX::XMVector3Length(direction).m128_f32[0] != 0.0f)
	{
		m_ikDirection = DirectX::XMVectorSet(p_direction.x, p_direction.y, p_direction.z, 0.0f);
		m_ikLegDirectionNetwork = DirectX::XMVectorSet(p_direction.x, p_direction.y, p_direction.z, 0.0f);
	}
}

void AnimationControl::HandleInput(DirectX::XMFLOAT3 p_dir)
{
	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_dir);

	float directionAngle = DirectX::XMVector3AngleBetweenVectors(m_ikDirection, direction).m128_f32[0];

	float cross = DirectX::XMVector3Cross(m_ikDirection, m_forwardDirection).m128_f32[1];

	if (DirectX::XMVector3Length(direction).m128_f32[0] == 0.0f)	// Idle
	{
		if (m_attackAnimation != true)
		{
			m_currentArms = m_animationStacksArray[7];
		}

		m_currentLegs = m_animationStacksArray[6];
	}
	else if (directionAngle < (3.14f * 0.375f))			  // Forward
	{
		if (m_attackAnimation != true)
		{
			m_currentArms = m_animationStacksArray[1];
		}

		m_currentLegs = m_animationStacksArray[0];
	}
	else if (directionAngle >(3.14f * 0.625f))			  // Back
	{
		if (m_attackAnimation != true)
		{
			m_currentArms = m_animationStacksArray[3];
		}

		m_currentLegs = m_animationStacksArray[2];
	}
	else if (cross > 0)									 // Right
	{
		if (m_attackAnimation != true)
		{
			m_currentArms = m_animationStacksArray[3];
		}

		m_currentLegs = m_animationStacksArray[5];
	}
	else                                                  // Left
	{
		if (m_attackAnimation != true)
		{
			m_currentArms = m_animationStacksArray[3];
		}

		m_currentLegs = m_animationStacksArray[4];
	}

	ApplyLegDirection(direction, directionAngle, cross);
}

void AnimationControl::NetworkInput(DirectX::XMFLOAT3 p_dir)
{
	DirectX::XMVECTOR direction = DirectX::XMLoadFloat3(&p_dir);

	float directionAngle = DirectX::XMVector3AngleBetweenVectors(m_ikLegDirectionNetwork, direction).m128_f32[0];

	float cross = DirectX::XMVector3Cross(m_ikLegDirectionNetwork, m_forwardDirection).m128_f32[1];

	if (m_animationStacks.size() > 0)
	{  
		//if (directionAngle < (3.14f * 0.375f))			  // Forward
		{
			m_currentArms = m_animationStacksArray[1];
			m_currentLegs = m_animationStacksArray[0];
		}
		//else if (directionAngle >(3.14f * 0.625f))			  // Back
		//{
		//	m_currentArms = m_animationStacksArray[3];
		//	m_currentLegs = m_animationStacksArray[2];
		//}
		//else if (cross > 0 && DirectX::XMVector3Length(direction).m128_f32[0] != 0.0f)									 // Right
		//{
		//	m_currentArms = m_animationStacksArray[3];
		//	m_currentLegs = m_animationStacksArray[5];
		//}
		//else if (cross <= 0 && DirectX::XMVector3Length(direction).m128_f32[0] != 0.0f)	                             // Left
		//{
		//	m_currentArms = m_animationStacksArray[3];
		//	m_currentLegs = m_animationStacksArray[4];
		//}
		//else                                                 // Idle
		//{
		//	m_currentArms = m_animationStacksArray[7];
		//	m_currentLegs = m_animationStacksArray[6];
		//}

		ApplyLegDirectionNetwork(direction, directionAngle, cross);	
	}
}

void AnimationControl::ApplyLegDirection(DirectX::XMVECTOR& direction, float directionAngle, float cross)
{
	float crossD = DirectX::XMVector3Cross(m_ikDirection, direction).m128_f32[1];

	float forwardAngle = DirectX::XMVector3AngleBetweenVectors(m_forwardDirection, m_ikDirection).m128_f32[0];

	float low = 3.14f * 0.125f;
	float lowMid = 3.14f * 0.375f;
	float highMid = 3.14f * 0.625f;
	float high = 3.14f * 0.875f;

	if (crossD > 0)
	{
		if (directionAngle < lowMid && directionAngle > low && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + directionAngle);
		}
		else if (directionAngle < lowMid && directionAngle > low && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - directionAngle);
		}
		else if (directionAngle < high && directionAngle > highMid && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + directionAngle) - 3.14f;
		}
		else if (directionAngle < high && directionAngle > highMid && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - (directionAngle - 3.14f));
		}
		else if (cross > 0)
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
		if (directionAngle < lowMid && directionAngle > low && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - directionAngle);
		}
		else if (directionAngle < lowMid && directionAngle > low && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + directionAngle);
		}
		else if (directionAngle < high && directionAngle > highMid && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - (directionAngle - 3.14f));
		}
		else if (directionAngle < high && directionAngle > highMid && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + directionAngle) - 3.14f;
		}
		else if (cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle);
		}
		else
		{
			m_hipRotation = CalculateLegDirection(forwardAngle);
		}
	}
}

void AnimationControl::ApplyLegDirectionNetwork(DirectX::XMVECTOR& direction, float directionAngle, float cross)
{
	float crossD = DirectX::XMVector3Cross(m_ikLegDirectionNetwork, direction).m128_f32[1];

	float forwardAngle = DirectX::XMVector3AngleBetweenVectors(m_forwardDirection, m_ikLegDirectionNetwork).m128_f32[0];

	float low = 3.14f * 0.125f;
	float lowMid = 3.14f * 0.375f;
	float highMid = 3.14f * 0.625f;
	float high = 3.14f * 0.875f;

	if (crossD > 0)
	{
		if (directionAngle < lowMid && directionAngle > low && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + directionAngle);
		}
		else if (directionAngle < lowMid && directionAngle > low && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - directionAngle);
		}
		else if (directionAngle < high && directionAngle > highMid && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle + directionAngle) - 3.14f;
		}
		else if (directionAngle < high && directionAngle > highMid && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle - (directionAngle - 3.14f));
		}
		/*else if (cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle);
		}
		else
		{
			m_hipRotation = CalculateLegDirection(forwardAngle);
		}*/
	}
	else
	{
		if (directionAngle < lowMid && directionAngle > low && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - directionAngle);
		}
		else if (directionAngle < lowMid && directionAngle > low && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + directionAngle);
		}
		else if (directionAngle < high && directionAngle > highMid && cross <= 0)
		{
			m_hipRotation = CalculateLegDirection(forwardAngle - (directionAngle - 3.14f));
		}
		else if (directionAngle < high && directionAngle > highMid && cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle + directionAngle) - 3.14f;
		}
		/*else if (cross > 0)
		{
			m_hipRotation = 6.28f - CalculateLegDirection(forwardAngle);
		}
		else
		{
			m_hipRotation = CalculateLegDirection(forwardAngle);
		}*/
	}
}

float AnimationControl::CalculateLegDirection(float forwardAngle)
{
	float piDivFour = 0.785000026f;
	int a = (int)(forwardAngle / piDivFour);
	float b = forwardAngle / piDivFour;

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
									   "DeadL", "DeadA", "Melee", "Range"};

	m_animationStacksArray = new AnimationStack[m_animationStacks.size()];

	for (unsigned int i = 0; i < m_animationStacks.size(); i++)
	{
		for (unsigned int j = 0; j < 12; j++)
		{
			if (strcmp(m_animationStacks[i].m_name, m_animationNames[j].c_str()) == 0)
			{
				m_animationStacksArray[j] = m_animationStacks[i];
			}
		}		
	}
}

void AnimationControl::Shutdown()
{
	delete[] m_animationStacksArray;
	m_animationStacksArray = NULL;
}

void AnimationControl::RangeAttack()
{
	if (!m_attackAnimation)
	{
		m_currentArms = m_animationStacksArray[11];
		m_frameArms = 0.0f;
		m_attackAnimation = true;
	}	
}

void AnimationControl::MeleeAttack()
{
	if (!m_attackAnimation)
	{
		m_currentArms = m_animationStacksArray[10];
		m_frameArms = 0.0f;
		m_attackAnimation = true;
	}
}