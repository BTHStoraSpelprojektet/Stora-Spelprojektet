#include "AnimatedObject.h"
#include "TextureLibrary.h"
#include "Model.h"

AnimatedObject::AnimatedObject(){}
AnimatedObject::~AnimatedObject(){}

bool AnimatedObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed)
{
	if (!Object::Initialize(p_filepath, p_pos))
	{
		return false;
	}

	m_texture = TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/char_bluetext.png");

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

void AnimatedObject::Render(int p_team)
{
	if (p_team == 1)
	{
		GraphicsEngine::RenderAnimated(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), m_animationController.GetBoneTransforms());
	}
	else
	{
		GraphicsEngine::RenderAnimated(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_texture, m_model->GetNormalMap(), m_animationController.GetBoneTransforms());
	}	
}

void AnimatedObject::RenderDepth()
{
	GraphicsEngine::RenderAnimatedDepth(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_animationController.UpdateAnimation());
}

void AnimatedObject::RenderOutlining()
{
	GraphicsEngine::RenderAnimatedOutlining(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), m_animationController.GetBoneTransforms());
}

void AnimatedObject::ChangeAnimationState(AnimationState p_newState)
{
	m_animationController.ChangeAnimationState(p_newState);
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

