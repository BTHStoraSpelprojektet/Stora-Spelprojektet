#ifndef SSAO_H_
#define SSAO_H_
#include <d3d11.h>
#include <DirectXMath.h>
class SSAO
{
public:
	SSAO();
	~SSAO();

	bool Initialize();
	void Shutdown();

	ID3D11ShaderResourceView* GetSSAO();

	HRESULT RenderSSAO(DirectX::XMFLOAT4X4 p_P);
	
	void BlurSSAO();

	DirectX::XMFLOAT4* GetOffsetVectors();

private:

	void ClearSSAO();
	void SetRenderToSSAO();
	void BuildOffsetVectors();
	bool InitSSAOMap();
	void BuildRandomVec();

	void BlurSSAO(ID3D11ShaderResourceView* p_input, ID3D11RenderTargetView* p_output, bool p_horizontal);

	// SSAOMap
	ID3D11RenderTargetView* m_SSAORTV;
	ID3D11RenderTargetView* m_SSAOBlurRTV;
	ID3D11ShaderResourceView* m_SSAOBlurSRV;
	ID3D11ShaderResourceView* m_SSAOSRV;
	ID3D11ShaderResourceView* m_RandomVecSRV;

	DirectX::XMFLOAT4 m_Offsets[14];
};
#endif
