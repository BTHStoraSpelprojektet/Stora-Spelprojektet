#ifndef LINES
#define LINES

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

class Lines
{
public:
	static Lines& GetInstance();

	void RenderSingleLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint);
	void RenderStaticLines();

	void AddStaticLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint);
	void ClearStaticLines();

private:
	Lines() {};
	Lines(Lines const&);
	void operator=(Lines const&);

	std::vector<DirectX::XMFLOAT3> m_lines;
};
#endif