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

	bool Initialize(POINTOFINTERESTTYPE p_type, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, DirectX::XMFLOAT3 p_lightColor);
	void Shutdown();
	void Update();
	void Render();

	void SparkleState(bool p_stateOn);
	bool IsActive();
	void SetActive(bool p_active);
	void SpawnLight();
	void PickedUp();

	POINTOFINTERESTTYPE GetType();
private:
	void Sparkle();

	ParticleEmitter* m_sparkles;
	bool m_active;

	DirectX::XMFLOAT3 m_positionLight;
	DirectX::XMFLOAT3 m_lightColor;

	POINTOFINTERESTTYPE m_type;
};
#endif // !POINTOFINTEREST_H_