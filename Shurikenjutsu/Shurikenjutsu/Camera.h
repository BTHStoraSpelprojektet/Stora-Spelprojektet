#ifndef CAMERA
#define CAMERA

#include <DirectXMath.h>

class Sound;

class Camera
{
public:
	bool Initialize();
	void Shutdown();

	void UpdateViewMatrix();
	void UpdateProjectionMatrix(bool p_orthographic);
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
	DirectX::XMFLOAT3 GetLookAt();
	DirectX::XMFLOAT4X4 GetViewMatrix();
	DirectX::XMFLOAT4X4 GetProjectionMatrix();

	void ResetCamera();
	void ResetCameraToLight();

	void HandleInput();
	void ToggleFullscreen(bool p_fullscreen);
	void FollowCharacter(DirectX::XMFLOAT3 p_playerPos);

	void MenuCameraRotation();

	void MovingCamera(DirectX::XMFLOAT3 p_playerPos);

	//void Update3DSound(Sound* p_sound);
	void Update3DSound(Sound* p_sound, float p_x, float p_y, float p_z);
	void SetOutliningRayPosition(DirectX::XMFLOAT3 p_position);
	DirectX::XMFLOAT3 GetOutliningRayPosition();
	void SetOutliningRayTarget(DirectX::XMFLOAT3 p_target);
	DirectX::XMFLOAT3 GetOutliningRayTarget();
	
private:
	DirectX::XMVECTOR SmoothStep(DirectX::XMVECTOR V0, DirectX::XMVECTOR V1, float t);

	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_target;
	DirectX::XMFLOAT3 m_look;
	DirectX::XMFLOAT3 m_upVector;
	DirectX::XMFLOAT3 m_right;
	DirectX::XMFLOAT3 m_oldPosition;
	DirectX::XMFLOAT3 m_outliningRayPosition;
	DirectX::XMFLOAT3 m_outliningRayTarget;

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

	float timerTesting;

	DirectX::XMFLOAT4X4 m_positionMatrix;
	DirectX::XMFLOAT4X4 m_rotationX;
	DirectX::XMFLOAT4X4 m_rotationY;

	float m_menuRotation;
};
#endif;