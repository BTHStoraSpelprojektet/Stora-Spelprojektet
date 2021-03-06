#ifndef KATANANINJA_H_
#define KATANANINJA_H_

#include "Player.h"
class AttackPredictionEditor;

class KatanaNinja : public Player
{
public:
	KatanaNinja();
	~KatanaNinja();

	void* operator new(size_t p_i);
	void operator delete(void* p_p);

	bool Initialize(DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction, int p_charNr, std::string p_name, UINT32 p_color);
	void Shutdown();
	void RenderAttackLocations();
	void UpdateAbilityBar();
	void CheckForSpecialAttack();

private:
};

#endif