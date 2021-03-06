#ifndef VOLLEYOBJECT_H_
#define VOLLEYOBJECT_H_

#include "MovingObject.h"

class VolleyObject : public MovingObject
{
public:
	VolleyObject();
	~VolleyObject();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_startPos, DirectX::XMFLOAT3 p_endPos);
	void Shutdown();
	bool Update(float p_timer);

private:
	DirectX::XMFLOAT3 m_startPosition;
	DirectX::XMFLOAT3 m_lastPosition;
	DirectX::XMFLOAT3 m_endPosition;
	float m_angle;
	float m_speedY;
	float m_percentX;
	float m_percentZ;
	float m_timeToLand;
	float m_lifeTime;
};

#endif