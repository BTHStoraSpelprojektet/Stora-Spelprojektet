#ifndef FANBOOMERANG_H_
#define FANBOOMERANG_H_

#include "MovingObject.h"
#include "..\CommonLibs\RakNet\RakNetTypes.h"

class FanBoomerang : public MovingObject
{
public:
	FanBoomerang();
	~FanBoomerang();

	bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_dir, float p_speed, unsigned int p_id, RakNet::RakNetGUID p_owner);

	unsigned int GetID();
	//void Shutdown();

	void Update(bool p_dead);

private:
	unsigned int m_id;
	RakNet::RakNetGUID m_owner;
};

#endif