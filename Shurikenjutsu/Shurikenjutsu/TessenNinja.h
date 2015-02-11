#ifndef TESSENNINJA_H_
#define TESSENNINJA_H_

#include "Player.h"

class TessenNinja : public Player
{
public:
	TessenNinja();
	~TessenNinja();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr);
	void Shutdown();
};

#endif