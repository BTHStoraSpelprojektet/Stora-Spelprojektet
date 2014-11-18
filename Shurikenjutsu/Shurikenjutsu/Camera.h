#ifndef CAMERA
#define CAMERA

#include <DirectXMath.h>

class Camera
{
public:
	bool Initialize();

	void UpdateViewMatrix();
	void UpdateProjectionMatrix();
	void UpdateMovedCamera();

	void UpdatePosition(DirectX::XMVECTOR p_position);
	void UpdateTarget(DirectX::XMVECTOR p_target);
	void UpdateLook(DirectX::XMVECTOR p_look);
	void UpdateUpVector(DirectX::XMVECTOR p_upVector);
	void UpdateRight(DirectX::XMVECTOR p_right);

	void Walk(float p_value);
	void Strafe(float p_value);
	void Pitch(float p_angle);
	void Rotate(float p_angle);

	void UpdateFieldOfView(float p_fieldOfView);
	void UpdateAspectRatio(float p_aspectRatio);
	void UpdateClippingPlanes(float p_nearPlane, float p_farPlane);

	DirectX::XMVECTOR GetPosition();
	DirectX::XMMATRIX GetViewMatrix();
	DirectX::XMMATRIX GetProjectionMatrix();

private:
	DirectX::XMVECTOR m_position;
	DirectX::XMVECTOR m_target;
	DirectX::XMVECTOR m_look;
	DirectX::XMVECTOR m_upVector;
	DirectX::XMVECTOR m_right;

	float m_fieldOfView;
	float m_aspectRatio;
	float m_nearPlane;
	float m_farPlane;

	DirectX::XMMATRIX m_viewMatrix;
	DirectX::XMMATRIX m_projectionMatrix;

	int m_newX;
	int m_newY;
	int m_oldX;
	int m_oldY;

	DirectX::XMMATRIX m_positionMatrix;
	DirectX::XMMATRIX m_rotationX;
	DirectX::XMMATRIX m_rotationY;
};
#endif;