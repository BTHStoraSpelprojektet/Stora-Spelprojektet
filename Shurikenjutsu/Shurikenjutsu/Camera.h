#pragma once
#include <DirectXMath.h>

class Camera
{
public:
	Camera();
	~Camera();

	void Initialize();
	void Shutdown();

	void UpdateViewMatrix();
	void CreateProjectionMatrix(float p_FOV, float p_height, float p_width, float p_nearZ, float p_farZ);

	// Moves the camera in x and z directions
	void Move(float p_x, float p_y);

	void SetPosition(DirectX::XMVECTOR p_position);
	DirectX::XMVECTOR GetPosition() const;

	void SetRotation(DirectX::XMVECTOR p_rotation);
	DirectX::XMVECTOR GetRotation() const;

	DirectX::XMMATRIX GetProjectionMatrix() const;
	DirectX::XMMATRIX GetViewMatrix() const;

private:
	DirectX::XMMATRIX m_view;
	DirectX::XMMATRIX m_projection;

	DirectX::XMVECTOR m_position;
	DirectX::XMVECTOR m_rotation;
};

