#include "Camera.h"

bool Camera::Initialize()
{
	m_position = DirectX::XMFLOAT3(0, 0, 0);
	m_target = DirectX::XMFLOAT3(0, 0, 0);
	m_upVector = DirectX::XMFLOAT3(0, 0, 0);

	m_fieldOfView = 0;
	m_aspectRatio = 0;
	m_nearPlane = 0;
	m_farPlane = 0;

	m_upVector = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);
	m_look = DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f);
	m_right = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);


	DirectX::XMStoreFloat4x4(&m_viewMatrix,DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_projectionMatrix, DirectX::XMMatrixIdentity());

	return true;
}

void Camera::UpdatePosition(DirectX::XMFLOAT3 p_position)
{
	// Set the camera position.
	m_position = p_position;
}

void Camera::UpdateTarget(DirectX::XMFLOAT3 p_target)
{
	// Set the camera target.
	m_target = p_target;
}

void Camera::UpdateUpVector(DirectX::XMFLOAT3 p_upVector)
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

void Camera::UpdateRight(DirectX::XMFLOAT3 p_right)
{
	m_right = p_right;
}

void Camera::UpdateLook(DirectX::XMFLOAT3 p_look)
{
	m_look = p_look;
}

void Camera::UpdateViewMatrix()
{
	m_upVector = DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f);

	// Update view matrix.
	DirectX::XMStoreFloat4x4(&m_viewMatrix, DirectX::XMMatrixLookAtLH(DirectX::XMLoadFloat3(&m_position), DirectX::XMLoadFloat3(&m_target), DirectX::XMLoadFloat3(&m_upVector)));
}

void Camera::UpdateProjectionMatrix()
{
	// Update projection matrix.
	DirectX::XMStoreFloat4x4(&m_projectionMatrix, DirectX::XMMatrixPerspectiveFovLH(m_fieldOfView, m_aspectRatio, m_nearPlane, m_farPlane));
}

void Camera::Walk(float p_value)
{
	DirectX::XMFLOAT3 look = DirectX::XMFLOAT3(p_value * m_look.x, p_value * m_look.y, p_value * m_look.z);
	m_position = DirectX::XMFLOAT3(m_position.x + look.x, m_position.y + look.y, m_position.z + look.z);
}

void Camera::Strafe(float p_value)
{
	DirectX::XMFLOAT3 right = DirectX::XMFLOAT3(p_value * m_right.x, p_value * m_right.y, p_value * m_right.z);
	m_position = DirectX::XMFLOAT3(m_position.x + right.x, m_position.y + right.y, m_position.z + right.z);
}

void Camera::Pitch(float p_angle)
{
	DirectX::XMFLOAT4X4 pitch;
	DirectX::XMStoreFloat4x4(&pitch, DirectX::XMMatrixRotationAxis(DirectX::XMLoadFloat3(&m_right), p_angle));

	DirectX::XMStoreFloat3(&m_upVector, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_upVector), DirectX::XMLoadFloat4x4(&pitch)));

	DirectX::XMStoreFloat3(&m_look, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_look), DirectX::XMLoadFloat4x4(&pitch)));
}

void Camera::Rotate(float p_angle)
{
	DirectX::XMFLOAT4X4 rotation;
	DirectX::XMStoreFloat4x4(&rotation, DirectX::XMMatrixRotationY(p_angle));

	DirectX::XMStoreFloat3(&m_right, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_right), DirectX::XMLoadFloat4x4(&rotation)));
	DirectX::XMStoreFloat3(&m_upVector, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_upVector), DirectX::XMLoadFloat4x4(&rotation)));
	DirectX::XMStoreFloat3(&m_look, DirectX::XMVector3TransformNormal(DirectX::XMLoadFloat3(&m_look), DirectX::XMLoadFloat4x4(&rotation)));
}

void Camera::UpdateMovedCamera()
{
	DirectX::XMFLOAT3 R = m_right;
	DirectX::XMFLOAT3 U = m_upVector;
	DirectX::XMFLOAT3 L = m_look;
	DirectX::XMFLOAT3 P = m_position;

	DirectX::XMStoreFloat3(&L, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&L)));

	DirectX::XMStoreFloat3(&U, DirectX::XMVector3Cross(DirectX::XMLoadFloat3(&L), DirectX::XMLoadFloat3(&R)));
	DirectX::XMStoreFloat3(&U, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&U)));

	DirectX::XMStoreFloat3(&R, DirectX::XMVector3Cross(DirectX::XMLoadFloat3(&U), DirectX::XMLoadFloat3(&L)));
	DirectX::XMStoreFloat3(&R, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&R)));

	float x;
	float y;
	float z;

	DirectX::XMStoreFloat(&x, DirectX::XMVector3Dot(DirectX::XMLoadFloat3(&P), DirectX::XMLoadFloat3(&R)));
	DirectX::XMStoreFloat(&y, DirectX::XMVector3Dot(DirectX::XMLoadFloat3(&P), DirectX::XMLoadFloat3(&U)));
	DirectX::XMStoreFloat(&z, DirectX::XMVector3Dot(DirectX::XMLoadFloat3(&P), DirectX::XMLoadFloat3(&L)));

	m_right = R;
	m_upVector = U;
	m_look = L;

	// Build view matrix.
	m_viewMatrix._11 = m_right.x;
	m_viewMatrix._21 = m_right.y;
	m_viewMatrix._31 = m_right.z;
	m_viewMatrix._41 = -x;

	m_viewMatrix._12 = m_upVector.x;
	m_viewMatrix._22 = m_upVector.y;
	m_viewMatrix._32 = m_upVector.z;
	m_viewMatrix._42 = -y;

	m_viewMatrix._13 = m_look.x;
	m_viewMatrix._23 = m_look.y;
	m_viewMatrix._33 = m_look.z;
	m_viewMatrix._43 = -z;

	m_viewMatrix._14 = 0.0f;
	m_viewMatrix._24 = 0.0f;
	m_viewMatrix._34 = 0.0f;
	m_viewMatrix._44 = 1.0f;

}

DirectX::XMFLOAT3 Camera::GetPosition()
{
	// Return view matrix
	return m_position;
}

DirectX::XMFLOAT4X4 Camera::GetViewMatrix()
{
	// Return view matrix
	return m_viewMatrix;
}

DirectX::XMFLOAT4X4 Camera::GetProjectionMatrix()
{
	// Return projection matrix.
	return m_projectionMatrix;
}