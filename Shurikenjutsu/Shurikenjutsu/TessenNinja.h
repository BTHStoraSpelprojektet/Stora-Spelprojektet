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

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name, UINT32 p_color);
	void Shutdown();
	void RenderAttackLocations();
	void UpdateAbilityBar();
	void CheckForSpecialAttack();

private:
	bool m_whipSpinPerformed;
};

#endif