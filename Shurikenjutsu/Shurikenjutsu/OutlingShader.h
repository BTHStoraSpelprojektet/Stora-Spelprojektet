#ifndef OUTLINGINGSHADER_H_
#define OUTLINGINSHADER_H_

#include "DirectX.h"
#include <D3D11.h>

class OutliningShader
{
public:
	OutliningShader();
	OutliningShader(const OutliningShader&);
	~OutliningShader();

	bool Initialize();
	void Shutdown();
	void Render();
	void InitializeBuffers();
	// Outlining
	bool SetStencilStateOff(ID3D11Device* p_device, ID3D11DeviceContext* p_context);
	bool SetStencilStateOn(ID3D11Device* p_device, ID3D11DeviceContext* p_context);

private:

	ID3D11DepthStencilState* m_stencilState;
	ID3D11Texture2D* m_depthStencil;

	std::string m_VSVersion;
	std::string m_PSVersion;

};


#endif // !OUTLINGSHADER_H_
// Outlining