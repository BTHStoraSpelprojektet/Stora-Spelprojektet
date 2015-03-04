#ifndef SUDDENDEATH_H_
#define SUDDENDEATH_H_

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

class GUIText;
class Camera;

class SuddenDeathState
{
public:
	SuddenDeathState();
	~SuddenDeathState();

	void Initialize();
	void Shutdown();

	void Update();
	void Render(Camera* p_camera);

private:
	struct SuddenDeathVertex
	{
		DirectX::XMFLOAT3 m_position;
		DirectX::XMFLOAT2 m_UV;

		SuddenDeathVertex()
		{
			m_position = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
			m_UV = DirectX::XMFLOAT2(0.0f, 0.0f);
		}

		SuddenDeathVertex(DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT2 p_UV)
		{
			m_position = p_position;
			m_UV = p_UV;
		}
	};

	struct MatrixBuffer
	{
		DirectX::XMMATRIX m_viewMatrix;
		DirectX::XMMATRIX m_projectionMatrix;
		DirectX::XMFLOAT4 m_color;

		MatrixBuffer()
		{
			DirectX::XMFLOAT4X4 view;
			DirectX::XMStoreFloat4x4(&view, DirectX::XMMatrixIdentity());
			m_viewMatrix = DirectX::XMLoadFloat4x4(&view);

			DirectX::XMFLOAT4X4 projection;
			DirectX::XMStoreFloat4x4(&projection, DirectX::XMMatrixIdentity());
			m_projectionMatrix = DirectX::XMLoadFloat4x4(&projection);

			m_color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
		}
	};

	GUIText* m_title;
	std::string m_VSVersion;
	std::string m_PSVersion;
	float m_UVOffset;
	bool m_UVForward;
	float m_gasOpacity;
	float m_gasHeight;

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11ShaderResourceView* m_texture;

	#define NUMBER_OF_VERTICES 36
	SuddenDeathVertex m_mesh[NUMBER_OF_VERTICES];
	DirectX::XMFLOAT2 m_originalValues[NUMBER_OF_VERTICES];
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_matrixBuffer;
};
#endif