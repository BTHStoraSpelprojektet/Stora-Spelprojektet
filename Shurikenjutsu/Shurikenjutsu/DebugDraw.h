#ifndef DEBUGDRAW
#define DEBUGDRAW

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

class DebugDraw
{
public:
	static DebugDraw& GetInstance();

	// Basic.
	void RenderLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint, DirectX::XMFLOAT3 p_color);

	// 2D.
	void RenderRectangle(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, DirectX::XMFLOAT3 p_color);
	void Render2DShape(std::vector<DirectX::XMFLOAT3> p_shape, DirectX::XMFLOAT3 p_color);

	// 3D.
	void RenderBox(DirectX::XMFLOAT3 p_centrum, float p_width, float p_depth, float p_height, DirectX::XMFLOAT3 p_color);
	void Render3DShape(std::vector<DirectX::XMFLOAT3> p_shape, float p_height, DirectX::XMFLOAT3 p_color);

private:
	DebugDraw() {};
	DebugDraw(DebugDraw const&);
	void operator=(DebugDraw const&);
};
#endif