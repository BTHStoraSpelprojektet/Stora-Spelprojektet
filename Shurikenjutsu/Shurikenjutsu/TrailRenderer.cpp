#include "TrailRenderer.h"

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

void TrailRenderer::RenderTrail()
{

}

void TrailRenderer::SetWorldMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{

}

void TrailRenderer::SetViewMatrix(DirectX::XMFLOAT4X4 p_viewMatrix)
{

}

void TrailRenderer::SetProjectionMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix)
{

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

}