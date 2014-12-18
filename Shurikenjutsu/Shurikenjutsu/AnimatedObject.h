#ifndef ANIMATEDOBJECT_H_
#define ANIMATEDOBJECT_H_

#include "Object.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject();
	~AnimatedObject();
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);
	virtual void Shutdown();
	virtual void SetDirection(DirectX::XMFLOAT3 p_direction);
	virtual DirectX::XMFLOAT3 GetDirection();
	virtual void SetSpeed(float p_speed);
	virtual float GetSpeed() const;

	void RenderAnimated(SHADERTYPE p_shader);
	void RangeAttackAnimation();
	void MeleeAttackAnimation();
	void HandleInput();

protected:
	DirectX::XMFLOAT3 m_direction;
	float m_speed;

private:
	AnimationControl m_animationController;
};

#endif ANIMATEDOBJECT_H_