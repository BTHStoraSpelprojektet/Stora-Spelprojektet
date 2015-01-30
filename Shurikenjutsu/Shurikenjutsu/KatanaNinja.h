#ifndef KATANANINJA_H_
#define KATANANINJA_H_

#include "Player.h"

class KatanaNinja : public Player
{
public:
	KatanaNinja();
	~KatanaNinja();

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
};

#endif