#include "Camera.h"

bool Camera::Initialize()
{
	m_position = DirectX::XMFLOAT3(0, 0, 0);
	m_target = DirectX::XMFLOAT3(0, 0, 0);

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

void Camera::Shutdown()
{

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
	// Update view matrix.
	DirectX::XMStoreFloat4x4(&m_viewMatrix, DirectX::XMMatrixLookAtLH(DirectX::XMLoadFloat3(&m_position), DirectX::XMLoadFloat3(&m_target), DirectX::XMLoadFloat3(&m_upVector)));
}

void Camera::UpdateProjectionMatrix(bool p_orthographic)
{
	// Update projection matrix.
	if (!p_orthographic)
	{
		DirectX::XMStoreFloat4x4(&m_projectionMatrix, DirectX::XMMatrixPerspectiveFovLH(m_fieldOfView, m_aspectRatio, m_nearPlane, m_farPlane));
		
	}

	else
	{
		DirectX::XMStoreFloat4x4(&m_projectionMatrix, DirectX::XMMatrixOrthographicLH(GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / 13.0f, (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT / 13.0f, m_nearPlane, m_farPlane));
	}
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

void Camera::ToggleFullscreen(bool p_fullscreen)
{
	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = true;

	if (p_fullscreen)
	{
		// Go to fullscreen
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MAX_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
		SetWindowPos(GraphicsEngine::GetWindowHandle(), HWND_TOP, 0, 0, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, SWP_SHOWWINDOW);
		GraphicsEngine::ToggleFullscreen(true);

		// Update aspect ratio.
		float aspectRatio = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
		UpdateAspectRatio(aspectRatio);
		UpdateProjectionMatrix(false);
		GraphicsEngine::SetViewAndProjection(GetViewMatrix(), GetProjectionMatrix());

		// Set both window positions.
		HWND console = GetConsoleWindow();
		MoveWindow(console, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, 0, 670, 1000, true);
	}

	else
	{
		// Go to windowed mode.
		GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH = GLOBAL::GetInstance().MIN_SCREEN_WIDTH;
		GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT = GLOBAL::GetInstance().MIN_SCREEN_HEIGHT;
		GraphicsEngine::ToggleFullscreen(false);

		// Update aspect ratio.
		float aspectRatio = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
		UpdateAspectRatio(aspectRatio);
		UpdateProjectionMatrix(false);
		GraphicsEngine::SetViewAndProjection(GetViewMatrix(), GetProjectionMatrix());

		// Set both window positions.
		HWND console = GetConsoleWindow();
		MoveWindow(console, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, 0, 670, 1000, true);
		SetWindowPos(GraphicsEngine::GetWindowHandle(), HWND_TOP, 0, 0, GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT, SWP_SHOWWINDOW);
	}

	GLOBAL::GetInstance().SWITCHING_SCREEN_MODE = false;
}

void Camera::MoveCamera( )
{
	double deltaTime = GLOBAL::GetInstance().GetDeltaTime();
	// Start moving the camera with the C key.
	if (InputManager::GetInstance()->IsKeyClicked(VkKeyScan('c')) && !GLOBAL::GetInstance().CAMERA_FLYING)
	{
		ShowCursor(false);
		GLOBAL::GetInstance().CAMERA_FLYING = true;

		POINT position;
		GetCursorPos(&position);

		m_oldMouseX = (float)position.x;
		m_oldMouseY = (float)position.y;

		m_upVector = DirectX::XMFLOAT3(0.0f, 20.0f, 10.0f);
		DirectX::XMStoreFloat3(&m_upVector, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_upVector)));

		m_look = DirectX::XMFLOAT3(0.0f, -20.0f, 10.0f);
		DirectX::XMStoreFloat3(&m_look, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_look)));

		m_right = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
		DirectX::XMStoreFloat3(&m_right, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_right)));
	}

	if (GLOBAL::GetInstance().CAMERA_FLYING)
	{
		// Rotate and pitch the camera.
		POINT position;
		GetCursorPos(&position);

		float dx = DirectX::XMConvertToRadians(0.25f * static_cast<float>(position.x - m_oldMouseX));
		float dy = DirectX::XMConvertToRadians(0.25f * static_cast<float>(position.y - m_oldMouseY));
		Pitch(dy);
		Rotate(dx);

		SetCursorPos((int)m_oldMouseX, (int)m_oldMouseY);

		// Move the camera using W, S, A, D keys.
		if (InputManager::GetInstance()->IsKeyPressed(VK_UP))
		{
			Walk(10.0f * (float)deltaTime);
		}

		if (InputManager::GetInstance()->IsKeyPressed(VK_DOWN))
		{
			Walk(-10.0f * (float)deltaTime);
		}

		if (InputManager::GetInstance()->IsKeyPressed(VK_LEFT))
		{
			Strafe(-10.0f * (float)deltaTime);
		}

		if (InputManager::GetInstance()->IsKeyPressed(VK_RIGHT))
		{
			Strafe(10.0f * (float)deltaTime);
		}

		// Update the camera.
		UpdateMovedCamera();

		// Set shader variables from the camera.
		GraphicsEngine::SetViewAndProjection(GetViewMatrix(), GetProjectionMatrix());

		// Reset the camera when BACKSPACE key is pressed.
		if (GetAsyncKeyState(VK_BACK))
		{
			ShowCursor(true);
			GLOBAL::GetInstance().CAMERA_FLYING = false;
			ResetCamera();
		}
	}
}

