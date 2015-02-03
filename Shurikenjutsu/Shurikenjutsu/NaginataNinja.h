#ifndef NAGINATANINJA_H_
#define NAGINATANINJA_H_

#include "Player.h"

class NaginataNinja :
	public Player
{
public:
	NaginataNinja();
	~NaginataNinja();

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
};

#endif // !NAGINATANINJA_H_