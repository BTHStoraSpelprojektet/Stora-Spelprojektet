#ifndef SCENESHADER
#define SCENESHADER

#include <D3D11.h>
#include <vector>
#include "Structures.h"

class InstanceManager;
class Object;

class SceneShader
{
public:
	bool Initialize(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

	void Shutdown();

	void Render(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);
	void RenderReversedShadows(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, ID3D11ShaderResourceView* p_visibilityMap, ID3D11ShaderResourceView* p_texture);
	void RenderAnimated(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderAnimatedOutliningDepth(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderAnimatedOutlining(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void RenderLine(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT3 p_color, DirectX::XMFLOAT4X4 p_worldMatrix);
	void RenderForward(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap);

	void UpdateViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void UpdateLightViewAndProjection(DirectX::XMFLOAT4X4 p_viewMatrix, DirectX::XMFLOAT4X4 p_projectionMatrix);
	void UpdateFogBuffer(ID3D11DeviceContext* p_context, float p_fogStart, float p_fogEnd, float p_fogDensity);

	void TurnOnBackFaceCulling(ID3D11DeviceContext* p_context);
	void TurnOffBackFaceCulling(ID3D11DeviceContext* p_context);

	void UpdateFrameBuffer(ID3D11DeviceContext* p_context, DirectionalLight& p_dlight);
	void UpdateShadowMap(ID3D11ShaderResourceView* p_shadowMap);

	void SetShadowMapDimensions(ID3D11Device* p_device, ID3D11DeviceContext* p_context, float p_width, float p_height);

	ID3D11ShaderResourceView* GetShadowMap();

	/// Instancing
	void RenderInstance(ID3D11DeviceContext* p_context, ID3D11Buffer* p_mesh, int p_numberOfVertices, DirectX::XMFLOAT4X4 p_worldMatrix, ID3D11ShaderResourceView* p_texture, ID3D11ShaderResourceView* p_normalMap, int p_instanceIndex, InstanceManager* p_instanceManager);

private:
	void UpdateWorldMatrix(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix);
	void UpdateReversedShadowMatrices(ID3D11DeviceContext* p_context);
	void UpdateAnimatedBuffer(ID3D11DeviceContext* p_context, std::vector<DirectX::XMFLOAT4X4> p_boneTransforms);
	void UpdateColorBuffer(ID3D11DeviceContext* p_context, float R, float G, float B);
	void UpdateWorldMatrixOutlining(ID3D11DeviceContext* p_context, DirectX::XMFLOAT4X4 p_worldMatrix);

	ID3D11VertexShader* m_vertexShader;
	ID3D11VertexShader* m_instanceShader;
	ID3D11VertexShader* m_animatedVertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11PixelShader* m_pixelShaderForward;
	ID3D11PixelShader* m_reversedShadowPixelShader;

	ID3D11VertexShader* m_lineVertexShader;
	ID3D11PixelShader* m_linePixelShader;

	// Outlining
	ID3D11VertexShader* m_vertexShaderOutlining;
	ID3D11PixelShader* m_pixelShaderOutlining;
	ID3D11InputLayout* m_layoutOutlining;

	ID3D11InputLayout* m_layout;
	ID3D11InputLayout* m_instanceLayout;
	ID3D11InputLayout* m_animatedLayout;
	ID3D11InputLayout* m_lineLayout;

	ID3D11SamplerState* m_samplerState;
	ID3D11SamplerState* m_samplerShadowMapState;
	
	ID3D11RasterizerState* m_rasterizerStateBackCulled;
	ID3D11RasterizerState* m_rasterizerStateNoneCulled;

	std::string m_VSVersion;
	std::string m_PSVersion;

	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_projectionMatrix;

	DirectX::XMFLOAT4X4 m_lightViewMatrix;
	DirectX::XMFLOAT4X4 m_lightProjectionMatrix;
	ID3D11ShaderResourceView* m_shadowMap;

	ID3D11Buffer* m_matrixBuffer;
	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;

		DirectX::XMMATRIX m_lightViewMatrix;
		DirectX::XMMATRIX m_lightProjectionMatrix;
	};

	ID3D11Buffer* m_matrixBufferOutlining;
	struct MatrixBufferOutlining
	{
		DirectX::XMMATRIX m_worldMatrix;
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
	};

	ID3D11Buffer* m_fogBuffer;
	struct FogBuffer
	{
		float m_fogStart;
		float m_fogEnd;
		float m_fogDensity;
		float m_padding;
	};

	// Animation matrix buffer.
	ID3D11Buffer* m_animationMatrixBuffer;
	struct AnimationMatrixBuffer
	{
		DirectX::XMMATRIX m_boneTransforms[30];
	};

	ID3D11Buffer* m_frameBuffer;
	struct FrameBuffer
	{
		DirectionalLight m_directionalLight;
	};

	struct ShadowMapSizeBuffer
	{
		float m_shadowMapWidth;
		float m_shadowMapHeight;
		float p0;
		float p1;
	};

	ID3D11Buffer* m_colorBuffer;
	struct ColorBuffer
	{
		DirectX::XMFLOAT4 m_color;
	};

	////Instancing
	//std::vector<ID3D11Buffer*> m_instanceBufferList;
	//std::vector<int> m_numberOfInstanceList;

};
#endif