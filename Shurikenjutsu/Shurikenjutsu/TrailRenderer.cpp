#include "TrailRenderer.h"

#include "ConsoleFunctions.h"

TrailRenderer& TrailRenderer::GetInstance()
{
	static TrailRenderer instance;

	return instance;
}

bool TrailRenderer::Initialize()
{
	return true;
}

void TrailRenderer::Shutdown()
{

}

void TrailRenderer::RenderTrail(ID3D11Buffer* p_vertexBuffer, unsigned int p_points, ID3D11ShaderResourceView* p_texture)
{
	// TODO, render.
}

void TrailRenderer::SetWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_worldMatrix = p_worldMatrix;
}

void TrailRenderer::SetViewMatrix(DirectX::XMFLOAT4X4 p_viewMatrix)
{
	m_viewMatrix = p_viewMatrix;
}

void TrailRenderer::SetProjectionMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_projectionMatrix = p_projectionMatrix;
}

DirectX::XMFLOAT4X4 TrailRenderer::GetWorldMatrix()
{
	return m_worldMatrix;
}

DirectX::XMFLOAT4X4 TrailRenderer::GetViewMatrix()
{
	return m_viewMatrix;
}

DirectX::XMFLOAT4X4 TrailRenderer::GetProjectionMatrix()
{
	return m_projectionMatrix;
}

void TrailRenderer::UpdateMatrixes()
{
	// TODO, Update matrices.
}