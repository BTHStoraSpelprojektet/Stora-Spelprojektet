#include "Camera.h"


Camera::Camera(){}


Camera::~Camera(){}



void Camera::Shutdown()
{

}

void Camera::Initialize()
{
	DirectX::XMVECTOR m_position = DirectX::XMVectorSet(0, 5, 0, 0);
	DirectX::XMVECTOR m_rotation = DirectX::XMVectorSet(0, 0, 0, 0);
}

void Camera::UpdateViewMatrix()
{
	// Rotate look and up vectors
	DirectX::XMMATRIX tempRotMatrix = DirectX::XMMatrixRotationRollPitchYawFromVector(m_position);

	DirectX::XMVECTOR look = DirectX::XMVectorSet(0, -1, 0, 0);
	DirectX::XMVECTOR up = DirectX::XMVectorSet(0, 0, 1, 0);

	//look = DirectX::XMVector2Transform(look, tempRotMatrix);
	//up = DirectX::XMVector2Transform(up, tempRotMatrix);

	// Update view matrix
	m_view = DirectX::XMMatrixLookToLH(m_position, look, up);
}

// Create a new projection matrix, replacing your current projection matrix
void Camera::CreateProjectionMatrix(float p_FOV, float p_height, float p_width, float p_nearZ, float p_farZ)
{
	m_projection = DirectX::XMMatrixPerspectiveFovLH(p_FOV, p_height / p_width, p_nearZ, p_farZ);
}

// Typical RTS Camera move
void Camera::Move(float p_x, float p_y)
{
	// Deal with the hax :-)
	m_position.m128_f32[0] += p_x;
	m_position.m128_f32[2] += p_y;
}

void Camera::SetPosition(DirectX::XMVECTOR p_position)
{
	m_position = p_position;
}

DirectX::XMVECTOR Camera::GetPosition() const
{
	return m_position;
}

void Camera::SetRotation(DirectX::XMVECTOR p_rotation)
{
	m_rotation = p_rotation;
}

DirectX::XMVECTOR Camera::GetRotation() const
{
	return m_rotation;
}

DirectX::XMMATRIX Camera::GetProjectionMatrix() const
{
	return m_projection;
}

DirectX::XMMATRIX Camera::GetViewMatrix() const
{
	return m_view;
}
