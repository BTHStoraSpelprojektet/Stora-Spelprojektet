#ifndef ANIMATIONCONTROL
#define ANIMATIONCONTROL

#include <vector>
#include <string>
#include "Structures.h"
#include "..\CommonLibs\CommonEnums.h"

class AnimationControl
{
public:
	bool CreateNewStack(AnimationStack p_newStack);
	std::vector<DirectX::XMFLOAT4X4> UpdateAnimation();

	bool IsAnimated();
	void SetIkDirection(DirectX::XMFLOAT3 p_direction);
	void ChangeAnimationState(AnimationState p_newState);

	void HandleInput(DirectX::XMFLOAT3 p_dir);
	void NetworkInput(DirectX::XMFLOAT3 p_dir);

	void FindAndReferenceLayers();

	void Shutdown();

	
	
private:
	void CombineMatrices(int* p_index, BoneFrame* p_jointArms, BoneFrame* p_jointLegs, DirectX::XMVECTOR& p_parentQuaternion, DirectX::XMVECTOR& p_parentTranslation);
	DirectX::XMVECTOR ApplyIK(DirectX::XMVECTOR& p_quaternion);	

	void ApplyLegDirection(DirectX::XMVECTOR& p_direction, float p_directionAngle, float p_cross);
	void ApplyLegDirectionNetwork(DirectX::XMVECTOR& p_direction, float p_directionAngle, float p_cross);

	float CalculateLegDirection(float p_forwardAngle);

	std::vector<AnimationStack> m_animationStacks;
	AnimationStack* m_animationStacksArray;

	double m_frameArms;
	double m_frameLegs;

	bool m_attackAnimation;

	DirectX::XMVECTOR m_ikDirection;
	DirectX::XMVECTOR m_ikLegDirection;
	DirectX::XMVECTOR m_forwardDirection;
	DirectX::XMVECTOR m_rotationAxis;
	float m_hipRotation;

	AnimationStack m_currentArms;
	AnimationStack m_currentLegs;

	std::vector<DirectX::XMFLOAT4X4> m_boneTransforms;
	std::vector<BindPose> m_bindPoses;
};

#endif;