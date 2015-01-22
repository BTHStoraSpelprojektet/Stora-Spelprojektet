#include "GUIElementColor.h"
#include "GUIManager.h"

GUIElementColor::GUIElementColor(){}
GUIElementColor::~GUIElementColor(){}

bool GUIElementColor::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, DirectX::XMFLOAT4 p_color)
{
	m_position = p_position;
	m_size = DirectX::XMFLOAT2((float)p_width, (float)p_height);
	m_color = p_color;
	return true;
}

void GUIElementColor::QueueRender()
{
	GUIManager::GetInstance()->AddToRenderQueueColor(this);
}

DirectX::XMFLOAT4X4 GUIElementColor::GetWorldMatrix()const
{
	DirectX::XMFLOAT4X4 matrix;
	DirectX::XMStoreFloat4x4(&matrix, DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat2(&m_size)) * DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_position)));
	return matrix;
}

DirectX::XMFLOAT4 GUIElementColor::GetColor()const
{
	return m_color;
}

void GUIElementColor::SetColor(DirectX::XMFLOAT4 p_color)
{
	m_color = p_color;
}

DirectX::XMFLOAT2 GUIElementColor::GetSize()const
{
	return m_size;
}

void GUIElementColor::SetSize(DirectX::XMFLOAT2 p_size)
{
	m_size = p_size;
}

DirectX::XMFLOAT3 GUIElementColor::GetPosition()const
{
	return m_position;
}

void GUIElementColor::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_position = p_position;
}