void Camera::FollowCharacter(DirectX::XMFLOAT3 p_playerPos)
{
	// Lock shadows on the player.
	DirectX::XMFLOAT3 playerPosition = p_playerPos;
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(playerPosition.x -25.0f, playerPosition.y + 100.0f, playerPosition.z - 50.0f);
	DirectX::XMFLOAT3 target = playerPosition;

	UpdatePosition(position);
	UpdateTarget(target);
	UpdateViewMatrix();
	UpdateProjectionMatrix(true);
	GraphicsEngine::SetLightViewAndProjection(GetViewMatrix(), GetProjectionMatrix());

	// Lock camera on the player.
	playerPosition = p_playerPos;
	position = DirectX::XMFLOAT3(playerPosition.x, playerPosition.y + 40.0f, playerPosition.z - 20.0f);
	target = playerPosition;

	UpdatePosition(position);
	UpdateTarget(target);
	UpdateViewMatrix();
	UpdateProjectionMatrix(false);
	GraphicsEngine::SetViewAndProjection(GetViewMatrix(), GetProjectionMatrix());
}

void Camera::ResetCamera()
{
	// Reset camera.
	DirectX::XMFLOAT3 target = DirectX::XMFLOAT3(0, 0, 0);
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(target.x, target.y + 40.0f, target.z - 20.0f);

	UpdatePosition(position);
	UpdateTarget(target);

	m_upVector = DirectX::XMFLOAT3(0.0f, 40.0f, 20.0f);
	DirectX::XMStoreFloat3(&m_upVector, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_upVector)));

	m_look = DirectX::XMFLOAT3(0.0f, -40.0f, 20.0f);
	DirectX::XMStoreFloat3(&m_look, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_look)));

	m_right = DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f);
	DirectX::XMStoreFloat3(&m_right, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_right)));

	// Projection data.
	float aspectRatio = (float)GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH / (float)GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;
	UpdateAspectRatio(aspectRatio);
	UpdateFieldOfView(3.141592f * 0.25f);
	UpdateClippingPlanes(0.1f, 1000.0f);
	UpdateViewMatrix();
	UpdateProjectionMatrix(false);

	GraphicsEngine::SetViewAndProjection(GetViewMatrix(), GetProjectionMatrix());
}

void Camera::ResetCameraToLight()
{
	// Reset camera.
	DirectX::XMFLOAT3 target = DirectX::XMFLOAT3(0, 0, 0);
	DirectX::XMFLOAT3 position = DirectX::XMFLOAT3(-25.0f, 100.0f, -50.0f);

	UpdatePosition(position);
	UpdateTarget(target);

	m_upVector = DirectX::XMFLOAT3(25.0f, 100.0f, 50.0f);
	DirectX::XMStoreFloat3(&m_upVector, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_upVector)));

	m_look = DirectX::XMFLOAT3(25.0f, -100.0f, 50.0f);
	DirectX::XMStoreFloat3(&m_look, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_look)));

	m_right = DirectX::XMFLOAT3(-25.0f, 0.0f, 50.0f);
	DirectX::XMStoreFloat3(&m_right, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&m_right)));

	// Projection data.
	float aspectRatio = (float)GLOBAL::GetInstance().MAX_SCREEN_WIDTH / (float)GLOBAL::GetInstance().MAX_SCREEN_HEIGHT;
	UpdateAspectRatio(aspectRatio);
	UpdateFieldOfView(3.141592f * 0.25f);
	UpdateClippingPlanes(0.1f, 1000.0f);
	UpdateViewMatrix();
	UpdateProjectionMatrix(true);

	GraphicsEngine::SetLightViewAndProjection(GetViewMatrix(), GetProjectionMatrix());
}