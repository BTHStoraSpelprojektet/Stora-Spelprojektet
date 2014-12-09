#ifndef ANIMATEDOBJECT_H_
#define ANIMATEDOBJECT_H_

#include "Object.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject();
	~AnimatedObject();
	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos);
	void RenderAnimated(SHADERTYPE p_shader);

private:
	AnimationControl m_animationController;
};

#endif // !ANIMATEDOBJECT_H_