#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(){}

AnimatedObject::~AnimatedObject(){}

bool AnimatedObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	if (!Object::Initialize(p_filepath, p_pos))
	{
		return false;
	}

	SetDirection(p_dir);
	SetSpeed(p_speed);

	for (unsigned i = 0; i < m_model->GetAnimationStacks().size(); i++)
	{
		m_animationController.CreateNewStack(m_model->GetAnimationStacks()[i]);
	}
	m_animationController.FindAndReferenceLayers();
	m_animationController.HandleInput(p_dir);

	return true;
}

void AnimatedObject::Shutdown()
{
	m_animationController.Shutdown();
	Object::Shutdown();
}

void AnimatedObject::SetDirection(DirectX::XMFLOAT3 p_direction)
{
	m_direction = p_direction;
}

DirectX::XMFLOAT3 AnimatedObject::GetDirection()
{
	return m_direction;
}

void AnimatedObject::SetSpeed(float p_speed)
{
	m_speed = p_speed;
}

float AnimatedObject::GetSpeed() const
{
	return m_speed;
}

void AnimatedObject::Render()
{
	GraphicsEngine::RenderAnimated(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), m_animationController.UpdateAnimation());
}

void AnimatedObject::RangeAttackAnimation()
{
	m_animationController.RangeAttack();
}

void AnimatedObject::MeleeAttackAnimation()
{
	m_animationController.MeleeAttack();
}

void AnimatedObject::HandleInput(DirectX::XMFLOAT3 p_dir)
{
	m_animationController.HandleInput(p_dir);
}

void AnimatedObject::NetworkInput(DirectX::XMFLOAT3 p_dir)
{
	m_animationController.NetworkInput(p_dir);
}

void AnimatedObject::SetIkDirection(DirectX::XMFLOAT3 p_ikDirection)
{
	m_animationController.SetIkDirection(p_ikDirection);
}