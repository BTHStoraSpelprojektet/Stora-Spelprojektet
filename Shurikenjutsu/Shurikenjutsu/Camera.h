#ifndef CAMERA
#define CAMERA

#include <Windows.h>
#include <DirectXMath.h>
#include "Globals.h"
#include "GraphicsEngine.h"
#include "InputManager.h"
class Camera
{
public:
	bool Initialize();
	void Shutdown();

	void UpdateViewMatrix();
	void UpdateProjectionMatrix();
	void UpdateMovedCamera();

	void UpdatePosition(DirectX::XMFLOAT3 p_position);
	void UpdateTarget(DirectX::XMFLOAT3 p_target);
	void UpdateLook(DirectX::XMFLOAT3 p_look);
	void UpdateUpVector(DirectX::XMFLOAT3 p_upVector);
	void UpdateRight(DirectX::XMFLOAT3 p_right);

	void Walk(float p_value);
	void Strafe(float p_value);
	void Pitch(float p_angle);
	void Rotate(float p_angle);

	void UpdateFieldOfView(float p_fieldOfView);
	void UpdateAspectRatio(float p_aspectRatio);
	void UpdateClippingPlanes(float p_nearPlane, float p_farPlane);

	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT4X4 GetViewMatrix();
	DirectX::XMFLOAT4X4 GetProjectionMatrix();

	void ResetCamera();
	void ResetCameraToLight();

	void MoveCamera(double p_deltaTime);
	void ToggleFullscreen(bool p_fullscreen);
	void FollowCharacter(DirectX::XMFLOAT3 p_playerPos);

private:
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_target;
	DirectX::XMFLOAT3 m_look;
	DirectX::XMFLOAT3 m_upVector;
	DirectX::XMFLOAT3 m_right;

	float m_fieldOfView;
	float m_aspectRatio;
	float m_nearPlane;
	float m_farPlane;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	int m_newX;
	int m_newY;
	int m_oldX;
	int m_oldY;

	float m_oldMouseX;
	float m_oldMouseY;

	DirectX::XMFLOAT4X4 m_positionMatrix;
	DirectX::XMFLOAT4X4 m_rotationX;
	DirectX::XMFLOAT4X4 m_rotationY;
};
#endif;