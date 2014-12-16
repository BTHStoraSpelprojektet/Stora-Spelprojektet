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
	return true;
}

void AnimatedObject::Shutdown()
{
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

void AnimatedObject::RenderAnimated(SHADERTYPE p_shader)
{
	GraphicsEngine::Render(p_shader, m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), 0, m_animationController.UpdateAnimation());
}
