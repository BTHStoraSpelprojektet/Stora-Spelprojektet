#include "AttackPredictionEditor.h"
#include "InputManager.h"

void AttackPredictionEditor::NormalMeleeAttackCone(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - p_playerPosition.x, 0.03f, mousePos3D.z - p_playerPosition.z);
	float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
	DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
	float yaw = atan2(p_attackDirection.x, p_attackDirection.z);

	p_object->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x + vectorToMouseNorm.x *1.7f, 0.03f, p_playerPosition.z + vectorToMouseNorm.z*1.7f));
	p_object->SetRotation(DirectX::XMFLOAT3(0.0f, yaw, 0.0f));
	p_object->SetScale(DirectX::XMFLOAT3(3.0f, 2.0f, 2.0f));
}