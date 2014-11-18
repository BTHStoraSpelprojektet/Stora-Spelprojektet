#include "Camera.h"

bool Camera::Initialize()
{
	m_position = DirectX::XMVectorSet(0, 0, 0, 0);
	m_target = DirectX::XMVectorSet(0, 0, 0, 0);
	m_upVector = DirectX::XMVectorSet(0, 0, 0, 0);

	m_fieldOfView = 0;
	m_aspectRatio = 0;
	m_nearPlane = 0;
	m_farPlane = 0;

	m_viewMatrix = DirectX::XMMatrixIdentity();
	m_projectionMatrix = DirectX::XMMatrixIdentity();

	return true;
}

void Camera::UpdatePosition(DirectX::XMVECTOR p_position)
{
	// Set the camera position.
	m_position = p_position;
}

void Camera::UpdateTarget(DirectX::XMVECTOR p_target)
{
	// Set the camera target.
	m_target = p_target;
}

void Camera::UpdateUpVector(DirectX::XMVECTOR p_upVector)
{
	// Set the camera up vector.
	m_upVector = p_upVector;
}

void Camera::UpdateFieldOfView(float p_fieldOfView)
{
	// Set the camera field of view.
	m_fieldOfView = p_fieldOfView;
}

void Camera::UpdateAspectRatio(float p_aspectRatio)
{
	// Set the camera aspect ratio.
	m_aspectRatio = p_aspectRatio;
}

void Camera::UpdateClippingPlanes(float p_nearPlane, float p_farPlane)
{
	// Set clipping planes.
	m_nearPlane = p_nearPlane;
	m_farPlane = p_farPlane;
}

void Camera::UpdateRight(DirectX::XMVECTOR p_right)
{
	m_right = p_right;
}

void Camera::UpdateLook(DirectX::XMVECTOR p_look)
{
	m_look = p_look;
}

void Camera::UpdateViewMatrix()
{
	// Update view matrix.
	m_viewMatrix = DirectX::XMMatrixLookAtLH(m_position, m_target, m_upVector);
}

void Camera::UpdateProjectionMatrix()
{
	// Update projection matrix.
	m_projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(m_fieldOfView, m_aspectRatio, m_nearPlane, m_farPlane);
}

void Camera::Walk(float p_value)
{
	DirectX::XMVECTOR look = DirectX::XMVectorSet(p_value * m_look.m128_f32[0], p_value * m_look.m128_f32[1], p_value * m_look.m128_f32[2], 0);
	m_position = DirectX::XMVectorSet(m_position.m128_f32[0] + look.m128_f32[0], m_position.m128_f32[1] + look.m128_f32[1], m_position.m128_f32[2] + look.m128_f32[2], 0);
}

void Camera::Strafe(float p_value)
{
	DirectX::XMVECTOR right = DirectX::XMVectorSet(p_value * m_right.m128_f32[0], p_value * m_right.m128_f32[1], p_value * m_right.m128_f32[2], 0);
	m_position = DirectX::XMVectorSet(m_position.m128_f32[0] + right.m128_f32[0], m_position.m128_f32[1] + right.m128_f32[1], m_position.m128_f32[2] + right.m128_f32[2], 0);
}

void Camera::Pitch(float p_angle)
{
	DirectX::XMMATRIX pitch;
	pitch = DirectX::XMMatrixRotationAxis(m_right, p_angle);

	m_upVector = DirectX::XMVector3TransformNormal(m_upVector, pitch);

	m_look = DirectX::XMVector3TransformNormal(m_look, pitch);
}

void Camera::Rotate(float p_angle)
{
	DirectX::XMMATRIX rotation;
	rotation = DirectX::XMMatrixRotationY(p_angle);

	m_right = DirectX::XMVector3TransformNormal(m_right, rotation);
	m_upVector = DirectX::XMVector3TransformNormal(m_upVector, rotation);
	m_look = DirectX::XMVector3TransformNormal(m_look, rotation);
}

void Camera::UpdateMovedCamera()
{
	DirectX::XMVECTOR R = m_right;
	DirectX::XMVECTOR U = m_upVector;
	DirectX::XMVECTOR L = m_look;
	DirectX::XMVECTOR P = m_position;

	L = DirectX::XMVector3Normalize(L);

	U = DirectX::XMVector3Cross(L, R);
	U = DirectX::XMVector3Normalize(U);

	R = DirectX::XMVector3Cross(U, L);
	R = DirectX::XMVector3Normalize(R);

	float x = -DirectX::XMVector3Dot(P, R).m128_f32[0];
	float y = -DirectX::XMVector3Dot(P, U).m128_f32[1];
	float z = -DirectX::XMVector3Dot(P, L).m128_f32[2];

	m_right = R;
	m_upVector = U;
	m_look = L;

	// Build view matrix.
	m_viewMatrix.r[0] = DirectX::XMVectorSet(m_right.m128_f32[0], m_right.m128_f32[1], m_right.m128_f32[2], x);
	m_viewMatrix.r[1] = DirectX::XMVectorSet(m_upVector.m128_f32[0], m_upVector.m128_f32[1], m_upVector.m128_f32[2], y);
	m_viewMatrix.r[2] = DirectX::XMVectorSet(m_look.m128_f32[0], m_look.m128_f32[1], m_look.m128_f32[2], z);
	m_viewMatrix.r[3] = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
}

DirectX::XMVECTOR Camera::GetPosition()
{
	// Return view matrix
	return m_position;
}

DirectX::XMMATRIX Camera::GetViewMatrix()
{
	// Return view matrix
	return m_viewMatrix;
}

DirectX::XMMATRIX Camera::GetProjectionMatrix()
{
	// Return projection matrix.
	return m_projectionMatrix;
}