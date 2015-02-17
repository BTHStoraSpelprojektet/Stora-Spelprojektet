#ifndef AWTTACKPREDICTIONEDITOR_H_
#define AWTTACKPREDICTIONEDITOR_H_

#include "Object.h"
class AttackPredictionEditor
{
public:
	static void NormalMeleeAttackCone(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition);
};

#endif