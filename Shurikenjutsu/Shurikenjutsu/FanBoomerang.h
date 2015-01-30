#ifndef FANBOOMERANG_H_
#define FANBOOMERANG_H_

#include "MovingObject.h"

class FanBoomerang : public MovingObject
{
public:
	FanBoomerang();
	~FanBoomerang();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id);

	unsigned int GetID();
	//void Shutdown();

	void Update(float p_x, float p_y, float p_z, float p_dirX, float p_dirY, float p_dirZ, float p_speed);

private:
	unsigned int m_id;
};

#endif