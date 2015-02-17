#include "GUIElement.h"
#include "TextureLibrary.h"
#include "GUIManager.h"
#include "GraphicsEngine.h"

GUIElement::GUIElement(){}
GUIElement::~GUIElement(){}

bool GUIElement::Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture)
{
	m_position = p_position;
	m_size = DirectX::XMFLOAT2((float)p_width, (float)p_height);
	m_texture = nullptr;
	SetTexture(p_texture);
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

ID3D11ShaderResourceView* GUIElement::GetTexture()const
{
	return m_texture;
}

void GUIElement::SetTexture(ID3D11ShaderResourceView* p_texture)
{
	m_texture = p_texture;
}

// For cursor :)
void GUIElement::Render()
{
	GraphicsEngine::GetInstance()->RenderGUI(GetWorldMatrix(), m_texture);
}