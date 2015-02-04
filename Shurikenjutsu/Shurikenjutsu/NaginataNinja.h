#ifndef NAGINATANINJA_H_
#define NAGINATANINJA_H_

#include "Player.h"

class NaginataNinja :
	public Player
{
public:
	NaginataNinja();
	~NaginataNinja();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
};

#endif // !NAGINATANINJA_H_