#ifndef ANIMATEDOBJECT_H_
#define ANIMATEDOBJECT_H_

#include "Object.h"
#include "AnimationControl.h"

class Trail;

class AnimatedObject : public Object
{
public:
	AnimatedObject();
	~AnimatedObject();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale);
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir);
	virtual void Shutdown();
	virtual void SetDirection(DirectX::XMFLOAT3 p_direction);
	virtual DirectX::XMFLOAT3 GetDirection();
	virtual void SetSpeed(float p_speed);
	virtual float GetSpeed() const;

	void RenderPlayer(int p_team);
	void Render();
	void RenderDepth();
	void RenderDepthOutlining();
	void RenderOutlining(DirectX::XMFLOAT4 p_color);
	void ChangeAnimationState(AnimationState p_newState);
	void HandleInput(DirectX::XMFLOAT3 p_dir);
	void NetworkInput(DirectX::XMFLOAT3 p_dir);
	void SetIkDirection(DirectX::XMFLOAT3 p_ikDirection);

	void ChangeTrailColor(int p_team);

protected:
	DirectX::XMFLOAT3 m_direction;
	float m_speed;

private:
	void LoadTexture(const char* p_filepath);

	AnimationControl m_animationController;

	ID3D11ShaderResourceView* m_texture;

	Trail* m_trail;
};

#endif ANIMATEDOBJECT_H_