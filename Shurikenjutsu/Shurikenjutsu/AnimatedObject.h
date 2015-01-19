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

	void Render();
	void RangeAttackAnimation();
	void MeleeAttackAnimation();
	void HandleInput(DirectX::XMFLOAT3 p_dir);
	void NetworkInput(DirectX::XMFLOAT3 p_dir);
	void SetIkDirection(DirectX::XMFLOAT3 p_ikDirection);

protected:
	DirectX::XMFLOAT3 m_direction;
	float m_speed;

private:
	AnimationControl m_animationController;
};

#endif ANIMATEDOBJECT_H_