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

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name, UINT32 p_color);
	void Shutdown();
	void RenderAttackLocations();


};

#endif // !NAGINATANINJA_H_