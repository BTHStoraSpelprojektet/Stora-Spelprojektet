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
void AttackPredictionEditor::ThinArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - p_playerPosition.x, 0.03f, mousePos3D.z - p_playerPosition.z);
	float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
	DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
	float yaw = atan2(p_attackDirection.x, p_attackDirection.z);

	p_arrowHead->SetPosition(DirectX::XMFLOAT3(mousePos3D));
	p_arrowBody->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x + vectorToMouseNorm.x * (poleLength * 0.5f), 0.03f, p_playerPosition.z + vectorToMouseNorm.z * (poleLength * 0.5f)));

	p_arrowHead->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));
	p_arrowBody->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

	p_arrowHead->SetScale(DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	p_arrowBody->SetScale(DirectX::XMFLOAT3(poleLength * 10.0f, 1.0f, 1.0f));
}
void AttackPredictionEditor::ThickArrowPrediction(Object *p_arrowHead, Object *p_arrowBody, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - p_playerPosition.x, 0.03f, mousePos3D.z - p_playerPosition.z);
	float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
	DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
	float yaw = atan2(p_attackDirection.x, p_attackDirection.z);

	p_arrowHead->SetPosition(DirectX::XMFLOAT3(mousePos3D));
	p_arrowBody->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x + vectorToMouseNorm.x * (poleLength * 0.5f), 0.03f, p_playerPosition.z + vectorToMouseNorm.z * (poleLength * 0.5f)));

	p_arrowHead->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));
	p_arrowBody->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

	p_arrowHead->SetScale(DirectX::XMFLOAT3(5.0f, 1.0f, 5.0f));
	p_arrowBody->SetScale(DirectX::XMFLOAT3(poleLength * 10.0f, 1.0f, 5.0f));
}
void AttackPredictionEditor::ThickRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - p_playerPosition.x, 0.03f, mousePos3D.z - p_playerPosition.z);
	float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
	DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
	float yaw = atan2(p_attackDirection.x, p_attackDirection.z);

	p_object->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

	p_object->SetScale(DirectX::XMFLOAT3(9.0f * p_length, 1.0f, 5.0f));

	p_object->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x + vectorToMouseNorm.x * 4.5f, 0.03f, p_playerPosition.z + vectorToMouseNorm.z * 4.5f));
}
void AttackPredictionEditor::ThinRectanglePrediction(Object *p_object, DirectX::XMFLOAT3 p_attackDirection, DirectX::XMFLOAT3 p_playerPosition, float p_length)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	DirectX::XMFLOAT3 vectorToMouse = DirectX::XMFLOAT3(mousePos3D.x - p_playerPosition.x, 0.03f, mousePos3D.z - p_playerPosition.z);
	float poleLength = sqrt(vectorToMouse.x * vectorToMouse.x + vectorToMouse.z * vectorToMouse.z);
	DirectX::XMFLOAT3 vectorToMouseNorm = DirectX::XMFLOAT3(vectorToMouse.x / poleLength, 0.03f, vectorToMouse.z / poleLength);
	float yaw = atan2(p_attackDirection.x, p_attackDirection.z);

	p_object->SetRotation(DirectX::XMFLOAT3(0.0f, yaw - 1.57f, 0.0f));

	p_object->SetScale(DirectX::XMFLOAT3(10.0f * p_length, 1.0f, 1.0f));

	p_object->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x + vectorToMouseNorm.x * (p_length * 0.5f), 0.03f, p_playerPosition.z + vectorToMouseNorm.z * (p_length * 0.5f)));
}
void AttackPredictionEditor::ThrowSphere(Object *p_object, float p_radius)
{
	DirectX::XMFLOAT3 mousePos3D = DirectX::XMFLOAT3(InputManager::GetInstance()->Get3DMousePositionX(), 0.03f, InputManager::GetInstance()->Get3DMousePositionZ());
	p_object->SetPosition(mousePos3D);
	p_object->SetScale(DirectX::XMFLOAT3(p_radius, p_object->GetScale().y, p_radius));
}
void AttackPredictionEditor::SpinAttackBigSphere(Object *p_object, DirectX::XMFLOAT3 p_playerPosition, float p_radius)
{
	p_object->SetPosition(DirectX::XMFLOAT3(p_playerPosition.x, 0.03f, p_playerPosition.z));
	p_object->SetScale(DirectX::XMFLOAT3(p_radius, p_object->GetScale().y, p_radius));
}