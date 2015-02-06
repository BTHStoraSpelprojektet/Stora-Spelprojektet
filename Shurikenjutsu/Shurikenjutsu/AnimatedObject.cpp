#include "AnimatedObject.h"
#include "TextureLibrary.h"
#include "Model.h"
#include "..\CommonLibs\ModelNames.h"

AnimatedObject::AnimatedObject(){}
AnimatedObject::~AnimatedObject(){}

void* AnimatedObject::operator new(size_t p_i)
{
	return _mm_malloc(p_i, 16);
}

void AnimatedObject::operator delete(void* p_p)
{
	_mm_free(p_p);
}

bool AnimatedObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir)
{
	// Players
	if (!Object::Initialize(p_filepath, p_pos))
	{
		return false;
	}

	LoadTexture(p_filepath);

	SetDirection(p_dir);

	for (unsigned int i = 0; i < m_model->GetAnimationStacks().size(); i++)
	{
		m_animationController.CreateNewStack(m_model->GetAnimationStacks()[i]);
	}
	m_animationController.FindAndReferenceLayers();
	m_animationController.HandleInput(p_dir);

	return true;
}

bool AnimatedObject::Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale)
{
	// Map objects
	if (!Object::Initialize(p_filepath, p_pos, p_rotation, p_scale))
	{
		return false;
	}

	m_texture = NULL;

	m_animationController.CreateNewStack(m_model->GetAnimationStacks()[0]);
	m_animationController.CreateNewStack(m_model->GetAnimationStacks()[1]);

	m_animationController.AnimatedObjectLayers();

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

void AnimatedObject::RenderPlayer(int p_team)
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

void AnimatedObject::Render()
{
	GraphicsEngine::RenderAnimated(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_model->GetNormalMap(), m_animationController.GetBoneTransforms());
}

void AnimatedObject::RenderDepth()
{
	GraphicsEngine::RenderAnimatedDepth(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrix(), m_model->GetTexture(), m_animationController.UpdateAnimation());
}

void AnimatedObject::RenderOutlining()
{
	GraphicsEngine::RenderAnimatedOutlining(m_model->GetMesh(), m_model->GetVertexCount(), GetWorldMatrixScaled(1.05f), m_animationController.GetBoneTransforms());
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

void AnimatedObject::LoadTexture(const char* p_filepath)
{
	std::string filePathString = p_filepath;
	int positionToCutStringBegin = filePathString.find_last_of('/');
	filePathString = filePathString.substr((positionToCutStringBegin + 1), filePathString.size());
	int positionToCutStringEnd = filePathString.find_last_of('.');
	filePathString = filePathString.substr(0, positionToCutStringEnd);

	m_texture = TextureLibrary::GetInstance()->GetTexture(NINJA_TEXTURE + filePathString + ".png");
}