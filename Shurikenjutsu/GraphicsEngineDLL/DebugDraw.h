#ifndef DEBUGDRAW
#define DEBUGDRAW

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

class DebugDraw
{
public:
	static DebugDraw& GetInstance();

	// Basic.
	void RenderSingleLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint, DirectX::XMFLOAT3 p_color);

private:
	DebugDraw() {};
	DebugDraw(DebugDraw const&);
	void operator=(DebugDraw const&);
};
#endif