#ifndef TESSENNINJA_H_
#define TESSENNINJA_H_

#include "Player.h"

class TessenNinja : public Player
{
public:
	TessenNinja();
	~TessenNinja();

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
};

#endif