#ifndef AWTTACKPREDICTIONEDITOR_H_
#define AWTTACKPREDICTIONEDITOR_H_

#include "Object.h"
class AttackPredictionEditor
{
public:
	static void NormalMeleeAttackCone(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition);
	static void ThinArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition);
	static void ThickArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition);
	static void ThickArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_maxLeangth);
	static void ThickRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length);
	static void ThinRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length);
	static void ThrowSphere(Object *p_object, float p_radius);
	static void SpinAttackBigSphere(Object *p_object, DirectX::XMFLOAT3 p_playerPosition, float p_radius);
};

#endif

