#ifndef AWTTACKPREDICTIONEDITOR_H_
#define AWTTACKPREDICTIONEDITOR_H_

#include <DirectXMath.h>
class Object;

class AttackPredictionEditor
{
public:
	static void NormalMeleeAttackCone(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_range);
	static void ThinArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, bool p_throwStuff);
	static void ThickArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, bool p_throwStuff);
	static void ThickArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_maxLeangth, bool p_throwStuff);
	static void ThickRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length);
	static void ThinRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length);
	static void ThrowSphere(Object *p_object, DirectX::XMFLOAT3 p_playerPosition, float p_radius, float p_maxRange);
	static void SpinAttackBigSphere(Object *p_object, DirectX::XMFLOAT3 p_playerPosition, float p_radius);
};

#endif

