#ifndef SCENESHADER
#define SCENESHADER

#include <D3D11.h>
#include <D3Dcompiler.h>
#include <Windows.h>
#include "ConsoleFunctions.h"

class SceneShader
{
public:
	bool Initialize(ID3D11Device* p_device, HWND p_handle);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3D11InputLayout* m_layout;
};
#endif