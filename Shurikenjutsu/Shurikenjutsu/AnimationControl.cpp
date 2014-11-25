#include "AnimationControl.h"

bool AnimationControl::CreateNewStack(AnimationStack p_newStack)
{
	m_animationStacks.push_back(p_newStack);

	return true;
}

void AnimationControl::UpdateAnimation()
{

}