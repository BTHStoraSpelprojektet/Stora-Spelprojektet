#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(){}

AnimatedObject::~AnimatedObject(){}

bool AnimatedObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos)
{
	if (!Object::Initialize(p_filepath, p_pos))
	{
		return false;
	}

	for (unsigned i = 0; i < m_model->GetAnimationStacks().size(); i++)
	{
		m_animationController.CreateNewStack(m_model->GetAnimationStacks()[i]);
	}
	return true;
}

void AnimatedObject::RenderAnimated(SHADERTYPE p_shader)
{
	GraphicsEngine::Render(p_shader, m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), 0, m_animationController.UpdateAnimation(GLOBAL::GetInstance().DELTATIME));
}
