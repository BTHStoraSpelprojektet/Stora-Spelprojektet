#ifndef SSAO_H_
#define SSAO_H_
#include <d3d11.h>
#include <DirectXMath.h>
class SSAO
{
public:
	SSAO();
	~SSAO();

	bool Initialize(int p_width, int p_height, float p_fovy, float p_farz);
	void Shutdown();

	ID3D11ShaderResourceView* GetSSAO();

	HRESULT RenderSSAO(DirectX::XMFLOAT4X4 p_P);
	
	void BlurSSAO();

private:

	void ClearSSAO();
	void SetRenderToSSAO();
	void BuildFrustumFarCorners(int p_textureWidth, int p_textureHeight, float p_fovy, float p_farz);
	void BuildOffsetVectors();
	bool InitSSAOMap(int p_textureWidth, int p_textureHeight);
	void BuildRandomVec();

	void BlurSSAO(ID3D11ShaderResourceView* p_input, ID3D11RenderTargetView* p_output, bool p_horizontal);

	D3D11_VIEWPORT m_SSAOVP;

	// SSAOMap
	ID3D11Texture2D* m_SSAORTT;
	ID3D11Texture2D* m_SSAOBlurRTT;
	ID3D11RenderTargetView* m_SSAORTV;
	ID3D11RenderTargetView* m_SSAOBlurRTV;
	ID3D11ShaderResourceView* m_SSAOBlurSRV;
	ID3D11ShaderResourceView* m_SSAOSRV;
	ID3D11ShaderResourceView* m_RandomVecSRV;

	ID3D11Buffer* m_ScreenQuadIB;
	ID3D11Buffer* m_ScreenQuadVB;
	DirectX::XMFLOAT4 m_Offsets[14];
	DirectX::XMFLOAT4 m_FrustumFarCorner[4];

	DirectX::XMFLOAT4X4 m_T;

};
#endif
