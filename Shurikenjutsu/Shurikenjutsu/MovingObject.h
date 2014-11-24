#pragma once
#include "Object.h"
class MovingObject :
	public Object
{
public:
	MovingObject();
	~MovingObject();
	virtual bool Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);
	virtual void Shutdown();
	virtual void SetDirection(DirectX::XMFLOAT3 p_direction);
	virtual DirectX::XMFLOAT3 GetDirection() const;
	virtual void SetSpeed(float p_speed);
	virtual float GetSpeed() const;
private:
	DirectX::XMFLOAT3 m_direction;
	float m_speed;
};

