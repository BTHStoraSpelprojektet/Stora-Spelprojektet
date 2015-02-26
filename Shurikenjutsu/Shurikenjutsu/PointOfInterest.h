#ifndef POINTOFINTEREST_H_
#define POINTOFINTEREST_H_

#include "MovingObject.h"

class ParticleEmitter;

class PointOfInterest :
	public MovingObject
{
public:
	PointOfInterest();
	~PointOfInterest();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed);
	void Shutdown();
	void Update();

	void SparkleState(bool p_stateOn);
	bool IsActive();
	void SetActive(bool p_active);
private:
	void Sparkle();

	ParticleEmitter* m_sparkles;
	bool m_active;
};
#endif // !POINTOFINTEREST_H_