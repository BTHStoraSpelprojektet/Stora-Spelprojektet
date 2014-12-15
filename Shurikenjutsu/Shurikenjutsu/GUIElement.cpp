#include "GUIElement.h"

GUIElement::GUIElement(){}
GUIElement::~GUIElement(){}

bool GUIElement::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, DirectX::XMFLOAT4 p_color)
{
	m_position = p_position;
	m_size = DirectX::XMFLOAT2((float)p_width, (float)p_height);
	m_color = p_color;
	return true;
}

void GUIElement::QueueRender()
{
	GUIManager::GetInstance()->AddToRenderQueue(this);
}

DirectX::XMFLOAT4X4 GUIElement::GetWorldMatrix()const
{
	DirectX::XMFLOAT4X4 matrix;
	DirectX::XMStoreFloat4x4(&matrix, DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat2(&m_size)) * DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_position)));
	return matrix;
}

DirectX::XMFLOAT4 GUIElement::GetColor()const
{
	return m_color;
}

void GUIElement::SetColor(DirectX::XMFLOAT4 p_color)
{
	m_color = p_color;
}

DirectX::XMFLOAT2 GUIElement::GetSize()const
{
	return m_size;
}

void GUIElement::SetSize(DirectX::XMFLOAT2 p_size)
{
	m_size = p_size;
}

DirectX::XMFLOAT3 GUIElement::GetPosition()const
{
	return m_position;
}

void GUIElement::SetPosition(DirectX::XMFLOAT3 p_position)
{
	m_position = p_position;
}