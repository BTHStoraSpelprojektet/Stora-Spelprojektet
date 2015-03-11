#ifndef DEPTHSHADER
#define DEPTHSHADER

#include <D3D11.h>
#include <Windows.h>

#include "..\Shurikenjutsu\Structures.h"

class InstanceManager;

class DepthShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	void Shutdown();

	void PrepareRender(ID3D11DeviceContext* p_context);
	void Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4& p_worldMatrix, ID3D11ShaderResourceView* p_texture);

	void UpdateViewAndProjection(DirectX::XMFLOAT4X4& p_viewMatrix, DirectX::XMFLOAT4X4& p_projectionMatrix);

	/// Instancing
	void PrepareRenderInstanced(ID3D11DeviceContext* p_context);
	void RenderInstance(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, int p_instanceIndex, InstanceManager* p_instanceManager);

	// Animated
	void PrepareRenderAnimated(ID3D11DeviceContext* p_context);
	void RenderAnimated(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4& p_worldMatrix, ID3D11ShaderResourceView* p_texture, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void UpdateAnimatedBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	
private:
	bool InitializeAnimatedDepth(ID3D11Device* p_device, ID3D11DeviceContext* p_context);


	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4& p_worldMatrix);

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11VertexShader* m_instanceShader;

	ID3D11InputLayout* m_layout;
	ID3D11InputLayout* m_instanceLayout;

	ID3D11RasterizerState* m_rasterizer;
	ID3D11SamplerState* m_samplerState;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMFLOAT4X4 m_worldMatrix;
		DirectX::XMFLOAT4X4 m_viewMatrix;
		DirectX::XMFLOAT4X4 m_projectionMatrix;
	};

	// Animation stuff
	ID3D11VertexShader* m_animatedVertexShader;
	ID3D11InputLayout* m_animatedLayout;
	ID3D11Buffer* m_animationMatrixBuffer;
	struct AnimationMatrixBuffer
	{
		DirectX::XMMATRIX m_boneTransforms[30];
	};
};
#endif